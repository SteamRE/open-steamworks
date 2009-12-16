#include "stdafx.h"
#include "interfaces.h"
#include "gameserver.h"
#include "contentserver.h"

OptionDefinition* OptionDefinition::front = NULL;

using namespace boost::program_options;
bool configLoaded = false;
options_description desc;
variables_map vm;

//api client interfaces
DEFINE_CURRENT_VERSION( STEAMCLIENT,				008, ISteamClient,				SteamClient)
DEFINE_CURRENT_VERSION( STEAMUSER,					012, ISteamUser,				SteamUser) 
DEFINE_CURRENT_VERSION( STEAMFRIENDS,				004, ISteamFriends,				SteamFriends)
DEFINE_CURRENT_VERSION( STEAMUTILS,					004, ISteamUtils,				SteamUtils)
DEFINE_CURRENT_VERSION( STEAMMATCHMAKING,			007, ISteamMatchmaking,			SteamMatchmaking)
DEFINE_CURRENT_VERSION( STEAMUSERSTATS,				006, ISteamUserStats,			SteamUserStats)
DEFINE_CURRENT_VERSION( STEAMAPPS,					003, ISteamApps,				SteamApps)
DEFINE_CURRENT_VERSION( STEAMNETWORKING,			003, ISteamNetworking,			SteamNetworking)
DEFINE_CURRENT_VERSION( STEAMMATCHMAKINGSERVERS,	002, ISteamMatchmakingServers,	SteamMatchmakingServers)
DEFINE_CURRENT_VERSION( STEAMREMOTESTORAGE,			002, ISteamRemoteStorage,		SteamRemoteStorage)

//gameserver interfaces
DEFINE_CURRENT_VERSION( STEAMGAMESERVER,			009, ISteamGameServer,			SteamGameServer)
DEFINE_CURRENT_VERSION( STEAMUTILS,					004, ISteamUtils,				SteamGameServerUtils)
DEFINE_CURRENT_VERSION( STEAMMASTERSERVERUPDATER,	001, ISteamMasterServerUpdater, SteamMasterServerUpdater)
DEFINE_CURRENT_VERSION( STEAMNETWORKING,			002, ISteamNetworking,			SteamGameServerNetworking)
DEFINE_CURRENT_VERSION( STEAMGAMESERVERITEMS,		003, ISteamGameServerItems,		SteamGameServerItems)

//contentserver interfaces
DEFINE_CURRENT_VERSION( STEAMCONTENTSERVER,			002, ISteamContentServer,		SteamContentServer )
DEFINE_CURRENT_VERSION( STEAMUTILS,					004, ISteamUtils,				SteamContentServerUtils )

void LoadConfig()
{
	std::ifstream ifcfg("steam_api.cfg");

	OptionDefinition *opt = OptionDefinition::front;
	while(opt != NULL)
	{
		desc.add_options()
			(opt->option.c_str(), value<std::string>());

		opt = opt->next;
	}

	store(parse_config_file(ifcfg, desc), vm);
}

bool LoadInterfaces(bool safe)
{
	if(!configLoaded)
		LoadConfig();

	TRYGET_CURRENT_VERSION_FACTORY( STEAMCLIENT,		SteamClient )
	TRYGET_CURRENT_VERSION_PIPE( STEAMUTILS,			SteamUtils,					GetISteamUtils )

	if(safe)
		return true;

	TRYGET_CURRENT_VERSION( STEAMUSER,					SteamUser,					GetISteamUser )
	TRYGET_CURRENT_VERSION( STEAMFRIENDS,				SteamFriends,				GetISteamFriends )
	TRYGET_CURRENT_VERSION( STEAMMATCHMAKING,			SteamMatchmaking,			GetISteamMatchmaking )
	TRYGET_CURRENT_VERSION( STEAMUSERSTATS,				SteamUserStats,				GetISteamUserStats )
	TRYGET_CURRENT_VERSION( STEAMAPPS,					SteamApps,					GetISteamApps )
	TRYGET_CURRENT_VERSION( STEAMNETWORKING,			SteamNetworking,			GetISteamNetworking )
	TRYGET_CURRENT_VERSION( STEAMMATCHMAKINGSERVERS,	SteamMatchmakingServers,	GetISteamMatchmakingServers )
	TRYGET_CURRENT_VERSION( STEAMREMOTESTORAGE,			SteamRemoteStorage,			GetISteamRemoteStorage )

	return true;
}

bool LoadInterfaces_GameServer(bool safe)
{
	if(!configLoaded)
		LoadConfig();

	STEAMCLIENT_ICLASS *steamclient = gameserver_steamclient;
	HSteamPipe pipe = gameserver_pipe;
	HSteamUser user = gameserver_user;

	TRYGET_CURRENT_VERSION( STEAMGAMESERVER,			SteamGameServer,				GetISteamGameServer )
	TRYGET_CURRENT_VERSION_PIPE( STEAMUTILS,			SteamGameServerUtils,			GetISteamUtils )

	if(safe)
		return true;

	TRYGET_CURRENT_VERSION( STEAMMASTERSERVERUPDATER,	SteamMasterServerUpdater,		GetISteamMasterServerUpdater)
	TRYGET_CURRENT_VERSION( STEAMNETWORKING,			SteamGameServerNetworking,		GetISteamNetworking)
	TRYGET_CURRENT_VERSION( STEAMGAMESERVERITEMS,		SteamGameServerItems,			GetISteamGenericInterface)

	return true;
}


bool LoadInterfaces_ContentServer()
{
	if(!configLoaded)
		LoadConfig();

	STEAMCLIENT_ICLASS *steamclient = contentserver_steamclient;
	HSteamPipe pipe = contentserver_pipe;
	HSteamUser user = contentserver_user;

	TRYGET_CURRENT_VERSION( STEAMCONTENTSERVER,		SteamContentServer,			GetISteamGenericInterface )
	TRYGET_CURRENT_VERSION_PIPE( STEAMUTILS,		SteamContentServerUtils,	GetISteamUtils )

	return true;
}