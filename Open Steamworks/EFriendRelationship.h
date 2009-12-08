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

#ifndef EFRIENDRELATIONSHIP_H
#define EFRIENDRELATIONSHIP_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

//-----------------------------------------------------------------------------
// Purpose: set of relationships to other users
//-----------------------------------------------------------------------------
enum EFriendRelationship
{
	k_EFriendRelationshipNone = 0,
	k_EFriendRelationshipBlocked = 1,
	k_EFriendRelationshipRequestRecipient = 2,
	k_EFriendRelationshipFriend = 3,
	k_EFriendRelationshipRequestInitiator = 4,
	k_EFriendRelationshipIgnored = 5,
	k_EFriendRelationshipIgnoredFriend = 6,
};

Begin_Enum_String( EFriendRelationship )
{
	Enum_String( k_EFriendRelationshipNone );
	Enum_String( k_EFriendRelationshipBlocked );
	Enum_String( k_EFriendRelationshipRequestRecipient );
	Enum_String( k_EFriendRelationshipFriend );
	Enum_String( k_EFriendRelationshipRequestInitiator );
	Enum_String( k_EFriendRelationshipIgnored );
	Enum_String( k_EFriendRelationshipIgnoredFriend );
}
End_Enum_String;

#endif // EFRIENDRELATIONSHIP_H
