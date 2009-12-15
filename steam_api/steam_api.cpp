#include "stdafx.h"
#include "interfaces.h"
#include "callbacks.h"

CSteamAPILoader loader;
CreateInterfaceFn clientFactory = NULL;

STEAMCLIENT_ICLASS *steamclient = NULL;
STEAMUTILS_ICLASS *steamutils = NULL;

HSteamPipe pipe = 0;
HSteamUser user = 0;

HSteamPipe SteamAPI_InitInternal()
{
	clientFactory = loader.Load();

	if(clientFactory == NULL)
		return 0;

	steamclient = (STEAMCLIENT_ICLASS *)clientFactory(STEAMCLIENT_IFACE, NULL);

	if(steamclient == NULL)
		return 0;

	HSteamPipe ipipe = steamclient->CreateSteamPipe();

	if(ipipe == NULL)
		return 0;

	steamutils = (STEAMUTILS_ICLASS *)steamclient->GetISteamUtils(ipipe, STEAMUTILS_IFACE);

	if(steamutils == NULL)
		return 0;

	return ipipe;
}

bool SteamAPI_InitInternalUser(bool safe)
{
	pipe = SteamAPI_InitInternal();

	if(pipe == NULL)
		return false;

	user = steamclient->ConnectToGlobalUser(pipe);

	if(user == NULL)
		return false;

	if(!LoadInterfaces(safe))
		return false;

	Steam_RegisterInterfaceFuncs(loader.GetSteamModule());

	if(steamutils->GetAppID() == 0)
	{
		std::cerr << "[S_API] Load failure. AppID not set!" << std::endl;
		return false;
	}

	return true;
}



S_API bool STEAM_CALL SteamAPI_Init()
{
	return SteamAPI_InitInternalUser(false);
}

S_API bool STEAM_CALL SteamAPI_InitSafe()
{
	return SteamAPI_InitInternalUser(true);
}



S_API void SteamAPI_Shutdown()
{
	if(user)
	{
		steamclient->ReleaseUser(pipe, user);
		user = NULL;
	}
	if(pipe)
	{
		steamclient->ReleaseSteamPipe(pipe);
		pipe = NULL;
	}

	callbackmanager.Cleanup();
}



S_API void STEAM_CALL SteamAPI_RunCallbacks()
{
	if(pipe)
		Steam_RunCallbacks(pipe, false);
}



S_API const char* STEAM_CALL SteamAPI_GetSteamInstallPath()
{
	return loader.GetSteamDir();
}



S_API HSteamPipe STEAM_CALL SteamAPI_GetHSteamPipe()
{
	return pipe;
}

S_API HSteamUser STEAM_CALL SteamAPI_GetHSteamUser()
{
	return user;
}

S_API HSteamPipe STEAM_CALL GetHSteamPipe()
{
	return SteamAPI_GetHSteamPipe();
}

S_API HSteamUser STEAM_CALL GetHSteamUser()
{
	return SteamAPI_GetHSteamUser();
}


S_API void STEAM_CALL SteamAPI_WriteMiniDump( uint32 uStructuredExceptionCode, void* pvExceptionInfo, uint32 uBuildID )
{
	std::cerr << "TODO: SteamAPI_WriteMiniDump" << std::endl;
}

S_API void STEAM_CALL SteamAPI_SetMiniDumpComment( const char *pchMsg )
{
	std::cerr << "TODO: SteamAPI_SEtMiniDumpComment" << std::endl;
}