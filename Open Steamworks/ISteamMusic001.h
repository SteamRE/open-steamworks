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

#ifndef ISTEAMMUSIC001_H
#define ISTEAMMUSIC001_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "MusicCommon.h"

abstract_class ISteamMusic001
{
	virtual unknown_ret BIsEnabled() = 0;
	virtual unknown_ret BIsPlaying() = 0;
	virtual unknown_ret GetPlaybackStatus() = 0;
	virtual unknown_ret Play() = 0;
	virtual unknown_ret Pause() = 0;
	virtual unknown_ret PlayPrevious() = 0;
	virtual unknown_ret PlayNext() = 0;
	virtual unknown_ret SerVolume( float fUnk ) = 0;
	virtual unknown_ret GetVolume() = 0;
};

#endif // ISTEAMMUSIC001_H
