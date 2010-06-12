//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================


#ifndef STEAMCLIENT_H
#define STEAMCLIENT_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"

#ifndef STEAMWORKS_CLIENT_INTERFACES
	#ifdef MSC_VER
		#define UNSAFE_INTERFACE __declspec(deprecated("IClient interfaces are unversioned and potentially unsafe. Class defintion can change between steamclient releases. #define STEAMWORKS_CLIENT_INTERFACES to supress this warning."))
	#else
		#define UNSAFE_INTERFACE
	#endif
#else
		#define UNSAFE_INTERFACE
#endif

#include "SteamTypes.h"

// client
#include "ISteamClient006.h"
#include "ISteamClient007.h"
#include "ISteamClient008.h"
#include "ISteamClient009.h"

// friends
#include "ISteamFriends001.h"
#include "ISteamFriends002.h"
#include "ISteamFriends003.h"
#include "ISteamFriends004.h"
#include "ISteamFriends005.h"

// user
#include "ISteamUser004.h"
#include "ISteamUser005.h"
#include "ISteamUser006.h"
#include "ISteamUser007.h"
#include "ISteamUser008.h"
#include "ISteamUser009.h"
#include "ISteamUser010.h"
#include "ISteamUser011.h"
#include "ISteamUser012.h"
#include "ISteamUser013.h"

// user items
#include "ISteamUserItems001.h"
#include "ISteamUserItems002.h"
#include "ISteamUserItems003.h"
#include "ISteamUserItems004.h"

// apps
#include "ISteamApps001.h"
#include "ISteamApps002.h"
#include "ISteamApps003.h"

// user stats
#include "ISteamUserStats001.h"
#include "ISteamUserStats002.h"
#include "ISteamUserStats003.h"
#include "ISteamUserStats004.h"
#include "ISteamUserStats005.h"
#include "ISteamUserStats006.h"
#include "ISteamUserStats007.h"

// utils
#include "ISteamUtils001.h"
#include "ISteamUtils002.h"
#include "ISteamUtils003.h"
#include "ISteamUtils004.h"
#include "ISteamUtils005.h"

// game server
#include "ISteamGameServer002.h"
#include "ISteamGameServer003.h"
#include "ISteamGameServer004.h"
#include "ISteamGameServer005.h"
#include "ISteamGameServer006.h"
#include "ISteamGameServer007.h"
#include "ISteamGameServer008.h"
#include "ISteamGameServer009.h"
#include "ISteamGameServer010.h"

// master server updater
#include "ISteamMasterServerUpdater001.h"

// matchmaking
#include "ISteamMatchmaking001.h"
#include "ISteamMatchmaking002.h"
#include "ISteamMatchmaking003.h"
#include "ISteamMatchmaking004.h"
#include "ISteamMatchmaking005.h"
#include "ISteamMatchmaking006.h"
#include "ISteamMatchmaking007.h"
#include "ISteamMatchmaking008.h"

// matchmaking servers
#include "ISteamMatchmakingServers001.h"
#include "ISteamMatchmakingServers002.h"

// networking
#include "ISteamNetworking001.h"
#include "ISteamNetworking002.h"
#include "ISteamNetworking003.h"

// billing
#include "ISteamBilling001.h"
#include "ISteamBilling002.h"

// remote storage
#include "ISteamRemoteStorage001.h"
#include "ISteamRemoteStorage002.h"

// content server
#include "ISteamContentServer001.h"
#include "ISteamContentServer002.h"

// steam 2 bridge
#include "ISteam2Bridge001.h"
#include "ISteam2Bridge002.h"

// game server items
#include "ISteamGameServerItems002.h"
#include "ISteamGameServerItems003.h"
#include "ISteamGameServerItems004.h"

// game coordinator
#include "ISteamGameCoordinator001.h"

// game server stats
#include "ISteamGameServerStats001.h"

// game stats
#include "ISteamGameStats001.h"

#ifndef NO_ICLIENT
// client interfaces
#include "IClientEngine.h"

