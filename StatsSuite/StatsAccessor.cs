using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using dotnetworks;

namespace StatsSuite
{
    // All this class is going to do is wrap the Steamworks stats functions
    public class StatsAccessor
    {
        // member vars
        GameID thisGameID;

        SteamUserStats002 stats002;
        SteamUserStats004 stats004;

        bool bActive;

        public StatsAccessor( SteamClient008 client, SteamPipeHandle pipe, SteamUserHandle user, uint lgameID )
        {

            stats002 = ( SteamUserStats002 )client.GetISteamUserStats( user, pipe, SteamUserStats002.InterfaceVersion );
            stats004 = ( SteamUserStats004 )client.GetISteamUserStats( user, pipe, SteamUserStats004.InterfaceVersion );


            thisGameID = new GameID( lgameID );

            if ( stats002.RequestCurrentStats( thisGameID ) && stats004.RequestCurrentStats() )
            {
                bActive = true;
            }
        }

        public bool SaveStats()
        {
            if ( !IsValid() )
                return false;

            return stats002.StoreStats( thisGameID ) && stats004.StoreStats();
        }

        public bool IsValid()
        {
            return bActive;
        }

        public int GetStat(string statName)
        {
            int val = 0;

            if (!stats002.GetStat(thisGameID, statName, ref val))
                stats004.GetStat( statName, ref val);

            return val;
        }

        public string GetStatString( string statName )
        {
            return GetStat(statName).ToString();
        }

        public bool SetStatValue( string statName, int value )
        {
            if ( !stats002.SetStat( thisGameID, statName, value ) )
                return stats004.SetStat( statName, value );
            else
                return true;
        }

        public void SetStatValue(string statName, float value)
        {
            if (!stats002.SetStat(thisGameID, statName, value))
                stats004.SetStat(statName, value);
        }

        public void ClearStats()
        {
            stats004.ResetAllStats( false );
        }
    }
}
