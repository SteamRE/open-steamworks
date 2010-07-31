using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using SAPIBase;
using Steam4NET;
using System.IO;

namespace CloudEditor
{
    public partial class MainForm : Form
    {
        int appId;

        public MainForm( int appId )
        {
            this.appId = appId;

            InitializeComponent();

            this.Icon = Icon.FromHandle( Properties.Resources.weather_clouds.GetHicon() );

            this.Text = string.Format( "Cloud Editor - [ {0} / AppID {1} ]", Steam.GetAppData( ( uint )appId, "name" ), appId );

            if ( !Cloud.IsEnabled() )
            {
                Util.MsgBox( this, "It appears as Steam Cloud is not enabled for this AppID." );
            }

            RefreshFiles();
        }

        void RefreshFiles()
        {
            DebugLog.AppendText( "Cloud - Refreshing Files..." );

            fileList.Items.Clear();

            foreach ( var fileInfo in Cloud.GetFiles() )
            {
                FileListViewItem lvi = new FileListViewItem( fileInfo.FileName, fileInfo.Size );

                fileList.Items.Add( lvi );
            }

            DebugLog.AppendText( "Done!{0}", Environment.NewLine );

            RefreshQuota();
        }
        void RefreshQuota()
        {
            DebugLog.AppendText( "Cloud - Refreshing Quota..." );

            int total;
            int avail;

            string strTotal = "Unknown";
            string strAvail = "Unknown";
            string strUsed = "Unknown";

            if ( Cloud.GetQuota( out total, out avail ) )
            {

                strTotal = Util.BytesToKB( total ).ToString();
                strAvail = Util.BytesToKB( avail ).ToString();

                strUsed = Util.BytesToKB( total - avail ).ToString();
            }

            quotaAvailLabel.Text = string.Format( "{0} KB Available", strAvail );
            quotaTotalLabel.Text = string.Format( "{0} KB Total", strTotal );

            quotaUsedLabel.Text = string.Format( "{0} KB Used", strUsed );

            DebugLog.AppendText( "Done!{0}", Environment.NewLine );
        }

        void EditFile( string fileName )
        {
            DebugLog.AppendText( "Cloud - Reading File..." );

            byte[] data = Cloud.ReadFile( fileName );

            if ( data == null || data.Length == 0 )
            {
                DebugLog.AppendText( "Failed!{0}", Environment.NewLine );
                return;
            }

            DebugLog.AppendText( "Done!{0}", Environment.NewLine );

            EditForm ef = new EditForm( fileName, data );

            if ( ef.ShowDlg( this ) == EditForm.EditResult.SaveChanges )
            {
                DebugLog.AppendText( "Cloud - Saving Changes..." );

                byte[] editData = ef.GetData();

                if ( !Cloud.WriteFile( fileName, editData ) )
                {
                    DebugLog.AppendText( "Failed!{0}", Environment.NewLine );
                    return;
                }

                DebugLog.AppendText( "Done!{0}", Environment.NewLine );

                RefreshFiles();
            }
        }
        void SaveFile( string fileName )
        {
            SaveFileDialog sfd = new SaveFileDialog();
            sfd.CheckPathExists = true;
            sfd.DefaultExt = Path.GetExtension( fileName );
            sfd.OverwritePrompt = true;
            sfd.SupportMultiDottedExtensions = true;
            sfd.FileName = Path.GetFileName( fileName );
            sfd.Filter = string.Format( "{0} Files (*.{0})|*.{0}|All Files (*.*)|*.*", sfd.DefaultExt );
            sfd.Title = string.Format( "Save \"{0}\"...", fileName );
            sfd.ValidateNames = true;

            if ( sfd.ShowDialog() != DialogResult.OK )
                return;

            DebugLog.AppendText( "Cloud - Reading File..." );

            byte[] data = Cloud.ReadFile( fileName );

            if ( data == null || data.Length == 0 )
            {
                DebugLog.AppendText( "Failed!{0}", Environment.NewLine );
                return;
            }

            DebugLog.AppendText( "Done!{0}", Environment.NewLine );

            DebugLog.AppendText( "Writing Local File..." );
            try
            {
                File.WriteAllBytes( sfd.FileName, data );
            }
            catch ( Exception ex )
            {
                DebugLog.AppendText( "Failed: {1}{0}", ex.Message, Environment.NewLine );
                return;
            }

            DebugLog.AppendText( "Done!{0}", Environment.NewLine );
        }
        void ReplaceFile( string fileName )
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.CheckFileExists = true;
            ofd.CheckPathExists = true;
            ofd.DefaultExt = Path.GetExtension( fileName );
            ofd.Filter = string.Format( "{0} Files (*.{0})|*.{0}|All Files (*.*)|*.*", ofd.DefaultExt );
            ofd.Multiselect = false;
            ofd.SupportMultiDottedExtensions = true;
            ofd.Title = string.Format( "Replace \"{0}\"...", fileName );
            ofd.ValidateNames = true;

