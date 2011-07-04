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

#ifndef ICLIENTSCREENSHOTS_H
#define ICLIENTSCREENSHOTS_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
//#include "ScreenshotsCommon.h"


enum EScreenshotPrivacyState;


abstract_class UNSAFE_INTERFACE IClientScreenshots
{
public:
	virtual const char *GetShortcutDisplayName( CGameID gameID ) = 0;
	virtual void SetShortcutDisplayName( CGameID, const char * ) = 0;

	virtual uint32 WriteScreenshot( CGameID, void *, uint32, int32, int32 ) = 0;
	virtual uint32 AddScreenshotToLibrary( CGameID, const char *, const char *, int32, int32 ) = 0;

	virtual void TriggerScreenshot( CGameID ) = 0;
	virtual void HookScreenshots( uint32, bool ) = 0;
	virtual void RequestScreenshotFromGame( uint32 ) = 0;

	virtual bool SetLocation( CGameID, uint32, const char * ) = 0;
	virtual bool TagUser( CGameID, uint32, CSteamID ) = 0;

	virtual bool ResolvePath( CGameID, uint32, bool, char *, uint32 ) = 0;
	virtual uint32 GetFileSize( CGameID, uint32 ) = 0;
	virtual bool IsPersisted( CGameID, uint32 ) = 0;

	virtual uint32 GetNumGamesWithLocalScreenshots() = 0;
	virtual CGameID GetGameWithLocalScreenshots( int ) = 0;

	virtual uint32 GetLocalScreenshotCount( CGameID ) = 0;
	virtual bool GetLocalScreenshot( CGameID, int32, uint32 *, int32 *, int32 *, uint32 *, EScreenshotPrivacyState *, uint64 *, char *, uint32 ) = 0;
	virtual bool SetLocalScreenshotCaption( CGameID, uint32, const char * ) = 0;
	virtual bool SetLocalScreenshotPrivacy( CGameID, uint32, EScreenshotPrivacyState ) = 0;

	virtual bool StartBatch( CGameID ) = 0;
	virtual bool AddToBatch( uint32 ) = 0;
	virtual uint64 UploadBatch( EScreenshotPrivacyState ) = 0;
	virtual uint64 DeleteBatch( bool ) = 0;
	virtual bool CancelBatch() = 0;

	virtual void RecoverOldScreenshots() = 0;
	virtual uint32 GetTaggedUserCount( CGameID, uint32 ) = 0;
	virtual void GetTaggedUser( CGameID, uint32, int32 ) = 0;
	virtual bool GetLocation( CGameID, uint32, char *, uint32 ) = 0;
};

#endif // ICLIENTSCREENSHOTS_H
