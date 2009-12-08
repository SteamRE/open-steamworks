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

#ifndef ELICENSEFLAGS_H
#define ELICENSEFLAGS_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

// Flags for licenses - BITS
enum ELicenseFlags
{
	k_ELicenseFlagRenew = 0x01,				// Renew this license next period
	k_ELicenseFlagRenewalFailed = 0x02,		// Auto-renew failed
	k_ELicenseFlagPending = 0x04,			// Purchase or renewal is pending
	k_ELicenseFlagExpired = 0x08,			// Regular expiration (no renewal attempted)
	k_ELicenseFlagCancelledByUser = 0x10,	// Cancelled by the user
	k_ELicenseFlagCancelledByAdmin = 0x20,	// Cancelled by customer support
};

Begin_Enum_String(ELicenseFlags)
{
	Enum_String( k_ELicenseFlagRenew );				// Renew this license next period
	Enum_String( k_ELicenseFlagRenewalFailed );		// Auto-renew failed
	Enum_String( k_ELicenseFlagPending );			// Purchase or renewal is pending
	Enum_String( k_ELicenseFlagExpired );			// Regular expiration (no renewal attempted)
	Enum_String( k_ELicenseFlagCancelledByUser );	// Cancelled by the user
	Enum_String( k_ELicenseFlagCancelledByAdmin );	// Cancelled by customer support
}
End_Enum_String;

#endif // ELICENSEFLAGS_H
