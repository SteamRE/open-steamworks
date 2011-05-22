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

#ifdef CLANG
	#define S_API extern "C"
	
	typedef unsigned int errno_t;
	typedef unsigned int size_t;
	typedef unsigned char byte;
	
	#define NULL 0
	
#elif _WIN32
	
	#ifndef _CRT_SECURE_NO_WARNINGS
		#define _CRT_SECURE_NO_WARNINGS // we don't use unsafe functions unsafely!
	#endif

	#include <sdkddkver.h>
	#include <windows.h>

	#undef SendMessage // for ISteamGameCoordinator001 to work right..
	#undef CreateProcess // for ISteam2Bridge

	#if defined( STEAM_API_EXPORTS )
	#define S_API extern "C" __declspec( dllexport ) 
	#else
	#define S_API extern "C" __declspec( dllimport ) 
	#endif // STEAM_API_EXPORTS
#else

	#include <dlfcn.h> // dlopen,dlclose, et al
	#include <unistd.h>
	#include <arpa/inet.h>
	#include <string.h>

	#define HMODULE void *
	#define GetProcAddress dlsym


	#define S_API extern "C"

	#ifndef __cdecl
		#define __cdecl __attribute__((__cdecl__))
	#endif

	// mac doesn't have errno_t ??
	typedef unsigned int errno_t;
	typedef unsigned char byte;

#endif

// this is an MSVC project.. but for the same of supporting other compilers we have to jump through hoops
#if !defined(_MSC_VER) && !defined(CLANG)
	#define sprintf_s snprintf
	inline void _strcpy_s(char *dest, size_t len, const char *source) { strncpy(dest, source, len); };
#else
	#define _strcpy_s strcpy_s
#endif


#define STEAM_CALL __cdecl

// Steam-specific types. Defined here so this header file can be included in other code bases.
#if !defined(WCHARTYPES_H) && !defined(CLANG)
typedef unsigned char uint8;
#endif

#if defined( __GNUC__ ) && !defined(POSIX)
	#if __GNUC__ < 4
		#error "Steamworks requires GCC 4.X (4.2 or 4.4 have been tested)"
	#endif
	#define POSIX 1
#endif

#if defined(__x86_64__) || defined(_WIN64)
#define X64BITS
#endif

typedef unsigned char uint8;
typedef signed char int8;

#if defined( _WIN32 ) && !defined(CLANG)

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

#ifndef abstract_class
	#ifndef _MSC_VER
		#define abstract_class class
	#else
		#define abstract_class class __declspec( novtable )
	#endif
#endif

// steamclient/api
#include "EAccountType.h"
#include "EChatMemberStateChange.h"
#include "ELobbyType.h"
#include "ENotificationPosition.h"
#include "EPersonalQuestion.h"
#include "EResult.h"
#include "EUniverse.h"
#include "EServerMode.h"

// these is outside NO_STEAM because external things use it
#include "ESteamError.h"
#include "ESteamNotify.h"

#ifndef NO_STEAM
// steam
#include "ESteamSeekMethod.h"
#include "ESteamBufferMethod.h"
#include "ESteamFindFilter.h"
#include "ESteamSubscriptionBillingInfoType.h"
#include "ESteamPaymentCardType.h"
#include "ESteamAppUpdateStatsQueryType.h"
#include "ESteamSubscriptionStatus.h"
#include "ESteamServerType.h"
#endif // NO_STEAM


typedef void* (*CreateInterfaceFn)( const char *pName, int *pReturnCode );
typedef void* (*FactoryFn)( const char *pName );
typedef void* (*InstantiateInterfaceFn)( void );

typedef void  (*SteamAPIWarningMessageHook_t)(int hpipe, const char *message);
typedef void (*KeyValueIteratorCallback_t)(const char* key, const char* value, void* kv);

typedef void (*SteamNotificationCallback_t)(ESteamNotify eEvent, unsigned int nData);

typedef bool (*SteamBGetCallbackFn)( int hpipe, void *pCallbackMsg );
typedef void (*SteamFreeLastCallbackFn)( int hpipe );
typedef bool (*SteamGetAPICallResultFn)( int hpipe, uint64 hSteamAPICall, void* pCallback, int cubCallback, int iCallbackExpected, bool* pbFailed );

//-----------------------------------------------------------------------------
// Purpose: Passed as argument to SteamAPI_UseBreakpadCrashHandler to enable optional callback
//  just before minidump file is captured after a crash has occurred.  (Allows app to append additional comment data to the dump, etc.)
//-----------------------------------------------------------------------------
typedef void (*PFNPreMinidumpCallback)(void *context);

//-----------------------------------------------------------------------------
// Purpose: Used by ICrashHandler interfaces to reference particular installed crash handlers
//-----------------------------------------------------------------------------
typedef void *BREAKPAD_HANDLE;
#define BREAKPAD_INVALID_HANDLE (BREAKPAD_HANDLE)0 

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

