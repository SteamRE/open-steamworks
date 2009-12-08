
#include "FriendGameInfo.h"

namespace dotnetworks
{
	FriendGameInfo::FriendGameInfo()
	{
	}

	FriendGameInfo::FriendGameInfo( FriendGameInfo_t *info )
	{
		Game = gcnew GameID( info->m_gameID );
		GameIP = info->m_unGameIP;
		GamePort = info->m_usGamePort;
		QueryPort = info->m_usQueryPort;
		SteamIDLobby = gcnew SteamID( info->m_steamIDLobby );
	}

}