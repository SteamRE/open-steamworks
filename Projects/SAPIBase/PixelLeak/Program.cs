using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using SAPIBase;
using System.Windows.Forms;


[assembly: AddIn( DisplayName = "PixelLeak" )]

namespace PixelLeak
{
    class Program
    {
        [STAThread]
        public static void Main( string[] args )
        {
            Util.MsgTitle = "PixelLeak";

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault( false );

            if ( Util.CheckAndLaunchBase( args ) )
            {
                return;
            }

            int appId = Util.GetAppID( args );

            if ( appId == -1 )
            {
                Util.MsgBox( null, "PixelLeak launched with invalid appid." );
                return;
            }

            Pixel.Initialize( appId );

            Application.Run( new MainForm( appId ) );

            Pixel.Shutdown();
        }
    }
}
