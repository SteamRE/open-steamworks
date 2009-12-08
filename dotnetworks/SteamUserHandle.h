#pragma once

#include "SteamclientAPI.h"

namespace dotnetworks
{
	public ref class SteamUserHandle
	{
	public:
		SteamUserHandle( HSteamUser steamUser);

		static bool operator == (SteamUserHandle^ left, SteamUserHandle^ right);

		static const SteamUserHandle^ InvalidHandle = gcnew SteamUserHandle( 0 );

	internal:
		HSteamUser base;
	};
}