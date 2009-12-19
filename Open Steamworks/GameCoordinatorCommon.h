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

#define STEAMGAMECOORDINATOR_INTERFACE_VERSION_001 "SteamGameCoordinator001"

struct GameCoordinatorMessageAvailable_t
{
	enum { k_iCallback = k_iSteamGameCoordinatorCallbacks + 1 };
	uint32 messageLength;
};

//TF2 game coordinator:
// message index    function
// 22               item moved
// 23               item deleted
// 24               items loaded
// 25               items unloaded

/*
22

uint16 id // AA
char garbage[16] // BB
CSteamID steamid // CC
uint32 unknown = 0x01 // DD 
uint64 itemid // EE
uint32 flagsa // FF
uint16 flagsb // GG

24

uint16 id
char garbage[16]
CSteamID steamid
uint32 unknown = 0x10001
uint16 padding
uint16 itemcount

[
	uint64 itemid
	uint32 accountid
	uint16 itemdefindex
	uint32 flagsa
	uint16 flagsb
	uint32 paddinga = 0x01
	uint16 paddingb
]
*/


#pragma pack(push, 1)

struct GC_ItemMoved
{
	enum { k_iMessage = 22 };

	uint16 id; // 0x01
	char garbage[16]; // FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF
	CSteamID steamid;
	uint32 unknown; // 0x01
	uint64 itemID;
	uint32 flagsA;
	uint16 flagsB;
};

struct GC_ItemDeleted
{
	enum { k_iMessage = 23 };
};

struct GC_ItemsList
{
	enum { k_iMessage = 24 };

	uint16 id; // 0x01
	char garbage[16]; // FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF
	CSteamID steamid;
	uint32 unknown; // 0x10001
	uint16 padding;
	uint16 itemcount;
};

struct GC_ItemsList_Item
{
	uint64 itemid;
	uint32 accountid;
	uint16 itemdefindex;
	uint32 flagsa;
	uint16 flagsb;
	uint32 paddinga; // 0x01
	uint16 paddingb;
};

struct GC_ItemsUnloaded
{
	enum { k_iMessage = 25 };

	uint16 id; // 0x01
	char garbage[16]; // FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF
	CSteamID steamid;
};

#pragma pack(pop)

#endif // ISTEAMGAMECOORDINATORCOMMON_H
