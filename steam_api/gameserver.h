#pragma once

#define STEAMGAMESERVER_ICLASS	ISteamGameServer009
#define STEAMGAMESERVER_IFACE	STEAMGAMESERVER_INTERFACE_VERSION_009

#define STEAMMASTERSERVERUPDATER_ICLASS ISteamMasterServerUpdater001
#define STEAMMASTERSERVERUPDATER_IFACE STEAMMASTERSERVERUPDATER_INTERFACE_VERSION_001

extern STEAMCLIENT_ICLASS *gameserver_steamclient;
extern STEAMUTILS_ICLASS *gameserver_steamutils;

extern HSteamUser gameserver_user;
extern HSteamPipe gameserver_pipe;

S_API ISteamClient *g_pSteamClientGameServer;

S_API bool STEAM_CALL SteamGameServer_InitSafe( uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usSpectatorPort, uint16 usQueryPort, EServerMode eServerMode, const char *pchGameDir, const char *pchVersionString );
S_API bool STEAM_CALL SteamGameServer_Init( uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usSpectatorPort, uint16 usQueryPort, EServerMode eServerMode, const char *pchGameDir, const char *pchVersionString );

S_API void STEAM_CALL SteamGameServer_Shutdown();
S_API void STEAM_CALL SteamGameServer_RunCallbacks();

S_API bool STEAM_CALL SteamGameServer_BSecure();
S_API uint64 STEAM_CALL SteamGameServer_GetSteamID();
S_API int32 STEAM_CALL SteamGameServer_GetIPCCallCount();

S_API HSteamPipe STEAM_CALL SteamGameServer_GetHSteamPipe();
S_API HSteamUser STEAM_CALL SteamGameServer_GetHSteamUser(); 