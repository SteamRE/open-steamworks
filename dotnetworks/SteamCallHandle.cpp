#pragma once

#include "SteamclientAPI.h"

namespace dotnetworks
{
	public ref class SteamCallHandle
	{
	public:
		SteamCallHandle( HSteamCall steamCall )
		{
			base = steamCall;
		}

	internal:
		HSteamCall base;
	};
}