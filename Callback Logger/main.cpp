#include "Steamworks.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

ISteamClient008 *steamClient = NULL;

HSteamPipe steamPipe = NULL;
HSteamUser user = NULL;

#ifndef _WIN32
void Sleep(int x) {
	usleep(x);
}
#endif

std::map<int, std::string> MakeCallbackMap() {
	#define _(x) result[x::k_iCallback] = #x;
	std::map<int, std::string> result;
	
	// k_iSteamUserCallbacks
	_(LogonSuccess_t);
	_(SteamServersConnected_t);
	_(LogonFailure_t);
	_(SteamServerConnectFailure_t);
	_(LoggedOff_t);
	_(SteamServersDisconnected_t);
	_(BeginLogonRetry_t);
	_(Steam2TicketChanged_t);
	_(ClientAppNewsItemUpdate_t);
	_(ClientSteamNewsItemUpdate_t);
	_(ClientGameServerDeny_t);
	_(PrimaryChatDestinationSet_t);
	_(UserPolicyResponse_t);
	_(ClientSteamNewsClientUpdate_t);
	_(CallbackPipeFailure_t);
	_(IPCFailure_t);
	_(ValidateAuthTicketResponse_t);
	
	// k_iSteamGameServerCallbacks
	_(GSClientApprove_t);
	_(GSClientDeny_t);
	_(GSClientKick_t);
	_(GSClientSteam2Deny_t);
	_(GSClientSteam2Accept_t);
	_(GSClientAchievementStatus_t);
	_(GSGameplayStats_t);
	_(GSClientGroupStatus_t);
	_(GSPolicyResponse_t);

	// k_iSteamFriendsCallbacks
	_(FriendAdded_t);
	_(UserRequestingFriendship_t);
	_(PersonaStateChangeOld_t);
	_(PersonaStateChange_t);
	_(SystemIM_t);
	_(FriendChatMsg_t);
	_(GroupChatMsg_t);
	_(FriendEndChatSession_t);
	_(GameOverlayActivated_t);
	_(GameServerChangeRequested_t);
	_(GameLobbyJoinRequested_t);
	
	// k_iSteamBillingCallbacks
	_(FinalPriceMsg_t);
	_(PurchaseMsg_t);
	
	// k_iSteamMatchmakingCallbacks
	_(FavoritesListChanged_t);
	_(LobbyInvite_t);
	_(LobbyEnter_t);
	_(LobbyDataUpdate_t);
	_(LobbyChatUpdate_t);
	_(LobbyChatMsg_t);
	_(LobbyAdminChange_t);
	_(LobbyGameCreated_t);
	_(LobbyMatchList_t);
	_(LobbyClosing_t);
	_(LobbyKicked_t);
	_(LobbyCreated_t);
	
	// k_iSteamContentServerCallbacks
	
	// k_iSteamUtilsCallbacks
	_(IPCountry_t);
	_(LowBatteryPower_t);
	_(SteamAPICallCompleted_t);
	_(SteamShutdown_t);
	
	// k_iClientFriendsCallbacks
	
	// k_iClientUserCallbacks
	
	// k_iSteamAppsCallbacks
	_(AppDataChanged_t);
	_(DlcInstalled_t);
	
	// k_iSteamUserStatsCallbacks
	_(UserStatsReceived_t);
	_(UserStatsStored_t);
	_(UserAchievementStored_t);
	_(LeaderboardFindResult_t);
	_(LeaderboardScoresDownloaded_t);
	_(LeaderboardScoreUploaded_t);
	_(NumberOfCurrentPlayers_t);
	
	// k_iSteamNetworkingCallbacks
	_(SocketStatusCallback_t);
	_(P2PSessionRequest_t);
	_(P2PSessionConnectFail_t);

	// k_iClientRemoteStorageCallbacks
	
	// k_iSteamUserItemsCallbacks
	_(UserItemCount_t);
	_(UserItemMoved_t);
	_(UserItemDeleted_t);
	_(UserItemGranted_t);
	_(UserItemGetBlob_t);
	_(UserItemSetBlob_t);

	// k_iSteamGameServerItemsCallbacks
	_(GSItemCount_t);
	_(GSItemRequest_t);
	_(GSItemGranted_t);
	_(GSItemGetBlob_t);
	_(GSItemSetBlob_t);
	
	// k_iClientUtilsCallbacks
	
	// k_iSteamGameCoordinatorCallbacks
	_(GameCoordinatorMessageAvailable_t);
	
	return result;
	#undef _
}

int main()
{
	using namespace std;

	CSteamAPILoader loader;
	CreateInterfaceFn factory = loader.Load();

	ISteamClient008 *steamClient = (ISteamClient008 *)factory( STEAMCLIENT_INTERFACE_VERSION_008, NULL );
	if ( !steamClient )
	{
		cout << "Error: Unable to load steamclient.dll" << endl;
		return EXIT_FAILURE;
	}

	steamPipe = steamClient->CreateSteamPipe();
	while (!steamPipe) // keep trying to get the pipe
	{
		steamPipe = steamClient->CreateSteamPipe();
		cout << ".";

		Sleep(100);
	}

	user = steamClient->ConnectToGlobalUser( steamPipe );
	while (!user)
	{
		user = steamClient->ConnectToGlobalUser( steamPipe);
		cout << ".";

		Sleep(100);
	}

	if ( !( steamPipe && user ) )
	{
		cout << "Unable to create steam pipe or user, please ensure steam is running and you are logged in." << endl;
		return EXIT_FAILURE;
	}

	CallbackMsg_t callbackMsg;
	HSteamCall steamCall;

	char fileName[] = "log.txt";
	fstream logFile( fileName, fstream::out | fstream::in | fstream::app );
	map<int, string> messageNameMap = MakeCallbackMap();

	while ( true )
	{
		if ( Steam_BGetCallback( steamPipe, &callbackMsg, &steamCall ) )
		{
			int32 callBack = callbackMsg.m_iCallback;
			ECallbackType type = ( ECallbackType )( ( callBack / 100 ) * 100 );
			string name = messageNameMap[callBack];
			
			if(name.empty()) {
				cout << "Callback: " << callBack << ", Type: " << EnumString<ECallbackType>::From( type ) << ", Size: " << callbackMsg.m_cubParam << endl << "  ";
				logFile << "Callback: " << callBack << ", Type: " << EnumString<ECallbackType>::From( type ) << ", Size: " << callbackMsg.m_cubParam << endl << "  ";
			} else {
				cout << "Callback: " << name << ", Type: " << EnumString<ECallbackType>::From( type ) << ", Size: " << callbackMsg.m_cubParam << endl << "  ";
				logFile << "Callback: " << name << ", Type: " << EnumString<ECallbackType>::From( type ) << ", Size: " << callbackMsg.m_cubParam << endl << "  ";
			}
			
			for ( int i = 0; i < callbackMsg.m_cubParam; i++ )
			{
				unsigned char value = callbackMsg.m_pubParam[ i ];
			
				cout << hex << setw( 2 ) << setfill( '0' ) << uppercase << (unsigned int)value;
				cout << " ";

				logFile << hex << setw( 2 ) << setfill( '0' ) << uppercase << (unsigned int)value;
				logFile << " ";
			}

			// log to file

			cout << resetiosflags( ios_base::hex | ios_base::uppercase ) << endl;
			logFile << resetiosflags( ios_base::hex | ios_base::uppercase ) << endl;

			cout << endl;
			logFile << endl;

			logFile.flush();

			Steam_FreeLastCallback( steamPipe );
		}

		Sleep(10);
	}

	return EXIT_SUCCESS;
}