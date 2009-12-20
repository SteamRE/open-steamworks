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

#ifndef STEAMTYPES_H
#define STEAMTYPES_H
#ifdef _WIN32
#pragma once
#endif

#ifdef _WIN32
	#ifndef WINVER
		#define WINVER 0x502
	#endif
	#define _CRT_SECURE_NO_WARNINGS // we don't use unsafe functions unsafely!
	#include <windows.h>

	#undef SendMessage // for ISteamGameCoordinator001 to work right..

	#if defined( STEAM_API_EXPORTS )
	#define S_API extern "C" __declspec( dllexport ) 
	#else
	#define S_API extern "C" __declspec( dllimport ) 
	#endif // STEAM_API_EXPORTS

#else

	#include <dlfcn.h> // dlopen,dlclose, et al
	#include <unistd.h>
	#include <arpa/inet.h>

	#define HMODULE void *
	#define GetProcAddress dlsym

	#define S_API extern "C"
	#define __cdecl __attribute__((__cdecl__))

	typedef unsigned char byte;
#endif

// this is an MSVC project.. but for the same of supporting other compilers we have to jump through hoops
#ifndef _MSC_VER
	#define sprintf_s snprintf
	inline void _strcpy_s(char *dest, size_t len, const char *source) { strncpy(dest, source, len); };
#else
	#define _strcpy_s strcpy_s
#endif

#define STEAM_CALL __cdecl

// Steam-specific types. Defined here so this header file can be included in other code bases.
#ifndef WCHARTYPES_H
typedef unsigned char uint8;
#endif

// is there a better place to put this?
#include "string_t.h"


#if defined(__x86_64__) || defined(_WIN64)
#define X64BITS
#endif

typedef unsigned char uint8;
typedef signed char int8;

#if defined( _WIN32 )

typedef __int16 int16;
typedef unsigned __int16 uint16;
typedef __int32 int32;
typedef unsigned __int32 uint32;
typedef __int64 int64;
typedef unsigned __int64 uint64;

#ifdef X64BITS
typedef __int64 intp;				// intp is an integer that can accomodate a pointer
typedef unsigned __int64 uintp;		// (ie, sizeof(intp) >= sizeof(int) && sizeof(intp) >= sizeof(void *)
#else
typedef __int32 intp;
typedef unsigned __int32 uintp;
#endif

#else // _WIN32

typedef short int16;
typedef unsigned short uint16;
typedef int int32;
typedef unsigned int uint32;
typedef long long int64;
typedef unsigned long long uint64;
#ifdef X64BITS
typedef long long intp;
typedef unsigned long long uintp;
#else
typedef int intp;
typedef unsigned int uintp;
#endif

#endif // else _WIN32

// steamclient/api
#include "EResult.h"
#include "EUniverse.h"
#include "EDenyReason.h"
#include "EAccountType.h"
#include "ESteamUserStatType.h"
#include "EChatEntryType.h"
#include "EChatRoomEnterResponse.h"
#include "EServerMode.h"
#include "EFriendRelationship.h"
#include "EPersonaState.h"
#include "EFriendFlags.h"
#include "EPersonaChange.h"
#include "EFriendMsgType.h"
#include "ERegistrySubTree.h"
#include "EAppUsageEvent.h"
#include "ELogonState.h"
#include "EVACBan.h"
#include "EItemRequestResult.h"
#include "EItemQuality.h"
#include "EMatchMakingServerResponse.h"
#include "EMatchMakingType.h"
#include "EPaymentMethod.h"
#include "ELicenseFlags.h"
#include "EPurchaseResultDetail.h"
#include "ESteamAPICallFailure.h"
#include "EAvatarSize.h"
#include "ELobbyType.h"
#include "ELobbyComparison.h"
#include "ESNetSocketState.h"
#include "ESNetSocketConnectionType.h"
#include "ELeaderboardDataRequest.h"
#include "ELeaderboardSortMethod.h"
#include "ELeaderboardDisplayType.h"
#include "EVoiceResult.h"
#include "EBeginAuthSessionResult.h"
#include "EAuthSessionResponse.h"
#include "ENotificationPosition.h"
#include "EItemCriteriaOperator.h"
#include "ESystemIMType.h"
#include "ENewsUpdateType.h"
#include "EAppState.h"
#include "EPurchaseStatus.h"
#include "ECurrencyCode.h"
#include "EConnectionPriority.h"
#include "EDepotBuildStatus.h"
#include "EChatRoomType.h"
#include "ECallState.h"
#include "EChatRoomVoiceStatus.h"
#include "EClanRelationship.h"
#include "EClanRank.h"
#include "EGameCoordinatorResult.h"

