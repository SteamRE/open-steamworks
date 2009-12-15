#pragma once

class OptionDefinition
{
public:
	OptionDefinition(std::string option) : option(option) { next = front; front = this; };

	std::string option;
	OptionDefinition* next;
	static OptionDefinition* front;
};

#define EXPORT_CURRENT_VERSION(ICLASS, EXPORT) \
	S_API ICLASS * STEAM_CALL EXPORT();

#define DEFINE_CURRENT_VERSION(IFACE, VERSION, ICLASS, EXPORT) \
	std::string IFACE##_##EXPORT##_VERSION = IFACE##_INTERFACE_VERSION_##VERSION; \
	void* IFACE##_##EXPORT##_PTR = NULL; \
	S_API ICLASS* STEAM_CALL EXPORT() { return (ICLASS *) IFACE##_##EXPORT##_PTR; }; \
	OptionDefinition IFACE##_##EXPORT##_OPTION( #EXPORT );

#define REPLACE_WITH_OPTION(IFACE, EXPORT) \
	if(vm.count(#EXPORT)) IFACE##_##EXPORT##_VERSION = vm[#EXPORT].as<std::string>();

#define TRYGET_CURRENT_VERSION(IFACE, EXPORT, VMETHOD) \
	REPLACE_WITH_OPTION(IFACE, EXPORT) \
	IFACE##_##EXPORT##_PTR = (void *)steamclient->VMETHOD(user, pipe, IFACE##_##EXPORT##_VERSION.c_str()); \
	if( IFACE##_##EXPORT##_PTR == NULL ) { std::cerr << "Unable to get " << #VMETHOD << "-" << IFACE##_##EXPORT##_VERSION << std::endl; return false; }

#define TRYGET_CURRENT_VERSION_PIPE(IFACE, EXPORT, VMETHOD) \
	REPLACE_WITH_OPTION(IFACE, EXPORT) \
	IFACE##_##EXPORT##_PTR = (void *)steamclient->VMETHOD(pipe, IFACE##_##EXPORT##_VERSION.c_str()); \
	if( IFACE##_##EXPORT##_PTR == NULL ) return false;

#define TRYGET_CURRENT_VERSION_FACTORY(IFACE, EXPORT) \
	REPLACE_WITH_OPTION(IFACE, EXPORT) \
	IFACE##_##EXPORT##_PTR = (void *)clientFactory(IFACE##_##EXPORT##_VERSION.c_str(), NULL); \
	if( IFACE##_##EXPORT##_PTR == NULL ) return false;

bool LoadInterfaces(bool safe);

//api user exports
EXPORT_CURRENT_VERSION(ISteamClient,				SteamClient);
EXPORT_CURRENT_VERSION(ISteamUser,					SteamUser);
EXPORT_CURRENT_VERSION(ISteamFriends,				SteamFriends);
EXPORT_CURRENT_VERSION(ISteamUtils,					SteamUtils);
EXPORT_CURRENT_VERSION(ISteamMatchmaking,			SteamMatchmaking);
EXPORT_CURRENT_VERSION(ISteamUserStats,				SteamUserStats);
EXPORT_CURRENT_VERSION(ISteamApps,					SteamApps);
EXPORT_CURRENT_VERSION(ISteamNetworking,			SteamNetworking);
EXPORT_CURRENT_VERSION(ISteamMatchmakingServers,	SteamMatchmakingServers);
EXPORT_CURRENT_VERSION(ISteamRemoteStorage,			SteamRemoteStorage);


bool LoadInterfaces_GameServer(bool safe);

//gameserver exports
EXPORT_CURRENT_VERSION(ISteamGameServer,			SteamGameServer);
EXPORT_CURRENT_VERSION(ISteamUtils,					SteamGameServerUtils);
EXPORT_CURRENT_VERSION(ISteamMasterServerUpdater,	SteamMasterServerUpdater);
EXPORT_CURRENT_VERSION(ISteamNetworking,			SteamGameServerNetworking);
EXPORT_CURRENT_VERSION(ISteamGameServerItems,		SteamGameServerItems);

bool LoadInterfaces_ContentServer();

//contentserver exports
EXPORT_CURRENT_VERSION(ISteamContentServer,			SteamContentServer);
EXPORT_CURRENT_VERSION(ISteamUtils,					SteamContentServerUtils);