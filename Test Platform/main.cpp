#define STEAMWORKS_CLIENT_INTERFACES

#include "Steamworks.h"

#pragma comment( lib, "../Resources/Libs/Win32/steamclient.lib" )

CSteamAPILoader loader;

int main()
{
	CreateInterfaceFn factory = loader.GetSteam3Factory();

	if ( !factory )
	{
		fprintf(stderr, "Unable to load steamclient factory.\n");
		return 1;
	}

	IClientEngine *pClientEngine = (IClientEngine *)factory( CLIENTENGINE_INTERFACE_VERSION, NULL );
	if ( !pClientEngine )
	{
		fprintf(stderr, "Unable to get the client engine.\n");
		return 1;
	}
	
	HSteamPipe hPipe;
	HSteamUser hUser = pClientEngine->CreateGlobalUser( &hPipe );
	if ( !hUser || !hPipe )
	{
		fprintf(stderr, "Unable to create the global user.\n");
		return 1;
	}

	IClientUser *pClientUser = (IClientUser *)pClientEngine->GetIClientUser( hUser, hPipe, CLIENTUSER_INTERFACE_VERSION );
	if ( !pClientUser )
	{
		fprintf(stderr, "Unable to get the client user interface.\n");
		pClientEngine->ReleaseUser(hPipe, hUser);
		pClientEngine->BReleaseSteamPipe(hPipe);
		return 1;
	}
	
	IClientFriends *pClientFriends = (IClientFriends *)pClientEngine->GetIClientFriends( hUser, hPipe, CLIENTFRIENDS_INTERFACE_VERSION );
	if ( !pClientFriends )
	{
		fprintf(stderr, "Unable to get the client friends interface.\n");
		pClientEngine->ReleaseUser(hPipe, hUser);
		pClientEngine->BReleaseSteamPipe(hPipe);
		return 1;
	}
	
	char szUsername[128] = "";
	char szPassword[128] = "";

	printf("Enter your username: ");
	if(fgets(szUsername, sizeof(szUsername), stdin))
	{
		szUsername[strlen(szUsername) - 1] = 0;
	}
	
	printf("Enter your password: ");
	if(fgets(szPassword, sizeof(szPassword), stdin))
	{
		szPassword[strlen(szPassword) - 1] = 0;
	}

	pClientUser->LogOnWithPassword(false, szUsername, szPassword);

	CallbackMsg_t callBack;
	CSteamID adminID;

	while ( true )
	{
		if ( Steam_BGetCallback( hPipe, &callBack ) )
		{
			switch (callBack.m_iCallback)
			{
			case SteamServersConnected_t::k_iCallback:
				{
					printf("Successfully logged on!\n");

					pClientUser->SetSelfAsPrimaryChatDestination();
					pClientFriends->SetPersonaState( k_EPersonaStateOnline );

					CSteamID friendID;
					for (int i = 0; i < pClientFriends->GetFriendCount(k_EFriendFlagImmediate); i++)
					{
						friendID = pClientFriends->GetFriendByIndex(i, k_EFriendFlagImmediate);

						if(strcmp(pClientFriends->GetFriendPersonaName(friendID), "Didrole") == 0) // Put the persona name of the friend to use as the 'front end' here.
						{
							const char* cszMessage = "I'm logged on!";
							pClientFriends->SendMsgToFriend(friendID, k_EChatEntryTypeChatMsg, cszMessage, strlen(cszMessage));
							adminID = friendID;

							break;
						}
					}
					break;
				}

			case SteamServerConnectFailure_t::k_iCallback:
				{
					SteamServerConnectFailure_t *pConnectFailureInfo = (SteamServerConnectFailure_t *)callBack.m_pubParam;
					fprintf(stderr, "Logon failed with eResult %u !\n", pConnectFailureInfo->m_eResult);

					pClientEngine->ReleaseUser(hPipe, hUser);
					pClientEngine->BReleaseSteamPipe(hPipe);

					return 1;
				}

			case FriendChatMsg_t::k_iCallback:
				{
					FriendChatMsg_t *pFriendMessageInfo = (FriendChatMsg_t *)callBack.m_pubParam;

					if(pFriendMessageInfo->m_ulSenderID != pClientUser->GetSteamID())
					{
						EChatEntryType eMsgType;
						CSteamID chatter;

						char szData[k_cchFriendChatMsgMax];  
						memset(szData, 0, k_cchFriendChatMsgMax);  

						int iLength = pClientFriends->GetChatMessage(pFriendMessageInfo->m_ulFriendID, pFriendMessageInfo->m_iChatID, szData, sizeof(szData), &eMsgType, &chatter);  

						if (eMsgType == k_EChatEntryTypeChatMsg || eMsgType == k_EChatEntryTypeEmote)  
						{
							printf("Message from %s: %s\n", pFriendMessageInfo->m_ulSenderID.Render(), szData);
							
							if (strcmp(szData, "quit") == 0 && pFriendMessageInfo->m_ulSenderID == adminID)
							{
								pClientFriends->SetPersonaState( k_EPersonaStateOffline );
								pClientUser->LogOff();
								pClientEngine->ReleaseUser(hPipe, hUser);
								pClientEngine->BReleaseSteamPipe(hPipe);

								return 0;
							}

							pClientFriends->SendMsgToFriend(pFriendMessageInfo->m_ulFriendID, eMsgType, szData, iLength);
						}
					}
					break;
				}
			}

			Steam_FreeLastCallback( hPipe );
		}

#ifdef _WIN32
		Sleep(10);
#else
		usleep(10000);
#endif
	}

	return 0;
}
