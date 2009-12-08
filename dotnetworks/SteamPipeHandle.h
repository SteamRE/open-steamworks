#pragma once

#include "SteamclientAPI.h"


namespace dotnetworks
{
	public ref class SteamPipeHandle
	{
	public:
		SteamPipeHandle( HSteamPipe steamPipe );

		static bool operator == (SteamPipeHandle^ left, SteamPipeHandle^ right);

		static const SteamPipeHandle^ InvalidHandle = gcnew SteamPipeHandle( 0 );

	internal:
		HSteamPipe base;
	};
}