#include "stdafx.h"
#include "interfaces.h"
#include "gameserver.h"

STEAMCLIENT_ICLASS *gameserver_steamclient = NULL;
STEAMUTILS_ICLASS *gameserver_steamutils = NULL;

HSteamUser gameserver_user = 0;
HSteamPipe gameserver_pipe = 0;

STEAMGAMESERVER_ICLASS *gameserver = NULL;
STEAMMASTERSERVERUPDATER_ICLASS *masterserver = NULL;

ISteamClient *g_pSteamClientGameServer = NULL;

bool SteamGameServer_InitInternal(bool safe, uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usSpectatorPort, uint16 usQueryPort, EServerMode eServerMode, const char *pchGameDir, const char *pchVersionString )
{
	if(!SteamAPI_InitInternal(&gameserver_steamclient))
		return false;

	g_pSteamClientGameServer = (ISteamClient *)gameserver_steamclient; // todo: make this "safe"

	gameserver_steamclient->SetLocalIPBinding(unIP, usPort);
	gameserver_user = gameserver_steamclient->CreateLocalUser(&gameserver_pipe, k_EAccountTypeGameServer);

	if(!gameserver_user)
		return false;

	gameserver_steamutils = (STEAMUTILS_ICLASS *)gameserver_steamclient->GetISteamUtils(gameserver_pipe, STEAMUTILS_IFACE);
	gameserver = (STEAMGAMESERVER_ICLASS *)gameserver_steamclient->GetISteamGameServer(gameserver_user, gameserver_pipe, STEAMGAMESERVER_IFACE);
	masterserver = (STEAMMASTERSERVERUPDATER_ICLASS *)gameserver_steamclient->GetISteamMasterServerUpdater(gameserver_user, gameserver_pipe, STEAMMASTERSERVERUPDATER_IFACE);

	if(!gameserver_steamutils || !gameserver || !masterserver)
		return false;

	if(!LoadInterfaces_GameServer(safe))
		return false;

	gameserver->LogOn();

	int flags = 0;

	if(eServerMode == eServerModeAuthenticationAndSecure)
		flags = k_unServerFlagSecure;
	else if(eServerMode == eServerModeNoAuthentication)
		flags = k_unServerFlagPrivate;

	if(!gameserver->SetServerType( flags, unIP, usGamePort, usSpectatorPort, usQueryPort, pchGameDir, pchVersionString, eServerMode == eServerModeNoAuthentication) )
		return false;

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

S_API int32 STEAM_CALL SteamGameServer_GetIPCCallCount()
{
	return gameserver_steamclient->GetIPCCallCount();
}

S_API HSteamPipe STEAM_CALL SteamGameServer_GetHSteamPipe()
{
	return gameserver_pipe;
}

S_API HSteamUser STEAM_CALL SteamGameServer_GetHSteamUser()
{
	return gameserver_user;
}