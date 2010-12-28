using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using Steam4NET;
using System.IO;
using System.Reflection;

namespace SAPIBase
{
    public partial class MainForm : Form
    {
        AddInManager addInManager;

        public MainForm()
        {
            addInManager = new AddInManager();

            InitializeComponent();

            this.Icon = Icon.FromHandle( Properties.Resources.world.GetHicon() );

            SetStatus( "Loading Addins..." );

            addInManager.LoadAddIns( Application.StartupPath );

            if ( addInManager.GetAddIns().Length == 0 )
                Util.MsgBox( this, "Warning: No AddIns loaded. Your installation may be corrupt." );

            SetStatus( "None" );
        }


        public void UpdateSelected( GameControl gc )
        {
            if ( gc == null )
            {
                gameToolStripMenuItem.Visible = false;
                return;
            }

            gameToolStripMenuItem.Text = string.Format( "[{0}]", gc.GameName );
            gameToolStripMenuItem.Visible = true;
        }

        public void ShowContextMenu( GameControl gc, Point pos )
        {
            gameContextMenu.Show( gc, pos );
        }



        void RefreshGames()
        {
            SetStatus( "Refreshing games..." );

            DebugLog.AppendText( "Steam - Refreshing Games..." );

            Steam.App[] apps = Steam.GetSubscribedApps( ( app ) =>
                {

                    // hide anything that isn't an installable game
                    if ( Settings.HideNonInstallable && Steam.GetAppData( app.uId, "gamedir" ) == "" )
                        return false;

                    string state = Steam.GetAppData( app.uId, "state" );

                    // hide sdks
                    if ( Settings.HideTools && state == "eStateTool" )
                        return false;

                    // hide unavailable
                    if ( Settings.HideUnavailable && state == "eStateUnAvailable" )
                        return false;

                    // hide demos
                    if ( Settings.HideDemos && Steam.GetAppData( app.uId, "DemoOfAppID" ) != "" )
                        return false;

                    // hide dlc
                    if ( Settings.HideDLC && Steam.GetAppData( app.uId, "DLCForAppID" ) != "" )
                        return false;

                    // hide movies
                    if ( Settings.HideMovies && Steam.GetAppData( app.uId, "IsMediaFile" ) == "1" )
                        return false;

                    return true;

                } );

            if ( apps == null || apps.Length == 0 )
            {
                DebugLog.AppendText( "Failed!{0}", Environment.NewLine );
                return;
            }

            gamePanel.SuspendLayout();

            gamePanel.Controls.Clear();

            foreach ( Steam.App app in apps )
            {
                GameControl gc = new GameControl()
                {
                    AppID = app.AppID,
                    GameName = app.Name,
                    Icon = app.Icon,
                };

                gc.RequestIcon();

                gamePanel.Controls.Add( gc );
            }

            gamePanel.ResumeLayout();

            DebugLog.AppendText( "Done!{0}", Environment.NewLine );

            SetStatus( "None" );
        }




        void SetStatus( string text )
        {
            statusLabel.Text = "Status: " + text;
        }

        AddInMenuItem[] BuildMenuItems( GameControl gc )
        {
            AddIn[] addIns = addInManager.GetAddIns();
            AddInMenuItem[] menuItems = new AddInMenuItem[ addIns.Length ];

            for ( int x = 0 ; x < addIns.Length ; ++x )
                menuItems[ x ] = new AddInMenuItem( addInManager, addIns[ x ], gc.AppID );

            return menuItems;
        }

        protected override void OnShown( EventArgs e )
        {
            base.OnShown( e );

            RefreshGames();
        }


        private void refreshGamesToolStripMenuItem_Click( object sender, EventArgs e )
        {
            RefreshGames();
        }

        private void gameToolStripMenuItem_DropDownOpening( object sender, EventArgs e )
        {
            GameControl gc = gamePanel.SelectedGame;

            if ( gc == null )
                return;

            gameToolStripMenuItem.DropDownItems.Clear();
            gameToolStripMenuItem.DropDownItems.AddRange( BuildMenuItems( gc ) );
        }

        private void gameContextMenu_Opening( object sender, CancelEventArgs e )
        {
            GameControl gc = gamePanel.SelectedGame;
            
            if ( gc == null )
                return;

            AddInMenuItem[] menuItems = BuildMenuItems( gc );

            gameContextMenu.Items.Clear();

            var nameItem = new ToolStripMenuItem( string.Format( "[{0}]", gc.GameName ) );
            nameItem.Enabled = false;

            gameContextMenu.Items.Add( nameItem );
            gameContextMenu.Items.Add( new ToolStripSeparator() );
            gameContextMenu.Items.AddRange( menuItems );
            gameContextMenu.Items.Add( new ToolStripSeparator() );

            var refreshItem = new ToolStripMenuItem( "Refresh Games" );
            refreshItem.Click += ( sender2, e2 ) =>
                {
                    RefreshGames();
                };

            gameContextMenu.Items.Add( refreshItem );
        }

        private void settingsToolStripMenuItem_Click( object sender, EventArgs e )
        {
            new SettingsForm().ShowDialog( this );
        }

        private void exitToolStripMenuItem_Click( object sender, EventArgs e )
        {
            this.Close();
        }

        private void aboutToolStripMenuItem_Click( object sender, EventArgs e )
        {
            // todo: show about window
            Util.MsgBox( this, "SAPIBase Launcher\nBy: VoiDeD\n\nIRC: #opensteamworks @ irc.gamesurge.net" );
        }
    }
}
