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

struct DownloadStats_s
{
#ifdef CLANG
	uint8 hack; // this is required to get S4N2's Steam4Intermediate to display this POD, this field doesn't actually exist
#endif
};
enum EAppDownloadPriority
{
};

abstract_class UNSAFE_INTERFACE IClientAppManager
{
public:
	virtual bool LaunchApp( AppId_t unAppID, uint32 uLaunchOption, const char *cszArgs ) = 0;
	virtual bool ShutdownApp( AppId_t unAppID, bool bForce ) = 0;

	virtual EAppState GetAppState( AppId_t unAppID ) = 0;

	virtual bool InstallApp( AppId_t unAppID ) = 0;
	virtual uint64 GetAppSize( AppId_t unAppID ) = 0;
	virtual uint32 GetAppDir( AppId_t unAppID, char *szBuffer, uint32 cubBuffer ) = 0;
	virtual bool UninstallApp( AppId_t unAppID, bool bComplete ) = 0;

	virtual uint32 GetUpdateInfo( AppId_t unAppID, AppUpdateInfo_s *pUpdateInfo ) = 0;

	virtual bool SetContentLocked( AppId_t unAppID, bool bContentLocked ) = 0;

	virtual bool StartValidatingApp( AppId_t unAppID ) = 0;

	virtual bool SetAppConfig( AppId_t unAppID, uint8 *pchBuffer, int cbBuffer, bool bUseSymbolsAsKeys ) = 0;

	virtual bool BIsAppUpToDate( AppId_t unAppID ) = 0;

	virtual bool SetDownloadingEnabled( bool bEnabled ) = 0;
	virtual bool BIsDownloadingEnabled() = 0;

	virtual bool GetDownloadStats( DownloadStats_s *pStats ) = 0;

	virtual AppId_t GetDownloadingAppID() = 0;
	virtual bool ChangeAppPriority( AppId_t unAppID, EAppDownloadPriority eDownloadPriority ) = 0;

	virtual bool AddSteam2Update( AppId_t unAppID ) = 0;
	virtual bool RemoveSteam2Update( AppId_t unAppID ) = 0;
	virtual bool StalledSteam2Update( AppId_t unAppID ) = 0;

	virtual bool IsUsingLocalContentServer() = 0;

};

#endif // ICLIENTAPPMANAGER_H
