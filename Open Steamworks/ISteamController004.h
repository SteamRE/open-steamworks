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

#ifndef ISTEAMCONTROLLER004_H
#define ISTEAMCONTROLLER004_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "ControllerCommon.h"

abstract_class ISteamController004
{
public:
	//
	// Native controller support API
	//

	// Must call init and shutdown when starting/ending use of the interface
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	// Pump callback/callresult events, SteamAPI_RunCallbacks will do this for you,
	// normally never need to call directly.
	virtual void RunFrame() = 0;

	virtual int32 GetConnectedControllers( uint64* ) = 0;
	virtual bool ShowBindingPanel( uint64 ) = 0;
	virtual unknown_ret GetActionSetHandle( char const* ) = 0;
	virtual void ActivateActionSet( uint64, uint64 ) = 0;
	virtual unknown_ret GetCurrentActionSet( uint64 ) = 0;
	virtual unknown_ret GetDigitalActionHandle( char const* ) = 0;
	virtual unknown_ret GetDigitalActionData( uint64, uint64 ) = 0;
	virtual unknown_ret GetDigitalActionOrigins( uint64, uint64, uint64, EControllerActionOrigin* ) = 0;
	virtual unknown_ret GetAnalogActionHandle( char const* ) = 0;
	virtual unknown_ret GetAnalogActionData( uint64, uint64 ) = 0;
	virtual unknown_ret GetAnalogActionOrigins( uint64, uint64, uint64, EControllerActionOrigin* ) = 0;
	virtual unknown_ret StopAnalogActionMomentum( uint64, uint64 ) = 0;

	// Trigger a haptic pulse on the controller
	virtual void TriggerHapticPulse( uint64, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec ) = 0;
	virtual void TriggerRepeatedHapticPulse( uint64, ESteamControllerPad, unsigned short, unsigned short, unsigned short, unsigned int ) = 0;

	virtual int32 GetGamepadIndexForController( uint64 ) = 0;
	virtual unknown_ret GetControllerForGamepadIndex( int32 ) = 0;
	virtual unknown_ret GetMotionData(  uint64  ) = 0;
	virtual unknown_ret ShowDigitalActionOrigins(  uint64 ,  uint64 , float, float, float) = 0;
	virtual unknown_ret ShowAnalogActionOrigins(  uint64 ,  uint64 , float, float, float) = 0;

};

#endif
