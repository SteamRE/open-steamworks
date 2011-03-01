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

#ifndef ICLIENTREMOTESTORAGE_H
#define ICLIENTREMOTESTORAGE_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "RemoteStorageCommon.h"

class UNSAFE_INTERFACE IClientRemoteStorage
{
public:

	virtual bool FileWrite( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile, const void *pvData, int cubData ) = 0;
	virtual int32 GetFileSize( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile  ) = 0;

	virtual int FileRead( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile, void *pvData, int cubDataToRead ) = 0;
	
	virtual bool FileForget( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile ) = 0;
	virtual bool FileDelete( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile ) = 0;
	virtual SteamAPICall_t FileShare( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile ) = 0;

	virtual bool FileExists( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile ) = 0;

	virtual bool FilePersisted( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile ) = 0;
	virtual int64 GetFileTimestamp( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile ) = 0;

	virtual bool SetSyncPlatforms( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile, int iUnk ) = 0;
	virtual int GetSyncPlatforms( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile ) = 0;

	virtual int32 GetFileCount( AppId_t nAppId, bool bUnk1 ) = 0;
	virtual const char *GetFileNameAndSize( AppId_t nAppId, int iFile, int *pnFileSizeInBytes, int iUnk2 ,bool bUnk1 ) = 0;

	virtual bool GetQuota( AppId_t nAppId, int32 *pnTotalBytes, int32 *pnAvailableBytes ) = 0;
	
	virtual bool IsCloudEnabledForAccount();
	virtual bool IsCloudEnabledForApp( AppId_t nAppId );
	virtual bool SetCloudEnabledForApp( AppId_t nAppId, bool bEnable );

	virtual unknown_ret UGCDownload( unknown_ret unk1, unknown_ret unk2 ) = 0;
	virtual unknown_ret GetUGCDetails( unknown_ret unk1, unknown_ret unk2,  unknown_ret unk3,  unknown_ret unk4,  unknown_ret unk5,  unknown_ret unk6 ) = 0;
	virtual unknown_ret UGCRead( unknown_ret unk1, unknown_ret unk2,  unknown_ret unk3,  unknown_ret unk4 ) = 0;
	virtual int32 GetCachedUGCCount() = 0;
	virtual unknown_ret GetCachedUGCHandle() = 0;
	
	virtual const char* GetShortcutDisplayName( CGameID GameID ) = 0;
	virtual void SetShortcutDisplayName( CGameID GameID, const char* szName ) = 0;
	virtual bool ScreenshotWrite( CGameID GameID, const uint8 *pubRGBData, uint32 uRGBDataSize, uint32 uWidth, uint32 uHeight ) = 0;
	virtual bool ScreenshotResolvePath( CGameID GameID, const char * szFilename, bool bUnk, char* szResolvedPath, uint32 cubResolvedPath ) = 0;
	virtual uint32 ScreenshotGetFileSize( CGameID GameID, const char * szFilename ) = 0;
	virtual uint32 GetNumGamesWithLocalScreenshots() = 0;
	virtual CGameID GetGameWithLocalScreenshots( uint32 uIndex ) = 0;
	virtual uint32 GetLocalScreenshotCount( CGameID GameID ) = 0;
	virtual bool GetLocalScreenshot( CGameID GameID, uint32 uIndex, char* pchFilename, uint32 cubFilename, uint32* puWidth, uint32* puHeight, uint32* puTimestamp, EScreenshotPrivacy* pePrivacy, uint64* pulUnk, char* pchCaption, uint32 cubCaption ) = 0;
	virtual bool SetLocalScreenshotCaption( CGameID GameID, const char * szFilename, const char * szCaption ) = 0;
	virtual bool SetLocalScreenshotPrivacy( CGameID GameID, const char * szFilename, EScreenshotPrivacy ePrivacy ) = 0;
	virtual bool ScreenshotStartBatch( CGameID GameID ) = 0;
	virtual bool ScreenshotAddToBatch( const char* szFilename ) = 0;
	virtual SteamAPICall_t ScreenshotUploadBatch( EScreenshotPrivacy ePrivacy ) = 0;
	virtual SteamAPICall_t ScreenshotDeleteBatch( bool bDeleteFromCloud ) = 0;
	virtual bool ScreenshotCancelBatch() = 0;
	virtual void RecoverOldScreenshots() = 0;

	virtual unknown_ret FilePersist( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *pchFile ) = 0;

	virtual unknown_ret ResolvePath( AppId_t nAppId, ERemoteStorageFileRoot eRemoteStorageFileRoot, const char *, char *, uint32 ) = 0;

	virtual bool SetCloudEnabledForAccount( bool bEnable);

	virtual unknown_ret LoadLocalFileInfoCache( AppId_t nAppId ) = 0;

	virtual unknown_ret EvaluateRemoteStorageSyncState( AppId_t nAppId ) = 0;
	virtual ERemoteStorageSyncState GetRemoteStorageSyncState( AppId_t nAppId ) = 0;

	virtual bool HaveLatestFilesLocally( AppId_t nAppId ) = 0;

	virtual unknown_ret GetConflictingFileTimestamps( AppId_t nAppId, uint32 *, uint32 * ) = 0;
	virtual unknown_ret ResolveSyncConflict( AppId_t nAppId, bool ) = 0;

	virtual void SynchronizeApp( AppId_t nAppId, bool bSyncClient, bool bSyncServer ) = 0;
	virtual bool IsAppSyncInProgress( AppId_t nAppId ) = 0;

	virtual ERemoteStorageFileRoot ERemoteStorageFileRootFromName( const char * ) = 0;
	virtual const char* PchNameFromERemoteStorageFileRoot( ERemoteStorageFileRoot eRemoteStorageFileRoot ) = 0;
};

#endif // ICLIENTREMOTESTORAGE_H
