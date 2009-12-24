namespace ChatLog
{
    using System;
    using System.Globalization;
    using System.IO;
    using dotnetworks;

    class LogManager
    {
        Settings sets;

        SteamClient008 steamClient;
        SteamFriends001 steamFriends;

        SteamPipeHandle pipe;
        SteamUserHandle user;

        public event EventHandler<LogFailureEventArgs> LogFailure;


        public LogManager( Settings settings )
        {
            sets = settings;

        }


        protected virtual void OnLogFailure( LogFailureEventArgs e )
        {
            if ( LogFailure != null )
                LogFailure( this, e );
        }

        public bool GetSteamClient()
        {
            int error;
            steamClient = (SteamClient008)Steamworks.CreateInterface( SteamClient008.InterfaceVersion, out error );

            if ( error > 0 || steamClient == null )
                return false;

            return true;
        }

        public bool GetPipe()
        {
            pipe = steamClient.CreateSteamPipe();

            if ( pipe == SteamPipeHandle.InvalidHandle )
                return false;

            return true;
        }

        public bool GetUser()
        {
            user = steamClient.ConnectToGlobalUser( pipe );

            if ( user == SteamUserHandle.InvalidHandle )
                return false;

            return true;
        }

        public bool GetInterface()
        {
            steamFriends = (SteamFriends001)steamClient.GetISteamFriends( user, pipe, SteamFriends001.InterfaceVersion );

            if ( steamFriends == null )
                return false;

            return true;
        }

        private void AddLog( LogMessage log )
        {
            string directoryName = sets.LogDirectory;

            if ( string.IsNullOrEmpty( directoryName ) )
            {
                OnLogFailure( new LogFailureEventArgs( "Log directory not configured" ) );
                return;
            }

            string linkRep = sets.LookupLinkID( log.Sender.ConvertToUint64() );

            if ( linkRep == null )
                linkRep = log.SenderName;

            string fileLink = sets.LookupLinkID( log.Reciever.ConvertToUint64() );

            if ( fileLink == null )
                fileLink = log.RecieverName;


            try
            {
                directoryName = directoryName.FormatWith(
                    new
                    {
                        SteamID = log.Reciever.Render().Replace( ":", "_" ),
                        Name = Util.StripInvalidChars( log.RecieverName, sets.InvalidReplacement ),
                        LinkID = Util.StripInvalidChars( fileLink, sets.InvalidReplacement ),
                        Date = Util.StripInvalidChars( DateTime.Now.ToString( "d", CultureInfo.CurrentCulture ), sets.InvalidReplacement ),
                        Time = Util.StripInvalidChars( DateTime.Now.ToString( "t", CultureInfo.CurrentCulture ), sets.InvalidReplacement ),
                    }
                );
            }
            catch
            {
                OnLogFailure( new LogFailureEventArgs( "Directory name format is invalid" ) );
                return;
            }

            if ( !Directory.Exists( directoryName ) )
            {
                try
                {
                    Directory.CreateDirectory( directoryName );
                }
                catch
                {
                    OnLogFailure( new LogFailureEventArgs( "Log directory configured, but the directory could not be created" ) );
                    return;
                }
            }


            string fileName = sets.Filename;

            if ( string.IsNullOrEmpty( fileName ) )
            {
                OnLogFailure( new LogFailureEventArgs( "Log filename not configured" ) );
                return;
            }

            try
            {
                fileName = fileName.FormatWith(
                    new
                    {
                        SteamID = log.Reciever.Render().Replace( ":", "_" ),
                        Name = Util.StripInvalidChars( log.RecieverName, sets.InvalidReplacement ),
                        LinkID = Util.StripInvalidChars( fileLink, sets.InvalidReplacement ),
                        Date = Util.StripInvalidChars( DateTime.Now.ToString( "d", CultureInfo.CurrentCulture ), sets.InvalidReplacement ),
                        Time = Util.StripInvalidChars( DateTime.Now.ToString( "t", CultureInfo.CurrentCulture ), sets.InvalidReplacement ),
                    }
                );
            }
            catch
            {
                OnLogFailure( new LogFailureEventArgs( "Filename format is invalid" ) );
                return;
            }

            string logMessage = string.Empty;

            string dateStr = string.Empty;
            try
            {
                dateStr = DateTime.Now.ToString( sets.DateFormat, CultureInfo.CurrentCulture );
            }
            catch
            {
                OnLogFailure( new LogFailureEventArgs( "Bad date format" ) );
                return;

                //dateStr = "Bad Date Format";
            }

            string timeStr = string.Empty;
            try
            {
                timeStr = DateTime.Now.ToString( sets.TimeFormat, CultureInfo.CurrentCulture );
            }
            catch
            {
                OnLogFailure( new LogFailureEventArgs( "Bad time format" ) );
                return;

                //timeStr = "Bad Time Format";
            }


            var ReplaceTable = new
            {
                Name = log.SenderName,
                SteamID = log.Sender.Render(),
                LinkID = linkRep,

                Message = log.Message,

                MyName = log.RecieverName,
                MySteamID = log.Reciever.Render(),

                Date = dateStr,
                Time = timeStr,
                UnixTime = ( DateTime.UtcNow - new DateTime( 1970, 1, 1, 0, 0, 0 ) ).TotalSeconds,

                NewLine = Environment.NewLine,
                Tab = "\t",

            };

            if ( log.MessageType == FriendMsgType.Chat )
            {
                logMessage = sets.LogFormat;

                if ( string.IsNullOrEmpty( logMessage ) )
                {
                    OnLogFailure( new LogFailureEventArgs( "Log format not configured" ) );
                    return;
                }

                try
                {
                    logMessage = logMessage.FormatWith( ReplaceTable );
                }
                catch
                {
                    OnLogFailure( new LogFailureEventArgs( "Log format was invalid" ) );
                    return;
                }
            }
            else if ( log.MessageType == FriendMsgType.ChatSent ) // these are emotes for the newer interface versions
            {
                logMessage = sets.EmoteFormat;

                if ( string.IsNullOrEmpty( logMessage ) )
                {
                    OnLogFailure( new LogFailureEventArgs( "Log emote format not configured" ) );
                    return;
                }

                try
                {
                    logMessage = logMessage.FormatWith( ReplaceTable );
                }
                catch
                {
                    OnLogFailure( new LogFailureEventArgs( "Log emote format was invalid" ) );
                    return;
                }
            }

            if ( string.IsNullOrEmpty( logMessage ) )
                return;

            try
            {
                File.AppendAllText( Path.Combine( directoryName, fileName ), logMessage + Environment.NewLine );
            }
            catch ( Exception ex )
            {
                OnLogFailure( new LogFailureEventArgs( ex.Message ) );
                return;
            }
        }

        public void Update()
        {
            Callback callback;
            SteamCallHandle steamCall;

            if ( Steamworks.Steam_BGetCallback( pipe, out callback, out steamCall ) )
            {
                if ( callback.CallbackNum == FriendChatMsg.Callback )
                {
                    FriendChatMsg chatMsg = null;

                    try
                    {
                        chatMsg = (FriendChatMsg)callback.CallbackObject;
                    }
                    catch
                    {
                        Steamworks.Steam_FreeLastCallback( pipe );
                        OnLogFailure( new LogFailureEventArgs( "Recieved callback was not in the correct format.\nThis indicates a major change in the steam client, please contact voidedweasel@gmail.com." ) );
                        return;
                    }

                    string message = string.Empty;
                    FriendMsgType type;

                    SteamID reciever = new SteamID( chatMsg.Reciever );

                    steamFriends.GetChatMessage( reciever, (int)chatMsg.ChatID, out message, 1024 * 4, out type );

                    LogMessage log = new LogMessage();

                    log.Sender = new SteamID( chatMsg.Sender );
                    log.SenderName = steamFriends.GetFriendPersonaName( log.Sender );

                    log.Reciever = reciever;
                    log.RecieverName = steamFriends.GetFriendPersonaName( log.Reciever );

                    log.Message = message;
                    log.MessageTime = DateTime.Now;
                    log.MessageType = type;

                    AddLog( log );
                }

                Steamworks.Steam_FreeLastCallback( pipe );
            }
        }

    }
}