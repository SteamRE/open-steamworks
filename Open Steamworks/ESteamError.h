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

#ifndef ESTEAMERROR_H
#define ESTEAMERROR_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

typedef enum ESteamError
{
	eSteamErrorNone													= 0,
	eSteamErrorUnknown												= 1,
	eSteamErrorLibraryNotInitialized								= 2,
	eSteamErrorLibraryAlreadyInitialized							= 3,
	eSteamErrorConfig												= 4,
	eSteamErrorContentServerConnect									= 5,
	eSteamErrorBadHandle											= 6,
	eSteamErrorHandlesExhausted										= 7,
	eSteamErrorBadArg												= 8,
	eSteamErrorNotFound												= 9,
	eSteamErrorRead													= 10,
	eSteamErrorEOF													= 11,
	eSteamErrorSeek													= 12,
	eSteamErrorCannotWriteNonUserConfigFile							= 13,
	eSteamErrorCacheOpen											= 14,
	eSteamErrorCacheRead											= 15,
	eSteamErrorCacheCorrupted										= 16,
	eSteamErrorCacheWrite											= 17,
	eSteamErrorCacheSession											= 18,
	eSteamErrorCacheInternal										= 19,
	eSteamErrorCacheBadApp											= 20,
	eSteamErrorCacheVersion											= 21,
	eSteamErrorCacheBadFingerPrint									= 22,

	eSteamErrorNotFinishedProcessing								= 23,
	eSteamErrorNothingToDo											= 24,
	eSteamErrorCorruptEncryptedUserIDTicket							= 25,
	eSteamErrorSocketLibraryNotInitialized							= 26,
	eSteamErrorFailedToConnectToUserIDTicketValidationServer		= 27,
	eSteamErrorBadProtocolVersion									= 28,
	eSteamErrorReplayedUserIDTicketFromClient						= 29,
	eSteamErrorReceiveResultBufferTooSmall							= 30,
	eSteamErrorSendFailed											= 31,
	eSteamErrorReceiveFailed										= 32,
	eSteamErrorReplayedReplyFromUserIDTicketValidationServer		= 33,
	eSteamErrorBadSignatureFromUserIDTicketValidationServer			= 34,
	eSteamErrorValidationStalledSoAborted							= 35,
	eSteamErrorInvalidUserIDTicket									= 36,
	eSteamErrorClientLoginRateTooHigh								= 37,
	eSteamErrorClientWasNeverValidated								= 38,
	eSteamErrorInternalSendBufferTooSmall							= 39,
	eSteamErrorInternalReceiveBufferTooSmall						= 40,
	eSteamErrorUserTicketExpired									= 41,
	eSteamErrorCDKeyAlreadyInUseOnAnotherClient						= 42,

	eSteamErrorNotLoggedIn											= 101,
	eSteamErrorAlreadyExists										= 102,
	eSteamErrorAlreadySubscribed									= 103,
	eSteamErrorNotSubscribed										= 104,
	eSteamErrorAccessDenied											= 105,
	eSteamErrorFailedToCreateCacheFile								= 106,
	eSteamErrorCallStalledSoAborted									= 107,
	eSteamErrorEngineNotRunning										= 108,
	eSteamErrorEngineConnectionLost									= 109,
	eSteamErrorLoginFailed											= 110,
	eSteamErrorAccountPending										= 111,
	eSteamErrorCacheWasMissingRetry									= 112,
	eSteamErrorLocalTimeIncorrect									= 113,
	eSteamErrorCacheNeedsDecryption									= 114,
	eSteamErrorAccountDisabled										= 115,
	eSteamErrorCacheNeedsRepair										= 116,
	eSteamErrorRebootRequired										= 117,

	eSteamErrorNetwork												= 200,

	eSteamErrorOffline												= 201,
} ESteamError;

