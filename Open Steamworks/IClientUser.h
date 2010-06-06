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

class CNatTraversalStat;

#define CLIENTUSER_INTERFACE_VERSION "CLIENTUSER_INTERFACE_VERSION001"

class UNSAFE_INTERFACE IClientUser
{
public:
	virtual HSteamUser GetHSteamUser() = 0;

	virtual void LogOn( CSteamID steamID ) = 0;
	virtual void LogOff() = 0;
	virtual bool LoggedOn() = 0;
	virtual ELogonState GetLogonState() = 0;
	virtual bool Connected() = 0;
	virtual CSteamID GetSteamID() = 0;

	virtual bool IsVACBanned( AppId_t nGameID ) = 0;
	virtual bool RequireShowVACBannedMessage( AppId_t nAppID ) = 0;
	virtual void AcknowledgeVACBanning( AppId_t nAppID ) = 0;

	virtual void SetSteam2Ticket( uint8* pubTicket, int cubTicket ) = 0;


	virtual bool SetEmail( const char* pchEmail ) = 0;
	virtual bool SetConfigString( ERegistrySubTree eRegistrySubTree, const char* pchKey, const char* pchValue ) = 0;
	virtual bool GetConfigString( ERegistrySubTree eRegistrySubTree, const char* pchKey, char* pchValue, int cbValue ) = 0;
	virtual bool SetConfigInt( ERegistrySubTree eRegistrySubTree, const char* pchKey, int iValue ) = 0;
	virtual bool GetConfigInt( ERegistrySubTree eRegistrySubTree, const char* pchKey, int* pValue ) = 0;
	virtual bool GetConfigStoreKeyName( ERegistrySubTree eRegistrySubTree, char  const *a, char *b, int c ) = 0;

	virtual int InitiateGameConnection( void* pOutputBlob, int cbBlobMax, CSteamID steamIDGS, CGameID gameID, uint32 unIPServer, uint16 usPortServer, bool bSecure ) = 0;
	virtual int InitiateGameConnectionOld( void* pOutputBlob, int cbBlobMax, CSteamID steamIDGS, CGameID gameID, uint32 unIPServer, uint16 usPortServer, bool bSecure, void* pvSteam2GetEncryptionKey, int cbSteam2GetEncryptionKey ) = 0;

	virtual void TerminateGameConnection( uint32 unIPServer, uint16 usPortServer ) = 0;

	virtual void SetSelfAsPrimaryChatDestination() = 0;
	virtual bool IsPrimaryChatDestination() = 0;

	virtual void RequestLegacyCDKey( AppId_t iAppID ) = 0;

	virtual bool SendGuestPassByEmail( const char* pchEmailAccount, GID_t gidGuestPassID, bool bResending ) = 0;
	virtual bool SendGuestPassByAccountID( uint32 uAccountID, GID_t gidGuestPassID, bool bResending ) = 0;

	virtual bool AckGuestPass( const char* pchGuestPassCode ) = 0;
	virtual bool RedeemGuestPass( const char* pchGuestPassCode ) = 0;

	virtual uint32 GetGuestPassToGiveCount() = 0;
	virtual uint32 GetGuestPassToRedeemCount() = 0;
	virtual uint32 GetGuestPassLastUpdateTime() = 0;

	virtual bool GetGuestPassToGiveInfo( uint32 nPassIndex, GID_t* pgidGuestPassID, PackageId_t* pnPackageID, RTime32* pRTime32Created, RTime32* pRTime32Expiration, RTime32* pRTime32Sent, RTime32* pRTime32Redeemed, char* pchRecipientAddress, int cRecipientAddressSize ) = 0;
	virtual bool GetGuestPassToRedeemInfo( uint32 nPassIndex, GID_t* pgidGuestPassID, PackageId_t* pnPackageID, RTime32* pRTime32Created, RTime32* pRTime32Expiration, RTime32* pRTime32Sent, RTime32* pRTime32Redeemed ) = 0;
	virtual bool GetGuestPassToRedeemSenderAddress( uint32 nPassIndex, char* pchSenderAddress, int cSenderAddressSize ) = 0;
	virtual bool GetGuestPassToRedeemSenderName( uint32 nPassIndex, char* pchSenderName, int cSenderNameSize ) = 0;

	virtual bool RequestGuestPassTargetList( GID_t gidGuestPassID ) = 0;

	virtual bool RequestGiftTargetList( PackageId_t nPackageID ) = 0;

	virtual void AcknowledgeMessageByGID( const char* pchMessageGID ) = 0;

	virtual bool SetLanguage( const char* pchLanguage ) = 0;

	virtual void TrackAppUsageEvent( CGameID gameID, int eAppUsageEvent, const char* pchExtraInfo = "" ) = 0;

	virtual int RaiseConnectionPriority( EConnectionPriority eConnectionPriority ) = 0;
	virtual void ResetConnectionPriority( int hRaiseConnectionPriorityPrev ) = 0;

