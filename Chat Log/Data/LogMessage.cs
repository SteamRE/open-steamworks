
namespace ChatLog
{
    using System;
    using dotnetworks;

    class LogMessage
    {
        public SteamID Sender;
        public string SenderName;

        public SteamID Reciever;
        public string RecieverName;

        public string Message;

        public DateTime MessageTime;

        public FriendMsgType MessageType;
    }
}
