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
                FriendGameInfo_t gameInfo = new FriendGameInfo_t();
                SteamContext.SteamFriends.GetFriendGamePlayed( this.SteamID, ref gameInfo );

                StringBuilder builder = new StringBuilder( 255 );
                SteamContext.SteamApps.GetAppData( new CGameID( gameInfo.m_gameID ).AppID, "name", builder, builder.Capacity );

                if ( builder.Length > 0 )
                {
                    return builder.ToString();
                }
                else
                {
                    return "";
                }
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
                bool bInGame = SteamContext.SteamFriends.GetFriendGamePlayed( this.SteamID, ref gameInfo );

                return bInGame && gameInfo.m_gameID != 0;
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
                return SteamContext.SteamFriends.GetFriendPersonaState( this.SteamID ) != EPersonaState.k_EPersonaStateOffline;
            }
            catch { return false; }
        }

        public string GetName()
        {
            try
            {
                return SteamContext.SteamFriends.GetFriendPersonaName( this.SteamID );
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

                EPersonaState state = SteamContext.SteamFriends.GetFriendPersonaState( this.SteamID );

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
                return SteamContext.SteamFriends.GetFriendPersonaState( this.SteamID );
            }
            catch
            {
                return EPersonaState.k_EPersonaStateOffline;
            }
        }
    }
}
