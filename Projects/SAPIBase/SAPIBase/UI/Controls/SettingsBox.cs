using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;
using System.Reflection;

namespace SAPIBase
{
    class SettingBox : CheckBox
    {
        public PropertyInfo Setting { get; set; }

        public SettingBox()
        {
            this.Margin = new Padding( 3, 0, 3, 0 );

            this.AutoSize = true;
        }
    }
}
