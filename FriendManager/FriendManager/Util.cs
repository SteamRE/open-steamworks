using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;
using System.Drawing;
using Steam4NET;

namespace FriendManager
{
    static class Util
    {
        public static DialogResult MsgBox( IWin32Window parent, string msg )
        {
            return MessageBox.Show( parent, msg, "Friend Manager" );
        }
        public static DialogResult MsgBox( string msg )
        {
            return MsgBox( null, msg );
        }

        public static Color GetStatusColor( Friend steamid )
        {
            Color inGame = Color.FromArgb( 177, 251, 80 );
            Color online = Color.FromArgb( 111, 189, 255 );
            Color offline = Color.FromArgb( 137, 137, 137 );

            if ( steamid.IsInGame() )
                return inGame;

            if ( !steamid.IsOnline() )
                return offline;

            return online;
        }

    }
}
