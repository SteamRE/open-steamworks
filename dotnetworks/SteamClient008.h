#pragma once

#include "SteamclientAPI.h"

#include "SteamPipeHandle.h"
#include "SteamUserHandle.h"

#include "SteamFriends001.h"
#include "SteamFriends005.h"
#include "SteamRemoteStorage001.h"
#include "SteamUser012.h"
#include "SteamUserStats002.h"
#include "SteamUserStats004.h"
#include "SteamUtils004.h"

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
		SteamClient008( ISteamClient008 *steamClient );
		
	public:
		SteamPipeHandle^ CreateSteamPipe();
		bool ReleaseSteamPipe( SteamPipeHandle^ hSteamPipe );

		SteamUserHandle^ ConnectToGlobalUser( SteamPipeHandle^ hSteamPipe );
		SteamUserHandle^ CreateLocalUser( [Out] SteamPipeHandle^% phSteamPipe, EAccountType eAccountType );

		void ReleaseUser( SteamPipeHandle^ hSteamPipe, SteamUserHandle^ hSteamUser );

		
		DECLARE_GET_INTERFACE_FUNC(SteamUser);
		DECLARE_GET_INTERFACE_FUNC(SteamGameServer);

		void SetLocalIPBinding( uint32 unIP, uint16 usPort);

		DECLARE_GET_INTERFACE_FUNC(SteamFriends);
		DECLARE_GET_UTIL_FUNC(SteamUtils);
		DECLARE_GET_INTERFACE_FUNC(SteamMatchmaking);
        DECLARE_GET_INTERFACE_FUNC(SteamMasterServerUpdater);
        DECLARE_GET_INTERFACE_FUNC(SteamMatchmakingServers);
        DECLARE_GET_GENERIC_FUNC(SteamGenericInterface);
		DECLARE_GET_INTERFACE_FUNC(SteamUserStats);
		DECLARE_GET_INTERFACE_FUNC(SteamApps);
		DECLARE_GET_INTERFACE_FUNC(SteamNetworking);
		DECLARE_GET_INTERFACE_FUNC(SteamRemoteStorage);

		void RunFrame();

		uint32 GetIPCCallCount();

		void SetWarningMessageHook( void* fnPointer );

	private:
		DECLARE_GET_INTERFACE();

	public:
		literal String^ InterfaceVersion = STEAMCLIENT_INTERFACE_VERSION_008;

	private:
		ISteamClient008 *base;
	};
}