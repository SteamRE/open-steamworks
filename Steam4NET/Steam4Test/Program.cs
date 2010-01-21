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
            Console.WriteLine(pipe);
            Console.WriteLine(steamclient.ReleaseSteamPipe(pipe));

            Console.ReadKey();
        }
    }
}
