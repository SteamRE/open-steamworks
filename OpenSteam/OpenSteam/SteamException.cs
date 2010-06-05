using System;
using System.Collections.Generic;
using System.Text;
using Steam4NET;

namespace OpenSteam
{
    class SteamException : Exception
    {
        public TSteamError ErrorInfo { get; set; }

        public SteamException( TSteamError error )
        {
            ErrorInfo = error;
        }
    }
}
