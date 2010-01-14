#pragma once

#include "SteamclientAPI.h"

#include "SteamID.cpp"

namespace dotnetworks
{
	public ref class FriendChatMsg
	{
	internal:
		FriendChatMsg( FriendChatMsg_t *chatMsg )
		{
			Sender = gcnew SteamID( chatMsg->m_ulSender );
			Reciever = gcnew SteamID( chatMsg->m_ulReceiver );

			Unknown = chatMsg->m_iUnknown1;
			ChatID = chatMsg->m_iChatID;
		}

	public:
		literal int Callback = FriendChatMsg_t::k_iCallback;

		SteamID^ Sender;
		SteamID^ Reciever;
		uint32 Unknown;
		uint32 ChatID;

	};
}