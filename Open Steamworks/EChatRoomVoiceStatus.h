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

#ifndef ECHATROOMVOICESTATUS_H
#define ECHATROOMVOICESTATUS_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

typedef enum EChatRoomVoiceStatus
{
	eChatRoomVoiceStatusBad = 0,
	eChatRoomVoiceStatusUnknownRoom = 1,
	eChatRoomVoiceStatusUnknownUser = 2,
	eChatRoomVoiceStatusNotSpeaking = 3,
	eChatRoomVoiceStatusConnectedSpeaking = 4,
	eChatRoomVoiceStatusConnectedSpeakingData = 5,
	eChatRoomVoiceStatusNotConnectedSpeaking = 6,
	eChatRoomVoiceStatusConnecting = 7,
	eChatRoomVoiceStatusUnreachable = 8,
	eChatRoomVoiceStatusDisconnected = 9,
	eChatRoomVoiceStatusCount = 10,
} EChatRoomVoiceStatus;

Begin_Enum_String( EChatRoomVoiceStatus )
{
	Enum_String( eChatRoomVoiceStatusBad );
	Enum_String( eChatRoomVoiceStatusUnknownRoom );
	Enum_String( eChatRoomVoiceStatusUnknownUser );
	Enum_String( eChatRoomVoiceStatusNotSpeaking );
	Enum_String( eChatRoomVoiceStatusConnectedSpeaking );
	Enum_String( eChatRoomVoiceStatusConnectedSpeakingData );
	Enum_String( eChatRoomVoiceStatusNotConnectedSpeaking );
	Enum_String( eChatRoomVoiceStatusConnecting );
	Enum_String( eChatRoomVoiceStatusUnreachable );
	Enum_String( eChatRoomVoiceStatusDisconnected );
	Enum_String( eChatRoomVoiceStatusCount );
}
End_Enum_String( EChatRoomVoiceStatus );

#endif // ECHATROOMVOICESTATUS_H
