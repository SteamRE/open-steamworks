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

#ifndef EFRIENDMSGTYPE_H
#define EFRIENGMSGTYPE_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

//-----------------------------------------------------------------------------
// Purpose: friend-to-friend message types
//-----------------------------------------------------------------------------
enum EFriendMsgType
{
	k_EFriendMsgTypeChat = 1,			// chat test message
	k_EFriendMsgTypeTyping = 2,			// lets the friend know the other user has starting typing a chat message
	k_EFriendMsgTypeInvite = 3,			// invites the friend into the users current game
	k_EFriendMsgTypeChatSent = 4,		// chat that the user has sent to a friend
};

Begin_Enum_String( EFriendMsgType )
{
	Enum_String( k_EFriendMsgTypeChat );
	Enum_String( k_EFriendMsgTypeTyping );
	Enum_String( k_EFriendMsgTypeInvite );
	Enum_String( k_EFriendMsgTypeChatSent );
}
End_Enum_String;

#endif // EFRIENDMSGTYPE_H
