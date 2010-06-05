using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;
using Steam4NET;
using System.Drawing;

namespace OpenSteam
{
    class FriendListViewItem : ListViewItem
    {
        public CSteamID FriendID { get; private set; }

        public FriendListViewItem( CSteamID friendId )
        {
            FriendID = friendId;

            this.Text = Steam3.SteamFriends.GetFriendPersonaName( FriendID );

            this.SubItems.Add( FriendID.Render() );
        }

        public void PersonaStateChange( PersonaStateChange_t callBack )
        {
            if ( (callBack.m_nChangeFlags & EPersonaChange.k_EPersonaChangeStatus) == EPersonaChange.k_EPersonaChangeStatus )
            {
                EPersonaState friendState = Steam3.SteamFriends.GetFriendPersonaState( FriendID );
                switch ( friendState )
                {
                    case EPersonaState.k_EPersonaStateOffline:
                        this.ForeColor = Color.DarkRed;
                        break;

                    case EPersonaState.k_EPersonaStateOnline:
                        this.ForeColor = Color.DarkGreen;
                        break;

                    default:
                        this.ForeColor = Color.Black;
                        break;
                }
            }
        }
    }
}
