using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace SAPIBase
{
    public partial class DebugForm : Form
    {
        public DebugForm()
        {
            InitializeComponent();

            this.Icon = Icon.FromHandle( Properties.Resources.world.GetHicon() );
        }

        protected override void OnFormClosing( FormClosingEventArgs e )
        {
            e.Cancel = true;
            this.Hide();
        }

        public void AppendText( string text )
        {
            try
            {
                this.Invoke( new MethodInvoker( () => { AppendTextInternal( text ); } ) );
            }
            catch ( InvalidOperationException )
            {
            }
        }

        void AppendTextInternal( string text )
        {
            if ( !this.Visible )
                this.Show();

            debugLog.AppendText( text );
            debugLog.ScrollToCaret();
        }
    }
}
