#ifndef CCLIENTCONTEXT_H
#define CCLIENTCONTEXT_H

#include "Common.h"

#define IDLER_CLIENT_VERSION 1

class CClientContext : public IdlerContext
{
public:
    virtual ~CClientContext() {};
	CClientContext(ISteamClient008 *client, uint32 ip, uint16 port) : IdlerContext(client), remoteip(ip), remoteport(port), clientSocket(0) {};

	bool Begin();
	void End();
	void Think();

	void HandleCallback(const CallbackMsg_t &callback);

private:
	// callback handlers
	void HandleCallbackSocketStatus( SocketStatusCallback_t *pSocketStatus );
	void HandleCallbackUserItemGranted( UserItemGranted_t *pItemGranted );

	void HandleNetworking();

	// network handlers
	void DefaultCallback( const CallbackMsg_t& callbackMsg );
	void HandleNetConnectionDenied( NetServerConnectionDenied_t *pConnectionDenied );
	void HandleNetSendInfo( NetServerSendInfo_t *pSendInfo );
	void HandleNetClientAuthed( NetServerClientAuthed_t *pClientAuthed );
	void HandleNetClientKicked( NetServerClientKicked_t *pClientKicked );
	void HandleNetPingRequest( NetServerPingRequest_t *pPing );
	void HandleNetNameResponse( NetServerYourItemWas_t *pItemName );

	ISteamNetworking002 *networking;
	ISteamUser012		*steamuser;
	ISteamFriends005	*steamfriends;
	ISteamUserItems003	*useritems;
	ISteamGameCoordinator001 *coordinator;


	CFileLogger *fileLogger;

	uint32 remoteip;
	uint16 remoteport;
	SNetSocket_t clientSocket;

	time_t lastping;
	bool connected;
};

#endif //CCLIENTCONTEXT_H
