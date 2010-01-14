#pragma once

#include "SteamclientAPI.h"

#include "SteamID.cpp"

namespace dotnetworks
{
	public ref class UserRequestingFriendship
	{
	internal:
		UserRequestingFriendship( UserRequestingFriendship_t *friendshipRequest )
		{
			SteamId = gcnew SteamID( friendshipRequest->m_ulSteamID );
		};

	public:
		literal int Callback = UserRequestingFriendship_t::k_iCallback;

		SteamID^ SteamId;
	};
}