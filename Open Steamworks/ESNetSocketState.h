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

#ifndef ESNETSOCKETSTATE_H
#define ESNETSOCKETSTATE_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"


// connection progress indicators
enum ESNetSocketState
{
	k_ESNetSocketStateInvalid = 0,						

	// communication is valid
	k_ESNetSocketStateConnected = 1,				
	
	// states while establishing a connection
	k_ESNetSocketStateInitiated = 10,				// the connection state machine has started

	// p2p connections
	k_ESNetSocketStateLocalCandidatesFound = 11,	// we've found our local IP info
	k_ESNetSocketStateReceivedRemoteCandidates = 12,// we've received information from the remote machine, via the Steam back-end, about their IP info

	// direct connections
	k_ESNetSocketStateChallengeHandshake = 15,		// we've received a challenge packet from the server

	// failure states
	k_ESNetSocketStateDisconnecting = 21,			// the API shut it down, and we're in the process of telling the other end	
	k_ESNetSocketStateLocalDisconnect = 22,			// the API shut it down, and we've completed shutdown
	k_ESNetSocketStateTimeoutDuringConnect = 23,	// we timed out while trying to creating the connection
	k_ESNetSocketStateRemoteEndDisconnected = 24,	// the remote end has disconnected from us
	k_ESNetSocketStateConnectionBroken = 25,		// connection has been broken; either the other end has disappeared or our local network connection has broke

};

Begin_Enum_String(ESNetSocketState)
{
	Enum_String( k_ESNetSocketStateInvalid );						

	// communication is valid
	Enum_String( k_ESNetSocketStateConnected );				
	
	// states while establishing a connection
	Enum_String( k_ESNetSocketStateInitiated );				// the connection state machine has started

	// p2p connections
	Enum_String( k_ESNetSocketStateLocalCandidatesFound );	// we've found our local IP info
	Enum_String( k_ESNetSocketStateReceivedRemoteCandidates );// we've received information from the remote machine, via the Steam back-end, about their IP info

	// direct connections
	Enum_String( k_ESNetSocketStateChallengeHandshake );		// we've received a challenge packet from the server

	// failure states
	Enum_String( k_ESNetSocketStateDisconnecting );			// the API shut it down, and we're in the process of telling the other end	
	Enum_String( k_ESNetSocketStateLocalDisconnect );			// the API shut it down, and we've completed shutdown
	Enum_String( k_ESNetSocketStateTimeoutDuringConnect );	// we timed out while trying to creating the connection
	Enum_String( k_ESNetSocketStateRemoteEndDisconnected );	// the remote end has disconnected from us
	Enum_String( k_ESNetSocketStateConnectionBroken );		// connection has been broken; either the other end has disappeared or our local network connection has broke
}
End_Enum_String;

#endif // ESNETSOCKETSTATE_H
