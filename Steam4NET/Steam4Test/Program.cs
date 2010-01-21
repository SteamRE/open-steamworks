using System;
using System.Threading;

using Steam4NET;

namespace Steam4Test
{
    class Program
    {
        static void ChatEnd(FriendEndChatSession_t chatend)
        {
            Console.WriteLine("Chat end with " + (CSteamID)chatend.m_SteamID);
        }

        static void Main(string[] args)
        {
            if (!Steamworks.Load())
                return;

            ISteamClient008 steamclient = Steamworks.CreateInterface<ISteamClient008>("SteamClient008");
            int pipe = steamclient.CreateSteamPipe();
            int user = steamclient.ConnectToGlobalUser(pipe);

            Console.WriteLine(user);
            Console.WriteLine(pipe);

            ISteamUtils004 utils = Steamworks.CastInterface<ISteamUtils004>(steamclient.GetISteamUtils(pipe, "SteamUtils004"));
            ISteamFriends001 friends = Steamworks.CastInterface<ISteamFriends001>(steamclient.GetISteamFriends(user, pipe, "SteamFriends001"));
            ISteamUser008 steamuser = Steamworks.CastInterface<ISteamUser008>(steamclient.GetISteamUser(user, pipe, "SteamUser008"));

            Console.WriteLine(utils.GetAppID());
            Console.WriteLine(utils.GetConnectedUniverse());
            Console.WriteLine(utils.GetIPCountry());

            Console.WriteLine(friends.GetPersonaName());

            int count = friends.GetFriendCount();
            Console.WriteLine("Friend count: " + count);

            for(int i = 0; i < count; i++)
            {
                CSteamID friendid = friends.GetFriendByIndex(i);
                Console.WriteLine((string)friendid);
            }

            CSteamID steamid = 76561197983869206; 

           Console.WriteLine((string)steamid);

            CSteamID myid = steamuser.GetSteamID();

            Callback<FriendEndChatSession_t> chatend = new Callback<FriendEndChatSession_t>(ChatEnd, FriendEndChatSession_t.k_iCallback);

            while(true)
            {
                CallbackDispatcher.RunCallbacks(pipe);
                Thread.Sleep(500);
            }

            steamclient.ReleaseUser(pipe, user);

            Console.WriteLine(steamclient.ReleaseSteamPipe(pipe));
        }
    }
}
