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

#ifndef EAPPSTATE_H
#define EAPPSTATE_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

enum EAppState
{
	k_EAppStateDownloading = 0,
	k_EAppStatePaused = 1,
	k_EAppStateDownloadComplete = 2,
};

Begin_Enum_String( EAppState )
{
	Enum_String( k_EAppStateDownloading );
	Enum_String( k_EAppStatePaused );
	Enum_String( k_EAppStateDownloadComplete );
}
End_Enum_String;

#endif // EAPPSTATE_H
