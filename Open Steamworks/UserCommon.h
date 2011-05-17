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



#define CLIENTUSER_INTERFACE_VERSION "CLIENTUSER_INTERFACE_VERSION001"
#define CLIENTGAMESERVER_INTERFACE_VERSION "CLIENTGAMESERVER_INTERFACE_VERSION001"

#define STEAMUSER_INTERFACE_VERSION_004 "SteamUser004"
#define STEAMUSER_INTERFACE_VERSION_005 "SteamUser005"
#define STEAMUSER_INTERFACE_VERSION_006 "SteamUser006"
#define STEAMUSER_INTERFACE_VERSION_007 "SteamUser007"
#define STEAMUSER_INTERFACE_VERSION_008 "SteamUser008"
#define STEAMUSER_INTERFACE_VERSION_009 "SteamUser009"
#define STEAMUSER_INTERFACE_VERSION_010 "SteamUser010"
#define STEAMUSER_INTERFACE_VERSION_011 "SteamUser011"
#define STEAMUSER_INTERFACE_VERSION_012 "SteamUser012"
#define STEAMUSER_INTERFACE_VERSION_013 "SteamUser013"
#define STEAMUSER_INTERFACE_VERSION_014 "SteamUser014"
#define STEAMUSER_INTERFACE_VERSION_015 "SteamUser015"
#define STEAMUSER_INTERFACE_VERSION_016 "SteamUser016"

// Callback values for callback ValidateAuthTicketResponse_t which is a response to BeginAuthSession
typedef enum EAuthSessionResponse
{
	k_EAuthSessionResponseOK = 0,							// Steam has verified the user is online, the ticket is valid and ticket has not been reused.
	k_EAuthSessionResponseUserNotConnectedToSteam = 1,		// The user in question is not connected to steam
	k_EAuthSessionResponseNoLicenseOrExpired = 2,			// The license has expired.
	k_EAuthSessionResponseVACBanned = 3,					// The user is VAC banned for this game.
	k_EAuthSessionResponseLoggedInElseWhere = 4,			// The user account has logged in elsewhere and the session containing the game instance has been disconnected.
	k_EAuthSessionResponseVACCheckTimedOut = 5,				// VAC has been unable to perform anti-cheat checks on this user
	k_EAuthSessionResponseAuthTicketCanceled = 6,			// The ticket has been canceled by the issuer
	k_EAuthSessionResponseAuthTicketInvalidAlreadyUsed = 7,	// This ticket has already been used, it is not valid.
	k_EAuthSessionResponseAuthTicketInvalid = 8,			// This ticket is not from a user instance currently connected to steam.
} EAuthSessionResponse;

// results from BeginAuthSession
typedef enum EBeginAuthSessionResult
{
	k_EBeginAuthSessionResultOK = 0,						// Ticket is valid for this game and this steamID.
	k_EBeginAuthSessionResultInvalidTicket = 1,				// Ticket is not valid.
	k_EBeginAuthSessionResultDuplicateRequest = 2,			// A ticket has already been submitted for this steamID
	k_EBeginAuthSessionResultInvalidVersion = 3,			// Ticket is from an incompatible interface version
	k_EBeginAuthSessionResultGameMismatch = 4,				// Ticket is not for this game
	k_EBeginAuthSessionResultExpiredTicket = 5,				// Ticket has expired
} EBeginAuthSessionResult;

typedef enum EAppUsageEvent
{
	k_EAppUsageEventGameLaunch = 1,
	k_EAppUsageEventGameLaunchTrial = 2,
	k_EAppUsageEventMedia = 3,
	k_EAppUsageEventPreloadStart = 4,
	k_EAppUsageEventPreloadFinish = 5,
	k_EAppUsageEventMarketingMessageView = 6,	// deprecated, do not use
	k_EAppUsageEventInGameAdViewed = 7,
	k_EAppUsageEventGameLaunchFreeWeekend = 8,
} EAppUsageEvent;

