using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using Steam4NET;

namespace OpenSteam
{
    public partial class FriendsForm : Form
    {
        Callback<SteamServersConnected_t> serversConnected;
        Callback<SteamServersDisconnected_t> serversDisconnected;
        Callback<SteamServerConnectFailure_t> connectionFailure;

        public FriendsForm()
        {
            InitializeComponent();

            serversConnected = new Callback<SteamServersConnected_t>( SteamServersConnected, SteamServersConnected_t.k_iCallback );
            serversDisconnected = new Callback<SteamServersDisconnected_t>( SteamServersDisconnected, SteamServersDisconnected_t.k_iCallback );
            connectionFailure = new Callback<SteamServerConnectFailure_t>( SteamServerConnectionFailure, SteamServerConnectFailure_t.k_iCallback );

        }

        void SteamServersConnected( SteamServersConnected_t callBack )
        {
            //MessageBox.Show( this, "Connected to Steam3!" );
        }
        void SteamServersDisconnected( SteamServersDisconnected_t callBack )
        {
            //MessageBox.Show( this, "Disconnected from Steam3!" );
        }
        void SteamServerConnectionFailure( SteamServerConnectFailure_t callBack )
        {
            //MessageBox.Show( this, "Unable to connect to Steam3!" );
        }

        public void RunCallbacks()
        {
            CallbackDispatcher.RunCallbacks( Steam3.HSteamPipe );
        }
    }
}
