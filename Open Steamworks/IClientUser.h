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

#ifndef ICLIENTUSER_H
#define ICLIENTUSER_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "UserCommon.h"
#include "ContentServerCommon.h"


abstract_class UNSAFE_INTERFACE IClientUser
{
public:
	virtual HSteamUser GetHSteamUser() = 0;

	virtual void LogOn( bool bUnk1, CSteamID steamID ) = 0;
	virtual void LogOnWithPassword( bool bUnk1, const char * pchLogin, const char * pchPassword ) = 0;
	virtual void LogOnAndCreateNewSteamAccountIfNeeded( bool bUnk1 ) = 0;
	virtual void LogOff() = 0;
	virtual bool BLoggedOn() = 0;
	virtual ELogonState GetLogonState() = 0;
	virtual bool BConnected() = 0;
	virtual bool BTryingToLogin() = 0;

	virtual CSteamID GetSteamID() = 0;
	virtual CSteamID GetConsoleSteamID() = 0;

	virtual bool IsVACBanned( AppId_t nGameID ) = 0;
	virtual bool RequireShowVACBannedMessage( AppId_t nAppID ) = 0;
	virtual void AcknowledgeVACBanning( AppId_t nAppID ) = 0;

	virtual void SetSteam2Ticket( uint8* pubTicket, int cubTicket ) = 0;
	
	virtual bool BExistsSteam2Ticket() = 0;

	virtual bool SetEmail( const char *pchEmail ) = 0;

	virtual bool SetConfigString( ERegistrySubTree eRegistrySubTree, const char *pchKey, const char *pchValue ) = 0;
	virtual bool GetConfigString( ERegistrySubTree eRegistrySubTree, const char *pchKey, char *pchValue, int cbValue ) = 0;
	virtual bool SetConfigInt( ERegistrySubTree eRegistrySubTree, const char *pchKey, int iValue ) = 0;
	virtual bool GetConfigInt( ERegistrySubTree eRegistrySubTree, const char *pchKey, int *pValue ) = 0;

	virtual bool GetConfigStoreKeyName( ERegistrySubTree eRegistrySubTree, const char *pchKey, char *pchStoreName, int cbStoreName ) = 0;

	virtual int InitiateGameConnection( void *pOutputBlob, int cbBlobMax, CSteamID steamIDGS, CGameID gameID, uint32 unIPServer, uint16 usPortServer, bool bSecure ) = 0;
	virtual int InitiateGameConnectionOld( void *pOutputBlob, int cbBlobMax, CSteamID steamIDGS, CGameID gameID, uint32 unIPServer, uint16 usPortServer, bool bSecure, void *pvSteam2GetEncryptionKey, int cbSteam2GetEncryptionKey ) = 0;

	virtual void TerminateGameConnection( uint32 unIPServer, uint16 usPortServer ) = 0;

	virtual void SetSelfAsPrimaryChatDestination() = 0;
	virtual bool IsPrimaryChatDestination() = 0;

	virtual void RequestLegacyCDKey( AppId_t iAppID ) = 0;

	virtual bool SendGuestPassByEmail( const char *pchEmailAccount, GID_t gidGuestPassID, bool bResending ) = 0;
	virtual bool SendGuestPassByAccountID( uint32 uAccountID, GID_t gidGuestPassID, bool bResending ) = 0;

	virtual bool AckGuestPass( const char *pchGuestPassCode ) = 0;
	virtual bool RedeemGuestPass( const char *pchGuestPassCode ) = 0;

	virtual uint32 GetGuestPassToGiveCount() = 0;
	virtual uint32 GetGuestPassToRedeemCount() = 0;
	virtual uint32 GetGuestPassLastUpdateTime() = 0;

	virtual bool GetGuestPassToGiveInfo( uint32 nPassIndex, GID_t *pgidGuestPassID, PackageId_t* pnPackageID, RTime32* pRTime32Created, RTime32* pRTime32Expiration, RTime32* pRTime32Sent, RTime32* pRTime32Redeemed, char* pchRecipientAddress, int cRecipientAddressSize ) = 0;
	virtual bool GetGuestPassToRedeemInfo( uint32 nPassIndex, GID_t *pgidGuestPassID, PackageId_t* pnPackageID, RTime32* pRTime32Created, RTime32* pRTime32Expiration, RTime32* pRTime32Sent, RTime32* pRTime32Redeemed ) = 0;
	virtual bool GetGuestPassToRedeemSenderAddress( uint32 nPassIndex, char* pchSenderAddress, int cSenderAddressSize ) = 0;
	virtual bool GetGuestPassToRedeemSenderName( uint32 nPassIndex, char* pchSenderName, int cSenderNameSize ) = 0;

	virtual bool RequestGuestPassTargetList( GID_t gidGuestPassID ) = 0;

	virtual bool RequestGiftTargetList( PackageId_t nPackageID ) = 0;

	virtual void AcknowledgeMessageByGID( const char *pchMessageGID ) = 0;

	virtual bool SetLanguage( const char *pchLanguage ) = 0;

	virtual void TrackAppUsageEvent( CGameID gameID, int eAppUsageEvent, const char *pchExtraInfo = "" ) = 0;

	virtual int RaiseConnectionPriority( EConnectionPriority eConnectionPriority ) = 0;
	virtual void ResetConnectionPriority( int hRaiseConnectionPriorityPrev ) = 0;

	virtual void SetAccountNameFromSteam2( const char *pchAccountName ) = 0;
	virtual void SetPasswordFromSteam2( const char *pchPassword ) = 0;

	virtual void SetAccountNameForCachedCredentialLogin( const char *pchAccountName, bool bRememberPassword, bool bUnk ) = 0;
	virtual void SetLoginInformation( const char *pchAccountName, const char *pchPassword, bool bRememberPassword ) = 0;

	virtual void SetAccountCreationTime( RTime32 rtime32Time ) = 0;
	virtual bool DoesTextContainUserPassword( const char *pchText ) = 0;

	virtual OBSOLETE_FUNCTION uint32 obselete_GetCMIPAddress() = 0;
	virtual OBSOLETE_FUNCTION uint32 obselete_GetP2PRelayIPAddress() = 0;

	virtual SteamAPICall_t RequestWebAuthToken( void ) = 0;
	virtual bool GetLanguage( char* pchLanguage, int cbLanguage ) = 0;
	virtual void SetCyberCafe( bool bCyberCafe ) = 0;

	virtual void CreateAccount( const char *pchAccountName, const char *pchNewPassword, const char *pchNewEmail, int iQuestion, const char *pchNewQuestion, const char *pchNewAnswer ) = 0;

	virtual void ResetPassword( const char *pchAccountName, const char *pchOldPassword, const char *pchNewPassword, const char *pchValidationCode, const char *pchAnswer ) = 0;


	virtual void TrackNatTraversalStat( const CNatTraversalStat *pNatStat ) = 0;

	virtual void RefreshSteam2Login() = 0;
	virtual void RefreshSteam2LoginWithSecureOption( bool bIsSecure ) = 0;
	virtual bool Steam2IsSecureComputer() = 0;

	virtual PackageId_t GetPackageIDForGuestPassToRedeemByGID( GID_t gid ) = 0;

	virtual void TrackSteamUsageEvent( ESteamUsageEvent eSteamUsageEvent, const uint8 *pubKV, uint32 cubKV ) = 0;
	virtual void TrackSteamGUIUsage( const char * ) = 0;

	virtual void SetComputerInUse() = 0;

	virtual bool BIsGameRunning( CGameID gameID ) = 0;


	virtual uint64 GetCurrentSessionToken() = 0;

	virtual bool BUpdateAppOwnershipTicket( AppId_t nAppID, bool bOnlyUpdateIfStale, bool unk ) = 0;

	virtual bool RequestCustomBinary( const char *pszAbsolutePath, AppId_t nAppID, bool bForceUpdate, bool bAppLaunchRequest ) = 0;
	virtual bool GetCustomBinariesState( AppId_t unAppID, uint32 *punProgress ) = 0;

	virtual void SetCellID( CellID_t cellID ) = 0;

	virtual const char *GetUserBaseFolder() = 0;

	virtual bool GetUserDataFolder( CGameID gameID, char* pchBuffer, int cubBuffer ) = 0;
	virtual bool GetUserConfigFolder( char *pchBuffer, int cubBuffer ) = 0;

	virtual bool GetAccountName( char* pchAccountName, uint32 cb ) = 0;

	virtual void RequiresLegacyCDKey( uint32 ) = 0;
	virtual bool GetLegacyCDKey( AppId_t nAppID, char* pchKeyData, int cbKeyData ) = 0;
	virtual bool HasLegacyCDKey( AppId_t nAppID ) = 0;
	virtual bool SetLegacyCDKey( AppId_t nAppID, const char* pchKeyData ) = 0;
	virtual void RemoveLegacyCDKey( AppId_t nAppID ) = 0;

	virtual bool BIsAnyGameRunning() = 0;

	virtual void ChangePassword( const char *pchOldPassword, const char *pchNewPassword ) = 0;
	virtual void ChangeEmail( const char *, const char *pchEmail ) = 0;
	virtual void ChangeSecretQuestionAndAnswer( const char *, int iQuestion, const char *pchNewQuestion, const char *pchNewAnswer ) = 0;

	virtual void SetSteam2FullASTicket( uint8* pubTicket, int cubTicket ) = 0;
	virtual uint32 GetSteam2FullASTicket( uint8* pubTicket, int32 cubTicket ) = 0;

	virtual bool GetEmail( char* pchEmail, int cchEmail, bool* pbUnk ) = 0;

	virtual void RequestForgottenPasswordEmail( const char *pchAccountName, const char *pchTriedPassword ) = 0;
	
	virtual void FindAccountsByEmailAddress( const char *pchEmailAddress ) = 0; // UI Callback 161
	virtual void FindAccountsByCdKey( const char *pchCdKey ) = 0; // ???
	virtual void GetNumAccountsWithEmailAddress( const char * pchEmailAddress ) = 0; // UI Callback 159
	virtual void IsAccountNameInUse( const char * pchAccountName ) = 0; // UI Callback 160

	virtual void Test_FakeConnectionTimeout() = 0;

	virtual bool RunInstallScript( AppId_t *pAppIDs, int cAppIDs, const char *pchInstallPath, const char *pchLanguage, bool bUninstall ) = 0;

	virtual AppId_t IsInstallScriptRunning() = 0;

	virtual bool GetInstallScriptString( AppId_t nAppID, const char *pchInstallPath, const char *pchLanguage, const char *pchKeyname, const char *pchKeyvalue, char* pchValue, int cchValue ) = 0;
	virtual bool GetInstallScriptState( char* pchDescription, uint32 cchDescription, uint32* punNumSteps, uint32* punCurrStep ) = 0;
//TODO
	virtual bool SpawnProcess( void *lpVACBlob, uint32 cbBlobSize, const char *lpApplicationName, const char *lpCommandLine, uint32 dwCreationFlags, const char *lpCurrentDirectory, AppId_t nAppID, const char *pchGameName, bool bAlwaysUseShellExec ) = 0;
	
	virtual uint32 GetAppOwnershipTicketLength( uint32 nAppID ) = 0;
	virtual uint32 GetAppOwnershipTicketData( uint32 nAppID, void *pvBuffer, uint32 cbBufferLength ) = 0;

	virtual uint32 GetAppOwnershipTicketExtendedData( uint32 nAppID, void *pvBuffer, uint32 cbBufferLength, uint32*, uint32*, uint32* ticket_length, uint32* signature_length ) = 0;

	virtual bool GetAppDecryptionKey( uint32 nAppID, void *pvBuffer, uint32 cbBufferLength ) = 0;

	virtual int GetMarketingMessageCount() = 0;
	virtual bool GetMarketingMessage( int cMarketingMessage, GID_t* gidMarketingMessageID, char* pubMsgUrl, int cubMessageUrl, EMarketingMessageFlags *eMarketingMssageFlags ) = 0;

	virtual HAuthTicket GetAuthSessionTicket( void *pMyAuthTicket, int cbMaxMyAuthTicket, uint32* pcbAuthTicket ) = 0;

	virtual EBeginAuthSessionResult BeginAuthSession( void const* pTheirAuthTicket, int cbTicket, CSteamID steamID ) = 0;
	virtual void EndAuthSession( CSteamID steamID ) = 0;

	virtual void CancelAuthTicket( HAuthTicket hAuthTicket ) = 0;

	virtual int IsUserSubscribedAppInTicket( CSteamID steamID, AppId_t appID ) = 0;

	virtual bool AdvertiseGame( CGameID gameID, CSteamID steamIDGameServer, uint32 unIPServer , uint16 usPortServer ) = 0;

	virtual SteamAPICall_t RequestEncryptedAppTicket( const void *pUserData, int cbUserData ) = 0;
	virtual bool GetEncryptedAppTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket ) = 0;

	virtual void SetAccountLimited( bool bAccountLimited ) = 0;
	virtual bool BIsAccountLimited() = 0;

	virtual void SendValidationEmail() = 0;
	virtual bool BGameConnectTokensAvailable() = 0;

	virtual int NumGamesRunning() = 0;
	virtual CGameID GetRunningGameID( int iGame ) = 0;

	virtual uint32 GetAccountSecurityPolicyFlags() = 0;

	virtual void RequestChangeEmail( const char *pchPassword, int eRequestType ) = 0;
	virtual void ChangePasswordWithCode( const char *pchOldPassword, const char *pchCode, const char *pchNewPassword ) = 0;
	virtual void ChangeEmailWithCode( const char *pchPassword, const char *pchCode, const char *pchEmail, bool bUnk ) = 0;
	virtual void ChangeSecretQuestionAndAnswerWithCode( const char *pchPassword, const char *pchCode, const char *pchNewQuestion, const char *pchNewAnswer ) = 0;

	virtual void SetClientStat( EClientStat eStat, int64 llValue, AppId_t nAppID, DepotId_t nDepotID, CellID_t nCellID ) = 0;

	virtual void VerifyPassword( const char *pchPassword ) = 0;

	virtual bool BSupportUser() = 0;

	virtual bool BIsAppOverlayEnabled( uint32 ) = 0;

	virtual bool BIsBehindNAT() = 0;

	virtual AppId_t GetMicroTxnAppID( uint64 ) = 0;
	virtual uint64 GetMicroTxnOrderID( uint64 ) = 0;

	//virtual bool BGetMicroTxnPrice( uint64, CAmount *, CAmount *, bool * ) = 0;
	virtual bool BGetMicroTxnPrice( uint64, int *, int *, bool * ) = 0;

	virtual int32 GetMicroTxnLineItemCount( uint64 ) = 0;

	//virtual bool BGetMicroTxnLineItem( uint64, uint32, CAmount *, uint32 *, char *, uint32 ) = 0;
	virtual bool BGetMicroTxnLineItem( uint64, uint32, int *, uint32 *, char *, uint32 ) = 0;

	virtual bool BIsSandboxMicroTxn( uint64, bool* pbUnk ) = 0;

	//virtual unknown_ret AuthorizeMicroTxn( uint64, EMicroTxnAuthResponse ) = 0;
	virtual SteamAPICall_t AuthorizeMicroTxn( uint64, int ) = 0;

	virtual void NotifyAppMicroTxnAuthResponse( uint32, uint64, bool ) = 0;

	//virtual bool BGetWalletBalance( bool *, CAmount * ) = 0;
	virtual bool BGetWalletBalance( bool *, int * ) = 0;

	virtual SteamAPICall_t RequestMicroTxnInfo( uint64 ) = 0;

	virtual bool BGetAppMinutesPlayed( uint32, int *, int * ) = 0;

	virtual bool BGetGuideURL( uint32, char *, uint32 ) = 0;

	virtual void GetClientAppListResponse_AddApp( unsigned int, bool,bool, bool, char  const*, unsigned long long, unsigned long long, unsigned int ) = 0;
	virtual void GetClientAppListResponse_AddDLC( unsigned int, bool ) = 0;
	virtual void GetClientAppListResponse_Done( unsigned long long ) = 0;
	virtual void PostUIResultToClientJob( unsigned long long, EResult ) = 0;

	virtual bool BPromptToVerifyEmail() = 0;
	virtual bool BPromptToChangePassword() = 0;
	virtual bool BAccountLocked() = 0;
	virtual bool BAccountShouldShowLockUI() = 0;
	virtual bool BAccountLockedByIPT() = 0;
	virtual int32 GetCountAuthedComputers() = 0;
	virtual bool BAccountCanUseIPT() = 0;
	virtual void ChangeTwoFactorAuthOptions( uint32 uOption ) = 0;
	virtual void Set2ndFactorAuthCode( const char* pchAuthCode ) = 0;
	virtual bool BAccountHasIPTConfig() = 0;

	virtual bool GetEmailDomainFromLogonFailure( char * pchEmailDomain, int cbEmailDomain ) = 0;
	
	virtual bool BIsSubscribedApp( AppId_t nAppId ) = 0;
	virtual SteamAPICall_t RegisterActivationCode( const char * pchActivationCode ) = 0;
	
	virtual void OptionalDLCInstallation( AppId_t, bool ) = 0;

	virtual void AckSystemIM(unsigned long long) = 0;
};

#endif // ICLIENTUSER_H
