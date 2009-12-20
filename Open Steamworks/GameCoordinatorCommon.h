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

#ifndef ISTEAMGAMECOORDINATORCOMMON_H
#define ISTEAMGAMECOORDINATORCOMMON_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

#define STEAMGAMECOORDINATOR_INTERFACE_VERSION_001 "SteamGameCoordinator001"

struct GameCoordinatorMessageAvailable_t
{
	enum { k_iCallback = k_iSteamGameCoordinatorCallbacks + 1 };
	uint32 messageLength;
};

enum EGCMessages
{
	k_ESOMsg_Create = 21,
	k_ESOMsg_Update,
	k_ESOMsg_Destroy,
	k_ESOMsg_CacheSubscribed,
	k_ESOMsg_CacheUnsubscribed,

	k_EGCMsgStartPlaying = 53,
	k_EGCMsgStopPlaying,
	k_EGCMsgStartGameserver,
	k_EGCMsgStopGameserver,

	k_EMsgGCSetItemPosition = 1001,
	k_EMsgGCCraft,
	k_EMsgGCCraftResponse,
	k_EMsgGCDelete,

	k_EMsgGCDev_NewItemRequest = 2001,
	k_EMsgGCDev_NewItemRequestResponse
};

Begin_Enum_String(EGCMessages)
{
	Enum_String( k_ESOMsg_Create );
	Enum_String( k_ESOMsg_Update );
	Enum_String( k_ESOMsg_Destroy );
	Enum_String( k_ESOMsg_CacheSubscribed );
	Enum_String( k_ESOMsg_CacheUnsubscribed );

	Enum_String( k_EGCMsgStartPlaying );
	Enum_String( k_EGCMsgStopPlaying );
	Enum_String( k_EGCMsgStartGameserver );
	Enum_String( k_EGCMsgStopGameserver );

	Enum_String( k_EMsgGCSetItemPosition );
	Enum_String( k_EMsgGCCraft );
	Enum_String( k_EMsgGCCraftResponse );
	Enum_String( k_EMsgGCDelete );

	Enum_String( k_EMsgGCDev_NewItemRequest );
	Enum_String( k_EMsgGCDev_NewItemRequestResponse );
}
End_Enum_String;

//TF2 game coordinator:
// message index    function
// 22               item moved
// 23               item deleted
// 24               items loaded
// 25               items unloaded

#pragma pack(push, 1)

struct SOMsgCreate_t
{
	enum { k_iMessage = k_ESOMsg_Create };
};

struct SOMsgUpdate_t
{
	enum { k_iMessage = k_ESOMsg_Update };

	uint16 id; // 0x01
	char garbage[16]; // FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF
	CSteamID steamid;
	uint32 unknown; // 0x01
	uint64 itemID;
	uint32 flagsA;
	uint16 flagsB;
};

struct SOMsgDeleted_t
{
	enum { k_iMessage = k_ESOMsg_Destroy };
};

struct SOMsgCacheSubscribed_t
{
	enum { k_iMessage = k_ESOMsg_CacheSubscribed };

	uint16 id; // 0x01
	char garbage[16]; // FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF
	CSteamID steamid;
	uint32 unknown; // 0x10001
	uint16 padding;
	uint16 itemcount;
};

struct SOMsgCacheSubscribed_Item_t
{
	uint64 itemid;
	uint32 accountid;
	uint16 itemdefindex;
	uint8 itemlevel;
	EItemQuality itemquality;
	uint32 position;
	uint32 itemcount;
	uint16 attribcount;
};

struct SOMsgCacheSubscribed_Item_Attrib_t
{
	uint16 attribindex;
	float value;
};

struct SOMsgCacheUnsubscribed_t
{
	enum { k_iMessage = k_ESOMsg_CacheUnsubscribed };

	uint16 id; // 0x01
	char garbage[16]; // FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF
	CSteamID steamid;
};

#pragma pack(pop)

#endif // ISTEAMGAMECOORDINATORCOMMON_H
