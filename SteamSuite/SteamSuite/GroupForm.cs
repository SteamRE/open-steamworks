using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using Steam4NET;

namespace SteamSuite
{
    public partial class GroupForm : Form
    {
        SteamContext context;

        public Group Group { get; set; }

        public GroupForm( SteamContext context, Group group )
        {
            this.context = context;
            this.Group = group;

            InitializeComponent();
        }

        private void inputBox_EnterPressed( object sender, EventArgs e )
        {
            SendText( inputBox.Text );

            inputBox.Text = "";
        }

        void SendText( string text )
        {
            string input = text;
            EChatEntryType type = EChatEntryType.k_EChatEntryTypeChatMsg;

            if ( input.Length > 3 && input.IndexOf( "/me", StringComparison.OrdinalIgnoreCase ) == 0 )
            {
                input = input.Substring( 4, input.Length - 4 );
                type = EChatEntryType.k_EChatEntryTypeEmote;
            }

            byte[] inputBytes = Encoding.ASCII.GetBytes( text );

            context.ClientFriends.SendChatMsg( Group.SteamID, type, inputBytes, inputBytes.Length + 1 );
        }
    }
}
