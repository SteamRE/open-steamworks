using System;

namespace Steam4NET
{
    public class CGameID
    {
        public const int k_EGameIDTypeApp = 0;
        public const int k_EGameIDTypeGameMod = 1;
        public const int k_EGameIDTypeShortcut = 2;
        public const int k_EGameIDTypeP2P = 3;

        private UInt64 gameid;

        public CGameID(UInt64 id)
        {
            gameid = id;
        }

        // provide this as implicit to make them decide what they want
        public static implicit operator string(CGameID gid)
        {
            return gid.gameid.ToString();
        }

        public static implicit operator UInt64(CGameID gid)
        {
            return gid.gameid;
        }

        public static implicit operator CGameID(UInt64 id)
        {
            return new CGameID(id);
        }

        public override bool Equals(System.Object obj)
        {
            if (obj == null)
                return false;

            CGameID gid = obj as CGameID;
            if ((System.Object)gid == null)
                return false;

            return gameid == gid.gameid;
        }

        public bool Equals(CGameID gid)
        {
            if ((object)gid == null)
                return false;

            return gameid == gid.gameid;
        }

        public static bool operator ==(CGameID a, CGameID b)
        {
            if (System.Object.ReferenceEquals(a, b))
                return true;

            if (((object)a == null) || ((object)b == null))
                return false;

            return a.gameid == b.gameid;
        }

        public static bool operator !=(CGameID a, CGameID b)
        {
            return !(a == b);
        }

        public override int GetHashCode()
        {
            return gameid.GetHashCode();
        }
    }
}
