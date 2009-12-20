#ifndef NETMESSAGES_H
#define NETMESSAGES_H

#pragma pack(push, 1)

enum ENetworkMessage
{
	// server
	eServerBegin = 0,
	eServerConnectionDenied = eServerBegin + 1,
	eServerSendInfo = eServerBegin + 2,
	eServerClientAuthed = eServerBegin + 3,
	eServerPingRequest = eServerBegin + 4,
	eServerClientKicked = eServerBegin + 5,
	eServerYourItemWas = eServerBegin + 6,

	// client
	eClientBegin = 1000,
	eClientInitConnection = eClientBegin + 1,
	eClientAuth = eClientBegin + 2,
	eClientPingReply = eClientBegin + 3,
	eClientItemGranted = eClientBegin + 4,

	eWORD = 0xFFFFFF,

};

enum EConnectionDenyReason WINSIZE(uint8)
{
	EDenyServerFull,
	EDenyAuthFailed,
	EDenySteamIDBanned,
	EDenySteamIDExists,
	
	EDenyClientOutdated,

	eBYTE = 0xFF,
};

struct NetMessageBase_t
{
	NetMessageBase_t(ENetworkMessage mt) : messageType(mt) {};

	const ENetworkMessage messageType;
};

struct NetServerConnectionDenied_t : NetMessageBase_t
{
	NetServerConnectionDenied_t() : NetMessageBase_t( eServerConnectionDenied ) { }

	EConnectionDenyReason denyReason;
	char optionalMessage[ MESSAGE_SIZE ];
};


struct NetServerSendInfo_t : NetMessageBase_t
{
	NetServerSendInfo_t() : NetMessageBase_t( eServerSendInfo) {}

	CSteamID serverSteamID;
	bool vacSecure;
};

struct NetServerClientAuthed_t : NetMessageBase_t
{
	NetServerClientAuthed_t() : NetMessageBase_t( eServerClientAuthed ) { }

	char messageOfTheDay[ MOTD_SIZE ];
	// maybe send other last details to an authed client?
};

struct NetServerPingRequest_t : NetMessageBase_t
{
	NetServerPingRequest_t() : NetMessageBase_t( eServerPingRequest ) { }

	uint32 itemsTotal;
};

struct NetServerClientKicked_t : NetMessageBase_t
{
	NetServerClientKicked_t() : NetMessageBase_t( eServerClientKicked ) { }

	char kickMessage[ MESSAGE_SIZE ];
};

struct NetServerYourItemWas_t : NetMessageBase_t
{
	NetServerYourItemWas_t() : NetMessageBase_t( eServerYourItemWas ) { };

	char itemName[ITEM_MAXNAMELEN];
};

struct NetClientInitConnection_t : NetMessageBase_t
{
	NetClientInitConnection_t() : NetMessageBase_t( eClientInitConnection ) { }

	uint32 clientProtocolVersion;
};

struct NetClientAuth_t : NetMessageBase_t
{
	NetClientAuth_t() : NetMessageBase_t( eClientAuth ) { }

	// uint64 clientSteamID; // probably located in the auth ticket
	uint32 ticketLen;
	byte authTicket[ AUTHTICKET_SIZE ];
	char username[ k_cchPersonaNameMax ];
};

struct NetClientPingReply_t : NetMessageBase_t
{
	NetClientPingReply_t() : NetMessageBase_t( eClientPingReply ) { }

};

struct NetClientItemGranted_t : NetMessageBase_t
{
	NetClientItemGranted_t() : NetMessageBase_t( eClientItemGranted ) { }

	uint32 itemid;
};

#pragma pack(pop)

#endif // NETMESSAGES_H
