#include "CClientContext.h"

bool CClientContext::Begin()
{
	connected = false;

	fileLogger = new CFileLogger( "client_log.txt" );

	std::cout << "[CLIENT] Initializing... ";

	pipe = client->CreateSteamPipe();
	if (!pipe)
	{
		std::cerr << "Steam pipe could not be created." << std::endl;
		return false;
	}

	user = client->ConnectToGlobalUser(pipe);
	if (!user)
	{
		std::cerr << "Steam user could not be created." << std::endl;
		return false;
	}

	networking = (ISteamNetworking002 *)client->GetISteamNetworking( user, pipe, STEAMNETWORKING_INTERFACE_VERSION_002 );
	if ( !networking )
	{
		std::cerr << "Unable to get " STEAMNETWORKING_INTERFACE_VERSION_002  << std::endl;
		return false;
	}

	steamuser = (ISteamUser012 *)client->GetISteamUser( user, pipe, STEAMUSER_INTERFACE_VERSION_012 );
	if ( !steamuser )
	{
		std::cerr << "Unable to get " STEAMUSER_INTERFACE_VERSION_012 << std::endl;
		return false;
	}

	steamfriends = (ISteamFriends005 *)client->GetISteamFriends( user, pipe, STEAMFRIENDS_INTERFACE_VERSION_005 );
	if ( !steamfriends )
	{
		std::cerr << "Unable to get " STEAMFRIENDS_INTERFACE_VERSION_005 << std::endl;
		return false;
	}

	useritems = (ISteamUserItems003 *)client->GetISteamGenericInterface( user, pipe, STEAMUSERITEMS_INTERFACE_VERSION_003 );
	if ( !useritems )
	{
		std::cerr << "Unable to get " STEAMUSERITEMS_INTERFACE_VERSION_003 << std::endl;
		return false;
	}

	coordinator = (ISteamGameCoordinator001 *)client->GetISteamGenericInterface( user, pipe, STEAMGAMECOORDINATOR_INTERFACE_VERSION_001 );
	if (!coordinator)
	{
		std::cerr << "Unable to get " STEAMGAMECOORDINATOR_INTERFACE_VERSION_001 << std::endl;
		return false;
	}

	std::cout << "Complete! pipe: " << pipe << " user: " << user << std::endl;

	clientSocket = networking->CreateConnectionSocket(remoteip, remoteport, 20);
	if ( !clientSocket )
	{
		std::cerr << "Unable to create connection socket." << std::endl;
		return false;
	}

	running = true;
	lastping = time(0);
	return true;
}

void CClientContext::Think()
{
	HandleNetworking();

	if(time(0) > (lastping + PING_TIMEOUT))
	{
		std::cout << "[CLIENT] Lost connection to server." << std::endl;
		running = false;
	}
}

void CClientContext::HandleNetworking()
{
	uint32 dataSize;

	if ( !networking->IsDataAvailableOnSocket( clientSocket, &dataSize ) )
		return; // no data waiting

	void *data = malloc( dataSize );

	if ( !networking->RetrieveDataFromSocket( clientSocket, data, dataSize, &dataSize ) )
	{
		// data is waiting, but we're unable to read it
		free( data );
		return;
	}

	ENetworkMessage *eMsg = (ENetworkMessage *)data;

	switch ( *eMsg )
	{

		case eServerConnectionDenied:
			HandleNetConnectionDenied( (NetServerConnectionDenied_t *)data );
			break;

		case eServerSendInfo:
			HandleNetSendInfo( (NetServerSendInfo_t *)data );
			break;

		case eServerClientAuthed:
			HandleNetClientAuthed( (NetServerClientAuthed_t *)data );
			break;

		case eServerClientKicked:
			HandleNetClientKicked( (NetServerClientKicked_t *)data );
			break;

		case eServerPingRequest:
			HandleNetPingRequest( (NetServerPingRequest_t *)data );
			break;

		case eServerYourItemWas:
			HandleNetNameResponse( (NetServerYourItemWas_t *)data );
			break;

		default:
			std::cout << "[CLIENT] Recieved unexpected ENetworkMessage from server (" << *eMsg << ")" << std::endl;
			std::cout << "  Your client is out of date." << std::endl;
			break;
	}

	free( data );
}

