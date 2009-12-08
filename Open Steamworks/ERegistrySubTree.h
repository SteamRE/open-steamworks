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

#ifndef EREGISTRYSUBTREE_H
#define EREGISTRYSUBTREE_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

enum ERegistrySubTree
{
	k_ERegistrySubTreeNews = 0,
	k_ERegistrySubTreeApps = 1,
	k_ERegistrySubTreeSubscriptions = 2,
	k_ERegistrySubTreeGameServers = 3,
	k_ERegistrySubTreeFriends = 4,
	k_ERegistrySubTreeSystem = 5,
};

Begin_Enum_String(ERegistrySubTree)
{
	Enum_String( k_ERegistrySubTreeNews );
	Enum_String( k_ERegistrySubTreeApps );
	Enum_String( k_ERegistrySubTreeSubscriptions );
	Enum_String( k_ERegistrySubTreeGameServers );
	Enum_String( k_ERegistrySubTreeFriends );
	Enum_String( k_ERegistrySubTreeSystem );
}
End_Enum_String;

#endif // EREGISTRYSUBTREE_H
