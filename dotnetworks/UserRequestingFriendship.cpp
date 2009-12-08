#pragma once

#include "SteamclientAPI.h"

namespace dotnetworks
{
	public ref class UserRequestingFriendship
	{
	internal:
		UserRequestingFriendship( UserRequestingFriendship_t *friendshipRequest )
		{
			SteamID = friendshipRequest->m_ulSteamID;
		};

	public:
		literal int Callback = 302;

		uint64 SteamID;
	};
}