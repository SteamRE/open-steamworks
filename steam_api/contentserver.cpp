#include "stdafx.h"
#include "interfaces.h"
#include "contentserver.h"

STEAMCLIENT_ICLASS *contentserver_steamclient = NULL;
STEAMUTILS_ICLASS *contentserver_steamutils = NULL;

HSteamUser contentserver_user = 0;
HSteamPipe contentserver_pipe = 0;

STEAMCONTENTSERVER_ICLASS *contentserver = NULL;

S_API bool STEAM_CALL SteamContentServer_Init(uint32 unIP, uint16 usPort)
{
	contentserver_pipe = SteamAPI_InitInternal(&contentserver_steamclient, &contentserver_steamutils);

	if(!contentserver_pipe)
		return false;

	contentserver_steamclient->SetLocalIPBinding(unIP, usPort);
	contentserver_user = contentserver_steamclient->CreateLocalUser(&contentserver_pipe, k_EAccountTypeContentServer);

	if(!contentserver_user)
		return false;

	contentserver = (STEAMCONTENTSERVER_ICLASS *)contentserver_steamclient->GetISteamGenericInterface(contentserver_user, contentserver_pipe, STEAMCONTENTSERVER_IFACE);

	if(!contentserver)
		return false;

	if(!LoadInterfaces_ContentServer())
		return false;

	if(!contentserver->LogOn(0))
		return false;

	Steam_RegisterInterfaceFuncs(loader.GetSteamModule());

	return true;
}

S_API void STEAM_CALL SteamContentServer_Shutdown()
{
	if(contentserver)
	{
		contentserver->LogOff();
	}

	if(contentserver_user)
	{
		contentserver_steamclient->ReleaseUser(contentserver_pipe, contentserver_user);
		contentserver_user = NULL;
	}
	if(contentserver_pipe)
	{
		contentserver_steamclient->ReleaseSteamPipe(contentserver_pipe);
		contentserver_pipe = NULL;
	}
}

S_API void STEAM_CALL SteamContentServer_RunCallbacks()
{
	Steam_RunCallbacks(contentserver_pipe, true);
}