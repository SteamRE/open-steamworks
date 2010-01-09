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

#ifndef EDEPOTBUILDSTATUS_H
#define EDEPOTBUILDSTATUS_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"


typedef enum EDepotBuildStatus
{
	k_EDepotBuildStatusInvalid = -1,
	k_EDepotBuildStatusFailed = 0,
	k_EDepotBuildStatusProcessingConfig = 1,
	k_EDepotBuildStatusProcessingData = 2,
	k_EDepotBuildStatusUploadingData = 3,
	k_EDepotBuildStatusCompleted = 4,
}  EDepotBuildStatus;

Begin_Enum_String( EDepotBuildStatus )
{
	Enum_String( k_EDepotBuildStatusInvalid );
	Enum_String( k_EDepotBuildStatusFailed );
	Enum_String( k_EDepotBuildStatusProcessingConfig );
	Enum_String( k_EDepotBuildStatusProcessingData );
	Enum_String( k_EDepotBuildStatusUploadingData );
	Enum_String( k_EDepotBuildStatusCompleted );
}
End_Enum_String( EDepotBuildStatus );

#endif // EDEPOTBUILDSTATUS_H
