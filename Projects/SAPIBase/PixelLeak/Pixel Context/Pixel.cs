using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using SAPIBase;
using Steam4NET;

namespace PixelLeak
{
    static class Pixel
    {

        public static ISteamScreenshots001 Screenshots { get; private set; }


        public static void Initialize( int appId )
        {
            Environment.SetEnvironmentVariable( "SteamAppId", appId.ToString() );

            SteamContext.Initialize( false );

            DebugLog.AppendText( "Getting ISteam interface: ISteamScreenshots001..." );
            Screenshots = SteamContext.SteamClient.GetISteamGenericInterface<ISteamScreenshots001>(
                SteamContext.HSteamUser,
                SteamContext.HSteamPipe
            );
            DebugLog.AppendText( "ISteamScreenshots001 = 0x{0:8x}", Screenshots.Interface );

        }

        public static void Shutdown()
        {
            SteamContext.Shutdown();
        }
    }
}
