
#include "ClientUtils.h"


namespace dotnetworks
{

	ClientUtils::ClientUtils( void *clientUtils )
	{
		base = (IClientUtils *)clientUtils;
	}
	
	// return the number of seconds since the user 
	uint32 ClientUtils::GetSecondsSinceAppActive()
	{
		return base->GetSecondsSinceAppActive();
	}
	uint32 ClientUtils::GetSecondsSinceComputerActive()
	{
		return base->GetSecondsSinceComputerActive();
	}

	// the universe this client is connecting to
	EUniverse ClientUtils::GetConnectedUniverse()
	{
		return base->GetConnectedUniverse();
	}

	// server time - in PST, number of seconds since January 1, 1970 (i.e unix time)
	uint32 ClientUtils::GetServerRealTime()
	{
		return base->GetServerRealTime();
	}

	// returns the 2 digit ISO 3166-1-alpha-2 format country code this client is running in (as looked up via an IP-to-location database)
	// e.g "US" or "UK".
	String^ ClientUtils::GetIPCountry()
	{
		return gcnew String( base->GetIPCountry() );
	}

	unknown_ret ClientUtils::LoadFileFromCDN( String^ a, [Out] bool% b, int c, uint64 d )
	{
		throw gcnew NotImplementedException();
	}
	unknown_ret ClientUtils::WriteCDNFileToDisk( int a, String^ b )
	{
		throw gcnew NotImplementedException();
	}

	// returns true if the image exists, and valid sizes were filled out
	bool ClientUtils::GetImageSize( int iImage, [Out] uint32% pnWidth, [Out] uint32% pnHeight )
	{
		uint32 tempWid;
		uint32 tempHei;

		bool ret = base->GetImageSize( iImage, &tempWid, &tempHei );

		pnWidth = tempWid;
		pnHeight = tempHei;

		return ret;
	}

	// returns true if the image exists, and the buffer was successfully filled out
	// results are returned in RGBA format
	// the destination buffer size should be 4 * height * width * sizeof(char)
	bool ClientUtils::GetImageRGBA( int iImage, array<byte>^ pubDest, int nDestBufferSize )
	{
		uint8 *buff = (uint8 *)malloc(nDestBufferSize);

		bool ret = base->GetImageRGBA( iImage, buff, nDestBufferSize );

		IntPtr ptr(buff);
		Marshal::Copy(ptr, pubDest, 0, nDestBufferSize);
		free(buff);

		return ret;
	}

	// returns the IP of the reporting server for valve - currently only used in Source engine games
	bool ClientUtils::GetCSERIPPort( [Out] uint32% unIP, [Out] uint16% usPort )
	{
		uint32 tempIP;
		uint16 tempPort;

		bool ret = base->GetCSERIPPort(&tempIP, &tempPort);

		unIP = tempIP;
		usPort = tempPort;

		return ret;
	}

	uint32 ClientUtils::GetNumRunningApps()
	{
		return base->GetNumRunningApps();
	}

	// return the amount of battery power left in the current system in % [0..100], 255 for being on AC power
	uint8 ClientUtils::GetCurrentBatteryPower() 
	{
		return base->GetCurrentBatteryPower();
	}


	unknown_ret ClientUtils::SetOfflineMode( bool mode )
	{
		return base->SetOfflineMode(mode);
	}
	bool ClientUtils::GetOfflineMode()
	{
		return base->GetOfflineMode();
	}

	void ClientUtils::SetAppIDForCurrentPipe( AppID^ appId )
	{
		base->SetAppIDForCurrentPipe( appId->base );
	}
	uint32 ClientUtils::GetAppID()
	{
		return base->GetAppID();
	}

	unknown_ret ClientUtils::SetAPIDebuggingActive( bool a, bool b )
	{
		return base->SetAPIDebuggingActive(a, b);
	}
	unknown_ret ClientUtils::IsAPICallCompleted( uint64 a, [Out] bool% b )
	{
		bool tempB;

		unknown_ret ret = base->IsAPICallCompleted(a, &tempB);

		b = tempB;

		return ret;
	}

	unknown_ret ClientUtils::GetAPICallFailureReason( uint64 a )
	{
		return base->GetAPICallFailureReason(a);
	}
	unknown_ret ClientUtils::GetAPICallResult( uint64 a, [Out] array<byte>^ b, int c, int d, bool% e )
	{
		throw gcnew NotImplementedException();
	}

	unknown_ret ClientUtils::SignalAppsToShutDown()
	{
		return base->SignalAppsToShutDown();
	}

	unknown_ret ClientUtils::GetCellID()
	{
		return base->GetCellID();
	}
}