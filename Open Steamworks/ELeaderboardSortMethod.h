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

#ifndef ELEADERBOARDSORTMETHOD_H
#define ELEADERBOARDSORTMETHOD_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

// the sort order of a leaderboard
enum ELeaderboardSortMethod
{
	k_ELeaderboardSortMethodNone = 0,
	k_ELeaderboardSortMethodAscending = 1,	// top-score is lowest number
	k_ELeaderboardSortMethodDescending = 2,	// top-score is highest number
};

Begin_Enum_String(ELeaderboardSortMethod)
{
	Enum_String(k_ELeaderboardSortMethodNone);
	Enum_String(k_ELeaderboardSortMethodAscending);
	Enum_String(k_ELeaderboardSortMethodDescending);
}
End_Enum_String;

#endif // ELEADERBOARDSORTMETHOD_H
