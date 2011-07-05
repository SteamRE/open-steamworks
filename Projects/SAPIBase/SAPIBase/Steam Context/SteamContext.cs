using System;
using System.Collections.Generic;
using System.Text;
using Steam4NET;
using System.Diagnostics;

namespace SAPIBase
{
    public static class SteamContext
    {
        public static ISteam006 Steam { get; private set; }

        public static ISteamClient009 SteamClient { get; private set; }
        public static IClientEngine ClientEngine { get; private set; }

        public static int HSteamPipe { get; private set; }
        public static int HSteamUser { get; private set; }


        public static IClientUser ClientUser { get; private set; }
        public static IClientApps ClientApps { get; private set; }

        public static void Initialize()
        {
            Initialize( false );
        }
        public static void Initialize( bool steam2 )
        {
            if ( steam2 )
                InitSteam2();

            InitSteam3();

            if ( steam2 )
                PostInitSteam2();

            DebugLog.AppendText( "Spawning callback dispatch thread..." );

            CallbackDispatcher.SpawnDispatchThread( HSteamPipe );

            DebugLog.AppendText( "Thread spawned.\n" );
        }


        static void InitSteam2()
        {
            DebugLog.AppendText( "Initializing Steam2..." );

            if ( !Steamworks.LoadSteam() )
                throw new InvalidOperationException( "Unable to load steam.dll" );

            DebugLog.AppendText( "Getting Steam2 interface: ISteam006... " );

            Steam = Steamworks.CreateSteamInterface<ISteam006>();
            DebugLog.AppendText( string.Format( "ISteam006 = 0x{0:8X}", Steam.Interface ) );


            if ( Steam == null )
                throw new InvalidOperationException( "Unable to get ISteam006." );

            TSteamError error = new TSteamError();

            DebugLog.AppendText( "ISteam006::Startup()..." );

            if ( Steam.Startup( 0, ref error ) == 0 )
                throw new InvalidOperationException( "Unable to startup steam interface: " + error.szDesc );

            DebugLog.AppendText( "Steam2 startup success." + Environment.NewLine );
        }
        static void PostInitSteam2()
        {
            DebugLog.AppendText( "Getting account name..." );
            StringBuilder accName = new StringBuilder( 255 );

            if ( !ClientUser.GetAccountName( accName ) )
                throw new InvalidOperationException( "Unable to startup steam interface." );

            DebugLog.AppendText( "Account = \"{0}\"", accName.ToString() );


            TSteamError error = new TSteamError();

            DebugLog.AppendText( "ISteam006::SetUser( \"{0}\" )...", accName.ToString() );
            int bUserSet = 0;
            uint setUserHandle = Steam.SetUser( accName.ToString(), ref bUserSet, ref error );
            DebugLog.AppendText( "SetUserHandle = {0}", setUserHandle );

            if ( setUserHandle == 0 )
                throw new InvalidOperationException( "Unable to get SetUser call handle." );

            DebugLog.AppendText( "ISteam006::BlockingCall( {0} )...", setUserHandle );
            if ( Steam.BlockingCall( setUserHandle, 100, ref error ) == 0 )
                throw new InvalidOperationException( "Unable to process SetUser call: " + error.szDesc );

            DebugLog.AppendText( "User set!" + Environment.NewLine );
        }

        static void InitSteam3()
        {
            DebugLog.AppendText( "Initializing Steam3..." );

            if ( !Steamworks.LoadSteamClient() )
                throw new InvalidOperationException( "Unable to load steamclient.dll" );

            DebugLog.AppendText( "Getting Steam3 interface: ISteamClient009..." );
            SteamClient = Steamworks.CreateInterface<ISteamClient009>();
            DebugLog.AppendText( string.Format( "ISteamClient009 = 0x{0:8X}", SteamClient.Interface ) );

            DebugLog.AppendText( "Getting Steam3 interface: IClientEngine..." );
            ClientEngine = Steamworks.CreateInterface<IClientEngine>();
            DebugLog.AppendText( string.Format( "IClientEngine = 0x{0:8X}{1}", ClientEngine.Interface, Environment.NewLine ) );

            if ( SteamClient == null || ClientEngine == null )
                throw new InvalidOperationException( "Unable to get required steamclient interfaces." );


            DebugLog.AppendText( "Creating steam pipe..." );
            HSteamPipe = SteamClient.CreateSteamPipe();
            DebugLog.AppendText( string.Format( "HSteamPipe = {0}", HSteamPipe ) );

            DebugLog.AppendText( "Connecting to global user..." );
            HSteamUser = SteamClient.ConnectToGlobalUser( HSteamPipe );
            DebugLog.AppendText( string.Format( "HSteamUser = {0}{1}", HSteamUser, Environment.NewLine ) );

            if ( HSteamUser == 0 || HSteamPipe == 0 )
                throw new InvalidOperationException( "Unable to connect to global user." );

            DebugLog.AppendText( "Getting IClient interface: IClientApps..." );
            ClientApps = ClientEngine.GetIClientApps<IClientApps>( HSteamUser, HSteamPipe );
            DebugLog.AppendText( string.Format( "IClientApps = 0x{0:8X}", ClientApps.Interface ) );

            DebugLog.AppendText( "Getting IClient interface: IClientUser..." );
            ClientUser = ClientEngine.GetIClientUser<IClientUser>( HSteamUser, HSteamPipe );
            DebugLog.AppendText( string.Format( "IClientUser = 0x{0:8X}", ClientUser.Interface ) );

            if ( ClientApps == null || ClientUser == null )
                throw new InvalidOperationException( "Unable to get required interfaces." );

            DebugLog.AppendText( "Steam3 startup success." + Environment.NewLine );
        }

        public static void Shutdown()
        {
            DebugLog.AppendText( "Stopping callback dispatch thread..." );
            CallbackDispatcher.StopDispatchThread( HSteamPipe );
            DebugLog.AppendText( "Thread stopped." + Environment.NewLine );

            ShutdownSteam3();
            ShutdownSteam2();
        }

        private static void ShutdownSteam3()
        {
            DebugLog.AppendText( "Shutting down Steam3..." );

            if ( SteamClient != null )
            {
                if ( HSteamUser != 0 && HSteamPipe != 0 )
                {
                    DebugLog.AppendText( string.Format( "Releasing user: {0}", HSteamUser ) );
                    SteamClient.ReleaseUser( HSteamPipe, HSteamUser );
                }

                if ( HSteamPipe != 0 )
                {
                    DebugLog.AppendText( string.Format( "Releasing steam pipe: {0}", HSteamPipe ) );
                    SteamClient.BReleaseSteamPipe( HSteamPipe );
                }

                SteamClient = null;
            }

            DebugLog.AppendText( "Steam3 shutdown complete." + Environment.NewLine );
        }

        private static void ShutdownSteam2()
        {
            DebugLog.AppendText( "Shutting down Steam2..." );

            TSteamError error = new TSteamError();

            if ( Steam != null )
            {
                DebugLog.AppendText( "ISteam006::Cleanup()..." );

                Steam.Cleanup( ref error );

                Steam = null;
            }

            DebugLog.AppendText( "Steam2 shutdown complete.\n" );
        }
    }
}
