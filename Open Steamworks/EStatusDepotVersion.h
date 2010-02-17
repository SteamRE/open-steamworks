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

#ifndef ESTATUSDEPOTVERSION_H
#define ESTATUSDEPOTVERSION_H
#ifdef _WIN32
#pragma once
#endif


#include "EnumString.h"


//-----------------------------------------------------------------------------
// Purpose: Status of a given depot version, these are stored in the DB, don't renumber
//-----------------------------------------------------------------------------
typedef enum EStatusDepotVersion
{
	k_EStatusDepotVersionInvalid = 0,
	k_EStatusDepotVersionCompleteDisabled = 1,
	k_EStatusDepotVersionCompleteEnabledBeta = 2,
	k_EStatusDepotVersionCompleteEnabledPublic = 3,
} EStatusDepotVersion;

Begin_Enum_String( EStatusDepotVersion )
{
	Enum_String( k_EStatusDepotVersionInvalid );
	Enum_String( k_EStatusDepotVersionCompleteDisabled );
	Enum_String( k_EStatusDepotVersionCompleteEnabledBeta );
	Enum_String( k_EStatusDepotVersionCompleteEnabledPublic );
}
End_Enum_String(EChatRoomEnterResponse);

#endif // ESTATUSDEPOTVERSION_H
