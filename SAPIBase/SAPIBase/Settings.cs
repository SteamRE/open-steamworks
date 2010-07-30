using System;
using System.Collections.Generic;
using System.Text;

namespace SAPIBase
{
    [AttributeUsage( AttributeTargets.Property, Inherited = false, AllowMultiple = false )]
    sealed class SettingAttribute : Attribute
    {
        public string Display { get; set; }
    }

    static class Settings
    {
        [Setting( Display = "Hide Non-Installable Apps (No Gamedir)" )]
        public static bool HideNonInstallable { get; set; }

        [Setting( Display = "Hide Tools (SDKs, etc)" )]
        public static bool HideTools { get; set; }

        [Setting( Display = "Hide Unavailable (state = eStateUnAvailable)" )]
        public static bool HideUnavailable { get; set; }

        [Setting( Display = "Hide Demos" )]
        public static bool HideDemos { get; set; }
        [Setting( Display = "Hide DLC" )]
        public static bool HideDLC { get; set; }
        [Setting( Display = "Hide Movies" )]
        public static bool HideMovies { get; set; }

        static Settings()
        {
            HideNonInstallable = HideTools = HideUnavailable = HideDemos = HideDLC = HideMovies = true;
        }
    }
}
