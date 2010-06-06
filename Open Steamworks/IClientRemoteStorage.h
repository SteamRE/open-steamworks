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

	virtual unknown_ret FileWrite( AppId_t nAppId, ERemoteStorageFileRoot, char  const*,void  const*, int ) = 0;
	virtual unknown_ret GetFileSize( AppId_t nAppId, ERemoteStorageFileRoot, char  const* ) = 0;
	virtual unknown_ret FileRead( AppId_t nAppId, ERemoteStorageFileRoot, char  const*, void *, int ) = 0;
	virtual bool FileExists( AppId_t nAppId, ERemoteStorageFileRoot, char  const* ) = 0;
	virtual int GetFileCount( AppId_t nAppId ) = 0;
	virtual unknown_ret GetFileNameAndSize( AppId_t nAppId, int, int * ) = 0;
	virtual unknown_ret GetQuota( AppId_t nAppId, int *, int * ) = 0;
	virtual unknown_ret FilePersist( AppId_t nAppId, ERemoteStorageFileRoot, char  const* ) = 0;
	virtual unknown_ret FileForget( AppId_t nAppId, ERemoteStorageFileRoot, char  const* ) = 0;
	virtual unknown_ret ResolvePath( AppId_t nAppId, ERemoteStorageFileRoot, char  const*, char *, unsigned int ) = 0;
	virtual unknown_ret GetFileCountEx( AppId_t nAppId ) = 0;
	virtual unknown_ret GetFileNameAndSizeEx( AppId_t nAppId, int, ERemoteStorageFileRoot *, int * ) = 0;
	virtual unknown_ret LoadLocalFileInfoCache( AppId_t nAppId ) = 0;
	virtual unknown_ret EvaluateRemoteStorageSyncState( AppId_t nAppId ) = 0;
	virtual unknown_ret GetRemoteStorageSyncState( AppId_t nAppId ) = 0;
	virtual unknown_ret HaveLatestFilesLocally( AppId_t nAppId ) = 0;
	virtual unknown_ret GetConflictingFileTimestamps( AppId_t nAppId, unsigned int *, unsigned int * ) = 0;
	virtual unknown_ret ResolveSyncConflict( AppId_t nAppId, bool ) = 0;
	virtual unknown_ret SynchronizeApp( AppId_t nAppId, bool, bool ) = 0;
	virtual bool IsAppSyncInProgress( AppId_t nAppId ) = 0;
	virtual ERemoteStorageFileRoot ERemoteStorageFileRootFromName( char  const* ) = 0;
	virtual const char* PchNameFromERemoteStorageFileRoot( ERemoteStorageFileRoot ) = 0;
};

#endif // ICLIENTREMOTESTORAGE_H
