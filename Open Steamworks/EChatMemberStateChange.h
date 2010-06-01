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

#ifndef ECHATMEMBERSTATECHANGE_H
#define ECHATMEMBERSTATECHANGE_H
#ifdef _WIN32
#pragma once
#endif


//-----------------------------------------------------------------------------
// Purpose: Used in ChatInfo messages - fields specific to a chat member - must fit in a uint32
//-----------------------------------------------------------------------------
typedef enum EChatMemberStateChange
{
	// Specific to joining / leaving the chatroom
	k_EChatMemberStateChangeEntered			= 0x0001,		// This user has joined or is joining the chat room
	k_EChatMemberStateChangeLeft			= 0x0002,		// This user has left or is leaving the chat room
	k_EChatMemberStateChangeDisconnected	= 0x0004,		// User disconnected without leaving the chat first
	k_EChatMemberStateChangeKicked			= 0x0008,		// User kicked
	k_EChatMemberStateChangeBanned			= 0x0010,		// User kicked and banned
} EChatMemberStateChange;

#endif // ECHATMEMBERSTATECHANGE_H
