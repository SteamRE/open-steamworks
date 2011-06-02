using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Threading;
using Steam4NET;

namespace SteamSuite
{
    public partial class MessageForm : Form
    {
        SteamContext context;

        public Friend FriendID { get; set; }

        System.Threading.Timer typingTimer;
        System.Threading.Timer beeKeepTimer;

        bool isSpamming = false;

        Settings settings;

        public MessageForm( SteamContext context, Friend friendId, Settings sets)
        {
            InitializeComponent();

            this.context = context;
            this.FriendID = friendId;

            this.Text = friendId.PersonaName;

            settings = sets;

            foreach ( BeeKeeper bk in settings.BeeKeeper )
            {
                if ( bk.SteamID == ( ulong )FriendID.SteamID )
                {
                    foreach ( string str in bk.Entries )
                    {
                        txtResponses.Text += str + "\r\n";
                    }

                    checkBeeKeeper.Checked = bk.Enabled;

                    continue;
                }
            }

        }

        void typingTimer_Tick( object arg )
        {
            chatBox.Invoke( ( MethodInvoker )delegate
            {
                Text = FriendID.PersonaName;
            } );

            typingTimer = null;
        }

        private void inputBox_EnterPressed( object sender, EventArgs e )
        {
            SendText( inputBox.Text );

            inputBox.Text = "";
        }

        private void SendText( string text )
        {
            string input = text;
            EChatEntryType type = EChatEntryType.k_EChatEntryTypeChatMsg;

            if ( input.Length > 3 && input.IndexOf( "/me", StringComparison.OrdinalIgnoreCase ) == 0 )
            {
                input = input.Substring( 4, input.Length - 4 );
                type = EChatEntryType.k_EChatEntryTypeEmote;
            }

            byte[] inputBytes = Encoding.ASCII.GetBytes( input );

            context.SteamFriends.SendMsgToFriend( FriendID.SteamID, type, inputBytes, inputBytes.Length + 1 );

            chatBox.Invoke( ( MethodInvoker )delegate
            {
                if ( type == EChatEntryType.k_EChatEntryTypeChatMsg )
                    chatBox.AppendText( context.SteamFriends.GetPersonaName() + ": " + input + Environment.NewLine );
                else
                    chatBox.AppendText( "* " + context.SteamFriends.GetPersonaName() + " " + input + Environment.NewLine );

                chatBox.ScrollToCaret();
            } );
        }

        Random rnd = new Random( Environment.TickCount );
        public void RecievedMessage( FriendChatMsg_t param )
        {
            byte[] msgData = new byte[ 1024 * 4 ];
            EChatEntryType type = EChatEntryType.k_EChatEntryTypeChatMsg;

            int len = context.SteamFriends.GetChatMessage( param.m_ulSender, ( int )param.m_iChatID, msgData, msgData.Length, ref type );

            if ( type == EChatEntryType.k_EChatEntryTypeTyping )
            {
                chatBox.Invoke( ( MethodInvoker )delegate
                {
                    Text = context.SteamFriends.GetFriendPersonaName( param.m_ulSender ) + " is typing a message...";
                } );

                if ( typingTimer == null )
                    typingTimer = new System.Threading.Timer( typingTimer_Tick, null, 10000, Timeout.Infinite );

                return;
            }

            string text = "";

            if ( type == EChatEntryType.k_EChatEntryTypeChatMsg )
                text = context.SteamFriends.GetFriendPersonaName( param.m_ulSender ) + ": " + Encoding.ASCII.GetString( msgData, 0, len - 1 ) + Environment.NewLine;
            else if ( type == ( EChatEntryType )6 )
                text = "* " + context.SteamFriends.GetFriendPersonaName( param.m_ulSender ) + " has closed the window." + Environment.NewLine;
            else
                text = "* " + context.SteamFriends.GetFriendPersonaName( param.m_ulSender ) + " " + Encoding.ASCII.GetString( msgData, 0, len - 1 ) + Environment.NewLine;

            chatBox.Invoke( ( MethodInvoker )delegate
            {
                Text = context.SteamFriends.GetFriendPersonaName( param.m_ulSender );
            } );

            chatBox.Invoke( ( MethodInvoker )delegate
            {
                chatBox.AppendText( text );
                chatBox.ScrollToCaret();
                FlashWindow.Flash( this );
            } );

            if ( checkBeeKeeper.Checked && type != EChatEntryType.k_EChatEntryTypeTyping && type != ( EChatEntryType )6 )
            {
                txtResponses.Invoke( ( MethodInvoker )delegate
                {
                    string[] responses = txtResponses.Text.Split( "\r\n".ToCharArray(), StringSplitOptions.RemoveEmptyEntries );

                    if ( responses.Length == 0 )
                        return;

                    int index = rnd.Next( 0, responses.Length );

                    string resp = responses[ index ];

                    if ( beeKeepTimer == null )
                        beeKeepTimer = new System.Threading.Timer( BeeKeeper, resp, 2000, Timeout.Infinite );
                } );
            }
        }

