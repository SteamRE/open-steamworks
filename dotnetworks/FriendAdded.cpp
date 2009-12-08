#pragma once

#include "SteamclientAPI.h"

namespace dotnetworks
{
	public ref class FriendAdded
	{
	internal:
		FriendAdded( FriendAdded_t *friendAdded )
		{
			SteamID = friendAdded->m_ulSteamID;
			Success = friendAdded->m_bSuccess != 0;
		};

	public:
		literal int Callback = 301;

		uint64 SteamID;
		bool Success;
	};
}