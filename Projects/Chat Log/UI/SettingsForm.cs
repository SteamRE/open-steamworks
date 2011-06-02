
namespace ChatLog
{
    using System;
    using System.IO;
    using System.Windows.Forms;
    using System.Globalization;
    using System.Diagnostics;

    partial class SettingsForm : Form
    {
        Settings settings;

        string originalHelp;

        public SettingsForm( Settings sets )
        {
            settings = sets;


            InitializeComponent();

            this.Icon = Properties.Resources.logger;


            originalHelp = helpBox.Text;

            browseBox.Text = sets.LogDirectory;
            filenameBox.Text = sets.Filename;

            logFormatBox.Text = sets.LogFormat;
            emoteFormatBox.Text = sets.EmoteFormat;

            invalidCharBox.Text = sets.InvalidReplacement;

            dateFormatBox.Text = sets.DateFormat;
            timeFormatBox.Text = sets.TimeFormat;

            filenameBox.PreviewFunction = () =>
            {
                return IOPreview( filenameBox.Text );
            };

            logFormatBox.PreviewFunction = () =>
            {
                return LogPreview( logFormatBox.Text, "Hello there!" );
            };
            emoteFormatBox.PreviewFunction = () =>
            {
                return LogPreview( emoteFormatBox.Text, "does an emote." );
            };

            timeFormatBox.PreviewFunction = () =>
            {
                return DateTime.Now.ToString( timeFormatBox.Text, CultureInfo.CurrentCulture );
            };
            dateFormatBox.PreviewFunction = () =>
            {
                return DateTime.Now.ToString( dateFormatBox.Text, CultureInfo.CurrentCulture );
            };

            trackSessions.Checked = sets.TrackSessions;

            sessionMinutes.Text = sets.MinsBetweenSessions.ToString();

            enableGroupChats.Checked = sets.GroupChatEnabled;

            UpdateHelp();
        }

        private string IOPreview( string input )
        {
            string dateStr = string.Empty;
            try
            {
                dateStr = DateTime.Now.ToString( dateFormatBox.Text, CultureInfo.CurrentCulture );
            }
            catch
            {
                dateStr = "Bad Date Format";
            }

            string timeStr = string.Empty;
            try
            {
                timeStr = DateTime.Now.ToString( timeFormatBox.Text, CultureInfo.CurrentCulture );
            }
            catch
            {
                timeStr = "Bad Time Format";
            }

            var replaceTable = new
            {
                SteamID = "STEAM_0:0:123456".Replace( ":", Util.StripInvalidChars( invalidCharBox.Text, "" ) ),
                LinkID = "Some Linked ID",
                CommunityID = "7656119796123456",
                Name = Util.StripInvalidChars( "VoiDeD", Util.StripInvalidChars( invalidCharBox.Text, "" ) ),
                Date = Util.StripInvalidChars( dateStr, Util.StripInvalidChars( invalidCharBox.Text, "" ) ),
                Time = Util.StripInvalidChars( timeStr, Util.StripInvalidChars( invalidCharBox.Text, "" ) ),
            };

            return input.FormatWith( replaceTable );
        }

        private string LogPreview( string input, string message )
        {
            string dateStr = string.Empty;
            try
            {
                dateStr = DateTime.Now.ToString( dateFormatBox.Text, CultureInfo.CurrentCulture );
            }
            catch
            {
                dateStr = "Bad Date Format";
            }

            string timeStr = string.Empty;
            try
            {
                timeStr = DateTime.Now.ToString( timeFormatBox.Text, CultureInfo.CurrentCulture );
            }
            catch
            {
                timeStr = "Bad Time Format";
            }

            var ReplaceTable = new
            {
                Name = "VoiDeD",
                SteamID = "STEAM_0:0:123456",
                LinkID = "VoiDeD",
                CommunityID = "7656119796123456",

                Message = message,

                MyName = "Your Name",
                MySteamID = "STEAM_0:0:1337",

                Date = dateStr,
                Time = timeStr,
                UnixTime = ( DateTime.UtcNow - new DateTime( 1970, 1, 1, 0, 0, 0 ) ).TotalSeconds,
       

                NewLine = Environment.NewLine,
                Tab = "\t",
            };

            return input.FormatWith( ReplaceTable );
        }

        private void UpdateHelp()
        {
            filenameBox.Update();

            logFormatBox.Update();
            emoteFormatBox.Update();

            timeFormatBox.Update();
            dateFormatBox.Update();

            string dateFormat = dateFormatBox.GetPreviewString();
            string timeFormat = timeFormatBox.GetPreviewString();

            var helpReplacement = new
            {
                DateFormat = dateFormat,
                TimeFormat = timeFormat,
                SafeDate = Util.StripInvalidChars( dateFormat, Util.StripInvalidChars(invalidCharBox.Text, "") ),
                SafeTime = Util.StripInvalidChars( timeFormat, Util.StripInvalidChars(invalidCharBox.Text, "") ),
                InvalidReplacement = Util.StripInvalidChars( invalidCharBox.Text, ""),
            };

            helpBox.Text = originalHelp.FormatWith( helpReplacement );
        }

        private void SettingsForm_FormClosing( object sender, FormClosingEventArgs e )
        {
            settings.LogDirectory = browseBox.Text;
            settings.Filename = filenameBox.Text;

            settings.LogFormat = logFormatBox.Text;
            settings.EmoteFormat = emoteFormatBox.Text;

            settings.InvalidReplacement = Util.StripInvalidChars( invalidCharBox.Text, "" );

            settings.DateFormat = dateFormatBox.Text;
            settings.TimeFormat = timeFormatBox.Text;

            settings.TrackSessions = trackSessions.Checked;

            settings.GroupChatEnabled = enableGroupChats.Checked;

            try
            {
                settings.MinsBetweenSessions = int.Parse( sessionMinutes.Text );
            }
            catch
            {
                Util.ShowError( this, "Session minutes is in incorrect format." );

                e.Cancel = true;

                return;
            }

            try
            {
                settings.Save();
            }
            catch (Exception ex )
            {
                Util.ShowError( this, "Unable to save settings: " + ex.Message );
            }

            e.Cancel = true;

            this.Hide();
        }

        private void tabControl1_Selecting( object sender, TabControlCancelEventArgs e )
        {
            UpdateHelp();
        }

        private void linkLabel1_LinkClicked( object sender, LinkLabelLinkClickedEventArgs e )
        {
            Process.Start( "http://steamworks.assembla.com/wiki/show/steamworks" );
        }

        private void linkLabel2_LinkClicked( object sender, LinkLabelLinkClickedEventArgs e )
        {
            Process.Start( "http://www.facepunch.com/showthread.php?t=824685" );
        }

        private void linkLabel3_LinkClicked( object sender, LinkLabelLinkClickedEventArgs e )
        {
            Process.Start( "http://www.facepunch.com/showthread.php?t=840880" );
        }

        private void linkLabel4_LinkClicked( object sender, LinkLabelLinkClickedEventArgs e )
        {
            Process.Start( "http://msdn.microsoft.com/en-us/library/az4se3k1(lightweight).aspx" );
            Process.Start( "http://msdn.microsoft.com/en-us/library/8kb3ddd4(lightweight).aspx" );
        }

        private void editLinkIdsBox_Click( object sender, EventArgs e )
        {
            LinkIDForm lif = new LinkIDForm( settings );

            lif.ShowDialog( this );
        }

        public void SetGroupChatStatus( string status )
        {
            statusLabel.Text = "Group Chat Logging Status: " + status;
        }
    }
}
