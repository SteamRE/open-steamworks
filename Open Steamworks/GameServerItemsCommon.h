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

#ifndef GAMESERVERITEMSCOMMON_H
#define GAMESERVERITEMSCOMMON_H
#ifdef _WIN32
#pragma once
#endif

#include "UserItemsCommon.h"



#define STEAMGAMESERVERITEMS_INTERFACE_VERSION_002 "STEAMGAMESERVERITEMS_INTERFACE_VERSION002"
#define STEAMGAMESERVERITEMS_INTERFACE_VERSION_003 "STEAMGAMESERVERITEMS_INTERFACE_VERSION003"
#define STEAMGAMESERVERITEMS_INTERFACE_VERSION_004 "STEAMGAMESERVERITEMS_INTERFACE_VERSION004"


#pragma pack( push, 8 )
struct GSItemCount_t
{
	enum { k_iCallback = k_iSteamGameServerItemsCallbacks };
	CSteamID m_steamID;
	EItemRequestResult m_eResult;
	uint32 m_unCount;
};

struct GSItemRequest_t
{
	enum { k_iCallback = k_iSteamGameServerItemsCallbacks + 1 };
	CSteamID m_steamID;
	EItemRequestResult m_eResult;
	ItemID m_itemID;
};

struct GSItemGranted_t
{
	enum { k_iCallback = k_iSteamGameServerItemsCallbacks + 7 };

	CSteamID m_steamID;
	ItemID m_itemID;
};

struct GSItemGetBlob_t
{
	enum { k_iCallback = k_iSteamGameServerItemsCallbacks + 8 };
	ItemID m_itemID;
	EItemRequestResult m_eResult;
	uint8 m_itemBlob[1024];
};

struct GSItemSetBlob_t
{
	enum { k_iCallback = k_iSteamGameServerItemsCallbacks + 9 };
	ItemID m_itemID;
	EItemRequestResult m_eResult;
	uint32 Unk;
};
#pragma pack( pop )

// 1511 - item server connection success?
// --------------------------------------
// 01

#endif // GAMESERVERITEMSCOMMON_H
