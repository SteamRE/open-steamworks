#pragma once

#include "SteamclientAPI.h"

#include "SteamID.cpp"
#include "SteamUserHandle.cpp"
#include "SteamPipeHandle.cpp"

#include "ChatEntryType.h"

#include "Macros.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;

namespace dotnetworks
{
	public ref class ClientFriends
	{
	internal:
		ClientFriends( void *clientFriends )
		{
			base = (IClientFriends *)clientFriends;
		}

	public:
		bool SendChatMsg( SteamID^ steamIDchat, ChatEntryType eChatEntryType, String^ pvMsgBody, int cubMsgBody )
		{
			STR_FROM_MANAGED( pvMsgBody, str );

			bool ret = base->SendChatMsg( *(steamIDchat->base), (EChatEntryType)eChatEntryType, (void*)str, cubMsgBody);

			STR_FREE( str );

			return ret;
		}

		int GetChatRoomEntry( SteamID^ steamIDchat, int iChatID, SteamID^ steamIDuser, [Out] String^% pvData, int cubData, [Out] ChatEntryType% peChatEntryType )
		{
			char *msg = new char[ cubData ];
			CSteamID user;
			EChatEntryType type;


			int ret = base->GetChatRoomEntry( *(steamIDchat->base), iChatID, &user, msg, cubData, &type );

			peChatEntryType = (ChatEntryType)type;
			steamIDuser = gcnew SteamID( user.ConvertToUint64() );
			pvData = gcnew String( msg );
			
			delete [] pvData;

			return ret;
		}



	private:
		IClientFriends *base;
	};
}