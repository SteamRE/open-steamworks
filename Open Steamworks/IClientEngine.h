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

#ifndef ICLIENTENGINE_H
#define ICLIENTENGINE_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"

class IClientApps;
class IClientBilling;
class IClientContentServer;
class IClientFriends;
class IClientGameCoordinator;
class IClientGameServer;
class IClientGameServerItems;
class IClientGameStats;
class IClientMasterServerUpdater;
class IClientMatchmaking;
class IClientMatchmakingServers;
class IClientNetworking;
class IClientRemoteStorage;
class IClientUser;
class IClientUserItems;
class IClientUserStats;
class IClientUtils;
class IP2PController;
class IClientAppManager;
class IClientDepotBuilder;
class IConCommandBaseAccessor;
class IClientGameCoordinator;
class IClientHTTP;

#define CLIENTENGINE_INTERFACE_VERSION "CLIENTENGINE_INTERFACE_VERSION001"

class UNSAFE_INTERFACE IClientEngine
{

public:
	virtual HSteamPipe CreateSteamPipe() = 0; 
	virtual bool ReleaseSteamPipe( HSteamPipe hSteamPipe ) = 0;

	virtual HSteamUser CreateGlobalUser( HSteamPipe* phSteamPipe ) = 0;
	virtual HSteamUser ConnectToGlobalUser( HSteamPipe hSteamPipe ) = 0;

	virtual HSteamUser CreateLocalUser( HSteamPipe* phSteamPipe, EAccountType eAccountType ) = 0;

	virtual void ReleaseUser( HSteamPipe hSteamPipe, HSteamUser hUser ) = 0;
/*
#if defined( _WIN32 ) && defined( STEAM )
	virtual unknown_ret Unknown( int a, int b ) = 0; // exists in steam's steamclient, but not l4d2's or l4d1's steamclient
#endif*/

	// this seems to be the actual func... unless this is added and the unknown function still exists in steam
	virtual bool IsValidHSteamUserPipe( HSteamPipe hSteamPipe, HSteamUser hUser ) = 0;

	virtual IClientUser* GetIClientUser( HSteamUser hSteamUser, HSteamPipe hSteamPipe, char const* pchVersion ) = 0;
	virtual IClientGameServer *GetIClientGameServer( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) = 0;

	virtual void SetLocalIPBinding( uint32 unIP, uint16 usPort ) = 0;
	virtual char const* GetUniverseName( EUniverse eUniverse ) = 0;

	virtual IClientFriends* GetIClientFriends( HSteamUser hSteamUser, HSteamPipe hSteamPipe, char const* pchVersion ) = 0;
	virtual IClientUtils* GetIClientUtils( HSteamPipe hSteamPipe, char const* pchVersion ) = 0;
	virtual IClientBilling* GetIClientBilling( HSteamUser hSteamUser, HSteamPipe hSteamPipe, char const* pchVersion ) = 0;
	virtual IClientMatchmaking* GetIClientMatchmaking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, char const* pchVersion ) = 0;
	virtual IClientApps* GetIClientApps( HSteamUser hSteamUser, HSteamPipe hSteamPipe, char const* pchVersion ) = 0;
	virtual IClientContentServer* GetIClientContentServer( HSteamUser hSteamUser, HSteamPipe hSteamPipe, char const* pchVersion ) = 0;
	virtual IClientMasterServerUpdater* GetIClientMasterServerUpdater( HSteamUser hSteamUser, HSteamPipe hSteamPipe, char const* pchVersion ) = 0;
	virtual IClientMatchmakingServers* GetIClientMatchmakingServers( HSteamUser hSteamUser, HSteamPipe hSteamPipe, char const* pchVersion ) = 0;
	virtual IP2PController* GetIP2PController( HSteamUser hSteamUser, HSteamPipe hSteamPipe, char const* pchVersion ) = 0;

	virtual void RunFrame() = 0;
	virtual uint32 GetIPCCallCount() = 0;

	virtual IClientUserStats* GetIClientUserStats( HSteamUser hSteamUser, HSteamPipe hSteamPipe, char const* pchVersion ) = 0;
	virtual IClientNetworking* GetIClientNetworking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, char const* pchVersion ) = 0;
	virtual IClientRemoteStorage* GetIClientRemoteStorage( HSteamUser hSteamUser, HSteamPipe hSteamPipe, char const* pchVersion ) = 0;

	virtual void SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction ) = 0;

	virtual IClientUserItems* GetIClientUserItems( HSteamUser hSteamUser, HSteamPipe hSteamPipe, char const* pchVersion ) = 0;
	virtual IClientGameServerItems* GetIClientGameServerItems( HSteamUser hSteamUser, HSteamPipe hSteamPipe, char const* pchVersion ) = 0;
	virtual IClientGameCoordinator* GetIClientGameCoordinator( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ) = 0;

	virtual void SetOverlayNotificationPosition( ENotificationPosition eNotificationPosition ) = 0;

	virtual bool IsOverlayEnabled() = 0;
	virtual bool GetAPICallResult( HSteamPipe hSteamPipe, SteamAPICall_t hSteamAPICall, void* pCallback, int cubCallback, int iCallbackExpected, bool* pbFailed ) = 0;

	virtual IClientDepotBuilder* GetIClientDepotBuilder( HSteamUser hSteamUser, HSteamPipe hSteamPipe, char const* pchVersion ) = 0;

	virtual void ConCommandInit( IConCommandBaseAccessor * ) = 0;

	virtual IClientAppManager* GetIClientAppManager( HSteamUser hSteamUser, HSteamPipe hSteamPipe, char const* pchVersion ) = 0;
	
//#if defined( _WIN32 ) && defined( STEAM )
	virtual bool OverlayNeedsPresent() = 0; // only in steam, since latest update, it seems this is available in the linux bins too...
//#endif

	virtual IClientGameStats* GetIClientGameStats( HSteamUser hSteamUser, HSteamPipe hSteamPipe, char const* pchVersion ) = 0;

	virtual unknown_ret GetIPCServerMap() = 0;

#if !defined( STEAM )
	virtual unknown_ret OnDebugTextArrived( const char *text ) = 0; // linux only
#endif

	virtual IClientHTTP* GetIClientHTTP(HSteamUser hSteamUser, HSteamPipe hSteamPipe, char const* pchVersion) = 0;
};

#endif // ICLIENTENGINE_H
