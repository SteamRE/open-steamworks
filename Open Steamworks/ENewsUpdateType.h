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

#ifndef ENEWSUPDATETYPE_H
#define ENEWSUPDATETYPE_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

// Enum for the types of news push items you can get
enum ENewsUpdateType
{
	k_EAppNews = 0,	 // news about a particular app
	k_ESteamAds = 1, // Marketing messages
	k_ESteamNews = 2, // EJ's corner and the like
	k_ECDDBUpdate = 3, // backend has a new CDDB for you to load
	k_EClientUpdate = 4,	// new version of the steam client is available
};

Begin_Enum_String(ENewsUpdateType)
{
	Enum_String( k_EAppNews );
	Enum_String( k_ESteamAds );
	Enum_String( k_ESteamNews );
	Enum_String( k_ECDDBUpdate );
	Enum_String( k_EClientUpdate );
}
End_Enum_String;

#endif
