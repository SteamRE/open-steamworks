using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using FriendManager.Properties;

namespace FriendManager
{
    public partial class AliasForm : Form
    {
        public string Alias { get { return txtAlias.Text; } }

        public AliasForm()
        {
            InitializeComponent();

            this.Icon = Icon.FromHandle( Resources.AliasIcon.GetHicon() );
        }

        private void btnOk_Click( object sender, EventArgs e )
        {
            DialogResult = DialogResult.OK;
            this.Close();
        }

        private void btnCancel_Click( object sender, EventArgs e )
        {
            DialogResult = DialogResult.Cancel;
            this.Close();
        }
    }
}
