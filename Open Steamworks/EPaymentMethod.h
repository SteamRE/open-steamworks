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

#ifndef EPAYMENTMETHOD_H
#define EPAYMENTMETHOD_H
#ifdef _WIN32
#pragma once
#endif

#include "EnumString.h"

// Payment methods for purchases - BIT FLAGS so can be used to indicate
// acceptable payment methods for packages
enum EPaymentMethod
{
	k_EPaymentMethodNone = 0x00,
	k_EPaymentMethodCDKey = 0x01,		
	k_EPaymentMethodCreditCard = 0x02,
	k_EPaymentMethodPayPal = 0x04,		
	k_EPaymentMethodManual = 0x08,		// Purchase was added by Steam support
};

Begin_Enum_String(EPaymentMethod)
{
	Enum_String( k_EPaymentMethodNone );
	Enum_String( k_EPaymentMethodCDKey );		
	Enum_String( k_EPaymentMethodCreditCard );
	Enum_String( k_EPaymentMethodPayPal );		
	Enum_String( k_EPaymentMethodManual );		// Purchase was added by Steam support
}
End_Enum_String;

#endif // EPAYMENTMETHOD_H
