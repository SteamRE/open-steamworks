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

#ifndef ECONNECTIONPRIORITY_H
#define ECONNECTIONPRIORITY_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

enum EConnectionPriority
{
	k_EConnectionPriorityLow = 0,
	k_EConnectionPriorityMedium = 1,
	k_EConnectionPriorityHigh = 2,
};

Begin_Enum_String( EConnectionPriority )
{
	Enum_String( k_EConnectionPriorityLow );
	Enum_String( k_EConnectionPriorityMedium );
	Enum_String( k_EConnectionPriorityHigh );
}
End_Enum_String;

#endif // ECONNECTIONPRIORITY_H