	virtual void SetAccountNameFromSteam2( const char* pchAccountName ) = 0;
	virtual void SetPasswordFromSteam2( const char* pchPassword ) = 0;

	virtual void SetAccountNameForCachedCredentialLogin( const char*, bool ) = 0;
	virtual void SetLoginInformation( const char *szUserName, const char *szPassword, bool bUnknown ) = 0;

	virtual void SetAccountCreationTime( RTime32 rtime32Time ) = 0;
	virtual bool DoesTextContainUserPassword( const char* pchText ) = 0;

	virtual uint32 obselete_GetCMIPAddress() = 0;
	virtual uint32 obselete_GetP2PRelayIPAddress() = 0;

	virtual SteamAPICall_t RequestWebAuthToken( void ) = 0;
	virtual bool GetLanguage( char* pchLanguage, int cbLanguage ) = 0;
	virtual void SetCyberCafe( bool bCyberCafe ) = 0;

	virtual void CreateAccount( const char* pchAccountName, const char* pchNewPassword, const char* pchNewEmail, int iQuestion, const char* pchNewQuestion, const char* pchNewAnswer ) = 0;

	virtual void CheckPassword( const char* pchAccountName, const char* pchPassword, bool bAttemptRecovery ) = 0;
	virtual void ResetPassword( const char* pchAccountName, const char* pchOldPassword, const char* pchNewPassword, const char* pchValidationCode, const char* pchAnswer ) = 0;



	virtual void TrackNatTraversalStat( CNatTraversalStat const* pNatStat ) = 0;

	virtual void RefreshSteam2Login() = 0;
	virtual void RefreshSteam2LoginWithSecureOption( bool ) = 0;
	virtual bool Steam2IsSecureComputer() = 0;

	virtual PackageId_t GetPackageIDForGuestPassToRedeemByGID( GID_t gid ) = 0;

	virtual void TrackSteamUsageEvent( ESteamUsageEvent eSteamUsageEvent, byte const* pubKV, uint32 cubKV ) = 0;
	virtual void TrackSteamGUIUsage( const char* ) = 0;

	virtual void SetComputerInUse() = 0;

	virtual bool IsGameRunning( CGameID gameID ) = 0;


	virtual uint64 GetCurrentSessionToken() = 0;

	virtual bool UpdateAppOwnershipTicket( AppId_t nAppID, bool bOnlyUpdateIfStale ) = 0;

	virtual bool RequestCustomBinary( const char* pszAbsolutePath, AppId_t nAppID, bool ) = 0;
	virtual bool GetCustomBinariesState( AppId_t unAppID, uint32* ) = 0;

	virtual void SetCellID( CellID_t cellID ) = 0;

	virtual bool GetUserBaseFolder( void ) = 0;

	virtual bool GetUserDataFolder( CGameID gameID, char* pchBuffer, int cubBuffer ) = 0;
	virtual bool GetUserConfigFolder( char *, int ) = 0;

	virtual bool GetAccountName( char* pchAccountName, uint32 cb ) = 0;

	virtual void RequiresLegacyCDKey( uint32 ) = 0;
	virtual bool GetLegacyCDKey( AppId_t nAppID, char* pchKeyData, int cbKeyData ) = 0;
	virtual bool HasLegacyCDKey( AppId_t nAppID ) = 0;
	virtual void RemoveLegacyCDKey( AppId_t nAppID ) = 0;

	virtual void StartVoiceRecording() = 0;
	virtual void StopVoiceRecording() = 0;
	virtual void ResetVoiceRecording() = 0;

	virtual void GetAvailableVoice( uint32 *, uint32 * ) = 0;
	virtual void GetVoice( bool, void *, uint32, uint32 *, bool, void *, uint32, uint32 * ) = 0;

	virtual EVoiceResult GetCompressedVoice( void* pDestBuffer, uint32 cbDestBufferSize, uint32* nBytesWritten ) = 0;
	virtual EVoiceResult DecompressVoice( void* pCompressed, uint32 cbCompressed, void* pDestBuffer, uint32 cbDestBufferSize, uint32* nBytesWritten ) = 0;

	virtual bool IsAnyGameRunning() = 0;

	virtual void ChangePassword( const char* pchOldPassword, const char* pchNewPassword ) = 0;
	virtual void ChangeEmail( const char*, const char* pchEmail ) = 0;
	virtual void ChangeSecretQuestionAndAnswer( const char*, int iQuestion, const char* pchNewQuestion, const char* pchNewAnswer ) = 0;

	virtual void SetSteam2FullASTicket( uint8* pubTicket, int cubTicket ) = 0;

	virtual bool GetEmail( char* pchEmail, int cchEmail ) = 0;

	virtual void RequestForgottenPasswordEmail( const char* pchAccountName, const char* pchTriedPassword ) = 0;

	//virtual void ResetPasswordInformSteam3( const char* pchAccountName, const char* pchNewPassword, const char* pchValidationCode, const char* pchAnswer ) = 0;
	//virtual void CreateAccountInformSteam3( const char* pchAccountName, const char* pchNewPassword, const char* pchNewEmail, int iQuestion, const char* pchNewQuestion, const char* pchNewAnswer ) = 0;
	
