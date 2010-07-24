using System.Collections.Generic;
namespace ChatLog
{
    using System;
    using System.Globalization;
    using System.IO;
    using Steam4NET;
    using System.Text;

    class LogManager
    {
        Settings sets;

        ISteamClient008 steamClient;
        ISteamFriends002 steamFriends;

        int pipe;
        int user;

        Dictionary<ulong, DateTime> sessionInfo;

        public event EventHandler<LogFailureEventArgs> LogFailure;

        Callback<FriendChatMsg_t> chatCallback;


        public LogManager( Settings settings )
        {
            sets = settings;

            sessionInfo = new Dictionary<ulong, DateTime>();

            chatCallback = new Callback<FriendChatMsg_t>( ChatMsg, FriendChatMsg_t.k_iCallback );

        }


        protected virtual void OnLogFailure( LogFailureEventArgs e )
        {
            if ( LogFailure != null )
                LogFailure( this, e );
        }

        public bool GetSteamClient()
        {
            if ( !Steamworks.Load() )
                return false;

            steamClient = Steamworks.CreateInterface<ISteamClient008>( "SteamClient008" );

            if ( steamClient == null )
                return false;

            return true;
        }

        public bool GetPipe()
        {
            if ( pipe != 0 )
            {
                steamClient.ReleaseSteamPipe( pipe );
            }

            pipe = steamClient.CreateSteamPipe();

            if ( pipe == 0 )
                return false;

            return true;
        }

        public bool GetUser()
        {
            if ( user != 0 )
            {
                steamClient.ReleaseUser( pipe, user );
            }

            user = steamClient.ConnectToGlobalUser( pipe );

            if ( user == 0 )
                return false;

            return true;
        }

        public bool GetInterface()
        {
            steamFriends = Steamworks.CastInterface<ISteamFriends002>( steamClient.GetISteamFriends( user, pipe, "SteamFriends002" ) );

            if ( steamFriends == null )
                return false;

            CallbackDispatcher.SpawnDispatchThread( pipe );

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

            string linkRep = sets.LookupLinkID( log.Sender );

            if ( linkRep == null )
                linkRep = log.SenderName;

            string fileLink = sets.LookupLinkID( log.Reciever );

            if ( fileLink == null )
                fileLink = log.RecieverName;


            try
            {
                directoryName = directoryName.FormatWith(
                    new
                    {
                        CommunityID = (ulong)log.Reciever,
                        SteamID = log.Reciever.Render().Replace( ":", sets.InvalidReplacement ),
                        Name = Util.StripInvalidChars( log.RecieverName, sets.InvalidReplacement ),
                        LinkID = Util.StripInvalidChars( fileLink, sets.InvalidReplacement ),
                        Date = Util.StripInvalidChars( DateTime.Now.ToString( sets.DateFormat, CultureInfo.CurrentCulture ), sets.InvalidReplacement ),
                        Time = Util.StripInvalidChars( DateTime.Now.ToString( sets.TimeFormat, CultureInfo.CurrentCulture ), sets.InvalidReplacement ),
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
                        CommunityID = (ulong)log.Reciever,
                        SteamID = log.Reciever.Render().Replace( ":", sets.InvalidReplacement ),
                        Name = Util.StripInvalidChars( log.RecieverName, sets.InvalidReplacement ),
                        LinkID = Util.StripInvalidChars( fileLink, sets.InvalidReplacement ),
                        Date = Util.StripInvalidChars( DateTime.Now.ToString( sets.DateFormat, CultureInfo.CurrentCulture ), sets.InvalidReplacement ),
                        Time = Util.StripInvalidChars( DateTime.Now.ToString( sets.TimeFormat, CultureInfo.CurrentCulture ), sets.InvalidReplacement ),
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
                CommunityID = (ulong)log.Sender,
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

            if ( log.MessageType == EChatEntryType.k_EChatEntryTypeChatMsg )
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
            else if ( log.MessageType == EChatEntryType.k_EChatEntryTypeEmote )
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

            ulong senderId = log.Sender;

            if ( sets.TrackSessions )
            {
                if ( sessionInfo.ContainsKey( senderId ) )
                {
                    DateTime lastMsg = sessionInfo[ senderId ];

                    if ( ( DateTime.Now - lastMsg ) > TimeSpan.FromMinutes( sets.MinsBetweenSessions ) )
                    {
                        File.AppendAllText( Path.Combine( directoryName, fileName ), Environment.NewLine + Environment.NewLine + "New session started on " + dateStr + " at " + timeStr + Environment.NewLine );
                        sessionInfo[ senderId ] = DateTime.Now;
                    }
                }
                else
                {
                    File.AppendAllText( Path.Combine( directoryName, fileName ), Environment.NewLine + Environment.NewLine + "New session started on " + dateStr + " at " + timeStr + Environment.NewLine );

                    sessionInfo.Add( senderId, DateTime.Now );
                }
            }

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

        void ChatMsg( FriendChatMsg_t chatMsg )
        {
            
            byte[] msgData = new byte[ 1024 * 4 ];
            EChatEntryType type = EChatEntryType.k_EChatEntryTypeChatMsg;

            CSteamID reciever = new CSteamID( chatMsg.m_ulReceiver );

            int msgLength = steamFriends.GetChatMessage( chatMsg.m_ulReceiver, ( int )chatMsg.m_iChatID, msgData, msgData.Length, ref type );

            if ( type == EChatEntryType.k_EChatEntryTypeTyping )
                return;

            if ( msgLength < 0 )
                msgLength = 1; // JUST IN CASE!!

            LogMessage log = new LogMessage();

            log.Sender = new CSteamID( chatMsg.m_ulSender );
            log.SenderName = steamFriends.GetFriendPersonaName( log.Sender );

            log.Reciever = reciever;
            log.RecieverName = steamFriends.GetFriendPersonaName( log.Reciever );

            log.Message = Encoding.UTF8.GetString( msgData ).Substring( 0, msgLength - 1 );
            log.MessageTime = DateTime.Now;
            log.MessageType = type;

            AddLog( log );
        }
        /*
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

                    SteamID reciever = chatMsg.Reciever;

                    steamFriends.GetChatMessage( reciever, (int)chatMsg.ChatID, out message, 1024 * 4, out type );

                    LogMessage log = new LogMessage();

                    log.Sender = chatMsg.Sender;
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
        }*/

    }
}