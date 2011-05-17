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

#ifndef APPSCOMMON_H
#define APPSCOMMON_H
#ifdef _WIN32
#pragma once
#endif



#define CLIENTAPPS_INTERFACE_VERSION "CLIENTAPPS_INTERFACE_VERSION001"
#define CLIENTAPPMANAGER_INTERFACE_VERSION "CLIENTAPPMANAGER_INTERFACE_VERSION001"

#define STEAMAPPS_INTERFACE_VERSION_001 "STEAMAPPS_INTERFACE_VERSION001"
#define STEAMAPPS_INTERFACE_VERSION_002 "STEAMAPPS_INTERFACE_VERSION002"
#define STEAMAPPS_INTERFACE_VERSION_003 "STEAMAPPS_INTERFACE_VERSION003"
#define STEAMAPPS_INTERFACE_VERSION_004 "STEAMAPPS_INTERFACE_VERSION004"


typedef enum EAppState
{
	k_EAppStateInvalid = 0,
	k_EAppStateUninstalled = 1,
	k_EAppStateUpdateRequired = 2,
	k_EAppStateFullyInstalled = 4,
	k_EAppStateDataEncrypted = 8,
	k_EAppStateDataLocked = 16,
	k_EAppStateDataCorrupt = 32,
	k_EAppStateAppRunning = 64,
	k_EAppStateUpdateRunning = 256,
	k_EAppStateUpdatePaused = 512,
	k_EAppStateUpdateSuspended = 1024,
	k_EAppStateUninstalling = 2048,
	k_EAppStateReconfiguring = 4096,
	k_EAppStateDownloading = 8192,
	k_EAppStateStaging = 16384,
	k_EAppStateCommitting = 32768,
} EAppState;

typedef enum EAppEvent
{
	k_EAppEventDownloadComplete = 2,
} EAppEvent;



#pragma pack( push, 8 )
//-----------------------------------------------------------------------------
// Purpose: called when new information about an app has arrived
//-----------------------------------------------------------------------------
struct AppDataChanged_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 1 };

	uint32 m_nAppID;

	bool m_bBySteamUI;
	bool m_bCDDBUpdate;
};

struct RequestAppCallbacksComplete_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 2 };
};

struct AppInfoUpdateComplete_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 3 };

	EResult m_EResult;
	uint32 m_cAppsUpdated;
};


//-----------------------------------------------------------------------------
// Purpose: posted after the user gains ownership of DLC & that DLC is installed
//-----------------------------------------------------------------------------
struct DlcInstalled_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 5 };

	uint32 m_nAppID;		// AppID of the DLC
};

struct OptionalDLCInstallation_t
{
	enum { k_iCallback = k_iSteamAppsCallbacks + 10 };

	AppId_t		m_nAppID;
	bool		m_bUnk;
};

#pragma pack( pop )

#endif // APPSCOMMON_H
