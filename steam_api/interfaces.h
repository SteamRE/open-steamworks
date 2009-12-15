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
	std::string IFACE##_VERSION = IFACE##_INTERFACE_VERSION_##VERSION; \
	void* IFACE##_PTR = NULL; \
	S_API ICLASS* STEAM_CALL EXPORT() { return (ICLASS *) IFACE##_PTR; }; \
	OptionDefinition IFACE##_OPTION( #EXPORT );

#define REPLACE_WITH_OPTION(IFACE, EXPORT) \
	if(vm.count(#EXPORT)) IFACE##_VERSION = vm[#EXPORT].as<std::string>();

#define TRYGET_CURRENT_VERSION(IFACE, EXPORT, VMETHOD) \
	REPLACE_WITH_OPTION(IFACE, EXPORT) \
	IFACE##_PTR = (void *)steamclient->VMETHOD(user, pipe, IFACE##_VERSION.c_str()); \
	if( IFACE##_PTR == NULL ) return false;

#define TRYGET_CURRENT_VERSION_PIPE(IFACE, EXPORT, VMETHOD) \
	REPLACE_WITH_OPTION(IFACE, EXPORT) \
	IFACE##_PTR = (void *)steamclient->VMETHOD(pipe, IFACE##_VERSION.c_str()); \
	if( IFACE##_PTR == NULL ) return false;

#define TRYGET_CURRENT_VERSION_FACTORY(IFACE, EXPORT) \
	REPLACE_WITH_OPTION(IFACE, EXPORT) \
	IFACE##_PTR = (void *)clientFactory(IFACE##_VERSION.c_str(), NULL); \
	if( IFACE##_PTR == NULL ) return false;

bool LoadInterfaces();

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