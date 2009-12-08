
namespace ChatLog
{
    using System;

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

        public Settings()
        {
            Filename = "{Name}.txt";

            LogFormat = "[{Time}] {Name}: {Message}";
            EmoteFormat = "[{Time}] * {Name} {Message}";

            InvalidReplacement = "_";

            DateFormat = "d";
            TimeFormat = "t";
        }


        public bool Save()
        {
            return base.Save( BackingFile );
        }
    }
}
