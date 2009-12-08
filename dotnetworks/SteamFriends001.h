#pragma once

#include "Macros.h"

#include "SteamclientAPI.h"

#include "FriendRelationship.h"
#include "PersonaState.h"
#include "SteamID.h"
#include "FriendMsgType.h"
#include "SteamCallHandle.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;



namespace dotnetworks
{
	public ref class SteamFriends001
	{
	internal:
		SteamFriends001( void *steamFriends );

	public:
		// returns the local players name - guaranteed to not be NULL.
		String^ GetPersonaName();
		// sets the player name, stores it on the server and publishes the changes to all friends who are online
		void SetPersonaName(String^ name);
		// gets the friend status of the current user
		PersonaState GetPersonaState();
		// sets the status, communicates to server, tells all friends
		void SetPersonaState( PersonaState ePersonaState );

		// adds a friend to the users list.  Friend will be notified that they have been added, and have the option of accept/decline
		bool AddFriend( SteamID^ steamIDFriend );
		// removes the friend from the list, and blocks them from contacting the user again
		bool RemoveFriend( SteamID^ steamIDFriend );
		// returns true if the specified user is considered a friend (can see our online status)
		bool HasFriend( SteamID^ steamIDFriend );

		// gets the relationship to a user
		FriendRelationship GetFriendRelationship( SteamID^ steamIDFriend );
		// returns true if the specified user is considered a friend (can see our online status)
		PersonaState GetFriendPersonaState( SteamID^ steamIDFriend );
		// retrieves details about the game the friend is currently playing - returns false if the friend is not playing any games
		bool GetFriendGamePlayed( SteamID^ steamIDFriend, [Out] uint64% pnGameID, [Out] uint32% punGameIP, [Out] uint16% pusGamePort );
		// returns the name of a friend - guaranteed to not be NULL.
		String^ GetFriendPersonaName(SteamID^ steamId);

		// adds a friend by email address or account name - value returned in callback
		SteamCallHandle^ AddFriendByName( String^ pchEmailOrAccountName );

		// friend iteration
		int GetFriendCount();
		SteamID^ GetFriendByIndex( int iFriend );

		// generic friend->friend message sending
		// DEPRECATED, use the sized-buffer version instead (has much higher max buffer size)
		void SendMsgToFriend( SteamID^ steamId, FriendMsgType msgType, String^ msg );

		// steam registry, accessed by friend
		void SetFriendRegValue( SteamID^ steamIDFriend, String^ pchKey, String^ pchValue );
		String^ GetFriendRegValue( SteamID^ steamIDFriend, String^ pchKey );

		// accesses old friends names - returns an empty string when their are no more items in the history
		String^ GetFriendPersonaNameHistory( SteamID^ steamIDFriend, int iPersonaName );

		// chat message iteration
		// returns the number of bytes in the message, filling pvData with as many of those bytes as possible
		// returns 0 if the steamID or iChatID are invalid
		int GetChatMessage( SteamID^ steamId, int chatId, [Out] String^% msg, int msgSize, [Out] FriendMsgType% msgTypeOut );

		// generic friend->friend message sending, takes a sized buffer
		bool SendMsgToFriend( SteamID^ steamIDFriend, EFriendMsgType eFriendMsgType, array<byte>^ pvMsgBody, int cubMsgBody );

		// returns the chatID that a chat should be resumed from when switching chat contexts
		int GetChatIDOfChatHistoryStart( SteamID^ steamIDFriend );
		// sets where a chat with a user should resume
		void SetChatHistoryStart( SteamID^ steamIDFriend, int iChatID );
		// clears the chat history - should be called when a chat dialog closes
		// the chat history can still be recovered by another context using SetChatHistoryStart() to reset the ChatIDOfChatHistoryStart
		void ClearChatHistory( SteamID^ steamIDFriend );

		literal String^ InterfaceVersion = STEAMFRIENDS_INTERFACE_VERSION_001;

	private:
		ISteamFriends001 *base;
	};
}