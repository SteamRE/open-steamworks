
#include <windows.h>

#include <string>
#include <cstdio>
#include <iostream>

#include "Steamworks.h"

int main()
{
	bool sessionClosed = true;
	bool fuckedOff = false;

	CSteamID stanId( (uint64)76561197996282699LL );

	ISteamClient007 *steamClient;
	if ( !Sys_LoadInterface( "steamclient", STEAMCLIENT_INTERFACE_VERSION_007, NULL, (void**)&steamClient ) )
	{
		getchar();
		return 0;
	}

	HSteamPipe pipe = steamClient->CreateSteamPipe();
	HSteamUser user = steamClient->ConnectToGlobalUser( pipe );

	ISteamFriends001 *steamFriends = (ISteamFriends001 *)steamClient->GetISteamFriends( user, pipe, STEAMFRIENDS_INTERFACE_VERSION_001 );

	CallbackMsg_t callBack;
	HSteamCall steamCall;

	while ( true )
	{
		if ( Steam_BGetCallback( pipe, &callBack, &steamCall ) )
		{
			if ( callBack.m_iCallback == FriendEndChatSession_t::k_iCallback )
			{
				FriendEndChatSession_t *chatEnd = (FriendEndChatSession_t *)callBack.m_pubParam;

				if ( chatEnd->m_SteamID == stanId )
				{
					sessionClosed = true;
					fuckedOff = false;
				}
			}
			if ( callBack.m_iCallback == FriendChatMsg_t::k_iCallback )
			{
				FriendChatMsg_t *chatMsg = (FriendChatMsg_t *)callBack.m_pubParam;

				if (chatMsg->m_ulSender != stanId.ConvertToUint64())
				{
					Steam_FreeLastCallback( pipe );

					continue;
				}

				EFriendMsgType msgType;
				steamFriends->GetChatMessage( chatMsg->m_ulSender, chatMsg->m_iChatID, NULL, 0, &msgType );

				if ( msgType == k_EFriendMsgTypeTyping )
				{
					if ( sessionClosed )
					{
						steamFriends->SendMsgToFriend( stanId, k_EFriendMsgTypeChat, "what teh fuck do you want" );
						sessionClosed = false;
					}
				}

				if ( msgType == k_EFriendMsgTypeChat )
				{
					if ( !fuckedOff )
					{
						steamFriends->SendMsgToFriend( stanId, k_EFriendMsgTypeChat, "no." );
						fuckedOff = true;
					}
				}
			}

			Steam_FreeLastCallback( pipe );

		}
		Sleep(10);
	}

	return 0;
}