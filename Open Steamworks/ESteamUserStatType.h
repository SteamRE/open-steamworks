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

#ifndef ESTEAMUSERSTATTYPE_H
#define ESTEAMUSERSTATTYPE_H
#ifdef _WIN32
#pragma once
#endif


#include "EnumString.h"

//-----------------------------------------------------------------------------
// types of user game stats fields
// WARNING: DO NOT RENUMBER EXISTING VALUES - STORED IN DATABASE
//-----------------------------------------------------------------------------
enum ESteamUserStatType
{
	k_ESteamUserStatTypeINVALID = 0,
	k_ESteamUserStatTypeINT = 1,
	k_ESteamUserStatTypeFLOAT = 2,
	// Read as FLOAT, set with count / session length
	k_ESteamUserStatTypeAVGRATE = 3,
	k_ESteamUserStatTypeACHIEVEMENTS = 4,
	k_ESteamUserStatTypeGROUPACHIEVEMENTS = 5,
};

Begin_Enum_String(ESteamUserStatType)
{
	Enum_String( k_ESteamUserStatTypeINVALID );
	Enum_String( k_ESteamUserStatTypeINT );
	Enum_String( k_ESteamUserStatTypeFLOAT );
	// Read as FLOAT, set with count / session length
	Enum_String( k_ESteamUserStatTypeAVGRATE );
	Enum_String( k_ESteamUserStatTypeACHIEVEMENTS );
	Enum_String( k_ESteamUserStatTypeGROUPACHIEVEMENTS );
}
End_Enum_String;

#endif // ESTEAMUSERSTATTYPE_H
