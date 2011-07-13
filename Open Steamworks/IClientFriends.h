//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#ifndef ICLIENTFRIENDS_H
#define ICLIENTFRIENDS_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "FriendsCommon.h"


abstract_class UNSAFE_INTERFACE IClientFriends
{
public:

	// returns the local players name - guaranteed to not be NULL.
	virtual const char *GetPersonaName() = 0;

	// sets the player name, stores it on the server and publishes the changes to all friends who are online
	virtual void SetPersonaName( const char *pchPersonaName ) = 0;

	virtual bool IsPersonaNameSet() = 0;

	// gets the friend status of the current user
	virtual EPersonaState GetPersonaState() = 0;
	// sets the status, communicates to server, tells all friends
	virtual void SetPersonaState( EPersonaState ePersonaState ) = 0;

	virtual bool NotifyUIOfMenuChange( bool bShowAvatars, bool bSortByName, bool bShowOnlineOnly ) = 0;

	// friend iteration
	virtual int GetFriendCount( EFriendFlags iFriendFlags ) = 0;
	virtual CSteamID GetFriendByIndex( int iFriend, EFriendFlags iFriendFlags ) = 0;

	virtual int GetOnlineFriendCount() = 0;

	// gets the relationship to a user
	virtual EFriendRelationship GetFriendRelationship( CSteamID steamIDFriend ) = 0;
	virtual EPersonaState GetFriendPersonaState( CSteamID steamIDFriend ) = 0;
	// returns the name of a friend - guaranteed to not be NULL.
	virtual const char *GetFriendPersonaName( CSteamID steamIDFriend ) = 0;

	virtual void SetFriendAlias( CSteamID steamIDFriend, const char *pchAlias ) = 0;

	// gets the avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
	virtual int GetSmallFriendAvatar( CSteamID steamIDFriend ) = 0;
	virtual int GetMediumFriendAvatar( CSteamID steamIDFriend ) = 0;
	virtual int GetLargeFriendAvatar( CSteamID steamIDFriend ) = 0;

	// steam registry, accessed by friend
	virtual void SetFriendRegValue( CSteamID steamIDFriend, const char *pchKey, const char *pchValue ) = 0;
	virtual const char *GetFriendRegValue( CSteamID steamIDFriend, const char *pchKey ) = 0;

	virtual bool DeleteFriendRegValue( CSteamID steamID, const char *pchKey ) = 0;

	virtual bool GetFriendGamePlayed( CSteamID steamID, FriendGameInfo_t *pGamePlayInfo ) = 0;
	virtual const char *GetFriendGamePlayedExtraInfo( CSteamID steamID ) = 0;

	virtual CSteamID GetFriendGameServer( CSteamID steamID ) = 0;

	virtual unknown_ret GetFriendPersonaStateFlags( CSteamID steamID ) = 0;
	virtual bool IsFriendGameOnConsole( CSteamID steamID ) = 0;
	virtual unknown_ret GetFriendRestrictions( CSteamID steamID ) = 0;

	// accesses old friends names - returns an empty string when their are no more items in the history
	virtual const char *GetFriendPersonaNameHistory( CSteamID steamIDFriend, int iPersonaName ) = 0;
	
	virtual SteamAPICall_t RequestPersonaNameHistory( CSteamID steamIDFriend ) = 0;
	virtual const char * GetFriendPersonaNameHistoryAndDate( CSteamID steamIDFriend, int32 iPersonaName, RTime32 * puTime ) = 0;

	virtual bool AddFriend( CSteamID steamID ) = 0;
	virtual bool RemoveFriend( CSteamID steamID ) = 0;
	virtual bool HasFriend( CSteamID steamID, EFriendFlags iFriendFlags ) = 0;

	// adds a friend by email address or account name - value returned in callback
	virtual HSteamCall AddFriendByName( const char *pchEmailOrAccountName ) = 0;

	virtual bool InviteFriendByEmail( const char *pchEmailAddress ) = 0;

	virtual bool RequestUserInformation( CSteamID steamID, bool bUnk1 ) = 0;

	virtual bool SetIgnoreFriend( CSteamID steamID, bool bIgnore ) = 0;

	virtual bool ReportChatDeclined( CSteamID steamID ) = 0;
	
	
	virtual bool CreateFriendGroup( const char* pchGroupName ) = 0;
	virtual bool DeleteFriendGroup( int16 iGroupID ) = 0;
	virtual bool RenameFriendGroup( const char* pchNewGroupName, int16 iGroupID ) = 0;
	virtual bool AddFriendToGroup( CSteamID steamID, int16 iGroupID ) = 0;
	virtual bool RemoveFriendFromGroup( CSteamID steamID, int16 iGroupID ) = 0;
	virtual int16 GetFriendGroupCount() = 0;
	virtual int16 GetFriendGroupIDByIndex( int16 iGroupIndex ) = 0;
	virtual const char * GetFriendGroupName( int16 iGroupID ) = 0;
	virtual int16 GetFriendGroupMembershipCount( int16 iGroupID ) = 0;
	virtual CSteamID GetFirstFriendGroupMember( int16 iGroupID ) = 0;
	virtual CSteamID GetNextFriendGroupMember( int16 iGroupID ) = 0;
	virtual int16 GetGroupFriendMembershipCount( CSteamID steamID ) = 0;
	virtual int16 GetFirstGroupFriendMember( CSteamID steamID ) = 0;
	virtual int16 GetNextGroupFriendMember( CSteamID steamID ) = 0;

	// chat message iteration
	// returns the number of bytes in the message, filling pvData with as many of those bytes as possible
	// returns 0 if the steamID or iChatID are invalid
	virtual int GetChatMessage( CSteamID steamIDFriend, int iChatID, void *pvData, int cubData, EChatEntryType *peChatEntryType, CSteamID* pSteamIDChatter ) = 0;

	// generic friend->friend message sending, takes a sized buffer
	virtual bool SendMsgToFriend( CSteamID steamIDFriend, EChatEntryType eChatEntryType, const void *pvMsgBody, int cubMsgBody ) = 0;

	// clears the chat history - should be called when a chat dialog closes
	virtual void ClearChatHistory( CSteamID steamIDFriend ) = 0;

	virtual int GetKnownClanCount() = 0;
	virtual CSteamID GetKnownClanByIndex( int iClan ) = 0;
	virtual int GetClanCount() = 0;
	virtual CSteamID GetClanByIndex( int iClan ) = 0;

	virtual const char *GetClanName( CSteamID steamID ) = 0;
	virtual const char *GetClanTag( CSteamID steamID ) = 0;

	virtual bool GetFriendActivityCounts( int *a, int *b) = 0;
	virtual bool GetClanActivityCounts( CSteamID steamID, int *pnOnline, int *pnInGame, int *pnChatting ) = 0;

	virtual bool IsClanPublic( CSteamID steamID ) = 0;
	virtual bool IsClanLarge( CSteamID steamID ) = 0;

	virtual void SubscribeToPersonaStateFeed( CSteamID, bool ) = 0;

	virtual bool InviteFriendToClan( CSteamID steamIDfriend, CSteamID steamIDclan ) = 0;
	virtual bool AcknowledgeInviteToClan( CSteamID steamID, bool bAcceptOrDenyClanInvite ) = 0;

	// iterators for any source
	virtual int GetFriendCountFromSource( CSteamID steamIDSource ) = 0;
	virtual CSteamID GetFriendFromSourceByIndex( CSteamID steamIDSource, int iFriend ) = 0;
	virtual bool IsUserInSource( CSteamID steamIDUser, CSteamID steamIDSource ) = 0;

	virtual int GetCoplayFriendCount() = 0;
	virtual CSteamID GetCoplayFriend( int32 iIndex ) = 0;

	virtual RTime32 GetFriendCoplayTime( CSteamID steamID ) = 0;
	virtual AppId_t GetFriendCoplayGame( CSteamID steamID ) = 0;

	virtual bool SetRichPresence( AppId_t nAppId, const char *szKey, const char *szValue ) = 0;
	virtual void ClearRichPresence( AppId_t nAppId ) = 0;
	virtual const char* GetFriendRichPresence( AppId_t nAppId, CSteamID steamIDFriend, const char *szKey ) = 0;
	virtual int32 GetFriendRichPresenceKeyCount( AppId_t nAppId, CSteamID steamIDFriend ) = 0;
	virtual const char* GetFriendRichPresenceKeyByIndex( AppId_t nAppId, CSteamID steamIDFriend, int32 iIndex ) = 0;

	virtual void RequestFriendRichPresence( AppId_t nAppId, CSteamID steamID ) = 0;

	virtual bool JoinChatRoom( CSteamID steamID ) = 0;
	virtual void LeaveChatRoom( CSteamID steamID ) = 0;

	virtual bool InviteUserToChatRoom( CSteamID steamIDfriend, CSteamID steamIDchat ) = 0;

	virtual bool SendChatMsg( CSteamID steamIDchat, EChatEntryType eChatEntryType, const void *pvMsgBody, int cubMsgBody ) = 0;

	virtual int GetChatRoomEntry( CSteamID steamIDchat, int iChatID, CSteamID *steamIDuser, void *pvData, int cubData, EChatEntryType *peChatEntryType ) = 0;

	virtual void ClearChatRoomHistory( CSteamID steamID ) = 0;

	virtual bool SerializeChatRoomDlg( CSteamID steamIDchat, void const* pvHistory, int cubHistory ) = 0;
	virtual int GetSizeOfSerializedChatRoomDlg( CSteamID steamIDchat ) = 0;
	virtual bool GetSerializedChatRoomDlg( CSteamID steamIDchat, void* pvHistory, int cubBuffer, int* pcubData ) = 0;
	virtual bool ClearSerializedChatRoomDlg( CSteamID steamIDchat ) = 0;

	virtual bool KickChatMember( CSteamID steamIDchat, CSteamID steamIDuser ) = 0;
	virtual bool BanChatMember( CSteamID steamIDchat, CSteamID steamIDuser ) = 0;
	virtual bool UnBanChatMember( CSteamID steamIDchat, CSteamID steamIDuser ) = 0;

	virtual bool SetChatRoomType( CSteamID steamIDchat, ELobbyType eLobbyType ) = 0;
	virtual bool GetChatRoomLockState( CSteamID steamIDchat, bool *pbLocked ) = 0;
	virtual bool GetChatRoomPermissions( CSteamID steamIDchat, uint32 *prgfChatRoomPermissions ) = 0;

	virtual bool SetChatRoomModerated( CSteamID steamIDchat, bool bModerated ) = 0;
	virtual bool BChatRoomModerated( CSteamID steamIDChat ) = 0;

	virtual bool NotifyChatRoomDlgsOfUIChange( CSteamID steamIDchat, bool bShowAvatars, bool bBeepOnNewMsg, bool bShowSteamIDs, bool bShowTimestampOnNewMsg ) = 0;

	virtual bool TerminateChatRoom( CSteamID steamIDchat ) = 0;

	virtual int GetChatRoomCount() = 0;
	virtual CSteamID GetChatRoomByIndex( int iChatRoom ) = 0;

	virtual const char *GetChatRoomName( CSteamID steamIDchat ) = 0;

	virtual bool BGetChatRoomMemberDetails( CSteamID steamIDchat, CSteamID steamIDuser, uint32* pChatMemberDetails, uint32* pChatMemberDetailsLocal ) = 0;

	virtual void CreateChatRoom( EChatRoomType eType, uint64 ulGameID, const char *pchName, ELobbyType eLobbyType, CSteamID steamIDClan, CSteamID steamIDFriendChat, CSteamID steamIDInvited, uint32 chatPermissionOfficer, uint32 chatPermissionMember, uint32 chatPermissionAll ) = 0;

	virtual const char *GetChatRoomMetadata( CSteamID steamIDchat, CSteamID steamIDuser, const char *pchKey ) = 0;
	virtual bool SetChatRoomMetadata( CSteamID steamIDChat, CSteamID steamIDMember, const char *pchKey, const char *pchValue ) = 0;

	virtual bool SetChatRoomPermissions( CSteamID steamIDchat, CSteamID steamIDmemeber, uint32 permissions, bool bMakeOwner ) = 0;

	virtual void VoiceCall( CSteamID steamIDlocal, CSteamID steamIDremote ) = 0;
	virtual void VoiceHangUp( HVoiceCall hVoiceCall ) = 0;

	virtual bool SetVoiceSpeakerVolume( float flVolume ) = 0;
	virtual bool SetVoiceMicrophoneVolume( float flVolume ) = 0;

	virtual void SetAutoAnswer( bool bAutoAnswer ) = 0;

	virtual void VoiceAnswer( HVoiceCall hVoiceCall ) = 0;

	virtual void VoicePutOnHold( HVoiceCall HVoiceCall, bool bOnLocalHold ) = 0;
	virtual bool BVoiceIsLocalOnHold( HVoiceCall hVoiceCall ) = 0;
	virtual bool BVoiceIsRemoteOnHold( HVoiceCall hVoiceCall ) = 0;

	virtual void SetDoNotDisturb( bool bDoNotDisturb ) = 0;

	virtual void EnableVoiceNotificationSounds( bool bEnable ) = 0;

	virtual void SetPushToTalkEnabled( bool bEnabled ) = 0;
	virtual bool IsPushToTalkEnabled() = 0;

	virtual void SetPushToTalkKey( int nKey ) = 0;
	virtual int GetPushToTalkKey() = 0;

	virtual bool IsPushToTalkKeyDown() = 0;

	virtual void EnableVoiceCalibration( bool bEnable ) = 0;
	virtual bool IsVoiceCalibrating() = 0;
	virtual float GetVoiceCalibrationSamplePeak() = 0;

	virtual void SetMicBoost( bool bBoost ) = 0;
	virtual bool GetMicBoost() = 0;

	virtual bool HasHardwareMicBoost() = 0;

	virtual const char *GetMicDeviceName() = 0;

	virtual void StartTalking( HVoiceCall hVoiceCall ) = 0;
	virtual void EndTalking( HVoiceCall hVoiceCall ) = 0;

	virtual bool VoiceIsValid( HVoiceCall hVoiceCall ) = 0;

	virtual void SetAutoReflectVoice( bool bAuto ) = 0;

	virtual ECallState GetCallState( HVoiceCall hVoiceCall ) = 0;

	virtual float GetVoiceMicrophoneVolume() = 0;
	virtual float GetVoiceSpeakerVolume() = 0;

	virtual float TimeSinceLastVoiceDataReceived( HVoiceCall hVoiceCall ) = 0;
	virtual float TimeSinceLastVoiceDataSend( HVoiceCall hVoiceCall ) = 0;

	virtual bool BCanSend( HVoiceCall hVoiceCall ) = 0;
	virtual bool BCanReceive( HVoiceCall hVoiceCall ) = 0;

	virtual float GetEstimatedBitsPerSecond( HVoiceCall hVoiceCall, bool bIncoming ) = 0;
	virtual float GetPeakSample( HVoiceCall hVoiceCall, bool bIncoming ) = 0;

	virtual void SendResumeRequest( HVoiceCall hVoiceCall ) = 0;

	virtual void OpenChatDialog( CSteamID steamID ) = 0;

	virtual void StartChatRoomVoiceSpeaking( CSteamID steamIDchat, CSteamID steamIDuser ) = 0;
	virtual void EndChatRoomVoiceSpeaking( CSteamID steamIDchat, CSteamID steamIDuser ) = 0;

	virtual RTime32 GetFriendLastLogonTime( CSteamID steamID ) = 0;
	virtual RTime32 GetFriendLastLogoffTime( CSteamID steamID ) = 0;

	virtual int GetChatRoomVoiceTotalSlotCount( CSteamID steamIDchat ) = 0;
	virtual int GetChatRoomVoiceUsedSlotCount( CSteamID steamIDchat ) = 0;
	virtual CSteamID GetChatRoomVoiceUsedSlot( CSteamID steamID, int iSlot ) = 0;
	virtual EChatRoomVoiceStatus GetChatRoomVoiceStatus( CSteamID steamIDchat, CSteamID steamIDuser ) = 0;

	virtual bool BChatRoomHasAvailableVoiceSlots( CSteamID steamID ) = 0;

	virtual bool BIsChatRoomVoiceSpeaking( CSteamID steamIDchat, CSteamID steamIDuser ) = 0;

	virtual float GetChatRoomPeakSample( CSteamID steamIDchat, CSteamID steamIDuser, bool bIncoming ) = 0;

	virtual void ChatRoomVoiceRetryConnections( CSteamID steamIDchat ) = 0;

	virtual void SetPortTypes( uint32 unFlags ) = 0;

	virtual void ReinitAudio() = 0;

	virtual void SetInGameVoiceSpeaking( CSteamID steamIDuser, bool bIsSpeaking ) = 0;

	virtual bool IsInGameVoiceSpeaking() = 0;

	virtual void ActivateGameOverlay( const char *pchDialog ) = 0;
	virtual void ActivateGameOverlayToUser( const char *pchDialog, CSteamID steamID ) = 0;
	virtual void ActivateGameOverlayToWebPage( const char *pchUrl ) = 0;
	virtual void ActivateGameOverlayToStore( AppId_t nAppId ) = 0;
	virtual void ActivateGameOverlayInviteDialog( CSteamID steamIDLobby ) = 0;

	virtual void NotifyGameOverlayStateChanged( bool bActive ) = 0;
	virtual void NotifyGameServerChangeRequested( const char *pchServerAddress, const char *pchPassword ) = 0;
	virtual bool NotifyLobbyJoinRequested( AppId_t nAppId, CSteamID steamIDlobby, CSteamID steamIDfriend ) = 0;
	virtual bool NotifyRichPresenceJoinRequested( AppId_t nAppId, CSteamID steamID, const char *szUnk ) = 0;

	virtual EClanRelationship GetClanRelationship( CSteamID steamIDclan ) = 0;

	virtual EClanRank GetFriendClanRank( CSteamID steamIDuser, CSteamID steamIDclan ) = 0;

	virtual bool VoiceIsAvailable() = 0;

	virtual void TestVoiceDisconnect( HVoiceCall hVoiceCall ) = 0;
	virtual void TestChatRoomPeerDisconnect( CSteamID steamIDchat, CSteamID steamIDuser ) = 0;
	virtual void TestVoicePacketLoss( float flPacketDropFraction ) = 0;

	virtual HVoiceCall FindFriendVoiceChatHandle( CSteamID steamID ) = 0;

	virtual void RequestFriendsWhoPlayGame( CGameID gameId ) = 0;
	virtual uint32 GetCountFriendsWhoPlayGame( CGameID gameId ) = 0;

	virtual CSteamID GetFriendWhoPlaysGame( uint32 , CGameID gameId ) = 0;
	virtual void SetPlayedWith( CSteamID steamId ) = 0;
	
	virtual SteamAPICall_t RequestClanOfficerList( CSteamID clanId ) = 0;
	virtual CSteamID GetClanOwner( CSteamID clanId ) = 0;
	virtual int GetClanOfficerCount( CSteamID clanId ) = 0;
	virtual CSteamID GetClanOfficerByIndex( CSteamID clanId, int iIndex ) = 0;

	virtual unknown_ret GetUserRestrictions() = 0;

	virtual SteamAPICall_t RequestFriendProfileInfo( CSteamID friendID ) = 0;
	virtual const char* GetFriendProfileInfo( CSteamID friendID, const char* szKey ) = 0;

	virtual bool InviteUserToGame( CSteamID steamID, const char *szUnk ) = 0;

	virtual int GetOnlineConsoleFriendCount() = 0;

	virtual SteamAPICall_t RequestTrade( CSteamID steamID ) = 0;
	virtual void TradeResponse( unsigned int, bool ) = 0;
	virtual void CancelTradeRequest( CSteamID steamID ) = 0;
	
	virtual bool HideFriend( CSteamID friendID, bool bHide ) = 0;
	virtual const char * GetFriendFacebookName( CSteamID friendID ) = 0;
	virtual uint64 GetFriendFacebookID( CSteamID friendID ) = 0;
};

#endif // ICLIENTFRIENDS_H
