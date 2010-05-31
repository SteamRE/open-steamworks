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

#ifndef FRIENDSCOMMON_H
#define FRIENDSCOMMON_H
#ifdef _WIN32
#pragma once
#endif

#define STEAMFRIENDS_INTERFACE_VERSION_001 "SteamFriends001"
#define STEAMFRIENDS_INTERFACE_VERSION_002 "SteamFriends002"
#define STEAMFRIENDS_INTERFACE_VERSION_003 "SteamFriends003"
#define STEAMFRIENDS_INTERFACE_VERSION_004 "SteamFriends004"
#define STEAMFRIENDS_INTERFACE_VERSION_005 "SteamFriends005"

//-----------------------------------------------------------------------------
// Purpose: called after a friend has been successfully added
//-----------------------------------------------------------------------------
struct FriendAdded_t
{
	enum { k_iCallback = k_iSteamFriendsCallbacks + 1 };
	uint8 m_bSuccess;
	uint64 m_ulSteamID;	// steamID of the friend who was just added
};

//-----------------------------------------------------------------------------
// Purpose: called when a user is requesting friendship
//			the persona details of this user are guaranteed to be available locally
//			at the point this callback occurs
//-----------------------------------------------------------------------------
struct UserRequestingFriendship_t
{
	enum { k_iCallback = k_iSteamFriendsCallbacks + 2 };
	uint64 m_ulSteamID;		// steamID of the friend who just added us
};

//-----------------------------------------------------------------------------
// Purpose: called when a friends' status changes
//-----------------------------------------------------------------------------
struct PersonaStateChangeOld_t
{
	enum { k_iCallback = k_iSteamFriendsCallbacks + 3 };
	uint64 m_ulSteamID;					// steamID of the friend who changed

	// previous state of the user, so comparisons can be done of exactly what changed
	int32 m_ePersonaStatePrevious;
	int32 m_nGameIDPrevious;
	uint32 m_unGameServerIPPrevious;
	uint16 m_usGameServerPortPrevious;
};

//-----------------------------------------------------------------------------
// Purpose: called when a friends' status changes
//-----------------------------------------------------------------------------
struct PersonaStateChange_t
{
	enum { k_iCallback = k_iSteamFriendsCallbacks + 4 };
	
	uint64 m_ulSteamID;		// steamID of the friend who changed
	int m_nChangeFlags;		// what's changed
};

//-----------------------------------------------------------------------------
// Purpose: used to send a system IM from the service to a user
//-----------------------------------------------------------------------------
struct SystemIM_t
{
	enum { k_iCallback = k_iSteamFriendsCallbacks + 5 };
	uint32 m_ESystemIMType;					// type of system IM
	char m_rgchMsgBody[k_cchSystemIMTextMax];		// text associated with message (if any)
};

//-----------------------------------------------------------------------------
// Purpose: called when this client has received a chat/invite/etc. message from a friend
//-----------------------------------------------------------------------------
#pragma pack(push, 1)
struct FriendChatMsg_t
{
	enum { k_iCallback = k_iSteamFriendsCallbacks + 6 };

	CSteamID m_ulReceiver;			// other participant in the msg
	CSteamID m_ulSender;				// steamID of the friend who has sent this message
	uint32 m_iUnknown1;				// unknown
	uint32 m_iChatID;				// chat id
};
#pragma pack(pop)

// 82 FF 0A 00 00 00 88 01 | 0A D7 44 01 01 00 10 01 | 02 00 00 00 | 82 FF 0A 00 | 0A D7 44 01 01 00 10 01 // leaving
// 82 FF 0A 00 00 00 88 01 | 0A D7 44 01 01 00 10 01 | 01 00 00 00 | 40 DD B4 05 | 0A D7 44 01 01 00 10 01 // joining
// 82 FF 0A 00 00 00 88 01 | 0A D7 44 01 01 00 10 01 | 08 00 00 00 | 82 FF 0A 00 | 22 23 E2 03 01 00 10 01 // kicking

#pragma pack(push, 1)
struct GroupJoinLeave_t
{
	enum { k_iCallback = k_iSteamFriendsCallbacks + 10 };

	CSteamID m_GroupID;
	CSteamID m_SteamID;

	uint16 m_iState;
	uint16 m_iAccountID;

	CSteamID m_KickerID;
};
#pragma pack(pop)

// 05 F4 25 33 EA 03 80 01 | AC 15 89 00 01 00 10 01 | 01 E2 EB 06 | 04 00 00 00
// 05 F4 25 33 EA 03 80 01 | AC 15 89 00 01 00 10 01 | 01 E2 EB 06 | 20 00 00 00
// 05 F4 25 33 EA 03 80 01 | 4F 70 A4 01 01 00 10 01 | 01 00 00 00 | 21 00 00 00

#pragma pack(push, 1)
struct GroupChatMsg_t
{
	enum { k_iCallback = k_iSteamFriendsCallbacks + 11 };

	CSteamID m_GroupID;
	CSteamID m_SenderID;
	uint32 m_iUnknown;
	uint32 m_iChatID;
};
#pragma pack(pop)

struct FriendEndChatSession_t
{
	enum { k_iCallback = k_iSteamFriendsCallbacks + 12 };

	CSteamID m_SteamID;
};


// 321 - 16 bytes
// -------------------------------
// 7d 74 08 00 00 00 70 01 00 01 00 00 e0 c6 74 04
// 76 18 00 00 00 00 70 01 00 00 00 00 00 00 00 00
// 1B BB 17 00 00 00 70 01 00 00 00 00 00 00 00 00
// 82 FF 0A 00 00 00 70 01 00 00 00 00 00 00 00 00
struct GroupUnknown_t
{
	enum { k_iCallback = k_iSteamFriendsCallbacks + 21 };

	CSteamID m_GroupID;
	uint64 m_Unknown;
};


// 329 - 16 bytes
// -------------------------------
// 82 FF 0A 00 00 00 88 01 | 0A D7 44 01 01 00 10 01
struct GroupUnknown2_t
{
	enum { k_iCallback = k_iSteamFriendsCallbacks + 29 };

	CSteamID m_GroupID;
	CSteamID m_SteamID;
};


//-----------------------------------------------------------------------------
// Purpose: posted when game overlay activates or deactivates
//			the game can use this to be pause or resume single player games
//-----------------------------------------------------------------------------
struct GameOverlayActivated_t
{
	enum { k_iCallback = k_iSteamFriendsCallbacks + 31 };
	uint8 m_bActive;	// true if it's just been activated, false otherwise
};


//-----------------------------------------------------------------------------
// Purpose: called when the user tries to join a different game server from their friends list
//			game client should attempt to connect to specified server when this is received
//-----------------------------------------------------------------------------
struct GameServerChangeRequested_t
{
	enum { k_iCallback = k_iSteamFriendsCallbacks + 32 };
	char m_rgchServer[64];		// server address ("127.0.0.1:27015", "tf2.valvesoftware.com")
	char m_rgchPassword[64];	// server password, if any
};


//-----------------------------------------------------------------------------
// Purpose: called when the user tries to join a lobby from their friends list
//			game client should attempt to connect to specified lobby when this is received
//-----------------------------------------------------------------------------
struct GameLobbyJoinRequested_t
{
	enum { k_iCallback = k_iSteamFriendsCallbacks + 33 };
	CSteamID m_steamIDLobby;
	CSteamID m_steamIDFriend;		// the friend they did the join via (will be invalid if not directly via a friend)
};



#endif // FRIENDSCOMMON_H
