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

struct AppUpdateInfo_s
{
	RTime32 m_timeUpdateStart;
	uint64 m_unBytesToDownload;
	uint64 m_unBytesDownloaded;
	uint64 m_unBytesToWrite;
	uint64 m_unBytesWritten;
};

abstract_class UNSAFE_INTERFACE IClientAppManager
{
public:
	virtual bool LaunchApp( AppId_t unAppID, uint32 uLaunchOption, const char *cszArgs ) = 0;
	virtual bool ShutdownApp( AppId_t unAppID, bool bForce ) = 0;

	virtual EAppState GetAppState( AppId_t unAppID ) = 0;

	virtual bool InstallApp( AppId_t unAppID, const char *phBuffer, int cbBuffer ) = 0;
	virtual uint32 GetAppDir( AppId_t unAppID, char *szBuffer, uint32 cubBuffer ) = 0;
	virtual bool UninstallApp( AppId_t unAppID, bool bComplete ) = 0;

	virtual uint32 GetUpdateInfo( AppId_t unAppID, AppUpdateInfo_s *pUpdateInfo ) = 0;

	virtual bool StartDownloadingUpdates( AppId_t unAppID ) = 0;
	virtual bool StopDownloadingUpdates( AppId_t unAppID, bool bLockContent ) = 0;
	virtual bool ApplyUpdate( AppId_t unAppID ) = 0;

	virtual bool VerifyApp( AppId_t unAppID ) = 0;

	virtual bool GetFileInfo( AppId_t unAppID, const char *pchFileName, uint64 *punFileSize, DepotId_t *puDepotId ) = 0;

	virtual bool SetAppConfig( AppId_t unAppID, uint8 *pchBuffer, int cbBuffer ) = 0;

	virtual bool IsAppUpToDate( AppId_t unAppID ) = 0;
};

#endif // ICLIENTAPPMANAGER_H
