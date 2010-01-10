using System;

namespace Steam4NET
{
    public class Steamworks
    {

        public static void TestMethod()
        {
            CallbackMsg_t xyz;

            xyz.m_hSteamUser = 5;
            Console.WriteLine(xyz.m_hSteamUser);
        }
    }
}
