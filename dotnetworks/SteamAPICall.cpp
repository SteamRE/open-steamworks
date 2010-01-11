#pragma once

#include "SteamclientAPI.h"

namespace dotnetworks
{
	public ref class SteamAPICall
	{
	public:
		SteamAPICall( SteamAPICall_t steamCall )
		{
			base = steamCall;
		}

	internal:
		SteamAPICall_t base;
	};
}