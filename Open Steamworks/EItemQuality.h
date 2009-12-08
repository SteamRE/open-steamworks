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

#ifndef EITEMQUALITY_H
#define EITEMQUALITY_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"


enum EItemQuality
{
	k_EItemQuality_Invalid = -2,
	k_EItemQuality_Any,
	k_EItemQuality_Normal, 
	k_EItemQuality_Common,
	k_EItemQuality_Rare,
	k_EItemQuality_Unique,
	k_EItemQuality_Count,
	k_EItemQuality_Unk5,
	k_EItemQuality_Unk6,
	k_EItemQuality_Community,
	k_EItemQuality_Valve
};

Begin_Enum_String(EItemQuality)
{
	Enum_String( k_EItemQuality_Invalid );
	Enum_String( k_EItemQuality_Any );
	Enum_String( k_EItemQuality_Normal ); 
	Enum_String( k_EItemQuality_Common );
	Enum_String( k_EItemQuality_Rare );
	Enum_String( k_EItemQuality_Unique );
	Enum_String( k_EItemQuality_Count );
	Enum_String( k_EItemQuality_Unk5 );
	Enum_String( k_EItemQuality_Unk6 );
	Enum_String( k_EItemQuality_Community );
	Enum_String( k_EItemQuality_Valve );
}
End_Enum_String;



#endif // EITEMQUALITY_H
