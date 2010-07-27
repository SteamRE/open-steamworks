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

#ifndef ISTEAMGAMECOORDINATORCOMMON_H
#define ISTEAMGAMECOORDINATORCOMMON_H
#ifdef _WIN32
#pragma once
#endif



#define CLIENTGAMECOORDINATOR_INTERFACE_VERSION "CLIENTGAMECOORDINATOR_INTERFACE_VERSION001"

#define STEAMGAMECOORDINATOR_INTERFACE_VERSION_001 "SteamGameCoordinator001"



typedef enum EGCMsgResponse
{
	k_EGCMsgResponseOK,
	k_EGCMsgResponseDenied,
	k_EGCMsgResponseServerError,
	k_EGCMsgResponseTimeout,
	k_EGCMsgResponseInvalid,
	k_EGCMsgResponseNoMatch,
	k_EGCMsgResponseUnknownError,
	k_EGCMsgResponseNotLoggedOn,
} EGCMsgResponse;

// list of possible return values from the ISteamGameCoordinator API
typedef enum EGCResults
{
	k_EGCResultOK = 0,
	k_EGCResultNoMessage = 1,			// There is no message in the queue
	k_EGCResultBufferTooSmall = 2,		// The buffer is too small for the requested message
	k_EGCResultNotLoggedOn = 3,			// The client is not logged onto Steam
	k_EGCResultInvalidMessage = 4,		// Something was wrong with the message being sent with SendMessage
} EGCResults;

typedef enum EGCMessages
{
	k_ESOMsg_Create = 21,
	k_ESOMsg_Update,
	k_ESOMsg_Destroy,
	k_ESOMsg_CacheSubscribed,
	k_ESOMsg_CacheUnsubscribed,

	k_EGCMsgStartPlaying = 53,
	k_EGCMsgStopPlaying,
	k_EGCMsgStartGameserver,
	k_EGCMsgStopGameserver,
	k_EGCMsgWGRequest,

	k_EGCMsgGetUserGameStatsSchema = 59,
	k_EGCMsgGetUserGameStatsSchemaResponse,
	k_EGCMsgGetUserStats,
	k_EGCMsgGetUserStatsResponse,
	k_EGCMsgAppInfoUpdated,
	k_EGCMsgValidateSession,
	k_EGCMsgValidateSessionResponse,
	k_EGCMsgLookupAccountFromInput,
	k_EGCMsgSendHTTPRequest,
	k_EGCMsgSendHTTPRequestResponse,
	k_EGCMsgPreTestSetup,
	k_EGCMsgRecordSupportAction,
	k_EGCMsgGetAccountDetails,
	k_EGCMsgSendInterAppMessage,
	k_EGCMsgReceiveInterAppMessage,

	k_EGCMsgWebAPIRegisterInterfaces = 101,
	k_EGCMsgWebAPIJobRequest,
	k_EGCMsgWebAPIRegistrationRequested,

	k_EMsgGCSetItemPosition = 1001,
	k_EMsgGCCraft,
	k_EMsgGCCraftResponse,
	k_EMsgGCDelete,
	k_EMsgGCVerifyCacheSubscription,
	k_EMsgGCNameItem,
	k_EMsgGCDecodeItem,
	k_EMsgGCDecodeItemResponse,
	k_EMsgGCPaintItem,
	k_EMsgGCPaintItemResponse,
	k_EMsgGCGoldenWrenchBroadcast,
	k_EMsgGCMOTDRequest,
	k_EMsgGCMOTDRequestResponse,
	k_EMsgGCAddItemToSocket,
	k_EMsgGCAddItemToSocketResponse,
	k_EMsgGCAddSocketToBaseItem,
	k_EMsgGCAddSocketToItem,
	k_EMsgGCAddSocketToItemResponse,
	k_EMsgGCNameBaseItem,
	k_EMsgGCNameBaseItemResponse,
	k_EMsgGCRemoveSocketItem,
	k_EMsgGCRemoveSocketItemResponse,


	k_EMsgGCDev_NewItemRequest = 2001,
	k_EMsgGCDev_NewItemRequestResponse
} EGCMessages;



#pragma pack( push, 8 )
// callback notification - A new message is available for reading from the message queue
struct GCMessageAvailable_t
{
	enum { k_iCallback = k_iSteamGameCoordinatorCallbacks + 1 };

	uint32 m_nMessageSize;
};

// callback notification - A message failed to make it to the GC. It may be down temporarily
struct GCMessageFailed_t
{
	enum { k_iCallback = k_iSteamGameCoordinatorCallbacks + 2 };
};
#pragma pack( pop )

#pragma pack(push, 1)

