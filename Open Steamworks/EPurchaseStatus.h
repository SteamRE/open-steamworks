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

#ifndef EPURCHASESTATUS_H
#define EPURCHASESTATUS_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"


enum EPurchaseStatus
{
	k_EPurchasePending = 0,
	k_EPurchaseSucceeded = 1,
	k_EPurchaseFailed = 2,
	k_EPurchaseRefunded = 3,
	k_EPurchaseInit = 4,
	k_EPurchaseChargedback = 5,
	k_EPurchaseRevoked = 6,
};

Begin_Enum_String( EPurchaseStatus )
{
	Enum_String( k_EPurchasePending );
	Enum_String( k_EPurchaseSucceeded );
	Enum_String( k_EPurchaseFailed );
	Enum_String( k_EPurchaseRefunded );
	Enum_String( k_EPurchaseInit );
	Enum_String( k_EPurchaseChargedback );
	Enum_String( k_EPurchaseRevoked );
}
End_Enum_String;

#endif // EPURCHASESTATUS_H
