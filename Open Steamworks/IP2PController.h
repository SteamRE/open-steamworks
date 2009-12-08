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

#ifndef IP2PCONTROLLER_H
#define IP2PCONTROLLER_H
#ifdef _WIN32
#pragma once
#endif


#include "SteamTypes.h"

#define P2PCONTROLLER_INTERFACE_VERSION "P2PCONTROLLER_INTERFACE_VERSION001"


class UNSAFE_INTERFACE IP2PController
{
public:
	virtual unknown_ret Start() = 0;

	virtual bool IsEnabled() = 0;

	virtual unknown_ret SetAutoGeneratePerTorrentSteamIDs( bool ) = 0;

	//virtual unknown_ret LoadVST( const CSteamID*, const char*, SimulationParams_t * ) = 0;
	virtual unknown_ret LoadVST( const CSteamID*, const char*, uint32* ) = 0;

	virtual unknown_ret GetActiveHandleCount() = 0;

	virtual unknown_ret GetHandle( int ) = 0;

	virtual unknown_ret Activate( uint32, bool ) = 0;
	virtual unknown_ret Deactivate( uint32, bool ) = 0;
	virtual unknown_ret Remove( uint32 ) = 0;

	virtual unknown_ret GetStatusSnapshot( uint32 ) = 0;

	virtual bool IsCompleted( uint32 ) = 0;
	virtual bool IsActive( uint32 ) = 0;
	virtual bool IsChecking( uint32 ) = 0;

	virtual unknown_ret GetValue( uint32, const char* ) = 0;
	virtual unknown_ret GetSharingSaveFolder() = 0;
	virtual unknown_ret SetSharingSaveFolder( const char* ) = 0;
	virtual unknown_ret GetSharingTemporaryFolder() = 0;
	virtual unknown_ret SetSharingTemporaryFolder( const char* ) = 0;

	virtual unknown_ret GetVSTFolder() = 0;
	virtual unknown_ret SetVSTFolder( const char* ) = 0;

	virtual unknown_ret SetShareType( ShareType_t ) = 0;
	virtual ShareType_t GetShareType() = 0;

	virtual unknown_ret SetUploadBitsPerSecond( int ) = 0;
	virtual unknown_ret GetUploadBitsPerSecond() = 0;

	virtual unknown_ret GetNumFiles( uint32 ) = 0;

	virtual unknown_ret GetFile( uint32, int ) = 0;

	//virtual unknown_ret GetP2PFileInfo( uint32, int, TorrentFileInfo_t * ) = 0;
	virtual unknown_ret GetP2PFileInfo( uint32, int, uint32 * ) = 0;
	virtual unknown_ret GetBlockStates( uint32, int, uint8 * ) = 0;
	virtual unknown_ret GetAvailBlocks( uint32, int, uint16 * ) = 0;
	//virtual unknown_ret GetPeerInfo( uint32, int, PeerInfo_t * ) = 0;
	virtual unknown_ret GetPeerInfo( uint32, int, uint32 * ) = 0;
	virtual unknown_ret GetPeerBlockInfo( uint32, uint32, int, uint8 * ) = 0;
	virtual unknown_ret GetP2PKeyValues( uint32 ) = 0;
	virtual unknown_ret GetP2POptions( uint32 ) = 0;

	virtual unknown_ret MarkP2POptionsDirty( uint32 ) = 0;

	virtual unknown_ret SaveP2POptions( uint32 ) = 0;

	//virtual unknown_ret GetP2PFileID( uint32, VstFileID *, uint32 ) = 0;
	virtual unknown_ret GetP2PFileID( uint32, uint32 *, uint32 ) = 0;

	virtual unknown_ret GetP2PGlobalOptions() = 0;
	virtual unknown_ret MarkP2PGlobalOptionsDirty() = 0;
	virtual unknown_ret ResetGlobalOptionsToDefaults() = 0;

	virtual unknown_ret DeleteLocalContent( uint32 ) = 0;

	virtual unknown_ret ResetToMissing( uint32 ) = 0;

	virtual unknown_ret Validate( uint32 ) = 0;

	virtual unknown_ret OnCopyCompleted( uint32 ) = 0;

	virtual unknown_ret GetCopyFileNames( uint32, int, char *, uint32, char *, uint32 ) = 0;

	virtual bool IsUserActive( uint32 ) = 0;

	//virtual unknown_ret GetFileIDFromVST( const char*, VstFileID *, uint32 ) = 0
	virtual unknown_ret GetFileIDFromVST( const char*, uint32 *, uint32 ) = 0;

	//virtual unknown_ret SetHostType( IP2PEngine::EP2PHostType ) = 0;
	virtual unknown_ret SetHostType( uint32 ) = 0;

	virtual unknown_ret SetRegistryHive( char  const* ) = 0;
};


#endif // IP2PCONTROLLER_H
