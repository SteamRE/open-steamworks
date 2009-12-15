#include "stdafx.h"
#include "interfaces.h"
#include "gameserver.h"

STEAMCLIENT_ICLASS *gameserver_steamclient = NULL;
STEAMUTILS_ICLASS *gameserver_steamutils = NULL;

HSteamUser gameserver_user = 0;
HSteamPipe gameserver_pipe = 0;

STEAMGAMESERVER_ICLASS *gameserver = NULL;

bool SteamGameServer_InitInternal(bool safe, uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usSpectatorPort, uint16 usQueryPort, EServerMode eServerMode, const char *pchGameDir, const char *pchVersionString )
{
	gameserver_pipe = SteamAPI_InitInternal(&gameserver_steamclient, &gameserver_steamutils);

	if(!gameserver_pipe)
		return false;

	gameserver_steamclient->SetLocalIPBinding(unIP, usPort);
	gameserver_user = gameserver_steamclient->CreateLocalUser(&gameserver_pipe, k_EAccountTypeGameServer);

	if(!gameserver_user)
		return false;

	gameserver = (STEAMGAMESERVER_ICLASS *)gameserver_steamclient->GetISteamGameServer(gameserver_user, gameserver_pipe, STEAMGAMESERVER_IFACE);

	if(!gameserver)
		return false;

	if(!LoadInterfaces_GameServer(safe))
		return false;

	int flags = k_unServerFlagDedicated | k_unServerFlagActive;
	bool lan = false;

	switch(eServerMode)
	{
	case eServerModeNoAuthentication:
		{
			lan = true;
			flags = flags | k_unServerFlagPrivate;
		}
		break;
	case eServerModeAuthenticationAndSecure:
		{
			flags = flags | k_unServerFlagSecure;
		}
		break;
	}

	if(!gameserver->SetServerType( flags, unIP, usGamePort, usSpectatorPort, usQueryPort, pchGameDir, pchVersionString, lan))
		return false;

	gameserver->LogOn();

	Steam_RegisterInterfaceFuncs(loader.GetSteamModule());

	return true;
}

S_API bool STEAM_CALL SteamGameServer_Init(uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usSpectatorPort, uint16 usQueryPort, EServerMode eServerMode, const char *pchGameDir, const char *pchVersionString )
{
	return SteamGameServer_InitInternal(false, unIP, usPort, usGamePort, usSpectatorPort, usQueryPort, eServerMode, pchGameDir, pchVersionString);
}


S_API bool STEAM_CALL SteamGameServer_InitSafe(uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usSpectatorPort, uint16 usQueryPort, EServerMode eServerMode, const char *pchGameDir, const char *pchVersionString )
{
	return SteamGameServer_InitInternal(true, unIP, usPort, usGamePort, usSpectatorPort, usQueryPort, eServerMode, pchGameDir, pchVersionString);
}

S_API void STEAM_CALL SteamGameServer_Shutdown()
{
	if(gameserver)
	{
		gameserver->LogOff();
	}

	if(gameserver_user)
	{
		gameserver_steamclient->ReleaseUser(gameserver_pipe, gameserver_user);
		gameserver_user = NULL;
	}
	if(gameserver_pipe)
	{
		gameserver_steamclient->ReleaseSteamPipe(gameserver_pipe);
		gameserver_pipe = NULL;
	}
}

S_API void STEAM_CALL SteamGameServer_RunCallbacks()
{
	Steam_RunCallbacks(gameserver_pipe, true);
}

S_API bool STEAM_CALL SteamGameServer_BSecure()
{
	return gameserver->Secure();
}

S_API uint64 STEAM_CALL SteamGameServer_GetSteamID()
{
	return gameserver->GetSteamID().ConvertToUint64();
}