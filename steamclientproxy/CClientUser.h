#pragma once

DEFINE_PROXY_CLASS(CClientUser, IClientUser)

	CLASS_PROXY(HSteamUser, GetHSteamUser, (), ())

	// steam account management functions
	DECL_CLASS_PROXY(void, LogOn, (CSteamID steamID))
		::Log("[%s]\tCClientUser::LogOn( steamID = \"%s\" (%lld) )\n", callerModule.szModule, steamID.Render(), steamID.ConvertToUint64());
	RETURN_CLASS_PROXY(LogOn, (steamID))

	CLASS_PROXY(void, LogOff, (), ())
	CLASS_PROXY(bool, LoggedOn, (), ())
	CLASS_PROXY(ELogonState, GetLogonState, (), ())
	CLASS_PROXY(bool, Connected, (), ())
	CLASS_PROXY(CSteamID, GetSteamID, (), ())

	// returns true if this account is VAC banned from the specified ban set
	CLASS_PROXY(bool, IsVACBanned, (EVACBan eVACBan), (eVACBan))

	// returns true if the user needs to see the newly-banned message from the specified ban set
	CLASS_PROXY(bool, RequireShowVACBannedMessage, (EVACBan eVACBan), (eVACBan))

	// tells the server that the user has seen the 'you have been banned' dialog
	CLASS_PROXY(void, AcknowledgeVACBanning, (EVACBan eVACBan), (eVACBan))

	// email address setting
	DECL_CLASS_PROXY(bool, SetEmail, ( const char *pchEmail ))
		::Log("[%s]\tCClientUser::SetEmail( pchEmail = \"%s\" )\n", callerModule.szModule, pchEmail);
	RETURN_CLASS_PROXY(SetEmail, (pchEmail))

	// steam2 stuff
	DECL_CLASS_PROXY(void, SetSteam2Ticket, ( uint8 *pubTicket, int cubTicket ))
		Log("[%s]\tCClientUser::SetSteam2Ticket( a = \"%s\" (%d), b = \"%s\" (%d) )\n", callerModule.szModule, (char*)pubTicket, pubTicket, (char*)cubTicket, cubTicket);
	RETURN_CLASS_PROXY(SetSteam2Ticket, (pubTicket, cubTicket))

	// persist per user data
	CLASS_PROXY(bool, SetRegistryString, ( ERegistrySubTree eRegistrySubTree, const char *pchKey, const char *pchValue ), (eRegistrySubTree, pchKey, pchValue))
	CLASS_PROXY(bool, GetRegistryString, ( ERegistrySubTree eRegistrySubTree, const char *pchKey, char *pchValue, int cbValue ), (eRegistrySubTree, pchKey, pchValue, cbValue))
	CLASS_PROXY(bool, SetRegistryInt, ( ERegistrySubTree eRegistrySubTree, const char *pchKey, int iValue ), (eRegistrySubTree, pchKey, iValue))
	CLASS_PROXY(bool, GetRegistryInt, ( ERegistrySubTree eRegistrySubTree, const char *pchKey, int *piValue ), (eRegistrySubTree, pchKey, piValue))

	// InitiateGameConnection() starts the state machine for authenticating the game client with the game server
	// It is the client portion of a three-way handshake between the client, the game server, and the steam servers
	//
	// Parameters:
	// void *pAuthBlob - a pointer to empty memory that will be filled in with the authentication token.
	// int cbMaxAuthBlob - the number of bytes of allocated memory in pBlob. Should be at least 2048 bytes.
	// CSteamID steamIDGameServer - the steamID of the game server, received from the game server by the client
	// CGameID gameID - the ID of the current game. For games without mods, this is just CGameID( <appID> )
	// uint32 unIPServer, uint16 usPortServer - the IP address of the game server
	// bool bSecure - whether or not the client thinks that the game server is reporting itself as secure (i.e. VAC is running)
	//
	// return value - returns the number of bytes written to pBlob. If the return is 0, then the buffer passed in was too small, and the call has failed
	// The contents of pBlob should then be sent to the game server, for it to use to complete the authentication process.
	CLASS_PROXY(int, InitiateGameConnection, ( void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, CGameID gameID, uint32 unIPServer, uint16 usPortServer, bool bSecure ), (pAuthBlob, cbMaxAuthBlob, steamIDGameServer, gameID, unIPServer, usPortServer, bSecure ))
	CLASS_PROXY(int, InitiateGameConnectionOld, ( void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, CGameID gameID, uint32 unIPServer, uint16 usPortServer, bool bSecure, void *pvSteam2GetEncryptionKey, int cbSteam2GetEncryptionKey ), (pAuthBlob, cbMaxAuthBlob, steamIDGameServer, gameID, unIPServer, usPortServer, bSecure, pvSteam2GetEncryptionKey, cbSteam2GetEncryptionKey ))

	// notify of disconnect
	// needs to occur when the game client leaves the specified game server, needs to match with the InitiateGameConnection() call
	CLASS_PROXY(void,  TerminateGameConnection,( uint32 unIPServer, uint16 usPortServer ), (unIPServer, usPortServer))

	// controls where chat messages go to - puts the caller on top of the stack of chat destinations
	CLASS_PROXY(void, SetSelfAsPrimaryChatDestination, (), ())
    // returns true if the current caller is the one that should open new chat dialogs
	CLASS_PROXY(bool, IsPrimaryChatDestination, (), ())

	CLASS_PROXY(void, RequestLegacyCDKey, (AppId_t iAppID), (iAppID))

	CLASS_PROXY(bool, SendGuestPassByEmail, ( const char *pchEmailAccount , GID_t gidGuestPassID, bool bResending ), (pchEmailAccount, gidGuestPassID, bResending ))
	CLASS_PROXY(bool, SendGuestPassByAccountID, ( uint32 uAccountID, GID_t gidGuestPassID, bool bResending ), (uAccountID, gidGuestPassID, bResending ))

	CLASS_PROXY(bool, AckGuestPass, ( const char *pchGuestPassCode ), (pchGuestPassCode))
	CLASS_PROXY(bool, RedeemGuestPass, ( const char *pchGuestPassCode ), (pchGuestPassCode))

	CLASS_PROXY(uint32, GetGuestPassToGiveCount, (), ())
	CLASS_PROXY(uint32, GetGuestPassToRedeemCount, (), ())
	CLASS_PROXY(uint32, GetGuestPassLastUpdateTime, (), ())

	CLASS_PROXY(bool, GetGuestPassToGiveInfo, (uint32 nPassIndex, GID_t* pgidGuestPassID, PackageId_t* pnPackageID, RTime32* pRTime32Created, RTime32* pRTime32Expiration, RTime32* pRTime32Sent, RTime32* pRTime32Redeemed, char* pchRecipientAddress, int cRecipientAddressSize ),
	(nPassIndex, pgidGuestPassID, pnPackageID, pRTime32Created, pRTime32Expiration, pRTime32Sent, pRTime32Redeemed, pchRecipientAddress, cRecipientAddressSize))
	CLASS_PROXY(bool, GetGuestPassToRedeemInfo, ( uint32 a, uint64 *b, uint32 *c, uint32 *d, uint32 *e, uint32 *f, uint32 *g ), (a, b, c, d, e, f, g))
	CLASS_PROXY(bool, GetGuestPassToRedeemSenderAddress, ( uint32 a, char *b, int c ), (a, b, c))
	CLASS_PROXY(bool, GetGuestPassToRedeemSenderName, ( uint32 a, char *b, int c ), (a, b, c))

	CLASS_PROXY(bool, RequestGuestPassTargetList, ( uint64 a ), (a))

	CLASS_PROXY(bool, RequestGiftTargetList, ( uint32 a ), (a))

	CLASS_PROXY(void, AcknowledgeMessageByGID, ( const char* a ), (a))

	DECL_CLASS_PROXY(unknown_ret, SetLanguage, ( const char* pchLanguage ))
		::Log("[%s]\tCClientUser::SetLanguage( pchLanguage = \"%s\" )\n", callerModule.szModule, pchLanguage);
	RETURN_CLASS_PROXY(SetLanguage, (pchLanguage))

	// used by only a few games to track usage events
	DECL_CLASS_PROXY(void, TrackAppUsageEvent, (CGameID gameID, int eAppUsageEvent, char const* pchExtraInfo = ""))
		::Log("[%s]\tCClientUser::TrackAppUsageEvent( gameID = %d, eAppUsageEvent = %d, pchExtraInfo = \"%s\" )\n", callerModule.szModule, gameID.AppID(), eAppUsageEvent, pchExtraInfo );
	RETURN_CLASS_PROXY(TrackAppUsageEvent, (gameID, eAppUsageEvent, pchExtraInfo))

	//CLASS_PROXY(unknown_ret, RaiseConnectionPriority, (EConnectionPriority ), ())
	CLASS_PROXY(unknown_ret, RaiseConnectionPriority, (uint32 a), (a))

	CLASS_PROXY(void, ResetConnectionPriority, (int a), (a))
	CLASS_PROXY(void, SetAccountName, ( const char *a), (a))
	CLASS_PROXY(void, SetPassword, ( const char *a ), (a))

	CLASS_PROXY(void, SetAccountCreationTime, (uint32 creationTime), (creationTime))

	CLASS_PROXY(bool, DoesTextContainUserPassword,(char const* pchText), (pchText))

	CLASS_PROXY(uint32, GetCMIPAddress, (), ())
	CLASS_PROXY(uint32, GetP2PRelayIPAddress, (), ())
	// ---------------------------------------------------------

	CLASS_PROXY(bool, GetOneTimeWGAuthPassword,( char *a, int b), (a, b))
	CLASS_PROXY(bool, GetLanguage,( char *a, int b), (a, b))
	CLASS_PROXY(void, SetCyberCafe, (bool a), (a))
	CLASS_PROXY(void, ChangePasswordOld, ( const char *a, const char *b ), (a, b))
	CLASS_PROXY(void, ChangeEmailOld, ( const char *a ), (a))
	CLASS_PROXY(void, ChangeSecretQuestionAndAnswerOld, ( const char *a, int b, const char *c, const char *d ), (a, b, c, d))
	CLASS_PROXY(void, CreateAccount, ( const char *a, const char *b, const char *c, int d, const char *e, const char *f ), (a, b, c, d, e, f))
	CLASS_PROXY(void, CheckPassword, ( const char *a, const char *b, bool c ), (a, b, c))
	CLASS_PROXY(void, ResetPassword, ( const char *a, const char *b, const char *c, const char *d, const char *e ), (a, b, c, d, e ))
	CLASS_PROXY(void, TrackNatTraversalStat, ( const CNatTraversalStat *a ), (a))
	CLASS_PROXY(void, RefreshSteam2Login, (), ())
	CLASS_PROXY(PackageId_t, GetPackageIDForGuestPassToRedeemByGID, ( uint64 a ), (a))

	//CLASS_PROXY(unknown_ret, TrackSteamUsageEvent( ESteamUsageEvent, unsigned const char*, uint32 ) = 0;
	CLASS_PROXY(void, TrackSteamUsageEvent, (uint32 eSteamUsageEvent, const char* pubKV, uint32 cubKV), (eSteamUsageEvent, pubKV, cubKV))

	CLASS_PROXY(void, SetComputerInUse, (), ())

	CLASS_PROXY(bool, IsGameRunning, (CGameID gameId), (gameId))

	CLASS_PROXY(uint64, GetCurrentSessionToken, (), ())

	CLASS_PROXY(bool, UpdateAppOwnershipTicket, ( uint32 a, bool b ), (a, b))

	CLASS_PROXY(unknown_ret, RequestCustomBinary, ( const char *a, uint32 b, bool c), (a, b, c))

	CLASS_PROXY(unknown_ret, IsWaitingForCustomBinaries, (uint32 a ), (a))

	CLASS_PROXY(void, SetCellID, (uint32 a), (a))

	// get the local storage folder for current Steam account to write application data, e.g. save games, configs etc.
	// this will usually be something like "C:\Progam Files\Steam\userdata\<SteamID>\<AppID>\local"
	CLASS_PROXY(bool, GetUserDataFolder, (CGameID gameID, char* pchBuffer, int cubBuffer), (gameID, pchBuffer, cubBuffer))

	CLASS_PROXY(bool, GetAccountName,( char *a, uint32 b ), (a, b))

	CLASS_PROXY(bool, GetLegacyCDKey,( uint32 a, char *b, int c ), (a, b, c))
	CLASS_PROXY(bool, HasLegacyCDKey, (uint32 a), (a))

	CLASS_PROXY(void, RemoveLegacyCDKey, (uint32 a), (a))

	// Starts voice recording. Once started, use GetCompressedVoice() to get the data
	CLASS_PROXY(void, StartVoiceRecording, (), ())

	// Stops voice recording. Because people often release push-to-talk keys early, the system will keep recording for
	// a little bit after this function is called. GetCompressedVoice() should continue to be called until it returns
	// k_eVoiceResultNotRecording
	CLASS_PROXY(void, StopVoiceRecording, (), ())

	CLASS_PROXY(void, ResetVoiceRecording, (), ())

	// Gets the latest voice data. It should be called as often as possible once recording has started.
	// nBytesWritten is set to the number of bytes written to pDestBuffer. 
	//CLASS_PROXY(EVoiceResult GetCompressedVoice( void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten ) = 0;
	CLASS_PROXY(int32, GetCompressedVoice, ( void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten ), (pDestBuffer, cbDestBufferSize, nBytesWritten))

	// Decompresses a chunk of data produced by GetCompressedVoice(). nBytesWritten is set to the 
	// number of bytes written to pDestBuffer. The output format of the data is 16-bit signed at 
	// 11025 samples per second.
	//CLASS_PROXY(EVoiceResult DecompressVoice( void *pCompressed, uint32 cbCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten ) = 0;
	CLASS_PROXY(int32, DecompressVoice, ( void *pCompressed, uint32 cbCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten ), (pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten))


	CLASS_PROXY(bool, IsAnyGameRunning, (), ())

	/*DECL_CLASS_PROXY(unknown_ret, ChangePassword,( const char *a, const char *b ))
		::Log("CClientUser::ChangePassword( a = \"%s\" (%d), b = \"%s\" (%d) )\n", a, (int)a, b, (int)b);
	RETURN_CLASS_PROXY(ChangePassword, (a, b))*/

	CLASS_PROXY(void, ChangeEmail,( const char *a, const char *b ), (a, b))
	CLASS_PROXY(void, ChangeSecretQuestionAndAnswer,( const char *a, int b, const char *c, const char *d ), (a, b, c, d))

	CLASS_PROXY(void, SetSteam2FullASTicket, ( unsigned char *a, int b ), (a, b))

	CLASS_PROXY(bool, GetEmail, ( char *a, int b ), (a, b))

	CLASS_PROXY(void, ResetPasswordInformSteam3, ( const char *a, const char *b, const char *c, const char *d ), (a, b, c, d))

	CLASS_PROXY(void, RequestForgottenPasswordEmail, ( const char *a, const char *b ), (a, b))

	CLASS_PROXY(void, CreateAccountInformSteam3, ( const char *a, const char *b, const char *c, int d, const char *e, const char *f ), (a, b, c, d, e, f))

	CLASS_PROXY(void, Test_FakeConnectionTimeout, (), ())

	CLASS_PROXY(unknown_ret, RunInstallScript,( uint32 *a, int b, const char *c, const char *d, bool e ), (a, b, c, d, e))

	CLASS_PROXY(AppId_t, IsInstallScriptRunning, (), ())

	CLASS_PROXY(unknown_ret, GetInstallScriptString,( uint32 a, const char *b, const char *c, const char *d, const char *e, char *f, int g ), (a, b, c, d, e, f, g))
	CLASS_PROXY(unknown_ret, GetInstallScriptState,( char *a, uint32 b, uint32 *c, uint32 *d ), (a, b, c, d)) 

	CLASS_PROXY(unknown_ret, SpawnProcess,( void *a, uint32 b, const char *c, const char *d, uint32 e, const char *f, uint32 g, const char *h, bool i ), (a, b, c, d, e, f, g, h, i))

	CLASS_PROXY(unknown_ret, GetAppOwnershipTicketLength, (uint32 a), (a))
	CLASS_PROXY(unknown_ret, GetAppOwnershipTicketData,( uint32 a, void *b, uint32 c), (a, b, c))

	CLASS_PROXY(unknown_ret, GetAppDecryptionKey, ( uint32 a, void *b, uint32 c ), (a, b, c))

	CLASS_PROXY(int, GetMarketingMessageCount, (), ())
	CLASS_PROXY(unknown_ret, GetMarketingMessage, ( int a, uint64 *b, char *c, int d), (a, b, c, d))

	// Retrieve ticket to be sent to the entity who wishes to authenticate you. 
	// pcbTicket retrieves the length of the actual ticket.
	CLASS_PROXY(HAuthTicket, GetAuthSessionTicket, ( void *pTicket, int cbMaxTicket, uint32 *pcbTicket ), (pTicket, cbMaxTicket, pcbTicket))

	// Authenticate ticket from entity steamID to be sure it is valid and isnt reused
	// Registers for callbacks if the entity goes offline or cancels the ticket ( see ValidateAuthTicketResponse_t callback and EAuthSessionResponse )
	CLASS_PROXY(int32, BeginAuthSession,( const void *pAuthTicket, int cbAuthTicket, CSteamID steamID ), (pAuthTicket, cbAuthTicket, steamID))

	// Stop tracking started by BeginAuthSession - called when no longer playing game with this entity
	CLASS_PROXY(void, EndAuthSession, (CSteamID steamID), (steamID))

	// Cancel auth ticket from GetAuthSessionTicket, called when no longer playing game with the entity you gave the ticket to
	CLASS_PROXY(void, CancelAuthTicket, (HAuthTicket hAuthTicket), (hAuthTicket))

	CLASS_PROXY(int, IsUserSubscribedAppInTicket, ( CSteamID a, uint32 b ), (a, b))

	CLASS_PROXY(void, SetAccountLimited, (bool bLimited), (bLimited))
	CLASS_PROXY(bool, BIsAccountLimited, (), ())
};