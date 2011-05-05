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

#ifndef ISTEAMGAMESERVERITEMS002_H
#define ISTEAMGAMESERVERITEMS002_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "GameServerItemsCommon.h"


abstract_class OBSOLETE_INTERFACE ISteamGameServerItems002
{
public:
	virtual SteamAPICall_t LoadItems( CSteamID steamid ) = 0;
	virtual SteamAPICall_t GetItemCount( CSteamID steamid ) = 0;

	virtual bool GetItemIterative( CSteamID steamid, uint32 i, ItemID *UniqueID, uint32 *ItemType, uint32 *ItemLevel, EItemQuality *Quality, uint32 *Flags, uint32 *Quantity ) = 0;
	virtual bool GetItemByID( ItemID itemid, CSteamID* steamid, uint32 *ItemType, uint32 *ItemLevel, EItemQuality *Quality, uint32 *Flags, uint32 *Quantity ) = 0;

	virtual bool GetItemAttribute( ItemID itemid, uint32, uint32*, float* ) = 0;

	virtual HNewItemRequest CreateNewItemRequest( CSteamID steamid, uint32, EItemQuality quality ) = 0;

	virtual bool AddNewItemCriteria( HNewItemRequest ireq, const char*, EItemCriteriaOperator, const char*, bool ) = 0;
	virtual bool AddNewItemCriteria( HNewItemRequest ireq, const char*, EItemCriteriaOperator, float, bool ) = 0;

	virtual SteamAPICall_t SendNewItemRequest( HNewItemRequest ireq ) = 0;

	virtual SteamAPICall_t GrantItemToUser( ItemID item, CSteamID steamid ) = 0;

	virtual SteamAPICall_t DeleteTemporaryItem( ItemID item ) = 0;
	virtual SteamAPICall_t DeleteAllTemporaryItems() = 0;
};

#endif // ISTEAMGAMESERVEITEMS002_H
