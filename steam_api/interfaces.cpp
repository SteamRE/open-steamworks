#include "stdafx.h"
#include "interfaces.h"

DEFINE_CURRENT_VERSION( STEAMUSER,					012, ISteamUser,				SteamUser) 
DEFINE_CURRENT_VERSION( STEAMFRIENDS,				004, ISteamFriends,				SteamFriends)
DEFINE_CURRENT_VERSION( STEAMUTILS,					004, ISteamUtils,				SteamUtils)
DEFINE_CURRENT_VERSION( STEAMMATCHMAKING,			007, ISteamMatchmaking,			SteamMatchmaking)
DEFINE_CURRENT_VERSION( STEAMUSERSTATS,				004, ISteamUserStats,			SteamUserStats)
DEFINE_CURRENT_VERSION( STEAMAPPS,					003, ISteamApps,				SteamApps)
DEFINE_CURRENT_VERSION( STEAMNETWORKING,			003, ISteamNetworking,			SteamNetworking)
DEFINE_CURRENT_VERSION( STEAMMATCHMAKINGSERVERS,	002, ISteamMatchmakingServers,	SteamMatchmakingServers)
DEFINE_CURRENT_VERSION( STEAMREMOTESTORAGE,			002, ISteamRemoteStorage,		SteamRemoteStorage)


bool LoadInterfaces()
{
	TRYGET_CURRENT_VERSION_PIPE( STEAMUTILS,			GetISteamUtils )
	TRYGET_CURRENT_VERSION( STEAMUSER,					GetISteamUser )
	TRYGET_CURRENT_VERSION( STEAMFRIENDS,				GetISteamFriends )
	TRYGET_CURRENT_VERSION( STEAMMATCHMAKING,			GetISteamMatchmaking )
	TRYGET_CURRENT_VERSION( STEAMUSERSTATS,				GetISteamUserStats )
	TRYGET_CURRENT_VERSION( STEAMAPPS,					GetISteamApps )
	TRYGET_CURRENT_VERSION( STEAMNETWORKING,			GetISteamNetworking )
	TRYGET_CURRENT_VERSION( STEAMMATCHMAKINGSERVERS,	GetISteamMatchmakingServers )
	TRYGET_CURRENT_VERSION( STEAMREMOTESTORAGE,			GetISteamRemoteStorage )

	return true;
}

S_API ISteamClient* STEAM_CALL SteamClient()
{
	return (ISteamClient *)steamclient;
}