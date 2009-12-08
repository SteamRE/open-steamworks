using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using dotnetworks;
using System.Diagnostics;

namespace StatsSuite
{
    public partial class MainForm : Form
    {
        SteamClient008 client;
        ClientEngine clientEngine;

        SteamPipeHandle pipe;
        SteamUserHandle user;

        SteamUser012 steamUser;
        ClientUtils clientUtils;

        StatsAccessor statsAcc;

        bool aboutEnabled;

        public MainForm(bool enableAbout)
        {
            aboutEnabled = enableAbout;

            InitializeComponent();
        }

        private void exitToolStripMenuItem_Click( object sender, EventArgs e )
        {
            this.Close();
        }

        private void aboutToolStripMenuItem_Click( object sender, EventArgs e )
        {
            if ( aboutEnabled )
            {
                toolStripStatusLabel1.Text = "Teh...";
                new About().ShowDialog();
                toolStripStatusLabel1.Text = "Ready.";
            }
            else
            {
                MessageBox.Show( this,
                    "TF2 Stats Suite.\nAuthors:\n\n* SteveUK\n* VoiDeD",
                    "TF2 Stats Suite", MessageBoxButtons.OK, MessageBoxIcon.Information );
            }
        }

        private void MainForm_FormClosing( object sender, FormClosingEventArgs e )
        {
            if ( statsAcc == null )
            {
                MessageBox.Show( "Unable to save stats. Stats were never loaded?" );
                return;
            }

            // personal liability
            DialogResult cont = MessageBox.Show( this,
                "Are you sure you wish to set your stats to this?\n\n" +
                "PLEASE NOTE: In order for stats to be set (due to the nature of the steam_api) they must be CLEARED before setting!!\n" +
                "If you lose your connection to steam between the clearing and saving process, your stats will be erased!!\n\n" +
                "Are you sure you wish to continue?\n\nYes: Save stats. No: Don't save stats and exit. Cancel: Don't save, don't exit.",
                "TF2 Stats Suite", MessageBoxButtons.YesNoCancel
            );

            if ( cont == DialogResult.Cancel )
            {
                toolStripStatusLabel1.Text = "Stats not saved.";
                e.Cancel = true;
                return;
            }
            if ( cont == DialogResult.No )
            {
                toolStripStatusLabel1.Text = "Stats not saved, exiting...";
                return;
            }

            // lets make sure we can store them before we clear them!
            if ( !statsAcc.SaveStats() )
            {
                toolStripStatusLabel1.Text = "Unable to save stats. Your connection to steam servers may have been interrupted.";
                MessageBox.Show( this, "Unable to save stats. Your connection to steam servers may have been interrupted.\n\n" +
                    "Please note: your stats have not been cleared at this point.", "TF2 Stats Suite"
                );
                e.Cancel = true;
                return;
            }

            // clearing them because you cannot set values lower than what's already set
            statsAcc.ClearStats();

            foreach ( ClassEditControl cec in flowLayoutPanel1.Controls )
            {
                cec.SetStat( statsAcc );
                toolStripStatusLabel1.Text = "Saving stat '" + cec.Class + "'...";
                Application.DoEvents();
            }

            // if we can't store the stats, we're never exiting.. it's a gift to the user, you see...
            if ( !statsAcc.SaveStats() )
            {
                MessageBox.Show( this, "MAJOR ERROR: UNABLE TO STORE STATS AFTER CLEARING THEM. YOUR STATS HAVE BEEN CLEARED!\n\n" +
                    "You can try another attempt at saving them by closing the window again.", "TF2 Stats Suite"
                );

                e.Cancel = true;
                return;
            }
        }

