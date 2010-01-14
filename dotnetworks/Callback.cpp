#pragma once

#include "SteamclientAPI.h"

#include "SteamUserHandle.cpp"

#include "PersonaStateChange.cpp"
#include "FriendChatMsg.cpp"
#include "UserRequestingFriendship.cpp"
#include "FriendAdded.cpp"
#include "SteamWindowClosed.cpp"
#include "GameOverlayActivated.cpp"
#include "SocketStatusCallback.cpp"

namespace dotnetworks
{
	public ref class Callback
	{
	internal:
		Callback( CallbackMsg_t callbackMsg )
		{
			SteamUser = gcnew SteamUserHandle( callbackMsg.m_hSteamUser );

			CallbackNum = callbackMsg.m_iCallback;
			CallbackSize = callbackMsg.m_cubParam;

			switch ( CallbackNum )
			{

			case PersonaStateChange_t::k_iCallback:
				CallbackObject = gcnew PersonaStateChange( (PersonaStateChange_t *)callbackMsg.m_pubParam );
				break;

			case FriendChatMsg_t::k_iCallback:
				CallbackObject = gcnew FriendChatMsg( (FriendChatMsg_t *)callbackMsg.m_pubParam );
				break;

			case UserRequestingFriendship_t::k_iCallback:
				CallbackObject = gcnew UserRequestingFriendship( (UserRequestingFriendship_t *)callbackMsg.m_pubParam );
				break;

			case FriendAdded_t::k_iCallback:
				CallbackObject = gcnew FriendAdded( (FriendAdded_t *)callbackMsg.m_pubParam );
				break;

			case FriendEndChatSession_t::k_iCallback:
				CallbackObject = gcnew SteamWindowClosed( (FriendEndChatSession_t *)callbackMsg.m_pubParam );
				break;

			case GameOverlayActivated_t::k_iCallback:
				CallbackObject = gcnew GameOverlayActivated( (GameOverlayActivated_t *)callbackMsg.m_pubParam );
				break;

			case SocketStatusCallback_t::k_iCallback:
				CallbackObject = gcnew SocketStatusCallback( (SocketStatusCallback_t *)callbackMsg.m_pubParam );
				break;

			}
		}

	public:

		SteamUserHandle^ SteamUser;
		int CallbackNum;
		Object^ CallbackObject;
		int CallbackSize;
	};
}