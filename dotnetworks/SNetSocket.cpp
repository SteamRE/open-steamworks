#pragma once

#include "SteamTypes.h"

namespace dotnetworks
{
	public ref class SNetSocket
	{
	public:
		SNetSocket( SNetSocket_t sock )
		{
			base = sock;
		}

	internal:
		SNetSocket_t base;
	};

	public ref class SNetListenSocket
	{
	public:
		SNetListenSocket( SNetListenSocket_t sock )
		{
			base = sock;
		}

	internal:
		SNetListenSocket_t base;
	};
}