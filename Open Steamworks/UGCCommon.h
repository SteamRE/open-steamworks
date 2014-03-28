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

#ifndef UGCCOMMON_H
#define UGCCOMMON_H
#ifdef _WIN32
#pragma once
#endif



#define STEAMUGC_INTERFACE_VERSION_001 "STEAMUGC_INTERFACE_VERSION001"
#define STEAMUGC_INTERFACE_VERSION_002 "STEAMUGC_INTERFACE_VERSION002"


typedef uint64 UGCQueryHandle_t;

const UGCQueryHandle_t k_UGCQueryHandleInvalid = 0xffffffffffffffffull;

enum EUGCQuery
{
	// TODO: Reverse this enum
};

enum EUserUGCList
{
	// TODO: Reverse this enum
};

enum EUGCMatchingUGCType
{
	// TODO: Reverse this enum
};

enum EUserUGCListSortOrder
{
	// TODO: Reverse this enum
};

struct SteamUGCDetails_t
{
	// TODO : Reverse this struct
#ifdef _S4N_
	int m_iPadding;
#endif
};


#endif // UGCCOMMON_H
