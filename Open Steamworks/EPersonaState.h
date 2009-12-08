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

#ifndef EPERSONASTATE_H
#define EPERSONASTATE_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

//-----------------------------------------------------------------------------
// Purpose: list of states a friend can be in
//-----------------------------------------------------------------------------
enum EPersonaState
{
	k_EPersonaStateOffline = 0,			// friend is not currently logged on
	k_EPersonaStateOnline = 1,			// friend is logged on
	k_EPersonaStateBusy = 2,			// user is on, but busy
	k_EPersonaStateAway = 3,			// auto-away feature
	k_EPersonaStateSnooze = 4,			// auto-away for a long time
	k_EPersonaStateMax,
};

Begin_Enum_String( EPersonaState )
{
	Enum_String( k_EPersonaStateOffline );	// friend is not currently logged on
	Enum_String( k_EPersonaStateOnline );	// friend is logged on
	Enum_String( k_EPersonaStateBusy );		// user is on, but busy
	Enum_String( k_EPersonaStateAway );		// auto-away feature
	Enum_String( k_EPersonaStateSnooze );	// auto-away for a long time
	Enum_String( k_EPersonaStateMax );
}
End_Enum_String;


#endif // EPERSONASTATE_H
