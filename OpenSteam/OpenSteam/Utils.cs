using System;
using System.Collections.Generic;
using System.Text;
using Steam4NET;

namespace OpenSteam
{
    static class Utils
    {
        public static string GetDisplayError( TSteamError error )
        {
            string errorString = string.Format( "Steam Error: {0}\nDetailed Error: {1}\nDetailed Code: {2}\nDescription: {3}", error.eSteamError, error.eDetailedErrorType, error.nDetailedErrorCode, error.szDesc );

            return errorString;
        }
    }
}
