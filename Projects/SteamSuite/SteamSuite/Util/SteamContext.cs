using System;
using System.Collections.Generic;
using System.Text;
using Steam4NET;

namespace SteamSuite
{
    public class SteamContext
    {
        public ISteamClient008 SteamClient { get; set; }

        public int Pipe { get; set; }
        public int User { get; set; }

        public ISteamFriends002 SteamFriends { get; set; }

        public ISteamUser013 SteamUser { get; set; }

        public Callback<FriendChatMsg_t> FriendChatMsg = new Callback<FriendChatMsg_t>( FriendChatMsg_t.k_iCallback );


        public SteamContext()
        {
        }

        public bool Initialize()
        {
            if ( !Steamworks.Load() )
                return false;

            SteamClient = Steamworks.CreateInterface<ISteamClient008>( "SteamClient008" );
            if ( SteamClient == null )
                return false;


            Pipe = SteamClient.CreateSteamPipe();
            if ( Pipe == 0 )
                return false;

            User = SteamClient.ConnectToGlobalUser( Pipe );
            if ( User == 0 )
                return false;


            SteamFriends = Steamworks.CastInterface<ISteamFriends002>( SteamClient.GetISteamFriends( User, Pipe, "SteamFriends002" ) );
            if ( SteamFriends == null )
                return false;


            SteamUser = Steamworks.CastInterface<ISteamUser013>( SteamClient.GetISteamUser( User, Pipe, "SteamUser013" ) );
            if ( SteamUser == null )
                return false;

            return true;
        }

        public void StartCallbacks()
        {
            CallbackDispatcher.SpawnDispatchThread( Pipe );
        }

        public void Shutdown()
        {
            SteamClient.ReleaseUser( Pipe, User );

            SteamClient.ReleaseSteamPipe( Pipe );

            CallbackDispatcher.StopDispatchThread( Pipe );
        }
    }
}