/*
0100 ffffffffffffffffffffffffffffffff 86cf4e0001001001 01000000 d069ea0200000000 86cf4e00 8f13 01 03 00000000 01000000 0000
0100 ffffffffffffffffffffffffffffffff 86cf4e0001001001 01000000 cff9ea0200000000 86cf4e00 2a00 01 03 00000000 01000000 0000
0100 ffffffffffffffffffffffffffffffff 86cf4e0001001001 01000000 8dbaf70200000000 86cf4e00 8b13 01 03 00000000 01000000 0000
*/
struct SOMsgCreate_t
{
	enum { k_iMessage = k_ESOMsg_Create };
	uint16 id;
	char garbage[16];
	CSteamID steamid;
	uint32 unknown;
	
	//Same as SOMsgCacheSubscribed_Item_t
	uint64 itemid;
	uint32 accountid;
	uint16 itemtype;
	uint8 itemlevel;
	uint8 itemquality;
	uint32 position;
	uint32 itemcount;
	uint16 attribcount;
};

/*
0100 ffffffffffffffffffffffffffffffff 86cf4e0001001001 01000000 76f0da0200000000 0105 0f000080
0100 ffffffffffffffffffffffffffffffff 86cf4e0001001001 01000000 21ccd90200000000 0105 10000080
0100 ffffffffffffffffffffffffffffffff 86cf4e0001001001 01000000 d069ea0200000000 0105 20000080
*/
struct SOMsgUpdate_t
{
	enum { k_iMessage = k_ESOMsg_Update };

	uint16 id;
	char garbage[16];
	CSteamID steamid;
	uint32 unk1;
	uint64 itemID;
	uint16 unk2;
	uint32 position;
};

/*
0100 ffffffffffffffffffffffffffffffff 86cf4e0001001001 01000000 7f7e1b0200000000
0100 ffffffffffffffffffffffffffffffff 86cf4e0001001001 01000000 5a77020200000000
0100 ffffffffffffffffffffffffffffffff 86cf4e0001001001 01000000 bdbc1c0200000000
0100 ffffffffffffffffffffffffffffffff 86cf4e0001001001 01000000 8885210200000000
0100 ffffffffffffffffffffffffffffffff 86cf4e0001001001 01000000 e582e30100000000
*/
struct SOMsgDeleted_t
{
	enum { k_iMessage = k_ESOMsg_Destroy };
	uint16 id;
	char garbage[16];
	CSteamID steamid;
	uint32 unk1;
	uint64 itemid;
};

struct SOMsgCacheSubscribed_t
{
	enum { k_iMessage = k_ESOMsg_CacheSubscribed };

	uint16 id;
	char garbage[16];
	CSteamID steamid;
	uint32 unknown;
	uint16 padding;
	uint16 itemcount;
	// Variable length data:
	// [SOMsgCacheSubscribed_Item_t] * itemcount
};

struct SOMsgCacheSubscribed_Item_t
{
	uint64 itemid;
	uint32 accountid;
	uint16 itemdefindex;
	uint8 itemlevel;
	uint8 itemquality;
	uint32 position;
	uint32 itemcount;
	uint16 unk1;
	uint16 attribcount;
	// Variable length data:
	// [SOMsgCacheSubscribed_Item_Attrib_t] * attribcount
};

struct SOMsgCacheSubscribed_Item_Attrib_t
{
	uint16 attribindex;
	float value;
};


struct SOMsgCacheUnsubscribed_t
{
	enum { k_iMessage = k_ESOMsg_CacheUnsubscribed };

	uint16 id;
	char garbage[16];
	CSteamID steamid;
};


/*
0100 ffffffffffffffffffffffffffffffff 76f0da0200000000 0f000080 00000000
0100 ffffffffffffffffffffffffffffffff 21ccd90200000000 10000080 00000000
0100 ffffffffffffffffffffffffffffffff cff9ea0200000000 42000080 00000000
0100 ffffffffffffffffffffffffffffffff d069ea0200000000 20000080 00000000
*/
struct GCSetItemPosition_t
{
	enum { k_iMessage = k_EMsgGCSetItemPosition };
	uint16 id;
	char garbage[16];
	uint64 itemID;
	uint32 position;
	uint32 unk1;
};


/*
This one is 4 natasha
0100 ffffffffffffffffffffffffffffffff 0700 0400 5a77020200000000 bdbc1c0200000000 8885210200000000 e582e30100000000
*/
struct GCCraft_t
{
	enum { k_iMessage = k_EMsgGCCraft };
	uint16 id;
	char garbage[16];
	uint16 blueprint;//0xffff = unknown blueprint
	uint16 itemcount;
	// Variable length data:
	// [uint64 itemid] * itemcount
};


