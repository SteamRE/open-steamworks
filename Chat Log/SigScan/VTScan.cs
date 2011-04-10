using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.Diagnostics;
using System.Collections.ObjectModel;

namespace ChatLog
{
    class ScanResultCollection<T> : ReadOnlyCollection<ScanResult<T>>
    {
        public ScanResultCollection( IList<ScanResult<T>> list )
            : base( list )
        {
        }
    }

    class ScanResult<T>
    {
        public T Delegate { get; private set; }
        public uint Address { get; private set; }

        public ScanResult( T dele, uint addr )
        {
            this.Delegate = dele;
            this.Address = addr;
        }
    }

    class VTScan
    {
        static class Native
        {
            [DllImport( "kernel32.dll" )]
            public static extern int VirtualQuery(
                IntPtr lpAddress,
                ref MEMORY_BASIC_INFORMATION lpBuffer,
                uint dwLength
            );

            public const ushort IMAGE_DOS_SIGNATURE = 0x5A4D; // MZ
            public const uint IMAGE_NT_SIGNATURE = 0x00004550; // PE00

            [StructLayout( LayoutKind.Sequential )]
            public struct MEMORY_BASIC_INFORMATION
            {
                public IntPtr BaseAddress;
                public IntPtr AllocationBase;
                public uint AllocationProtect;
                public IntPtr RegionSize;
                public uint State;
                public uint Protect;
                public uint Type;
            }

            [StructLayout( LayoutKind.Sequential )]
            public struct IMAGE_DOS_HEADER
            {
                public UInt16 e_magic;       // Magic number
                public UInt16 e_cblp;        // Bytes on last page of file
                public UInt16 e_cp;          // Pages in file
                public UInt16 e_crlc;        // Relocations
                public UInt16 e_cparhdr;     // Size of header in paragraphs
                public UInt16 e_minalloc;    // Minimum extra paragraphs needed
                public UInt16 e_maxalloc;    // Maximum extra paragraphs needed
                public UInt16 e_ss;          // Initial (relative) SS value
                public UInt16 e_sp;          // Initial SP value
                public UInt16 e_csum;        // Checksum
                public UInt16 e_ip;          // Initial IP value
                public UInt16 e_cs;          // Initial (relative) CS value
                public UInt16 e_lfarlc;      // File address of relocation table
                public UInt16 e_ovno;        // Overlay number
                [MarshalAs( UnmanagedType.ByValArray, SizeConst = 4 )]
                public UInt16[] e_res1;        // Reserved words
                public UInt16 e_oemid;       // OEM identifier (for e_oeminfo)
                public UInt16 e_oeminfo;     // OEM information; e_oemid specific
                [MarshalAs( UnmanagedType.ByValArray, SizeConst = 10 )]
                public UInt16[] e_res2;        // Reserved words
                public Int32 e_lfanew;      // File address of new exe header
            }

            [StructLayout( LayoutKind.Sequential )]
            public struct IMAGE_NT_HEADERS
            {
                public UInt32 Signature;
                public IMAGE_FILE_HEADER FileHeader;
                public IMAGE_OPTIONAL_HEADER32 OptionalHeader;
            }

            [StructLayout( LayoutKind.Sequential )]
            public struct IMAGE_FILE_HEADER
            {
                public UInt16 Machine;
                public UInt16 NumberOfSections;
                public UInt32 TimeDateStamp;
                public UInt32 PointerToSymbolTable;
                public UInt32 NumberOfSymbols;
                public UInt16 SizeOfOptionalHeader;
                public UInt16 Characteristics;
            }

