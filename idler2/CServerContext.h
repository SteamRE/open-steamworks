#ifndef CSERVERCONTEXT_H
#define CSERVERCONTEXT_H

#include "Common.h"
#include "CUser.h"
#include "CItemDB.h"

#ifdef _WIN32
#define SERVER_FLAGS k_unServerFlagDedicated | k_unServerFlagActive
#else
#define SERVER_FLAGS k_unServerFlagDedicated | k_unServerFlagActive | k_unServerFlagLinux
#endif

struct SteamHash : public std::unary_function<CSteamID, size_t> {
    size_t operator()(const CSteamID& f) const {
		return boost::hash<uint64>()(f.ConvertToUint64());
    }
};

typedef boost::unordered_map<SNetSocket_t, CUser *> SocketUserMap;
typedef boost::unordered_map<CSteamID, CUser *, SteamHash> SteamUserMap;

#define IDLER_SERVER_VERSION 1

class CServerContext : public IdlerContext
{
public:
    virtual ~CServerContext() {};
	CServerContext(ISteamClient008 *client, uint32 bindaddress, uint16 port) : IdlerContext(client), gameserver(NULL), masterserver(NULL), bindip(bindaddress), serverport(port), serverSocket(0), numClients(0) {}
	bool Begin();
	void End();
	void Think();

	void HandleCallback(const CallbackMsg_t &callback);



private:
	// callback handlers
	void DefaultCallback( const CallbackMsg_t& callbackMsg );
	void HandleCallbackSocketStatus( SocketStatusCallback_t *pSocketStatus );
	void HandleCallbackPolicyResponse( GSPolicyResponse_t *pPolicyResponse );
	void HandleCallbackClientKick( GSClientKick_t *pClientKick );
	void HandleCallbackClientDeny( GSClientDeny_t *pClientDeny );
	void HandleCallbackClientApprove( GSClientApprove_t *pClientApprove );
	void HandleCallbackItemCount( GSItemCount_t *pClientItems );
	void HandleCallbackItemGranted( GSItemGranted_t *pItemGranted );

	void HandleNetworking();

	// networking callbacks
	void HandleNetClientInitConnection( SNetSocket_t clientSocket, NetClientInitConnection_t *pClientInit );
	void HandleNetClientAuth( SNetSocket_t clientSocket, NetClientAuth_t *pClientAuth );
	void HandleNetClientPingReply( SNetSocket_t clientSocket, NetClientPingReply_t *pClientPong );
	void HandleNetClientItemGranted( SNetSocket_t clientSocket, NetClientItemGranted_t *pClientItemGranted );

	void UpdateServerStatus();

	void RemoveUser(CUser *user);
	void SendPingRequest();

	ISteamGameServer009			 *gameserver;
	ISteamMasterServerUpdater001 *masterserver;
	ISteamNetworking002			 *networking;
	ISteamGameServerItems004	 *gameserveritems;

	CFileLogger *fileLogger;

	uint32 bindip;
	uint16 serverport;
	SNetListenSocket_t serverSocket;

	time_t lastping;

	uint32 numClients;
	SocketUserMap clientSocketMap;
	SteamUserMap  clientSteamMap;
};

#endif //CSERVERCONTEXT_H
