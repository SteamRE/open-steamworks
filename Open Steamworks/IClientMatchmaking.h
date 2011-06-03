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

#ifndef ICLIENTMATCHMAKING_H
#define ICLIENTMATCHMAKING_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "MatchmakingCommon.h"
#include "UserCommon.h"


abstract_class UNSAFE_INTERFACE IClientMatchmaking
{
public:
	virtual int GetFavoriteGameCount() = 0;
	virtual bool GetFavoriteGame( int iGame, AppId_t *pnAppID, uint32 *pnIP, uint16 *pnConnPort, uint16 *pnQueryPort, uint32 *punFlags, uint32 *pRTime32LastPlayedOnServer ) = 0;
	virtual int AddFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer ) =0;
	virtual bool RemoveFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags ) = 0;

	virtual SteamAPICall_t RequestLobbyList() = 0;

	virtual void AddRequestLobbyListStringFilter( const char *pchKeyToMatch, const char *pchValueToMatch, ELobbyComparison eComparisonType ) = 0;
	virtual void AddRequestLobbyListNumericalFilter( const char *pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType ) = 0;
	virtual void AddRequestLobbyListNearValueFilter( const char *pchKeyToMatch, int nValueToBeCloseTo ) = 0;
	virtual void AddRequestLobbyListFilterSlotsAvailable( int nSlotsAvailable ) = 0;
	virtual void AddRequestLobbyListDistanceFilter( ELobbyDistanceFilter filter ) = 0;
	virtual void AddRequestLobbyListResultCountFilter( int cMaxResults ) = 0;

	virtual CSteamID GetLobbyByIndex( int iLobby ) = 0;

	virtual SteamAPICall_t CreateLobby( ELobbyType eLobbyType, int cMaxMembers ) = 0;
	virtual SteamAPICall_t JoinLobby( CSteamID steamIDLobby ) = 0;
	virtual void LeaveLobby( CSteamID steamIDLobby ) = 0;
	virtual bool InviteUserToLobby( CSteamID steamIDLobby, CSteamID steamIDInvitee ) = 0;

	virtual int GetNumLobbyMembers( CSteamID steamIDLobby ) = 0;
	virtual CSteamID GetLobbyMemberByIndex( CSteamID steamIDLobby, int iMember ) = 0;

	virtual const char *GetLobbyData( CSteamID steamIDLobby, const char *pchKey ) = 0;
	virtual bool SetLobbyData( CSteamID steamIDLobby, const char *pchKey, const char *pchValue ) = 0;

	virtual int GetLobbyDataCount( CSteamID steamIDLobby ) = 0;
	virtual bool GetLobbyDataByIndex( CSteamID steamIDLobby, int iLobbyData, char *pchKey, int cchKeyBufferSize, char *pchValue, int cchValueBufferSize ) = 0;
	virtual bool DeleteLobbyData( CSteamID steamIDLobby, const char *pchKey ) = 0;

	virtual const char *GetLobbyMemberData( CSteamID steamIDLobby, CSteamID steamIDUser, const char *pchKey ) = 0;
	virtual void SetLobbyMemberData( CSteamID steamIDLobby, const char *pchKey, const char *pchValue ) = 0;

	virtual bool SendLobbyChatMsg( CSteamID steamIDLobby, const void *pvMsgBody, int cubMsgBody ) = 0;
	virtual int GetLobbyChatEntry( CSteamID steamIDLobby, int iChatID, CSteamID *pSteamIDUser, void *pvData, int cubData, EChatEntryType *peChatEntryType ) = 0;

	virtual bool RequestLobbyData( CSteamID steamIDLobby ) = 0;

	virtual void SetLobbyGameServer( CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer ) = 0;
	virtual bool GetLobbyGameServer( CSteamID steamIDLobby, uint32 *punGameServerIP, uint16 *punGameServerPort, CSteamID *psteamIDGameServer ) = 0;

	virtual bool SetLobbyMemberLimit( CSteamID steamIDLobby, int cMaxMembers ) = 0;
	virtual int GetLobbyMemberLimit( CSteamID steamIDLobby ) = 0;

	virtual void SetLobbyVoiceEnabled( CSteamID steamIDLobby, bool bVoiceEnabled ) = 0;
	virtual bool RequestFriendsLobbies() = 0;

	virtual bool SetLobbyType( CSteamID steamIDLobby, ELobbyType eLobbyType ) = 0;
	virtual bool SetLobbyJoinable( CSteamID steamIDLobby, bool bLobbyJoinable ) = 0;
	virtual CSteamID GetLobbyOwner( CSteamID steamIDLobby ) = 0;
	virtual bool SetLobbyOwner( CSteamID steamIDLobby, CSteamID steamIDNewOwner ) = 0;

	virtual int GetGMSServerCount() = 0;
	virtual bool GetGMSServerAddress( int iServer, uint32 *unServerIP, uint16 *usServerPort ) = 0;

	// TODO : Check this when at least one GMS will be online.
	virtual SteamAPICall_t BeginGMSQuery( AppId_t nAppId, int32 iRegionCode, const char* szFilterText ) = 0;
	virtual int32 PollGMSQuery( SteamAPICall_t ) = 0;
	virtual int32 GetGMSQueryResults( SteamAPICall_t, GMSQueryResult_t *, int32 iResultIndex ) = 0;
	virtual void ReleaseGMSQuery( SteamAPICall_t ) = 0;
};


#endif // ICLIENTMATCHMAKING_H
