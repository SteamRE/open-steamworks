#pragma once

#include "SteamclientAPI.h"

#include "SteamID.h"
#include "GameID.h"


namespace dotnetworks
{
	public ref class FriendGameInfo
	{
	public:
		FriendGameInfo();

	internal:
		FriendGameInfo( FriendGameInfo_t *info );

	public:
		property GameID^ Game;
		property uint32 GameIP;
		property uint16 GamePort;
		property uint16 QueryPort;
		property SteamID^ SteamIDLobby;
	};
}