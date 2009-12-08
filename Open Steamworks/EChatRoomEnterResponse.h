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

#ifndef ECHATROOMENTERRESPONSE_H
#define ECHATROOMENTERRESPONSE_H
#ifdef _WIN32
#pragma once
#endif


#include "EnumString.h"



//-----------------------------------------------------------------------------
// Purpose: Chat Room Enter Responses
//-----------------------------------------------------------------------------
enum EChatRoomEnterResponse
{
	k_EChatRoomEnterResponseSuccess = 1,		// Success
	k_EChatRoomEnterResponseDoesntExist = 2,	// Chat doesn't exist (probably closed)
	k_EChatRoomEnterResponseNotAllowed = 3,		// General Denied - You don't have the permissions needed to join the chat
	k_EChatRoomEnterResponseFull = 4,			// Chat room has reached its maximum size
	k_EChatRoomEnterResponseError = 5,			// Unexpected Error
	k_EChatRoomEnterResponseBanned = 6,			// You are banned from this chat room and may not join
};

Begin_Enum_String(EChatRoomEnterResponse)
{
	Enum_String( k_EChatRoomEnterResponseSuccess );		// Success
	Enum_String( k_EChatRoomEnterResponseDoesntExist );	// Chat doesn't exist (probably closed)
	Enum_String( k_EChatRoomEnterResponseNotAllowed );	// General Denied - You don't have the permissions needed to join the chat
	Enum_String( k_EChatRoomEnterResponseFull );		// Chat room has reached its maximum size
	Enum_String( k_EChatRoomEnterResponseError );		// Unexpected Error
	Enum_String( k_EChatRoomEnterResponseBanned );		// You are banned from this chat room and may not join
}
End_Enum_String;

#endif // ECHATROOMENTERRESPONSE_H
