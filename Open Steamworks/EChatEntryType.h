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

#ifndef ECHATENTRYTYPE_H
#define ECHATENTRYTYPE_H
#ifdef _WIN32
#pragma once
#endif


#include "EnumString.h"


//-----------------------------------------------------------------------------
// Purpose: Chat Entry Types (previously was only friend-to-friend message types)
//-----------------------------------------------------------------------------
enum EChatEntryType
{
	k_EChatEntryTypeChatMsg = 1,		// Normal text message from another user
	k_EChatEntryTypeTyping = 2,			// Another user is typing (not used in multi-user chat)
	k_EChatEntryTypeInviteGame = 3,		// Invite from other user into that users current game
	k_EChatEntryTypeEmote = 4,			// text emote message
	k_EChatEntryTypeLobbyGameStart = 5,	// lobby game is starting
	// Above are previous FriendMsgType entries, now merged into more generic chat entry types
};


Begin_Enum_String(EChatEntryType)
{
	Enum_String( k_EChatEntryTypeChatMsg );		// Normal text message from another user
	Enum_String( k_EChatEntryTypeTyping );		// Another user is typing (not used in multi-user chat)
	Enum_String( k_EChatEntryTypeInviteGame );	// DEPRECATED Invite from other user into that users current game
	Enum_String( k_EChatEntryTypeEmote );		// text emote message
	Enum_String( k_EChatEntryTypeLobbyGameStart );
	// Above are previous FriendMsgType entries, now merged into more generic chat entry types
}
End_Enum_String;

#endif // ECHATENTRYTYPE_H
