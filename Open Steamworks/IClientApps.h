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

#ifndef ICLIENTAPPS_H
#define ICLIENTAPPS_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "AppsCommon.h"


abstract_class UNSAFE_INTERFACE IClientApps
{
public:
	// returns 0 if the key does not exist
	// this may be true on first call, since the app data may not be cached locally yet
	// If you expect it to exists wait for the AppDataChanged_t after the first failure and ask again
	virtual int GetAppData( AppId_t unAppID, const char *pchKey, char *pchValue, int cchValueMax ) = 0;

	virtual AppId_t GetInternalAppIDFromGameID( CGameID gameID ) = 0;

	virtual void RequestAppCallbacks( bool bOnlyMultiplayerApps ) = 0;

	virtual int GetAppDataSection( AppId_t unAppID, int eSection, uint8 *pchBuffer, int cbBufferMax, bool bUseSymbolsAsKeys ) = 0;
	virtual bool RequestAppInfoUpdate( const AppId_t *pAppIDs, int nNumAppIDs, bool bForceUpdate ) = 0;

	virtual void NotifyAppEventTriggered( AppId_t unAppID, EAppEvent eAppEvent ) = 0;
	virtual void NotifyDlcInstalled( AppId_t unAppID ) = 0;

	virtual int GetDLCCount( AppId_t unAppID ) = 0;
	virtual bool BGetDLCDataByIndex( AppId_t unAppID, int iIndex, AppId_t* unDLCAppID, bool *, char *, int) = 0;
};

#endif // ICLIENTAPPS_H