typedef enum ERegistrySubTree
{
	k_ERegistrySubTreeNews = 0,
	k_ERegistrySubTreeApps = 1,
	k_ERegistrySubTreeSubscriptions = 2,
	k_ERegistrySubTreeGameServers = 3,
	k_ERegistrySubTreeFriends = 4,
	k_ERegistrySubTreeSystem = 5,
	k_ERegistrySubTreeAppOwnershipTickets = 6,
	k_ERegistrySubTreeLegacyCDKeys = 7,
} ERegistrySubTree;

typedef enum ELogonState
{
	k_ELogonStateNotLoggedOn = 0,
	k_ELogonStateLoggingOn = 1,
	k_ELogonStateLoggingOff = 2,
	k_ELogonStateLoggedOn = 3
} ELogonState;

// Error codes for use with the voice functions
typedef enum EVoiceResult
{
	k_EVoiceResultOK = 0,
	k_EVoiceResultNotInitialized = 1,
	k_EVoiceResultNotRecording = 2,
	k_EVoiceResultNoData = 3,
	k_EVoiceResultBufferTooSmall = 4,
	k_EVoiceResultDataCorrupted = 5,
	k_EVoiceResultRestricted = 6,
	k_EVoiceResultUnsupportedCodec = 7,
} EVoiceResult;

//-----------------------------------------------------------------------------
// Purpose: types of VAC bans
//-----------------------------------------------------------------------------
typedef enum EVACBan
{
	k_EVACBanGoldsrc,
	k_EVACBanSource,
	k_EVACBanDayOfDefeatSource,
} EVACBan;

typedef enum EUserHasLicenseForAppResult
{
	k_EUserHasLicenseResultHasLicense = 0,					// User has a license for specified app
	k_EUserHasLicenseResultDoesNotHaveLicense = 1,			// User does not have a license for the specified app
	k_EUserHasLicenseResultNoAuth = 2,						// User has not been authenticated
} EUserHasLicenseForAppResult;

// Enum for the types of news push items you can get
typedef enum ENewsUpdateType
{
	k_EAppNews = 0,	 // news about a particular app
	k_ESteamAds = 1, // Marketing messages
	k_ESteamNews = 2, // EJ's corner and the like
	k_ECDDBUpdate = 3, // backend has a new CDDB for you to load
	k_EClientUpdate = 4,	// new version of the steam client is available
} ENewsUpdateType;

typedef enum ESteamUsageEvent
{
	k_ESteamUsageEventMarketingMessageView = 1,
	k_ESteamUsageEventHardwareSurvey = 2,
	k_ESteamUsageEventDownloadStarted = 3,
	k_ESteamUsageEventLocalizedAudioChange = 4,
} ESteamUsageEvent;

typedef enum EClientStat
{
	k_EClientStatP2PConnectionsUDP = 0,
	k_EClientStatP2PConnectionsRelay = 1,
	k_EClientStatP2PGameConnections = 2,
	k_EClientStatP2PVoiceConnections = 3,
	k_EClientStatBytesDownloaded = 4,
	k_EClientStatMax = 5,
} EClientStat;

typedef enum ENatType
{
	eNatTypeUntested = 0,
	eNatTypeTestFailed = 1,
	eNatTypeNoUDP = 2,
	eNatTypeOpenInternet = 3,
	eNatTypeFullCone = 4,
	eNatTypeRestrictedCone = 5,
	eNatTypePortRestrictedCone = 6,
	eNatTypeUnspecified = 7,
	eNatTypeSymmetric = 8,
	eNatTypeSymmetricFirewall = 9,
	eNatTypeCount = 10,
} ENatType;

//-----------------------------------------------------------------------------
// Purpose: Marketing message flags that change how a client should handle them
//-----------------------------------------------------------------------------
typedef enum EMarketingMessageFlags
{
	k_EMarketingMessageFlagsNone = 0,
	k_EMarketingMessageFlagsHighPriority = 1 << 0,
	k_EMarketingMessageFlagsPlatformWindows = 1 << 1,
	k_EMarketingMessageFlagsPlatformMac = 1 << 2,

	//aggregate flags
	k_EMarketingMessageFlagsPlatformRestrictions = 
	k_EMarketingMessageFlagsPlatformWindows | k_EMarketingMessageFlagsPlatformMac,
} EMarketingMessageFlags;