#include "IClientAppManager.h"
#include "IClientApps.h"
#include "IClientBilling.h"
#include "IClientContentServer.h"
#include "IClientDepotBuilder.h"
#include "IClientFriends.h"
#include "IClientGameCoordinator.h"
#include "IClientGameServer.h"
#include "IClientGameStats.h"
#include "IClientMatchmaking.h"
#include "IClientRemoteStorage.h"
#include "IClientUser.h"
#include "IClientUtils.h"
#include "IClientHTTP.h"
#include "IClientConfigStore.h"
#endif // NO_ICLIENT

// callback
#include "CCallback.h"


// Breakpad
S_API errno_t STEAM_CALL Breakpad_SetSteamID( uint64 ulSteamID );
S_API errno_t STEAM_CALL Breakpad_SteamSetSteamID( uint64 ulSteamID );
S_API void STEAM_CALL Breakpad_SteamMiniDumpInit( uint32 a, const char *b, const char *c );
S_API errno_t STEAM_CALL Breakpad_SteamWriteMiniDumpSetComment( const char *pchMsg );
S_API void STEAM_CALL Breakpad_SteamWriteMiniDumpUsingExceptionInfoWithBuildId( int a, int b );


// Steam user
S_API bool STEAM_CALL Steam_BConnected( HSteamUser hUser, HSteamPipe hSteamPipe );
S_API bool STEAM_CALL Steam_BLoggedOn( HSteamUser hUser, HSteamPipe hSteamPipe );
S_API void STEAM_CALL Steam_LogOn( HSteamUser hUser, HSteamPipe hSteamPipe, uint64 ulSteamID );
S_API void STEAM_CALL Steam_LogOff( HSteamUser hUser, HSteamPipe hSteamPipe );
S_API int STEAM_CALL Steam_InitiateGameConnection( HSteamUser hUser, HSteamPipe hSteamPipe, void *pBlob, int cbMaxBlob, uint64 steamID, int nGameAppID, uint32 unIPServer, uint16 usPortServer, bool bSecure );
S_API void STEAM_CALL Steam_TerminateGameConnection( HSteamUser hUser, HSteamPipe hSteamPipe, uint32 unIPServer, uint16 usPortServer );

// Steam callbacks
S_API bool STEAM_CALL Steam_BGetCallback( HSteamPipe hSteamPipe, CallbackMsg_t *pCallbackMsg );
S_API void STEAM_CALL Steam_FreeLastCallback( HSteamPipe hSteamPipe );
S_API bool STEAM_CALL Steam_GetAPICallResult( HSteamPipe hSteamPipe, SteamAPICall_t hSteamAPICall, void* pCallback, int cubCallback, int iCallbackExpected, bool* pbFailed );

// Steam client
S_API HSteamPipe STEAM_CALL Steam_CreateSteamPipe();
S_API bool STEAM_CALL Steam_BReleaseSteamPipe( HSteamPipe hSteamPipe );
S_API HSteamUser STEAM_CALL Steam_CreateLocalUser( HSteamPipe *phSteamPipe, EAccountType eAccountType );
S_API HSteamUser STEAM_CALL Steam_CreateGlobalUser( HSteamPipe *phSteamPipe );
S_API HSteamUser STEAM_CALL Steam_ConnectToGlobalUser( HSteamPipe hSteamPipe );
S_API void STEAM_CALL Steam_ReleaseUser( HSteamPipe hSteamPipe, HSteamUser hUser );
S_API void STEAM_CALL Steam_SetLocalIPBinding( uint32 unIP, uint16 usLocalPort );

