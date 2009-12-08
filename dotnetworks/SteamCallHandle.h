#pragma once

#include "SteamclientAPI.h"

namespace dotnetworks
{
	public ref class SteamCallHandle
	{
	public:
		SteamCallHandle(HSteamCall steamCall);

	internal:
		HSteamCall base;
	};
}