// steam
#include "EDetailedPlatformErrorType.h"
#include "ESteamError.h"
#include "ESteamSeekMethod.h"
#include "ESteamBufferMethod.h"
#include "ESteamFindFilter.h"
#include "ESteamBillingType.h"
#include "ESteamSubscriptionBillingInfoType.h"
#include "ESteamPaymentCardType.h"
#include "ESteamNotificationCallbackEvent.h"
#include "ESteamAppUpdateStatsQueryType.h"
#include "ESteamSubscriptionStatus.h"
#include "ESteamServerType.h"


typedef void* (*CreateInterfaceFn)( const char *pName, int *pReturnCode );
typedef void* (*FactoryFn)( const char *pName );
typedef void* (*InstantiateInterfaceFn)();

typedef void  (*SteamAPIWarningMessageHook_t)(int, const char *);
typedef void (*SteamNotificationCallback_t)(ESteamNotify eEvent, unsigned int nData);
typedef void (*KeyValueIteratorCallback_t)(const char*, const char*, void*);

typedef bool (*SteamBGetCallbackFn)( int, void *pCallbackMsg, int32 *phSteamCall );
typedef void (*SteamFreeLastCallbackFn)( int );
typedef bool (*SteamGetAPICallResultFn)( int, uint64 hSteamAPICall, void* pCallback, int cubCallback, int iCallbackExpected, bool* pbFailed );

const int k_cubDigestSize = 20;							// CryptoPP::SHA::DIGESTSIZE
const int k_cubSaltSize   = 8;

const int k_cchGameExtraInfoMax = 64;

// Max number of credit cards stored for one account
const int k_nMaxNumCardsPerAccount = 1;

// game server flags
const uint32 k_unServerFlagNone			= 0x00;
const uint32 k_unServerFlagActive		= 0x01;		// server has users playing
const uint32 k_unServerFlagSecure		= 0x02;		// server wants to be secure
const uint32 k_unServerFlagDedicated	= 0x04;		// server is dedicated
const uint32 k_unServerFlagLinux		= 0x08;		// linux build
const uint32 k_unServerFlagPassworded	= 0x10;		// password protected
const uint32 k_unServerFlagPrivate		= 0x20;		// server shouldn't list on master server and
													// won't enforce authentication of users that connect to the server.
													// Useful when you run a server where the clients may not
													// be connected to the internet but you want them to play (i.e LANs)

//-----------------------------------------------------------------------------
// Constants used for query ports.
//-----------------------------------------------------------------------------
#define QUERY_PORT_NOT_INITIALIZED		0xFFFF	// We haven't asked the GS for this query port's actual value yet.
#define QUERY_PORT_ERROR				0xFFFE	// We were unable to get the query port for this server.


typedef	uint8 SHADigest_t[ k_cubDigestSize ];
typedef	uint8 Salt_t[ k_cubSaltSize ];

typedef uint64 GID_t;		// globally unique identifier


// this is baked into client messages and interfaces as an int, 
// make sure we never break this.
typedef uint32 PackageId_t;
const PackageId_t k_uPackageIdInvalid = 0xFFFFFFFF;

