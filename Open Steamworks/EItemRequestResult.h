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

#ifndef EITEMREQUESTRESULT_H
#define EITEMREQUESTRESULT_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

enum EItemRequestResult
{
	k_EItemRequestResultOK,
	k_EItemRequestResultDenied,
	k_EItemRequestResultServerError,
	k_EItemRequestResultTimeout,
    k_EItemRequestResultInvalid,
	k_EItemRequestResultNoMatch,
	k_EItemRequestResultUnknownError,
	k_EItemRequestResultNotLoggedOn
};

Begin_Enum_String(EItemRequestResult)
{
	Enum_String( k_EItemRequestResultOK );
	Enum_String( k_EItemRequestResultDenied );
	Enum_String( k_EItemRequestResultServerError );
	Enum_String( k_EItemRequestResultTimeout );
    Enum_String( k_EItemRequestResultInvalid );
	Enum_String( k_EItemRequestResultNoMatch );
	Enum_String( k_EItemRequestResultUnknownError );
	Enum_String( k_EItemRequestResultNotLoggedOn );
}
End_Enum_String;



#endif // EITEMREQUESTRESULT_H
