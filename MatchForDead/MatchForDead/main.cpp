#define STEAMWORKS_CLIENT_INTERFACES
#define STEAM

#include "steamworks.h"

#include <boost/cstdlib.hpp>
#include <boost/unordered_map.hpp>

#include <iostream>
#include <iomanip>

#define APPID 500

IClientEngine *clengine;
IClientFriends *clfriends;

ISteamClient008 *client;
ISteamMatchmaking007 *matchmaking;
ISteamUserStats006 *stats;
ISteamUtils004 *utils;
ISteamUser012 *steamuser;

class APICallResult
{
public:
	int callback;
	int size;
	uint8 *buff;

public:
	APICallResult(int callback, int size) : callback(callback), size(size) { buff = (uint8 *)malloc(size); };
	~APICallResult() { free(buff); };
};

typedef boost::unordered_map<SteamAPICall_t, APICallResult *> APIRemapMap;
APIRemapMap apiremap;

#define REMAP_APICALL(A,T) apiremap.insert(APIRemapMap::value_type(A, new APICallResult(T::k_iCallback, sizeof(T))));



void DefaultCallback( const CallbackMsg_t& callbackMsg );

void HandleCallback( const CallbackMsg_t& callback )
{
	switch(callback.m_iCallback)
	{
		case LobbyMatchList_t::k_iCallback:
			{
				LobbyMatchList_t *list = (LobbyMatchList_t *)callback.m_pubParam;

				std::cout << "[CLIENT] I see " << list->m_nLobbiesMatching << " lobbies." << std::endl;

				for(int i = 0; i < list->m_nLobbiesMatching; i++)
				{
					CSteamID lobbyid = matchmaking->GetLobbyByIndex(i);
					std::cout << "[CLIENT] Lobby " << i << " " << lobbyid << std::endl;
				}

				char c;
				std::cout << "1) new lobby" << std::endl << "2) join lobby" << std::endl;
				std::cin >> c;
				switch(c)
				{
				case '1':
					std::cout << std::endl << "[CLIENT] Creating our own lobby" << std::endl;
					matchmaking->CreateLobby(k_ELobbyTypeFriendsOnly, 6); 
				break;
				case '2':
					std::cout << std::endl << "lobby: ";
					uint64 lobby;
					std::cin >> lobby;
					matchmaking->JoinLobby(lobby);
				break;
				}
			}
		break;
		case LobbyCreated_t::k_iCallback:
			{
				LobbyCreated_t *create = (LobbyCreated_t *)callback.m_pubParam;

				std::cout << "[CLIENT] Lobby created from server " << EnumString<EResult>::From(create->m_eResult) << " " << create->m_ulSteamIDLobby << std::endl;

				int lobbydatacount = matchmaking->GetLobbyDataCount(create->m_ulSteamIDLobby);
				std::cout << "num k/v " << lobbydatacount << std::endl;
				for(int i = 0; i < lobbydatacount; i++)
				{
					char key[1024];
					char value[1024];
					matchmaking->GetLobbyDataByIndex(create->m_ulSteamIDLobby, i, (char *)&key, sizeof(key), (char *)&value, sizeof(value));
					std::cout << i << " key: " << key << " value: " << value << std::endl;
				}
			}
		break;
		case LobbyEnter_t::k_iCallback:
			{
				LobbyEnter_t *enter = (LobbyEnter_t *)callback.m_pubParam;

				std::cout << "[CLIENT] Entered lobby " << enter->m_ulSteamIDLobby << " chat " << EnumString<EChatRoomEnterResponse>::From(enter->m_EChatRoomEnterResponse) << " permissions " << enter->m_rgfChatPermissions << std::endl;

				bool sent = matchmaking->SendLobbyChatMsg(enter->m_ulSteamIDLobby, "Test\0", 5);
				std::cout << "[CLIENT] Sent message " << sent << std::endl;
			}
		break;
		case LobbyDataUpdate_t::k_iCallback:
			{
				LobbyDataUpdate_t *data = (LobbyDataUpdate_t *)callback.m_pubParam;

				std::cout << "[CLIENT] Lobby data update " << data->m_ulSteamIDLobby << " is lobby itself " << (data->m_ulSteamIDLobby == data->m_ulSteamIDMember) << std::endl;
			}
		break;
		case LobbyChatMsg_t::k_iCallback:
			{
				LobbyChatMsg_t *chat = (LobbyChatMsg_t *)callback.m_pubParam;
				CSteamID user = chat->m_ulSteamIDUser;

				std::cout << "[CLIENT] Message in lobby " << chat->m_ulSteamIDLobby << " by user " << user << " of type " << EnumString<EChatEntryType>::From(chat->m_eChatEntryType) << " id " << chat->m_iChatID << std::endl;

				CSteamID chatuser;
				char buff[1024];
				EChatEntryType entry;

				matchmaking->GetLobbyChatEntry(chat->m_ulSteamIDLobby, chat->m_iChatID, &chatuser, &buff, sizeof(buff), &entry);
				std::cout << "Message contents: " << buff << std::endl;

				if(user != steamuser->GetSteamID())
				{
					uint32 perm = 0;
					bool got = clfriends->GetChatRoomPermissions(chat->m_ulSteamIDLobby, &perm);
					std::cout << "[CLIENT] " << got << " permissions " << perm << std::endl;

					bool term = clfriends->KickChatMember(chat->m_ulSteamIDLobby, user);
					std::cout << "[CLIENT] Let's get out of here" << term << std::endl;
					//matchmaking->LeaveLobby(chat->m_ulSteamIDLobby);
				}
			}
		break;
		case LobbyChatUpdate_t::k_iCallback:
			{
				LobbyChatUpdate_t *chatup = (LobbyChatUpdate_t *)callback.m_pubParam;
				CSteamID userchanged = chatup->m_ulSteamIDUserChanged;
				CSteamID userchanger = chatup->m_ulSteamIDMakingChange;

				std::cout << "[CLIENT] Lobby update " << chatup->m_ulSteamIDLobby << " for user " << userchanged << " by " << userchanger << " to " << chatup->m_rgfChatMemberStateChange << " removed " << std::endl;
			}
		break;
		case LobbyKicked_t::k_iCallback:
			{
				LobbyKicked_t *kick = (LobbyKicked_t *)callback.m_pubParam;
			
				std::cout << "[CLIENT] Kicked from lobby " << kick->m_ulSteamIDLobby << " by " << CSteamID(kick->m_ulSteamIDAdmin) << std::endl;
			}
		break;

		case 304:
		break;

		case SteamAPICallCompleted_t::k_iCallback:
			{
				SteamAPICallCompleted_t *call = (SteamAPICallCompleted_t *)callback.m_pubParam;

				std::cout << "[CLIENT] Async call " << call->m_hAsyncCall << " completed. " << std::endl;

				APIRemapMap::iterator iter = apiremap.find( call->m_hAsyncCall );
				if(iter != apiremap.end())
				{
					bool failed = false;
					APICallResult *res = iter->second;
					
					bool ok = utils->GetAPICallResult(call->m_hAsyncCall, res->buff, res->size, res->callback, &failed);

					CallbackMsg_t newcallback;
					newcallback.m_iCallback = res->callback;
					newcallback.m_pubParam = res->buff;
					newcallback.m_cubParam = res->size;

					HandleCallback(newcallback);

					delete res;
					apiremap.erase(iter);

					if(failed)
					{
						bool gotstatus = utils->IsAPICallCompleted(call->m_hAsyncCall, &failed);
						ESteamAPICallFailure cf = utils->GetAPICallFailureReason(call->m_hAsyncCall);
	
						std::cout << "Failure: " << gotstatus << " " << failed << " " << EnumString<ESteamAPICallFailure>::From(cf) << std::endl;
					}
				}
			}
			break;
		default:
			DefaultCallback(callback);
			break;
	}
}

