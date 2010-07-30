using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using SAPIBase;

namespace CloudEditor
{
    partial class EditForm : Form
    {
        public enum EditResult
        {
            DiscardChanges,
            SaveChanges,
        }

        bool bChanged;
        string origText;

        public EditForm( string fileName, byte[] data )
        {
            InitializeComponent();

            this.Icon = Icon.FromHandle( Properties.Resources.weather_clouds.GetHicon() );

            this.Text = fileName;

            dataBox.Text = Encoding.Default.GetString( data );
            origText = dataBox.Text;
        }

        public EditResult ShowDlg( IWin32Window owner )
        {
            DialogResult dr = this.ShowDialog( null );

            EditResult er = EditResult.DiscardChanges;

            if ( dr == DialogResult.Yes )
                er = EditResult.SaveChanges;

            return er;
        }

        public byte[] GetData()
        {
            return Encoding.Default.GetBytes( dataBox.Text );
        }


        protected override void OnFormClosing( FormClosingEventArgs e )
        {
            if ( !bChanged )
                return;

            DialogResult dr = Util.YesNoCancel( this, "You have changed the contents of this file. Would you like to save it to the cloud?" );

            if ( dr == DialogResult.Cancel )
            {
                e.Cancel = true;
                return;
            }

            if ( dr == DialogResult.Yes )
                DialogResult = DialogResult.Yes;
            else
                DialogResult = DialogResult.No;

            return;
        }

        private void dataBox_TextChanged( object sender, EventArgs e )
        {
            bChanged = dataBox.Text != origText;

            if ( bChanged && !this.Text.EndsWith( "*" ) )
                this.Text += "*";
            else if ( !bChanged )
                this.Text = this.Text.TrimEnd( '*' );

        }
    }
}
