using System;
using System.Collections.Generic;
using System.Text;
using SAPIBase;
using Steam4NET;

namespace CloudEditor
{
    static class CloudContext
    {
        public static ISteamRemoteStorage001 RemoteStorageOld { get; private set; }
        public static ISteamRemoteStorage002 RemoteStorage { get; private set; }

        public static void Initialize()
        {
            SteamContext.Initialize( false );


            DebugLog.AppendText( "Getting ISteam interface: ISteamRemoteStorage002..." );

            RemoteStorage = Steamworks.CastInterface<ISteamRemoteStorage002>(
                SteamContext.SteamClient.GetISteamRemoteStorage(
                    SteamContext.HSteamUser,
                    SteamContext.HSteamPipe,
                    "STEAMREMOTESTORAGE_INTERFACE_VERSION002"
                )
            );

            DebugLog.AppendText( string.Format( "ISteamRemoteStorage002 = 0x{0:8X}", RemoteStorage.Interface ) );


            DebugLog.AppendText( "Getting ISteam interface: ISteamRemoteStorage001..." );

            RemoteStorageOld = Steamworks.CastInterface<ISteamRemoteStorage001>(
                SteamContext.SteamClient.GetISteamRemoteStorage(
                    SteamContext.HSteamUser,
                    SteamContext.HSteamPipe,
                    "STEAMREMOTESTORAGE_INTERFACE_VERSION001"
                )
            );

            DebugLog.AppendText( string.Format( "ISteamRemoteStorage001 = 0x{0:8X}{1}", RemoteStorageOld.Interface, Environment.NewLine ) );

        }

        public static void Shutdown()
        {
            SteamContext.Shutdown();
        }
    }
}
