//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code,  comments,  and all related files,  projects,  resources, 
// redistributables included with this project are Copyright Valve Corporation.
// Additionally,  Valve,  the Valve logo,  Half-Life,  the Half-Life logo,  the
// Lambda logo,  Steam,  the Steam logo,  Team Fortress,  the Team Fortress logo, 
// Opposing Force,  Day of Defeat,  the Day of Defeat logo,  Counter-Strike,  the
// Counter-Strike logo,  Source,  the Source logo,  and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#ifndef ICLIENTCONFIGSTORE_H
#define ICLIENTCONFIGSTORE_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"

// this is a guess,  i couldn't find it in the bins
#define CLIENTCONFIGSTORE_INTERFACE_VERSION "CLIENTCONFIGSTORE_INTERFACE_VERSION001"

typedef uint32 EConfigStore;

class UNSAFE_INTERFACE IClientConfigStore
{

public:
	virtual unknown_ret IsSet( EConfigStore eConfigStore, const char *a ) = 0;

	virtual unknown_ret GetBool( EConfigStore eConfigStore, const char *a, bool b ) = 0;
	virtual unknown_ret GetInt( EConfigStore eConfigStore, const char *a, int b ) = 0;
	virtual unknown_ret GetUint64( EConfigStore eConfigStore, const char *a, uint64 b ) = 0;
	virtual unknown_ret GetFloat( EConfigStore eConfigStore, const char *a, float b ) = 0;
	virtual unknown_ret GetString( EConfigStore eConfigStore, const char *a, const char *b ) = 0;
	virtual unknown_ret GetBinary( EConfigStore eConfigStore, const char *a, uint8 *b, uint32 c ) = 0;
	virtual unknown_ret GetBinaryWatermarked( EConfigStore eConfigStore, const char *a, uint8 *b, uint32 c ) = 0;

	virtual unknown_ret SetBool( EConfigStore eConfigStore, const char *a, bool b ) = 0;
	virtual unknown_ret SetInt( EConfigStore eConfigStore, const char *a, int b ) = 0;
	virtual unknown_ret SetUint64( EConfigStore eConfigStore, const char *a, uint64 b ) = 0;
	virtual unknown_ret SetFloat( EConfigStore eConfigStore, const char *a, float b ) = 0;
	virtual unknown_ret SetString( EConfigStore eConfigStore, const char *a, const char *b ) = 0;
	virtual unknown_ret SetBinary( EConfigStore eConfigStore, const char *a, const uint8 *b, uint32 c ) = 0;
	virtual unknown_ret SetBinaryWatermarked( EConfigStore eConfigStore, const char *a, const uint8 *b, uint32 c ) = 0;

	virtual unknown_ret RemoveKey( EConfigStore eConfigStore, const char *a ) = 0;
	virtual unknown_ret GetKeySerialized( EConfigStore eConfigStore, const char *a, uint8 *b, int c ) = 0;
};

#endif // ICLIENTCONFIGSTORE_H