void CClientContext::HandleCallback(const CallbackMsg_t &callback)
{
	switch(callback.m_iCallback)
	{
		case SteamServersConnected_t::k_iCallback:
			std::cout << "[CLIENT] Connected to back-end." << std::endl;
			break;

		case BeginLogonRetry_t::k_iCallback:
			std::cout << "[CLIENT] Attempting to reconnect to back-end..." << std::endl;
			break;

		case SteamServerConnectFailure_t::k_iCallback:
			std::cout << "[CLIENT] Disconnected from steam back-end." << std::endl;
			std::cout << "  The client will automatically reconnect when the back-end is available." << std::endl;
			break;

		case SocketStatusCallback_t::k_iCallback:
			HandleCallbackSocketStatus( (SocketStatusCallback_t *)callback.m_pubParam );
			break;

		case UserItemCount_t::k_iCallback:
			std::cout << "[CLIENT] I have " << ((UserItemCount_t *)callback.m_pubParam)->m_unCount << " items." << std::endl;
			std::cout << "  You will be notified when you recieve a new item." << std::endl;
			break;

		case UserItemGranted_t::k_iCallback:
			HandleCallbackUserItemGranted( (UserItemGranted_t *)callback.m_pubParam );
			break;

		case SteamAPICallCompleted_t::k_iCallback:
		case PersonaStateChange_t::k_iCallback:
			break;

		case GameCoordinatorMessageAvailable_t::k_iCallback:
			{
				GameCoordinatorMessageAvailable_t *gcm = (GameCoordinatorMessageAvailable_t *)callback.m_pubParam;
				uint32 size = 0;

				if(coordinator->IsMessageAvailable(&size))
				{
					unsigned int id = 0;
					unsigned int real = 0;
					void *buff = malloc(gcm->messageLength);
					coordinator->RetrieveMessage(&id, buff, gcm->messageLength, &real);
					std::cout << "Coordinator message available " << gcm->messageLength << " - " << id << std::endl;
					//PrintData((unsigned char *)buff, real);
					//std::cout << std::endl;

					if(id == 24)
					{
						DumpItems((unsigned char *)buff);
					}
				} else {
					std::cout << "No message" << std::endl;
				}
			}
		break;

		default:
			DefaultCallback( callback );
			break;
	}
}

void CClientContext::DefaultCallback( const CallbackMsg_t& callbackMsg )
{
	std::stringstream ss;

	int32 callBack = callbackMsg.m_iCallback;
	ECallbackType type = (ECallbackType)((callBack / 100) * 100);

	std::cout << "[CLIENT] Unhandled Callback: " << callBack << ", Type: " << EnumString<ECallbackType>::From(type) << ", Size: " << callbackMsg.m_cubParam << std::endl;
	ss << "[CLIENT] Unhandled Callback: " << callBack << ", Type: " << EnumString<ECallbackType>::From(type) << ", Size: " << callbackMsg.m_cubParam << std::endl;

	int32 callSize = callbackMsg.m_cubParam;
	unsigned char *data = callbackMsg.m_pubParam;
	std::cout << "  ";
	ss << "  ";
	for (int i = 0; i < callSize; i++)
	{
		unsigned char value = data[i];
	
		std::cout << std::hex << std::setw(2) << std::setfill('0') << std::uppercase << (unsigned int)value;
		std::cout << " ";

		ss << std::hex << std::setw(2) << std::setfill('0') << std::uppercase << (unsigned int)value;
		ss << " ";
	}

	std::cout << std::resetiosflags(std::ios_base::hex | std::ios_base::uppercase) << std::endl;
	ss << std::resetiosflags(std::ios_base::hex | std::ios_base::uppercase) << std::endl;

	fileLogger->Log( ss.str().c_str() );
}

void CClientContext::HandleCallbackUserItemGranted( UserItemGranted_t *pItemGranted )
{
	ItemID id = pItemGranted->m_itemID;
	uint32 itemType, itemLevel, itemFlags, quantity, nbAttribs;
	EItemQuality quality;

	useritems->GetItemByID(id, &itemType, &itemLevel, &quality, &itemFlags, &quantity, &nbAttribs);

	NetClientItemGranted_t granted;
	granted.itemid = itemType;

	std::stringstream ss;

	std::cout << "[CLIENT] You have been granted an item! Retrieving name from server..." << std::endl;
	std::cout << "  ID: " << id << ", Type: " << itemType << ", Level: " << itemLevel << std::endl;

	ss << "[CLIENT] You have been granted an item! Retrieving name from server..." << std::endl;
	ss << "  ID: " << id << ", Type: " << itemType << ", Level: " << itemLevel << std::endl;

	fileLogger->Log( ss.str().c_str() );

	if ( !networking->SendDataOnSocket( clientSocket, (void *)&granted, sizeof( granted ), true ) )
	{
		std::cout << "HandleCallbackUserItemGranted() - Unable to report to server!" << std::endl;
		running = false;
	}
}

void CClientContext::HandleCallbackSocketStatus( SocketStatusCallback_t *pSocketStatus )
{
	// handle various client socket situations
	switch ( pSocketStatus->m_eSNetSocketState )
	{	
		case k_ESNetSocketStateTimeoutDuringConnect:
			// connection timeout to destination server, so we exit out
			running = false;
			std::cout << "HandleSocketStatusCallback() - Unable to connect to destination server." << std::endl;
			break;

		case k_ESNetSocketStateConnected:
			{
				std::cout << "[CLIENT] Connected to server, initiating handshake..." << std::endl;
				// we've connected, lets start our data handshake
				NetClientInitConnection_t msg;
				msg.clientProtocolVersion = IDLER_CLIENT_VERSION;

				networking->SendDataOnSocket( clientSocket, (void *)&msg, sizeof( msg ), true );
			}
			break;

		case k_ESNetSocketStateConnectionBroken:
		case k_ESNetSocketStateRemoteEndDisconnected:
			std::cout << "[CLIENT] Lost connection to remote server. (" << EnumString<ESNetSocketState>::From( (ESNetSocketState)pSocketStatus->m_eSNetSocketState ) << ")" << std::endl;
			running = false;
			break;

		case k_ESNetSocketStateInitiated:
		case k_ESNetSocketStateChallengeHandshake:
			break;

		default:
			std::cout << "[CLIENT] Socket " << pSocketStatus->m_hListenSocket << " is now " << EnumString<ESNetSocketState>::From( (ESNetSocketState)pSocketStatus->m_eSNetSocketState ) << std::endl;
			break;
	}
}

