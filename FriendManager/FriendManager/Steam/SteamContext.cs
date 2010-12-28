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

        public static int SteamPipe { get; private set; }
        public static int SteamUser { get; private set; }

        // CLIENTFRIENDS_INTERFACE_VERSION001
        public static IClientFriends ClientFriends { get; private set; }

        // CLIENTUTILS_INTERFACE_VERSION001
        public static IClientUtils ClientUtils { get; private set; }

        // CLIENTUSER_INTERFACE_VERSION001
        public static IClientUser ClientUser { get; private set; }

        // CLIENTAPPS_INTERFACE_VERSION001
        public static IClientApps ClientApps { get; private set; }


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

            if ( ClientEngine == null )
                throw new SteamException( "Unable to get IClientEngine interface." );

            SteamPipe = ClientEngine.CreateSteamPipe();

            if ( SteamPipe == 0 )
                throw new SteamException( "Unable to aquire steam pipe." );

            SteamUser = ClientEngine.ConnectToGlobalUser( SteamPipe );

            if ( SteamUser == 0 )
                throw new SteamException( "Unable to connect to global user." );


            ClientFriends = GetInterface<IClientFriends>(
                () => { return ClientEngine.GetIClientFriends( SteamUser, SteamPipe, "CLIENTFRIENDS_INTERFACE_VERSION001" ); },
                "Unable to get IClientFriends interface."
            );

            ClientUtils = GetInterface<IClientUtils>(
                () => { return ClientEngine.GetIClientUtils( SteamPipe, "CLIENTUTILS_INTERFACE_VERSION001" ); },
                "Unable to get IClientUtils interface."
            );

            ClientUser = GetInterface<IClientUser>(
                () => { return ClientEngine.GetIClientUser( SteamUser, SteamPipe, "CLIENTUSER_INTERFACE_VERSION001" ); },
                "Unable to get IClientUser interface."
            );

            ClientApps = GetInterface<IClientApps>(
                () => { return ClientEngine.GetIClientApps( SteamUser, SteamPipe, "CLIENTAPPS_INTERFACE_VERSION001" ); },
                "Unable to get IClientApps interface."
            );

            OnStateChange = new Callback<PersonaStateChange_t>( PersonaStateChange_t.k_iCallback );
        }

        public static void StartCallbacks()
        {
            CallbackDispatcher.SpawnDispatchThread( SteamPipe );
        }

        public static void StopCallbacks()
        {
            CallbackDispatcher.StopDispatchThread( SteamPipe );
        }

        public static void Shutdown()
        {
            if ( ClientEngine != null )
            {
                if ( SteamUser != 0 )
                    ClientEngine.ReleaseUser( SteamPipe, SteamUser );

                if ( SteamPipe != 0 )
                    ClientEngine.ReleaseSteamPipe( SteamPipe );
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
