
namespace ChatLog
{
    using System;
    using Steam4NET;

    class LogMessage
    {
        public bool IsGroupMsg;

        public CSteamID ChatRoom;
        public string ChatRoomName;

        public CSteamID Sender;
        public string SenderName;

        public CSteamID Reciever;
        public string RecieverName;

        public string Message;

        public DateTime MessageTime;

        public EChatEntryType MessageType;
    }
}
