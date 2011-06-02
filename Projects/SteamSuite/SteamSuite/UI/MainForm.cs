using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using Steam4NET;
using System.Text.RegularExpressions;
using System.Threading;

namespace SteamSuite
{
    public partial class MainForm : Form
    {
        SteamContext context;

        bool isAway = false;
        bool changingNames = false;

        List<NameEntry> nameEntries;

        Settings sets;        

        public MainForm( SteamContext context )
        {
            try
            {
                sets = Settings.Load( "settings.xml" );

                if ( sets == null )
                {
                    sets = new Settings();
                    sets.Save( "settings.xml" );
                }
            }
            catch ( Exception ex )
            {
                MessageBox.Show( "Unable to load settings!\n\n" + ex.ToString() );
				sets = new Settings();
            }

            InitializeComponent();

            foreach ( string str in sets.NameChanger )
            {
                txtNameChanger.Text += str + "\r\n";
            }

            chkNoEscape.Checked = sets.NoEscape;
            awayMessageBox.Text = sets.NoEscapeString;

            nameEntries = new List<NameEntry>();

            this.context = context;

            friendsList.SteamContext = context;

            txtPersonaName.Text = context.SteamFriends.GetPersonaName();

            for ( int x = -2 ; x < ( int )( EPersonaState.k_EPersonaStateMax + 2 ) ; x++ )
                cmbState.Items.Add( ( EPersonaState )x );

            cmbState.SelectedIndex = ( int )( context.SteamFriends.GetPersonaState() + 2 );

            for ( int i = 0 ; i < context.SteamFriends.GetFriendCount( ( int )EFriendFlags.k_EFriendFlagImmediate ) ; ++i )
            {
                Friend friend = new Friend();

                CSteamID steamId = context.SteamFriends.GetFriendByIndex( i, ( int )EFriendFlags.k_EFriendFlagImmediate );
                string friendName = context.SteamFriends.GetFriendPersonaName( steamId );

                friend.SteamID = steamId;
                friend.PersonaName = friendName;

                friendsList.Items.Add( friend );
            }

            friendsList.Sorted = true;
        }

        void PersonaStateChange( PersonaStateChange_t obj )
        {
            txtCallbacks.Invoke( ( MethodInvoker )delegate
            {
                txtCallbacks.AppendText( "PersonaStateChange_t: " + context.SteamFriends.GetFriendPersonaName( obj.m_ulSteamID ) + " (" + new CSteamID( obj.m_ulSteamID ).Render() + ") Flags: " + obj.m_nChangeFlags + Environment.NewLine );

                txtCallbacks.ScrollToCaret();
            } );
        }

        void UnhandledCallback( CallbackMsg_t msg )
        {
            txtCallbacks.Invoke( ( MethodInvoker )delegate
            {
                int iCall = ( msg.m_iCallback / 100 ) * 100;
                ECallbackType type = ( ECallbackType )iCall;

                txtCallbacks.AppendText( "Unhandled callback: " + msg.m_iCallback + " Type: " + type + " Size: " + msg.m_cubParam + Environment.NewLine );

                txtCallbacks.ScrollToCaret();
            } );
        }


        private void btnSetName_Click( object sender, EventArgs e )
        {
            context.SteamFriends.SetPersonaName( txtPersonaName.Text );
        }

        private void cmbState_SelectedIndexChanged( object sender, EventArgs e )
        {
            context.SteamFriends.SetPersonaState( ( EPersonaState )( cmbState.SelectedIndex - 2 ) );
        }


        private void friendsList_DoubleClick( object sender, EventArgs e )
        {
            if ( friendsList.SelectedItem == null )
                return;

            Friend friendObj = (Friend)friendsList.SelectedItem;

            foreach ( MessageForm msgForm in this.OwnedForms )
            {
                if ( msgForm.FriendID.SteamID == friendObj.SteamID )
                {
                    msgForm.Focus();

                    return;
                }
            }

            MessageForm mf = new MessageForm( context, friendObj, sets );

            mf.Show( this );
        }


        void FriendChatMsg_OnRun( FriendChatMsg_t param )
        {
            if ( context.SteamUser.GetSteamID() == param.m_ulSender )
                return;

            EChatEntryType type = EChatEntryType.k_EChatEntryTypeChatMsg;
            context.SteamFriends.GetChatMessage( param.m_ulSender, ( int )param.m_iChatID, new byte[ 0 ], 0, ref type );

            foreach ( MessageForm msgForm in this.OwnedForms )
            {
                if ( msgForm.FriendID.SteamID == param.m_ulSender )
                {
                    msgForm.RecievedMessage( param );

                    if ( chkNoEscape.Checked )
                    {
                        if ( type == ( EChatEntryType )6 )
                        {
                            msgForm.AwayMsg( param, awayMessageBox.Text );
                            return;
                        }
                    }

                    if ( isAway && type != EChatEntryType.k_EChatEntryTypeTyping && type != ( EChatEntryType )6 )
                    {
                        msgForm.AwayMsg( param, awayMessageBox.Text );
                        return;
                    }

                    return;
                }
            }

            if ( type == EChatEntryType.k_EChatEntryTypeTyping || type == ( EChatEntryType )6 )
                return;

            Friend friend = new Friend();

            friend.SteamID = param.m_ulSender;
            friend.PersonaName = context.SteamFriends.GetFriendPersonaName( friend.SteamID );

            MessageForm mf = new MessageForm( context, friend, sets );

            this.Invoke( ( MethodInvoker )delegate
            {
                mf.Show( this );
                mf.RecievedMessage( param );

                if ( isAway )
                    mf.AwayMsg( param, awayMessageBox.Text );
            } );
        }

