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

#ifndef ISTEAMAPPLIST001_H
#define ISTEAMAPPLIST001_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "AppsCommon.h"

//-----------------------------------------------------------------------------
// Purpose: interface to app data
//-----------------------------------------------------------------------------
abstract_class ISteamAppList001
{
public:
	virtual unknown_ret GetNumInstalledApps() = 0;
	virtual unknown_ret GetInstalledApps( uint32 * puUnk, uint32 uUnk ) = 0;
	virtual unknown_ret GetAppName( uint32 uUnk, char * pUnk, int32 iUnk ) = 0;
	virtual unknown_ret GetAppInstallDir( uint32 uUnk, char * pUnk, int32 iUnk ) = 0;
	virtual unknown_ret GetAppBuildId( uint32 uUnk ) = 0;
};


#endif // ISTEAMAPPS001_H
