using System;
using System.Collections.Generic;
using System.Text;
using Steam4NET;
using SAPIBase;

namespace LBEditor
{
    static class LBContext
    {
        public static ISteamUserStats007 UserStats { get; private set; }
        public static ISteamFriends008 Friends { get; private set; }

        public static APICallCallback<LeaderboardFindResult_t> FindResult { get; private set; }
        public static APICallCallback<LeaderboardScoresDownloaded_t> ScoresDownloaded { get; private set; }
        public static APICallCallback<LeaderboardScoreUploaded_t> ScoreUploaded { get; private set; }

        public static void Initialize( int appID )
        {

            FindResult = new APICallCallback<LeaderboardFindResult_t>();
            ScoresDownloaded = new APICallCallback<LeaderboardScoresDownloaded_t>();
            ScoreUploaded = new APICallCallback<LeaderboardScoreUploaded_t>();

            Environment.SetEnvironmentVariable( "SteamAppId", appID.ToString() );

            SteamContext.Initialize( false );

            DebugLog.AppendText( "Getting ISteam interface: ISteamFriends008..." );

            Friends = SteamContext.SteamClient.GetISteamFriends<ISteamFriends008>(
                SteamContext.HSteamPipe,
                SteamContext.HSteamUser
            );

            DebugLog.AppendText( string.Format( "ISteamFriends008 = 0x{0:8x}", Friends ) );

            DebugLog.AppendText( "Getting ISteam interface: ISteamUserStats007..." );

            UserStats = SteamContext.SteamClient.GetISteamUserStats<ISteamUserStats007>(
                SteamContext.HSteamUser,
                SteamContext.HSteamPipe
            );

            DebugLog.AppendText( string.Format( "ISteamUserStats007 = 0x{0:8X}{1}", UserStats, Environment.NewLine ) );

        }

        public static LeaderboardEntry001_t GetLBEntry( ulong hEntry, int index )
        {
            LeaderboardEntry001_t entry = new LeaderboardEntry001_t();
            int ignored = 0;

            UserStats.GetDownloadedLeaderboardEntry( hEntry, index, ref entry, ref ignored, 0 );

            return entry;
        }

        public static void Shutdown()
        {
            SteamContext.Shutdown();
        }
    }
}
