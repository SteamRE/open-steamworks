
#include "SteamFriends001.h"

namespace dotnetworks
{

	SteamFriends001::SteamFriends001( void *steamFriends )
	{
		base = (ISteamFriends001 *)steamFriends;
	}

	// returns the local players name - guaranteed to not be NULL.
	String^ SteamFriends001::GetPersonaName()
	{
		return gcnew String(base->GetPersonaName());
	}
	// sets the player name, stores it on the server and publishes the changes to all friends who are online
	void SteamFriends001::SetPersonaName(String^ name)
	{
		STR_FROM_MANAGED(name, str);

		base->SetPersonaName(str);

		STR_FREE(str);
	}
	// gets the friend status of the current user
	PersonaState SteamFriends001::GetPersonaState()
	{
		return (PersonaState)base->GetPersonaState();
	}
	// sets the status, communicates to server, tells all friends
	void SteamFriends001::SetPersonaState( PersonaState ePersonaState )
	{
		base->SetPersonaState( (EPersonaState)ePersonaState );
	}

	// adds a friend to the users list.  Friend will be notified that they have been added, and have the option of accept/decline
	bool SteamFriends001::AddFriend( SteamID^ steamIDFriend )
	{
		return base->AddFriend( *(steamIDFriend->base) );
	}
	// removes the friend from the list, and blocks them from contacting the user again
	bool SteamFriends001::RemoveFriend( SteamID^ steamIDFriend )
	{
		return base->RemoveFriend( *(steamIDFriend->base) );
	}
	// returns true if the specified user is considered a friend (can see our online status)
	bool SteamFriends001::HasFriend( SteamID^ steamIDFriend )
	{
		return base->HasFriend( *(steamIDFriend->base) );
	}

	// gets the relationship to a user
	FriendRelationship SteamFriends001::GetFriendRelationship( SteamID^ steamIDFriend )
	{
		return (FriendRelationship)base->GetFriendRelationship( *(steamIDFriend->base) );
	}
	// returns true if the specified user is considered a friend (can see our online status)
	PersonaState SteamFriends001::GetFriendPersonaState( SteamID^ steamIDFriend )
	{
		return (PersonaState)base->GetFriendPersonaState( *(steamIDFriend->base) );
	}
	// retrieves details about the game the friend is currently playing - returns false if the friend is not playing any games
	bool SteamFriends001::GetFriendGamePlayed( SteamID^ steamIDFriend, [Out] uint64% pnGameID, [Out] uint32% punGameIP, [Out] uint16% pusGamePort )
	{
		uint64 tempGameID;
		uint32 tempIP;
		uint16 tempPort;

		bool ret = base->GetFriendGamePlayed( *(steamIDFriend->base), &tempGameID, &tempIP, &tempPort );

		pnGameID = tempGameID;
		punGameIP = tempIP;
		pusGamePort = tempPort;

		return ret;
	}
	// returns the name of a friend - guaranteed to not be NULL.
	String^ SteamFriends001::GetFriendPersonaName(SteamID^ steamId)
	{
		const char *pchName = base->GetFriendPersonaName( *( steamId->base ) );

		int wideLen = MultiByteToWideChar( CP_UTF8, 0, pchName, -1, NULL, 0 );
		wchar_t *wideName = new wchar_t[ wideLen ];

		MultiByteToWideChar( CP_UTF8, 0, pchName, -1, wideName, wideLen );

		String^ ret = gcnew String( wideName );

		delete [] wideName;

		return ret;
	}

	// adds a friend by email address or account name - value returned in callback
	SteamCallHandle^ SteamFriends001::AddFriendByName( String^ pchEmailOrAccountName )
	{
		STR_FROM_MANAGED(pchEmailOrAccountName, str);

		HSteamCall ret = base->AddFriendByName(str);

		STR_FREE(str);

		return gcnew SteamCallHandle( ret );
	}

	// friend iteration
	int SteamFriends001::GetFriendCount()
	{
		return base->GetFriendCount();
	}
	SteamID^ SteamFriends001::GetFriendByIndex( int iFriend )
	{
		return gcnew SteamID( base->GetFriendByIndex( iFriend ) );
	}

