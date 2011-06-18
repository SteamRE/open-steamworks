using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Steam4NET;
using HSteamPipe = System.Int32;
using HSteamUser = System.Int32;

namespace SkypeStatus
{
    class SteamException : Exception
    {
        public SteamException( string msg )
            : base( msg )
        {
        }
    }

    static class SteamContext
    {
        public static ISteamClient009 SteamClient { get; private set; }

        public static HSteamPipe Pipe { get; private set; }
        public static HSteamUser User { get; private set; }

        public static ISteamUser015 SteamUser { get; private set; }
        public static ISteamFriends009 SteamFriends { get; private set; }
        public static ISteamApps001 SteamApps { get; private set; }

        public static Callback<PersonaStateChange_t> PersonaStateChange = new Callback<PersonaStateChange_t>();
        public static Callback<AppDataChanged_t> AppDataChanged = new Callback<AppDataChanged_t>();

        public static void Init()
        {

            if ( !Steamworks.Load() )
            {
                throw new SteamException( "Unable to load steamclient library." );
            }

            if ( SteamClient == null )
            {
                SteamClient = Steamworks.CreateInterface<ISteamClient009>();

                if ( SteamClient == null )
                {
                    throw new SteamException( "Unable to get ISteamClient interface." );
                }
            }

            if ( Pipe == 0 )
            {
                Pipe = SteamClient.CreateSteamPipe();

                if ( Pipe == 0 )
                {
                    throw new SteamException( "Unable to create steam pipe." );
                }
            }

            if ( User == 0 )
            {
                User = SteamClient.ConnectToGlobalUser( Pipe );

                if ( User == 0 )
                {
                    throw new SteamException( "Unable to connect to global user." );
                }
            }

            if ( SteamUser == null )
            {
                SteamUser = SteamClient.GetISteamUser<ISteamUser015>( User, Pipe );

                if ( SteamUser == null )
                {
                    throw new SteamException( "Unable to get ISteamUser interface." );
                }
            }

            if ( SteamFriends == null )
            {
                SteamFriends = SteamClient.GetISteamFriends<ISteamFriends009>( User, Pipe );

                if ( SteamFriends == null )
                {
                    throw new SteamException( "Unable to get ISteamFriends interface." );
                }
            }

            if ( SteamApps == null )
            {
                SteamApps = SteamClient.GetISteamApps<ISteamApps001>( User, Pipe );

                if ( SteamApps == null )
                {
                    throw new SteamException( "Unable to get ISteamApps interface." );
                }
            }

            CallbackDispatcher.SpawnDispatchThread( Pipe );

        }

        public static void Shutdown()
        {

            CallbackDispatcher.StopDispatchThread( Pipe );

            if ( SteamClient != null && User != 0 )
            {
                SteamClient.ReleaseUser( Pipe, User );
            }

            if ( SteamClient != null && Pipe != 0 )
            {
                SteamClient.ReleaseSteamPipe( Pipe );
            }

        }
    }
}
