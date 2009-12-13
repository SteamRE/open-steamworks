#include "stdafx.h"
#include "interfaces.h"

CSteamAPILoader *loader = NULL;
CreateInterfaceFn clientFactory = NULL;

STEAMCLIENT_ICLASS *steamclient = NULL;
STEAMUTILS_ICLASS *steamutils = NULL;

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
	if(loader != NULL)
		delete loader;

	loader = new CSteamAPILoader();
	clientFactory = loader->Load();

	if(clientFactory == NULL)
		return false;

	steamclient = (STEAMCLIENT_ICLASS *)clientFactory(STEAMCLIENT_IFACE, NULL);
	steamutils = (STEAMUTILS_ICLASS *)clientFactory(STEAMUTILS_IFACE, NULL);

	if(steamclient == NULL || steamutils == NULL)
		return false;

	pipe = steamclient->CreateSteamPipe();

	if(pipe == NULL)
		return false;

	user = steamclient->ConnectToGlobalUser(pipe);

	if(user == NULL)
		return false;

	return true;
}

S_API void SteamAPI_Shutdown()
{
	if(loader == NULL)
		return;

	delete loader;
}