// Steam game server
S_API int STEAM_CALL Steam_GSGetSteamGameConnectToken( HSteamUser hUser, HSteamPipe hSteamPipe, void *pBlob, int cbBlobMax ); // does this exist anymore?
S_API void* STEAM_CALL Steam_GetGSHandle( HSteamUser hUser, HSteamPipe hSteamPipe );
S_API bool STEAM_CALL Steam_GSSendSteam2UserConnect( void *phSteamHandle, uint32 unUserID, const void *pvRawKey, uint32 unKeyLen, uint32 unIPPublic, uint16 usPort, const void *pvCookie, uint32 cubCookie );
S_API bool STEAM_CALL Steam_GSSendUserDisconnect( void *phSteamHandle, uint64 ulSteamID, uint32 unUserID );
S_API bool STEAM_CALL Steam_GSSendUserStatusResponse( void *phSteamHandle, uint64 ulSteamID, int nSecondsConnected, int nSecondsSinceLast );
S_API bool STEAM_CALL Steam_GSUpdateStatus( void *phSteamHandle, int cPlayers, int cPlayersMax, int cBotPlayers, const char *pchServerName, const char *pchMapName );
S_API bool STEAM_CALL Steam_GSRemoveUserConnect( void *phSteamHandle, uint32 unUserID );
S_API void STEAM_CALL Steam_GSSetSpawnCount( void *phSteamHandle, uint32 ucSpawn );
S_API bool STEAM_CALL Steam_GSGetSteam2GetEncryptionKeyToSendToNewClient( void *phSteamHandle, void *pvEncryptionKey, uint32 *pcbEncryptionKey, uint32 cbMaxEncryptionKey );
S_API void STEAM_CALL Steam_GSLogOn( void *phSteamHandle );
S_API void STEAM_CALL Steam_GSLogOff( void *phSteamHandle );
S_API bool STEAM_CALL Steam_GSBLoggedOn( void *phSteamHandle );
S_API bool STEAM_CALL Steam_GSSetServerType( void *phSteamHandle, int32 nAppIdServed, uint32 unServerFlags, uint32 unGameIP, uint32 unGamePort, const char *pchGameDir, const char *pchVersion );
S_API bool STEAM_CALL Steam_GSBSecure( void *phSteamHandle);


//----------------------------------------------------------------------------------------------------------------------------------------------------------//
//	Steam API setup & teardown
//
//	These functions manage loading, initializing and shutdown of the steamclient.dll
//
//  bugbug johnc: seperate defining these to defining game server interface more cleanly
//
//----------------------------------------------------------------------------------------------------------------------------------------------------------//
S_API bool STEAM_CALL SteamAPI_Init();
S_API bool STEAM_CALL SteamAPI_InitSafe();
S_API void STEAM_CALL SteamAPI_Shutdown();

// checks if a local Steam client is running 
S_API bool SteamAPI_IsSteamRunning();

// Detects if your executable was launched through the Steam client, and restarts your game through 
// the client if necessary. The Steam client will be started if it is not running.
//
// Returns: true if your executable was NOT launched through the Steam client. This function will
//          then start your application through the client. Your current process should exit.
//
//          false if your executable was started through the Steam client or a steam_appid.txt file
//          is present in your game's directory (for development). Your current process should continue.
//
// NOTE: This function should be used only if you are using CEG or not using Steam's DRM. Once applied
//       to your executable, Steam's DRM will handle restarting through Steam if necessary.
S_API bool SteamAPI_RestartAppIfNecessary( uint32 unOwnAppID );


// crash dump recording functions
S_API void SteamAPI_WriteMiniDump( uint32 uStructuredExceptionCode, void* pvExceptionInfo, uint32 uBuildID );
S_API void SteamAPI_SetMiniDumpComment( const char *pchMsg );

// this should be called before the game initialized the steam APIs
// pchDate should be of the format "Mmm dd yyyy" (such as from the __DATE__ macro )
// pchTime should be of the format "hh:mm:ss" (such as from the __TIME__ macro )
S_API void SteamAPI_UseBreakpadCrashHandler( char const *pchVersion, char const *pchDate, char const *pchTime );


#ifndef VERSIONED_STEAMAPI_INTERFACES
S_API ISteamClient* STEAM_CALL SteamClient();
S_API ISteamUser* STEAM_CALL SteamUser();
S_API ISteamFriends* STEAM_CALL SteamFriends();
S_API ISteamUtils* STEAM_CALL SteamUtils();
S_API ISteamMatchmaking* STEAM_CALL SteamMatchmaking();
S_API ISteamUserStats* STEAM_CALL SteamUserStats();
S_API ISteamApps* STEAM_CALL SteamApps();
S_API ISteamMatchmakingServers* STEAM_CALL SteamMatchmakingServers();
#else
S_API ISteamClient009* STEAM_CALL SteamClient();
S_API ISteamUser013* STEAM_CALL SteamUser();
S_API ISteamFriends005* STEAM_CALL SteamFriends();
S_API ISteamUtils005* STEAM_CALL SteamUtils();
S_API ISteamMatchmaking008* STEAM_CALL SteamMatchmaking();
S_API ISteamUserStats007* STEAM_CALL SteamUserStats();
S_API ISteamApps003* STEAM_CALL SteamApps();
S_API ISteamMatchmakingServers002* STEAM_CALL SteamMatchmakingServers();
#endif

