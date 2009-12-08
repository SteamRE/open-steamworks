
#include "SteamPipeHandle.h"

namespace dotnetworks
{
	SteamPipeHandle::SteamPipeHandle( HSteamPipe steamPipe )
	{
		base = steamPipe;
	}

	bool SteamPipeHandle::operator == (SteamPipeHandle^ left, SteamPipeHandle^ right)
	{
		return left->base == right->base;
	}
}