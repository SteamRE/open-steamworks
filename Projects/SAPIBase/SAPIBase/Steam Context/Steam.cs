using System;
using System.Collections.Generic;
using System.Text;
using Steam4NET;
using System.Runtime.InteropServices;

namespace SAPIBase
{
    public static class Steam
    {
        public delegate bool ReturnCriteria( TSteamApp steamApp );

        public struct App
        {
            public string Name { get; set; }
            public uint AppID { get; set; }

            public string Icon { get; set; }
        }

        public static string GetAppData( uint appId, string key )
        {
            StringBuilder sb = new StringBuilder( 255 );
            SteamContext.ClientApps.GetAppData( appId, key, sb );

            return sb.ToString();
        }

        public static bool GetAppInternal( uint appId, out TSteamApp app )
        {
            TSteamError error = new TSteamError();
            app = new TSteamApp()
            {
                uMaxNameChars = 255,
                uMaxCurrentVersionLabelChars = 255,
                uMaxLatestVersionLabelChars = 255,
                uMaxInstallDirNameChars = 255,

                szName = new string( '\0', 255 ),
                szCurrentVersionLabel = new string( '\0', 255 ),
                szLatestVersionLabel = new string( '\0', 255 ),
                szInstallDirName = new string( '\0', 255 ),
            };

            if ( SteamContext.Steam.EnumerateApp( appId, ref app, ref error ) == 0 )
            {
                DebugLog.AppendText( "ISteam006::EnumerateApp( {0} ) Failed: {1}", appId, error.szDesc );
                return false;
            }

            return true;
        }

        public static bool GetAppIds( out uint[] appIds )
        {
            TSteamError error = new TSteamError();
            TSteamAppStats stats = new TSteamAppStats();

            appIds = null;

            if ( SteamContext.Steam.GetAppStats( ref stats, ref error ) == 0 )
            {
                DebugLog.AppendText( "ISteam006::GetAppStats() Failed: {0}", error.szDesc );
                return false;
            }

            appIds = new uint[ stats.uNumApps ];

            if ( SteamContext.Steam.GetAppIds( appIds, ( uint )appIds.Length, ref error ) == 0 )
            {
                DebugLog.AppendText( "ISteam006::GetAppIds( {0} ) Failed: {1}", appIds.Length, error.szDesc );
                return false;
            }

            return true;
        }

        public static bool GetAppDependencies( uint appId, out uint[] depends )
        {
            TSteamError error = new TSteamError();

            depends = null;

            TSteamApp steamApp;

            if ( !GetAppInternal( appId, out steamApp ) )
                return false;

            if ( steamApp.uNumDependencies == 0 )
                return false;

            depends = new uint[ steamApp.uNumDependencies ];

            if ( SteamContext.Steam.GetAppDependencies( appId, depends, ( uint )depends.Length, ref error ) == 0 )
            {
                DebugLog.AppendText( "ISteam006::GetAppDependencies( {0}, {1} ) Failed: {2}", appId, depends.Length, error.szDesc );
                return false;
            }

            return true;
        }

        public static bool IsAppSubscribed( uint appId )
        {
            TSteamError error = new TSteamError();

            int bSubscribed = 0;
            int reserved = 0;

            if ( SteamContext.Steam.IsAppSubscribed( appId, ref bSubscribed, ref reserved, ref error ) == 0 )
            {
                DebugLog.AppendText( "ISteam006::IsAppSubscribed( {0} ) Failed: {1} ", appId, error.szDesc );
                return false;
            }

            return bSubscribed == 1;
        }

        public static App[] GetSubscribedApps( ReturnCriteria rc )
        {
            List<App> appList = new List<App>();

            uint[] appIDs;

            if ( !GetAppIds( out appIDs ) )
                return null;

            foreach ( uint appID in appIDs )
            {

                if ( !IsAppSubscribed( appID ) )
                    continue;

                TSteamApp steamApp;

                if ( !GetAppInternal( appID, out steamApp ) )
                    continue;

                if ( rc != null )
                {
                    if ( !rc( steamApp ) )
                        continue;
                }

                string icon = GetAppData( appID, "logo" );

                App stmApp = new App()
                {
                    Name = steamApp.szName,
                    AppID = appID,

                    Icon = icon,
                };

                appList.Add( stmApp );
            }

            return appList.ToArray();
        }
    }
}
