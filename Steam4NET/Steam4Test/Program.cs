using System;
using Steam4NET;

namespace Steam4Test
{
    class Program
    {
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


            CSteamID steamid = 76561197983869206; 

           Console.WriteLine((string)steamid);

           Console.WriteLine(steamuser.GetSteamID());

            Console.ReadKey();

            steamclient.ReleaseUser(pipe, user);

            Console.WriteLine(steamclient.ReleaseSteamPipe(pipe));
        }
    }
}
