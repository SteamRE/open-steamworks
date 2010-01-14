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

		static bool operator == (SNetSocket^ left, SNetSocket^ right )
		{
			return left->base == right->base;
		}
		static bool operator != (SNetSocket^ left, SNetSocket^ right )
		{
			return !(left == right);
		}

		static const SNetSocket^ InvalidSocket = gcnew SNetSocket( 0 );

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

		static bool operator == (SNetListenSocket^ left, SNetListenSocket^ right )
		{
			return left->base == right->base;
		}
		static bool operator != (SNetListenSocket^ left, SNetListenSocket^ right )
		{
			return !(left == right);
		}

		static const SNetListenSocket^ InvalidSocket = gcnew SNetListenSocket( 0 );

	internal:
		SNetListenSocket_t base;
	};
}