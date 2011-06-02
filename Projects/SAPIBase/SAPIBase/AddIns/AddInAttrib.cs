using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;

namespace SAPIBase
{
    [AttributeUsage( AttributeTargets.Assembly, Inherited = false, AllowMultiple = false )]
    public sealed class AddInAttribute : Attribute
    {
        public string DisplayName { get; set; }
    }
}