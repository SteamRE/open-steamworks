namespace ChatLog
{
    using System;
    using System.Globalization;
    using System.IO;
    using Steam4NET;
    using System.Text;
    using System.Runtime.InteropServices;
    using System.Collections.Generic;

    [UnmanagedFunctionPointer( CallingConvention.ThisCall )]
    delegate Int32 NativeGetChatRoomEntry( IntPtr thisobj, UInt64 steamIDchat, Int32 iChatID, ref UInt64 steamIDuser, byte[] pvData, Int32 cubData, ref EChatEntryType peChatEntryType );

    [UnmanagedFunctionPointer( CallingConvention.ThisCall )]
    delegate string NativeGetChatRoomName( IntPtr thisobj, UInt64 steamIDchat );

    class LogManager
    {
        Settings sets;

        IClientEngine clientEngine;
        IClientFriends clientFriends;
        ISteamClient008 steamClient;
        ISteamFriends002 steamFriends;

        int pipe;
        int user;

        bool groupChatEnabled;
        NativeGetChatRoomEntry getChatMsg;
        NativeGetChatRoomName getChatName;
        string groupStatusMsg;

        Dictionary<ulong, DateTime> sessionInfo;

        public event EventHandler<LogFailureEventArgs> LogFailure;

        Callback<FriendChatMsg_t> chatCallback;
        Callback<PersonaStateChange_t> stateCallback;
        Callback<ChatRoomMsg_t> chatRoomCallback;


        public LogManager( Settings settings )
        {
            groupChatEnabled = false;

            sets = settings;

            sessionInfo = new Dictionary<ulong, DateTime>();

            chatCallback = new Callback<FriendChatMsg_t>( ChatMsg, FriendChatMsg_t.k_iCallback );
            stateCallback = new Callback<PersonaStateChange_t>( StateChange, PersonaStateChange_t.k_iCallback );
            chatRoomCallback = new Callback<ChatRoomMsg_t>( ChatRoomMsg, ChatRoomMsg_t.k_iCallback );

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
            clientEngine = Steamworks.CreateInterface<IClientEngine>( "CLIENTENGINE_INTERFACE_VERSION001" );

            if ( steamClient == null )
                return false;

            if ( clientEngine == null )
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

            clientFriends = Steamworks.CastInterface<IClientFriends>( clientEngine.GetIClientFriends( user, pipe, "CLIENTFRIENDS_INTERFACE_VERSION001" ) );

            if ( clientFriends == null )
                return false;

            VTScan vtScan = new VTScan( clientFriends.Interface );

            if ( vtScan.Init() )
            {

                /*
                .text:3809F73D 6A 00                                   push    0
                .text:3809F73F 68 62 D4 46 38                          push    offset unk_3846D462
                .text:3809F744 68 95 03 00 00                          push    394h
                .text:3809F749 68 40 E7 3C 38                          push    offset aEBuild_slav_20 ; "e:\\build_slave\\steam_rel_client_win32\\b"...
                .text:3809F74E 6A 00                                   push    0
                .text:3809F750 68 90 E7 3C 38                          push    offset asc_383CE790 ; "Assertion Failed: bufRet.GetUint8() == "...
                .text:3809F755 FF 15 44 E5 37 38                       call    ds:AssertMsgImplementation
                */
                var results = vtScan.DoScan<NativeGetChatRoomEntry>(
                    "\x6A\x00\x68\x62\xD4\x46\x38\x68\x83\x03\x00\x00\x68\x40\xE7\x3C\x38\x6A\x00\x68\x90\xE7\x3C\x38\xFF\x15\x44\xE5\x37\x38",
                    "xxx????xxxxxx????xxx????xx????"
                );

                bool foundFirst = false;

                if ( results.Count == 0 )
                {
                    groupStatusMsg = "Error: Unable to scan for GetChatRoomEntry";
                }
                else
                {
                    if ( results.Count > 1 )
                    {
                        groupStatusMsg = "Error: Scan for GetChatRoomEntry gave multiple results!";
                    }
                    else
                    {
                        getChatMsg = results[ 0 ].Delegate;
                        foundFirst = true;
                    }
                }

                /*
                .text:380A06A4 6A 00                                   push    0
                .text:380A06A6 68 69 D4 46 38                          push    offset unk_3846D469
                .text:380A06AB 68 AB 03 00 00                          push    3AAh
                .text:380A06B0 68 40 E7 3C 38                          push    offset aEBuild_slav_20 ; "e:\\build_slave\\steam_rel_client_win32\\b"...
                .text:380A06B5 6A 00                                   push    0
                .text:380A06B7 68 90 E7 3C 38                          push    offset asc_383CE790 ; "Assertion Failed: bufRet.GetUint8() == "...
                .text:380A06BC FF 15 44 E5 37 38                       call    ds:AssertMsgImplementation
                */

                var results2 = vtScan.DoScan<NativeGetChatRoomName>(
                    "\x6A\x00\x68\x69\xD4\x46\x38\x68\x99\x03\x00\x00\x68\x40\xE7\x3C\x38\x6A\x00\x68\x90\xE7\x3C\x38\xFF\x15\x44\xE5\x37\x38",
                    "xxx????xxxxxx????xxx????xx????"
                );

                if ( results2.Count == 0 )
                {
                    groupStatusMsg = "Error: Unable to scan for GetChatRoomName";
                }
                else
                {
                    if ( results2.Count > 1 )
                    {
                        groupStatusMsg = "Error: Scan for GetChatRoomName gave multiple results!";
                    }
                    else
                    {
                        getChatName = results2[ 0 ].Delegate;
                        groupChatEnabled = foundFirst && true;
                    }
                }
            }
            else
            {
                groupStatusMsg = "Error: Unable to initialize scan!";
            }

            CallbackDispatcher.SpawnDispatchThread( pipe );

            return true;
        }

        public string GetGroupChatStatus()
        {
            if ( groupChatEnabled )
                return "Working normally";

            return groupStatusMsg ?? "Not enabled. (Requires restart)";
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

            string fileLink = null;

            if ( log.IsGroupMsg )
                fileLink = sets.LookupLinkID( log.ChatRoom );
            else
                fileLink = sets.LookupLinkID( log.Reciever );

            if ( fileLink == null )
            {
                if ( log.IsGroupMsg )
                    fileLink = log.ChatRoomName;
                else
                    fileLink = log.RecieverName;
            }


            try
            {
                directoryName = directoryName.FormatWith(
                    new
                    {
                        CommunityID = ( ulong )log.Reciever,
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
                if ( log.IsGroupMsg )
                {
                    fileName = fileName.FormatWith(
                        new
                        {
                            Name = Util.StripInvalidChars( log.ChatRoomName, sets.InvalidReplacement ),
                            Date = Util.StripInvalidChars( DateTime.Now.ToString( sets.DateFormat, CultureInfo.CurrentCulture ), sets.InvalidReplacement ),
                            Time = Util.StripInvalidChars( DateTime.Now.ToString( sets.TimeFormat, CultureInfo.CurrentCulture ), sets.InvalidReplacement ),
                        }
                    );
                }
                else
                {
                    fileName = fileName.FormatWith(
                        new
                        {
                            CommunityID = ( ulong )log.Reciever,
                            SteamID = log.Reciever.Render().Replace( ":", sets.InvalidReplacement ),
                            Name = Util.StripInvalidChars( log.RecieverName, sets.InvalidReplacement ),
                            LinkID = Util.StripInvalidChars( fileLink, sets.InvalidReplacement ),
                            Date = Util.StripInvalidChars( DateTime.Now.ToString( sets.DateFormat, CultureInfo.CurrentCulture ), sets.InvalidReplacement ),
                            Time = Util.StripInvalidChars( DateTime.Now.ToString( sets.TimeFormat, CultureInfo.CurrentCulture ), sets.InvalidReplacement ),
                        }
                    );
                }
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
                CommunityID = ( ulong )log.Sender,
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

            if ( log.IsGroupMsg )
            {
                try
                {
                    File.AppendAllText( Path.Combine( directoryName, fileName ), logMessage + Environment.NewLine );
                    return;
                }
                catch ( Exception ex )
                {
                    OnLogFailure( new LogFailureEventArgs( ex.Message ) );
                    return;
                }
            }

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

        void StateChange( PersonaStateChange_t perState )
        {
        }

        int Clamp( int value, int min, int max )
        {
            if ( value < min )
                return min;

            if ( value > max )
                return max;

            return value;
        }

        void ChatRoomMsg( ChatRoomMsg_t chatMsg )
        {
            if ( !groupChatEnabled || !sets.GroupChatEnabled )
                return;

            byte[] msgData = new byte[ 1024 * 4 ];
            EChatEntryType chatType = EChatEntryType.k_EChatEntryTypeInvalid;
            ulong chatter = 0;

            int len = getChatMsg( clientFriends.Interface, chatMsg.m_ulSteamIDChat, ( int )chatMsg.m_iChatID, ref chatter, msgData, msgData.Length, ref chatType );

            len = Clamp( len, 1, msgData.Length );

            LogMessage log = new LogMessage();

            log.IsGroupMsg = true;
            log.ChatRoom = chatMsg.m_ulSteamIDChat;
            log.ChatRoomName = getChatName( clientFriends.Interface, log.ChatRoom );

            log.Sender = new CSteamID( chatMsg.m_ulSteamIDUser );
            log.SenderName = steamFriends.GetFriendPersonaName( log.Sender );

            log.Reciever = log.Sender;
            log.RecieverName = log.SenderName;

            log.Message = Encoding.UTF8.GetString( msgData, 0, len );
            log.Message = log.Message.Substring(0, log.Message.Length - 1);
            log.MessageTime = DateTime.Now;
            log.MessageType = chatType;

            AddLog( log );
            
        }

        void ChatMsg( FriendChatMsg_t chatMsg )
        {
            
            byte[] msgData = new byte[ 1024 * 4 ];
            EChatEntryType type = EChatEntryType.k_EChatEntryTypeChatMsg;

            CSteamID reciever = new CSteamID( chatMsg.m_ulReceiver );

            int msgLength = steamFriends.GetChatMessage( chatMsg.m_ulReceiver, ( int )chatMsg.m_iChatID, msgData, msgData.Length, ref type );

            if ( type == EChatEntryType.k_EChatEntryTypeTyping )
                return;

            msgLength = Clamp( msgLength, 1, msgData.Length );

            LogMessage log = new LogMessage();

            log.Sender = new CSteamID( chatMsg.m_ulSender );
            log.SenderName = steamFriends.GetFriendPersonaName( log.Sender );

            log.Reciever = reciever;
            log.RecieverName = steamFriends.GetFriendPersonaName( log.Reciever );

            log.Message = Encoding.UTF8.GetString( msgData, 0, msgLength );
            log.Message = log.Message.Substring( 0, log.Message.Length - 1 );
            log.MessageTime = DateTime.Now;
            log.MessageType = type;

            AddLog( log );
        }


        public void Close()
        {
            CallbackDispatcher.StopDispatchThread( this.pipe );
        }
    }
}