using System;
using System.Collections.Generic;
using System.Windows.Forms;

using SAPIBase;
using System.Diagnostics;
using System.Drawing;

[assembly:AddIn( DisplayName = "Cloud Editor" )]

namespace CloudEditor
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main( string[] args )
        {
            Util.MsgTitle = "Cloud Editor";

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault( false );

            if ( args.Length == 0 )
            {
                if ( !Util.StartProcess( "SAPIBase.exe", "" ) )
                    Util.MsgBox( null, "Unable to launch \"SAPIBase.exe\". Executable may be missing or renamed. Please reinstall." );

                return;
            }

            int appId = GetAppID( args );
            if ( appId == -1 )
            {
                Util.MsgBox( null, "CloudEdit launched with invalid appid." );
                return;
            }

            try
            {
                Cloud.Initialize( appId );
            }
            catch ( Exception ex )
            {
                Util.MsgBox( null, "Unable to initialize Cloud context: " + ex.Message );

                Cloud.Shutdown();
                return;
            }

            Application.Run( new MainForm( appId ) );

            Cloud.Shutdown();
        }

        static int GetAppID( string[] args )
        {
            int appId = -1;

            for ( int x = 0 ; x < args.Length ; x++ )
            {
                string arg = args[ x ];

                if ( arg.IndexOf( "-appid", StringComparison.OrdinalIgnoreCase ) == -1 )
                    continue;

                string[] argSplit = arg.Split( "=".ToCharArray(), StringSplitOptions.RemoveEmptyEntries );

                if ( argSplit.Length != 2 )
                    continue;

                if ( !int.TryParse( argSplit[ 1 ], out appId ) )
                    continue;
            }
            return appId;
        }
    }
}