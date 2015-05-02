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

#ifndef ISTEAMFRIENDS015_H
#define ISTEAMFRIENDS015_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "FriendsCommon.h"


//-----------------------------------------------------------------------------
// Purpose: interface to accessing information about individual users,
//			that can be a friend, in a group, on a game server or in a lobby with the local user
//-----------------------------------------------------------------------------
abstract_class ISteamFriends015
{
public:
	virtual const char *GetPersonaName() = 0;
	virtual SteamAPICall_t SetPersonaName(const char *pchPersonaName) = 0;
	virtual EPersonaState GetPersonaState() = 0;
	virtual int GetFriendCount(int iFriendFlags) = 0;
	STEAMWORKS_STRUCT_RETURN_2(CSteamID, GetFriendByIndex, int, iFriend, int, iFriendFlags) /*virtual CSteamID GetFriendByIndex( int iFriend, int iFriendFlags ) = 0;*/
	virtual EFriendRelationship GetFriendRelationship(CSteamID steamIDFriend) = 0;
	virtual EPersonaState GetFriendPersonaState(CSteamID steamIDFriend) = 0;
	virtual const char *GetFriendPersonaName(CSteamID steamIDFriend) = 0;
	virtual bool GetFriendGamePlayed(CSteamID steamID, FriendGameInfo_t *pGamePlayInfo) = 0;
	virtual const char *GetFriendPersonaNameHistory(CSteamID steamIDFriend, int iPersonaName) = 0;
	virtual int GetFriendSteamLevel(CSteamID steamIDFriend) = 0;
	virtual const char *GetPlayerNickname(CSteamID steamIDPlayer) = 0;
	virtual int16 GetFriendsGroupCount() = 0;
	virtual int16 GetFriendsGroupIDByIndex(int32) = 0;
	virtual const char * GetFriendsGroupName(int16) = 0;
	virtual unknown_ret GetFriendsGroupMembersCount(int16) = 0;
	virtual unknown_ret GetFriendsGroupMembersList(int16, CSteamID *, int32) = 0;
	virtual bool HasFriend(CSteamID steamIDFriend, int iFriendFlags) = 0;
	virtual int GetClanCount() = 0;
	STEAMWORKS_STRUCT_RETURN_1(CSteamID, GetClanByIndex, int, iClan) /*virtual CSteamID GetClanByIndex( int iClan ) = 0;*/
	virtual const char *GetClanName(CSteamID steamIDClan) = 0;
	virtual const char *GetClanTag(CSteamID steamIDClan) = 0;
	virtual bool GetClanActivityCounts(CSteamID steamID, int *pnOnline, int *pnInGame, int *pnChatting) = 0;
	virtual SteamAPICall_t DownloadClanActivityCounts(CSteamID groupIDs[], int nIds) = 0;
	virtual int GetFriendCountFromSource(CSteamID steamIDSource) = 0;
	STEAMWORKS_STRUCT_RETURN_2(CSteamID, GetFriendFromSourceByIndex, CSteamID, steamIDSource, int, iFriend) /*virtual CSteamID GetFriendFromSourceByIndex( CSteamID steamIDSource, int iFriend ) = 0;*/
	virtual bool IsUserInSource(CSteamID steamIDUser, CSteamID steamIDSource) = 0;
	virtual void SetInGameVoiceSpeaking(CSteamID steamIDUser, bool bSpeaking) = 0;
	virtual void ActivateGameOverlay(const char *pchDialog) = 0;
	virtual void ActivateGameOverlayToUser(const char *pchDialog, CSteamID steamID) = 0;
	virtual void ActivateGameOverlayToWebPage(const char *pchURL) = 0;
	virtual void ActivateGameOverlayToStore(AppId_t nAppID, EOverlayToStoreFlag eFlag) = 0;
	virtual void SetPlayedWith(CSteamID steamIDUserPlayedWith) = 0;
	virtual void ActivateGameOverlayInviteDialog(CSteamID steamIDLobby) = 0;
	virtual int GetSmallFriendAvatar(CSteamID steamIDFriend) = 0;
	virtual int GetMediumFriendAvatar(CSteamID steamIDFriend) = 0;
	virtual int GetLargeFriendAvatar(CSteamID steamIDFriend) = 0;
	virtual bool RequestUserInformation(CSteamID steamIDUser, bool bRequireNameOnly) = 0;
	virtual SteamAPICall_t RequestClanOfficerList(CSteamID steamIDClan) = 0;
	STEAMWORKS_STRUCT_RETURN_1(CSteamID, GetClanOwner, CSteamID, steamIDClan) /*virtual CSteamID GetClanOwner( CSteamID steamIDClan ) = 0;*/
	virtual int GetClanOfficerCount(CSteamID steamIDClan) = 0;
	STEAMWORKS_STRUCT_RETURN_2(CSteamID, GetClanOfficerByIndex, CSteamID, steamIDClan, int, iOfficer) /*virtual CSteamID GetClanOfficerByIndex( CSteamID steamIDClan, int iOfficer ) = 0;*/
	virtual EUserRestriction GetUserRestrictions() = 0;
	virtual bool SetRichPresence(const char *pchKey, const char *pchValue) = 0;
	virtual void ClearRichPresence() = 0;
	virtual const char *GetFriendRichPresence(CSteamID steamIDFriend, const char *pchKey) = 0;
	virtual int GetFriendRichPresenceKeyCount(CSteamID steamIDFriend) = 0;
	virtual const char *GetFriendRichPresenceKeyByIndex(CSteamID steamIDFriend, int iKey) = 0;
	virtual void RequestFriendRichPresence(CSteamID steamIDFriend) = 0;
	virtual bool InviteUserToGame(CSteamID steamIDFriend, const char *pchConnectString) = 0;
	virtual int GetCoplayFriendCount() = 0;
	STEAMWORKS_STRUCT_RETURN_1(CSteamID, GetCoplayFriend, int, iCoplayFriend) /*virtual CSteamID GetCoplayFriend( int iCoplayFriend ) = 0;*/
	virtual int GetFriendCoplayTime(CSteamID steamIDFriend) = 0;
	virtual AppId_t GetFriendCoplayGame(CSteamID steamIDFriend) = 0;
	virtual SteamAPICall_t JoinClanChatRoom(CSteamID steamIDClan) = 0;
	virtual bool LeaveClanChatRoom(CSteamID steamIDClan) = 0;
	virtual int GetClanChatMemberCount(CSteamID steamIDClan) = 0;
	STEAMWORKS_STRUCT_RETURN_2(CSteamID, GetChatMemberByIndex, CSteamID, steamIDClan, int, iUser) /*virtual CSteamID GetChatMemberByIndex( CSteamID steamIDClan, int iUser ) = 0;*/
	virtual bool SendClanChatMessage(CSteamID steamIDClanChat, const char *pchText) = 0;
	virtual int GetClanChatMessage(CSteamID steamIDClanChat, int iMessage, void *prgchText, int cchTextMax, EChatEntryType *peChatEntryType, CSteamID *pSteamIDChatter) = 0;
	virtual bool IsClanChatAdmin(CSteamID steamIDClanChat, CSteamID steamIDUser) = 0;
	virtual bool IsClanChatWindowOpenInSteam(CSteamID steamIDClanChat) = 0;
	virtual bool OpenClanChatWindowInSteam(CSteamID steamIDClanChat) = 0;
	virtual bool CloseClanChatWindowInSteam(CSteamID steamIDClanChat) = 0;
	virtual bool SetListenForFriendsMessages(bool bInterceptEnabled) = 0;
	virtual bool ReplyToFriendMessage(CSteamID steamIDFriend, const char *pchMsgToSend) = 0;
	virtual int GetFriendMessage(CSteamID steamIDFriend, int iMessageID, void *pvData, int cubData, EChatEntryType *peChatEntryType) = 0;
	virtual SteamAPICall_t GetFollowerCount(CSteamID steamID) = 0;
	virtual SteamAPICall_t IsFollowing(CSteamID steamID) = 0;
	virtual SteamAPICall_t EnumerateFollowingList(uint32 unStartIndex) = 0;
};


#endif // ISTEAMFRIENDS015_H