            if ( ofd.ShowDialog() != DialogResult.OK )
                return;

            byte[] data = null;

            DebugLog.AppendText( "Reading Local File..." );

            try
            {
                data = File.ReadAllBytes( ofd.FileName );
            }
            catch ( Exception ex )
            {
                DebugLog.AppendText( "Failed: {1}{0}", ex.Message, Environment.NewLine );
                return;
            }

            DebugLog.AppendText( "Done!{0}", Environment.NewLine );


            DebugLog.AppendText( "Cloud - Writing File..." );

            if ( !Cloud.WriteFile( fileName, data ) )
            {
                DebugLog.AppendText( "Failed!{0}", Environment.NewLine );
                return;
            }

            DebugLog.AppendText( "Done!{0}", Environment.NewLine );

            RefreshFiles();
        }

        private void fileList_MouseClick( object sender, MouseEventArgs e )
        {
            if ( fileList.SelectedItems.Count == 0 )
                return;

            FileListViewItem lvi = fileList.SelectedItems[ 0 ] as FileListViewItem;

            if ( e.Button == MouseButtons.Right )
            {
                fileMenuStrip.Items[ 0 ].Text = "[" + lvi.FileNameShort + "]";
                fileMenuStrip.Show( this, e.Location );
            }
        }

        private void exitToolStripMenuItem_Click( object sender, EventArgs e )
        {
            this.Close();
        }
        private void refreshToolStripMenuItem_Click( object sender, EventArgs e )
        {
            RefreshFiles();
        }

        private void saveToolStripMenuItem_Click( object sender, EventArgs e )
        {
            if ( fileList.SelectedItems.Count == 0 )
                return;

            FileListViewItem lvi = fileList.SelectedItems[ 0 ] as FileListViewItem;

            SaveFile( lvi.FileName );
        }
        private void replaceToolStripMenuItem_Click( object sender, EventArgs e )
        {
            if ( fileList.SelectedItems.Count == 0 )
                return;

            FileListViewItem lvi = fileList.SelectedItems[ 0 ] as FileListViewItem;

            ReplaceFile( lvi.FileName );
        }
        private void editToolStripMenuItem_Click( object sender, EventArgs e )
        {
            if ( fileList.SelectedItems.Count == 0 )
                return;

            FileListViewItem lvi = fileList.SelectedItems[ 0 ] as FileListViewItem;

            EditFile( lvi.FileName );

        }
        private void fileList_MouseDoubleClick( object sender, MouseEventArgs e )
        {
            if ( fileList.SelectedItems.Count == 0 )
                return;

            FileListViewItem lvi = fileList.SelectedItems[ 0 ] as FileListViewItem;

            EditFile( lvi.FileName );
        }

        private void deleteToolStripMenuItem_Click( object sender, EventArgs e )
        {
            // no impl until valve implements it
        }

        private void aboutToolStripMenuItem_Click( object sender, EventArgs e )
        {
            new AboutForm().ShowDialog( this );
        }
    }
}
