
namespace ChatLog
{
    using System;
    using System.Collections.Generic;

    public class Settings : Serializable<Settings>
    {
        public const string BackingFile = "settings.xml";

        public string LogDirectory;
        public string Filename;

        public string LogFormat;
        public string EmoteFormat;

        public string InvalidReplacement;

        public string DateFormat;
        public string TimeFormat;

        public bool TrackSessions;
        public int MinsBetweenSessions;

        public bool GroupChatEnabled;

        public List<LinkEntry> Links;


        public Settings()
        {
            Filename = "{Name}.txt";

            LogFormat = "[{Time}] {Name}: {Message}";
            EmoteFormat = "[{Time}] * {Name} {Message}";

            InvalidReplacement = "_";

            DateFormat = "d";
            TimeFormat = "t";

            TrackSessions = true;
            MinsBetweenSessions = 60;

            Links = new List<LinkEntry>();
        }

        public string LookupLinkID( ulong commId )
        {
            foreach ( LinkEntry le in Links )
            {
                if ( le.SteamID == commId )
                    return le.Name;
            }
            return null;
        }


        public bool Save()
        {
            return base.Save( BackingFile );
        }
    }
}
