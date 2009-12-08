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

#ifndef EFRIENDFLAGS_H
#define EFRIENDFLAGS_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

// for enumerating friends list
enum k_EFriendFlags
{
	k_EFriendFlagNone			= 0x00,
	k_EFriendFlagBlocked		= 0x01,
	k_EFriendFlagFriendshipRequested	= 0x02,
	k_EFriendFlagImmediate		= 0x04,			// "regular" friend
	k_EFriendFlagClanMember		= 0x08,
	k_EFriendFlagOnGameServer	= 0x10,	
	//	k_EFriendFlagHasPlayedWith	= 0x20,
	//	k_EFriendFlagFriendOfFriend	= 0x40,
	k_EFriendFlagRequestingFriendship = 0x80,
	k_EFriendFlagRequestingInfo = 0x100,
	k_EFriendFlagIgnored		= 0x200,
	k_EFriendFlagIgnoredFriend	= 0x400,
	k_EFriendFlagAll			= 0xFFFF,
};

Begin_Enum_String( k_EFriendFlags )
{
	Enum_String( k_EFriendFlagNone );
	Enum_String( k_EFriendFlagBlocked );
	Enum_String( k_EFriendFlagFriendshipRequested );
	Enum_String( k_EFriendFlagImmediate );			// "regular" friend
	Enum_String( k_EFriendFlagClanMember);
	Enum_String( k_EFriendFlagOnGameServer );
	//	Enum_String( k_EFriendFlagHasPlayedWith );
	//	Enum_String( k_EFriendFlagFriendOfFriend );
	Enum_String( k_EFriendFlagRequestingFriendship );
	Enum_String( k_EFriendFlagRequestingInfo );
	Enum_String( k_EFriendFlagIgnored );
	Enum_String( k_EFriendFlagIgnoredFriend	);
	Enum_String( k_EFriendFlagAll );
}
End_Enum_String;

#endif // EFRIENDFLAGS_H