Begin_Enum_String( ESteamError )
{
	Enum_String( eSteamErrorNone );
	Enum_String( eSteamErrorUnknown );
	Enum_String( eSteamErrorLibraryNotInitialized );
	Enum_String( eSteamErrorLibraryAlreadyInitialized );
	Enum_String( eSteamErrorConfig );
	Enum_String( eSteamErrorContentServerConnect );
	Enum_String( eSteamErrorBadHandle );
	Enum_String( eSteamErrorHandlesExhausted );
	Enum_String( eSteamErrorBadArg );
	Enum_String( eSteamErrorNotFound );
	Enum_String( eSteamErrorRead );
	Enum_String( eSteamErrorEOF );
	Enum_String( eSteamErrorSeek );
	Enum_String( eSteamErrorCannotWriteNonUserConfigFile );
	Enum_String( eSteamErrorCacheOpen );
	Enum_String( eSteamErrorCacheRead );
	Enum_String( eSteamErrorCacheCorrupted );
	Enum_String( eSteamErrorCacheWrite );
	Enum_String( eSteamErrorCacheSession );
	Enum_String( eSteamErrorCacheInternal );
	Enum_String( eSteamErrorCacheBadApp );
	Enum_String( eSteamErrorCacheVersion );
	Enum_String( eSteamErrorCacheBadFingerPrint );

	Enum_String( eSteamErrorNotFinishedProcessing );
	Enum_String( eSteamErrorNothingToDo	);
	Enum_String( eSteamErrorCorruptEncryptedUserIDTicket );
	Enum_String( eSteamErrorSocketLibraryNotInitialized );
	Enum_String( eSteamErrorFailedToConnectToUserIDTicketValidationServer );
	Enum_String( eSteamErrorBadProtocolVersion );
	Enum_String( eSteamErrorReplayedUserIDTicketFromClient );
	Enum_String( eSteamErrorReceiveResultBufferTooSmall );
	Enum_String( eSteamErrorSendFailed );
	Enum_String( eSteamErrorReceiveFailed );
	Enum_String( eSteamErrorReplayedReplyFromUserIDTicketValidationServer );
	Enum_String( eSteamErrorBadSignatureFromUserIDTicketValidationServer );
	Enum_String( eSteamErrorValidationStalledSoAborted );
	Enum_String( eSteamErrorInvalidUserIDTicket );
	Enum_String( eSteamErrorClientLoginRateTooHigh );
	Enum_String( eSteamErrorClientWasNeverValidated );
	Enum_String( eSteamErrorInternalSendBufferTooSmall );
	Enum_String( eSteamErrorInternalReceiveBufferTooSmall );
	Enum_String( eSteamErrorUserTicketExpired );
	Enum_String( eSteamErrorCDKeyAlreadyInUseOnAnotherClient );

	Enum_String( eSteamErrorNotLoggedIn );
	Enum_String( eSteamErrorAlreadyExists );
	Enum_String( eSteamErrorAlreadySubscribed );
	Enum_String( eSteamErrorNotSubscribed );
	Enum_String( eSteamErrorAccessDenied );
	Enum_String( eSteamErrorFailedToCreateCacheFile );
	Enum_String( eSteamErrorCallStalledSoAborted );
	Enum_String( eSteamErrorEngineNotRunning );
	Enum_String( eSteamErrorEngineConnectionLost );
	Enum_String( eSteamErrorLoginFailed );
	Enum_String( eSteamErrorAccountPending );
	Enum_String( eSteamErrorCacheWasMissingRetry );
	Enum_String( eSteamErrorLocalTimeIncorrect );
	Enum_String( eSteamErrorCacheNeedsDecryption );
	Enum_String( eSteamErrorAccountDisabled );
	Enum_String( eSteamErrorCacheNeedsRepair );
	Enum_String( eSteamErrorRebootRequired );

	Enum_String( eSteamErrorNetwork );

	Enum_String( eSteamErrorOffline );
}
End_Enum_String( ESteamError );

#endif // ESTEAMERROR_H
