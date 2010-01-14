#pragma once

#include "SteamclientAPI.h"

#include "SteamID.cpp"

namespace dotnetworks
{
	public ref class SteamWindowClosed
	{
	internal:
		SteamWindowClosed( FriendEndChatSession_t *windowClosed )
		{
			SteamId = gcnew SteamID( windowClosed->m_SteamID );
		};

	public:
		literal int Callback = FriendEndChatSession_t::k_iCallback;

		SteamID^ SteamId;
	};
}