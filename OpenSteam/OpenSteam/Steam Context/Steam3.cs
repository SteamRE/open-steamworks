using System;
using System.Collections.Generic;
using System.Text;
using Steam4NET;

namespace OpenSteam
{
    static class Steam3
    {
        public static IClientEngine ClientEngine { get; private set; }
        public static ISteamClient009 SteamClient { get; private set; }

        public static int HSteamPipe { get; private set; }
        public static int HSteamUser { get; private set; }

        public static IClientUser ClientUser { get; private set; }

        public static ISteam2Bridge002 Steam2Bridge { get; private set; }

        public static void Initialize()
        {
            ClientEngine = Steamworks.CreateInterface<IClientEngine>( "CLIENTENGINE_INTERFACE_VERSION001" );
            SteamClient = Steamworks.CreateInterface<ISteamClient009>( "SteamClient009" );

            if ( ClientEngine == null || SteamClient == null )
                throw new Exception( "Unable to get steamclient interfaces." );

            int hSteamPipe = 0;
            HSteamUser = ClientEngine.CreateGlobalUser( ref hSteamPipe );
            HSteamPipe = hSteamPipe;

            if ( HSteamPipe == 0 || HSteamUser == 0 )
                throw new Exception( "Unable to create global user." );

            ClientUser = Steamworks.CastInterface<IClientUser>( ClientEngine.GetIClientUser( HSteamUser, HSteamPipe, "CLIENTUSER_INTERFACE_VERSION001" ) );
            Steam2Bridge = Steamworks.CastInterface<ISteam2Bridge002>( SteamClient.GetISteamGenericInterface( HSteamUser, HSteamPipe, "STEAM2BRIDGE_INTERFACE_VERSION002" ) );

            if ( ClientUser == null || Steam2Bridge == null )
                throw new Exception( "Unable to get interfaces." );
        }

        public static void ReadyLogin( string userName, string passWord )
        {
            ClientUser.SetLoginInformation( userName, passWord, false );
        }

        public static EUniverse GetUniverse()
        {
            return Steam2Bridge.GetConnectedUniverse();
        }

        public static void LogOn( CSteamID steamId )
        {
            ClientUser.LogOn( steamId );
        }
        public static ELogonState GetLogonState()
        {
            return ClientUser.GetLogonState();
        }

        public static bool SetEmail( string email )
        {
            return ClientUser.SetEmail( email );
        }
    }
}
