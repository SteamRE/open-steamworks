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

#ifndef ICLIENTAPPMANAGER_H
#define ICLIENTAPPMANAGER_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "AppsCommon.h"

struct AppUpdateInfo_s;

class UNSAFE_INTERFACE IClientAppManager
{
public:
	virtual unknown_ret LaunchApp( AppId_t appId, uint32, const char* ) = 0;
	virtual unknown_ret ShutdownApp( AppId_t appId, bool ) = 0;

	virtual EAppState GetAppState( AppId_t appId ) = 0;

	virtual unknown_ret InstallApp( AppId_t appId, const char*, int) = 0;

	virtual unknown_ret GetAppDir( AppId_t appId, char *szBuffer, uint32 cubBuffer ) = 0;

	virtual unknown_ret UninstallApp( AppId_t appId, bool ) = 0;

	virtual unknown_ret GetUpdateInfo( AppId_t appId, AppUpdateInfo_s *) = 0;

	virtual unknown_ret StartDownloadingUpdate( AppId_t appId ) = 0;
	virtual unknown_ret StopDownloadingUpdate( AppId_t appId, bool ) = 0;
	virtual unknown_ret ApplyUpdate( AppId_t appId ) = 0;

	virtual unknown_ret VerifyApp( AppId_t appId ) = 0;

	virtual unknown_ret GetFileInfo( uint32, const char*, uint64*, uint32 * ) = 0;

	virtual unknown_ret SetAppConfig( uint32, unsigned char *, int ) = 0;
};

#endif // ICLIENTAPPMANAGER_H
