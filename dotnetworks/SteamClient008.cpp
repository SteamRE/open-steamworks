
#include "SteamClient008.h"

namespace dotnetworks
{
	SteamClient008::SteamClient008( ISteamClient008 *steamClient ) //: base( steamClient )
	{
		base = steamClient;
	}

	SteamPipeHandle^ SteamClient008::CreateSteamPipe()
	{
		return gcnew SteamPipeHandle( base->CreateSteamPipe() );
	}

	bool SteamClient008::ReleaseSteamPipe( SteamPipeHandle^ hSteamPipe )
	{
		return base->ReleaseSteamPipe( hSteamPipe->base );
	}

	SteamUserHandle^ SteamClient008::ConnectToGlobalUser( SteamPipeHandle^ hSteamPipe )
	{
		return gcnew SteamUserHandle( base->ConnectToGlobalUser( hSteamPipe->base ) );
	}

	SteamUserHandle^ SteamClient008::CreateLocalUser( [Out] SteamPipeHandle^% phSteamPipe, EAccountType eAccountType )
	{
		HSteamPipe tempPipe;
		HSteamUser ret = base->CreateLocalUser( &tempPipe, eAccountType );

		phSteamPipe = gcnew SteamPipeHandle( tempPipe );
		return gcnew SteamUserHandle(ret);
	}
	void SteamClient008::ReleaseUser( SteamPipeHandle^ hSteamPipe, SteamUserHandle^ hSteamUser )
	{
		return base->ReleaseUser( hSteamPipe->base, hSteamUser->base );
	}

	
	DEFINE_GET_INTERFACE_FUNC(SteamClient008, SteamUser);
	DEFINE_GET_INTERFACE_FUNC(SteamClient008, SteamGameServer);

	void SteamClient008::SetLocalIPBinding( uint32 unIP, uint16 usPort)
	{
		base->SetLocalIPBinding(unIP, usPort);
	}

	DEFINE_GET_INTERFACE_FUNC( SteamClient008, SteamFriends );
	DEFINE_GET_UTIL_FUNC( SteamClient008, SteamUtils );
	DEFINE_GET_INTERFACE_FUNC( SteamClient008, SteamMatchmaking );
    DEFINE_GET_INTERFACE_FUNC( SteamClient008, SteamMasterServerUpdater );
    DEFINE_GET_INTERFACE_FUNC( SteamClient008, SteamMatchmakingServers );
    DEFINE_GET_GENERIC_FUNC( SteamClient008, SteamGenericInterface );
	DEFINE_GET_INTERFACE_FUNC( SteamClient008, SteamUserStats );
	DEFINE_GET_INTERFACE_FUNC( SteamClient008, SteamApps );
	DEFINE_GET_INTERFACE_FUNC( SteamClient008, SteamNetworking );
	DEFINE_GET_INTERFACE_FUNC( SteamClient008, SteamRemoteStorage );

	void SteamClient008::RunFrame()
	{
		base->RunFrame();
	}

	uint32 SteamClient008::GetIPCCallCount()
	{
		return base->GetIPCCallCount();
	}

	
	// TODO: wrap this function
	void SteamClient008::SetWarningMessageHook( void* fnPointer )
	{
		throw gcnew NotImplementedException();
		//base->Set...
	}

	BEGIN_GET_INTERFACE( SteamClient008 )
	{
		RETURN_INTERFACE( SteamFriends001, STEAMFRIENDS_INTERFACE_VERSION_001 );
		RETURN_INTERFACE( SteamFriends005, STEAMFRIENDS_INTERFACE_VERSION_005 );
		RETURN_INTERFACE( SteamRemoteStorage001, STEAMREMOTESTORAGE_INTERFACE_VERSION_001 );
		RETURN_INTERFACE( SteamUser012, STEAMUSER_INTERFACE_VERSION_012 );
		RETURN_INTERFACE( SteamUserStats002, STEAMUSERSTATS_INTERFACE_VERSION_002 );
		RETURN_INTERFACE( SteamUserStats004, STEAMUSERSTATS_INTERFACE_VERSION_004 );
		RETURN_INTERFACE( SteamUtils004, STEAMUTILS_INTERFACE_VERSION_004 );
	}
	END_GET_INTERFACE()
}