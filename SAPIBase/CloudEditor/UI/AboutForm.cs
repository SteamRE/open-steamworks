using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;

namespace CloudEditor
{
    public partial class AboutForm : Form
    {
        public AboutForm()
        {
            InitializeComponent();

            this.Icon = Icon.FromHandle( Properties.Resources.weather_clouds.GetHicon() );
        }

        private void voidedLink_LinkClicked( object sender, LinkLabelLinkClickedEventArgs e )
        {
            Process.Start( "http://deadcode.info" );
        }

        private void oswLink_LinkClicked( object sender, LinkLabelLinkClickedEventArgs e )
        {
            Process.Start( "http://osw.limetech.org" );
        }

        private void silkLink_LinkClicked( object sender, LinkLabelLinkClickedEventArgs e )
        {
            Process.Start( "http://www.famfamfam.com/lab/icons/silk/" );
        }
    }
}
