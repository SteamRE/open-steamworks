using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using Steam4NET;

namespace OpenSteam
{
    public partial class ChatForm : Form
    {
        public CSteamID FriendID { get; private set; }

        public ChatForm( CSteamID steamId )
        {
            InitializeComponent();

            FriendID = steamId;

            string friendsName = Steam3.SteamFriends.GetFriendPersonaName( steamId );
            this.Text = this.Text.Replace( "%name%", friendsName );
        }

        public void MessageRecieved( FriendChatMsg_t msg )
        {
            string senderName = Steam3.SteamFriends.GetFriendPersonaName( msg.m_ulSender );

            byte[] msgData = new byte[ 1024 * 32 ];
            EChatEntryType chatType = EChatEntryType.k_EChatEntryTypeInvalid;

            int length = Steam3.SteamFriends.GetChatMessage( msg.m_ulReceiver, (int)msg.m_iChatID, msgData, msgData.Length, ref chatType );

            string chatMsg = Encoding.Default.GetString( msgData, 0, length - 1 );

            string msgFormat = "";
            switch ( chatType )
            {
                case EChatEntryType.k_EChatEntryTypeChatMsg:
                    msgFormat = string.Format( "{0}: {1}", senderName, chatMsg );
                    break;

                case EChatEntryType.k_EChatEntryTypeEmote:
                    msgFormat = string.Format( " * {0} {1}", senderName, chatMsg );
                    break;
            }

            chatBox.AppendText( msgFormat + Environment.NewLine );
            chatBox.ScrollToCaret();
        }

        private void chatTextBox1_EnterPressed( object sender, EventArgs e )
        {
            if ( String.IsNullOrEmpty( chatTextBox1.Text ) )
                return;

            byte[] messageData = Encoding.Default.GetBytes( chatTextBox1.Text );
            Steam3.SteamFriends.SendMsgToFriend( FriendID, EChatEntryType.k_EChatEntryTypeChatMsg, messageData, messageData.Length + 1 );

            chatTextBox1.Clear();
        }
    }
}
