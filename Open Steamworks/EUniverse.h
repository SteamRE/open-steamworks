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

#ifndef EUNIVERSE_H
#define EUNIVERSE_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

// Steam universes.  Each universe is a self-contained Steam instance.
enum EUniverse
{
	k_EUniverseInvalid = 0,
	k_EUniversePublic = 1,
	k_EUniverseBeta = 2,
	k_EUniverseInternal = 3,
	k_EUniverseDev = 4,
	k_EUniverseRC = 5,

	k_EUniverseMax
};

Begin_Enum_String(EUniverse)
{
	Enum_String( k_EUniverseInvalid );
	Enum_String( k_EUniversePublic );
	Enum_String( k_EUniverseBeta );
	Enum_String( k_EUniverseInternal );
	Enum_String( k_EUniverseDev );
	Enum_String( k_EUniverseRC );

	Enum_String( k_EUniverseMax );
}
End_Enum_String;

#endif // EUNIVERSE_H
