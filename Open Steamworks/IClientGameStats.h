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

#ifndef ICLIENTGAMESTATS_H
#define ICLIENTGAMESTATS_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"


#define CLIENTGAMESTATS_INTERFACE_VERSION "CLIENTGAMESTATS_INTERFACE_VERSION001"

class UNSAFE_INTERFACE IClientGameStats
{
public:
	virtual unknown_ret GetNewSession( int8, uint64, int, uint32) = 0;
	virtual unknown_ret EndSession(uint64, uint32, int) = 0;

	virtual unknown_ret AddSessionAttributeInt(uint64,const char *, int) = 0;
	virtual unknown_ret AddSessionAttributeString( uint64, const char *, const char * ) = 0;
	virtual unknown_ret AddSessionAttributeFloat( uint64, const char *, float ) = 0;

	virtual unknown_ret AddNewRow( uint64 *, uint64, const char * ) = 0;

	virtual unknown_ret CommitRow( uint64 ) = 0;
	virtual unknown_ret CommitOutstandingRows( uint64 ) = 0;

	virtual unknown_ret AddRowAttributeInt( uint64, const char *, int ) = 0;
	virtual unknown_ret AddRowAtributeString( uint64, const char *, const char * ) = 0;
	virtual unknown_ret AddRowAttributeFloat( uint64, const char *, float ) = 0;

	virtual unknown_ret AddSessionAttributeInt64( uint64, const char *, int64 ) = 0;

	virtual unknown_ret AddRowAttributeInt64( uint64, const char *, int64 ) = 0;
};


#endif // ICLIENTGAMESTATS_H
