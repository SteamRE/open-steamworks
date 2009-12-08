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

#ifndef EAPPUSAGEEVENT_H
#define EAPPUSAGEEVENT_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

enum EAppUsageEvent
{
	k_EAppUsageEventGameLaunch = 1,
	k_EAppUsageEventGameLaunchTrial = 2,
	k_EAppUsageEventMedia = 3,
	k_EAppUsageEventPreloadStart = 4,
	k_EAppUsageEventPreloadFinish = 5,
	k_EAppUsageEventMarketingMessageView = 6,	// deprecated, do not use
	k_EAppUsageEventInGameAdViewed = 7,
	k_EAppUsageEventGameLaunchFreeWeekend = 8,
};

Begin_Enum_String( EAppUsageEvent )
{
	Enum_String( k_EAppUsageEventGameLaunch );
	Enum_String( k_EAppUsageEventGameLaunchTrial );
	Enum_String( k_EAppUsageEventMedia );
	Enum_String( k_EAppUsageEventPreloadStart );
	Enum_String( k_EAppUsageEventPreloadFinish );
	Enum_String( k_EAppUsageEventMarketingMessageView );	// deprecated, do not use
	Enum_String( k_EAppUsageEventInGameAdViewed );
	Enum_String( k_EAppUsageEventGameLaunchFreeWeekend );
}
End_Enum_String;


#endif // EAPPUSAGEEVENT_H
