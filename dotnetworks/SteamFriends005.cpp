#pragma once

#include "SteamclientAPI.h"

#include "PersonaState.h"
#include "FriendRelationship.h"

#include "FriendGameInfo.cpp"
#include "SteamID.cpp"
#include "AppID.cpp"

#include "Macros.h"

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
		SteamFriends005( void *steamFriends )
		{
			base = (ISteamFriends005 *)steamFriends;
		}
		
	public:
		String^ GetPersonaName()
		{
			return gcnew String( base->GetPersonaName() );
		}

		void SetPersonaName( String^ pchPersonaName )
		{
			IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchPersonaName);
			char *str = (char *)strPtr.ToPointer();

			base->SetPersonaName( str );

			Marshal::FreeHGlobal(strPtr);
			return;
		}

		PersonaState GetPersonaState()
		{
			return (PersonaState)base->GetPersonaState( );
		}

		int GetFriendCount( int iFriendFlags )
		{
			return base->GetFriendCount( iFriendFlags );
		}

		SteamID^ GetFriendByIndex( int iFriend, int iFriendFlags )
		{
			return gcnew SteamID( base->GetFriendByIndex( iFriend, iFriendFlags ) );
		}

		FriendRelationship GetFriendRelationship( SteamID^ steamIDFriend )
		{
			return (FriendRelationship) base->GetFriendRelationship( *(steamIDFriend->base) );
		}

		PersonaState GetFriendPersonaState( SteamID^ steamIDFriend )
		{
			return (PersonaState) base->GetFriendPersonaState( *(steamIDFriend->base) );
		}

		String^ GetFriendPersonaName( SteamID^ steamIDFriend )
		{
			return gcnew String( base->GetFriendPersonaName( *(steamIDFriend->base) ) );
		}

		int GetFriendAvatar( SteamID^ steamIDFriend, int eAvatarSize )
		{
			return base->GetFriendAvatar( *(steamIDFriend->base), eAvatarSize );
		}

		bool GetFriendGamePlayed( SteamID^ steamIDFriend, [Out] FriendGameInfo^% pFriendGameInfo )
		{
			FriendGameInfo_t gameInfo;
			bool ret = base->GetFriendGamePlayed( *(steamIDFriend->base), &gameInfo );

			pFriendGameInfo = gcnew FriendGameInfo( &gameInfo );
			return ret;
		}

		String^ GetFriendPersonaNameHistory( SteamID^ steamIDFriend, int iPersonaName )
		{
			return gcnew String( base->GetFriendPersonaNameHistory( *(steamIDFriend->base), iPersonaName ) );
		}

		bool HasFriend( SteamID^ steamIDFriend, int iFriendFlags )
		{
			return base->HasFriend( *(steamIDFriend->base), iFriendFlags );
		}

		int GetClanCount( )
		{
			return base->GetClanCount( );
		}

		SteamID^ GetClanByIndex( int iClan )
		{
			return gcnew SteamID( base->GetClanByIndex( iClan ) );
		}

		String^ GetClanName( SteamID^ steamIDClan )
		{
			return gcnew String( base->GetClanName( *(steamIDClan->base) ) );
		}

		int GetFriendCountFromSource( SteamID^ steamIDSource )
		{
			return base->GetFriendCountFromSource( *(steamIDSource->base) );
		}

		CSteamID GetFriendFromSourceByIndex( SteamID^ steamIDSource, int iFriend )
		{
			return base->GetFriendFromSourceByIndex( *(steamIDSource->base), iFriend );
		}

		bool IsUserInSource( SteamID^ steamIDUser, SteamID^ steamIDSource )
		{
			return base->IsUserInSource( *(steamIDUser->base), *(steamIDSource->base) );
		}

		void SetInGameVoiceSpeaking( SteamID^ steamIDUser, bool bSpeaking )
		{
			base->SetInGameVoiceSpeaking( *(steamIDUser->base), bSpeaking );
		}

		void ActivateGameOverlay( String^ pchDialog )
		{
			STR_FROM_MANAGED(pchDialog, str);

			base->ActivateGameOverlay( str );

			STR_FREE(str);
		}

		void ActivateGameOverlayToUser( String^ pchDialog, SteamID^ steamIDUser )
		{
			STR_FROM_MANAGED(pchDialog, str);

			base->ActivateGameOverlayToUser( str, *(steamIDUser->base) );

			STR_FREE(str);
		}

		void ActivateGameOverlayToWebPage( String^ pchURL )
		{
			STR_FROM_MANAGED(pchURL, str);

			base->ActivateGameOverlayToWebPage( str );

			STR_FREE(str);
		}

		void ActivateGameOverlayToStore( AppID^ nAppID )
		{
			base->ActivateGameOverlayToStore( nAppID->base );
		}

		literal String^ InterfaceVersion = STEAMFRIENDS_INTERFACE_VERSION_005;

	private:
		ISteamFriends005 *base;
	};
}

