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

#ifndef EAUTHSESSIONRESPONSE_H
#define EAUTHSESSIONRESPONSE_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

// Callback values for callback ValidateAuthTicketResponse_t which is a response to BeginAuthSession
typedef enum
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

Begin_Enum_String(EAuthSessionResponse)
{
	Enum_String( k_EAuthSessionResponseOK );							// Steam has verified the user is online, the ticket is valid and ticket has not been reused.
	Enum_String( k_EAuthSessionResponseUserNotConnectedToSteam );		// The user in question is not connected to steam
	Enum_String( k_EAuthSessionResponseNoLicenseOrExpired );			// The license has expired.
	Enum_String( k_EAuthSessionResponseVACBanned );					// The user is VAC banned for this game.
	Enum_String( k_EAuthSessionResponseLoggedInElseWhere );			// The user account has logged in elsewhere and the session containing the game instance has been disconnected.
	Enum_String( k_EAuthSessionResponseVACCheckTimedOut );				// VAC has been unable to perform anti-cheat checks on this user
	Enum_String( k_EAuthSessionResponseAuthTicketCanceled );			// The ticket has been canceled by the issuer
	Enum_String( k_EAuthSessionResponseAuthTicketInvalidAlreadyUsed );	// This ticket has already been used, it is not valid.
	Enum_String( k_EAuthSessionResponseAuthTicketInvalid );			// This ticket is not from a user instance currently connected to steam.
}
End_Enum_String;

#endif // EAUTHSESSIONRESPONSE_H
