using System;
using System.Collections.Generic;
using System.Text;
using Steam4NET;
using System.Runtime.InteropServices;

namespace OpenSteam
{
    static class Steam2
    {
        [DllImport( "steam", CallingConvention = CallingConvention.Cdecl )]
        internal static extern int SteamStartEngine( ref TSteamError pError );

        [DllImport( "steam", CallingConvention = CallingConvention.Cdecl )]
        internal static extern int SteamStartup( uint usingMask, ref TSteamError pError );

        [DllImport( "steam", CallingConvention = CallingConvention.Cdecl )]
        internal static extern int SteamLogin( string szUser, string szPassword, int bIsSecureComputer, ref TSteamError pError );

        [DllImport( "steam", CallingConvention = CallingConvention.Cdecl )]
        internal static extern int SteamBlockingCall( uint handle, int uiProcessTickMS, ref TSteamError pError );

        [DllImport( "steam", CallingConvention = CallingConvention.Cdecl )]
        internal static extern int SteamShutdownEngine( ref TSteamError pError );

        [DllImport( "steam", CallingConvention = CallingConvention.Cdecl )]
        internal static extern int SteamCleanup( ref TSteamError pError );

        [DllImport( "steam", CallingConvention = CallingConvention.Cdecl )]
        internal static extern int SteamProcessCall( int steamHandle, ref TSteamProgress pProgress, ref TSteamError pError );

        [DllImport( "steam", CallingConvention = CallingConvention.Cdecl )]
        internal static extern int SteamIsLoggedIn( ref int isLoggedIn, ref TSteamError pError );

        [DllImport( "steam", CallingConvention = CallingConvention.Cdecl )]
        internal static extern int SteamSetUser( string szUser, ref int bUserSet, ref TSteamError pError );

        [DllImport( "steam", CallingConvention = CallingConvention.Cdecl )]
        internal static extern int SteamGetUser( [Out] StringBuilder szUser, uint uBufSize, out uint puUserChars, ref TSteamGlobalUserID pSteamGlobalUserID, ref TSteamError pError );

        [DllImport( "steam", CallingConvention = CallingConvention.Cdecl )]
        internal static extern int SteamGetCurrentEmailAddress( [Out] StringBuilder szEmailaddress, uint uBufSize, out uint puEmailaddressChars, ref TSteamError pError );

        public static void Initialize()
        {
            TSteamError error = new TSteamError();

            if ( SteamStartEngine( ref error ) == 0 )
                throw new Exception( error.szDesc );

            if ( SteamStartup( /* STEAM_USING_ALL */ 15, ref error ) == 0 )
            {
                SteamShutdownEngine( ref error );

                throw new SteamException( error );
            }
        }

        public static int Login( string userName, string passWord )
        {
            TSteamError error = new TSteamError();

            int handle = SteamLogin( userName, passWord, 1, ref error );

            if ( handle == 0 )
                throw new SteamException( error );

            return handle;
        }

        public static TSteamGlobalUserID GetUser()
        {
            TSteamError error = new TSteamError();
            StringBuilder stringBuilder = new StringBuilder();
            uint userChars = 0;
            TSteamGlobalUserID globalUserId = new TSteamGlobalUserID();

            if ( SteamGetUser( stringBuilder, 1024, out userChars, ref globalUserId, ref error ) == 0 )
                throw new SteamException( error );

            return globalUserId;
        }

        public static string GetEmailAddress()
        {
            TSteamError error = new TSteamError();
            StringBuilder stringBuilder = new StringBuilder();
            uint emailChars = 0;

            if ( SteamGetCurrentEmailAddress( stringBuilder, 1024, out emailChars, ref error ) == 0 )
                throw new SteamException( error );

            return stringBuilder.ToString();
        }

        public static int SetUser( string userName )
        {
            TSteamError error = new TSteamError();
            int bUserSet = 0;

            int handle = SteamSetUser( userName, ref bUserSet, ref error );

            if ( handle == 0 )
                throw new SteamException( error );

            return handle;
        }

        public static bool IsLoggedIn()
        {
            TSteamError error = new TSteamError();

            int isLoggedIn = 0;
            if ( SteamIsLoggedIn( ref isLoggedIn, ref error ) == 0 )
            {
                throw new SteamException( error );
            }

            return isLoggedIn == 1;
        }

        public static void Shutdown()
        {
            TSteamError error = new TSteamError();

            // todo: handle errors?

            SteamCleanup( ref error );
            SteamShutdownEngine( ref error );
        }
    }
}