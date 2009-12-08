#pragma once

#include "SteamclientAPI.h"

#include "PersonaStateChange.cpp"
#include "FriendChatMsg.cpp"
#include "UserRequestingFriendship.cpp"
#include "FriendAdded.cpp"
#include "SteamWindowClosed.cpp"
#include "GameOverlayActivated.cpp"

namespace dotnetworks
{
	public ref class Callback
	{
	internal:
		Callback( CallbackMsg_t callbackMsg );

	public:
		int32 SteamUser;
		int CallbackNum;
		Object^ CallbackObject;
		int CallbackSize;
	};
}