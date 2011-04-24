using System;
using System.Threading;

using Steam4NET;
using System.Diagnostics;
using System.Text;
using System.IO;
using System.Runtime.InteropServices;

namespace Steam4Test
{
    class Program
    {
        public static void Main()
        {
            File.WriteAllText("steam_appid.txt", "630");

            Steamworks.Load(true);

            ISteamClient006 steamclient = Steamworks.CreateInterface<ISteamClient006>();

            int pipe = steamclient.CreateSteamPipe();
            int user = steamclient.ConnectToGlobalUser(pipe); // steamclient.CreateLocalUser(ref pipe); // steamclient.ConnectToGlobalUser(pipe);

            ISteamUser004 steamuser = steamclient.GetISteamUser<ISteamUser004>(user, pipe);


            ISteam003 steam003 = Steamworks.CreateSteamInterface<ISteam003>();

            StringBuilder version = new StringBuilder();
            version.EnsureCapacity(256);

            steam003.GetVersion(version);

            TSteamError error = new TSteamError();
            uint sz = 0;
            StringBuilder email = new StringBuilder();
            email.EnsureCapacity(256);

            steam003.GetCurrentEmailAddress(email, ref sz, ref error);

            CSteamID steamid = steamuser.GetSteamID();

            ISteamFriends003 friends = steamclient.GetISteamFriends<ISteamFriends003>(user, pipe);
            ISteamFriends002 friends2 = steamclient.GetISteamFriends<ISteamFriends002>(user, pipe);

            int num = friends.GetFriendCount(EFriendFlags.k_EFriendFlagAll);
            for (int i = 0; i < num; i++)
            {
                CSteamID id = friends.GetFriendByIndex(i, EFriendFlags.k_EFriendFlagAll);
                string name = friends.GetFriendPersonaName(id);

                if (name == "Stan")
                {
                    byte[] buff = Encoding.ASCII.GetBytes("Oidy.");
                    friends2.SendMsgToFriend(id, EChatEntryType.k_EChatEntryTypeChatMsg, buff);
                }

                Debug.WriteLine(name);
            }
             
        }
             
    }
}