        private void MainForm_FormClosing( object sender, FormClosingEventArgs e )
        {
            string[] lines = txtNameChanger.Text.Split( "\r\n".ToCharArray(), StringSplitOptions.RemoveEmptyEntries );

            sets.NameChanger.Clear();
            sets.NameChanger.AddRange( lines );

            sets.NoEscape = chkNoEscape.Checked;
            sets.NoEscapeString = awayMessageBox.Text;

            sets.Save( "settings.xml" );

            context.Shutdown();
        }

        private void btnGoAway_Click( object sender, EventArgs e )
        {
            if ( isAway )
            {
                btnGoAway.Text = "Go Away";
            }
            else
            {
                btnGoAway.Text = "Come Back";
            }

            isAway = !isAway;
        }

        int currentIndex;

        private void NameChangeTick( object obj )
        {
            if ( !changingNames )
                return;

            if (currentIndex >= nameEntries.Count)
                currentIndex = 0;

            NameEntry entry = nameEntries[ currentIndex ];

            context.SteamFriends.SetPersonaName( entry.Name );

            currentIndex++;

            nameTimer.Change(entry.Time, 0 );
        }

        System.Threading.Timer nameTimer;

        private void btnEnable_Click( object sender, EventArgs e )
        {
            if ( changingNames )
            {
                txtNameChanger.Enabled = true;

                nameEntries.Clear();

                if ( nameTimer != null )
                {
                    nameTimer.Change( Timeout.Infinite, Timeout.Infinite );

                    nameTimer.Dispose();
                    nameTimer = null;
                }

                btnEnable.Text = "Enable";

                changingNames = false;
            }
            else
            {
                string[] lines = txtNameChanger.Text.Split( "\r\n".ToCharArray(), StringSplitOptions.RemoveEmptyEntries );

                if ( lines.Length == 0 )
                    return;

                nameEntries.Clear();

                foreach ( string lineEntry in lines )
                {
                    NameEntry entry = NameEntry.Parse( lineEntry );

                    if ( entry == null )
                        continue;

                    nameEntries.Add( entry );
                }

                if ( nameEntries.Count == 0 )
                    return;

                txtNameChanger.Enabled = false;

                currentIndex = 0;

                changingNames = true;

                nameTimer = new System.Threading.Timer( NameChangeTick, null, 0, 0 );

                btnEnable.Text = "Disable";
            }

            string[] nameLines = txtNameChanger.Text.Split( "\r\n".ToCharArray(), StringSplitOptions.RemoveEmptyEntries );

            sets.NameChanger.Clear();
            sets.NameChanger.AddRange( nameLines );

            sets.NoEscape = chkNoEscape.Checked;
            sets.NoEscapeString = awayMessageBox.Text;

            sets.Save( "settings.xml" );
        }

        private void MainForm_Shown( object sender, EventArgs e )
        {
            context.FriendChatMsg.OnRun += new Callback<FriendChatMsg_t>.DispatchDelegate( FriendChatMsg_OnRun );

            ICallback psc = new Callback<PersonaStateChange_t>( PersonaStateChange, PersonaStateChange_t.k_iCallback );
            CallbackUnhandled unhandled = new CallbackUnhandled( UnhandledCallback );

            context.StartCallbacks();
        }

        private void btnAbout_Click( object sender, EventArgs e )
        {
            AboutForm af = new AboutForm();
            af.ShowDialog( this );
        }
    }

    class NameEntry
    {
        static readonly Regex NameRegex = new Regex( @"(?<name>.+?)\:(?<time>\d+)", RegexOptions.Compiled | RegexOptions.IgnoreCase | RegexOptions.ExplicitCapture | RegexOptions.Singleline );

        public string Name { get; set; }
        public int Time { get; set; }

        public static NameEntry Parse( string entry )
        {
            Match match = NameRegex.Match( entry );

            if ( !match.Success )
                return null;

            string name = match.Groups[ "name" ].Value.Trim();
            int time = int.Parse( match.Groups[ "time" ].Value.Trim() );

            NameEntry nameEntry = new NameEntry
            {
                Name = name,
                Time = time
            };

            return nameEntry;
        }
    }
}