void CClientContext::HandleNetConnectionDenied( NetServerConnectionDenied_t *pConnectionDenied )
{
	// handle various denial reasons
	switch ( pConnectionDenied->denyReason )
	{

	case EDenyServerFull:
		std::cout << "[CLIENT] Connection denied to server: Server is full." << std::endl;
		break;

	case EDenySteamIDBanned:
		std::cout << "[CLIENT] Connection denied to server: You are banned." << std::endl;
		break;

	case EDenyAuthFailed:
		std::cout << "[CLIENT] Connection denied to server: Authentication failure." << std::endl;
		break;

	case EDenySteamIDExists:
		std::cout << "[CLIENT] Connection denied to server: SteamID is already present on server." << std::endl;
		break;

	case EDenyClientOutdated:
		std::cout << "[CLIENT] Connection denied to server: Your client is out of date." << std::endl;
		break;

	default:
		std::cout << "[CLIENT] Connection denied to server, but an invalid reason (" << (uint8)pConnectionDenied->denyReason << ") was supplied." << std::endl;
		std::cout << "  Your client is out of date." << std::endl;
		break;

	}

	std::cout << "  Message: " << pConnectionDenied->optionalMessage << std::endl;

	running = false;
}

//-----------------------------------------------------------------------------
// Purpose: 
//		   
//-----------------------------------------------------------------------------
void CClientContext::HandleNetSendInfo( NetServerSendInfo_t *pSendInfo )
{
	// should maybe store this server info somewhere?
	std::cout << "[CLIENT] Recieved server details. SteamID: " << pSendInfo->serverSteamID << ", VAC Secure: " << pSendInfo->vacSecure << std::endl;

	std::cout << "[CLIENT] Authenticating with server..." << std::endl;

	NetClientAuth_t auth;
	auth.ticketLen = steamuser->InitiateGameConnection( (void *)&auth.authTicket, AUTHTICKET_SIZE, pSendInfo->serverSteamID, remoteip, remoteport, pSendInfo->vacSecure );
	strncpy(auth.username, steamfriends->GetPersonaName(), sizeof(auth.username));

	useritems->LoadItems();

	if ( !auth.ticketLen )
	{
		// if InitiateGameConnection fails, we bail out
		std::cout << "HandleNetSendInfo() - InitiateGameConnection failed." << std::endl;
		running = false;
		return;
	}
	
	if ( !networking->SendDataOnSocket( clientSocket, (void *)&auth, sizeof( auth ), true ) )
	{
		// connection was interrupted during the authentication process
		std::cout << "HandleNetSendInfo() - Unable to send authticket to server." << std::endl;
		running = false;
		return;
	}
}

void CClientContext::HandleNetClientAuthed( NetServerClientAuthed_t *pClientAuthed )
{
	std::cout << "[CLIENT] Authentication completed." << std::endl;
	std::cout << "[CLIENT]   MOTD: " << pClientAuthed->messageOfTheDay << std::endl;
}

void CClientContext::HandleNetClientKicked( NetServerClientKicked_t *pClientKicked )
{
	std::cout << "[CLIENT] You have been kicked from the server: " << pClientKicked->kickMessage << std::endl;
	
	running = false;
	return;
}

void CClientContext::HandleNetPingRequest( NetServerPingRequest_t *pPing )
{
	//std::cout << "[CLIENT] Pong! (Server said " << pPing->itemsTotal << ")" << std::endl;

	lastping = time(0);

	NetClientPingReply_t pong;
	if ( !networking->SendDataOnSocket( clientSocket, (void *)&pong, sizeof( pong ), true ) )
	{
		std::cout << "HandleNetPingRequest() - Unable to reply to server ping!" << std::endl;
		running = false;
	}

	return;
}

void CClientContext::HandleNetNameResponse( NetServerYourItemWas_t *pItemName )
{
	std::stringstream ss;

	std::cout << "[CLIENT] You got a: " << pItemName->itemName << std::endl;
	ss << "[CLIENT] You got a: " << pItemName->itemName << std::endl;

	fileLogger->Log( ss.str().c_str() );
}

void CClientContext::End()
{
	if(clientSocket)
		networking->DestroySocket(clientSocket, false);

	if(user)
		client->ReleaseUser(pipe, user);
	if(pipe)
		client->ReleaseSteamPipe(pipe);

	delete fileLogger;
}
