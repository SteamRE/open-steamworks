
#include "Steamworks.h"

#include <iostream>
#include <iomanip>

#pragma comment( lib, "../steamclient" )
#pragma comment( lib, "../steam" )


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


	CSteamAPILoader loader;

	CreateInterfaceFn factory = loader.Load();

	if ( !factory )
	{
		MessageBox( HWND_DESKTOP, "Unable to load steamclient.dll.", "Away Reply", MB_OK );
		return 0;
	}

	ISteamClient009 *steamClient = (ISteamClient009 *)factory( STEAMCLIENT_INTERFACE_VERSION_009, NULL );
	IClientEngine *clientEngine = (IClientEngine *)factory( CLIENTENGINE_INTERFACE_VERSION, NULL );

	HSteamPipe hPipe;
	HSteamUser hUser = clientEngine->CreateGlobalUser( &hPipe );
	if ( !hUser || !hPipe )
	{
		MessageBox( HWND_DESKTOP, "Unable to connect to global user.", "Away Reply", MB_OK );
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

	ISteam006 *steam = (ISteam006*)fn( "Steam006" );
	if ( !steam )
	{
		std::cout << "Unable to get ISteam006.\n";
		return 0;
	}

	std::string userName;
	std::string passWord;

	std::cout << "Username: ";
	std::cin >> userName;

	std::cout << "Password: ";
	std::cin >> passWord;

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

	clientUser->LogOn( steamId );

	ELogonState state = clientUser->GetLogonState();

	while ( state == k_ELogonStateLoggingOn )
	{
		state = clientUser->GetLogonState();
	}

	std::cout << "Logged on!\n";

	CallbackMsg_t callBack;

	while ( true )
	{
		if ( Steam_BGetCallback( hPipe, &callBack ) )
		{

			if ( callBack.m_iCallback == SteamServersConnected_t::k_iCallback )
			{
				MessageBox( HWND_DESKTOP, "We have successfully logged on!", "FML", MB_OK );

				clientFriends->SetPersonaState( k_EPersonaStateOnline );
			}

			/*
			std::cout << std::dec;
			std::cout << "Callback: " << callBack.m_iCallback << " Size: " << callBack.m_cubParam << "\n\t";

			
			for ( int i = 0; i < callBack.m_cubParam; i++ )
			{
				unsigned char value = callBack.m_pubParam[ i ];

				std::cout << std::hex << std::setw( 2 ) << std::setfill( '0' ) << std::uppercase << (unsigned int)value;
				std::cout << " ";
			}

			std::cout << "\n";*/


			Steam_FreeLastCallback( hPipe );
		}

		Sleep( 10 );
	}
}
