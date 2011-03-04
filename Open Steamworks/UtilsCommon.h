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

#ifndef UTILSCOMMON_H
#define UTILSCOMMON_H
#ifdef _WIN32
#pragma once
#endif



#define CLIENTUTILS_INTERFACE_VERSION "CLIENTUTILS_INTERFACE_VERSION001"

#define STEAMUTILS_INTERFACE_VERSION_001 "SteamUtils001"
#define STEAMUTILS_INTERFACE_VERSION_003 "SteamUtils003"
#define STEAMUTILS_INTERFACE_VERSION_002 "SteamUtils002"
#define STEAMUTILS_INTERFACE_VERSION_004 "SteamUtils004"
#define STEAMUTILS_INTERFACE_VERSION_005 "SteamUtils005"



// Steam API call failure results
typedef enum ESteamAPICallFailure
{
	k_ESteamAPICallFailureNone = -1,			// no failure
	k_ESteamAPICallFailureSteamGone = 0,		// the local Steam process has gone away
	k_ESteamAPICallFailureNetworkFailure = 1,	// the network connection to Steam has been broken, or was already broken
	// SteamServersDisconnected_t callback will be sent around the same time
	// SteamServersConnected_t will be sent when the client is able to talk to the Steam servers again
	k_ESteamAPICallFailureInvalidHandle = 2,	// the SteamAPICall_t handle passed in no longer exists
	k_ESteamAPICallFailureMismatchedCallback = 3,// GetAPICallResult() was called with the wrong callback type for this API call
} ESteamAPICallFailure;

typedef enum EConfigStore
{
	k_EConfigStoreInvalid = 0,
	k_EConfigStoreInstall = 1,
	k_EConfigStoreUserRoaming = 2,
	k_EConfigStoreUserLocal = 3,
	k_EConfigStoreMax = 4,
} EConfigStore;



#pragma pack( push, 8 )
//-----------------------------------------------------------------------------
// Purpose: The country of the user changed
//-----------------------------------------------------------------------------
struct IPCountry_t
{
	enum { k_iCallback = k_iSteamUtilsCallbacks + 1 };
};


//-----------------------------------------------------------------------------
// Purpose: Fired when running on a laptop and less than 10 minutes of battery is left, fires then every minute
//-----------------------------------------------------------------------------
struct LowBatteryPower_t
{
	enum { k_iCallback = k_iSteamUtilsCallbacks + 2 };
	uint8 m_nMinutesBatteryLeft;
};


//-----------------------------------------------------------------------------
// Purpose: called when a SteamAsyncCall_t has completed (or failed)
//-----------------------------------------------------------------------------
struct SteamAPICallCompleted_t
{
	enum { k_iCallback = k_iSteamUtilsCallbacks + 3 };
	SteamAPICall_t m_hAsyncCall;
};


//-----------------------------------------------------------------------------
// called when Steam wants to shutdown
//-----------------------------------------------------------------------------
struct SteamShutdown_t
{
	enum { k_iCallback = k_iSteamUtilsCallbacks + 4 };
};

struct SteamConfigStoreChanged_t
{
	enum { k_iCallback = k_iSteamUtilsCallbacks + 11 };

	EConfigStore m_eConfigStore;
	char m_szRootOfChanges[ 256 ];
};

//-----------------------------------------------------------------------------
// results for CheckFileSignature
//-----------------------------------------------------------------------------
enum ECheckFileSignature
{
	k_ECheckFileSignatureInvalidSignature = 0,
	k_ECheckFileSignatureValidSignature = 1,
	k_ECheckFileSignatureFileNotFound = 2,
	k_ECheckFileSignatureNoSignaturesFoundForThisApp = 3,
	k_ECheckFileSignatureNoSignaturesFoundForThisFile = 4,
};

//-----------------------------------------------------------------------------
// callback for CheckFileSignature
//-----------------------------------------------------------------------------
struct CheckFileSignature_t
{
	enum { k_iCallback = k_iSteamUtilsCallbacks + 5 };
	ECheckFileSignature m_eCheckFileSignature;
};

#pragma pack( pop )


#endif // UTILSCOMMON_H
