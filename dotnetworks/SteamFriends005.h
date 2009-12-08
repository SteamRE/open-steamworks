#pragma once

#include "SteamclientAPI.h"

#include "PersonaState.h"
#include "SteamID.h"
#include "FriendRelationship.h"
#include "FriendGameInfo.h"
#include "AppID.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;


namespace dotnetworks
{
	public ref class SteamFriends005
	{
	internal:
		SteamFriends005( void *steamFriends );
		
	public:
		String^ GetPersonaName();

		void SetPersonaName( String^ pchPersonaName );
		
		PersonaState GetPersonaState();

		int GetFriendCount( int iFriendFlags );
		
		SteamID^ GetFriendByIndex( int iFriend, int iFriendFlags );

		FriendRelationship GetFriendRelationship( SteamID^ steamIDFriend );

		PersonaState GetFriendPersonaState( SteamID^ steamIDFriend );

		String^ GetFriendPersonaName( SteamID^ steamIDFriend );

		int GetFriendAvatar( SteamID^ steamIDFriend, int eAvatarSize );

		bool GetFriendGamePlayed( SteamID^ steamIDFriend, [Out] FriendGameInfo^% pFriendGameInfo );

		String^ GetFriendPersonaNameHistory( SteamID^ steamIDFriend, int iPersonaName );

		bool HasFriend( SteamID^ steamIDFriend, int iFriendFlags );

		int GetClanCount( );

		SteamID^ GetClanByIndex( int iClan );

		String^ GetClanName( SteamID^ steamIDClan );

		int GetFriendCountFromSource( SteamID^ steamIDSource );

		CSteamID GetFriendFromSourceByIndex( SteamID^ steamIDSource, int iFriend );

		bool IsUserInSource( SteamID^ steamIDUser, SteamID^ steamIDSource );

		void SetInGameVoiceSpeaking( SteamID^ steamIDUser, bool bSpeaking );

		void ActivateGameOverlay( String^ pchDialog );
		void ActivateGameOverlayToUser( String^ pchDialog, SteamID^ steamIDUser );

		void ActivateGameOverlayToWebPage( String^ pchURL );

		void ActivateGameOverlayToStore( AppID^ nAppID );

		literal String^ InterfaceVersion = STEAMFRIENDS_INTERFACE_VERSION_005;

	private:
		ISteamFriends005 *base;
	};
}

