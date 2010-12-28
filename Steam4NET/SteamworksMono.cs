using System;
using System.IO;
using Microsoft.Win32;
using System.Text;
using System.Runtime.InteropServices;

/*
 Steamworks and NativeWrapper classes provided by Rick - http://gib.me/
*/

namespace Steam4NET
{
    public class Steamworks
    {
        private struct Native
        {
            [DllImport("steamclient", CallingConvention = CallingConvention.Cdecl)]
            [return: MarshalAs(UnmanagedType.I1)]
            internal static extern bool Steam_BGetCallback(int pipe, ref CallbackMsg_t message, ref int call);

            [DllImport("steamclient", CallingConvention = CallingConvention.Cdecl)]
            [return: MarshalAs(UnmanagedType.I1)]
            internal static extern bool Steam_FreeLastCallback(int pipe);

            [DllImport("steamclient", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Ansi)]
            internal static extern IntPtr CreateInterface(string version, IntPtr returnCode);

            [DllImport( "libsteam", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Ansi )]
            internal static extern IntPtr _f( string version );
        }

        public static TClass CreateInterface<TClass>(string version)
            where TClass : INativeWrapper, new()
        {
            IntPtr address = Native.CreateInterface(version, IntPtr.Zero);

            if (address == IntPtr.Zero)
            {
                return default(TClass);
            }

            var rez = new TClass();
            rez.SetupFunctions(address);
            return rez;
        }

        public static TClass CreateSteamInterface<TClass>( string version )
            where TClass : INativeWrapper, new()
        {
            IntPtr address = Native._f( version );

            if ( address == IntPtr.Zero )
                return default( TClass );

            var rez = new TClass();
            rez.SetupFunctions( address );

            return rez;
        }

        public static TClass CastInterface<TClass>(IntPtr address)
            where TClass : INativeWrapper, new()
        {
            if (address == IntPtr.Zero)
            {
                return default(TClass);
            }

            var rez = new TClass();
            rez.SetupFunctions(address);
            return rez;
        }

        public static bool GetCallback(int pipe, ref CallbackMsg_t message)
        {
            return Native.Steam_BGetCallback(pipe, ref message);
        }

        public static bool FreeLastCallback(int pipe)
        {
            return Native.Steam_FreeLastCallback(pipe);
        }

        public static bool Load()
        {
            return true;
        }
    }
}
