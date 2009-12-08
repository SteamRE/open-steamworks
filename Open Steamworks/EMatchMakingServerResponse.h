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

#ifndef EMATCHMAKINGSERVERRESPONSE_H
#define EMATCHMAKINGSERVERRESPONSE_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

enum EMatchMakingServerResponse
{
	eServerResponded = 0,
	eServerFailedToRespond,
	eNoServersListedOnMasterServer // for the Internet query type, returned in response callback if no servers of this type match
};

Begin_Enum_String(EMatchMakingServerResponse)
{
	Enum_String( eServerResponded );
	Enum_String( eServerFailedToRespond );
	Enum_String( eNoServersListedOnMasterServer );
}
End_Enum_String;

#endif // EMATCHMAKINGSERVERRESPONSE_H
