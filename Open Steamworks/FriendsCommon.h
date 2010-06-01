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



#define CLIENTFRIENDS_INTERFACE_VERSION "CLIENTFRIENDS_INTERFACE_VERSION001"

#define STEAMFRIENDS_INTERFACE_VERSION_001 "SteamFriends001"
#define STEAMFRIENDS_INTERFACE_VERSION_002 "SteamFriends002"
#define STEAMFRIENDS_INTERFACE_VERSION_003 "SteamFriends003"
#define STEAMFRIENDS_INTERFACE_VERSION_004 "SteamFriends004"
#define STEAMFRIENDS_INTERFACE_VERSION_005 "SteamFriends005"



//-----------------------------------------------------------------------------
// Purpose: avatar sizes, used in ISteamFriends::GetFriendAvatar()
//-----------------------------------------------------------------------------
typedef enum EAvatarSize
{
	k_EAvatarSize32x32 = 0,
	k_EAvatarSize64x64 = 1,
} EAvatarSize;

typedef enum ECallState
{
	k_ECallStateUnknown = 0,
	k_ECallStateWaiting = 1,
	k_ECallStateDialing = 2,
	k_ECallStateRinging = 3,
	k_ECallStateInCall = 4,
} ECallState;

//-----------------------------------------------------------------------------
// Purpose: Chat Entry Types (previously was only friend-to-friend message types)
//-----------------------------------------------------------------------------
typedef enum EChatEntryType
{
	k_EChatEntryTypeInvalid = 0, 
	k_EChatEntryTypeChatMsg = 1,		// Normal text message from another user
	k_EChatEntryTypeTyping = 2,			// Another user is typing (not used in multi-user chat)
	k_EChatEntryTypeInviteGame = 3,		// Invite from other user into that users current game
	k_EChatEntryTypeEmote = 4,			// text emote message
	k_EChatEntryTypeLobbyGameStart = 5,	// lobby game is starting
	k_EChatEntryTypeLeftConversation = 6, // user has left the conversation ( closed chat window )
	// Above are previous FriendMsgType entries, now merged into more generic chat entry types
} EChatEntryType;

// Type of system IM.  The client can use this to do special UI handling in specific circumstances
typedef enum ESystemIMType
{
	k_ESystemIMRawText = 0,
	k_ESystemIMInvalidCard = 1,
	k_ESystemIMRecurringPurchaseFailed = 2,
	k_ESystemIMCardWillExpire = 3,
	k_ESystemIMSubscriptionExpired = 4,

	k_ESystemIMTypeMax
} ESystemIMType;

//-----------------------------------------------------------------------------
// Purpose: set of relationships to other users
//-----------------------------------------------------------------------------
typedef enum EFriendRelationship
{
	k_EFriendRelationshipNone = 0,
	k_EFriendRelationshipBlocked = 1,
	k_EFriendRelationshipRequestRecipient = 2,
	k_EFriendRelationshipFriend = 3,
	k_EFriendRelationshipRequestInitiator = 4,
	k_EFriendRelationshipIgnored = 5,
	k_EFriendRelationshipIgnoredFriend = 6,
} EFriendRelationship;

typedef enum EChatRoomType
{
	k_EChatRoomTypeFriend = 1,
	k_EChatRoomTypeMUC = 2,
	k_EChatRoomTypeLobby = 3,
} EChatRoomType;

typedef enum EChatRoomVoiceStatus
{
	eChatRoomVoiceStatusBad = 0,
	eChatRoomVoiceStatusUnknownRoom = 1,
	eChatRoomVoiceStatusUnknownUser = 2,
	eChatRoomVoiceStatusNotSpeaking = 3,
	eChatRoomVoiceStatusConnectedSpeaking = 4,
	eChatRoomVoiceStatusConnectedSpeakingData = 5,
	eChatRoomVoiceStatusNotConnectedSpeaking = 6,
	eChatRoomVoiceStatusConnecting = 7,
	eChatRoomVoiceStatusUnreachable = 8,
	eChatRoomVoiceStatusDisconnected = 9,
	eChatRoomVoiceStatusCount = 10,
} EChatRoomVoiceStatus;

typedef enum EClanRank
{
	k_EClanRankNone = 0,
	k_EClanRankOwner = 1,
	k_EClanRankOfficer = 2,
	k_EClanRankMember = 3,
} EClanRank;

typedef enum EClanRelationship
{
	eClanRelationshipNone = 0,
	eClanRelationshipBlocked = 1,
	eClanRelationshipInvited = 2,
	eClanRelationshipMember = 3,
	eClanRelationshipKicked = 4,
} EClanRelationship;

