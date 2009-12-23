#include "Steamworks.h"

#pragma comment(lib, "../steam")
#pragma comment(lib, "../steamclient")

using std::string;
using std::cout;
using std::cin;

#define STEAM_ERROR(err) ( err.eSteamError != eSteamErrorNone )

int main()
{
	// load steamclient
	CreateInterfaceFn interfaceFn = Sys_GetFactory( "steamclient.dll" );

	IClientEngine *clientEngine = (IClientEngine *)interfaceFn( CLIENTENGINE_INTERFACE_VERSION, NULL );
	if ( !clientEngine )
	{
		cout << "Unable to get IClientEngine.\n";
		return 1;
	}

	HSteamPipe hPipe;
	HSteamUser hUser = clientEngine->CreateGlobalUser( &hPipe );

	if ( !hUser || !hPipe )
	{
		cout << "Unable to create global user.\n";
		return 1;
	}

	TSteamError error;
	
	SteamClearError( &error );
	if ( !SteamStartEngine( &error ) )
	{
		cout << "Unable to start steam engine: " << error.szDesc << "\n";
		return 1;
	}

	SteamClearError( &error );
	if ( !SteamStartup( STEAM_USING_ALL, &error ) )
	{
		cout << "Unable to startup steam: " << error.szDesc << "\n";
		return 1;
	}

	FactoryFn _f = Sys_GetFactoryOld( "Steam.dll" );
	if ( !_f )
	{
		cout << "Unable to get steam factory.\n";
		return 1;
	}

	ISteam006 *steam = (ISteam006 *)_f( STEAM_INTERFACE_VERSION_006 );
	if ( !steam )
	{
		cout << "Unable to get Steam interface.\n";
		return 1;
	}

	string strUser;
	string strPass;

	cout << "Username: ";
	cin >> strUser;

	cout << "Password: ";
	cin >> strPass;

	SteamCallHandle_t loginHandle = steam->Login( strUser.c_str(), strPass.c_str(), true, &error );
	if ( loginHandle == STEAM_INVALID_CALL_HANDLE )
	{
		cout << "Invalid login handle.\n";
		return 1;
	}

	steam->BlockingCall( loginHandle, 100, &error );
	if ( STEAM_ERROR( error ) )
	{
		cout << "Unable to login: " << error.szDesc << "\n";
		return 1;
	}

	char szUser[ MAX_PATH ];
	uint32 nameLen;
	size_t len = strUser.copy( szUser, MAX_PATH );
	szUser[ len ] = 0;

	_strlwr( (char*)&szUser );

	SetEnvironmentVariable( "SteamUser", szUser );
	SetEnvironmentVariable( "SteamAppUser", szUser );

	TSteamGlobalUserID userId;

	IClientUtils *utils = clientEngine->GetIClientUtils( hPipe, CLIENTUTILS_INTERFACE_VERSION );
	IClientUser *user = clientEngine->GetIClientUser( hUser, hPipe, CLIENTUSER_INTERFACE_VERSION );
	if ( !utils || !user )
	{
		cout << "Unable to get IClientUtils or IClientUser.\n";
		return 1;
	}

	steam->GetUser( szUser, MAX_PATH, &nameLen, &userId, &error );
	if ( STEAM_ERROR( error ) )
	{
		cout << "Unable to GetUser: " << error.szDesc << "\n";
		return 1;
	}

	EUniverse universe = utils->GetConnectedUniverse();
	CSteamID steamId;

	steamId.SetFromSteam2( &userId, universe );

	

	user->LogOn( steamId );
	ELogonState state = user->GetLogonState();
	while ( state == k_ELogonStateLoggingOn )
	{
		Sleep( 10 );
		state = user->GetLogonState();
	}

	if ( state != k_ELogonStateLoggedOn )
	{
		cout << "Logon failed.";
		return 1;
	}


	return 0;

}