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

#ifndef ESNETSOCKETCONNECTIONTYPE_H
#define ESNETSOCKETCONNECTIONTYPE_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"


// describes how the socket is currently connected
enum ESNetSocketConnectionType
{
	k_ESNetSocketConnectionTypeNotConnected = 0,
	k_ESNetSocketConnectionTypeUDP = 1,
	k_ESNetSocketConnectionTypeUDPRelay = 2,
};

Begin_Enum_String(ESNetSocketConnectionType)
{
	Enum_String( k_ESNetSocketConnectionTypeNotConnected );
	Enum_String( k_ESNetSocketConnectionTypeUDP );
	Enum_String( k_ESNetSocketConnectionTypeUDPRelay );
}
End_Enum_String;


#endif // ESNETSOCKETCONNECTIONTYPE_H
