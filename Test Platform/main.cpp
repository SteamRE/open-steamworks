#define STEAMWORKS_CLIENT_INTERFACES
#include "Steamworks.h"

#include <iostream>
#include <iomanip>

#pragma comment( lib, "../Resources/steamclient" )
#pragma comment( lib, "../Resources/steam" )


void ShowError( TSteamError *err )
{
	if ( !IS_STEAM_ERROR( (*err) ) )
		return;

	std::cout << "Error: " << err->szDesc << "\n";

	getchar();

	exit( 0 );
}

int main()
{
	//CSteamAPILoader loader;
	//CreateInterfaceFn factory = loader.Load();

	/*
	HMODULE hModuleSteamClient = GetModuleHandleA("steamclient.dll");
	if ( !hModuleSteamClient )
		hModuleSteamClient = LoadLibraryExA("steamclient.dll", NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
	CreateInterfaceFn factory = (CreateInterfaceFn)(GetProcAddress(hModuleSteamClient, CREATEINTERFACE_PROCNAME));
	*/
#if defined _WIN32
	CreateInterfaceFn factory = (CreateInterfaceFn)GetProcAddress(GetModuleHandleA("steamclient.dll"), "CreateInterface");
#elif defined _LINUX
	void* steamclient_library = dlopen("steamclient.so", RTLD_LAZY);
	CreateInterfaceFn factory = (CreateInterfaceFn)dlsym(steamclient_library, "CreateInterface");
	dlclose(steamclient_library);
#endif

	if ( !factory )
	{
		std::cout << "Unable to load steamclient factory." << std::endl;
		return 0;
	}

	ISteamClient009 *steamClient = (ISteamClient009 *)factory( STEAMCLIENT_INTERFACE_VERSION_009, NULL );
	IClientEngine *clientEngine = (IClientEngine *)factory( CLIENTENGINE_INTERFACE_VERSION, NULL );

	HSteamPipe hPipe;
	HSteamUser hUser = clientEngine->CreateGlobalUser( &hPipe );
	if ( !hUser || !hPipe )
	{
		std::cout << "Unable to connect to global user." << std::endl;
		return 0;
	}

	IClientUser *clientUser = (IClientUser *)clientEngine->GetIClientUser( hUser, hPipe, CLIENTUSER_INTERFACE_VERSION );
	IClientFriends *clientFriends = (IClientFriends *)clientEngine->GetIClientFriends( hUser, hPipe, CLIENTFRIENDS_INTERFACE_VERSION );
	ISteam2Bridge002 *steam2Bridge = (ISteam2Bridge002 *)steamClient->GetISteamGenericInterface( hUser, hPipe, STEAM2BRIDGE_INTERFACE_VERSION_002 );

	TSteamError error;

	if ( !SteamStartEngine( &error ) )
		ShowError( &error );

	if ( !SteamStartup( STEAM_USING_ALL, &error ) )
		ShowError( &error );
	
	/*
	HMODULE hModule = GetModuleHandle( "steam.dll" );
	if ( !hModule )
	{
		std::cout << "Unable to get steam.dll module.\n";
		return 0;
	}

	FactoryFn fn = (FactoryFn)GetProcAddress( hModule, "_f" );
	if ( !fn )
	{
		std::cout << "Unable to get factory.\n";
		return 0;
	}
	*/

#if defined _WIN32
	FactoryFn fn = (FactoryFn)GetProcAddress(GetModuleHandleA("steam.dll"), "_f");
#elif defined _LINUX
	void* steam_library = dlopen("libsteam.so", RTLD_LAZY);
	FactoryFn fn = (FactoryFn)dlsym(steam_library, "_f");
	dlclose(steam_library);
#endif

	ISteam006 *steam = (ISteam006*)fn( "Steam006" );
	if ( !steam )
	{
		std::cout << "Unable to get ISteam006.\n";
		return 0;
	}

	std::string userName = "hurrrusername"; // Username
	std::string passWord = "passworddurrr"; // Password

	//std::cout << "Username: ";
	//std::cin >> userName;

	//std::cout << "Password: ";
	//std::cin >> passWord;

	clientUser->SetLoginInformation( userName.c_str(), passWord.c_str(), false );

	SteamCallHandle_t handle = steam->Login( userName.c_str(), passWord.c_str(), 1, &error );
	if ( handle == STEAM_INVALID_CALL_HANDLE )
		ShowError( &error );

	if ( !steam->BlockingCall( handle, 100, &error ) )
		ShowError( &error );

	char szUser[ 255 ];
	uint32 userChars;
	TSteamGlobalUserID globalId;

	if ( !steam->GetUser( szUser, sizeof( szUser ), &userChars, &globalId, &error ) )
		ShowError( &error );

	char szEmailAddress[ 255 ];
	uint32 emailChars;

	if ( !steam->GetCurrentEmailAddress( szEmailAddress, sizeof( szEmailAddress ), &emailChars, &error ) )
		ShowError( &error );

	CSteamID steamId;
	steamId.SetFromSteam2( &globalId, steam2Bridge->GetConnectedUniverse() );

	clientUser->SetEmail( szEmailAddress );

	clientUser->LogOn( false, steamId );

	ELogonState state = clientUser->GetLogonState();

	while ( state == k_ELogonStateLoggingOn )
	{
		state = clientUser->GetLogonState();
	}

	std::cout << "Logged on!\n";

	CallbackMsg_t callBack;
	CSteamID adminID;

	while ( true )
	{
		if ( Steam_BGetCallback( hPipe, &callBack ) )
		{
			switch (callBack.m_iCallback)
			{
			case SteamServersConnected_t::k_iCallback:
				{
					std::cout << "Successfully logged on!" << std::endl;

					clientUser->SetComputerInUse();
					clientUser->SetSelfAsPrimaryChatDestination();
					clientFriends->SetPersonaState( k_EPersonaStateOnline );

					CSteamID friendID;
					for (int i = 0; i < clientFriends->GetFriendCount(k_EFriendFlagImmediate); i++)
					{
						friendID = clientFriends->GetFriendByIndex(i, k_EFriendFlagImmediate);

						if (strcmp(clientFriends->GetFriendPersonaName(friendID), ":MIB: Asherkin") != 0) // Put the persona name of the friend to use as the 'front end' here.
							continue;

						clientFriends->SendMsgToFriend(friendID, k_EChatEntryTypeChatMsg, "I'm logged on!", 15);
						adminID = friendID;
					}
					break;
				}

			case FriendChatMsg_t::k_iCallback:
				{
					FriendChatMsg_t *friendMessageInfo = (FriendChatMsg_t *)callBack.m_pubParam;
					if (friendMessageInfo->m_ulSender == adminID)
					{
						EChatEntryType msgType;
						CSteamID chatter;

						// allocate data for message  
						char *pvData = new char[2049];  
						memset(pvData, 0, 2049);  

						int length = clientFriends->GetChatMessage(friendMessageInfo->m_ulSender, friendMessageInfo->m_iChatID, pvData, 2049, &msgType, &chatter);  

						if (msgType & k_EChatEntryTypeChatMsg || msgType & k_EChatEntryTypeEmote)  
						{  
							std::cout << "Message from " << friendMessageInfo->m_ulSender.Render() << ": " << pvData << std::endl;

							if (strcmp(pvData, "quit") == 0)
							{
								clientFriends->SetPersonaState( k_EPersonaStateOffline );
								clientUser->LogOff();
								steam->Logout(&error);
								
								while ( state == k_ELogonStateLoggingOff || state == k_ELogonStateLoggedOn )
								{
									state = clientUser->GetLogonState();
								}

								exit( 0 );
							}

							clientFriends->SendMsgToFriend(friendMessageInfo->m_ulSender, msgType, pvData, length);
						}  

						// clean up  
						delete [] pvData;
					}
					break;
				}
			}

			/*std::cout << std::dec;
			std::cout << "Callback: " << callBack.m_iCallback << " Size: " << callBack.m_cubParam << "\n\t";

			
			for ( int i = 0; i < callBack.m_cubParam; i++ )
			{
				unsigned char value = callBack.m_pubParam[ i ];

				std::cout << std::hex << std::setw( 2 ) << std::setfill( '0' ) << std::uppercase << (unsigned int)value;
				std::cout << " ";
			}

			std::cout << "\n";
			*/

			Steam_FreeLastCallback( hPipe );
		}

#if defined _WIN32
		Sleep(10);
#elif defined _LINUX
		sleep(10);
#endif
	}
}
