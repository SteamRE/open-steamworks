using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Reflection;

namespace SAPIBase
{

    public partial class SettingsForm : Form
    {
        public SettingsForm()
        {
            InitializeComponent();

            this.Icon = Icon.FromHandle( Properties.Resources.world.GetHicon() );

            PropertyInfo[] props = typeof( Settings ).GetProperties( BindingFlags.Public | BindingFlags.Static );

            foreach ( PropertyInfo pi in props )
            {
                SettingAttribute[] setAttribs = ( SettingAttribute[] )pi.GetCustomAttributes( typeof( SettingAttribute ), false );

                if ( setAttribs == null || setAttribs.Length == 0 )
                    continue;

                string text = setAttribs[ 0 ].Display;

                SettingBox sb = new SettingBox()
                {
                    Text = text,
                    Setting = pi,
                };

                bool bEnabled = ( bool )pi.GetValue( null, null );
                sb.Checked = bEnabled;

                settingsPanel.Controls.Add( sb );
            }
        }

        protected override void OnFormClosing( FormClosingEventArgs e )
        {
            base.OnFormClosing( e );

            if ( DialogResult == DialogResult.Cancel )
                return;

            foreach ( SettingBox sb in settingsPanel.Controls )
            {
                sb.Setting.SetValue( null, sb.Checked, null );
            }
        }
    }
}
