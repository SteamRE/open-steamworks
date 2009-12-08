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

#ifndef EDENYREASON_H
#define EDENYREASON_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

// Result codes to GSHandleClientDeny/Kick
typedef enum
{
	k_EDenyInvalidVersion = 1,
	k_EDenyGeneric = 2,
	k_EDenyNotLoggedOn = 3,
	k_EDenyNoLicense = 4,
	k_EDenyCheater = 5,
	k_EDenyLoggedInElseWhere = 6,
	k_EDenyUnknownText = 7,
	k_EDenyIncompatibleAnticheat = 8,
	k_EDenyMemoryCorruption = 9,
	k_EDenyIncompatibleSoftware = 10,
	k_EDenySteamConnectionLost = 11,
	k_EDenySteamConnectionError = 12,
	k_EDenySteamResponseTimedOut = 13,
	k_EDenySteamValidationStalled = 14,
	k_EDenySteamOwnerLeftGuestUser = 15,
} EDenyReason;

Begin_Enum_String(EDenyReason)
{
	Enum_String( k_EDenyInvalidVersion );
	Enum_String( k_EDenyGeneric );
	Enum_String( k_EDenyNotLoggedOn );
	Enum_String( k_EDenyNoLicense );
	Enum_String( k_EDenyCheater );
	Enum_String( k_EDenyLoggedInElseWhere );
	Enum_String( k_EDenyUnknownText );
	Enum_String( k_EDenyIncompatibleAnticheat );
	Enum_String( k_EDenyMemoryCorruption );
	Enum_String( k_EDenyIncompatibleSoftware );
	Enum_String( k_EDenySteamConnectionLost );
	Enum_String( k_EDenySteamConnectionError );
	Enum_String( k_EDenySteamResponseTimedOut );
	Enum_String( k_EDenySteamValidationStalled );
	Enum_String( k_EDenySteamOwnerLeftGuestUser );
}
End_Enum_String;


#endif // EDENYREASON_H
