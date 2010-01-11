#pragma once

#include "SteamclientAPI.h"

#include "Universe.h"
#include "SteamAPICallFailure.h"

#include "SteamAPICall.cpp"

#include "Macros.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;

namespace dotnetworks
{

	public ref class SteamUtils004
	{
	internal:
		SteamUtils004( void *steamUtils )
		{
			base = (ISteamUtils004 *)steamUtils;
		}
		
	public:

		// return the number of seconds since the user 
		uint32 GetSecondsSinceAppActive()
		{
			return base->GetSecondsSinceAppActive();
		}
		uint32 GetSecondsSinceComputerActive()
		{
			return base->GetSecondsSinceComputerActive();
		}

		// the universe this client is connecting to
		Universe GetConnectedUniverse()
		{
			return (Universe)base->GetConnectedUniverse();
		}

		// Steam server time - in PST, number of seconds since January 1, 1970 (i.e unix time)
		uint32 GetServerRealTime()
		{
			return base->GetServerRealTime();
		}

		// returns the 2 digit ISO 3166-1-alpha-2 format country code this client is running in (as looked up via an IP-to-location database)
		// e.g "US" or "UK".
		String^ GetIPCountry()
		{
			return gcnew String( base->GetIPCountry() );
		}

		// returns true if the image exists, and valid sizes were filled out
		bool GetImageSize( int iImage, [Out] uint32% pnWidth, [Out] uint32% pnHeight )
		{
			uint32 width, height;

			bool ret = base->GetImageSize(iImage, &width, &height);

			pnWidth = width;
			pnHeight = height;

			return ret;
		}

		// returns true if the image exists, and the buffer was successfully filled out
		// results are returned in RGBA format
		// the destination buffer size should be 4 * height * width * sizeof(char)
		bool GetImageRGBA( int iImage, array<byte>^ pubDest, int nDestBufferSize )
		{
			ARRAY_TO_PTR_NOCOPY(mem, nDestBufferSize);

			bool ret = base->GetImageRGBA(iImage, (uint8 *)mem, nDestBufferSize);

			ARRAY_COPY(mem, pubDest, nDestBufferSize);
			ARRAY_FREE(mem);

			return ret;
		}

		// returns the IP of the reporting server for valve - currently only used in Source engine games
		bool GetCSERIPPort( [Out] uint32% unIP, [Out] uint16% usPort )
		{
			uint32 ip;
			uint16 port;

			bool ret = base->GetCSERIPPort(&ip, &port);

			unIP = ip;
			usPort = port;

			return ret;
		}

		// return the amount of battery power left in the current system in % [0..100], 255 for being on AC power
		uint8 GetCurrentBatteryPower()
		{
			return base->GetCurrentBatteryPower();
		}

		// returns the appID of the current process
		uint32 GetAppID()
		{
			return base->GetAppID();
		}

		// Sets the position where the overlay instance for the currently calling game should show notifications.
		// This position is per-game and if this function is called from outside of a game context it will do nothing.
		void SetOverlayNotificationPosition( ENotificationPosition eNotificationPosition )
		{
			base->SetOverlayNotificationPosition(eNotificationPosition);
		}

		// API asynchronous call results
		// can be used directly, but more commonly used via the callback dispatch API (see steam_api.h)
		bool IsAPICallCompleted( SteamAPICall^ hSteamAPICall, [Out] bool% pbFailed )
		{
			bool temp;

			bool ret = base->IsAPICallCompleted(hSteamAPICall->base, &temp);

			pbFailed = temp;

			return ret;
		}
		SteamAPICallFailure GetAPICallFailureReason( SteamAPICall^ hSteamAPICall )
		{
			return (SteamAPICallFailure)base->GetAPICallFailureReason( hSteamAPICall->base );
		}
		bool GetAPICallResult( SteamAPICall^ hSteamAPICall, void *pCallback, int cubCallback, int iCallbackExpected, [Out] bool% pbFailed )
		{
			throw gcnew NotImplementedException();
		}

		// this needs to be called every frame to process matchmaking results
		// redundant if you're already calling SteamAPI_RunCallbacks()
		void RunFrame()
		{
			base->RunFrame();
		}

		// returns the number of IPC calls made since the last time this function was called
		// Used for perf debugging so you can understand how many IPC calls your game makes per frame
		// Every IPC call is at minimum a thread context switch if not a process one so you want to rate
		// control how often you do them.
		uint32 GetIPCCallCount()
		{
			return base->GetIPCCallCount();
		}

		// API warning handling
		// 'int' is the severity; 0 for msg, 1 for warning
		// 'const char *' is the text of the message
		// callbacks will occur directly after the API function is called that generated the warning or message
		void SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction )
		{
			throw gcnew NotImplementedException();
		}

		// Returns true if the overlay is running & the user can access it. The overlay process could take a few seconds to
		// start & hook the game process, so this function will initially return false while the overlay is loading.
		bool IsOverlayEnabled()
		{
			return base->IsOverlayEnabled();
		}

		literal String^ InterfaceVersion = STEAMUTILS_INTERFACE_VERSION_004;

	private:
		ISteamUtils004 *base;
	};
}