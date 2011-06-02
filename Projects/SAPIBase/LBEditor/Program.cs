using System;
using System.Collections.Generic;
using System.Text;
using SAPIBase;
using System.Windows.Forms;
using Steam4NET;

[assembly: AddIn( DisplayName = "Leaderboard Editor" )]

namespace LBEditor
{
    class Program
    {
        public static void Main( string[] args )
        {
            Util.MsgTitle = "Leaderboard Editor";

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault( false );

            if ( Util.CheckAndLaunchBase( args ) )
                return;

            int appId = Util.GetAppID( args );
            if ( appId == -1 )
            {
                Util.MsgBox( null, "Leaderboard Editor launched with invalid appid." );
                return;
            }

            LBContext.Initialize( appId );

            Application.Run( new MainForm( appId ) );

            LBContext.Shutdown();
        }
    }
}
