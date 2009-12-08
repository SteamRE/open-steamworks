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

class IClientDepotBuilder
{
public:
	virtual HDepotBuild InitializeDepotBuildForConfigFile( const char *pchConfigFile ) = 0;

	virtual bool GetDepotBuildStatus( HDepotBuild hDepotBuild, EDepotBuildStatus* pStatusOut, uint32* pPercentDone ) = 0;

	virtual bool CloseDepotBuildHandle( HDepotBuild hDepotBuild ) = 0;

	virtual int ReconstructDepotFromManifestAndChunks( const char *a, const char *b, const char *c ) = 0;
};

#endif // ICLIENTDEPOTBUILDER_H