class CNatTraversalStat
{
public:
	EResult m_eResult;
	ENatType m_eLocalNatType;
	ENatType m_eRemoteNatType;
	bool m_bMultiUserChat : 1;
	bool m_bRelay : 1;
};


#pragma pack( push, 8 )
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

struct ClientPrimaryChatDestinationSet_t
{
	enum { k_iCallback = k_iClientUserCallbacks + 3 };

	uint8 m_bIsPrimary;
	uint8 m_bWasPrimary;
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

	ENewsUpdateType m_eNewsUpdateType;	// one of ENewsUpdateType
	uint32 m_uNewsID;			// unique news post ID
	uint32 m_uAppID;			// app ID this update applies to if it is of type k_EAppNews
};


//-----------------------------------------------------------------------------
// Purpose: steam news update
//-----------------------------------------------------------------------------
struct ClientSteamNewsItemUpdate_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 12 };

	ENewsUpdateType m_eNewsUpdateType;	// one of ENewsUpdateType

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

	AppId_t m_uAppID;
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

struct LegacyCDKeyRegistered_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 18 };

	EResult m_eResult;
	AppId_t m_iAppID;
	char m_rgchCDKey[ 64 ];
};

struct AccountInformationUpdated_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 19 };
};


struct GuestPassSent_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 20 };

	EResult m_eResult;
};

struct GuestPassAcked_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 21 };

	EResult m_eResult;

	PackageId_t m_unPackageID;

	GID_t m_gidGuestPassID;
	uint64 m_ulGuestPassKey;
};

struct GuestPassRedeemed_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 22 };

	EResult m_eResult;
	uint32 m_unPackageID;
};

struct UpdateGuestPasses_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 23 };

	EResult m_eResult;

	uint32 m_cGuestPassesToGive;
	uint32 m_cGuestPassesToRedeem;
};

struct LogOnCredentialsChanged_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 24 };
};

struct LicensesUpdated_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 25 };
};

struct CheckPasswordResponse_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 26 };

	EResult m_EResult;
};

struct ResetPasswordResponse_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 27 };

	EResult m_EResult;
};

struct AppLifetimeNotice_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 30 };

	AppId_t m_nAppID;
	int m_nInstanceID;
	bool m_bExiting;
};

struct AppOwnershipTicketReceived_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 31 };

	AppId_t m_nAppID;
};

struct PasswordChangeResponse_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 32 };

	EResult m_EResult;
};

struct EmailChangeResponse_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 33 };

	EResult m_EResult;
};

struct SecretQAChangeResponse_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 34 };

	EResult m_EResult;
};

struct CreateAccountResponse_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 35 };

	EResult m_EResult;
};

struct SendForgottonPasswordEmailResponse_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 37 };

	EResult m_EResult;
};

struct ResetForgottonPasswordResponse_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 38 };

	EResult m_EResult;
};

struct DownloadFromDFSResponse_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 40 };

	EResult m_EResult;

	char m_rgchURL[ 128 ];
};

struct DRMSDKFileTransferResult_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 41 };

	EResult m_EResult;
};

struct ClientMarketingMessageUpdate_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 42 };
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

struct MsgWebAuthToken_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 48 };
	
	bool m_bValid;
	char m_Token[ 512 ];
};

//-----------------------------------------------------------------------------
// Purpose: called when a user has responded to a microtransaction authorization request
//-----------------------------------------------------------------------------
struct MicroTxnAuthorizationResponse_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 52 };

	uint32 m_unAppID;			// AppID for this microtransaction
	uint64 m_ulOrderID;			// OrderID provided for the microtransaction
	uint8 m_bAuthorized;		// if user authorized transaction
};


//-----------------------------------------------------------------------------
// Purpose: Result from RequestEncryptedAppTicket
//-----------------------------------------------------------------------------
struct EncryptedAppTicketResponse_t
{
	enum { k_iCallback = k_iSteamUserCallbacks + 54 };

	EResult m_eResult;
};

#pragma pack( pop )


#endif // USERCOMMON_H
