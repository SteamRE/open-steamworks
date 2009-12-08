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

#ifndef ESYSTEMIMTYPE_H
#define ESYSTEMIMTYPE_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

// Type of system IM.  The client can use this to do special UI handling in specific circumstances
enum ESystemIMType
{
	k_ESystemIMRawText = 0,
	k_ESystemIMInvalidCard = 1,
	k_ESystemIMRecurringPurchaseFailed = 2,
	k_ESystemIMCardWillExpire = 3,
	k_ESystemIMSubscriptionExpired = 4,

	//
	k_ESystemIMTypeMax
};

Begin_Enum_String( ESystemIMType )
{
	Enum_String( k_ESystemIMRawText );
	Enum_String( k_ESystemIMInvalidCard );
	Enum_String( k_ESystemIMRecurringPurchaseFailed );
	Enum_String( k_ESystemIMCardWillExpire );
	Enum_String( k_ESystemIMSubscriptionExpired );
}
End_Enum_String;

#endif
