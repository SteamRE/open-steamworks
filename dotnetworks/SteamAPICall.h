#pragma once

#include "SteamclientAPI.h"

namespace dotnetworks
{
	public ref class SteamAPICall
	{
	public:
		SteamAPICall( SteamAPICall_t steamCall );

	internal:
		SteamAPICall_t base;
	};
}