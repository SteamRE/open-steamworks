
#include "SteamFriends005.h"

#include "Macros.h"


namespace dotnetworks
{
	SteamFriends005::SteamFriends005( void *steamFriends )
	{
		base = (ISteamFriends005 *)steamFriends;
	}
	
	String^ SteamFriends005::GetPersonaName()
	{
		return gcnew String( base->GetPersonaName() );
	}

	void SteamFriends005::SetPersonaName( String^ pchPersonaName )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchPersonaName);
		char *str = (char *)strPtr.ToPointer();

		base->SetPersonaName( str );

		Marshal::FreeHGlobal(strPtr);
		return;
	}
	
	PersonaState SteamFriends005::GetPersonaState()
	{
		return (PersonaState)base->GetPersonaState( );
	}

	int SteamFriends005::GetFriendCount( int iFriendFlags )
	{
		return base->GetFriendCount( iFriendFlags );
	}
	
	SteamID^ SteamFriends005::GetFriendByIndex( int iFriend, int iFriendFlags )
	{
		return gcnew SteamID( base->GetFriendByIndex( iFriend, iFriendFlags ) );
	}

	FriendRelationship SteamFriends005::GetFriendRelationship( SteamID^ steamIDFriend )
	{
		return (FriendRelationship) base->GetFriendRelationship( *(steamIDFriend->base) );
	}

	PersonaState SteamFriends005::GetFriendPersonaState( SteamID^ steamIDFriend )
	{
		return (PersonaState) base->GetFriendPersonaState( *(steamIDFriend->base) );
	}

	String^ SteamFriends005::GetFriendPersonaName( SteamID^ steamIDFriend )
	{
		return gcnew String( base->GetFriendPersonaName( *(steamIDFriend->base) ) );
	}

	int SteamFriends005::GetFriendAvatar( SteamID^ steamIDFriend, int eAvatarSize )
	{
		return base->GetFriendAvatar( *(steamIDFriend->base), eAvatarSize );
	}

	bool SteamFriends005::GetFriendGamePlayed( SteamID^ steamIDFriend, [Out] FriendGameInfo^% pFriendGameInfo )
	{
		FriendGameInfo_t gameInfo;
		bool ret = base->GetFriendGamePlayed( *(steamIDFriend->base), &gameInfo );

		pFriendGameInfo = gcnew FriendGameInfo( &gameInfo );
		return ret;
	}

	String^ SteamFriends005::GetFriendPersonaNameHistory( SteamID^ steamIDFriend, int iPersonaName )
	{
		return gcnew String( base->GetFriendPersonaNameHistory( *(steamIDFriend->base), iPersonaName ) );
	}

	bool SteamFriends005::HasFriend( SteamID^ steamIDFriend, int iFriendFlags )
	{
		return base->HasFriend( *(steamIDFriend->base), iFriendFlags );
	}

	int SteamFriends005::GetClanCount( )
	{
		return base->GetClanCount( );
	}

	SteamID^ SteamFriends005::GetClanByIndex( int iClan )
	{
		return gcnew SteamID( base->GetClanByIndex( iClan ) );
	}

	String^ SteamFriends005::GetClanName( SteamID^ steamIDClan )
	{
		return gcnew String( base->GetClanName( *(steamIDClan->base) ) );
	}

	int SteamFriends005::GetFriendCountFromSource( SteamID^ steamIDSource )
	{
		return base->GetFriendCountFromSource( *(steamIDSource->base) );
	}

	CSteamID SteamFriends005::GetFriendFromSourceByIndex( SteamID^ steamIDSource, int iFriend )
	{
		return base->GetFriendFromSourceByIndex( *(steamIDSource->base), iFriend );
	}

	bool SteamFriends005::IsUserInSource( SteamID^ steamIDUser, SteamID^ steamIDSource )
	{
		return base->IsUserInSource( *(steamIDUser->base), *(steamIDSource->base) );
	}

	void SteamFriends005::SetInGameVoiceSpeaking( SteamID^ steamIDUser, bool bSpeaking )
	{
		base->SetInGameVoiceSpeaking( *(steamIDUser->base), bSpeaking );
	}

	void SteamFriends005::ActivateGameOverlay( String^ pchDialog )
	{
		STR_FROM_MANAGED(pchDialog, str);

		base->ActivateGameOverlay( str );

		STR_FREE(str);
	}

	void SteamFriends005::ActivateGameOverlayToUser( String^ pchDialog, SteamID^ steamIDUser )
	{
		STR_FROM_MANAGED(pchDialog, str);

		base->ActivateGameOverlayToUser( str, *(steamIDUser->base) );

		STR_FREE(str);
	}

	void SteamFriends005::ActivateGameOverlayToWebPage( String^ pchURL )
	{
		STR_FROM_MANAGED(pchURL, str);

		base->ActivateGameOverlayToWebPage( str );

		STR_FREE(str);
	}

	void SteamFriends005::ActivateGameOverlayToStore( AppID^ nAppID )
	{
		base->ActivateGameOverlayToStore( nAppID->base );
	}

}

