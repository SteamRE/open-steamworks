using System;
using System.Collections.Generic;
using System.Text;

namespace SteamSuite
{
    public class Settings : Serializable<Settings>
    {
        public List<string> NameChanger;

        public bool NoEscape;
        public string NoEscapeString;

        public List<BeeKeeper> BeeKeeper;

        public Settings()
        {
            NameChanger = new List<string>();

            NoEscapeString = "";

            BeeKeeper = new List<BeeKeeper>();
        }

        public bool ContainsSteamID( ulong steamID )
        {
            foreach ( BeeKeeper bk in BeeKeeper )
            {
                if ( bk.SteamID == steamID )
                    return true;
            }

            return false;
        }

        public int IndexOfSteamID( ulong steamId )
        {
            for ( int x = 0 ; x < BeeKeeper.Count ; x++ )
            {
                if ( BeeKeeper[ x ].SteamID == steamId )
                    return x;
            }
            return -1;
        }

        public BeeKeeper this[ ulong steamid ]
        {
            get
            {
                foreach ( BeeKeeper bk in BeeKeeper )
                {
                    if ( bk.SteamID == steamid )
                        return bk;
                }
                return null;
            }
        }
    }

    public class BeeKeeper
    {
        public ulong SteamID;

        public bool Enabled;
        public List<string> Entries;

        public BeeKeeper()
        {
            Entries = new List<string>();
        }

    }
}
