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

#ifndef NETWORKINGCOMMON_H
#define NETWORKINGCOMMON_H
#ifdef _WIN32
#pragma once
#endif

// connection state to a specified user, returned by GetP2PSessionState()
// this is under-the-hood info about what's going on with a SendP2PPacket(), shouldn't be needed except for debuggin
struct P2PSessionState_t
{
	uint8 m_bConnectionActive;		// true if we've got an active open connection
	uint8 m_bConnecting;			// true if we're currently trying to establish a connection
	uint8 m_eP2PSessionError;		// last error recorded (see enum above)
	uint8 m_bUsingRelay;			// true if it's going through a relay server (TURN)
	int32 m_nBytesQueuedForSend;
	int32 m_nPacketsQueuedForSend;
	uint32 m_nRemoteIP;				// potential IP:Port of remote host. Could be TURN server. 
	uint16 m_nRemotePort;			// Only exists for compatibility with older authentication api's
};


#define STEAMNETWORKING_INTERFACE_VERSION_001 "SteamNetworking001"
#define STEAMNETWORKING_INTERFACE_VERSION_002 "SteamNetworking002"
#define STEAMNETWORKING_INTERFACE_VERSION_003 "SteamNetworking003"

// callback notification - status of a socket has changed
struct SocketStatusCallback_t
{ 
	enum { k_iCallback = k_iSteamNetworkingCallbacks + 1 };
	SNetSocket_t m_hSocket;				// the socket used to send/receive data to the remote host
	SNetListenSocket_t m_hListenSocket;	// this is the server socket that we were listening on; NULL if this was an outgoing connection
	CSteamID m_steamIDRemote;			// remote steamID we have connected to, if it has one
	int m_eSNetSocketState;				// socket state, ESNetSocketState
};


// callback notification - a user wants to talk to us over the P2P channel via the SendP2PPacket() API
// in response, a call to AcceptP2PPacketsFromUser() needs to be made, if you want to talk with them
struct P2PSessionRequest_t
{ 
	enum { k_iCallback = k_iSteamNetworkingCallbacks + 2 };
	CSteamID m_steamIDRemote;			// user who wants to talk to us
};


// callback notification - packets can't get through to the specified user via the SendP2PPacket() API
// all packets queued packets unsent at this point will be dropped
// further attempts to send will retry making the connection (but will be dropped if we fail again)
struct P2PSessionConnectFail_t
{ 
	enum { k_iCallback = k_iSteamNetworkingCallbacks + 3 };
	CSteamID m_steamIDRemote;			// user we were sending packets to
	uint8 m_eP2PSessionError;			// EP2PSessionError indicating why we're having trouble
};

#endif // NETWORKINGCOMMON_H