// this is baked into client messages and interfaces as an int, 
// make sure we never break this.
typedef uint32 AppId_t;
const AppId_t k_uAppIdInvalid = 0x0;

typedef uint32 ShareType_t;

typedef uint32 HDepotBuild;

typedef int HVoiceCall;


// RTime32
// We use this 32 bit time representing real world time.
// It offers 1 second resolution beginning on January 1, 1970 (Unix time)
typedef uint32 RTime32;

typedef uint32 CellID_t;

// handle to a Steam API call
typedef uint64 SteamAPICall_t;

// handle to a communication pipe to the Steam client
typedef int32 HSteamPipe;
// handle to single instance of a steam user
typedef int32 HSteamUser;
// reference to a steam call, to filter results by
typedef int32 HSteamCall;

// return type of GetAuthSessionTicket
typedef uint32 HAuthTicket;
const HAuthTicket k_HAuthTicketInvalid = 0;

typedef int HNewItemRequest;
typedef uint64 ItemID;

typedef int unknown_ret; // unknown return value

typedef int HServerQuery;
const int HSERVERQUERY_INVALID = 0xffffffff;

// returns true of the flags indicate that a user has been removed from the chat
#define BChatMemberStateChangeRemoved( rgfChatMemberStateChangeFlags ) ( rgfChatMemberStateChangeFlags & ( k_EChatMemberStateChangeDisconnected | k_EChatMemberStateChangeLeft | k_EChatMemberStateChangeKicked | k_EChatMemberStateChangeBanned ) )

// game server flags
const uint32 k_unFavoriteFlagNone			= 0x00;
const uint32 k_unFavoriteFlagFavorite		= 0x01; // this game favorite entry is for the favorites list
const uint32 k_unFavoriteFlagHistory		= 0x02; // this game favorite entry is for the history list

// handle to a socket
typedef uint32 SNetSocket_t;
typedef uint32 SNetListenSocket_t;

// 32KB max size on chat messages
enum { k_cchFriendChatMsgMax = 32 * 1024 };

// maximum number of characters in a users name
enum { k_cchPersonaNameMax = 128 };

// size limit on chat room or member metadata
const uint32 k_cubChatMetadataMax = 8192;

const int k_cchSystemIMTextMax = 4096;	// upper bound of length of system IM text

// size limit on stat or achievement name (UTF-8 encoded)
enum { k_cchStatNameMax = 128 };

// maximum number of bytes for a leaderboard name (UTF-8 encoded)
enum { k_cchLeaderboardNameMax = 128 };

// maximum number of details int32's storable for a single leaderboard entry
enum { k_cLeaderboardDetailsMax = 64 };

// handle to a single leaderboard
typedef uint64 SteamLeaderboard_t;

// handle to a set of downloaded entries in a leaderboard
typedef uint64 SteamLeaderboardEntries_t;

typedef void (*PFNLegacyKeyRegistration)( const char *pchCDKey, const char *pchInstallPath );
typedef bool (*PFNLegacyKeyInstalled)();

const int k_unSteamAccountIDMask = 0xFFFFFFFF;
const int k_unSteamAccountInstanceMask = 0x000FFFFF;

// Special flags for Chat accounts - they go in the top 8 bits
// of the steam ID's "instance", leaving 12 for the actual instances
enum EChatSteamIDInstanceFlags
{
	k_EChatAccountInstanceMask = 0x00000FFF, // top 8 bits are flags

	k_EChatInstanceFlagClan = ( k_unSteamAccountInstanceMask + 1 ) >> 1,	// top bit
	k_EChatInstanceFlagLobby = ( k_unSteamAccountInstanceMask + 1 ) >> 2,	// next one down, etc

	// Max of 8 flags
};

