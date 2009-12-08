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

#ifndef ECLANRANK_H
#define ECLANRANK_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

enum EClanRank
{
	k_EClanRankNone = 0,
	k_EClanRankOwner = 1,
	k_EClanRankOfficer = 2,
	k_EClanRankMember = 3,
};

Begin_Enum_String( EClanRank )
{
	Enum_String( k_EClanRankNone );
	Enum_String( k_EClanRankOwner );
	Enum_String( k_EClanRankOfficer );
	Enum_String( k_EClanRankMember );
}
End_Enum_String;

#endif // ECLANRANK_H
