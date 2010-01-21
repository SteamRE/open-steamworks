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
            [DllImport("kernel32.dll", SetLastError = true)]
            internal static extern IntPtr GetProcAddress(IntPtr hModule, string procName);
            
            [DllImport("kernel32.dll", SetLastError = true)]
            internal static extern IntPtr LoadLibraryEx(string lpszLib, IntPtr hFile, UInt32 dwFlags);
            
            [DllImport("kernel32.dll", SetLastError = true)]
            internal static extern IntPtr SetDllDirectory(string lpPathName);
            
            internal const UInt32 LOAD_WITH_ALTERED_SEARCH_PATH = 8;
        }

        private static Delegate GetExportDelegate<TDelegate>(IntPtr module, string name)
        {
            IntPtr address = Native.GetProcAddress(module, name);

            if (address == IntPtr.Zero)
            {
                return null;
            }

            return Marshal.GetDelegateForFunctionPointer(address, typeof(TDelegate));
        }

        private static TDelegate GetExportFunction<TDelegate>(IntPtr module, string name)
            where TDelegate : class
        {
            return (TDelegate)((object)GetExportDelegate<TDelegate>(module, name));
        }

        private static IntPtr Handle = IntPtr.Zero;

        public static string GetInstallPath()
        {
            return (string)Registry.GetValue(
                @"HKEY_LOCAL_MACHINE\Software\Valve\Steam",
                "InstallPath",
                null);
        }

        [UnmanagedFunctionPointer(CallingConvention.StdCall, CharSet = CharSet.Ansi)]
        private delegate IntPtr NativeCreateInterface(string version, IntPtr returnCode);
        private static NativeCreateInterface CallCreateInterface;
        public static TClass CreateInterface<TClass>(string version)
            where TClass : INativeWrapper, new()
        {
            IntPtr address = CallCreateInterface(version, IntPtr.Zero);

            if (address == IntPtr.Zero)
            {
                return default(TClass);
            }

            var rez = new TClass();
            rez.SetupFunctions(address);
            return rez;
        }

        public static TClass CastInterface<TClass>(IntPtr address)
            where TClass : INativeWrapper, new()
        {
            if(address == IntPtr.Zero)
            {
                return default(TClass);
            }

            var rez = new TClass();
            rez.SetupFunctions(address);
            return rez;
        }

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        private delegate bool NativeSteamBGetCallback(int pipe, ref CallbackMsg_t message, ref int call);
        private static NativeSteamBGetCallback CallSteamBGetCallback;
        public static bool GetCallback(int pipe, ref CallbackMsg_t message, ref int call)
        {
            return CallSteamBGetCallback(pipe, ref message, ref call);
        }

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        private delegate bool NativeSteamFreeLastCallback(int pipe);
        private static NativeSteamFreeLastCallback CallSteamFreeLastCallback;
        public static bool FreeLastCallback(int pipe)
        {
            return CallSteamFreeLastCallback(pipe);
        }

        public static bool Load()
        {
            if (Handle != IntPtr.Zero)
            {
                return true;
            }

            string path = GetInstallPath();
            if (path == null)
            {
                return false;
            }

            Native.SetDllDirectory(path + ";" + Path.Combine(path, "bin"));

            path = Path.Combine(path, "steamclient.dll");
            IntPtr module = Native.LoadLibraryEx(path, IntPtr.Zero, Native.LOAD_WITH_ALTERED_SEARCH_PATH);
            if (module == IntPtr.Zero)
            {
                return false;
            }

            CallCreateInterface = GetExportFunction<NativeCreateInterface>(
                module, "CreateInterface");
            if (CallCreateInterface == null)
            {
                return false;
            }

            CallSteamBGetCallback = GetExportFunction<NativeSteamBGetCallback>(
                module, "Steam_BGetCallback");
            if (CallSteamBGetCallback == null)
            {
                return false;
            }

            CallSteamFreeLastCallback = GetExportFunction<NativeSteamFreeLastCallback>(
                module, "Steam_FreeLastCallback");
            if (CallSteamFreeLastCallback == null)
            {
                return false;
            }

            Handle = module;
            return true;
        }
    }
}
