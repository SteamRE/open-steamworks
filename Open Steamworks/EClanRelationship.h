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

#ifndef ECLANRELATIONSHIP_H
#define ECLANRELATIONSHIP_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

enum EClanRelationship
{
	eClanRelationshipNone = 0,
	eClanRelationshipBlocked = 1,
	eClanRelationshipInvited = 2,
	eClanRelationshipMember = 3,
	eClanRelationshipKicked = 4,
};

Begin_Enum_String( EClanRelationship )
{
	Enum_String( eClanRelationshipNone );
	Enum_String( eClanRelationshipBlocked );
	Enum_String( eClanRelationshipInvited );
	Enum_String( eClanRelationshipMember );
	Enum_String( eClanRelationshipKicked );
}
End_Enum_String;

#endif // ECLANRELATIONSHIP_H