            [StructLayout( LayoutKind.Sequential )]
            public struct IMAGE_OPTIONAL_HEADER32
            {
                //
                // Standard fields.
                //
                public UInt16 Magic;
                public Byte MajorLinkerVersion;
                public Byte MinorLinkerVersion;
                public UInt32 SizeOfCode;
                public UInt32 SizeOfInitializedData;
                public UInt32 SizeOfUninitializedData;
                public UInt32 AddressOfEntryPoint;
                public UInt32 BaseOfCode;
                public UInt32 BaseOfData;
                //
                // NT additional fields.
                //
                public UInt32 ImageBase;
                public UInt32 SectionAlignment;
                public UInt32 FileAlignment;
                public UInt16 MajorOperatingSystemVersion;
                public UInt16 MinorOperatingSystemVersion;
                public UInt16 MajorImageVersion;
                public UInt16 MinorImageVersion;
                public UInt16 MajorSubsystemVersion;
                public UInt16 MinorSubsystemVersion;
                public UInt32 Win32VersionValue;
                public UInt32 SizeOfImage;
                public UInt32 SizeOfHeaders;
                public UInt32 CheckSum;
                public UInt16 Subsystem;
                public UInt16 DllCharacteristics;
                public UInt32 SizeOfStackReserve;
                public UInt32 SizeOfStackCommit;
                public UInt32 SizeOfHeapReserve;
                public UInt32 SizeOfHeapCommit;
                public UInt32 LoaderFlags;
                public UInt32 NumberOfRvaAndSizes;
                [MarshalAs( UnmanagedType.ByValArray, SizeConst = 16 )]
                public IMAGE_DATA_DIRECTORY[] DataDirectory;
            }

            [StructLayout( LayoutKind.Sequential )]
            public struct IMAGE_DATA_DIRECTORY
            {
                public UInt32 VirtualAddress;
                public UInt32 Size;
            }
        }

        IntPtr vtObject;
        uint baseAddr, baseLen;

        List<IntPtr> vtFuncs = new List<IntPtr>();


        public unsafe VTScan( IntPtr vtObject )
        {
            this.vtObject = vtObject;

            int* vtable = ( int* )*( ( int* )vtObject.ToInt32() );
            for ( int i = 0 ; vtable[ i ] != 0 ; ++i )
            {
                vtFuncs.Add( new IntPtr( vtable[ i ] ) );
            }
        }


        public bool Init()
        {
            if ( vtFuncs.Count == 0 )
                return false;

            Native.MEMORY_BASIC_INFORMATION memInfo = new Native.MEMORY_BASIC_INFORMATION();

            if ( Native.VirtualQuery( vtFuncs[ 0 ], ref memInfo, ( uint )Marshal.SizeOf( memInfo ) ) == 0 )
                return false;

            baseAddr = ( uint )memInfo.AllocationBase.ToInt32();

            Native.IMAGE_DOS_HEADER dos = PtrToStruct<Native.IMAGE_DOS_HEADER>( memInfo.AllocationBase );

            if ( dos.e_magic != Native.IMAGE_DOS_SIGNATURE )
                return false;

            Native.IMAGE_NT_HEADERS pe = PtrToStruct<Native.IMAGE_NT_HEADERS>( new IntPtr( baseAddr + dos.e_lfanew ) );

            if ( pe.Signature != Native.IMAGE_NT_SIGNATURE )
                return false;

            baseLen = pe.OptionalHeader.SizeOfImage;

            return true;
        }

        public unsafe ScanResultCollection<T> DoScan<T>( string sig, string mask )
            where T : class
        {
            Debug.Assert( sig.Length == mask.Length );
            int sigLen = sig.Length;

            List<ScanResult<T>> matches = new List<ScanResult<T>>();

            foreach ( IntPtr vFunc in vtFuncs )
            {

                byte* basePtr = ( byte* )vFunc.ToInt32();
                byte* endPtr = ( byte* )( baseAddr + baseLen );
                int i = 0;

                while ( basePtr < endPtr )
                {
                    for ( i = 0 ; i < sigLen ; ++i )
                    {
                        if ( ( mask[ i ] != '?' ) && ( sig[ i ] != basePtr[ i ] ) )
                            break;
                    }

                    ushort padding = *( ushort* )basePtr;

                    if ( padding == 0xCCCC )
                        break;

                    if ( i == sigLen )
                    {
                        ScanResult<T> result = new ScanResult<T>( ( T )( object )Marshal.GetDelegateForFunctionPointer( vFunc, typeof( T ) ), ( uint )vFunc.ToInt32() );
                        matches.Add( result );
                    }

                    basePtr++;
                }
            }

            ScanResultCollection<T> src = new ScanResultCollection<T>( matches );
            return src;
        }

        T PtrToStruct<T>( IntPtr addr )
        {
            return ( T )Marshal.PtrToStructure( addr, typeof( T ) );
        }
    }
}
