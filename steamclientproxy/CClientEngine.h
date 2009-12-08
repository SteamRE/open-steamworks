#pragma once

void Log(char *msg, ...);


#include "CClientUser.h"


DEFINE_PROXY_CLASS(CClientEngine, IClientEngine)

	// Creates a communication pipe to the Steam client
	CLASS_PROXY(HSteamUser, CreateSteamPipe, (), ())

	// Releases a previously created communications pipe
	DECL_CLASS_PROXY(bool, ReleaseSteamPipe, ( HSteamPipe hSteamPipe ))
		::Log("[%s]\tCClientEngine::ReleaseSteamPipe( hSteamPipe = %d )\n", callerModule.szModule, hSteamPipe);
	RETURN_CLASS_PROXY(ReleaseSteamPipe, (hSteamPipe))

	// creates a global instance of a steam user, so that other processes can share it
	// used by the steam UI, to share it's account info/connection with any games it launches
	// fails (returns NULL) if an existing instance already exists
	CLASS_PROXY(HSteamUser, CreateGlobalUser, ( HSteamPipe *phSteamPipe ), (phSteamPipe))

	// connects to an existing global user, failing if none exists
	// used by the game to coordinate with the steamUI
	CLASS_PROXY(HSteamUser, ConnectToGlobalUser, ( HSteamPipe hSteamPipe ), (hSteamPipe))

	// used by game servers, create a steam user that won't be shared with anyone else
	CLASS_PROXY(HSteamUser, CreateLocalUser, ( HSteamPipe *phSteamPipe, EAccountType eAccountType ), (phSteamPipe, eAccountType))

	// removes an allocated user
	CLASS_PROXY(void, ReleaseUser, ( HSteamPipe hSteamPipe, HSteamUser hUser ), (hSteamPipe, hUser))

	// retrieves the IClientUser interface associated with the handle
	DECL_CLASS_PROXY(IClientUser*, GetIClientUser,( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ))
		::Log("[%s]\tCClientEngine::GetIClientUser( hSteamUser = %d, hSteamPipe = %d, pchVersion = \"%s\" )\n", callerModule.szModule, hSteamUser, hSteamPipe, pchVersion);
		static CClientUser *myClientUser;

		if (strcmp(pchVersion, CLIENTUSER_INTERFACE_VERSION) == 0)
		{
			if (!myClientUser)
			{
				IClientUser *origUser = base->GetIClientUser(hSteamUser, hSteamPipe, pchVersion);
				myClientUser = new CClientUser(origUser);
			}

			return (IClientUser*)myClientUser;
		}

	RETURN_CLASS_PROXY(GetIClientUser, (hSteamUser, hSteamPipe, pchVersion))

	// retrieves the IClientGameServer interface associated with the handle
	GET_IFACE_CLASS_PROXY(IClientGameServer*, GetIClientGameServer, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// set the local IP and Port to bind to
	// this must be set before CreateLocalUser()
	CLASS_PROXY(void, SetLocalIPBinding,( unsigned int unIP, unsigned short usPort ), (unIP, usPort))

	// returns the name of a universe
	CLASS_PROXY(const char*, GetUniverseName, ( EUniverse eUniverse ), (eUniverse))

	// returns the IClientFriends interface
	GET_IFACE_CLASS_PROXY(IClientFriends*, GetIClientFriends, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// returns the IClientUtils interface
	DECL_CLASS_PROXY(IClientUtils*, GetIClientUtils, ( HSteamPipe hSteamPipe, const char *pchVersion ))
		::Log("[%s]\tCClientEngine::GetIClientUtils( hSteamPipe = %d, pchVersion = \"%s\" )\n", callerModule.szModule, hSteamPipe, pchVersion);
	RETURN_CLASS_PROXY(GetIClientUtils, (hSteamPipe, pchVersion))

	// returns the IClientBilling interface
	GET_IFACE_CLASS_PROXY(IClientBilling*, GetIClientBilling, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// returns the IClientMatchmaking interface
	GET_IFACE_CLASS_PROXY(IClientMatchmaking*, GetIClientMatchmaking, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// returns the IClientApps interface
	GET_IFACE_CLASS_PROXY(IClientApps*, GetIClientApps, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// returns the IClientContentServer interface
	GET_IFACE_CLASS_PROXY(IClientContentServer*, GetIClientContentServer, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// returns the IClientMasterServerUpdater interface
	GET_IFACE_CLASS_PROXY(IClientMasterServerUpdater*, GetIClientMasterServerUpdater, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// returns the IClientMatchmakingServers interface
	GET_IFACE_CLASS_PROXY(IClientMatchmakingServers*, GetIClientMatchmakingServers, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// returns the IP2PController interface
	GET_IFACE_CLASS_PROXY(IP2PController*, GetIP2PController, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	CLASS_PROXY(void, RunFrame, (), ())

	CLASS_PROXY(uint32, GetIPCCallCount, (), ())

	// returns the IClientUserStats interface
	GET_IFACE_CLASS_PROXY(IClientUserStats*, GetIClientUserStats, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// returns the IClientUserStats interface
	GET_IFACE_CLASS_PROXY(IClientNetworking*, GetIClientNetworking, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// returns the IClientRemoteStorage interface
	GET_IFACE_CLASS_PROXY(IClientRemoteStorage*, GetIClientRemoteStorage, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	CLASS_PROXY(void, SetWarningMessageHook, (SteamAPIWarningMessageHook_t warningHook), (warningHook))

	// returns the IClientUserItems interface
	GET_IFACE_CLASS_PROXY(IClientUserItems*, GetIClientUserItems, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	// returns the IClientGameServerItems interface
	GET_IFACE_CLASS_PROXY(IClientGameServerItems*, GetIClientGameServerItems, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	//virtual unknown_ret SetOverlayNotificationPosition( ENotificationPosition ) = 0;
	CLASS_PROXY(void, SetOverlayNotificationPosition, ( ENotificationPosition a), (a))

    CLASS_PROXY(bool, IsOverlayEnabled, (), ())

	CLASS_PROXY(unknown_ret, GetAPICallResult, ( int a, uint64 b, void *c, int d, int e, bool *f ), (a, b, c, d, e, f))
	
    GET_IFACE_CLASS_PROXY(IClientAppManager *, GetIClientAppManager, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))
    

	GET_IFACE_CLASS_PROXY(IClientDepotBuilder *, GetIClientDepotBuilder, ( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion ), (hSteamUser, hSteamPipe, pchVersion))

	//CLASS_PROXY(void, ConCommandInit, ( IConCommandBaseAccessor *pAccessor ), ( pAccessor ))
	DECL_CLASS_PROXY(void, ConCommandInit, (IConCommandBaseAccessor *pAccessor))
		Sleep(2000);
		::Log("[%s]\tCClientEngine::ConCommandInit\n", callerModule.szModule);
		base->ConCommandInit( pAccessor );
	}


};
