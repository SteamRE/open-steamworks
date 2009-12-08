#pragma once

#include "SteamclientAPI.h"

namespace dotnetworks
{
	public ref class SteamWindowClosed
	{
	internal:
		SteamWindowClosed( FriendEndChatSession_t *windowClosed )
		{
			SteamID = windowClosed->m_SteamID.ConvertToUint64();
		};

	public:
		literal int Callback = 312;

		uint64 SteamID;
	};
}