#pragma once

#include "SteamclientAPI.h"

#include "SteamID.cpp"
#include "GameID.cpp"


namespace dotnetworks
{
	public ref class FriendGameInfo
	{
	public:
		FriendGameInfo()
		{
		}

	internal:
		FriendGameInfo( FriendGameInfo_t *info )
		{
			Game = gcnew GameID( info->m_gameID );
			GameIP = info->m_unGameIP;
			GamePort = info->m_usGamePort;
			QueryPort = info->m_usQueryPort;
			SteamIDLobby = gcnew SteamID( info->m_steamIDLobby );
		}

	public:
		property GameID^ Game;
		property uint32 GameIP;
		property uint16 GamePort;
		property uint16 QueryPort;
		property SteamID^ SteamIDLobby;
	};
}