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

#ifndef EPERSONACHANGE_H
#define EPERSONACHANGE_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

// used in PersonaStateChange_t::m_nChangeFlags to describe what's changed about a user
// these flags describe what the client has learned has changed recently, so on startup you'll see a name, avatar & relationship change for every friend
enum EPersonaChange
{
	k_EPersonaChangeName		= 0x001,
	k_EPersonaChangeStatus		= 0x002,
	k_EPersonaChangeComeOnline	= 0x004,
	k_EPersonaChangeGoneOffline	= 0x008,
	k_EPersonaChangeGamePlayed	= 0x010,
	k_EPersonaChangeGameServer	= 0x020,
	k_EPersonaChangeAvatar		= 0x040,
	k_EPersonaChangeJoinedSource= 0x080,
	k_EPersonaChangeLeftSource	= 0x100,
	k_EPersonaChangeRelationshipChanged = 0x200,
	k_EPersonaChangeNameFirstSet = 0x400,
};

Begin_Enum_String(EPersonaChange)
{
	Enum_String( k_EPersonaChangeName );
	Enum_String( k_EPersonaChangeStatus );
	Enum_String( k_EPersonaChangeComeOnline );
	Enum_String( k_EPersonaChangeGoneOffline );
	Enum_String( k_EPersonaChangeGamePlayed );
	Enum_String( k_EPersonaChangeGameServer );
	Enum_String( k_EPersonaChangeAvatar );
	Enum_String( k_EPersonaChangeJoinedSource );
	Enum_String( k_EPersonaChangeLeftSource );
	Enum_String( k_EPersonaChangeRelationshipChanged );
	Enum_String( k_EPersonaChangeNameFirstSet );
}
End_Enum_String;

#endif // EPERSONACHANGE_H
