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

#ifndef USERCOMMON_H
#define USERCOMMON_H
#ifdef _WIN32
#pragma once
#endif


#define STEAMUSER_INTERFACE_VERSION_004 "SteamUser004"
#define STEAMUSER_INTERFACE_VERSION_005 "SteamUser005"
#define STEAMUSER_INTERFACE_VERSION_006 "SteamUser006"
#define STEAMUSER_INTERFACE_VERSION_007 "SteamUser007"
#define STEAMUSER_INTERFACE_VERSION_008 "SteamUser008"
#define STEAMUSER_INTERFACE_VERSION_009 "SteamUser009"
#define STEAMUSER_INTERFACE_VERSION_010 "SteamUser010"
#define STEAMUSER_INTERFACE_VERSION_011 "SteamUser011"
#define STEAMUSER_INTERFACE_VERSION_012 "SteamUser012"


// callbacks


//-----------------------------------------------------------------------------
// Purpose: called when a logon attempt has succeeded
//-----------------------------------------------------------------------------
struct LogonSuccess_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 1 };
};

//-----------------------------------------------------------------------------
// Purpose: called when a connections to the Steam back-end has been established
//			this means the Steam client now has a working connection to the Steam servers
//			usually this will have occurred before the game has launched, and should
//			only be seen if the user has dropped connection due to a networking issue
//			or a Steam server update
//-----------------------------------------------------------------------------
struct SteamServersConnected_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 1 };
};


//-----------------------------------------------------------------------------
// Purpose: called when a logon attempt has failed
//-----------------------------------------------------------------------------
struct LogonFailure_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 2 };
	EResult m_eResult;
};

//-----------------------------------------------------------------------------
// Purpose: called when a connection attempt has failed
//			this will occur periodically if the Steam client is not connected, 
//			and has failed in it's retry to establish a connection
//-----------------------------------------------------------------------------
struct SteamServerConnectFailure_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 2 };
	EResult m_eResult;
};



//-----------------------------------------------------------------------------
// Purpose: called when the user logs off
//-----------------------------------------------------------------------------
struct LoggedOff_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 3 };
	EResult m_eResult;
};

//-----------------------------------------------------------------------------
// Purpose: called if the client has lost connection to the Steam servers
//			real-time services will be disabled until a matching SteamServersConnected_t has been posted
//-----------------------------------------------------------------------------
struct SteamServersDisconnected_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 3 };
	EResult m_eResult;
};


//-----------------------------------------------------------------------------
// Purpose: called when the client is trying to retry logon after being unintentionally logged off
//-----------------------------------------------------------------------------
struct BeginLogonRetry_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 4 };
};

//-----------------------------------------------------------------------------
// Purpose: called when the steam2 ticket has been set
//-----------------------------------------------------------------------------
struct Steam2TicketChanged_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 6 };
};

//-----------------------------------------------------------------------------
// Purpose: called when app news update is recieved
//-----------------------------------------------------------------------------
struct ClientAppNewsItemUpdate_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 10 };

	uint8 m_eNewsUpdateType;	// one of ENewsUpdateType
	uint32 m_uNewsID;			// unique news post ID
	uint32 m_uAppID;			// app ID this update applies to if it is of type k_EAppNews
};


//-----------------------------------------------------------------------------
// Purpose: steam news update
//-----------------------------------------------------------------------------
struct ClientSteamNewsItemUpdate_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 12 };

	uint8 m_eNewsUpdateType;	// one of ENewsUpdateType
	uint32 m_uNewsID;			// unique news post ID
	uint32 m_uHaveSubID;		// conditions to control if we display this update for type k_ESteamNews
	uint32 m_uNotHaveSubID;
	uint32 m_uHaveAppID;
	uint32 m_uNotHaveAppID;
	uint32 m_uHaveAppIDInstalled;
	uint32 m_uHavePlayedAppID;
};



//-----------------------------------------------------------------------------
// Purpose: Sent by the Steam server to the client telling it to disconnect from the specified game server,
//			which it may be in the process of or already connected to.
//			The game client should immediately disconnect upon receiving this message.
//			This can usually occur if the user doesn't have rights to play on the game server.
//-----------------------------------------------------------------------------
struct ClientGameServerDeny_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 13 };

	uint32 m_uAppID;
	uint32 m_unGameServerIP;
	uint16 m_usGameServerPort;
	uint16 m_bSecure;
	uint32 m_uReason;
};

//-----------------------------------------------------------------------------
// Purpose: notifies the user that they are now the primary access point for chat messages
//-----------------------------------------------------------------------------
struct PrimaryChatDestinationSet_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 14 };
	uint8 m_bIsPrimary;
};

//-----------------------------------------------------------------------------
// Purpose: connect to game server denied
//-----------------------------------------------------------------------------
struct UserPolicyResponse_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 15 };
	uint8 m_bSecure;
};

//-----------------------------------------------------------------------------
// Purpose: steam cddb/bootstrapper update
//-----------------------------------------------------------------------------
struct ClientSteamNewsClientUpdate_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 16 };

	uint8 m_eNewsUpdateType;	// one of ENewsUpdateType
	uint8 m_bReloadCDDB; // if true there is a new CDDB available
	uint32 m_unCurrentBootstrapperVersion;
	uint32 m_unCurrentClientVersion;
};

//-----------------------------------------------------------------------------
// Purpose: called when the callback system for this client is in an error state (and has flushed pending callbacks)
//			When getting this message the client should disconnect from Steam, reset any stored Steam state and reconnect
//-----------------------------------------------------------------------------
struct CallbackPipeFailure_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 17 };
};

//-----------------------------------------------------------------------------
// Purpose: called when the callback system for this client is in an error state (and has flushed pending callbacks)
//			When getting this message the client should disconnect from Steam, reset any stored Steam state and reconnect.
//			This usually occurs in the rare event the Steam client has some kind of fatal error.
//-----------------------------------------------------------------------------
struct IPCFailure_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 17 };
	enum EFailureType 
	{ 
		k_EFailureFlushedCallbackQueue, 
		k_EFailurePipeFail,
	};
	uint8 m_eFailureType;
};

//-----------------------------------------------------------------------------
// callback for BeginAuthSession
//-----------------------------------------------------------------------------
struct ValidateAuthTicketResponse_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 43 };
	CSteamID m_SteamID;
	EAuthSessionResponse m_eAuthSessionResponse;
};


#endif // USERCOMMON_H
