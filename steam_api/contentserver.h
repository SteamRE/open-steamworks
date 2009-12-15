#pragma once

#define STEAMCONTENTSERVER_ICLASS	ISteamContentServer002
#define STEAMCONTENTSERVER_IFACE	STEAMCONTENTSERVER_INTERFACE_VERSION_002

extern STEAMCLIENT_ICLASS *contentserver_steamclient;
extern STEAMUTILS_ICLASS *contentserver_steamutils;

extern HSteamUser contentserver_user;
extern HSteamPipe contentserver_pipe;

S_API bool STEAM_CALL SteamContentServer_Init(uint32 unIP, uint16 usPort);

S_API void STEAM_CALL SteamContentServer_Shutdown();
S_API void STEAM_CALL SteamContentServer_RunCallbacks();