using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using HeronIRC;
using dotnetworks;
using System.Runtime.InteropServices;

namespace IRC_Relay
{
    class RelayUser : IEquatable<SteamID>, IEquatable<RelayUser>
    {
        public SteamID SteamID;
        public DateTime LastMessage;
        public bool RelayingIRC;


        public bool Equals( SteamID other )
        {
            return SteamID == other;
        }
        public bool Equals( RelayUser other )
        {
            return SteamID == other.SteamID;
        }

    }
    class Program
    {
        // config stuff
        public static string RelayNetwork = "Gigenet.IL.US.GameSurge.net";
        public static string RelayChannel = "#opensteamworks";

        public static string RelayNick = "irc-relay";

        public static string FriendsName = "Default Nickname";

        public static TimeSpan RelayDelay = TimeSpan.FromSeconds( 1 );

        public static List<RelayUser> RelayTargets;


        static IrcClient ircClient;

        static SteamPipeHandle pipe;
        static SteamUserHandle user;
        static SteamClient008 steamClient;
        static SteamFriends001 steamFriends;
        static SteamUser012 steamUser;

        static bool connected;
        static bool running;

        [DllImport( "kernel32" )]
        private static extern bool SetConsoleCtrlHandler( EventHandler handler, bool add ); // for detecting console exit

        private delegate bool EventHandler( CtrlType sig );
        static EventHandler _handler;

        enum CtrlType
        {
            CTRL_C_EVENT = 0,
            CTRL_BREAK_EVENT = 1,
            CTRL_CLOSE_EVENT = 2,
            CTRL_LOGOFF_EVENT = 5,
            CTRL_SHUTDOWN_EVENT = 6
        }


        static void Main( string[] args )
        {
            int error;
            steamClient = (SteamClient008) Steamworks.CreateInterface( SteamClient008.InterfaceVersion, out error );
            if ( steamClient == null )
            {
                Console.WriteLine( "Unable to get SteamClient." );
                return;
            }

            pipe = steamClient.CreateSteamPipe();
            user = steamClient.ConnectToGlobalUser( pipe );


            _handler += new EventHandler( ConsoleEvent );
            SetConsoleCtrlHandler( _handler, true );

            steamFriends = ( SteamFriends001 )steamClient.GetISteamFriends( user, pipe, SteamFriends001.InterfaceVersion );
            steamUser = (SteamUser012) steamClient.GetISteamUser( user, pipe, SteamUser012.InterfaceVersion );

            FriendsName = steamFriends.GetPersonaName();

            RelayTargets = new List<RelayUser>();

            ircClient = new IrcClient( RelayNick );
            ircClient.AlternateNickname = RelayNick + "`";

            ircClient.Debugger.Debugging = DebugMode.All;

            ConnectionParser connection = ircClient.ConnectionParser;
            MessageParser message = ircClient.MessageParser;

            connection.Connected += new EventHandler<InfoEventArgs>( connection_Connected );
            message.ChannelMessage += new EventHandler<MessageEventArgs>( message_ChannelMessage );

            running = ircClient.Connect( RelayNetwork );

            DateTime lastUpdate = DateTime.Now;
            while ( running )
            {
                ircClient.UpdateIn();

                if ( ( DateTime.Now - lastUpdate ) >= RelayDelay && connected )
                {
                    ircClient.UpdateOut();
                    lastUpdate = DateTime.Now;
                }
                else
                    ircClient.UpdateOut();

                if ( !connected )
                    continue;

                Callback callback;
                SteamCallHandle steamCall;

                if ( Steamworks.Steam_BGetCallback( pipe, out callback, out steamCall ) )
                {
                    Console.WriteLine( "Callback: " + callback.CallbackNum );

                    if ( callback.CallbackNum == FriendChatMsg.Callback )
                    {
                        FriendChatMsg chatMsg = ( FriendChatMsg )callback.CallbackObject;

                        SteamID sender = new SteamID( chatMsg.Sender );
                        SteamID reciever = new SteamID( chatMsg.Reciever );

                        if ( sender.Equals( steamUser.GetSteamID() ) )
                        {
                            Steamworks.Steam_FreeLastCallback( pipe );
                            continue;
                        }

                        string msg;
                        FriendMsgType msgType;
                        steamFriends.GetChatMessage( reciever, ( int )chatMsg.ChatID, out msg, 400, out msgType );

                        if ( msgType != FriendMsgType.Chat )
                        {
                            Steamworks.Steam_FreeLastCallback( pipe );
                            continue;
                        }

                        string senderStr = steamFriends.GetFriendPersonaName( sender );
                        msg = msg.Replace( "\n", " " ).Replace( "\r", " " ).Replace( "DCC", "" );

                        RelayUser ru = new RelayUser()
                        {
                            SteamID = sender,
                            LastMessage = DateTime.Now.Subtract( TimeSpan.FromSeconds( 1 ) ),
                        };

                        if ( !RelayTargets.Contains( ru ) )
                            RelayTargets.Add( ru );

                        RelayUser realUser = RelayTargets.Find( new Predicate<RelayUser>( ( ruser ) => { return ruser.SteamID.Equals( sender ); } ) );


                        if ( msg.StartsWith( "!relayon" ) )
                        {
                            realUser.RelayingIRC = true;
                            steamFriends.SendMsgToFriend( sender, FriendMsgType.ChatSent, "You are now added to the relay list." );
                        }
                        else if ( msg.StartsWith( "!relayoff" ) )
                        {
                            realUser.RelayingIRC = false;
                            steamFriends.SendMsgToFriend( sender, FriendMsgType.ChatSent, "You have been removed from the relay list." );
                        }
                        else
                        {
                            if ( !realUser.RelayingIRC )
                            {
                                Steamworks.Steam_FreeLastCallback( pipe );
                                continue;
                            }

                            if ( ( DateTime.Now - realUser.LastMessage ) >= TimeSpan.FromSeconds( 1 ) )
                            {
                                realUser.LastMessage = DateTime.Now;
                                ircClient.SendMessage( RelayChannel, senderStr + ": " + msg );
                            }
                            else
                            {
                                steamFriends.SendMsgToFriend( sender, FriendMsgType.ChatSent, "You are sending messages too fast." );
                            }
                        }
                    }

                    Steamworks.Steam_FreeLastCallback( pipe );
                }
            }
        }

        static bool ConsoleEvent( CtrlType sig )
        {
            if ( steamFriends != null )
                steamFriends.SetPersonaName( FriendsName );

            return true;
        }

        static void message_ChannelMessage( object sender, MessageEventArgs e )
        {
            IrcClient client = sender as IrcClient;

            foreach ( RelayUser relay in RelayTargets )
            {
                if ( relay.RelayingIRC )
                    steamFriends.SendMsgToFriend( relay.SteamID, FriendMsgType.ChatSent, "<" + e.Sender.Nickname + "/" + e.SourceChannel + "> " + e.Message );
            }
        }

        static void connection_Connected( object sender, InfoEventArgs e )
        {
            IrcClient client = sender as IrcClient;

            client.JoinChannel( RelayChannel );

            connected = true;

            steamFriends.SetPersonaName( FriendsName + " | IRC Relay" );
        }
    }
}
