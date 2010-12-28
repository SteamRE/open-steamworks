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

            FindResult = new APICallCallback<LeaderboardFindResult_t>( LeaderboardFindResult_t.k_iCallback );
            ScoresDownloaded = new APICallCallback<LeaderboardScoresDownloaded_t>( LeaderboardScoresDownloaded_t.k_iCallback );
            ScoreUploaded = new APICallCallback<LeaderboardScoreUploaded_t>( LeaderboardScoreUploaded_t.k_iCallback );

            Environment.SetEnvironmentVariable( "SteamAppId", appID.ToString() );

            SteamContext.Initialize( false );

            DebugLog.AppendText( "Getting ISteam interface: ISteamFriends008..." );

            Friends = Steamworks.CastInterface<ISteamFriends008>(
                SteamContext.SteamClient.GetISteamFriends(
                    SteamContext.HSteamPipe,
                    SteamContext.HSteamUser,
                    "SteamFriends008"
                )
            );

            DebugLog.AppendText( string.Format( "ISteamFriends008 = 0x{0:8x}", Friends ) );

            DebugLog.AppendText( "Getting ISteam interface: ISteamUserStats007..." );

            UserStats = Steamworks.CastInterface<ISteamUserStats007>(
                SteamContext.SteamClient.GetISteamUserStats(
                    SteamContext.HSteamUser,
                    SteamContext.HSteamPipe,
                    "STEAMUSERSTATS_INTERFACE_VERSION007"
                )
            );

            DebugLog.AppendText( string.Format( "ISteamUserStats007 = 0x{0:8X}{1}", UserStats, Environment.NewLine ) );

        }

        public static LeaderboardEntry_t GetLBEntry( ulong hEntry, int index )
        {
            LeaderboardEntry_t entry = new LeaderboardEntry_t();
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
