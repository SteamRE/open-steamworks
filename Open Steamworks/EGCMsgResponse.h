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

#ifndef EGAMECOORDINATORRESULT_H
#define EGAMECOORDINATORRESULT_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

enum EGCMsgResponse
{
	k_EGCMsgResponseOK,
	k_EGCMsgResponseDenied,
	k_EGCMsgResponseServerError,
	k_EGCMsgResponseTimeout,
	k_EGCMsgResponseInvalid,
	k_EGCMsgResponseNoMatch,
	k_EGCMsgResponseUnknownError,
	k_EGCMsgResponseNotLoggedOn,
};

Begin_Enum_String( EGCMsgResponse )
{
	Enum_String( k_EGCMsgResponseOK );
	Enum_String( k_EGCMsgResponseDenied );
	Enum_String( k_EGCMsgResponseServerError );
	Enum_String( k_EGCMsgResponseTimeout );
	Enum_String( k_EGCMsgResponseInvalid );
	Enum_String( k_EGCMsgResponseNoMatch );
	Enum_String( k_EGCMsgResponseUnknownError );
	Enum_String( k_EGCMsgResponseNotLoggedOn );
}
End_Enum_String;

#endif // EGAMECOORDINATORRESULT_H