// sets whether or not Steam_RunCallbacks() should do a try {} catch (...) {} around calls to issuing callbacks
S_API void SteamAPI_SetTryCatchCallbacks( bool bTryCatchCallbacks );

S_API void STEAM_CALL SteamAPI_RunCallbacks();

// functions used by the utility CCallback objects to receive callbacks
S_API void STEAM_CALL SteamAPI_RegisterCallback( class CCallbackBase *pCallback, int iCallback );
S_API void STEAM_CALL SteamAPI_UnregisterCallback( class CCallbackBase *pCallback );
// functions used by the utility CCallResult objects to receive async call results
S_API void STEAM_CALL SteamAPI_RegisterCallResult( class CCallbackBase *pCallback, SteamAPICall_t hAPICall );
S_API void STEAM_CALL SteamAPI_UnregisterCallResult( class CCallbackBase *pCallback, SteamAPICall_t hAPICall );
//----------------------------------------------------------------------------------------------------------------------------------------------------------//
//	steamclient.dll private wrapper functions
//
//	The following functions are part of abstracting API access to the steamclient.dll, but should only be used in very specific cases
//----------------------------------------------------------------------------------------------------------------------------------------------------------//
S_API void STEAM_CALL Steam_RunCallbacks( HSteamPipe hSteamPipe, bool bGameServerCallbacks );
S_API void STEAM_CALL Steam_RegisterInterfaceFuncs( void *hModule );

S_API HSteamUser STEAM_CALL Steam_GetHSteamUserCurrent();

S_API const char* STEAM_CALL SteamAPI_GetSteamInstallPath();

// used in version safe api
S_API HSteamPipe STEAM_CALL GetHSteamPipe();
S_API HSteamUser STEAM_CALL GetHSteamUser();

S_API HSteamPipe STEAM_CALL SteamAPI_GetHSteamPipe();
S_API HSteamUser STEAM_CALL SteamAPI_GetHSteamUser();

S_API bool STEAM_CALL SteamGameServer_InitSafe( uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usSpectatorPort, uint16 usQueryPort, EServerMode eServerMode, const char *pchGameDir, const char *pchVersionString );
S_API bool STEAM_CALL SteamGameServer_Init( uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usSpectatorPort, uint16 usQueryPort, EServerMode eServerMode, const char *pchGameDir, const char *pchVersionString );

S_API void STEAM_CALL SteamGameServer_Shutdown();
S_API void STEAM_CALL SteamGameServer_RunCallbacks();

S_API bool STEAM_CALL SteamGameServer_BSecure();
S_API uint64 STEAM_CALL SteamGameServer_GetSteamID();

S_API HSteamPipe STEAM_CALL SteamGameServer_GetHSteamPipe();
S_API HSteamUser STEAM_CALL SteamGameServer_GetHSteamUser(); 
S_API int32 STEAM_CALL SteamGameServer_GetIPCCallCount();

S_API ISteamGameServer* STEAM_CALL SteamGameServer();
S_API ISteamUtils* STEAM_CALL SteamGameServerUtils();
S_API ISteamMasterServerUpdater* STEAM_CALL SteamMasterServerUpdater();
S_API ISteamNetworking* STEAM_CALL SteamGameServerNetworking();

//content server
S_API ISteamContentServer* STEAM_CALL SteamContentServer();
S_API ISteamUtils* STEAM_CALL SteamContentServerUtils();
S_API bool STEAM_CALL SteamContentServer_Init(uint32 unIP, uint16 usPort);

S_API void STEAM_CALL SteamContentServer_Shutdown();
S_API void STEAM_CALL SteamContentServer_RunCallbacks();

#endif // STEAMCLIENT_H
