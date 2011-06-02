using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;
using System.Windows.Forms;
using System.IO;
using System.Threading;

namespace SAPIBase
{
    public static class DebugLog
    {
        static DebugForm debugForm;

        static string debugFile;
        static object fileLock = new object();


        static DebugLog()
        {
            if ( Environment.CommandLine.IndexOf( "-debug", StringComparison.OrdinalIgnoreCase ) == -1 )
                return;

            debugForm = new DebugForm();
            debugForm.Show();

            debugFile = Path.Combine( Application.StartupPath, "debug.log" );

            if ( File.Exists( debugFile ) )
                File.Delete( debugFile );

            AppendText( "Logging started.\n\n" );
        }


        public static void AppendText( string text, params object[] args )
        {
            AppendText( string.Format( text, args ) );
        }
        public static void AppendText( string text )
        {
            string logFmt = string.Format( "[ {0} ] {1}{2}", DateTime.Now.ToShortTimeString(), text, Environment.NewLine );

            Console.Write( logFmt );

            if ( !string.IsNullOrEmpty( debugFile ) )
            {
                Monitor.Enter( fileLock );
                File.AppendAllText( debugFile, logFmt );
                Monitor.Exit( fileLock );
            }

            if ( debugForm != null )
                debugForm.AppendText( logFmt );
        }
    }
}
