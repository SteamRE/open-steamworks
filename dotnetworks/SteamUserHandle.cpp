#pragma once

#include "SteamclientAPI.h"

namespace dotnetworks
{
	public ref class SteamUserHandle
	{
	public:
		SteamUserHandle( HSteamUser steamUser)
		{
			base = steamUser;
		}

		static bool operator == (SteamUserHandle^ left, SteamUserHandle^ right)
		{
			return left->base == right->base;
		}

		static const SteamUserHandle^ InvalidHandle = gcnew SteamUserHandle( 0 );

	internal:
		HSteamUser base;
	};
}