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
	virtual HSteamUser GetHSteamUser();

	virtual void LogOn(CSteamID steamID);
	virtual void LogOff();
	virtual bool LoggedOn();
	virtual ELogonState GetLogonState();
	virtual bool Connected();
	virtual CSteamID GetSteamID();

	virtual bool IsVACBanned(AppId_t nGameID);
	virtual bool RequireShowVACBannedMessage(AppId_t nAppID);
	virtual void AcknowledgeVACBanning(AppId_t nAppID);

	virtual void SetSteam2Ticket(uint8* pubTicket, int cubTicket);


	virtual bool SetEmail(char const* pchEmail);
	virtual bool SetConfigString(ERegistrySubTree eRegistrySubTree, char const* pchKey, char const* pchValue);
	virtual bool GetConfigString(ERegistrySubTree eRegistrySubTree, char const* pchKey, char* pchValue, int cbValue);
	virtual bool SetConfigInt(ERegistrySubTree eRegistrySubTree, char const* pchKey, int iValue);
	virtual bool GetConfigInt(ERegistrySubTree eRegistrySubTree, char const* pchKey, int* pValue);
	virtual bool GetConfigStoreKeyName(ERegistrySubTree,char  const*,char *,int);

	virtual int InitiateGameConnection(void* pOutputBlob, int cbBlobMax, CSteamID steamIDGS, CGameID gameID, uint32 unIPServer, uint16 usPortServer, bool bSecure);
	virtual int InitiateGameConnectionOld(void* pOutputBlob, int cbBlobMax, CSteamID steamIDGS, CGameID gameID, uint32 unIPServer, uint16 usPortServer, bool bSecure, void* pvSteam2GetEncryptionKey, int cbSteam2GetEncryptionKey);

	virtual void TerminateGameConnection(uint32 unIPServer, uint16 usPortServer);

	virtual void SetSelfAsPrimaryChatDestination();
	virtual bool IsPrimaryChatDestination();

	virtual void RequestLegacyCDKey(AppId_t iAppID);

	virtual bool SendGuestPassByEmail(char const* pchEmailAccount, GID_t gidGuestPassID, bool bResending);
	virtual bool SendGuestPassByAccountID(uint32 uAccountID, GID_t gidGuestPassID, bool bResending);

	virtual bool AckGuestPass(char const* pchGuestPassCode);
	virtual bool RedeemGuestPass(char const* pchGuestPassCode);

	virtual uint32 GetGuestPassToGiveCount();
	virtual uint32 GetGuestPassToRedeemCount();
	virtual uint32 GetGuestPassLastUpdateTime();

	virtual bool GetGuestPassToGiveInfo(uint32 nPassIndex, GID_t* pgidGuestPassID, PackageId_t* pnPackageID, RTime32* pRTime32Created, RTime32* pRTime32Expiration, RTime32* pRTime32Sent, RTime32* pRTime32Redeemed, char* pchRecipientAddress, int cRecipientAddressSize);
	virtual bool GetGuestPassToRedeemInfo(uint32 nPassIndex, GID_t* pgidGuestPassID, PackageId_t* pnPackageID, RTime32* pRTime32Created, RTime32* pRTime32Expiration, RTime32* pRTime32Sent, RTime32* pRTime32Redeemed);
	virtual bool GetGuestPassToRedeemSenderAddress(uint32 nPassIndex, char* pchSenderAddress, int cSenderAddressSize);
	virtual bool GetGuestPassToRedeemSenderName(uint32 nPassIndex, char* pchSenderName, int cSenderNameSize);

	virtual bool RequestGuestPassTargetList(GID_t gidGuestPassID);

	virtual bool RequestGiftTargetList(PackageId_t nPackageID);

	virtual void AcknowledgeMessageByGID(char const* pchMessageGID);

	virtual bool SetLanguage(char const* pchLanguage);

	virtual void TrackAppUsageEvent(CGameID gameID, int eAppUsageEvent, char const* pchExtraInfo = "");

	virtual int RaiseConnectionPriority(EConnectionPriority eConnectionPriority);
	virtual void ResetConnectionPriority(int hRaiseConnectionPriorityPrev);

	virtual void SetAccountNameFromSteam2(char const* pchAccountName);
	virtual void SetPasswordFromSteam2(char const* pchPassword);

	virtual void SetAccountNameForCachedCredentialLogin(char  const*,bool);
	virtual void SetLoginInformation( const char *szUserName, const char *szPassword, bool bUnknown ) = 0;

	virtual void SetAccountCreationTime(RTime32 rtime32Time);
	virtual bool DoesTextContainUserPassword(char const* pchText);

	virtual uint32 obselete_GetCMIPAddress();
	virtual uint32 obselete_GetP2PRelayIPAddress();

	virtual bool RequestWebAuthToken(void);
	virtual bool GetLanguage(char* pchLanguage, int cbLanguage);
	virtual void SetCyberCafe(bool bCyberCafe);

	virtual void CreateAccount(char const* pchAccountName, char const* pchNewPassword, char const* pchNewEmail, int iQuestion, char const* pchNewQuestion, char const* pchNewAnswer);

	virtual void CheckPassword(char const* pchAccountName, char const* pchPassword, bool bAttemptRecovery);
	virtual void ResetPassword(char const* pchAccountName, char const* pchOldPassword, char const* pchNewPassword, char const* pchValidationCode, char const* pchAnswer);



	virtual void TrackNatTraversalStat(CNatTraversalStat const* pNatStat);

	virtual void RefreshSteam2Login();
	virtual void RefreshSteam2LoginWithSecureOption();
	virtual bool Steam2IsSecureComputer();

	virtual PackageId_t GetPackageIDForGuestPassToRedeemByGID(GID_t gid);

	virtual void TrackSteamUsageEvent(ESteamUsageEvent eSteamUsageEvent, byte const* pubKV, uint32 cubKV);
	virtual void TrackSteamGUIUsage(char  const*);

	virtual void SetComputerInUse();

	virtual bool IsGameRunning(CGameID gameID);


	virtual uint64 GetCurrentSessionToken();

	virtual bool UpdateAppOwnershipTicket(AppId_t nAppID, bool bOnlyUpdateIfStale);

	virtual bool RequestCustomBinary(char const* pszAbsolutePath, AppId_t nAppID, bool);
	virtual bool GetCustomBinariesState(AppId_t unAppID,unsigned int*);

	virtual void SetCellID(CellID_t cellID);

	virtual bool GetUserBaseFolder(void);

	virtual bool GetUserDataFolder(CGameID gameID, char* pchBuffer, int cubBuffer);
	virtual bool GetUserConfigFolder(char *,int);

	virtual bool GetAccountName(char* pchAccountName, uint32 cb);

	virtual void RequiresLegacyCDKey(unsigned int);
	virtual bool GetLegacyCDKey(AppId_t nAppID, char* pchKeyData, int cbKeyData);
	virtual bool HasLegacyCDKey(AppId_t nAppID);
	virtual void RemoveLegacyCDKey(AppId_t nAppID);

	virtual void StartVoiceRecording();
	virtual void StopVoiceRecording();
	virtual void ResetVoiceRecording();

	virtual void GetAvailableVoice(unsigned int *,unsigned int *);
	virtual void GetVoice(bool,void *,unsigned int,unsigned int *,bool,void *,unsigned int,unsigned int *);

	virtual EVoiceResult GetCompressedVoice(void* pDestBuffer, uint32 cbDestBufferSize, uint32* nBytesWritten);
	virtual EVoiceResult DecompressVoice(void* pCompressed, uint32 cbCompressed, void* pDestBuffer, uint32 cbDestBufferSize, uint32* nBytesWritten);

	virtual bool IsAnyGameRunning();

	virtual void ChangePassword(char const* pchOldPassword, char const* pchNewPassword);
	virtual void ChangeEmail(char const*, char const* pchEmail);
	virtual void ChangeSecretQuestionAndAnswer(char const*, int iQuestion, char const* pchNewQuestion, char const* pchNewAnswer);

	virtual void SetSteam2FullASTicket(uint8* pubTicket, int cubTicket);

	virtual bool GetEmail(char* pchEmail, int cchEmail);

	virtual void RequestForgottenPasswordEmail(char const* pchAccountName, char const* pchTriedPassword);

	//virtual void ResetPasswordInformSteam3(char const* pchAccountName, char const* pchNewPassword, char const* pchValidationCode, char const* pchAnswer);
	//virtual void CreateAccountInformSteam3(char const* pchAccountName, char const* pchNewPassword, char const* pchNewEmail, int iQuestion, char const* pchNewQuestion, char const* pchNewAnswer);
	
	virtual void Test_FakeConnectionTimeout();

	virtual bool RunInstallScript(uint32*, AppId_t nAppID, char const* pchInstallPath, char const* pchLanguage, bool bUninstall);

	virtual AppId_t IsInstallScriptRunning();

	virtual bool GetInstallScriptString(AppId_t nAppID, char const* pchInstallPath, char const* pchLanguage, char const* pchKeyname, char const* pchKeyvalue, char* pchValue, int cchValue);
	virtual bool GetInstallScriptState(char* pchDescription, unsigned int cchDescription, unsigned int* punNumSteps, unsigned int* punCurrStep);

	virtual bool SpawnProcess(void* lpVACBlob, uint32 cbBlobSize, char const* lpApplicationName, char const* lpCommandLine, uint32 dwCreationFlags, char const* lpCurrentDirectory, AppId_t nAppID, char const* pchGameName, bool bAlwaysUseShellExec);
	
	virtual uint32 GetAppOwnershipTicketLength(uint32 nAppID);
	virtual uint32 GetAppOwnershipTicketData(uint32 nAppID, void* pvBuffer, uint32 cbBufferLength);

	virtual bool GetAppDecryptionKey(uint32 nAppID, void* pvBuffer, uint32 cbBufferLength);

	virtual int GetMarketingMessageCount();
	virtual bool GetMarketingMessage(int cMarketingMessage, uint64* gidMarketingMessageID, char* pubMsgUrl, int cubMessageUrl);

	virtual HAuthTicket GetAuthSessionTicket(void* pMyAuthTicket, int cbMaxMyAuthTicket, uint32* pcbAuthTicket);

	virtual EBeginAuthSessionResult BeginAuthSession(void const* pTheirAuthTicket, int cbTicket, CSteamID steamID);
	virtual void EndAuthSession(CSteamID steamID);

	virtual void CancelAuthTicket(HAuthTicket hAuthTicket);

	virtual int IsUserSubscribedAppInTicket(CSteamID, uint32);

	virtual void SetAccountLimited(bool);
	virtual bool BIsAccountLimited();

	virtual void SendValidationEmail(void);
	virtual void BGameConnectTokensAvailable(void);
	virtual int NumGamesRunning(void);
	virtual CGameID GetRunningGameID(int);
	virtual void GetAccountSecurityPolicyFlags(void);
	virtual void RequestChangeEmail(char  const*,int);
	virtual void ChangePasswordWithCode(char  const*,char  const*,char  const*);
	virtual void ChangeEmailWithCode(char  const*,char  const*,char  const*);
	virtual void ChangeSecretQuestionAndAnswerWithCode(char  const*,char  const*,char  const*,char  const*);
	virtual void SetClientStat(EClientStat eClientStat,long long,unsigned int,unsigned int,unsigned int);
	virtual void VerifyPassword(char  const*);
	virtual void BSupportUser(void);
	virtual void BIsAppOverlayEnabled(unsigned int);
	virtual void GetMicroTxnAppID(unsigned long long);
	virtual void GetMicroTxnOrderID(unsigned long long);
	virtual void BGetMicroTxnPrice(unsigned long long,/*CAmount*/int *,/*CAmount*/int *,bool *);
	virtual void GetMicroTxnLineItemCount(unsigned long long);
	virtual void BGetMicroTxnLineItem(unsigned long long,unsigned int,/*CAmount*/int *,unsigned int *,char *,unsigned int);
	virtual void AuthorizeMicroTxn(unsigned long long,/*EMicroTxnAuthResponse*/int);
	virtual void NotifyAppMicroTxnAuthResponse(unsigned int,unsigned long long,bool);
	virtual void BGetWalletBalance(bool *,/*CAmount*/int *);
	virtual void RequestMicroTxnInfo(unsigned long long);
	virtual void BGetAppMinutesPlayed(unsigned int,int *,int *);
	virtual void BGetGuideURL(unsigned int,char *,unsigned int);

};

#endif // ICLIENTUSER_H