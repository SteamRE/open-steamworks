using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using Steam4NET;

namespace SteamSuite
{
    public class Friend
    {
        public CSteamID SteamID { get; set; }

        public string PersonaName { get; set; }

        public override string ToString()
        {
            return PersonaName;
        }
    }
}
