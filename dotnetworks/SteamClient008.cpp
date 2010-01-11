#pragma once

#include "SteamclientAPI.h"

#include "AccountType.h"

#include "SteamPipeHandle.cpp"
#include "SteamUserHandle.cpp"

#include "SteamFriends001.cpp"
#include "SteamFriends005.cpp"
#include "SteamRemoteStorage001.cpp"
#include "SteamUser012.cpp"
#include "SteamUserStats002.cpp"
#include "SteamUserStats004.cpp"
#include "SteamUtils004.cpp"
#include "SteamNetworking002.cpp"

#include "Macros.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::Serialization;

namespace dotnetworks
{
	public ref class SteamClient008
	{
	internal:
		SteamClient008( ISteamClient008 *steamClient )
		{
			base = steamClient;
		}
		
	public:
		SteamPipeHandle^ CreateSteamPipe()
		{
			return gcnew SteamPipeHandle( base->CreateSteamPipe() );
		}

		bool ReleaseSteamPipe( SteamPipeHandle^ hSteamPipe )
		{
			return base->ReleaseSteamPipe( hSteamPipe->base );
		}

		SteamUserHandle^ ConnectToGlobalUser( SteamPipeHandle^ hSteamPipe )
		{
			return gcnew SteamUserHandle( base->ConnectToGlobalUser( hSteamPipe->base ) );
		}

		SteamUserHandle^ CreateLocalUser( [Out] SteamPipeHandle^% phSteamPipe, AccountType eAccountType )
		{
			HSteamPipe tempPipe;
			HSteamUser ret = base->CreateLocalUser( &tempPipe, (EAccountType)eAccountType );

			phSteamPipe = gcnew SteamPipeHandle( tempPipe );
			return gcnew SteamUserHandle(ret);
		}
		void ReleaseUser( SteamPipeHandle^ hSteamPipe, SteamUserHandle^ hSteamUser )
		{
			return base->ReleaseUser( hSteamPipe->base, hSteamUser->base );
		}

		GET_INTERFACE_FUNC( SteamUser );
		GET_INTERFACE_FUNC( SteamGameServer );

		void SetLocalIPBinding( uint32 unIP, uint16 usPort )
		{
			base->SetLocalIPBinding( unIP, usPort );
		}

		GET_INTERFACE_FUNC( SteamFriends );
		GET_UTIL_FUNC( SteamUtils );
		GET_INTERFACE_FUNC( SteamMatchmaking );
        GET_INTERFACE_FUNC( SteamMasterServerUpdater );
        GET_INTERFACE_FUNC( SteamMatchmakingServers );
        GET_INTERFACE_FUNC( SteamGenericInterface );
		GET_INTERFACE_FUNC( SteamUserStats );
		GET_INTERFACE_FUNC( SteamApps );
		GET_INTERFACE_FUNC( SteamNetworking );
		GET_INTERFACE_FUNC( SteamRemoteStorage );

		void RunFrame()
		{
			base->RunFrame();
		}

		uint32 GetIPCCallCount()
		{
			return base->GetIPCCallCount();
		}

		void SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction )
		{
			throw gcnew NotImplementedException();
		}

	public:
		literal String^ InterfaceVersion = STEAMCLIENT_INTERFACE_VERSION_008;

	private:
		ISteamClient008 *base;

		BEGIN_GET_INTERFACE()
			RETURN_INTERFACE( SteamFriends001, STEAMFRIENDS_INTERFACE_VERSION_001 )
			RETURN_INTERFACE( SteamFriends005, STEAMFRIENDS_INTERFACE_VERSION_005 )
			RETURN_INTERFACE( SteamRemoteStorage001, STEAMREMOTESTORAGE_INTERFACE_VERSION_001 )
			RETURN_INTERFACE( SteamUser012, STEAMUSER_INTERFACE_VERSION_012 )
			RETURN_INTERFACE( SteamUserStats002, STEAMUSERSTATS_INTERFACE_VERSION_002 )
			RETURN_INTERFACE( SteamUserStats004, STEAMUSERSTATS_INTERFACE_VERSION_004 )
			RETURN_INTERFACE( SteamUtils004, STEAMUTILS_INTERFACE_VERSION_004 )
			RETURN_INTERFACE( SteamNetworking002, STEAMNETWORKING_INTERFACE_VERSION_002 )
		END_GET_INTERFACE()

	};
}