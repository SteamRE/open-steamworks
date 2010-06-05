using System;
using System.Collections.Generic;
using System.Text;
using Steam4NET;

namespace OpenSteam
{
    class ChatManager
    {
        List<ChatForm> openChats;

        public ChatManager()
        {
            openChats = new List<ChatForm>();
        }

        public ChatForm GetChatForm( CSteamID steamId )
        {
            foreach ( ChatForm cf in openChats )
            {
                if ( cf.FriendID == steamId )
                    return cf;
            }

            ChatForm chatForm = new ChatForm( steamId );
            chatForm.FormClosed += ( obj, e ) =>
            {
                openChats.Remove( (ChatForm)obj );
            };
            openChats.Add( chatForm );

            return chatForm;
        }
    }
}
