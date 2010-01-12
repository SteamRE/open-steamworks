using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using VoiceSupport;

namespace SteamVoice
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();

            Steam.Init();
            PlayBack.Init();
        }

        private void button1_Click( object sender, EventArgs e )
        {
            Steam.StartRecording();
        }

        private void button2_Click( object sender, EventArgs e )
        {
            Steam.StopRecording();

            byte[] data = Steam.GetCompressedVoiceData();

            byte[] decomp = Steam.DecompressVoice( data );

            PlayBack.PlayData( decomp );
        }
    }
}
