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

            Console.WriteLine(utils.GetAppID());

            Console.WriteLine(steamclient.ReleaseSteamPipe(pipe));

            Console.ReadKey();
        }
    }
}
