using System;
using System.Collections.Generic;
using System.Text;
using Steam4NET;

namespace SteamSuite
{
    public class Group
    {
        public CSteamID SteamID { get; set; }

        public string GroupName { get; set; }

        public override string ToString()
        {
            return GroupName;
        }
    }
}
