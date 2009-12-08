
#include "SteamUtils004.h"

#include "Macros.h"

namespace dotnetworks
{

	SteamUtils004::SteamUtils004( void *steamUtils )
	{
		base = (ISteamUtils004 *)steamUtils;
	}
	
	// return the number of seconds since the user 
	uint32 SteamUtils004::GetSecondsSinceAppActive()
	{
		return base->GetSecondsSinceAppActive();
	}
	uint32 SteamUtils004::GetSecondsSinceComputerActive()
	{
		return base->GetSecondsSinceComputerActive();
	}

	// the universe this client is connecting to
	Universe SteamUtils004::GetConnectedUniverse()
	{
		return (Universe)base->GetConnectedUniverse();
	}

	// Steam server time - in PST, number of seconds since January 1, 1970 (i.e unix time)
	uint32 SteamUtils004::GetServerRealTime()
	{
		return base->GetServerRealTime();
	}

	// returns the 2 digit ISO 3166-1-alpha-2 format country code this client is running in (as looked up via an IP-to-location database)
	// e.g "US" or "UK".
	String^ SteamUtils004::GetIPCountry()
	{
		return gcnew String( base->GetIPCountry() );
	}

	// returns true if the image exists, and valid sizes were filled out
	bool SteamUtils004::GetImageSize( int iImage, [Out] uint32% pnWidth, [Out] uint32% pnHeight )
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
	bool SteamUtils004::GetImageRGBA( int iImage, array<byte>^ pubDest, int nDestBufferSize )
	{
		ARRAY_TO_PTR_NOCOPY(mem, nDestBufferSize);


		bool ret = base->GetImageRGBA(iImage, (uint8 *)mem, nDestBufferSize);

		ARRAY_COPY(mem, pubDest, nDestBufferSize);
		ARRAY_FREE(mem);

		return ret;
	}

	// returns the IP of the reporting server for valve - currently only used in Source engine games
	bool SteamUtils004::GetCSERIPPort( [Out] uint32% unIP, [Out] uint16% usPort )
	{
		uint32 ip;
		uint16 port;

		bool ret = base->GetCSERIPPort(&ip, &port);

		unIP = ip;
		usPort = port;

		return ret;
	}

	// return the amount of battery power left in the current system in % [0..100], 255 for being on AC power
	uint8 SteamUtils004::GetCurrentBatteryPower()
	{
		return base->GetCurrentBatteryPower();
	}

	// returns the appID of the current process
	uint32 SteamUtils004::GetAppID()
	{
		return base->GetAppID();
	}

	// Sets the position where the overlay instance for the currently calling game should show notifications.
	// This position is per-game and if this function is called from outside of a game context it will do nothing.
	void SteamUtils004::SetOverlayNotificationPosition( ENotificationPosition eNotificationPosition )
	{
		base->SetOverlayNotificationPosition(eNotificationPosition);
	}

	// API asynchronous call results
	// can be used directly, but more commonly used via the callback dispatch API (see steam_api.h)
	bool SteamUtils004::IsAPICallCompleted( SteamAPICall^ hSteamAPICall, [Out] bool% pbFailed )
	{
		bool temp;

		bool ret = base->IsAPICallCompleted(hSteamAPICall->base, &temp);

		pbFailed = temp;

		return ret;
	}
	ESteamAPICallFailure SteamUtils004::GetAPICallFailureReason( SteamAPICall^ hSteamAPICall )
	{
		return base->GetAPICallFailureReason(hSteamAPICall->base);
	}
	bool SteamUtils004::GetAPICallResult( SteamAPICall^ hSteamAPICall, void *pCallback, int cubCallback, int iCallbackExpected, [Out] bool% pbFailed )
	{
		throw gcnew NotImplementedException();
	}

	// this needs to be called every frame to process matchmaking results
	// redundant if you're already calling SteamAPI_RunCallbacks()
	void SteamUtils004::RunFrame()
	{
		base->RunFrame();
	}

	// returns the number of IPC calls made since the last time this function was called
	// Used for perf debugging so you can understand how many IPC calls your game makes per frame
	// Every IPC call is at minimum a thread context switch if not a process one so you want to rate
	// control how often you do them.
	uint32 SteamUtils004::GetIPCCallCount()
	{
		return base->GetIPCCallCount();
	}

	// API warning handling
	// 'int' is the severity; 0 for msg, 1 for warning
	// 'const char *' is the text of the message
	// callbacks will occur directly after the API function is called that generated the warning or message
	void SteamUtils004::SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction )
	{
		throw gcnew NotImplementedException();
	}

	// Returns true if the overlay is running & the user can access it. The overlay process could take a few seconds to
	// start & hook the game process, so this function will initially return false while the overlay is loading.
	bool SteamUtils004::IsOverlayEnabled()
	{
		return base->IsOverlayEnabled();
	}
}