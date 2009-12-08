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

#ifndef EACCOUNTTYPE_H
#define EACCOUNTTYPE_H
#ifdef _WIN32
#pragma once
#endif


#include "EnumString.h"

// Steam account types
enum EAccountType
{
	k_EAccountTypeInvalid = 0,			
	k_EAccountTypeIndividual = 1,		// single user account
	k_EAccountTypeMultiseat = 2,		// multiseat (e.g. cybercafe) account
	k_EAccountTypeGameServer = 3,		// game server account
	k_EAccountTypeAnonGameServer = 4,	// anonymous game server account
	k_EAccountTypePending = 5,			// pending
	k_EAccountTypeContentServer = 6,	// content server
	k_EAccountTypeClan = 7,
	k_EAccountTypeChat = 8,
	k_EAccountTypeP2PSuperSeeder = 9,	// a fake steamid used by superpeers to seed content to users of Steam P2P stuff
	k_EAccountTypeAnonUser = 10,

	// Max of 16 items in this field
	k_EAccountTypeMax
};

Begin_Enum_String(EAccountType)
{
	Enum_String( k_EAccountTypeInvalid );			
	Enum_String( k_EAccountTypeIndividual );		// single user account
	Enum_String( k_EAccountTypeMultiseat );			// multiseat (e.g. cybercafe) account
	Enum_String( k_EAccountTypeGameServer );		// game server account
	Enum_String( k_EAccountTypeAnonGameServer );	// anonymous game server account
	Enum_String( k_EAccountTypePending );			// pending
	Enum_String( k_EAccountTypeContentServer );		// content server
	Enum_String( k_EAccountTypeClan );
	Enum_String( k_EAccountTypeChat );
	Enum_String( k_EAccountTypeP2PSuperSeeder );	// a fake steamid used by superpeers to seed content to users of Steam P2P stuff
	Enum_String( k_EAccountTypeAnonUser );

	// Max of 16 items in this field
	Enum_String( k_EAccountTypeMax );
}
End_Enum_String;


#endif // EACCOUNTTYPE_H
