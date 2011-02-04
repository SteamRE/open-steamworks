using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using Steam4NET;
using FriendManager.Properties;

namespace FriendManager
{
    partial class MainForm : Form
    {
        bool bClosing;
        object closeLock = new object();

        public MainForm()
        {
            InitializeComponent();

            this.Icon = Icon.FromHandle( Resources.MainIcon.GetHicon() );

            selfControl.SetSteamID( new Friend( SteamContext.SteamUser.GetSteamID() ) );
            selfControl.BorderStyle = BorderStyle.None;

            ReloadFriends();

            SteamContext.OnStateChange.OnRun += new Callback<PersonaStateChange_t>.DispatchDelegate( OnStateChange_OnRun );
        }

        void HandleStateChange( PersonaStateChange_t param )
        {
            FriendControl fc = friendsFlow.GetFriendControl( new Friend( param.m_ulSteamID ) );

            if ( fc == null )
                return;

            // force update
            fc.SetSteamID( fc.Friend );
        }

        void OnStateChange_OnRun( PersonaStateChange_t param )
        {
            lock ( closeLock )
            {
                if ( bClosing )
                    return;

                this.Invoke( new MethodInvoker( () => HandleStateChange( param ) ) );
            }
        }

        void ReloadFriends()
        {
            List<Friend> friendsList = GetFriends();

            friendsList.Sort( ( a, b ) =>
            {
                if ( a.IsInGame() && b.IsInGame() )
                    return StringComparer.OrdinalIgnoreCase.Compare( a.GetName(), b.GetName() );

                if ( !a.IsOnline() && !b.IsOnline() )
                    return StringComparer.OrdinalIgnoreCase.Compare( a.GetName(), b.GetName() );

                if ( a.IsOnline() && !a.IsInGame() && b.IsOnline() && !b.IsInGame() )
                    return StringComparer.OrdinalIgnoreCase.Compare( a.GetName(), b.GetName() );

                if ( a.IsInGame() && !b.IsInGame() )
                    return -1;

                if ( a.IsOnline() && !b.IsOnline() )
                    return -1;

                if ( !a.IsInGame() && b.IsInGame() )
                    return 1;

                if ( !a.IsOnline() && b.IsOnline() )
                    return 1;

                return 0;

            } );

            int scroll = friendsFlow.VerticalScroll.Value;

            friendsFlow.SuspendLayout();
            friendsFlow.Controls.Clear();

            foreach ( Friend friend in friendsList )
            {
                FriendControl fc = new FriendControl( friend );

                friendsFlow.Controls.Add( fc );
            }

            ResizeFriends();

            friendsFlow.ResumeLayout();
            friendsFlow.PerformLayout();
            friendsFlow.Refresh();

            friendsFlow.VerticalScroll.Value = scroll;
        }

        private void ResizeFriends()
        {
            foreach ( FriendControl fc in friendsFlow.Controls )
            {
                fc.Width = this.Width - 34;
            }
        }

        List<Friend> GetFriends()
        {
            List<Friend> friends = new List<Friend>();

            int friendCount = SteamContext.ClientFriends.GetFriendCount( ( int )EFriendFlags.k_EFriendFlagImmediate );
            for ( int x = 0 ; x < friendCount ; ++x )
            {
                ulong friendId = SteamContext.ClientFriends.GetFriendByIndex( x, ( int )EFriendFlags.k_EFriendFlagImmediate );

                Friend friend = new Friend( friendId );
                friends.Add( friend );
            }

            return friends;
        }

        public void ShowContextMenu( Control displayControl, FriendControl friendControl, Point point )
        {
            if ( friendControl.Friend.SteamID == SteamContext.SteamUser.GetSteamID() )
                return;

            contextMenu.Show( displayControl, point );
            contextMenu.Tag = friendControl;
        }

        private void setAliasToolStripMenuItem_Click( object sender, EventArgs e )
        {
            FriendControl fc = contextMenu.Tag as FriendControl;

            if ( fc == null )
                return;

            AliasForm af = new AliasForm();

            if ( af.ShowDialog( this ) != DialogResult.OK )
                return;

            SteamContext.ClientFriends.SetFriendAlias( fc.Friend.SteamID, af.Alias );
        }
        private void removeAliasToolStripMenuItem_Click( object sender, EventArgs e )
        {
            FriendControl fc = contextMenu.Tag as FriendControl;

            if ( fc == null )
                return;

            SteamContext.ClientFriends.SetFriendAlias( fc.Friend.SteamID, "" );
        }

        private void MainForm_Resize( object sender, EventArgs e )
        {
            friendsFlow.SuspendLayout();

            ResizeFriends();

            friendsFlow.ResumeLayout();
        }

        private void MainForm_FormClosing( object sender, FormClosingEventArgs e )
        {
            lock ( closeLock )
            {
                bClosing = true;

            }
            SteamContext.StopCallbacks();
        }

        private void MainForm_Shown( object sender, EventArgs e )
        {
            SteamContext.StartCallbacks();
        }
    }
}
