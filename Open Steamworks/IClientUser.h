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

#ifndef STEAM // linux ver
	virtual bool IsVACBanned(int nGameID);
	virtual bool RequireShowVACBannedMessage(int nGameID);
	virtual void AcknowledgeVACBanning(int nGameID);
#else // windows ver
	virtual bool IsVACBanned(AppId_t nGameID);
	virtual bool RequireShowVACBannedMessage(AppId_t nAppID);
	virtual void AcknowledgeVACBanning(AppId_t nAppID);
#endif

	virtual void SetSteam2Ticket(uint8* pubTicket, int cubTicket);

#ifndef STEAM // linux only
	virtual void AddServerNetAddress(uint32, uint16);
#endif

	virtual bool SetEmail(char const* pchEmail);
	virtual bool SetRegistryString(ERegistrySubTree eRegistrySubTree, char const* pchKey, char const* pchValue);
	virtual bool GetRegistryString(ERegistrySubTree eRegistrySubTree, char const* pchKey, char* pchValue, int cbValue);
	virtual bool SetRegistryInt(ERegistrySubTree eRegistrySubTree, char const* pchKey, int iValue);
	virtual bool GetRegistryInt(ERegistrySubTree eRegistrySubTree, char const* pchKey, int* pValue);

#ifndef STEAM // linux
	virtual int InitiateGameConnection(void* pOutputBlob, int cbBlobMax, CSteamID steamIDGS, CGameID gameID, uint32 unIPServer, uint16 usPortServer, bool bSecure, void* pvSteam2GetEncryptionKey, int cbSteam2GetEncryptionKey);
#else // windows
	virtual int InitiateGameConnection(void* pOutputBlob, int cbBlobMax, CSteamID steamIDGS, CGameID gameID, uint32 unIPServer, uint16 usPortServer, bool bSecure);
	virtual int InitiateGameConnectionOld(void* pOutputBlob, int cbBlobMax, CSteamID steamIDGS, CGameID gameID, uint32 unIPServer, uint16 usPortServer, bool bSecure, void* pvSteam2GetEncryptionKey, int cbSteam2GetEncryptionKey);
#endif

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

	//virtual int RaiseConnectionPriority(EConnectionPriority eConnectionPriority);
	virtual int RaiseConnectionPriority(unsigned int eConnectionPriority);
	virtual void ResetConnectionPriority(int hRaiseConnectionPriorityPrev);

	virtual void SetAccountName(char const* pchAccountName);
	virtual void SetPassword(char const* pchPassword);

	virtual void SetAccountCreationTime(RTime32 rtime32Time);
	virtual bool DoesTextContainUserPassword(char const* pchText);

#ifdef STEAM // windows
	virtual uint32 GetCMIPAddress();
	virtual uint32 GetP2PRelayIPAddress();
#else // linux
	virtual uint32 obselete_GetCMIPAddress();
	virtual uint32 obselete_GetP2PRelayIPAddress();
#endif

	virtual bool GetOneTimeWGAuthPassword(char* pchPassword, int cbPassword);
	virtual bool GetLanguage(char* pchLanguage, int cbLanguage);
	virtual void SetCyberCafe(bool bCyberCafe);

#ifndef STEAM // linux
	virtual void ChangePassword(char const* pchOldPassword, char const* pchNewPassword);
	virtual void ChangeEmail(char const* pchEmail);
	virtual void ChangeSecretQuestionAndAnswer(int iQuestion, char const* pchNewQuestion, char const* pchNewAnswer);
#else // windows
	virtual void ChangePasswordOld(char const* pchOldPassword, char const* pchNewPassword);
	virtual void ChangeEmailOld(char const* pchEmail);
	virtual void ChangeSecretQuestionAndAnswerOld(char const*, int iQuestion, char const* pchNewQuestion, char const* pchNewAnswer);
#endif

	virtual void CreateAccount(char const* pchAccountName, char const* pchNewPassword, char const* pchNewEmail, int iQuestion, char const* pchNewQuestion, char const* pchNewAnswer);

#ifdef STEAM // windows
	virtual void CheckPassword(char const* pchAccountName, char const* pchPassword, bool bAttemptRecovery);
	virtual void ResetPassword(char const* pchAccountName, char const* pchOldPassword, char const* pchNewPassword, char const* pchValidationCode, char const* pchAnswer);
#endif

	virtual void TrackNatTraversalStat(CNatTraversalStat const* pNatStat);

	virtual void RefreshSteam2Login();

	virtual PackageId_t GetPackageIDForGuestPassToRedeemByGID(GID_t gid);

	//virtual void TrackSteamUsageEvent(ESteamUsageEvent eSteamUsageEvent, byte const* pubKV, uint32 cubKV);
	virtual void TrackSteamUsageEvent(uint32 eSteamUsageEvent, const char* pubKV, uint32 cubKV);

	virtual void SetComputerInUse();

	virtual bool IsGameRunning(CGameID gameID);

#ifdef STEAM
	virtual uint64 GetCurrentSessionToken();

	virtual bool UpdateAppOwnershipTicket(AppId_t nAppID, bool bOnlyUpdateIfStale);

	virtual bool RequestCustomBinary(char const* pszAbsolutePath, AppId_t nAppID, bool);
	virtual bool IsWaitingForCustomBinaries(AppId_t unAppID);

	virtual void SetCellID(CellID_t cellID);

	virtual bool GetUserDataFolder(CGameID gameID, char* pchBuffer, int cubBuffer);

	virtual bool GetAccountName(char* pchAccountName, uint32 cb);

	virtual bool GetLegacyCDKey(AppId_t nAppID, char* pchKeyData, int cbKeyData);
	virtual bool HasLegacyCDKey(AppId_t nAppID);
	virtual void RemoveLegacyCDKey(AppId_t nAppID);

	virtual void StartVoiceRecording();
	virtual void StopVoiceRecording();
	virtual void ResetVoiceRecording();

	virtual EVoiceResult GetCompressedVoice(void* pDestBuffer, uint32 cbDestBufferSize, uint32* nBytesWritten);
	virtual EVoiceResult DecompressVoice(void* pCompressed, uint32 cbCompressed, void* pDestBuffer, uint32 cbDestBufferSize, uint32* nBytesWritten);

	virtual bool IsAnyGameRunning();

	virtual void ChangePassword(char const* pchOldPassword, char const* pchNewPassword);
	virtual void ChangeEmail(char const*, char const* pchEmail);
	virtual void ChangeSecretQuestionAndAnswer(char const*, int iQuestion, char const* pchNewQuestion, char const* pchNewAnswer);

	virtual void SetSteam2FullASTicket(uint8* pubTicket, int cubTicket);

	virtual bool GetEmail(char* pchEmail, int cchEmail);

	virtual void ResetPasswordInformSteam3(char const* pchAccountName, char const* pchNewPassword, char const* pchValidationCode, char const* pchAnswer);
	virtual void RequestForgottenPasswordEmail(char const* pchAccountName, char const* pchTriedPassword);
	virtual void CreateAccountInformSteam3(char const* pchAccountName, char const* pchNewPassword, char const* pchNewEmail, int iQuestion, char const* pchNewQuestion, char const* pchNewAnswer);
	
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
#endif
};

#endif // ICLIENTUSER_H
