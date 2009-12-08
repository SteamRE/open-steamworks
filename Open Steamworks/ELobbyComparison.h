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

#ifndef ELOBBYCOMPARISON_H
#define ELOBBYCOMPARISON_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

enum ELobbyComparison
{
	k_ELobbyComparisonEqualToOrLessThan = -2,
	k_ELobbyComparisonLessThan = -1,
	k_ELobbyComparisonEqual = 0,
	k_ELobbyComparisonGreaterThan = 1,
	k_ELobbyComparisonEqualToOrGreaterThan = 2,
};

Begin_Enum_String(ELobbyComparison)
{
	Enum_String(k_ELobbyComparisonEqualToOrLessThan);
	Enum_String(k_ELobbyComparisonLessThan);
	Enum_String(k_ELobbyComparisonEqual);
	Enum_String(k_ELobbyComparisonGreaterThan);
	Enum_String(k_ELobbyComparisonEqualToOrGreaterThan);
}
End_Enum_String;

#endif // ELOBBYCOMPARISON_H
