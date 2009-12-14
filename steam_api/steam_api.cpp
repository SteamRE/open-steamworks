#include "stdafx.h"
#include "interfaces.h"

#include "ConfigReader.h"


CSteamAPILoader loader;
CreateInterfaceFn clientFactory = NULL;

STEAMCLIENT_ICLASS *internalSteamClient = NULL;

HSteamPipe pipe = 0;
HSteamUser user = 0;

ConfigReader config( "steam_api.cfg" );


#ifndef WIN32
void OutputDebugString( const char *msg )
{
	printf( "%s", msg ); // there's probably something better to use here
}
#endif



bool SteamAPI_InitInternal( bool safeInit )
{
	if ( !config.FileExists() )
	{
		OutputDebugString( "[S_API FAIL] SteamAPI_Init() failed; no config file found.\nConfig file names 'steam_api.cfg' is required.\n" );
		return false;
	}

	if ( !config.GetConfigString( "SteamCilent", steamClientVer, 30 ) )
	{
		OutputDebugString( "[S_API FAIL] SteamAPI_Init() failed; SteamClient version not set.\n" );
		return false;
	}
	// get other interface version strings


	clientFactory = loader.Load();
	if ( clientFactory == NULL )
	{
		OutputDebugString( "[S_API FAIL] SteamAPI_Init() failed; unable to locate a running instance of Steam, or a local steamclient.dll.\n" );
		return false;
	}

	steamClient = (ISteamClient *)clientFactory( steamClientVer, NULL );
	if ( !steamClient )
		return false; // valve's steam_api doesn't spew an error, but we probably should

	internalSteamClient = (STEAMCLIENT_ICLASS *)clientFactory( STEAMCLIENT_IFACE, NULL );
	if ( !internalSteamClient )
		return false;

	pipe = internalSteamClient->CreateSteamPipe();
	if ( !pipe )
		return false;

	user = internalSteamClient->ConnectToGlobalUser( pipe );
	if ( !user )
		return false;

	/* valve's code:

	if ( safe )
	{
		pSteamUtils = g_pSteamClient->GetISteamUils( g_hSteamPipe, "SteamUtils003" );
		if ( !pSteamUtils )
		{
			OutputDebugStringA("[S_API FAIL] SteamAPI_Init() failed; no appID found.\nEither launch the game from Steam, or put the file steam_appid.txt containing the correct appID in your game folder.\n");
			return 0;
		}
    }

	apparently this implies that if there is no steam_appid.txt, this interface won't be returned?
	*/
	if ( safeInit )
	{
		ISteamUtils003 *tempUtils = (ISteamUtils003 *)internalSteamClient->GetISteamUtils( pipe, STEAMUTILS_INTERFACE_VERSION_003 );

		if ( !tempUtils || !tempUtils->GetAppID() )
		{
			OutputDebugString("[S_API FAIL] SteamAPI_Init() failed; no appID found.\nEither launch the game from Steam, or put the file steam_appid.txt containing the correct appID in your game folder.\n");
			return false;
		}
	}

	// get other interfaces based on config strings
	if ( !LoadInterfaces() )
		return false;

	
	//Steam_RegisterInterfaceFuncs( loader.GetSteamModule() );

	return true;
}

S_API bool STEAM_CALL SteamAPI_Init()
{
	return SteamAPI_InitInternal( false );
}

S_API bool STEAM_CALL SteamAPI_InitSafe()
{
	return SteamAPI_InitInternal( true );
}

S_API void SteamAPI_Shutdown()
{
	if( user )
	{
		internalSteamClient->ReleaseUser( pipe, user );
		user = NULL;
	}

	if( pipe )
	{
		internalSteamClient->ReleaseSteamPipe( pipe );
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