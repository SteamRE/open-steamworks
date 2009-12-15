#pragma once

#define STEAMCLIENT_ICLASS	ISteamClient008
#define STEAMCLIENT_IFACE	STEAMCLIENT_INTERFACE_VERSION_008

#define STEAMUTILS_ICLASS	ISteamUtils004
#define STEAMUTILS_IFACE	STEAMUTILS_INTERFACE_VERSION_004

extern CSteamAPILoader loader;
extern CreateInterfaceFn clientFactory;

extern STEAMCLIENT_ICLASS *steamclient;
extern STEAMUTILS_ICLASS *steamutils;

extern HSteamUser user;
extern HSteamPipe pipe;

HSteamPipe SteamAPI_InitInternal();

S_API bool STEAM_CALL SteamAPI_Init();
S_API bool STEAM_CALL SteamAPI_InitSafe();

S_API void STEAM_CALL SteamAPI_Shutdown();

S_API const char* STEAM_CALL SteamAPI_GetSteamInstallPath();

S_API HSteamPipe STEAM_CALL SteamAPI_GetHSteamPipe();
S_API HSteamPipe STEAM_CALL GetHSteamPipe();

S_API HSteamUser STEAM_CALL SteamAPI_GetHSteamUser();
S_API HSteamUser STEAM_CALL GetHSteamUser();

S_API void STEAM_CALL SteamAPI_RunCallbacks();

S_API void STEAM_CALL SteamAPI_WriteMiniDump( uint32 uStructuredExceptionCode, void* pvExceptionInfo, uint32 uBuildID );
S_API void STEAM_CALL SteamAPI_SetMiniDumpComment( const char *pchMsg );