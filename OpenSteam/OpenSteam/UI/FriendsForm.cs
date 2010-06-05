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
    public partial class FriendsForm : Form
    {
        Callback<SteamServersConnected_t> serversConnected;
        Callback<SteamServersDisconnected_t> serversDisconnected;
        Callback<SteamServerConnectFailure_t> connectionFailure;

        Callback<FriendChatMsg_t> friendChatMsg;
        Callback<PersonaStateChange_t> personaChange;

        ChatManager chatManager;

        public FriendsForm()
        {
            InitializeComponent();

            serversConnected = new Callback<SteamServersConnected_t>( SteamServersConnected, SteamServersConnected_t.k_iCallback );
            serversDisconnected = new Callback<SteamServersDisconnected_t>( SteamServersDisconnected, SteamServersDisconnected_t.k_iCallback );
            connectionFailure = new Callback<SteamServerConnectFailure_t>( SteamServerConnectionFailure, SteamServerConnectFailure_t.k_iCallback );

            friendChatMsg = new Callback<FriendChatMsg_t>( FriendChatMsg, FriendChatMsg_t.k_iCallback );
            personaChange = new Callback<PersonaStateChange_t>( PersonaStateChange, PersonaStateChange_t.k_iCallback );

            chatManager = new ChatManager();
        }

        protected override void WndProc( ref Message m )
        {
            base.WndProc( ref m );

            RunCallbacks();
        }

        void PersonaStateChange( PersonaStateChange_t callBack )
        {
            foreach ( FriendListViewItem flvi in friendsView.Items )
            {
                if ( flvi.FriendID != callBack.m_ulSteamID )
                    continue;

                flvi.PersonaStateChange( callBack );
                break;
            }
        }

        void FriendChatMsg( FriendChatMsg_t callBack )
        {
            ChatForm cf = chatManager.GetChatForm( callBack.m_ulReceiver );

            cf.MessageRecieved( callBack );
        }

        void SteamServersConnected( SteamServersConnected_t callBack )
        {
            friendsView.Items.Clear();

            nameTextBox.Text = Steam3.SteamFriends.GetPersonaName();
            stateTextBox.Text = Steam3.SteamFriends.GetPersonaState().ToString();

            Steam3.ClientUser.SetComputerInUse();
            Steam3.ClientUser.SetSelfAsPrimaryChatDestination();

            Steam3.SteamFriends.SetPersonaState( EPersonaState.k_EPersonaStateOnline );

            int friendCount = Steam3.SteamFriends.GetFriendCount( ( int )EFriendFlags.k_EFriendFlagImmediate );
            for ( int x = 0 ; x < friendCount ; x++ )
            {
                CSteamID friendId = Steam3.SteamFriends.GetFriendByIndex( x, ( int )EFriendFlags.k_EFriendFlagImmediate );

                FriendListViewItem flvi = new FriendListViewItem( friendId );

                friendsView.Items.Add( flvi );
            }
        }
        void SteamServersDisconnected( SteamServersDisconnected_t callBack )
        {
            friendsView.Items.Clear();

            statusTextBox.AppendText( "Disconnected from Steam3: " + callBack.m_eResult + Environment.NewLine );
            statusTextBox.ScrollToCaret();
        }
        void SteamServerConnectionFailure( SteamServerConnectFailure_t callBack )
        {
            statusTextBox.AppendText( "Unable to connect to Steam3: " + callBack.m_eResult + Environment.NewLine );
            statusTextBox.ScrollToCaret();
        }

        public void RunCallbacks()
        {
            CallbackDispatcher.RunCallbacks( Steam3.HSteamPipe );
        }

        private void friendsView_MouseDoubleClick( object sender, MouseEventArgs e )
        {
            if ( friendsView.SelectedItems.Count == 0 )
                return;

            FriendListViewItem flvi = ( FriendListViewItem )friendsView.SelectedItems[ 0 ];

            ChatForm cf = chatManager.GetChatForm( flvi.FriendID );

            cf.Show( this );
        }
    }
}