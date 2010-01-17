#pragma once

#include "SteamclientAPI.h"

#include "SteamID.cpp"

namespace dotnetworks
{
	public ref class GroupChatMsg
	{
	internal:
		GroupChatMsg( GroupChatMsg_t *groupChat )
		{
			GroupID = gcnew SteamID( groupChat->m_GroupID );
			SenderID = gcnew SteamID( groupChat->m_SenderID );

			ChatID = groupChat->m_iChatID;
			Unknown = groupChat->m_iUnknown;
		};

	public:
		literal int Callback = GroupChatMsg_t::k_iCallback;

		SteamID^ GroupID;
		int ChatID;
		SteamID^ SenderID;
		int Unknown;

	};
}