        void BeeKeeper( object obj )
        {
            string response = ( string )obj;

            context.SteamFriends.SendMsgToFriend( FriendID.SteamID, EChatEntryType.k_EChatEntryTypeTyping, new byte[ 0 ], 0 );

            int length = response.Length;

            int time = ( int )( ( float )length / ( ( 4.5f * 50.0f ) / 60.0f ) );

            Thread.Sleep( time * 1000 );

            SendText( response );

            beeKeepTimer.Change( Timeout.Infinite, Timeout.Infinite );

            beeKeepTimer = null;
        }

        private void MessageForm_FormClosing( object sender, FormClosingEventArgs e )
        {
            string[] responses = txtResponses.Text.Split( "\r\n".ToCharArray(), StringSplitOptions.RemoveEmptyEntries );

            int index = settings.IndexOfSteamID( FriendID.SteamID );

            BeeKeeper bk = new BeeKeeper();

            bk.Entries.AddRange( responses );

            bk.Enabled = checkBeeKeeper.Checked;
            bk.SteamID = FriendID.SteamID;

            if ( index == -1 )
                settings.BeeKeeper.Add( bk );
            else
                settings.BeeKeeper[ index ] = bk;



            if ( typingTimer != null )
            {
                typingTimer.Change( Timeout.Infinite, Timeout.Infinite );
                typingTimer.Dispose();
            }

            if ( beeKeepTimer != null )
            {
                beeKeepTimer.Change( Timeout.Infinite, Timeout.Infinite );
                beeKeepTimer.Dispose();
            }
        }

        public void AwayMsg( FriendChatMsg_t param, string msg )
        {
            byte[] text = Encoding.ASCII.GetBytes( msg );

            context.SteamFriends.SendMsgToFriend( param.m_ulSender, EChatEntryType.k_EChatEntryTypeChatMsg, text, text.Length + 1 );

            chatBox.Invoke( ( MethodInvoker )delegate
            {
                chatBox.AppendText( context.SteamFriends.GetPersonaName() + ": " + msg + Environment.NewLine );
                chatBox.ScrollToCaret();
                FlashWindow.Flash( this );
            } );
        }

        void SpamTick( object obj )
        {
            if ( !isSpamming )
                return;

            txtSpam.Invoke( ( MethodInvoker )delegate
            {
                SendText( txtSpam.Text );
            } );
        }

        System.Threading.Timer spamTimer;

        private void btnSpam_Click( object sender, EventArgs e )
        {
            if ( isSpamming )
            {
                if ( spamTimer != null )
                {
                    spamTimer.Change( Timeout.Infinite, Timeout.Infinite );
                    spamTimer.Dispose();

                    spamTimer = null;
                }

                txtSpam.Enabled = true;
                txtDelay.Enabled = true;

                btnSpam.Text = "Begin";

                isSpamming = false;
            }
            else
            {
                if ( spamTimer != null )
                {
                    spamTimer.Change( Timeout.Infinite, Timeout.Infinite );
                    spamTimer.Dispose();

                    spamTimer = null;
                }

                int delay = 0;

                if ( !int.TryParse( txtDelay.Text, out delay ) )
                    return;

                spamTimer = new System.Threading.Timer( SpamTick, null, 0, delay );

                txtSpam.Enabled = false;
                txtDelay.Enabled = false;

                btnSpam.Text = "Stop";

                isSpamming = true;
            }
        }
    }
}
