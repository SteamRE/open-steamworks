using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using dotnetworks;
using System.Threading;
using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;

namespace StatsSuite
{
    static class Program
    {
        // warp factor: teh
        [DllImport( "kernel32", SetLastError = true )]
        static extern IntPtr LoadLibrary( string lpFileName );

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            if ( !File.Exists( "steamclient.dll" ) || !File.Exists( "vstdlib_s.dll" ) || !File.Exists( "tier0_s.dll" ) )
            {
                MessageBox.Show( "Unable to initialize steamworks. Please ensure the following:\n\n" +
                    " * steamclient.dll, tier0_s.dll, vstdlib_s.dll, are present in the running directory\n" +
                    " * You are logged into steam and are online.\n\nAdditional Details: required dll files not found.", "TF2 Stats Suite"
                );

                return;
            }

            IntPtr fmodex = PrepLibrary( "fmodex", Properties.Resources.fmodex );

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault( false );

            Application.Run( new MainForm( fmodex != IntPtr.Zero ) );
        }

        private static IntPtr PrepLibrary(string name, byte[] library)
        {
            string dirName = Path.Combine( Path.GetTempPath(), "ss." + name + "." + Path.GetRandomFileName() );

            if ( !Directory.Exists( dirName ) )
                Directory.CreateDirectory( dirName );

            string dllPath = Path.Combine( dirName, "fmodex.dll" );

            try
            {
                File.WriteAllBytes( dllPath, library );
            }
            catch
            {
            }

            return LoadLibrary( dllPath );
        }
    }
}
