#define STEAMWORKS_CLIENT_INTERFACES
#define STEAM
#include "steamclientapi.h"

#include <iostream>

int main()
{
	IClientEngine *steamClient = NULL;
	Sys_LoadInterface("steamclient", CLIENTENGINE_INTERFACE_VERSION, NULL, (void**)&steamClient);

	if (!steamClient)
	{
		std::cout << "Error: Unable to load steamclient.dll!" << std::endl;
		return 1;
	}

	HSteamPipe pipe = steamClient->CreateSteamPipe();
	steamClient->ConnectToGlobalUser(pipe);

	IClientUtils *clientUtils = steamClient->GetIClientUtils(pipe, CLIENTUTILS_INTERFACE_VERSION);
	clientUtils->SetAppIDForCurrentPipe(8980);

	for ( ; ; Sleep(2000) ) ;
		clientUtils->SetAppIDForCurrentPipe(8980);

	return 0;
}