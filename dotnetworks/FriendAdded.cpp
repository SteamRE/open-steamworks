#pragma once

#include "SteamclientAPI.h"

#include "SteamID.cpp"

namespace dotnetworks
{
	public ref class FriendAdded
	{
	internal:
		FriendAdded( FriendAdded_t *friendAdded )
		{
			SteamId = gcnew SteamID( friendAdded->m_ulSteamID );
			Success = friendAdded->m_bSuccess != 0;
		};

	public:
		literal int Callback = FriendAdded_t::k_iCallback;

		SteamID^ SteamId;
		bool Success;
	};
}