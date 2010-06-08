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

#ifndef REMOTESTORAGECOMMON_H
#define REMOTESTORAGECOMMON_H
#ifdef _WIN32
#pragma once
#endif



#define STEAMREMOTESTORAGE_INTERFACE_VERSION_001 "STEAMREMOTESTORAGE_INTERFACE_VERSION001"
#define STEAMREMOTESTORAGE_INTERFACE_VERSION_002 "STEAMREMOTESTORAGE_INTERFACE_VERSION002"

#define CLIENTREMOTESTORAGE_INTERFACE_VERSION "CLIENTREMOTESTORAGE_INTERFACE_VERSION001"



typedef enum ERemoteStorageFileRoot
{
	k_ERemoteStorageFileRootInvalid = 0,
	k_ERemoteStorageFileRootDefault,
	k_ERemoteStorageFileRootMax
} ERemoteStorageFileRoot;

typedef enum ERemoteStorageSyncState
{
	k_ERemoteSyncStateUnknown = 0,
	k_ERemoteSyncStateSynchronized = 1,
	k_ERemoteSyncStateSyncInProgress = 2,
	k_ERemoteSyncStatePendingChangesInCloud = 3,
	k_ERemoteSyncStatePendingChangesLocally = 4,
	k_ERemoteSyncStatePendingChangesInCloudAndLocally = 5,
} ERemoteStorageSyncState;




#endif // REMOTESTORAGECOMMON_H
