#pragma once


#include "CSteam2Bridge002.h"

//-----------------------------------------------------------------------------
// Purpose: Interface to creating a new steam instance, or to
//			connect to an existing steam instance, whether it's in a
//			different process or is local
//-----------------------------------------------------------------------------
DEFINE_PROXY_CLASS(CSteamClient008, ISteamClient008)

	// Creates a communication pipe to the Steam client
	CLASS_PROXY(HSteamPipe, CreateSteamPipe, (), ())

	// Releases a previously created communications pipe
	CLASS_PROXY(bool, ReleaseSteamPipe, ( HSteamPipe hSteamPipe ), (hSteamPipe))

	// connects to an existing global user, failing if none exists
	// used by the game to coordinate with the steamUI
	DECL_CLASS_PROXY(HSteamUser, ConnectToGlobalUser, ( HSteamPipe hSteamPipe ))
		::Log("[%s]\tCSteamClient008::ConnectToGlobalUser( hSteamPipe = %d )\n", callerModule.szModule, hSteamPipe);
	RETURN_CLASS_PROXY(ConnectToGlobalUser, (hSteamPipe))

	// used by game servers, create a steam user that won't be shared with anyone else
	CLASS_PROXY(HSteamUser, CreateLocalUser, ( HSteamPipe *phSteamPipe, EAccountType eAccountType ), (phSteamPipe, eAccountType))

	// removes an allocated user
	CLASS_PROXY(void, ReleaseUser, ( HSteamPipe hSteamPipe, HSteamUser hUser ), (hSteamPipe, hUser));

	// retrieves the ISteamUser interface associated with the handle
	GET_IFACE_CLASS_PROXY(ISteamUser *, GetISteamUser, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// retrieves the ISteamGameServer interface associated with the handle
	GET_IFACE_CLASS_PROXY(ISteamGameServer *, GetISteamGameServer, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// set the local IP and Port to bind to
	// this must be set before CreateLocalUser()
	CLASS_PROXY(void, SetLocalIPBinding, ( uint32 unIP, uint16 usPort ), (unIP, usPort)) 

	// returns the ISteamFriends interface
	GET_IFACE_CLASS_PROXY(ISteamFriends *, GetISteamFriends, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// returns the ISteamUtils interface
	CLASS_PROXY(ISteamUtils *, GetISteamUtils,( HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamPipe, pchVersion))

	// returns the ISteamMatchmaking interface
	GET_IFACE_CLASS_PROXY(ISteamMatchmaking *, GetISteamMatchmaking, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// returns the ISteamMasterServerUpdater interface
	GET_IFACE_CLASS_PROXY(ISteamMasterServerUpdater *, GetISteamMasterServerUpdater, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// returns the ISteamMatchmakingServers interface
	GET_IFACE_CLASS_PROXY(ISteamMatchmakingServers *, GetISteamMatchmakingServers, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// returns the a generic interface
	DECL_CLASS_PROXY(void *, GetISteamGenericInterface, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ))
	::Log("[%s]\tCSteamClient008::GetISteamGenericInterface( hSteamUser = %d, hSteamPipe = %d, pchVersion = \"%s\" )\n", callerModule.szModule, hSteamUser, hSteamPipe, pchVersion);

	static CSteam2Bridge002 *mySteam2Bridge;
	
	if (strcmp(pchVersion, STEAM2BRIDGE_INTERFACE_VERSION_002) == 0)
	{
		if (!mySteam2Bridge)
		{
			mySteam2Bridge = new CSteam2Bridge002( base->GetISteamGenericInterface(hSteamUser, hSteamPipe, pchVersion));
		}

		return (ISteam2Bridge*)mySteam2Bridge;
	}

	RETURN_CLASS_PROXY(GetISteamGenericInterface, (hSteamUser, hSteamPipe, pchVersion))

	// returns the ISteamUserStats interface
	GET_IFACE_CLASS_PROXY(ISteamUserStats *, GetISteamUserStats, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// returns apps interface
	GET_IFACE_CLASS_PROXY(ISteamApps *, GetISteamApps, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// networking
	GET_IFACE_CLASS_PROXY(ISteamNetworking *, GetISteamNetworking, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// remote storage
	GET_IFACE_CLASS_PROXY(ISteamRemoteStorage *, GetISteamRemoteStorage, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// this needs to be called every frame to process matchmaking results
	// redundant if you're already calling SteamAPI_RunCallbacks()
	CLASS_PROXY(void, RunFrame, (), ())

	// returns the number of IPC calls made since the last time this function was called
	// Used for perf debugging so you can understand how many IPC calls your game makes per frame
	// Every IPC call is at minimum a thread context switch if not a process one so you want to rate
	// control how often you do them.
	CLASS_PROXY(uint32, GetIPCCallCount, (), ())

	// API warning handling
	// 'int' is the severity; 0 for msg, 1 for warning
	// 'const char *' is the text of the message
	// callbacks will occur directly after the API function is called that generated the warning or message
	CLASS_PROXY(void, SetWarningMessageHook, ( SteamAPIWarningMessageHook_t pFunction ), (pFunction))

};
