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

#ifndef ICLIENTMUSIC_H
#define ICLIENTMUSIC_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"

class CMusicQueueEntry;

enum MusicPlayback_Status
{
	// TODO: Reverse this enum
};
enum MediaController_Status
{
	// TODO: Reverse this enum
};

#define CLIENTMUSIC_INTERFACE_VERSION "CLIENTMUSIC_INTERFACE_VERSION001"

abstract_class UNSAFE_INTERFACE IClientMusic
{
public:
		virtual int32 GetQueueCount() = 0;
		virtual CMusicQueueEntry * GetQueueEntry( int32 ) = 0;
		virtual void LoadQueueEntry( int32 ) = 0;
		virtual void AddQueueEntry( CMusicQueueEntry * ) = 0;
		virtual void RemoveQueueEntry( CMusicQueueEntry * ) = 0;
		virtual MusicPlayback_Status GetPlaybackStatus() = 0;
		virtual void Play() = 0;
		virtual void Pause() = 0;
		virtual void Stop() = 0;
		virtual void PlayFirst() = 0;
		virtual void PlayPrevious() = 0;
		virtual void PlayNext() = 0;
		virtual void PlayLast() = 0;
		virtual MediaController_Status GetStatusLocalLibrary() = 0;
		virtual int32 GetLocalLibraryDirectoryEntryCount() = 0;
		virtual bool GetLocalLibraryDirectoryEntry( int32, int32 *, char *, int32, char *, int32, bool * ) = 0;
		virtual void SetLocalLibraryDirectoryEntryEnabled( int32, bool ) = 0;
		virtual void ResetLocalLibraryDirectoriesToDefault() = 0;
		virtual void UpdateLocalLibraryDirectoriesToCrawl() = 0;
		virtual bool BLocalLibraryIsCrawling() = 0;
		virtual int32 GetLocalLibraryAlbumCount() = 0;
		virtual bool GetLocalLibraryAlbumKey( int32, char *, int32 ) = 0;
		virtual bool GetLocalLibraryAlbumNextKey( const char *, bool, char *, int32 ) = 0;
		virtual bool GetLocalLibraryAlbumEntry( const char *, char *, int32, char *, int32, int32 * ) = 0;
		virtual bool GetLocalLibraryAlbumTrackEntry( const char *, int32, char *, int32, int32 * ) = 0;
		virtual bool GetLocalLibraryAlbumTrackKey( const char *, int32, char *, int32 ) = 0;
		virtual void StartUsingSpotify() = 0;
		virtual void StopUsingSpotify() = 0;
		virtual MediaController_Status GetStatusSpotify() = 0;
		virtual void LoginSpotify( const char *, const char * ) = 0;
		virtual void ReloginSpotify() = 0;
		virtual const char * GetCurrentUserSpotify() = 0;
		virtual void ForgetCurrentUserSpotify() = 0;
		virtual void LogoutSpotify() = 0;
		virtual void DumpStatusToConsole() = 0;
};

#endif // ICLIENTMUSIC_H