int main(int argc, char *argv[])
{
	SetEnvironmentVariable("SteamAppId", "500");

	CSteamAPILoader apiloader;

	CreateInterfaceFn clientFactory = apiloader.Load();
	if(clientFactory == NULL)
		return EXIT_FAILURE;

	client = (ISteamClient008 *)clientFactory(STEAMCLIENT_INTERFACE_VERSION_008, NULL);
	assert(client != NULL);

	clengine = (IClientEngine *)clientFactory(CLIENTENGINE_INTERFACE_VERSION, NULL);
	assert(clengine != NULL);

	HSteamPipe pipe = client->CreateSteamPipe();
	HSteamUser user = client->ConnectToGlobalUser(pipe);
 
	if(!user || !pipe)
	{
		std::cerr << "Steam user/pipe could not be created." << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "Created user " << user << " pipe " << pipe << std::endl;

	
	clfriends = (IClientFriends *)clengine->GetIClientFriends( user, pipe, CLIENTFRIENDS_INTERFACE_VERSION );

	steamuser = (ISteamUser012 *)client->GetISteamUser( user, pipe, STEAMUSER_INTERFACE_VERSION_012 );
	utils = (ISteamUtils004 *)client->GetISteamUtils( pipe, STEAMUTILS_INTERFACE_VERSION_004 );
	assert( utils->GetAppID() == APPID );

	matchmaking = (ISteamMatchmaking007 *)client->GetISteamMatchmaking( user, pipe, STEAMMATCHMAKING_INTERFACE_VERSION_007 );
	stats = (ISteamUserStats006 *)client->GetISteamUserStats( user, pipe, STEAMUSERSTATS_INTERFACE_VERSION_006 );

	matchmaking->RequestLobbyList();

	while(true)
	{
		CallbackMsg_t callbackMsg;
		HSteamCall steamCall;

		client->RunFrame();

		if ( Steam_BGetCallback( pipe, &callbackMsg, &steamCall ))
		{
			HandleCallback(callbackMsg);

			Steam_FreeLastCallback( pipe );
		}

		Sleep(10);
	}
}

void DefaultCallback( const CallbackMsg_t& callbackMsg )
{
	int32 callBack = callbackMsg.m_iCallback;
	ECallbackType type = (ECallbackType)((callBack / 100) * 100);

	std::cout << "[CLIENT] Unhandled Callback: " << callBack << ", Type: " << EnumString<ECallbackType>::From(type) << ", Size: " << callbackMsg.m_cubParam << std::endl;

	int32 callSize = callbackMsg.m_cubParam;
	unsigned char *data = callbackMsg.m_pubParam;
	std::cout << "  ";

	for (int i = 0; i < callSize; i++)
	{
		unsigned char value = data[i];
	
		std::cout << std::hex << std::setw(2) << std::setfill('0') << std::uppercase << (unsigned int)value;
		std::cout << " ";
	}

	std::cout << std::resetiosflags(std::ios_base::hex | std::ios_base::uppercase) << std::endl;
}