	// generic friend->friend message sending
	// DEPRECATED, use the sized-buffer version instead (has much higher max buffer size)
	void SteamFriends001::SendMsgToFriend( SteamID^ steamId, FriendMsgType msgType, String^ msg )
	{
		STR_FROM_MANAGED(msg, str);

		base->SendMsgToFriend( *(steamId->base), (EFriendMsgType)msgType, str);

		STR_FREE(str);
	}

	// steam registry, accessed by friend
	void SteamFriends001::SetFriendRegValue( SteamID^ steamIDFriend, String^ pchKey, String^ pchValue )
	{
		STR_FROM_MANAGED(pchKey, key);
		STR_FROM_MANAGED(pchValue, value);

		base->SetFriendRegValue( *(steamIDFriend->base), key, value );

		STR_FREE(key);
		STR_FREE(value);
	}
	String^ SteamFriends001::GetFriendRegValue( SteamID^ steamIDFriend, String^ pchKey )
	{
		STR_FROM_MANAGED(pchKey, key);

		String^ ret = gcnew String( base->GetFriendRegValue( *(steamIDFriend->base), key ) );

		STR_FREE(key);

		return ret;
	}

	// accesses old friends names - returns an empty string when their are no more items in the history
	String^ SteamFriends001::GetFriendPersonaNameHistory( SteamID^ steamIDFriend, int iPersonaName )
	{
		return gcnew String( base->GetFriendPersonaNameHistory( *(steamIDFriend->base), iPersonaName ) );
	}

	// chat message iteration
	// returns the number of bytes in the message, filling pvData with as many of those bytes as possible
	// returns 0 if the steamID or iChatID are invalid
	int SteamFriends001::GetChatMessage( SteamID^ steamId, int chatId, [Out] String^% msg, int msgSize, [Out] FriendMsgType% msgTypeOut )
	{
		EFriendMsgType msgType;  
        char *pvData = new char[msgSize];

		int ret = base->GetChatMessage( *(steamId->base), chatId, pvData, msgSize, &msgType);  

		int reqSize = MultiByteToWideChar( CP_UTF8, 0, pvData, -1, NULL, 0 );
		wchar_t *wideData = new wchar_t[ reqSize ];

		MultiByteToWideChar( CP_UTF8, 0, pvData, -1, wideData, reqSize );

		msg = gcnew String( wideData );
		msgTypeOut = (FriendMsgType)msgType;

		delete [] wideData;
		delete [] pvData;

		return ret;
	}

	// generic friend->friend message sending, takes a sized buffer
	bool SteamFriends001::SendMsgToFriend( SteamID^ steamIDFriend, EFriendMsgType eFriendMsgType, array<byte>^ pvMsgBody, int cubMsgBody )
	{
		//IntPtr memPtr = Marshal::AllocHGlobal(cubMsgBody);
		//Marshal::Copy(pvMsgBody, 0, memPtr, cubData);
		ARRAY_TO_PTR(pvMsgBody, mem, cubMsgBody);

		bool ret = base->SendMsgToFriend( *(steamIDFriend->base), (EFriendMsgType)eFriendMsgType, mem, cubMsgBody );

		ARRAY_FREE(mem);

		return ret;
	}

	// returns the chatID that a chat should be resumed from when switching chat contexts
	int SteamFriends001::GetChatIDOfChatHistoryStart( SteamID^ steamIDFriend )
	{
		return base->GetChatIDOfChatHistoryStart( *(steamIDFriend->base) );
	}
	// sets where a chat with a user should resume
	void SteamFriends001::SetChatHistoryStart( SteamID^ steamIDFriend, int iChatID )
	{
		base->SetChatHistoryStart( *(steamIDFriend->base), iChatID );
	}
	// clears the chat history - should be called when a chat dialog closes
	// the chat history can still be recovered by another context using SetChatHistoryStart() to reset the ChatIDOfChatHistoryStart
	void SteamFriends001::ClearChatHistory( SteamID^ steamIDFriend )
	{
		base->ClearChatHistory( *(steamIDFriend->base) );
	}
}