#include "stdafx.h"
#include "interfaces.h"

OptionDefinition* OptionDefinition::front = NULL;

using namespace boost::program_options;

DEFINE_CURRENT_VERSION( STEAMCLIENT,				008, ISteamClient,				SteamClient)
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
	std::ifstream ifcfg("steam_api.cfg");

	options_description desc;
	variables_map vm;

	OptionDefinition *opt = OptionDefinition::front;
	while(opt != NULL)
	{
		desc.add_options()
			(opt->option.c_str(), value<std::string>());

		opt = opt->next;
	}

	store(parse_config_file(ifcfg, desc), vm);

	TRYGET_CURRENT_VERSION_FACTORY( STEAMCLIENT,		SteamClient )
	TRYGET_CURRENT_VERSION_PIPE( STEAMUTILS,			SteamUtils,					GetISteamUtils )
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