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

#ifndef EPURCHASERESULTDETAIL_H
#define EPURCHASERESULTDETAIL_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

enum EPurchaseResultDetail 
{
	k_EPurchaseResultNoDetail = 0,
	k_EPurchaseResultAVSFailure = 1,
	k_EPurchaseResultInsufficientFunds = 2,
	k_EPurchaseResultContactSupport = 3,
	k_EPurchaseResultTimeout = 4,

	// these are mainly used for testing
	k_EPurchaseResultInvalidPackage = 5,
	k_EPurchaseResultInvalidPaymentMethod = 6,
	k_EPurchaseResultInvalidData = 7,
	k_EPurchaseResultOthersInProgress = 8,
	k_EPurchaseResultAlreadyPurchased = 9,
	k_EPurchaseResultWrongPrice = 10
};

Begin_Enum_String( EPurchaseResultDetail )
{
	Enum_String( k_EPurchaseResultNoDetail );
	Enum_String( k_EPurchaseResultAVSFailure );
	Enum_String( k_EPurchaseResultInsufficientFunds );
	Enum_String( k_EPurchaseResultContactSupport );
	Enum_String( k_EPurchaseResultTimeout );

	// these are mainly used for testing
	Enum_String( k_EPurchaseResultInvalidPackage );
	Enum_String( k_EPurchaseResultInvalidPaymentMethod );
	Enum_String( k_EPurchaseResultInvalidData );
	Enum_String( k_EPurchaseResultOthersInProgress );
	Enum_String( k_EPurchaseResultAlreadyPurchased );
	Enum_String( k_EPurchaseResultWrongPrice );
}
End_Enum_String;


#endif // EPURCHASERESULTDETAIL_H
