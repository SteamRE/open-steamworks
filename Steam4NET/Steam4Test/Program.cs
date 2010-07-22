using System;
using System.Threading;

using Steam4NET;
using System.Diagnostics;

namespace Steam4Test
{
    class Program
    {

        static void Main(string[] args)
        {
            CSteamID qq = 133724098;


            if (!Steamworks.Load())
                return;

            ISteamClient008 steamclient = Steamworks.CreateInterface<ISteamClient008>("SteamClient008");
            Console.WriteLine("client: " + steamclient);

            int pipe = steamclient.CreateSteamPipe();
            int user = steamclient.ConnectToGlobalUser(pipe);

            Console.WriteLine(user);
            Console.WriteLine(pipe);

            ISteamUtils004 utils = Steamworks.CastInterface<ISteamUtils004>(steamclient.GetISteamUtils(pipe, "SteamUtils004"));
            ISteamFriends005 friends = Steamworks.CastInterface<ISteamFriends005>(steamclient.GetISteamFriends(user, pipe, "SteamFriends005"));

             int num = friends.GetFriendCount(EFriendFlags.k_EFriendFlagAll);
            for (int i = 0; i < num; i++)
            {
                CSteamID id = friends.GetFriendByIndex(i, (int)EFriendFlags.k_EFriendFlagAll);
                string name = friends.GetFriendPersonaName(id);

                Debug.WriteLine(name);
            }

            CallbackDispatcher.SpawnDispatchThread(pipe);
            Thread.Sleep(5000);
            CallbackDispatcher.StopDispatchThread(pipe);

            steamclient.ReleaseUser(pipe, user);
            steamclient.ReleaseSteamPipe(pipe);
        }
    }
}
