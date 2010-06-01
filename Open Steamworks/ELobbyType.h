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

#ifndef ELOBBYTYPE_H
#define ELOBBYTYPE_H
#ifdef _WIN32
#pragma once
#endif

//-----------------------------------------------------------------------------
// Purpose: Functions for match making services for clients to get to favorites
//-----------------------------------------------------------------------------
typedef enum ELobbyType
{
	k_ELobbyTypeFriendsOnly = 1,	// shows for friends or invitees, but not in lobby list
	k_ELobbyTypePublic = 2,			// visible for friends and in lobby list
	k_ELobbyTypeInvisible = 3,		// returned by search, but not visible to other friends 
	//    useful if you want a user in two lobbies, for example matching groups together
	//	  a user can be in only one regular lobby, and up to two invisible lobbies
} ELobbyType;



#endif // ELOBBYTYPE_H
