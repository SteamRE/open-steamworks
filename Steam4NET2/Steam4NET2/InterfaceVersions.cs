using System;
using System.Collections.Generic;

namespace Steam4NET
{
    class InterfaceVersions
    {
        private static Dictionary<Type, string> versionMap = new Dictionary<Type, string>()
        {
            { typeof(ISteamClient006), "SteamClient006" },

            { typeof(ISteam003), "Steam003" },

            { typeof(ISteamUser004), "SteamUser004" },

            { typeof(ISteamFriends002), "SteamFriends002" },
            { typeof(ISteamFriends003), "SteamFriends003" },

            { typeof(ISteamGameServer003), "SteamGameServer003" },
            { typeof(ISteamGameServer009), "SteamGameServer009" },
            { typeof(ISteamGameServer010), "SteamGameServer010" },
        };

        public static string GetIFace( Type iface )
        {
            string vInterface;

            if (!versionMap.TryGetValue(iface, out vInterface))
            {
                throw new Exception("Missing version interface for " + iface.ToString());
            }

            return vInterface;
        }
    }
}
