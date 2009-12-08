#pragma once

#define STEAMWORKS_CLIENT_INTERFACES
#include "SteamclientAPI.h"

#include "SteamID.h"
#include "AppID.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;


namespace dotnetworks
{

	public ref class ClientUtils
	{
	internal:
		ClientUtils( void *clientUtils );
		
	public:
		// return the number of seconds since the user 
		uint32 GetSecondsSinceAppActive();
		uint32 GetSecondsSinceComputerActive();

		// the universe this client is connecting to
		EUniverse GetConnectedUniverse();

		// server time - in PST, number of seconds since January 1, 1970 (i.e unix time)
		uint32 GetServerRealTime();

		// returns the 2 digit ISO 3166-1-alpha-2 format country code this client is running in (as looked up via an IP-to-location database)
		// e.g "US" or "UK".
		String^ GetIPCountry();

		unknown_ret LoadFileFromCDN( String^ a, [Out] bool% b, int c, uint64 d );
		unknown_ret WriteCDNFileToDisk( int a, String^ b );

		// returns true if the image exists, and valid sizes were filled out
		bool GetImageSize( int iImage, [Out] uint32% pnWidth, [Out] uint32% pnHeight );

		// returns true if the image exists, and the buffer was successfully filled out
		// results are returned in RGBA format
		// the destination buffer size should be 4 * height * width * sizeof(char)
		bool GetImageRGBA( int iImage, array<byte>^ pubDest, int nDestBufferSize );

		// returns the IP of the reporting server for valve - currently only used in Source engine games
		bool GetCSERIPPort( [Out] uint32% unIP, [Out] uint16% usPort );

		uint32 GetNumRunningApps();
		// return the amount of battery power left in the current system in % [0..100], 255 for being on AC power
		uint8 GetCurrentBatteryPower() ;


		unknown_ret SetOfflineMode( bool mode );
		bool GetOfflineMode();

		void SetAppIDForCurrentPipe( AppID^ appId );
		uint32 GetAppID();

		unknown_ret SetAPIDebuggingActive( bool a, bool b );
		unknown_ret IsAPICallCompleted( uint64 a, [Out] bool% b );

		unknown_ret GetAPICallFailureReason( uint64 a );
		unknown_ret GetAPICallResult( uint64 a, [Out] array<byte>^ b, int c, int d, bool% e );

		unknown_ret SignalAppsToShutDown();

		unknown_ret GetCellID();

		literal String^ InterfaceVersion = CLIENTUTILS_INTERFACE_VERSION;

	private:
		IClientUtils *base;
	};
}