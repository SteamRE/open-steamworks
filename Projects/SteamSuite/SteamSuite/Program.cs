using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace SteamSuite
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            SteamContext context = new SteamContext();

            if ( !context.Initialize() )
            {
                return;
            }

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault( false );


            Application.Run( new MainForm( context ) );
        }
    }
}
