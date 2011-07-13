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

#ifndef ICLIENTDEPOTBUILDER_H
#define ICLIENTDEPOTBUILDER_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"



#define CLIENTDEPOTBUILDER_INTERFACE_VERSION "CLIENTDEPOTBUILDER_INTERFACE_VERSION001"



typedef enum EDepotBuildStatus
{
	k_EDepotBuildStatusInvalid = -1,
	k_EDepotBuildStatusFailed = 0,
	k_EDepotBuildStatusProcessingConfig = 1,
	k_EDepotBuildStatusProcessingData = 2,
	k_EDepotBuildStatusUploadingData = 3,
	k_EDepotBuildStatusCompleted = 4,
}  EDepotBuildStatus;

//-----------------------------------------------------------------------------
// Purpose: Status of a given depot version, these are stored in the DB, don't renumber
//-----------------------------------------------------------------------------
typedef enum EStatusDepotVersion
{
	k_EStatusDepotVersionInvalid = 0,
	k_EStatusDepotVersionCompleteDisabled = 1,
	k_EStatusDepotVersionCompleteEnabledBeta = 2,
	k_EStatusDepotVersionCompleteEnabledPublic = 3,
} EStatusDepotVersion;


typedef uint32 HDEPOTBUILD;


abstract_class IClientDepotBuilder
{

public:
	virtual HDEPOTBUILD InitializeDepotBuildForConfigFile( const char *pchConfigFile ) = 0;
	
	virtual bool StartBuild( HDEPOTBUILD hDepotBuild, bool, bool, const char * pchBetaKey ) = 0;

	virtual bool BGetDepotBuildStatus( HDEPOTBUILD hDepotBuild, EDepotBuildStatus* pStatusOut, uint32* pPercentDone ) = 0;
	virtual bool CloseDepotBuildHandle( HDEPOTBUILD hDepotBuild ) = 0;

	virtual HDEPOTBUILD ReconstructDepotFromManifestAndChunks( const char *pchLocalManifestPath, const char *pchLocalChunkPath, const char *pchRestorePath ) = 0;

	virtual bool BGetChunkCounts( HDEPOTBUILD hDepotBuild, uint32 *unTotalChunksInNewBuild, uint32 *unChunksAlsoInOldBuild ) = 0;

	virtual bool GetManifestGIDs( HDEPOTBUILD hDepotBuild, uint64 *, uint64 * ) = 0;

	virtual uint32 RebaseAndBuildDepot( uint64, uint64 ) = 0;
};

#endif // ICLIENTDEPOTBUILDER_H
