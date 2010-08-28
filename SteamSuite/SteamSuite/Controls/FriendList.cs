using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;
using System.Drawing;
using Steam4NET;

namespace SteamSuite
{
    public class FriendList : ListBox
    {
        public SteamContext SteamContext { get; set; }

        protected override void OnDrawItem( DrawItemEventArgs e )
        {
            if ( Items.Count == 0 )
            {
                base.OnDrawItem( e );
                return;
            }

            if ( Items[ e.Index ] is Friend )
            {
                Friend friendObj = ( Friend )Items[ e.Index ];

                this.DrawMode = DrawMode.OwnerDrawFixed;

                e.DrawBackground();

                e.DrawFocusRectangle();

                EPersonaState state = SteamContext.SteamFriends.GetFriendPersonaState( friendObj.SteamID );

                if ( state == EPersonaState.k_EPersonaStateOffline )
                    e.Graphics.DrawString( friendObj.PersonaName, e.Font, new SolidBrush( Color.Red ), e.Bounds );
                else
                    e.Graphics.DrawString( friendObj.PersonaName, e.Font, new SolidBrush( Color.Green ), e.Bounds );
            }
        }
    }
}
