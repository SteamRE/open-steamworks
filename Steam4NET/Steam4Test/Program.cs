using System;
using System.Threading;

using Steam4NET;

namespace Steam4Test
{
    class Program
    {
        private static ISteamGameServer009 gameserver;

        static void ServerSignOn(LogonSuccess_t logon)
        {
            gameserver.SetGameData("a");
            Console.WriteLine("Server signed on. ");
            ulong gssteam = gameserver.GetSteamID();
            Console.WriteLine("game server id: " + gssteam);
        }

        static void Main(string[] args)
        {
            if (!Steamworks.Load())
                return;

            ISteamClient008 steamclient = Steamworks.CreateInterface<ISteamClient008>("SteamClient008");
            Console.WriteLine("client: " + steamclient);

            int pipe = steamclient.CreateSteamPipe();
            int user = steamclient.CreateLocalUser(ref pipe, EAccountType.k_EAccountTypeGameServer);

            Console.WriteLine(user);
            Console.WriteLine(pipe);

            ISteamUtils004 utils = Steamworks.CastInterface<ISteamUtils004>(steamclient.GetISteamUtils(pipe, "SteamUtils004"));
            ISteamFriends005 friends = Steamworks.CastInterface<ISteamFriends005>(steamclient.GetISteamFriends(user, pipe, "SteamFriends005"));
            gameserver = Steamworks.CastInterface<ISteamGameServer009>(steamclient.GetISteamGameServer(user, pipe, "SteamGameServer009"));

            gameserver.LogOn();

            Callback<LogonSuccess_t> logon = new Callback<LogonSuccess_t>(LogonSuccess_t.k_iCallback);
            logon.OnRun += ServerSignOn;

            CallbackDispatcher.SpawnDispatchThread(pipe);
            Thread.Sleep(5000);
            CallbackDispatcher.StopDispatchThread(pipe);

            steamclient.ReleaseUser(pipe, user);
            steamclient.ReleaseSteamPipe(pipe);
        }
    }
}
