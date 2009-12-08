#include "SteamUserHandle.h"

namespace dotnetworks
{
	SteamUserHandle::SteamUserHandle( HSteamUser steamUser)
	{
		base = steamUser;
	}

	bool SteamUserHandle::operator == (SteamUserHandle^ left, SteamUserHandle^ right)
	{
		return left->base == right->base;
	}

}