#define STEAM_USING_FILESYSTEM							(0x00000001)
#define STEAM_USING_LOGGING								(0x00000002)
#define STEAM_USING_USERID								(0x00000004)
#define STEAM_USING_ACCOUNT								(0x00000008)
#define STEAM_USING_ALL									(0x0000000f)
#define STEAM_MAX_PATH									(255)
#define STEAM_QUESTION_MAXLEN							(255)
#define STEAM_SALT_SIZE									(8)

#define STEAM_DATE_SIZE									(9)
#define STEAM_TIME_SIZE									(9)
#define STEAM_CARD_NUMBER_SIZE							(17)
#define STEAM_CONFIRMATION_CODE_SIZE					(16)
#define STEAM_CARD_HOLDERNAME_SIZE						(100)
#define STEAM_CARD_APPROVAL_CODE_SIZE					(100)
#define STEAM_CARD_EXPYEAR_SIZE							(4)
#define STEAM_CARD_LASTFOURDIGITS_SIZE					(4)
#define STEAM_CARD_EXPMONTH_SIZE						(2)
#define STEAM_CARD_CVV2_SIZE							(5)
#define STEAM_BILLING_ADDRESS1_SIZE						(128)
#define STEAM_BILLING_ADDRESS2_SIZE						(128)
#define STEAM_BILLING_CITY_SIZE							(50)
#define STEAM_BILLING_ZIP_SIZE							(16)
#define STEAM_BILLING_STATE_SIZE						(32)
#define STEAM_BILLING_COUNTRY_SIZE						(32)
#define STEAM_BILLING_PHONE_SIZE						(20)
#define STEAM_BILLING_EMAIL_SIZE						(100)
#define STEAM_TYPE_OF_PROOF_OF_PURCHASE_SIZE			(20)
#define STEAM_PROOF_OF_PURCHASE_TOKEN_SIZE				(200)
#define STEAM_EXTERNAL_ACCOUNTNAME_SIZE					(100)
#define STEAM_EXTERNAL_ACCOUNTPASSWORD_SIZE				(80)

#define IS_STEAM_ERROR(e) (e.eSteamError != eSteamErrorNone)

typedef unsigned int SteamHandle_t;

typedef void * SteamUserIDTicketValidationHandle_t;

typedef unsigned int SteamCallHandle_t;

#if defined(_MSC_VER)
typedef unsigned __int64	SteamUnsigned64_t;
#else
typedef unsigned long long	SteamUnsigned64_t;
#endif


#ifdef __cplusplus

const SteamHandle_t										STEAM_INVALID_HANDLE = 0;
const SteamCallHandle_t									STEAM_INVALID_CALL_HANDLE = 0;
const SteamUserIDTicketValidationHandle_t				STEAM_INACTIVE_USERIDTICKET_VALIDATION_HANDLE = 0;
const unsigned int										STEAM_USE_LATEST_VERSION = 0xFFFFFFFF;

#else

#define STEAM_INVALID_HANDLE							((SteamHandle_t)(0))
#define STEAM_INVALID_CALL_HANDLE						((SteamCallHandle_t)(0))
#define	STEAM_INACTIVE_USERIDTICKET_VALIDATION_HANDLE	((SteamUserIDTicketValidationHandle_t)(0))
#define STEAM_USE_LATEST_VERSION						(0xFFFFFFFFu);

#endif


// Each Steam instance (licensed Steam Service Provider) has a unique SteamInstanceID_t.
//
// Each Steam instance as its own DB of users.
// Each user in the DB has a unique SteamLocalUserID_t (a serial number, with possible 
// rare gaps in the sequence).

typedef	unsigned short		SteamInstanceID_t;		// MUST be 16 bits

#if defined ( WIN32 )
typedef	unsigned __int64	SteamLocalUserID_t;		// MUST be 64 bits
#else
typedef	unsigned long long	SteamLocalUserID_t;		// MUST be 64 bits
#endif


typedef char SteamPersonalQuestion_t[ STEAM_QUESTION_MAXLEN + 1 ];


