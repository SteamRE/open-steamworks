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

#ifndef ISTEAMGAMESERVERITEMS004_H
#define ISTEAMGAMESERVERITEMS004_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "GameServerItemsCommon.h"

abstract_class OBSOLETE_INTERFACE ISteamGameServerItems004
{
public:

	virtual SteamAPICall_t LoadItems( CSteamID steamid ) = 0;
	virtual SteamAPICall_t GetItemCount( CSteamID steamid ) = 0;

	virtual bool GetItemIterative( CSteamID steamid, uint32 i, ItemID *UniqueID, uint32 *ItemType, uint32 *ItemLevel, EItemQuality *Quality, uint32 *Flags, uint32 *Quantity, uint32 *NbOfAttribute ) = 0;
	virtual bool GetItemByID( ItemID itemid, CSteamID* steamid, uint32 *ItemType, uint32 *ItemLevel, EItemQuality *Quality, uint32 *Flags, uint32 *Quantity, uint32 *NbOfAttribute ) = 0;

	virtual bool GetItemAttribute( ItemID itemid, uint32 i, uint32* attribIndex, float* attribValue) = 0;

	virtual HNewItemRequest CreateNewItemRequest( CSteamID steamid ) = 0;

	virtual bool AddNewItemLevel( HNewItemRequest ireq, uint32 level ) = 0;
	virtual bool AddNewItemQuality( HNewItemRequest ireq, EItemQuality quality ) = 0;

	virtual bool SetNewItemInitialInventoryPos( HNewItemRequest ireq, uint32 pos ) = 0;
	virtual bool SetNewItemInitialQuantity( HNewItemRequest ireq, uint32 quantity ) = 0;

	virtual bool AddNewItemCriteria( HNewItemRequest ireq, const char* key, EItemCriteriaOperator criteria, const char* value, bool unkn ) = 0;
	virtual bool AddNewItemCriteria( HNewItemRequest ireq, const char* key, EItemCriteriaOperator criteria, float value, bool unkn ) = 0;

	virtual SteamAPICall_t SendNewItemRequest( HNewItemRequest ireq ) = 0;

	virtual SteamAPICall_t GrantItemToUser( ItemID item, CSteamID steamid ) = 0;

	virtual SteamAPICall_t DeleteTemporaryItem( ItemID item ) = 0;
	virtual SteamAPICall_t DeleteAllTemporaryItems() = 0;

	virtual SteamAPICall_t UpdateQuantity( ItemID item, uint32 quantity ) = 0;

	virtual SteamAPICall_t GetItemBlob( ItemID item ) = 0;
	virtual SteamAPICall_t SetItemBlob( ItemID item, void const* blob, uint32 size ) = 0;
};

#endif
