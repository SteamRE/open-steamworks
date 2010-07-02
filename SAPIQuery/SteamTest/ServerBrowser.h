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

#ifndef SERVERBROWSER_H
#define SERVERBROWSER_H

#include "Steamworks.h"
#include "CUtlVector.h"

// Class to encapsulate game server data
class CGameServer
{
public:
	CGameServer( gameserveritem_t *pGameServerItem );

	const char* GetName() { return m_szServerName; }

	const char* GetDisplayString() { return m_szServerString; }

	uint32 GetIP() { return m_unIPAddress; }

	int32 GetPort() { return m_nConnectionPort; }
	int32 GetQueryPort() { return m_nQueryPort; }

	CSteamID GetSteamID()	{ return m_steamID; }

	// Asher's
	const char* GetMap() { return m_szMap; }
	int GetPing() { return m_nPing; }
	int GetPlayers() { return m_nPlayers; }
	int GetBotPlayers() { return m_nBotPlayers; }
	int GetMaxPlayers() { return m_nMaxPlayers; }

	bool operator==(const CGameServer &other) const {
		return this->m_steamID == other.m_steamID;
	}

	bool operator!=(const CGameServer &other) const {
		return !(*this == other);
	}

private:
	uint32 m_unIPAddress;			// IP address for the server
	int32 m_nConnectionPort;		// Port for game clients to connect to for this server
	int32 m_nQueryPort;
	int m_nPing;					// current ping time in milliseconds
	char m_szMap[32];				// current map
	char m_szGameDescription[64];	// game description
	int m_nPlayers;					// current number of players on the server
	int m_nMaxPlayers;				// Maximum players that can join this server
	int m_nBotPlayers;				// Number of bots (i.e simulated players) on this server
	bool m_bPassword;				// true if this server needs a password to join
	bool m_bSecure;					// Is this server protected by VAC
	int	m_nServerVersion;			// server version as reported to Steam
	char m_szServerName[64];		// Game server name
	char m_szServerString[128];		// String to show in server browser
	CSteamID m_steamID;
};

class CServerBrowser : public ISteamMatchmakingServerListResponse, public ISteamMatchmakingRulesResponse
{
public:
	CServerBrowser();
	~CServerBrowser();

	// Initiate a refresh of internet servers
	void RefreshInternetServers();

	// Initiate a refresh of LAN servers
	void RefreshLANServers();

	// ISteamMatchmakingServerListResponse
	void ServerResponded( HServerListRequest hReq, int iServer );
	void ServerFailedToRespond( HServerListRequest hReq, int iServer );
	void RefreshComplete( HServerListRequest hReq, EMatchMakingServerResponse response );

	bool IsRefreshing() { return m_bRequestingServers; }

public: // ISteamMatchmakingRulesResponse
	// Got data on a rule on the server -- you'll get one of these per rule defined on
	// the server you are querying
	virtual void RulesResponded( const char *pchRule, const char *pchValue );

	// The server failed to respond to the request for rule details
	virtual void RulesFailedToRespond();

	// The server has finished responding to the rule details request 
	// (ie, you won't get anymore RulesResponded callbacks)
	virtual void RulesRefreshComplete();

public:	
	// List of game servers
	CUtlVector<CGameServer> m_ListGameServers; 

private:
	// Track whether we are in the middle of a refresh or not
	bool m_bRequestingServers;

	// Track what server list request is currently running
	HServerListRequest m_hServerListRequest;
};

#endif //SERVERBROWSER_H