	virtual void Test_FakeConnectionTimeout() = 0;

	virtual bool RunInstallScript( uint32*, AppId_t nAppID, const char* pchInstallPath, const char* pchLanguage, bool bUninstall ) = 0;

	virtual AppId_t IsInstallScriptRunning() = 0;

	virtual bool GetInstallScriptString( AppId_t nAppID, const char* pchInstallPath, const char* pchLanguage, const char* pchKeyname, const char* pchKeyvalue, char* pchValue, int cchValue ) = 0;
	virtual bool GetInstallScriptState( char* pchDescription, uint32 cchDescription, uint32* punNumSteps, uint32* punCurrStep ) = 0;

	virtual bool SpawnProcess( void* lpVACBlob, uint32 cbBlobSize, const char* lpApplicationName, const char* lpCommandLine, uint32 dwCreationFlags, const char* lpCurrentDirectory, AppId_t nAppID, const char* pchGameName, bool bAlwaysUseShellExec ) = 0;
	
	virtual uint32 GetAppOwnershipTicketLength( uint32 nAppID ) = 0;
	virtual uint32 GetAppOwnershipTicketData( uint32 nAppID, void* pvBuffer, uint32 cbBufferLength ) = 0;

	virtual bool GetAppDecryptionKey( uint32 nAppID, void* pvBuffer, uint32 cbBufferLength ) = 0;

	virtual int GetMarketingMessageCount() = 0;
	virtual bool GetMarketingMessage( int cMarketingMessage, uint64* gidMarketingMessageID, char* pubMsgUrl, int cubMessageUrl, EMarketingMessageFlags * ) = 0;

	virtual HAuthTicket GetAuthSessionTicket( void* pMyAuthTicket, int cbMaxMyAuthTicket, uint32* pcbAuthTicket ) = 0;

	virtual EBeginAuthSessionResult BeginAuthSession( void const* pTheirAuthTicket, int cbTicket, CSteamID steamID ) = 0;
	virtual void EndAuthSession( CSteamID steamID ) = 0;

	virtual void CancelAuthTicket( HAuthTicket hAuthTicket ) = 0;

	virtual int IsUserSubscribedAppInTicket( CSteamID, uint32 ) = 0;

	virtual void SetAccountLimited( bool ) = 0;
	virtual bool BIsAccountLimited() = 0;

	virtual unknown_ret SendValidationEmail( void ) = 0;
	virtual bool BGameConnectTokensAvailable( void ) = 0;

	virtual int NumGamesRunning( void ) = 0;
	virtual CGameID GetRunningGameID( int ) = 0;

	virtual unknown_ret GetAccountSecurityPolicyFlags( void ) = 0;

	virtual unknown_ret RequestChangeEmail( const char*, int ) = 0;
	virtual unknown_ret ChangePasswordWithCode( const char*, const char*, const char* ) = 0;
	virtual unknown_ret ChangeEmailWithCode( const char*, const char*, const char* ) = 0;
	virtual unknown_ret ChangeSecretQuestionAndAnswerWithCode( const char*, const char*, const char*, const char* ) = 0;

	virtual unknown_ret SetClientStat( EClientStat eClientStat, int64, uint32, uint32, uint32 ) = 0;

	virtual unknown_ret VerifyPassword( const char* ) = 0;

	virtual bool BSupportUser( void ) = 0;

	virtual bool BIsAppOverlayEnabled( uint32 ) = 0;

	virtual unknown_ret GetMicroTxnAppID( uint64 ) = 0;
	virtual unknown_ret GetMicroTxnOrderID( uint64 ) = 0;

	//virtual bool BGetMicroTxnPrice( uint64, CAmount *, CAmount *, bool * ) = 0;
	virtual bool BGetMicroTxnPrice( uint64, int *, int *, bool * ) = 0;

	virtual unknown_ret GetMicroTxnLineItemCount( uint64 ) = 0;

	//virtual bool BGetMicroTxnLineItem( uint64, uint32, CAmount *, uint32 *, char *, uint32 ) = 0;
	virtual bool BGetMicroTxnLineItem( uint64, uint32, int *, uint32 *, char *, uint32 ) = 0;

	//virtual unknown_ret AuthorizeMicroTxn( uint64, EMicroTxnAuthResponse ) = 0;
	virtual unknown_ret AuthorizeMicroTxn( uint64, int ) = 0;

	virtual unknown_ret NotifyAppMicroTxnAuthResponse( uint32, uint64, bool ) = 0;

	//virtual bool BGetWalletBalance( bool *, CAmount * ) = 0;
	virtual bool BGetWalletBalance( bool *, int * ) = 0;

	virtual unknown_ret RequestMicroTxnInfo( uint64 ) = 0;

	virtual bool BGetAppMinutesPlayed( uint32, int *, int * ) = 0;

	virtual bool BGetGuideURL( uint32, char *, uint32 ) = 0;
};

#endif // ICLIENTUSER_H
