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

#ifndef ESTEAMNOTIFICATIONCALLBACKEVENT_H
#define ESTEAMNOTIFICATIONCALLBACKEVENT_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

typedef enum ESteamNotify
{
	eSteamNotifyTicketsWillExpire = 0,
	eSteamNotifyAccountInfoChanged = 1,
	eSteamNotifyContentDescriptionChanged = 2,
	eSteamNotifyPleaseShutdown = 3,
	eSteamNotifyNewContentServer = 4,
	eSteamNotifySubscriptionStatusChanged = 5,
	eSteamNotifyContentServerConnectionLost = 6,
	eSteamNotifyCacheLoadingCompleted = 7,
	eSteamNotifyCacheNeedsDecryption = 8,
	eSteamNotifyCacheNeedsRepair = 9,
	eSteamNotifyAppDownloading = 10,
	eSteamNotifyAppDownloadingPaused = 11,
} ESteamNotify;



Begin_Enum_String( ESteamNotify )
{
	Enum_String( eSteamNotifyTicketsWillExpire );
	Enum_String( eSteamNotifyAccountInfoChanged );
	Enum_String( eSteamNotifyContentDescriptionChanged );
	Enum_String( eSteamNotifyPleaseShutdown );
	Enum_String( eSteamNotifyNewContentServer );
	Enum_String( eSteamNotifySubscriptionStatusChanged );
	Enum_String( eSteamNotifyContentServerConnectionLost );
	Enum_String( eSteamNotifyCacheLoadingCompleted );
	Enum_String( eSteamNotifyCacheNeedsDecryption );
	Enum_String( eSteamNotifyCacheNeedsRepair );
	Enum_String( eSteamNotifyAppDownloading );
	Enum_String( eSteamNotifyAppDownloadingPaused );
}
End_Enum_String( ESteamNotify );



#endif // ESTEAMNOTIFICATIONCALLBACKEVENT_H
