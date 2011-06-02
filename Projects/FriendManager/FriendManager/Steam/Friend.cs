using System;
using System.Collections.Generic;
using System.Text;
using Steam4NET;

namespace FriendManager
{
    class Friend
    {
        public ulong SteamID { get; set; }


        public Friend()
        {
        }
        public Friend( ulong steamid )
        {
            this.SteamID = steamid;
        }

        public string GetGameName()
        {
            if ( !IsInGame() )
                return "";
            try
            {
                return SteamContext.ClientFriends.GetFriendGamePlayedExtraInfo( this.SteamID );
            }
            catch
            {
                return "";
            }
        }


        public bool IsInGame()
        {
            try
            {
                FriendGameInfo_t gameInfo = new FriendGameInfo_t();
                return SteamContext.ClientFriends.GetFriendGamePlayed( this.SteamID, ref gameInfo );
            }
            catch
            {
                return false;
            }
        }

        public bool IsOnline()
        {
            try
            {
                return SteamContext.ClientFriends.GetFriendPersonaState( this.SteamID ) != EPersonaState.k_EPersonaStateOffline;
            }
            catch { return false; }
        }

        public string GetName()
        {
            try
            {
                return SteamContext.ClientFriends.GetFriendPersonaName( this.SteamID );
            }
            catch
            {
                return "[unknown]";
            }
        }

        public string GetStatus()
        {
            try
            {
                if ( this.IsInGame() )
                    return "In-Game";

                EPersonaState state = SteamContext.ClientFriends.GetFriendPersonaState( this.SteamID );

                switch ( state )
                {
                    case EPersonaState.k_EPersonaStateAway:
                        return "Away";

                    case EPersonaState.k_EPersonaStateBusy:
                        return "Busy";

                    case EPersonaState.k_EPersonaStateOnline:
                        return "Online";

                    case EPersonaState.k_EPersonaStateSnooze:
                        return "Snooze";
                }

                return "Offline";
            }
            catch
            {
                return "Offline";
            }
        }

        public EPersonaState GetState()
        {
            try
            {
                return SteamContext.ClientFriends.GetFriendPersonaState( this.SteamID );
            }
            catch
            {
                return EPersonaState.k_EPersonaStateOffline;
            }
        }
    }
}
