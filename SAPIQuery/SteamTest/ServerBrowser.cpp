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

#include "ServerBrowser.h"

//-----------------------------------------------------------------------------
// Purpose: Constructor -- initialize from steam gameserveritem_t
//-----------------------------------------------------------------------------
CGameServer::CGameServer( gameserveritem_t *pGameServerItem )
{
	m_unIPAddress = pGameServerItem->m_NetAdr.GetIP();
	m_nConnectionPort = pGameServerItem->m_NetAdr.GetConnectionPort();
	m_nPing = pGameServerItem->m_nPing;
	strncpy( m_szMap, pGameServerItem->m_szMap, ARRAYSIZE( m_szMap ) );
	strncpy( m_szGameDescription, pGameServerItem->m_szGameDescription, ARRAYSIZE( m_szGameDescription ) );
	m_nPlayers = pGameServerItem->m_nPlayers;
	m_nMaxPlayers = pGameServerItem->m_nMaxPlayers;
	m_nBotPlayers = pGameServerItem->m_nBotPlayers;
	m_bPassword = pGameServerItem->m_bPassword;
	m_bSecure = pGameServerItem->m_bSecure;
	m_nServerVersion = pGameServerItem->m_nServerVersion;
	strncpy( m_szServerName, pGameServerItem->GetName(), ARRAYSIZE( m_szServerName ) );
	//_snprintf( m_szServerString, ARRAYSIZE( m_szServerString ), "%s (%i/%i) at %s ping(%d)", pGameServerItem->GetName(), pGameServerItem->m_nPlayers, pGameServerItem->m_nMaxPlayers, pGameServerItem->m_NetAdr.GetConnectionAddressString(), pGameServerItem->m_nPing );
	m_steamID = pGameServerItem->m_steamID;
}


//-----------------------------------------------------------------------------
// Purpose: Constructor
//-----------------------------------------------------------------------------
CServerBrowser::CServerBrowser()
{
	m_nServers = 0;
	m_bRequestingServers = false;
	m_hServerListRequest = NULL;
}


//-----------------------------------------------------------------------------
// Purpose: Destructor
//-----------------------------------------------------------------------------
CServerBrowser::~CServerBrowser()
{
	if ( m_hServerListRequest )
	{
		SteamMatchmakingServers()->ReleaseRequest( m_hServerListRequest );
		m_hServerListRequest = NULL;
	}
}


//-----------------------------------------------------------------------------
// Purpose: Initiate a refresh of internet servers
//-----------------------------------------------------------------------------
void CServerBrowser::RefreshInternetServers()
{
	// If we are still finishing the previous refresh, then ignore this new request
	if ( m_bRequestingServers )
		return;

	// If another request is outstanding, make sure we release it properly
	if ( m_hServerListRequest )
	{
		SteamMatchmakingServers()->ReleaseRequest( m_hServerListRequest );
		m_hServerListRequest = NULL;
	}

	// Track that we are now in a refresh, what type of refresh, and reset our server count
	m_bRequestingServers = true;
	m_nServers = 0;
	m_ListGameServers.clear();

	// Allocate some filters, there are some common pre-defined values that can be used:
	//
	// "gamedir" -- this is used to specify mods inside or a single product/appid
	// "secure" -- this is used to specify whether anti-cheat is enabled for a server
	// "gametype" -- this is used to specify game type and is set to whatever your game server code sets

	MatchMakingKeyValuePair_t pFilters[1];
	MatchMakingKeyValuePair_t *pFilter = pFilters;
	
	strncpy( pFilters[ 0 ].m_szKey, "gamedir", sizeof(pFilters[ 0 ].m_szKey) );
	strncpy( pFilters[ 0 ].m_szValue, "tf", sizeof(pFilters[ 0 ].m_szValue) );

	//strncpy( pFilters[ 1 ].m_szKey, "map", sizeof(pFilters[ 1 ].m_szKey) );
	//strncpy( pFilters[ 1 ].m_szValue, "ctf_turbine", sizeof(pFilters[ 1 ].m_szValue) );
	
	//strncpy( pFilters[ 2 ].m_szKey, "gametype", sizeof(pFilters[ 1 ].m_szValue) );
	//strncpy( pFilters[ 2 ].m_szValue, "dm", sizeof(pFilters[ 1 ].m_szValue) );

	// bugbug jmccaskey - passing just the appid without filters results in getting all servers rather than
	// servers filtered by appid alone.  So, we'll use the filters to filter the results better.
	m_hServerListRequest = SteamMatchmakingServers()->RequestInternetServerList( SteamUtils()->GetAppID(), &pFilter, ARRAYSIZE(pFilters), this );
}


//-----------------------------------------------------------------------------
// Purpose: Initiate a refresh of LAN servers
//-----------------------------------------------------------------------------
void CServerBrowser::RefreshLANServers()
{
	// If we are still finishing the previous refresh, then ignore this new request
	if ( m_bRequestingServers )
		return;

	// If another request is outstanding, make sure we release it properly
	if ( m_hServerListRequest )
	{
		SteamMatchmakingServers()->ReleaseRequest( m_hServerListRequest );
		m_hServerListRequest = NULL;
	}

	// Track that we are now in a refresh, what type of refresh, and reset our server count
	m_bRequestingServers = true;
	m_nServers = 0;
	m_ListGameServers.clear();

	// LAN refresh doesn't accept filters like internet above does
	m_hServerListRequest = SteamMatchmakingServers()->RequestLANServerList( SteamUtils()->GetAppID(), this );
}


//-----------------------------------------------------------------------------
// Purpose: Callback from Steam telling us about a server that has responded
//-----------------------------------------------------------------------------
void CServerBrowser::ServerResponded( HServerListRequest hReq, int iServer )
{
	// Assert( hReq == m_hServerListRequest );

	gameserveritem_t *pServer = SteamMatchmakingServers()->GetServerDetails( hReq, iServer );
	if ( pServer )
	{
		// Filter out servers that don't match our appid here (might get these in LAN calls since we can't put more filters on it)
		if ( pServer->m_nAppID == SteamUtils()->GetAppID() )
		{
			std::cout << ".";

			//if (strncmp(pServer->m_szMap, "tfdb_", 5) == 0)
			//{
			//	std::cout << "Name: " << pServer->GetName() << " - " << "Map: " << pServer->m_szMap << std::endl;

				m_ListGameServers.push_back( CGameServer( pServer ) );
				m_nServers++;
			//}
		}
	}
}


//-----------------------------------------------------------------------------
// Purpose: Callback from Steam telling us about a server that has failed to respond
//-----------------------------------------------------------------------------
void CServerBrowser::ServerFailedToRespond( HServerListRequest hReq, int iServer )
{
	// Assert( hReq == m_hServerListRequest );

	// bugbug jmccaskey - why would we ever need this?  Remove servers from our list I guess?
}


//-----------------------------------------------------------------------------
// Purpose: Callback from Steam telling us a refresh is complete
//-----------------------------------------------------------------------------
void CServerBrowser::RefreshComplete( HServerListRequest hReq, EMatchMakingServerResponse response ) 
{
	// Assert( hReq == m_hServerListRequest );

	// Doesn't really matter to us whether the response tells us the refresh succeeded or failed,
	// we just track whether we are done refreshing or not
	m_bRequestingServers = false; 
}