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

#ifndef ISTEAMUSER005_H
#define ISTEAMUSER005_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "UserCommon.h"

class ISteamUser005
{
public:

	// returns the HSteamUser this interface represents
	// this is only used internally by the API, and by a few select interfaces that support multi-user
	virtual HSteamUser GetHSteamUser() = 0;

	// steam account management functions
	virtual void LogOn( CSteamID steamID ) = 0;
	virtual void LogOff() = 0;

	// returns true if the Steam client current has a live connection to the Steam servers. 
	// If false, it means there is no active connection due to either a networking issue on the local machine, or the Steam server is down/busy.
	// The Steam client will automatically be trying to recreate the connection as often as possible.
	virtual bool LoggedOn() = 0;

	virtual ELogonState GetLogonState() = 0;
	virtual bool Connected() = 0;

	// returns the CSteamID of the account currently logged into the Steam client
	// a CSteamID is a unique identifier for an account, and used to differentiate users in all parts of the Steamworks API
	virtual CSteamID GetSteamID() = 0;

	// returns true if this account is VAC banned from the specified ban set
	virtual bool IsVACBanned( EVACBan eVACBan ) = 0;

	// returns true if the user needs to see the newly-banned message from the specified ban set
	virtual bool RequireShowVACBannedMessage( EVACBan eVACBan ) = 0;

	// tells the server that the user has seen the 'you have been banned' dialog
	virtual void AcknowledgeVACBanning( EVACBan eVACBan ) = 0;

	// steam2 stuff
	virtual void SetSteam2Ticket( uint8 *pubTicket, int cubTicket ) = 0;
	virtual void AddServerNetAddress( uint32 unIP, uint16 unPort ) = 0;

	// email address setting
	virtual bool SetEmail( const char *pchEmail ) = 0;


	// persist per user data
	virtual bool SetRegistryString( ERegistrySubTree eRegistrySubTree, const char *pchKey, const char *pchValue ) = 0;
	virtual bool GetRegistryString( ERegistrySubTree eRegistrySubTree, const char *pchKey, char *pchValue, int cbValue ) = 0;
	virtual bool SetRegistryInt( ERegistrySubTree eRegistrySubTree, const char *pchKey, int iValue ) = 0;
	virtual bool GetRegistryInt( ERegistrySubTree eRegistrySubTree, const char *pchKey, int *piValue ) = 0;

	// InitiateGameConnection() starts the state machine for authenticating the game client with the game server
	// It is the client portion of a three-way handshake between the client, the game server, and the steam servers
	//
	// Parameters:
	// void *pAuthBlob - a pointer to empty memory that will be filled in with the authentication token.
	// int cbMaxAuthBlob - the number of bytes of allocated memory in pBlob. Should be at least 2048 bytes.
	// CSteamID steamIDGameServer - the steamID of the game server, received from the game server by the client
	// int nGameID - the ID of the current game.
	// uint32 unIPServer, uint16 usPortServer - the IP address of the game server
	// bool bSecure - whether or not the client thinks that the game server is reporting itself as secure (i.e. VAC is running)
	//
	// return value - returns the number of bytes written to pBlob. If the return is 0, then the buffer passed in was too small, and the call has failed
	// The contents of pBlob should then be sent to the game server, for it to use to complete the authentication process.
	virtual int InitiateGameConnection( void *pBlob, int cbMaxBlob, CSteamID steamID, CGameID nGameAppID, uint32 unIPServer, uint16 usPortServer, bool bSecure ) = 0;

	// notify of disconnect
	// needs to occur when the game client leaves the specified game server, needs to match with the InitiateGameConnection() call
	virtual void TerminateGameConnection( uint32 unIPServer, uint16 usPortServer ) = 0;

	// controls where chat messages go to - puts the caller on top of the stack of chat destinations
	virtual void SetSelfAsPrimaryChatDestination() = 0;
    // returns true if the current caller is the one that should open new chat dialogs
	virtual bool IsPrimaryChatDestination() = 0;

	virtual unknown_ret RequestLegacyCDKey( uint32 ) = 0;

	virtual unknown_ret SendGuestPassByEmail( const char*, uint64, bool ) = 0;
	virtual unknown_ret SendGuestPassByAccountID( uint32, uint64, bool ) = 0;

	virtual unknown_ret AckGuestPass( const char* ) = 0;

	virtual unknown_ret RedeemGuestPass( const char* ) = 0;

	virtual unknown_ret GetGuestPassToGiveCount( void ) = 0;
	virtual unknown_ret GetGuestPassToRedeemCount( void ) = 0;
	virtual unknown_ret GetGuestPassLastUpdateTime( void ) = 0;
	virtual unknown_ret GetGuestPassToGiveInfo( uint32, uint64 *, uint32 *, uint32 *, uint32 *, uint32 *, uint32 *, char *, int ) = 0;
	virtual unknown_ret GetGuestPassToRedeemInfo( uint32, uint64 *, uint32 *, uint32 *, uint32 *, uint32 *, uint32 * ) = 0;
	virtual unknown_ret GetGuestPassToRedeemSenderAddress( uint32, char *, int ) = 0;
	virtual unknown_ret GetGuestPassToRedeemSenderName( uint32, char *, int ) = 0;

	virtual unknown_ret AcknowledgeMessageByGID( const char* ) = 0;

	virtual unknown_ret SetLanguage( const char* ) = 0;

	// used by only a few games to track usage events
	virtual void TrackAppUsageEvent( CGameID gameID, int eAppUsageEvent, const char *pchExtraInfo = "" ) = 0;

	virtual unknown_ret SetAccountName( const char* ) = 0;
	virtual unknown_ret SetPassword( const char* ) = 0;

	virtual unknown_ret SetAccountCreationTime( uint32 ) = 0;
};


#endif // ISTEAMUSER005_H
