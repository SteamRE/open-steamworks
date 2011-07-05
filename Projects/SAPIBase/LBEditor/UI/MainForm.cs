using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using SAPIBase;
using Steam4NET;

namespace LBEditor
{
    public partial class MainForm : Form
    {
        ulong findCall = 0;
        ulong personalCall = 0;
        ulong leaderCall = 0;
        ulong uploadCall = 0;

        ulong currentBoard = 0;


        public MainForm( int appId )
        {
            InitializeComponent();

            this.Icon = Icon.FromHandle( Properties.Resources.application_view_list.GetHicon() );

            LBContext.FindResult.OnRun += new APICallCallback<LeaderboardFindResult_t>.APIDispatchDelegate( FindResult_OnRun );
            LBContext.ScoresDownloaded.OnRun += new APICallCallback<LeaderboardScoresDownloaded_t>.APIDispatchDelegate( ScoresDownloaded_OnRun );
            LBContext.ScoreUploaded.OnRun += new APICallCallback<LeaderboardScoreUploaded_t>.APIDispatchDelegate( ScoreUploaded_OnRun );

            this.Text = string.Format( "Leaderboard Editor - [ {0} / AppID {1} ]", Steam.GetAppData( ( uint )appId, "name" ), appId );

        }


        private void LoadLeaderboard( ulong hLeaderboard )
        {
            leaderCall = LBContext.UserStats.DownloadLeaderboardEntries( hLeaderboard, ELeaderboardDataRequest.k_ELeaderboardDataRequestGlobal, 1, 10 );
            LBContext.ScoresDownloaded.SetAPICallHandle( leaderCall );
        }

        private void LoadSelfRank( ulong hLeaderboard )
        {
            personalCall = LBContext.UserStats.DownloadLeaderboardEntries( hLeaderboard, ELeaderboardDataRequest.k_ELeaderboardDataRequestGlobalAroundUser, 0, 0 );
            LBContext.ScoresDownloaded.SetAPICallHandle( personalCall );
        }

        void ScoresDownloaded_OnRun( ulong callHandle, LeaderboardScoresDownloaded_t param )
        {
            if ( callHandle == personalCall )
            {
                try
                {

                    this.Invoke( new MethodInvoker( () =>
                        {
                            LeaderboardEntry001_t entry = LBContext.GetLBEntry( param.m_hSteamLeaderboardEntries, 0 );

                            rankLabel.Text = string.Format( "#{0}", entry.m_nGlobalRank );
                            rankBox.Text = entry.m_nScore.ToString();
                        } ) );

                    LoadLeaderboard( param.m_hSteamLeaderboard );

                }
                finally
                {
                    personalCall = 0;
                }
            }
            else if ( callHandle == leaderCall )
            {
                try
                {
                    this.Invoke( new MethodInvoker( () =>
                        {
                            leaderPanel.Controls.Clear();

                            for ( int x = 0 ; x < param.m_cEntryCount ; ++x )
                            {
                                RankControl rc = new RankControl( LBContext.GetLBEntry( param.m_hSteamLeaderboardEntries, x ) );

                                leaderPanel.Controls.Add( rc );
                            }

                        } ) );
                }
                finally
                {
                    leaderCall = 0;
                }
            }
        }

        void FindResult_OnRun( ulong callHandle, LeaderboardFindResult_t param )
        {
            if ( callHandle != findCall )
                return; // we'll ignore results which we're not expecting

            try
            {

                this.Invoke( new MethodInvoker( () =>
                    {

                        if ( param.m_bLeaderboardFound == 0 )
                        {
                            rankGroupBox.Enabled = false;
                            Util.MsgBox( this, "No leaderboard found!" );
                            return;
                        }

                        rankGroupBox.Enabled = true;

                    } ) );


                currentBoard = param.m_hSteamLeaderboard;

                LoadSelfRank( param.m_hSteamLeaderboard );

            }
            finally
            {
                findCall = 0;
            }
        }

        void ScoreUploaded_OnRun( ulong callHandle, LeaderboardScoreUploaded_t param )
        {
            if ( callHandle != uploadCall )
                return;

            try
            {
                LoadSelfRank( param.m_hSteamLeaderboard );
            }
            finally
            {
                uploadCall = 0;
            }
        }

        private void searchButton_Click( object sender, EventArgs e )
        {
            findCall = LBContext.UserStats.FindLeaderboard( searchBox.Text );
            LBContext.FindResult.SetAPICallHandle( findCall );
        }

        private void setButton_Click( object sender, EventArgs e )
        {
            int score;

            if ( !int.TryParse( rankBox.Text, out score ) )
            {
                Util.MsgBox( this, "Invalid rank!" );
                return;
            }

            int ignored = 0;

            uploadCall = LBContext.UserStats.UploadLeaderboardScore( currentBoard, ELeaderboardUploadScoreMethod.k_ELeaderboardUploadScoreMethodForceUpdate, score, ref ignored, 0 );
            LBContext.ScoreUploaded.SetAPICallHandle( uploadCall );
        }
    }
}
