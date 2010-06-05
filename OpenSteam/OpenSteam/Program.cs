using System;
using System.Collections.Generic;
using System.Windows.Forms;
using Steam4NET;
using System.Text;
using System.Runtime.InteropServices;
using System.Drawing;
using System.Security;

namespace OpenSteam
{
    [StructLayout( LayoutKind.Sequential )]
    public struct NativeMessage
    {
        public IntPtr handle;
        public uint msg;
        public IntPtr wParam;
        public IntPtr lParam;
        public uint time;
        public Point p;
    }

    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();

            if ( !Steamworks.Load() )
            {
                MessageBox.Show( "Fatal error: Unable to load steam libraries!" );
                return;
            }

            try
            {
                Steam2.Initialize();
                Steam3.Initialize();
            }
            catch ( SteamException ex )
            {
                MessageBox.Show( "Unable to initialize Steam2.\n\n" + Utils.GetDisplayError( ex.ErrorInfo ) );
                return;
            }
            catch ( Exception ex )
            {
                // steam2 initialized, but steam3 didn't
                MessageBox.Show( "Unable to initialize Steam3: " + ex.Message );

                Steam2.Shutdown();
                return;
            }

            LoginForm lf = new LoginForm();

            if ( lf.ShowDialog() != DialogResult.OK )
            {
                Steam2.Shutdown();
                return;
            }


            FriendsForm ff = new FriendsForm();

            Application.Idle += ( s, e ) => { ff.RunCallbacks(); };
            Application.Run( ff );

            Steam3.Shutdown();
            Steam2.Shutdown();
        }
    }
}