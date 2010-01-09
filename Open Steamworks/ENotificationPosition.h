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

#ifndef ENOTIFICATIONPOSITION_H
#define ENOTIFICATIONPOSITION_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

//-----------------------------------------------------------------------------
// Purpose: Possible positions to tell the overlay to show notifications in
//-----------------------------------------------------------------------------
typedef enum ENotificationPosition
{
	k_EPositionTopLeft = 0,
	k_EPositionTopRight = 1,
	k_EPositionBottomLeft = 2,
	k_EPositionBottomRight = 3,
} ENotificationPosition;

Begin_Enum_String(ENotificationPosition)
{
	Enum_String( k_EPositionTopLeft );
	Enum_String( k_EPositionTopRight );
	Enum_String( k_EPositionBottomLeft );
	Enum_String( k_EPositionBottomRight );
}
End_Enum_String(ENotificationPosition);

#endif // ENOTIFICATIONPOSITION_H
