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

#ifndef ISTEAMUSERITEMS003_H
#define ISTEAMUSERITEMS003_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "UserItemsCommon.h"

abstract_class OBSOLETE_INTERFACE ISteamUserItems003
{
public:
	virtual SteamAPICall_t LoadItems() = 0;

    virtual SteamAPICall_t GetItemCount() = 0;
	
	virtual bool GetItemIterative( uint32 i, ItemID *UniqueID, uint32 *ItemType, uint32 *ItemLevel, EItemQuality *Quality, uint32 *Flags, uint32 *Quantity, uint32 *NbOfAttribute ) = 0;
	virtual bool GetItemByID( ItemID uniqueID, uint32 *ItemType, uint32 *ItemLevel, EItemQuality *Quality, uint32 *Flags, uint32 *Quantity, uint32 *NbOfAttribute ) = 0;
	virtual void GetItemAttribute( ItemID uniqueID, uint32 b, uint32 *c, float *d ) = 0;

	virtual void UpdateInventoryPos( ItemID uniqueID, uint32 b ) = 0;

	virtual void DropItem( ItemID itemId ) = 0;

    virtual SteamAPICall_t GetItemBlob( ItemID itemId ) = 0;;
	virtual SteamAPICall_t SetItemBlob( ItemID itemID, const void *blob, uint32 ) = 0;
};
 


#endif // ISTEAMUSERITEMS003_H
