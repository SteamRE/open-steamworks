//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#ifndef ICLIENTUTILS_H
#define ICLIENTUTILS_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"

#define CLIENTUTILS_INTERFACE_VERSION "CLIENTUTILS_INTERFACE_VERSION001"

class UNSAFE_INTERFACE IClientUtils
{
public:

	virtual const char *GetInstallPath() = 0;
	virtual const char *GetManagedContentRoot() = 0;

	// return the number of seconds since the user 
	virtual uint32 GetSecondsSinceAppActive() = 0;
	virtual uint32 GetSecondsSinceComputerActive() = 0;

	// the universe this client is connecting to
	virtual EUniverse GetConnectedUniverse() = 0;

	// server time - in PST, number of seconds since January 1, 1970 (i.e unix time)
	virtual uint32 GetServerRealTime() = 0;

	// returns the 2 digit ISO 3166-1-alpha-2 format country code this client is running in (as looked up via an IP-to-location database)
	// e.g "US" or "UK".
	virtual const char *GetIPCountry() = 0;

	//virtual unknown_ret LoadFileFromCDN( const char*, bool *, int, uint64 ) = 0;
	//virtual unknown_ret WriteCDNFileToDisk( int, const char* ) = 0;

	// returns true if the image exists, and valid sizes were filled out
	virtual bool GetImageSize( int iImage, uint32 *pnWidth, uint32 *pnHeight ) = 0;

	// returns true if the image exists, and the buffer was successfully filled out
	// results are returned in RGBA format
	// the destination buffer size should be 4 * height * width * sizeof(char)
	virtual bool GetImageRGBA( int iImage, uint8 *pubDest, int nDestBufferSize ) = 0;

	// returns the IP of the reporting server for valve - currently only used in Source engine games
	virtual bool GetCSERIPPort( uint32 *unIP, uint16 *usPort ) = 0;

	virtual uint32 GetNumRunningApps() = 0;

	// return the amount of battery power left in the current system in % [0..100], 255 for being on AC power
	virtual uint8 GetCurrentBatteryPower() = 0;


	virtual unknown_ret SetOfflineMode( bool ) = 0;
	virtual bool GetOfflineMode() = 0;

	virtual void SetAppIDForCurrentPipe( AppId_t appId ) = 0;
	virtual uint32 GetAppID() = 0;

	virtual unknown_ret SetAPIDebuggingActive( bool, bool ) = 0;
	virtual unknown_ret IsAPICallCompleted( uint64, bool * ) = 0;

	virtual unknown_ret GetAPICallFailureReason( uint64 ) = 0;
	virtual unknown_ret GetAPICallResult( uint64, void *, int, int, bool * ) = 0;

	virtual unknown_ret SignalAppsToShutDown() = 0;

	virtual unknown_ret GetCellID() = 0;

	virtual bool IsGlobalInstance() = 0;
};

#endif // ICLIENTUTILS_H
