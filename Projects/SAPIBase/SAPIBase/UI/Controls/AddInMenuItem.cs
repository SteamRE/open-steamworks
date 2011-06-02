using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace SAPIBase
{
    class AddInMenuItem : ToolStripMenuItem
    {
        AddInManager addInManager;
        AddIn addIn;

        uint appId;

        public AddInMenuItem( AddInManager manager, AddIn addIn, uint appId )
        {
            addInManager = manager;
            this.addIn = addIn;

            this.appId = appId;

            this.Text = addIn.DisplayName;
        }

        protected override void OnClick( EventArgs e )
        {
            addInManager.LaunchAddIn( addIn, appId );

            base.OnClick( e );
        }
    }
}
