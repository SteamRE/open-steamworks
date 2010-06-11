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

#ifndef ISTEAMMATCHMAKINGSERVERS002_H
#define ISTEAMMATCHMAKINGSERVERS002_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "MatchmakingServersCommon.h"


//-----------------------------------------------------------------------------
// Purpose: Functions for match making services for clients to get to game lists and details
//-----------------------------------------------------------------------------
class ISteamMatchmakingServers002
{
public:
	// Request a new list of servers of a particular type.
	virtual void *RequestInternetServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse002 *pRequestServersResponse ) = 0;
	virtual void *RequestLANServerList( AppId_t iApp, ISteamMatchmakingServerListResponse002 *pRequestServersResponse ) = 0;
	virtual void *RequestFriendsServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse002 *pRequestServersResponse ) = 0;
	virtual void *RequestFavoritesServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse002 *pRequestServersResponse ) = 0;
	virtual void *RequestHistoryServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse002 *pRequestServersResponse ) = 0;
	virtual void *RequestSpectatorServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse002 *pRequestServersResponse ) = 0;

	/* the filters that are available in the ppchFilters params are:

		"map"		- map the server is running, as set in the dedicated server api
		"dedicated" - reports bDedicated from the API
		"secure"	- VAC-enabled
		"full"		- not full
		"empty"		- not empty
		"noplayers" - is empty
		"proxy"		- a relay server

	*/

	virtual unknown_ret ReleaseRequest( void *pRequest ) = 0;	// do requests return void* now?
																// i'm assuming they do, this makes logical sense with all the below functions

	virtual gameserveritem_t *GetServerDetails( void *pRequest, int iServer ) = 0;

	// Cancel an request which is operation on the given list type.  You should call this to cancel
	// any in-progress requests before destructing a callback object that may have been passed 
	// to one of the above list request calls.  Not doing so may result in a crash when a callback
	// occurs on the destructed object.
	virtual void CancelQuery( void *pRequest ) = 0; 

	// Ping every server in your list again but don't update the list of servers
	virtual void RefreshQuery( void *pRequest ) = 0; 

	// Returns true if the list is currently refreshing its server list
	virtual bool IsRefreshing( void *pRequest ) = 0; 

	// How many servers in the given list, GetServerDetails above takes 0... GetServerCount() - 1
	virtual int GetServerCount( void *pRequest ) = 0; 

	// Refresh a single server inside of a query (rather than all the servers )
	virtual void RefreshServer( void *pRequest, int iServer ) = 0; 


	//-----------------------------------------------------------------------------
	// Queries to individual servers directly via IP/Port
	//-----------------------------------------------------------------------------

	// Request updated ping time and other details from a single server
	virtual HServerQuery PingServer( uint32 unIP, uint16 usPort, ISteamMatchmakingPingResponse *pRequestServersResponse ) = 0; 

	// Request the list of players currently playing on a server
	virtual HServerQuery PlayerDetails( uint32 unIP, uint16 usPort, ISteamMatchmakingPlayersResponse *pRequestServersResponse ) = 0;

	// Request the list of rules that the server is running (See ISteamMasterServerUpdater->SetKeyValue() to set the rules server side)
	virtual HServerQuery ServerRules( uint32 unIP, uint16 usPort, ISteamMatchmakingRulesResponse *pRequestServersResponse ) = 0; 

	// Cancel an outstanding Ping/Players/Rules query from above.  You should call this to cancel
	// any in-progress requests before destructing a callback object that may have been passed 
	// to one of the above calls to avoid crashing when callbacks occur.
	virtual void CancelServerQuery( HServerQuery hServerQuery ) = 0; 
};


#endif // ISTEAMMATCHMAKINGSERVERS002_H