        private void MainForm_Load( object sender, EventArgs e )
        {
            ClassEditControl scout = new ClassEditControl( "Scout" );
            scout.ClassImage = Properties.Resources.scout;

            // heavy
            ClassEditControl heavy = new ClassEditControl( "Heavy" );
            heavy.ClassImage = Properties.Resources.heavy;

            // medic
            ClassEditControl medic = new ClassEditControl( "Medic" );
            medic.ClassImage = Properties.Resources.medic;

            // soldier
            ClassEditControl soldier = new ClassEditControl( "Soldier" );
            soldier.ClassImage = Properties.Resources.soldier;

            // engi
            ClassEditControl engineer = new ClassEditControl( "Engineer" );
            engineer.ClassImage = Properties.Resources.engineer;

            // spy
            ClassEditControl spy = new ClassEditControl( "Spy" );
            spy.ClassImage = Properties.Resources.spy;

            // sniper
            ClassEditControl sniper = new ClassEditControl( "Sniper" );
            sniper.ClassImage = Properties.Resources.sniper;

            // demo
            ClassEditControl demo = new ClassEditControl( "Demoman" );
            demo.ClassImage = Properties.Resources.demoman;

            // pyro
            ClassEditControl pyro = new ClassEditControl( "Pyro" );
            pyro.ClassImage = Properties.Resources.pyro;

            flowLayoutPanel1.Controls.Add( scout );
            flowLayoutPanel1.Controls.Add( heavy );
            flowLayoutPanel1.Controls.Add( medic );
            flowLayoutPanel1.Controls.Add( soldier );
            flowLayoutPanel1.Controls.Add( engineer );
            flowLayoutPanel1.Controls.Add( spy );
            flowLayoutPanel1.Controls.Add( sniper );
            flowLayoutPanel1.Controls.Add( demo );
            flowLayoutPanel1.Controls.Add( pyro );


            toolStripStatusLabel1.Text = "Initializing steamworks...";
            
            try
            {
                int error;
                client = ( SteamClient008 )Steamworks.CreateInterface( SteamClient008.InterfaceVersion, out error );

                if ( client == null )
                    throw new InvalidOperationException( "Unable to create ISteamClient." );

                pipe = client.CreateSteamPipe();
                if ( pipe == SteamPipeHandle.InvalidHandle )
                    throw new InvalidOperationException( "Unable to create steam pipe." );

                user = client.ConnectToGlobalUser( pipe );

                clientEngine = ( ClientEngine )Steamworks.CreateInterface( ClientEngine.InterfaceVersion, out error );

                if ( clientEngine == null )
                    throw new InvalidOperationException( "Unable to create IClientEngine." );
            }
            catch (Exception ex)
            {
                MessageBox.Show( this, "Unable to initialize steamworks. Please ensure the following:\n\n" +
                    " * steamclient.dll, tier0_s.dll, vstdlib_s.dll, are present in the running directory\n" +
                    " * You are logged into steam and are online.\n\nAdditional Details: " + ex.Message, "TF2 Stats Suite"
                );

                this.Close();
                return;
            }

            toolStripStatusLabel1.Text = "Loading stats...";

            statsAcc = new StatsAccessor( client, pipe, user, 440 );

            steamUser = ( SteamUser012 )client.GetISteamUser( user, pipe, SteamUser012.InterfaceVersion );
            clientUtils = ( ClientUtils )clientEngine.GetIClientUtils( pipe, ClientUtils.InterfaceVersion );

            clientUtils.SetAppIDForCurrentPipe( new AppID( 440 ) );

            foreach ( ClassEditControl cec in flowLayoutPanel1.Controls )
            {
                toolStripStatusLabel1.Text = "Loading stats for '" + cec.Class + "'...";
                cec.LoadStats( statsAcc );
                Application.DoEvents();
            }

            toolStripStatusLabel1.Text = "Stats fully loaded!";
        }

        private void maxAllStatsToolStripMenuItem_Click( object sender, EventArgs e )
        {
            DialogResult result = MessageBox.Show( this, 
                "Please note: this will max the values for your stats, but will not save them until you close the window.\n\n" +
                "Continue?", "TF2 Stats Suite", MessageBoxButtons.YesNo, MessageBoxIcon.Question
            );

            if ( result != DialogResult.Yes )
                return;

            foreach ( ClassEditControl cec in flowLayoutPanel1.Controls )
            {
                cec.MaxStats();
            }
        }

        private void clearAllStatsToolStripMenuItem_Click( object sender, EventArgs e )
        {
            DialogResult result = MessageBox.Show( this,
                "Please note: this will clear the values for your stats, but will not save them until you close the window.\n\n" +
                "Continue?", "TF2 Stats Suite", MessageBoxButtons.YesNo, MessageBoxIcon.Question
            );

            if ( result != DialogResult.Yes )
                return;

            foreach ( ClassEditControl cec in flowLayoutPanel1.Controls )
            {
                cec.ClearStats();
            }
        }

        private void checkStatsOnlineToolStripMenuItem_Click( object sender, EventArgs e )
        {
            Process.Start( "http://steamcommunity.com/profiles/" + steamUser.GetSteamID().ConvertToUint64() + "/stats/tf2" );
        }
    }
}