//-----------------------------------------------------------------------------
// Purpose: Base values for callback identifiers, each callback must
//			have a unique ID.
//-----------------------------------------------------------------------------
enum ECallbackType
{
	k_iSteamUserCallbacks = 100,
	k_iSteamGameServerCallbacks = 200,
	k_iSteamFriendsCallbacks = 300,
	k_iSteamBillingCallbacks = 400,
	k_iSteamMatchmakingCallbacks = 500,
	k_iSteamContentServerCallbacks = 600,
	k_iSteamUtilsCallbacks = 700,
	k_iClientFriendsCallbacks = 800,
	k_iClientUserCallbacks = 900,
	k_iSteamAppsCallbacks = 1000,
	k_iSteamUserStatsCallbacks = 1100,
	k_iSteamNetworkingCallbacks = 1200,
	k_iClientRemoteStorageCallbacks = 1300,
	k_iSteamUserItemsCallbacks = 1400,
	k_iSteamGameServerItemsCallbacks = 1500,
	k_iClientUtilsCallbacks = 1600,
	k_iSteamGameCoordinatorCallbacks = 1700,
};

#include "EnumString.h"

Begin_Enum_String(ECallbackType)
{
	Enum_String( k_iSteamUserCallbacks);
	Enum_String( k_iSteamGameServerCallbacks );
	Enum_String( k_iSteamFriendsCallbacks );
	Enum_String( k_iSteamBillingCallbacks );
	Enum_String( k_iSteamMatchmakingCallbacks );
	Enum_String( k_iSteamContentServerCallbacks );
	Enum_String( k_iSteamUtilsCallbacks );
	Enum_String( k_iClientFriendsCallbacks );
	Enum_String( k_iClientUserCallbacks );
	Enum_String( k_iSteamAppsCallbacks );
	Enum_String( k_iSteamUserStatsCallbacks );
	Enum_String( k_iSteamNetworkingCallbacks );
	Enum_String( k_iClientRemoteStorageCallbacks );
	Enum_String( k_iSteamUserItemsCallbacks );
	Enum_String( k_iSteamGameServerItemsCallbacks );
	Enum_String( k_iClientUtilsCallbacks );
	Enum_String( k_iSteamGameCoordinatorCallbacks );
}
End_Enum_String;

// steam structs, etc
#include "TSteamElemInfo.h"
#include "TSteamError.h"
#include "TSteamProgress.h"
#include "TSteamAppStats.h"
#include "TSteamUpdateStats.h"
#include "TSteamPaymentCardInfo.h"
#include "TSteamPrepurchaseInfo.h"
#include "TSteamExternalBillingInfo.h"
#include "TSteamSubscriptionBillingInfo.h"
#include "TSteamSubscriptionStats.h"
#include "TSteamSubscription.h"
#include "TSteamApp.h"
#include "TSteamAppLaunchOption.h"
#include "TSteamAppVersion.h"
#include "TSteamSplitLocalUserID.h"
#include "TSteamGlobalUserID.h"
#include "TSteamAppDependencyInfo.h"
#include "TSteamOfflineStatus.h"
#include "TSteamPaymentCardReceiptInfo.h"
#include "TSteamPrepurchaseReceiptInfo.h"
#include "TSteamSubscriptionReceipt.h"
#include "TSteamSubscriptionDiscount.h"
#include "TSteamDiscountQualifier.h"
#include "SteamSalt.h"


// steamclient/api
#include "CSteamID.h"
#include "CGameID.h"

#include "MatchMakingKeyValuePair.h"
#include "servernetadr.h"
#include "gameserveritem.h"
#include "FriendGameInfo.h"
#include "LeaderboardEntry.h"

// structure that contains client callback data
struct CallbackMsg_t
{
	HSteamUser m_hSteamUser;
	int m_iCallback;
	uint8 *m_pubParam;
	int m_cubParam;
};

#endif // STEAMTYPES_H

