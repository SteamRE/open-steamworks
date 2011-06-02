using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ChatLog
{

    public partial class LinkIDForm : Form
    {
        Settings settings;

        public LinkIDForm( Settings sets )
        {
            InitializeComponent();

            settings = sets;

            foreach ( LinkEntry le in settings.Links )
            {
                LinkViewItem lvi = new LinkViewItem( le );
                
                linkView.Items.Add( lvi );
            }

        }

        private void addButton_Click( object sender, EventArgs e )
        {
            if ( string.IsNullOrEmpty( steamIdBox.Text ) || string.IsNullOrEmpty( displayBox.Text ) )
                return;

            ulong commId = 0;

            if ( steamIdBox.Text.StartsWith( "STEAM_" ) )
            {
                // parse steam id
                string[] parts = steamIdBox.Text.Split( ":".ToCharArray(), StringSplitOptions.RemoveEmptyEntries );

                if ( parts.Length < 3 )
                {
                    Util.ShowError( this, "Invalid SteamID." );
                    return;
                }

                int y, z;

                if ( !int.TryParse( parts[ 1 ], out y ) )
                {
                    Util.ShowError( this, "Invalid SteamID." );
                    return;
                }

                if ( !int.TryParse( parts[ 2 ], out z ) )
                {
                    Util.ShowError( this, "Invalid SteamID." );
                    return;
                }

                commId = (ulong)( ( z * 2 ) + 76561197960265728L + y );

            }

            if ( commId == 0 )
            {
                if ( !ulong.TryParse( steamIdBox.Text, out commId ) )
                {
                    Util.ShowError( this, "Invalid SteamID or Community ID." );
                    return;
                }
            }

            LinkEntry le = new LinkEntry();

            le.SteamID = commId;
            le.Name = displayBox.Text;

            if ( IndexOfEntry( le ) != -1 )
            {
                Util.ShowError( this, "LinkID already present." );
                return;
            }

            LinkViewItem lvi = new LinkViewItem( le );

            linkView.Items.Add( lvi );

        }

        int IndexOfEntry( LinkEntry le )
        {
            for (int x = 0; x < linkView.Items.Count; x++ )
            {
                if ( ( (LinkViewItem)linkView.Items[ x ] ).Link.SteamID == le.SteamID )
                    return x;
            }
            return -1;
        }


        private void LinkIDForm_FormClosing( object sender, FormClosingEventArgs e )
        {
            settings.Links.Clear();

            foreach ( LinkViewItem lvi in linkView.Items )
            {
                settings.Links.Add( lvi.Link );
            }

            try
            {
                settings.Save();
            }
            catch ( Exception ex )
            {
                Util.ShowError( this, "Unable to save settings: " + ex.Message );
            }
        }

        private void removeToolStripMenuItem_Click( object sender, EventArgs e )
        {
            if ( linkView.SelectedItems.Count == 0 )
                return;

            linkView.Items.Remove( linkView.SelectedItems[ 0 ] );
        }

        private void contextMenuStrip1_Opening( object sender, CancelEventArgs e )
        {
            if ( linkView.SelectedItems.Count == 0 )
                e.Cancel = true;
        }
    }

    public class LinkViewItem : ListViewItem
    {
        public LinkEntry Link { get; set; }

        public LinkViewItem( LinkEntry entry )
        {
            Link = entry;

            Text = Link.SteamID.ToString();
            SubItems.Add( Link.Name );
        }
    }
}
