using System;
using System.Collections.Generic;
using System.Text;
using Steam4NET;

namespace FriendManager
{
    static class SteamContext
    {

        // CLIENTENGINE_INTERFACE_VERSION001
        public static IClientEngine ClientEngine { get; private set; }
        // SteamClient009
        public static ISteamClient009 SteamClient { get; private set; }

        public static int Pipe { get; private set; }
        public static int User { get; private set; }

        // CLIENTFRIENDS_INTERFACE_VERSION001
        public static IClientFriends ClientFriends { get; private set; }

        // SteamUser014
        public static ISteamUser014 SteamUser { get; private set; }

        // SteamUtils005
        public static ISteamUtils005 SteamUtils { get; private set; }



        public static Callback<PersonaStateChange_t> OnStateChange { get; private set; }


        public static void Initialize()
        {
            if ( !Steamworks.Load() )
                throw new SteamException( "Unable to load steamclient library." );

            try
            {
                ClientEngine = Steamworks.CreateInterface<IClientEngine>( "CLIENTENGINE_INTERFACE_VERSION001" );
            }
            catch ( Exception ex )
            {
                throw new SteamException( "Unable to get IClientEngine interface.", ex );
            }

            try
            {
                SteamClient = Steamworks.CreateInterface<ISteamClient009>( "SteamClient009" );
            }
            catch ( Exception ex)
            {
                throw new SteamException( "Unable to get ISteamClient interface.", ex );
            }

            if ( ClientEngine == null )
                throw new SteamException( "Unable to get IClientEngine interface." );

            Pipe = ClientEngine.CreateSteamPipe();

            if ( Pipe == 0 )
                throw new SteamException( "Unable to aquire steam pipe." );

            User = ClientEngine.ConnectToGlobalUser( Pipe );

            if ( User == 0 )
                throw new SteamException( "Unable to connect to global user." );


            ClientFriends = GetInterface<IClientFriends>(
                () => { return ClientEngine.GetIClientFriends( User, Pipe, "CLIENTFRIENDS_INTERFACE_VERSION001" ); },
                "Unable to get IClientFriends interface."
            );

            SteamUser = GetInterface<ISteamUser014>(
                () => { return SteamClient.GetISteamUser( User, Pipe, "SteamUser014" ); },
                "Unable to get ISteamUser interface."
            );

            SteamUtils = GetInterface<ISteamUtils005>(
                () => { return SteamClient.GetISteamUtils( Pipe, "SteamUtils005" ); },
                "Unable to get ISteamUtils interface."
            );

            OnStateChange = new Callback<PersonaStateChange_t>( PersonaStateChange_t.k_iCallback );
        }

        public static void StartCallbacks()
        {
            CallbackDispatcher.SpawnDispatchThread( Pipe );
        }

        public static void StopCallbacks()
        {
            CallbackDispatcher.StopDispatchThread( Pipe );
        }

        public static void Shutdown()
        {
            if ( ClientEngine != null )
            {
                if ( User != 0 )
                    ClientEngine.ReleaseUser( Pipe, User );

                if ( Pipe != 0 )
                    ClientEngine.ReleaseSteamPipe( Pipe );
            }
        }


        delegate IntPtr GetterFunc();
        static IFace GetInterface<IFace>( GetterFunc func, string errMsg )
             where IFace : INativeWrapper, new()
        {
            IFace iface = default( IFace );

            try
            {
                iface = Steamworks.CastInterface<IFace>( func() );
            }
            catch ( Exception ex )
            {
                throw new SteamException( errMsg, ex );
            }

            if ( iface == null )
                throw new SteamException( errMsg );

            return iface;
        }
    }
}
