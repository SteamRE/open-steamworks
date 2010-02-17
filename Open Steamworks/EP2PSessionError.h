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

#ifndef EP2PSESSIONERROR_H
#define EP2PSESSIONERROR_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

// list of possible errors returned by SendP2PPacket() API
// these will be posted in the P2PSessionConnectFail_t callback
typedef enum EP2PSessionError
{
	k_EP2PSessionErrorNone = 0,
	k_EP2PSessionErrorNotRunningApp = 1,			// target is not running the same game
	k_EP2PSessionErrorNoRightsToApp = 2,			// local user doesn't own the app that is running
	k_EP2PSessionErrorDestinationNotLoggedIn = 3,	// target user isn't connected to Steam
	k_EP2PSessionErrorTimeout = 4,					// target isn't responding, perhaps not calling AcceptP2PSessionWithUser()
} EP2PSessionError;

Begin_Enum_String( EP2PSessionError )
{
	Enum_String( k_EP2PSessionErrorNone );
	Enum_String( k_EP2PSessionErrorNotRunningApp );			// target is not running the same game
	Enum_String( k_EP2PSessionErrorNoRightsToApp );			// local user doesn't own the app that is running
	Enum_String( k_EP2PSessionErrorDestinationNotLoggedIn );	// target user isn't connected to Steam
	Enum_String( k_EP2PSessionErrorTimeout );				// target isn't responding, perhaps not calling AcceptP2PSessionWithUser()
}
End_Enum_String( EP2PSessionError );

#endif // EP2PSESSIONERROR_H
