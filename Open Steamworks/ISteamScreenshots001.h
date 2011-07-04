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

#ifndef ISTEAMSCREENSHOTS001_H
#define ISTEAMSCREENSHOTS001_H
#ifdef _WIN32
#pragma once
#endif


#include "SteamTypes.h"
#include "ScreenshotsCommon.h"


abstract_class ISteamScreenshots001
{

public:
	virtual uint32 WriteScreenshot( void *, uint32, int32, int32 ) = 0;
	virtual uint32 AddScreenshotToLibrary( const char *, const char *, int32, int32 ) = 0;

	virtual void TriggerScreenshot() = 0;
	virtual void HookScreenshots( bool ) = 0;

	virtual bool SetLocation( uint32, const char * ) = 0;
	virtual bool TagUser( uint32, CSteamID steamIDUser ) = 0;

};


#endif // ISTEAMSCREENSHOTS001_H