//-----------------------------------------------------------------------------
// GID (GlobalID) stuff
// This is a globally unique identifier.  It's guaranteed to be unique across all
// racks and servers for as long as a given universe persists.
//-----------------------------------------------------------------------------
// NOTE: for GID parsing/rendering and other utils, see gid.h
typedef uint64 GID_t;

const GID_t k_GIDNil = 0xffffffffffffffffull;

// For convenience, we define a number of types that are just new names for GIDs
typedef GID_t JobID_t;			// Each Job has a unique ID
typedef GID_t TxnID_t;			// Each financial transaction has a unique ID

const GID_t k_TxnIDNil = k_GIDNil;
const GID_t k_TxnIDUnknown = 0;


// this is baked into client messages and interfaces as an int, 
// make sure we never break this.
typedef uint32 PackageId_t;
const PackageId_t k_uPackageIdFreeSub = 0x0;
const PackageId_t k_uPackageIdInvalid = 0xFFFFFFFF;
const PackageId_t k_uPackageIdWallet = -2;
const PackageId_t k_uPackageIdMicroTxn = -3;

// this is baked into client messages and interfaces as an int, 
// make sure we never break this.
typedef uint32 AppId_t;
const AppId_t k_uAppIdInvalid = 0x0;
const AppId_t k_nGameIDNotepad = 65535;
const AppId_t k_nGameIDCSSTestApp = 65534;
const AppId_t k_nGameIDDRMTestApp_Static = 6710;
const AppId_t k_nGameIDDRMTestApp_Blob = 6711;
const AppId_t k_nGameIDDRMTestApp_Secrets = 6712;
const AppId_t k_nGameIDDRMTestApp_SDK = 6713;
const AppId_t k_nGameIDWinUI = 7;
const AppId_t k_nGameIDWinUI2 = 8;
const AppId_t k_nGameIDCS = 10;
const AppId_t k_nGameIDTFC = 20;
const AppId_t k_nGameIDDOD = 30;
const AppId_t k_nGameIDDMC = 40;
const AppId_t k_nGameIDOpFor = 50;
const AppId_t k_nGameIDRicochet = 60;
const AppId_t k_nGameIDHL1 = 70;
const AppId_t k_nGameIDCZero = 80;
const AppId_t k_nGameIDCSBeta = 150;
const AppId_t k_nGameIDBaseSourceSDK = 215;
const AppId_t k_nGameIDHL2 = 220;
const AppId_t k_nGameIDCSS = 240;
const AppId_t k_nDepotHL2Buka = 235;
const AppId_t k_nGameHL1SRC = 280;
const AppId_t k_nGameDRMTest = 199;
const AppId_t k_nGameIDDODSRC = 300;
const AppId_t k_nGameIDHL2DM = 320;
const AppId_t k_nGameIDPortal = 400;
const AppId_t k_nGameIDHL2EP2 = 420;
const AppId_t k_nGameIDTF2 = 440;
const AppId_t k_nGameIDL4D = 500;
const AppId_t k_nGameIDL4DDemo = 530;
const AppId_t k_nGameIDL4D2 = 550;
const AppId_t k_nGameIDRedOrchestra = 1200;
const AppId_t k_nGameIDRedOrchestraBeta = 1210;
const AppId_t k_nGameIDKillingFloor = 1250;
const AppId_t k_nGameIDSin1 = 1309;
const AppId_t k_nGameIDEarth2160 = 1900;
const AppId_t k_nGameIDTheShip = 2400;
const AppId_t k_nGameIDTheShipBeta = 2410;
const AppId_t k_nGameIDDarkMessiahSP = 2100;
const AppId_t k_nGameIDDarkMessiahMPBeta = 2110;
const AppId_t k_nGameIDDarkMessiahMP = 2115;
const AppId_t k_nGameIDDarkMessiahSPDemo = 2120;
const AppId_t k_nGameIDDarkMessiahFix = 2130;
const AppId_t k_nGameRaceWTCC = 4230;
const AppId_t k_nGameIDLostPlanetOld = 6500;
const AppId_t k_nGameIDLostPlanet = 6510;
const AppId_t k_nGameIDNBA2K9 = 7740;
const AppId_t k_nGameIDCallofDuty4 = 7940;
const AppId_t k_nMLBFrontOfficeManager = 7780;
const AppId_t k_nGameIDEmpireTotalWar = 10500;
const AppId_t k_nGameCSSOnline = 11600;
const AppId_t k_nGameIDFirstSource = 200;
const AppId_t k_nGameIDLastSource = 999;
const AppId_t k_nGameIDFirstGoldSource = 10;
const AppId_t k_nGameIDLastGoldSource = 199;
const AppId_t k_nGameIDFirstNonSource = 1000;
const AppId_t k_nGameIDMax = 2147483647;
const AppId_t k_nGameIDStress = 30020;
const AppId_t k_nGameIDGCTest = 30100;

typedef enum ShareType_t
{
	SHARE_STOPIMMEDIATELY = 0,
	SHARE_RATIO = 1,
	SHARE_MANUAL = 2,
} ShareType_t;

