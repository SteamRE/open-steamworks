using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;
using System.Drawing;
using System.Drawing.Imaging;
using System.Runtime.InteropServices;

namespace FriendManager
{
    class Program
    {
        public static void Main()
        {
            try
            {
                SteamContext.Initialize();
            }
            catch ( Exception ex )
            {
                Util.MsgBox( "Unable to initialize Steam Context: " + ex.Message + "\n\n" + ex.ToString() );
                return;
            }

            Application.Run( new MainForm() );

            SteamContext.Shutdown();
        }
    }
}