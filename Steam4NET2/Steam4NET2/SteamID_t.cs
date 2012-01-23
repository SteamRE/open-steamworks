using System;
using System.Runtime.InteropServices;

namespace Steam4NET
{
    [StructLayout(LayoutKind.Explicit, Size=8)]
    public struct SteamID_t
    {
        [FieldOffset(0)]
        public UInt32 m_unAccountID; // : 32
        [FieldOffset(4)]
        // /!\ C# doesn't support bit fields, use this field like this: m_unAccountInstance & 0xFFFFF
        public UInt32 m_unAccountInstance; // : 20
        [FieldOffset(6)]
        // /!\ C# doesn't support bit fields, use this field like this: (m_EAccountType & 0xF0) >> 4
        public EAccountType m_EAccountType; // : 4
        [FieldOffset(7)]
        public EUniverse m_EUniverse; // : 8
    }
}
