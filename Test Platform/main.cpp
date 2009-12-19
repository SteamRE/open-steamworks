
#include <windows.h>

#include <string>
#include <cstdio>
#include <iostream>
#include <iomanip>

#include "Steamworks.h"

int main()
{

	SetEnvironmentVariable( "SteamAppId", "440" );

	CSteamAPILoader loader;

	CreateInterfaceFn factory = loader.Load();
	if ( !factory )
	{
		std::cout << "unable to load steamclient.\n";
		getchar();
		return 0;
	}

	ISteamClient008 *steamClient = (ISteamClient008 *)factory( STEAMCLIENT_INTERFACE_VERSION_008, NULL );
	if ( !steamClient )
	{
		std::cout << "no interface.\n";
		getchar();
		return 0;
	}

	HSteamPipe pipe = steamClient->CreateSteamPipe();
	HSteamUser user = steamClient->ConnectToGlobalUser( pipe );

	ISteamGameCoordinator001 *coord = (ISteamGameCoordinator001 *)steamClient->GetISteamGenericInterface( user, pipe, STEAMGAMECOORDINATOR_INTERFACE_VERSION_001 );

	CallbackMsg_t callbackMsg;
	HSteamCall steamCall;

	coord->SendMessage( 1002, "test", 4 );

	while ( true )
	{
		uint32 msg;
		if ( coord->IsMessageAvailable( &msg ) )
		{
			std::cout << "got message: " << msg << "\n";
		}



		if ( Steam_BGetCallback( pipe, &callbackMsg, &steamCall ) )
		{


			int32 callBack = callbackMsg.m_iCallback;
			ECallbackType type = (ECallbackType)((callBack / 100) * 100);

			std::cout << "[SERVER] Unhandled Callback: " << callBack << ", Type: " << EnumString<ECallbackType>::From(type) << ", Size: " << callbackMsg.m_cubParam << std::endl;

			int32 callSize = callbackMsg.m_cubParam;
			unsigned char *data = callbackMsg.m_pubParam;
			std::cout << "  ";
			for (int i = 0; i < callSize; i++)
			{
				unsigned char value = data[i];

				std::cout << std::hex << std::setw(2) << std::setfill('0') << std::uppercase << (unsigned int)value;
				std::cout << " ";

			}

			std::cout << std::resetiosflags(std::ios_base::hex | std::ios_base::uppercase) << std::endl;

			Steam_FreeLastCallback( pipe );

		}
		Sleep(10);
	}

	return 0;
}