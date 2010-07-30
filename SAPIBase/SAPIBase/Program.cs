using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace SAPIBase
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Util.MsgTitle = "SAPI Base";

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault( false );


            try
            {
                SteamContext.Initialize( true );
            }
            catch ( Exception ex )
            {
                Util.MsgBox( null, "Unable to initialize Steam context: " + ex.Message );

                SteamContext.Shutdown();
                return;
            }


            Application.Run( new MainForm() );


            SteamContext.Shutdown();
        }
    }
}
