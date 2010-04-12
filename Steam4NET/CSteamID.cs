using System;

namespace Steam4NET
{
    internal class BitVector64
    {
        private UInt64 data;

        public BitVector64(UInt64 value)
        {
            data = value;
        }

        public UInt64 Data
        {
            get { return data; }
        }

        public UInt64 this[uint bitoffset, UInt64 valuemask]
        {
            get
            {
                return (data >> (ushort)bitoffset) & valuemask;
            }
            set
            {
                data = (data & ~(valuemask << (ushort)bitoffset) ) | ( (value & valuemask) << (ushort)bitoffset);
            }
        }
    }

    public class CSteamID
    {
        private BitVector64 steamid;

        public CSteamID(UInt64 id)
        {
            steamid = new BitVector64(id);
        }

        public UInt32 AccountID
        {
            get
            {
                return (UInt32)steamid[0, 0xFFFFFFFF];
            }
            set
            {
                steamid[0, 0xFFFFFFFF] = value;
            }
        }

        public UInt32 AccountInstance
        {
            get
            {
                return (UInt32)steamid[32, 0xFFFFF];
            }
            set
            {
                steamid[32, 0xFFFFF] = (UInt64)value;
            }
        }

        public EAccountType AccountType
        {
            get
            {
                return (EAccountType)steamid[52, 0xF];
            }
            set
            {
                steamid[52, 0xF] = (UInt64)value;
            }
        }

        public EUniverse AccountUniverse
        {
            get
            {
                return (EUniverse)steamid[56, 0xFF];
            }
            set
            {
                steamid[56, 0xFF] = (UInt64)value;
            }
        }

        public string Render()
        {
            switch (AccountType)
            {
                case EAccountType.k_EAccountTypeInvalid:
                case EAccountType.k_EAccountTypeIndividual:
                    if(AccountUniverse <= EUniverse.k_EUniversePublic)
                        return String.Format("STEAM_0:{0}:{1}", AccountID & 1, AccountID >> 1);
                    else
                        return String.Format("STEAM_{2}:{0}:{1}", AccountID & 1, AccountID >> 1, (int)AccountUniverse);
                default:
                    return Convert.ToString(this);
            }
        }

        public override string ToString()
        {
            return Render();
        }

        public static implicit operator UInt64( CSteamID sid )
        {
            return sid.steamid.Data;
        }

        public static implicit operator CSteamID( UInt64 id )
        {
            return new CSteamID(id);
        }

        public override bool Equals(System.Object obj)
        {
            if (obj == null)
                return false;

            CSteamID sid = obj as CSteamID;
            if ((System.Object)sid == null)
                return false;

            return steamid.Data == sid.steamid.Data;
        }

        public bool Equals(CSteamID sid)
        {
            if ((object)sid == null)
                return false;

            return steamid.Data == sid.steamid.Data;
        }

        public static bool operator ==(CSteamID a, CSteamID b)
        {
            if (System.Object.ReferenceEquals(a, b))
                return true;

            if (((object)a == null) || ((object)b == null))
                return false;

            return a.steamid.Data == b.steamid.Data;
        }

        public static bool operator !=(CSteamID a, CSteamID b)
        {
            return !(a == b);
        }

        public override int GetHashCode()
        {
            return steamid.Data.GetHashCode();
        }

    }
}