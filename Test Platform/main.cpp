#define STEAMWORKS_CLIENT_INTERFACES
#include "Steamworks.h"

#pragma comment( lib, "../Resources/steamclient" )

#ifdef _LINUX
// This is the poor man's delay load.
S_API bool STEAM_CALL Steam_BGetCallback( HSteamPipe hSteamPipe, CallbackMsg_t *pCallbackMsg )
{
	static bool (STEAM_CALL * _Steam_BGetCallback)(HSteamPipe, CallbackMsg_t *) = NULL;
	if(!_Steam_BGetCallback)
	{
		void* hSteamClient = dlopen("steamclient.so", RTLD_LAZY);
		if(hSteamClient)
		{
			_Steam_BGetCallback = (bool (STEAM_CALL *)(HSteamPipe, CallbackMsg_t *)) dlsym(hSteamClient, "Steam_BGetCallback");
			dlclose(hSteamClient);
		}
	}
	
	return _Steam_BGetCallback(hSteamPipe, pCallbackMsg);
}

S_API void STEAM_CALL Steam_FreeLastCallback( HSteamPipe hSteamPipe )
{
	static void (STEAM_CALL * _Steam_FreeLastCallback)(HSteamPipe) = NULL;
	if(!_Steam_FreeLastCallback)
	{
		void* hSteamClient = dlopen("steamclient.so", RTLD_LAZY);
		if(hSteamClient)
		{
			_Steam_FreeLastCallback = (void (STEAM_CALL *)(HSteamPipe)) dlsym(hSteamClient, "Steam_FreeLastCallback");
			dlclose(hSteamClient);
		}
	}
	
	return _Steam_FreeLastCallback(hSteamPipe);
}
#endif

int main()
{
	CSteamAPILoader loader;
	CreateInterfaceFn factory = loader.Load();

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
			case LogonSuccess_t::k_iCallback:
				{
					printf("Successfully logged on!\n");

					pClientUser->SetSelfAsPrimaryChatDestination();
					pClientFriends->SetPersonaState( k_EPersonaStateOnline );

					CSteamID friendID;
					for (int i = 0; i < pClientFriends->GetFriendCount(k_EFriendFlagImmediate); i++)
					{
						friendID = pClientFriends->GetFriendByIndex(i, k_EFriendFlagImmediate);

						if(strcmp(pClientFriends->GetFriendPersonaName(friendID), ":MIB: Asherkin") == 0) // Put the persona name of the friend to use as the 'front end' here.
						{
							const char* cszMessage = "I'm logged on!";
							pClientFriends->SendMsgToFriend(friendID, k_EChatEntryTypeChatMsg, cszMessage, strlen(cszMessage));
							adminID = friendID;

							break;
						}
					}
					break;
				}

			case LogonFailure_t::k_iCallback:
				{
					LogonFailure_t *pLoginFailureInfo = (LogonFailure_t *)callBack.m_pubParam;
					fprintf(stderr, "Logon failed with eResult %u !\n", pLoginFailureInfo->m_eResult);

					pClientEngine->ReleaseUser(hPipe, hUser);
					pClientEngine->BReleaseSteamPipe(hPipe);

					return 1;
				}

			case FriendChatMsg_t::k_iCallback:
				{
					FriendChatMsg_t *pFriendMessageInfo = (FriendChatMsg_t *)callBack.m_pubParam;
					if (pFriendMessageInfo->m_ulSender == adminID)
					{
						EChatEntryType eMsgType;
						CSteamID chatter;

						char szData[k_cchFriendChatMsgMax];  
						memset(szData, 0, k_cchFriendChatMsgMax);  

						int iLength = pClientFriends->GetChatMessage(pFriendMessageInfo->m_ulSender, pFriendMessageInfo->m_iChatID, szData, sizeof(szData), &eMsgType, &chatter);  

						if (eMsgType == k_EChatEntryTypeChatMsg || eMsgType == k_EChatEntryTypeEmote)  
						{
							printf("Message from %s: %s\n", pFriendMessageInfo->m_ulSender.Render(), szData);

							if (strcmp(szData, "quit") == 0)
							{
								pClientFriends->SetPersonaState( k_EPersonaStateOffline );
								pClientUser->LogOff();
								
								ELogonState eState;
								do
								{
									eState = pClientUser->GetLogonState();
								}
								while ( eState == k_ELogonStateLoggingOff || eState == k_ELogonStateLoggedOn );

								pClientEngine->ReleaseUser(hPipe, hUser);
								pClientEngine->BReleaseSteamPipe(hPipe);

								return 0;
							}

							pClientFriends->SendMsgToFriend(pFriendMessageInfo->m_ulSender, eMsgType, szData, iLength);
						}
					}
					break;
				}
			}

			Steam_FreeLastCallback( hPipe );
		}

#if defined _WIN32
		Sleep(10);
#elif defined _LINUX
		usleep(10000);
#endif
	}
	
	return 0;
}
