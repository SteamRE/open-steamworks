
#include "SteamCallHandle.h"

namespace dotnetworks
{
	SteamCallHandle::SteamCallHandle(HSteamCall steamCall)
	{
		base = steamCall;
	}
}