// for enumerating friends list
typedef enum EFriendFlags
{
	k_EFriendFlagNone			= 0x00,
	k_EFriendFlagBlocked		= 0x01,
	k_EFriendFlagFriendshipRequested	= 0x02,
	k_EFriendFlagImmediate		= 0x04,			// "regular" friend
	k_EFriendFlagClanMember		= 0x08,
	k_EFriendFlagOnGameServer	= 0x10,	
	//	k_EFriendFlagHasPlayedWith	= 0x20,	// not currently used
	//	k_EFriendFlagFriendOfFriend	= 0x40,	// not currently used
	k_EFriendFlagRequestingFriendship = 0x80,
	k_EFriendFlagRequestingInfo = 0x100,
	k_EFriendFlagIgnored		= 0x200,
	k_EFriendFlagIgnoredFriend	= 0x400,
	k_EFriendFlagAll			= 0xFFFF,
} EFriendFlags;
// for backwards compat
typedef EFriendFlags k_EFriendFlags;

//-----------------------------------------------------------------------------
// Purpose: friend-to-friend message types
//-----------------------------------------------------------------------------
typedef enum EFriendMsgType
{
	k_EFriendMsgTypeChat = 1,			// chat test message
	k_EFriendMsgTypeTyping = 2,			// lets the friend know the other user has starting typing a chat message
	k_EFriendMsgTypeInvite = 3,			// invites the friend into the users current game
	k_EFriendMsgTypeChatSent = 4,		// chat that the user has sent to a friend
} EFriendMsgType;

//-----------------------------------------------------------------------------
// Purpose: list of states a friend can be in
//-----------------------------------------------------------------------------
typedef enum EPersonaState
{
	k_EPersonaStateOffline = 0,			// friend is not currently logged on
	k_EPersonaStateOnline = 1,			// friend is logged on
	k_EPersonaStateBusy = 2,			// user is on, but busy
	k_EPersonaStateAway = 3,			// auto-away feature
	k_EPersonaStateSnooze = 4,			// auto-away for a long time
	k_EPersonaStateMax,
} EPersonaState;

// used in PersonaStateChange_t::m_nChangeFlags to describe what's changed about a user
// these flags describe what the client has learned has changed recently, so on startup you'll see a name, avatar & relationship change for every friend
typedef enum EPersonaChange
{
	k_EPersonaChangeName		= 0x001,
	k_EPersonaChangeStatus		= 0x002,
	k_EPersonaChangeComeOnline	= 0x004,
	k_EPersonaChangeGoneOffline	= 0x008,
	k_EPersonaChangeGamePlayed	= 0x010,
	k_EPersonaChangeGameServer	= 0x020,
	k_EPersonaChangeAvatar		= 0x040,
	k_EPersonaChangeJoinedSource= 0x080,
	k_EPersonaChangeLeftSource	= 0x100,
	k_EPersonaChangeRelationshipChanged = 0x200,
	k_EPersonaChangeNameFirstSet = 0x400,
} EPersonaChange;



//-----------------------------------------------------------------------------
// Purpose: called after a friend has been successfully added
//-----------------------------------------------------------------------------
struct FriendAdded_t
{
	enum { k_iCallback = k_iSteamFriendsCallbacks + 1 };

	uint8 m_bSuccess;
	CSteamID m_ulSteamID;	// steamID of the friend who was just added
};

//-----------------------------------------------------------------------------
// Purpose: called when a user is requesting friendship
//			the persona details of this user are guaranteed to be available locally
//			at the point this callback occurs
//-----------------------------------------------------------------------------
struct UserRequestingFriendship_t
{
	enum { k_iCallback = k_iSteamFriendsCallbacks + 2 };

	CSteamID m_ulSteamID;		// steamID of the friend who just added us
};

//-----------------------------------------------------------------------------
// Purpose: called when a friends' status changes, seems to not be used anymore
//-----------------------------------------------------------------------------
struct PersonaStateChangeOld_t
{
	enum { k_iCallback = k_iSteamFriendsCallbacks + 3 };

	CSteamID m_ulSteamID;					// steamID of the friend who changed

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
	
	CSteamID m_ulSteamID;		// steamID of the friend who changed
	EPersonaChange m_nChangeFlags;		// what's changed
};

//-----------------------------------------------------------------------------
// Purpose: used to send a system IM from the service to a user
//-----------------------------------------------------------------------------
struct SystemIM_t
{
	enum { k_iCallback = k_iSteamFriendsCallbacks + 5 };

	ESystemIMType m_ESystemIMType;					// type of system IM
	char m_rgchMsgBody[ k_cchSystemIMTextMax ];		// text associated with message (if any)
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
	uint32 m_iUnknown1;				// unknown. todo: this is possibly a EChatEntryType
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

	EChatMemberStateChange m_eGroupEvent;
	uint16 m_iChatAccountID;

	CSteamID m_KickerID; // this is the admin steamid that kicked, otherwise the steamid that joined, left, etc
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
