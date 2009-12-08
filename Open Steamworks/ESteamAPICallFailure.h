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

#ifndef ESTEAMAPICALLFAILURE_H
#define ESTEAMAPICALLFAILURE_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

// Steam API call failure results
enum ESteamAPICallFailure
{
	k_ESteamAPICallFailureNone = -1,			// no failure
	k_ESteamAPICallFailureSteamGone = 0,		// the local Steam process has gone away
	k_ESteamAPICallFailureNetworkFailure = 1,	// the network connection to Steam has been broken, or was already broken
	// SteamServersDisconnected_t callback will be sent around the same time
	// SteamServersConnected_t will be sent when the client is able to talk to the Steam servers again
	k_ESteamAPICallFailureInvalidHandle = 2,	// the SteamAPICall_t handle passed in no longer exists
	k_ESteamAPICallFailureMismatchedCallback = 3,// GetAPICallResult() was called with the wrong callback type for this API call
};

Begin_Enum_String( ESteamAPICallFailure )
{
	Enum_String( k_ESteamAPICallFailureNone );			// no failure
	Enum_String( k_ESteamAPICallFailureSteamGone );		// the local Steam process has gone away
	Enum_String( k_ESteamAPICallFailureNetworkFailure );	// the network connection to Steam has been broken, or was already broken
	// SteamServersDisconnected_t callback will be sent around the same time
	// SteamServersConnected_t will be sent when the client is able to talk to the Steam servers again
	Enum_String( k_ESteamAPICallFailureInvalidHandle );	// the SteamAPICall_t handle passed in no longer exists
	Enum_String( k_ESteamAPICallFailureMismatchedCallback );// GetAPICallResult() was called with the wrong callback type for this API call
}
End_Enum_String;


#endif // ESTEAMAPICALLFAILURE_H
