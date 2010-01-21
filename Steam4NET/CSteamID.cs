using System;

namespace Steam4NET
{
    public class CSteamID
    {
        private UInt64 steamid;

        public CSteamID(UInt64 id)
        {
            steamid = id;
        }

        public UInt32 AccountID()
        {
            return (UInt32)(steamid & 0xFFFFFFFF);
        }

        public UInt32 AccountInstance()
        {
            return (UInt32)((steamid >> 32) & 0xFFFFF);
        }

        public EAccountType AccountType()
        {
            return (EAccountType)((steamid >> 52) & 0xF);
        }

        public EUniverse AccountUniverse()
        {
            return (EUniverse)((steamid >> 56) & 0xFF);
        }

        public string Render()
        {
            switch (AccountType())
            {
                case EAccountType.k_EAccountTypeInvalid:
                case EAccountType.k_EAccountTypeIndividual:
                    return String.Format("STEAM_0:{0}:{1}", AccountID() % 2, AccountID() / 2);
                default:
                    return Convert.ToString(steamid);
            }
        }

        public override string ToString()
        {
            return Render();
        }

        // provide this as implicit to make them decide what they want
        public static implicit operator string( CSteamID sid )
        {
            return sid.Render();
        }

        public static implicit operator UInt64( CSteamID sid )
        {
            return sid.steamid;
        }

        public static implicit operator CSteamID( UInt64 id )
        {
            return new CSteamID(id);
        }
    }
}