/*
0100 ffffffffffffffffffffffffffffffff 0700 0000000000000100 d069ea0200000000
*/
struct GCCraftResponse_t
{
	enum { k_iMessage = k_EMsgGCCraftResponse };
	uint16 id;
	char garbage[16];
	uint16 blueprint;//0xffff = failed
	uint64 unk1;
	uint64 itemid;
};


/*
0100 ffffffffffffffffffffffffffffffff 7f7e1b0200000000
*/
struct GCDelete_t
{
	enum { k_iMessage = k_EMsgGCDelete };
	uint16 id;
	char garbage[16];
	uint64 itemID;
};


/*
0100 ffffffffffffffffffffffffffffffff 86cf4e0001001001
*/
struct GCVerifyCacheSubscription_t
{
	enum { k_iMessage = k_EMsgGCVerifyCacheSubscription };

	uint16 id;
	char garbage[16];
	CSteamID steamid;
};


/*
0100 ffffffffffffffffffffffffffffffff 28000000 4d61783637202846522900
0100 ffffffffffffffffffffffffffffffff 29000000 54726962697400
0100 ffffffffffffffffffffffffffffffff 2a000000 776973686d617374657200
0100 ffffffffffffffffffffffffffffffff 2b000000 416d616e6f6f00
0100 ffffffffffffffffffffffffffffffff 2c000000 7c4b47437c2047617920526f62696e00
0100 ffffffffffffffffffffffffffffffff 2d000000 416e6164757200
0100 ffffffffffffffffffffffffffffffff 2e000000 54686520436f726e62616c6c657200
0100 ffffffffffffffffffffffffffffffff 2f000000 69736c6100
*/
struct GCGoldenWrenchBroadcast_t
{
	enum { k_iMessage = k_EMsgGCGoldenWrenchBroadcast };
	uint16 id;
	char garbage[16];
	uint32 WrenchNumber;
	// Variable length data:
	// char OwnerName[];
};

/*
0100 ffffffffffffffffffffffffffffffff 00000000 02000000 
0100 ffffffffffffffffffffffffffffffff 329d2d4c 02000000 
0100 ffffffffffffffffffffffffffffffff e6c74e4c 02000000 
*/
struct GCMOTDRequest_t
{
	enum { k_iMessage = k_EMsgGCMOTDRequest };
	uint16 id;
	char garbage[16];
	uint32 timestamp;
	uint32 unk1;
};

/*
0100 ffffffffffffffffffffffffffffffff 0000
0100 ffffffffffffffffffffffffffffffff 0200 3100 30930e4c 436865636b6564206f75742074686520626c6f673f00 496620796f7520686176656e2774207265616420746865206f6666696369616c2054463220626c6f672c20697427732066756c6c206f6620696e73696768747320696e746f206f757220646576656c6f706d656e742070726f636573732c206c696e6b7320746f206e6f7461626c6520636f6d6d756e6974792070726f64756374696f6e732c20616e642072616e646f6d2073746f726965732061626f7574206f7572206c6f7665206f6620686174732e204869742074686520627574746f6e2062656c6f7720746f2074616b652061206c6f6f6b2100 687474703a5c5c7777772e7465616d666f7274726573732e636f6d5c00 3200 b0e52c4c 4f6666696369616c2057696b69206f70656e732100 576527766520726563656e746c79206f70656e65642074686520646f6f7273206f6e20746865204f6666696369616c205446322077696b692e20546865726520796f752063616e2066696e64206f75742065766572797468696e67205446322072656c617465642c2066726f6d20746865206e756d65726963616c206e75747320616e6420626f6c7473206f6620657665727920776561706f6e20746f2074686520656173746572206567677320696e7369646520746865204d65657420746865205465616d206d6f766965732e205468657927726520616c77617973206c6f6f6b696e6720666f72206d6f726520636f6e7472696275746f72732c20736f20776879206e6f742068656164206f76657220616e642068656c70207468656d3f00 687474703a5c5c77696b692e7465616d666f7274726573732e636f6d5c00
*/
struct GCMOTDRequestResponse_t
{
	enum { k_iMessage = k_EMsgGCMOTDRequestResponse };
	uint16 id;
	char garbage[16];
	uint16 NumberOfNews;
	// Variable length data:
	// [GCMOTDRequestResponse_News_t] * NumberOfNews
};

struct GCMOTDRequestResponse_News_t
{
	uint16 id;
	uint32 timestamp;
	// Variable length data:
	// char Title[];
	// char Content[];
	// char URL[];
};

#pragma pack(pop)

#endif // ISTEAMGAMECOORDINATORCOMMON_H