// this is baked into client messages and interfaces as an int, 
// make sure we never break this.  AppIds and DepotIDs also presently
// share the same namespace, but since we'd like to change that in the future
// I've defined it seperately here.
typedef uint32 DepotId_t;
const DepotId_t k_uDepotIdInvalid = 0x0;

typedef int HVoiceCall;


// RTime32
// We use this 32 bit time representing real world time.
// It offers 1 second resolution beginning on January 1, 1970 (Unix time)
typedef uint32 RTime32;
const RTime32 k_RTime32Nil = 0;
const RTime32 k_RTime32MinValid = 10;
const RTime32 k_RTime32Infinite = 2147483647;

typedef uint32 CellID_t;
const CellID_t k_uCellIDInvalid = 0xFFFFFFFF;

// handle to a Steam API call
typedef uint64 SteamAPICall_t;
const SteamAPICall_t k_uAPICallInvalid = 0x0;

// handle to a communication pipe to the Steam client
typedef int32 HSteamPipe;
// handle to single instance of a steam user
typedef int32 HSteamUser;
// reference to a steam call, to filter results by
typedef int32 HSteamCall;

//-----------------------------------------------------------------------------
// Typedef for handle type you will receive when requesting server list.
//-----------------------------------------------------------------------------
typedef void* HServerListRequest;

// return type of GetAuthSessionTicket
typedef uint32 HAuthTicket;
const HAuthTicket k_HAuthTicketInvalid = 0;

typedef int HNewItemRequest;
typedef uint64 ItemID;

typedef uint32 HTTPRequestHandle;

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
const uint32 k_cchFriendChatMsgMax = 32 * 1024;

// maximum number of characters in a user's name. Two flavors; one for UTF-8 and one for UTF-16.
// The UTF-8 version has to be very generous to accomodate characters that get large when encoded
// in UTF-8.
enum
{
	k_cchPersonaNameMax = 128,
	k_cwchPersonaNameMax = 32,
};

// size limit on chat room or member metadata
const uint32 k_cubChatMetadataMax = 8192;

const int k_cchSystemIMTextMax = 4096;	// upper bound of length of system IM text

// size limit on stat or achievement name (UTF-8 encoded)
const int k_cchStatNameMax = 128;

// maximum number of bytes for a leaderboard name (UTF-8 encoded)
const int k_cchLeaderboardNameMax = 128;

// maximum number of details int32's storable for a single leaderboard entry
const int k_cLeaderboardDetailsMax = 64;

// handle to a single leaderboard
typedef uint64 SteamLeaderboard_t;

// handle to a set of downloaded entries in a leaderboard
typedef uint64 SteamLeaderboardEntries_t;

typedef void (*PFNLegacyKeyRegistration)( const char *pchCDKey, const char *pchInstallPath );
typedef bool (*PFNLegacyKeyInstalled)();

const unsigned int k_unSteamAccountIDMask = 0xFFFFFFFF;
const unsigned int k_unSteamAccountInstanceMask = 0x000FFFFF;
// we allow 2 simultaneous user account instances right now, 1= desktop, 2 = console, 0 = all
const unsigned int k_unSteamUserDesktopInstance = 1;	 
const unsigned int k_unSteamUserConsoleInstance = 2;

// Special flags for Chat accounts - they go in the top 8 bits
// of the steam ID's "instance", leaving 12 for the actual instances
enum EChatSteamIDInstanceFlags
{
	k_EChatAccountInstanceMask = 0x00000FFF, // top 8 bits are flags

	k_EChatInstanceFlagClan = ( k_unSteamAccountInstanceMask + 1 ) >> 1,	// top bit
	k_EChatInstanceFlagLobby = ( k_unSteamAccountInstanceMask + 1 ) >> 2,	// next one down, etc
	k_EChatInstanceFlagMMSLobby = ( k_unSteamAccountInstanceMask + 1 ) >> 3,	// next one down, etc

	// Max of 8 flags
};

// A handle to a piece of user generated content
typedef uint64 UGCHandle_t;
const UGCHandle_t k_UGCHandleInvalid = 0xffffffffffffffffull;

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
#define STEAM_CONFIRMATION_CODE_SIZE					(22)
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

#if defined ( WIN32 ) && !defined(CLANG)
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
	k_iSteamGameServerStatsCallbacks = 1800,
	k_iSteam2AsyncCallbacks = 1900,
	k_iSteamGameStatsCallbacks = 2000,
	k_iClientHTTPCallbacks = 2100
};


#ifndef NO_STEAM
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
#endif // NO_STEAM


// steamclient/api
#include "CSteamID.h"
#include "CGameID.h"

#include "MatchMakingKeyValuePair.h"
#include "servernetadr.h"
#include "gameserveritem.h"
#include "FriendGameInfo.h"

// structure that contains client callback data
struct CallbackMsg_t
{
	HSteamUser m_hSteamUser;
	int m_iCallback;
	uint8 *m_pubParam;
	int m_cubParam;
};

#endif // STEAMTYPES_H

