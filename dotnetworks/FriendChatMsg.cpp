#pragma once

#include "SteamclientAPI.h"

namespace dotnetworks
{
	public ref class FriendChatMsg
	{
	internal:
		FriendChatMsg( FriendChatMsg_t *chatMsg )
		{
			Sender = chatMsg->m_ulSender;
			Reciever = chatMsg->m_ulReceiver;
			Unknown = chatMsg->m_iUnknown1;
			ChatID = chatMsg->m_iChatID;
		}

	public:
		literal int Callback = 306;

		uint64 Sender;
		uint64 Reciever;
		uint32 Unknown;
		uint32 ChatID;

	};
}