#include "stdafx.h"
#include "interfaces.h"
#include "callbacks.h"

CSteamAPILoader loader;
CreateInterfaceFn clientFactory = NULL;

STEAMCLIENT_ICLASS *steamclient = NULL;

HSteamPipe pipe = 0;
HSteamUser user = 0;

S_API bool STEAM_CALL SteamAPI_Init()
{
	if(!SteamAPI_InitSafe())
		return false;

	if(!LoadInterfaces())
		return false;

	return true;
}

S_API bool STEAM_CALL SteamAPI_InitSafe()
{
	clientFactory = loader.Load();

	if(clientFactory == NULL)
		return false;

	steamclient = (STEAMCLIENT_ICLASS *)clientFactory(STEAMCLIENT_IFACE, NULL);

	if(steamclient == NULL)
		return false;

	pipe = steamclient->CreateSteamPipe();

	if(pipe == NULL)
		return false;

	user = steamclient->ConnectToGlobalUser(pipe);

	if(user == NULL)
		return false;

	Steam_RegisterInterfaceFuncs(loader.GetSteamModule());

	return true;
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