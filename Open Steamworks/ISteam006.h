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

#ifndef ISTEAM006_H
#define ISTEAM006_H
#ifdef _WIN32
#pragma once
#endif


abstract_class ISteam006
{
public:
	virtual ~ISteam006() { };

	virtual SteamCallHandle_t ChangePassword(const char* cszCurrentPassphrase, const char* cszNewPassphrase, TSteamError* pError) = 0;
	virtual int GetCurrentEmailAddress(char* szEmailaddress, unsigned int uBufSize, unsigned int* puEmailaddressChars, TSteamError* pError) = 0;
	virtual SteamCallHandle_t ChangePersonalQA(const char* cszCurrentPassphrase, const char* cszNewPersonalQuestion, const char* cszNewAnswerToQuestion, TSteamError* pError) = 0;
	virtual SteamCallHandle_t ChangeEmailAddress(const char* cszNewEmailAddress, TSteamError* pError) = 0;
	virtual SteamCallHandle_t VerifyEmailAddress(const char* cszEmailAddress, TSteamError* pError) = 0;
	virtual SteamCallHandle_t RequestEmailAddressVerificationEmail(TSteamError* pError) = 0;
	virtual SteamCallHandle_t ChangeAccountName(const char* cszCurrentAccountName, const char* cszNewAccountName, TSteamError* pError) = 0;
	virtual int MountAppFilesystem(TSteamError* pError) = 0;
	virtual int UnmountAppFilesystem(TSteamError* pError) = 0;
	virtual SteamHandle_t MountFilesystem(unsigned int uAppId, const char* szMountPath, TSteamError* pError) = 0;
	virtual int UnmountFilesystem(SteamHandle_t hFile, TSteamError* pError) = 0;
	virtual int Stat(const char* cszName, TSteamElemInfo* pInfo, TSteamError* pError) = 0;
	virtual int SetvBuf(SteamHandle_t hFile, void* pBuf, ESteamBufferMethod eMethod, unsigned int uBytes, TSteamError* pError) = 0;
	virtual int FlushFile(SteamHandle_t hFile, TSteamError* pError) = 0;
	virtual SteamHandle_t OpenFile(const char* cszName, const char* cszMode, TSteamError* pError) = 0;
	virtual SteamHandle_t OpenFileEx(const char* cszFileName, const char* cszMode, int iArg3, unsigned int* puSize, int* piArg5, TSteamError *pError) = 0;
	virtual SteamHandle_t OpenTmpFile(TSteamError* pError) = 0;
	virtual void ClearError(TSteamError* pError) = 0;
	virtual int GetVersion(char* szVersion, unsigned int uVersionBufSize) = 0;
	virtual int GetOfflineStatus(TSteamOfflineStatus* pSteamOfflineStatus, TSteamError* pError) = 0;
	virtual int ChangeOfflineStatus(TSteamOfflineStatus* pSteamOfflineStatus, TSteamError* pError) = 0;
	virtual int ProcessCall(SteamCallHandle_t handle, TSteamProgress *pProgress, TSteamError *pError) = 0;
	virtual int AbortCall(SteamCallHandle_t handle, TSteamError *pError) = 0;
	virtual int BlockingCall(SteamCallHandle_t handle, unsigned int uiProcessTickMS, TSteamError *pError) = 0;
	virtual int SetMaxStallCount(unsigned int uNumStalls, TSteamError *pError) = 0;
	virtual int CloseFile(SteamHandle_t hFile, TSteamError* pError) = 0;
	virtual unsigned int ReadFile(void *pBuf, unsigned int uSize, unsigned int uCount, SteamHandle_t hFile, TSteamError *pError) = 0;
	virtual unsigned int WriteFile(const void *pBuf, unsigned int uSize, unsigned int uCount, SteamHandle_t hFile, TSteamError *pError) = 0;
	virtual int Getc(SteamHandle_t hFile, TSteamError* pError) = 0;
	virtual int Putc(int cChar, SteamHandle_t hFile, TSteamError *pError) = 0;
	virtual int SeekFile(SteamHandle_t hFile, long int lOffset, ESteamSeekMethod sm, TSteamError *pError) = 0;
	virtual long int TellFile(SteamHandle_t hFile,TSteamError* pError) = 0;
	virtual long int SizeFile(SteamHandle_t hFile,TSteamError* pError) = 0;
	virtual SteamHandle_t FindFirst(const char *cszPattern, ESteamFindFilter eFilter, TSteamElemInfo *pFindInfo, TSteamError *pError) = 0;
	virtual int FindNext(SteamHandle_t hFind, TSteamElemInfo *pFindInfo, TSteamError *pError) = 0;
	virtual int FindClose(SteamHandle_t hFind, TSteamError* pError) = 0;
	virtual int GetLocalFileCopy(const char *cszName, TSteamError *pError) = 0;
	virtual int IsFileImmediatelyAvailable(const char *cszName, TSteamError *pError) = 0;
	virtual int HintResourceNeed(const char *cszHintList, int bForgetEverything, TSteamError *pError) = 0;
	virtual int ForgetAllHints(TSteamError *pError) = 0;
	virtual int PauseCachePreloading(TSteamError *pError) = 0;
	virtual int ResumeCachePreloading(TSteamError *pError) = 0;
	virtual SteamCallHandle_t WaitForResources(const char *cszMasterList, TSteamError *pError) = 0;
	virtual int StartEngine(TSteamError *pError) = 0;
	virtual int ShutdownEngine(TSteamError* pError) = 0;
	virtual int Startup(unsigned int uUsingMask, TSteamError *pError) = 0;
	virtual int Cleanup(TSteamError* pError) = 0;
	virtual unsigned int NumAppsRunning(TSteamError* pError) = 0;
	virtual SteamCallHandle_t CreateAccount(const char *cszUser, const char *cszPassphrase, const char *cszCreationKey, const char *cszPersonalQuestion, const char *cszAnswerToQuestion, const char* cszArg6, int *pbCreated, TSteamError *pError) = 0;
	virtual SteamCallHandle_t GenerateSuggestedAccountNames(const char* cszArg1, const char* cszArg2, char* szArg3, unsigned int uArg4, unsigned int* puArg5, TSteamError *pError) = 0;
	virtual int IsLoggedIn(int *pbIsLoggedIn, TSteamError *pError) = 0;
	virtual SteamCallHandle_t Logout(TSteamError* pError) = 0;
	virtual int IsSecureComputer(int *pbIsSecure, TSteamError *pError) = 0;
	virtual SteamHandle_t CreateLogContext(const char *cszName) = 0;
	virtual int Log(SteamHandle_t hContext, const char *cszMsg) = 0;
	virtual void LogResourceLoadStarted(const char *cszMsg) = 0;
	virtual void LogResourceLoadFinished(const char *cszMsg) = 0;
	virtual SteamCallHandle_t RefreshLogin(const char *cszPassphrase, int bIsSecureComputer, TSteamError* pError) = 0;
	virtual int VerifyPassword(const char* cszArg1, int* piArg2, TSteamError* pError) = 0;
	virtual int GetUserType(unsigned int* puArg1, TSteamError* pError) = 0;
	virtual int GetAppStats(TSteamAppStats *pAppStats, TSteamError *pError) = 0;
	virtual SteamCallHandle_t IsAccountNameInUse(const char* cszUser, int* pbInUse, TSteamError *pError) = 0;
	virtual int GetAppIds(unsigned int puIds[], unsigned int uMaxIds, TSteamError *pError) = 0;
	virtual int GetSubscriptionStats(TSteamSubscriptionStats *pSubscriptionStats, TSteamError *pError) = 0;
	virtual SteamCallHandle_t RefreshAccountInfo(int arg1, TSteamError *pError) = 0;
	virtual SteamCallHandle_t Subscribe(unsigned int uSubscriptionId, const TSteamSubscriptionBillingInfo *pSubscriptionBillingInfo, TSteamError *pError) = 0;
	virtual SteamCallHandle_t Unsubscribe(unsigned int uSubscriptionId, TSteamError *pError) = 0;
	virtual int GetSubscriptionReceipt(unsigned int uSubscriptionId , TSteamSubscriptionReceipt* pSteamSubscriptionReceipt, TSteamError *pError) = 0;
	virtual int GetAccountStatus(unsigned int* puArg1, TSteamError *pError) = 0;
	virtual SteamCallHandle_t SetUser(const char *cszUser, int *pbUserSet, TSteamError *pError) = 0;
	virtual int GetUser(char *szUser, unsigned int uBufSize, unsigned int *puUserChars, TSteamGlobalUserID* pSteamGlobalUserID, TSteamError *pError) = 0;
	virtual SteamCallHandle_t Login(const char *cszUser, const char *cszPassphrase, int bIsSecureComputer, TSteamError *pError) = 0;
	virtual SteamCallHandle_t AckSubscriptionReceipt(unsigned int uArg1, TSteamError *pError) = 0;
	virtual int IsAppSubscribed(unsigned int uAppId, int *pbIsAppSubscribed, int *pReserved, TSteamError *pError) = 0;
	virtual int GetSubscriptionIds(unsigned int puIds[], unsigned int uMaxIds, TSteamError *pError) = 0;
	virtual int EnumerateSubscription(unsigned int uSubscriptionId, TSteamSubscription *pSubscription, TSteamError *pError) = 0;
	virtual int EnumerateSubscriptionDiscount(unsigned int uSubscriptionId, unsigned int uDiscountIdx, TSteamSubscriptionDiscount* pSteamSubscriptionDiscount, TSteamError *pError) = 0;
	virtual int EnumerateSubscriptionDiscountQualifier(unsigned int uSubscriptionId, unsigned int uDiscountIdx, unsigned int uQualifierIdx, TSteamDiscountQualifier* pSteamDiscountQualifier, TSteamError *pError) = 0;
	virtual int EnumerateApp(unsigned int uAppId, TSteamApp *pApp, TSteamError *pError) = 0;
	virtual int EnumerateAppLaunchOption(unsigned int uAppId, unsigned int uLaunchOptionIndex, TSteamAppLaunchOption *pLaunchOption, TSteamError *pError) = 0;
	virtual SteamCallHandle_t DeleteAccount(TSteamError* pError) = 0;
	virtual int EnumerateAppIcon(unsigned int uAppId, unsigned int uIconIndex, unsigned char *pIconData, unsigned int uIconDataBufSize,  unsigned int *puSizeOfIconData, TSteamError *pError) = 0;
	virtual SteamCallHandle_t LaunchApp(unsigned int uAppId, unsigned int uLaunchOption, const char *cszArgs, TSteamError *pError) = 0;
	virtual int GetCacheFilePath(unsigned int uAppId,  char* szFilePath, unsigned int uBufferLength, unsigned int* puRecievedLength, TSteamError *pError) = 0;
	virtual int EnumerateAppVersion(unsigned int uAppId, unsigned int uVersionIndex, TSteamAppVersion *pAppVersion, TSteamError *pError) = 0;
	virtual int EnumerateAppDependency(unsigned int uAppId, unsigned int uDependency, TSteamAppDependencyInfo *pDependencyInfo, TSteamError *pError) = 0;
	virtual SteamCallHandle_t StartLoadingCache(unsigned int uAppId, TSteamError *pError) = 0;
	virtual int InsertAppDependency(unsigned int uAppId, unsigned int uFileSystemIndex, TSteamAppDependencyInfo *pDependencyInfo, TSteamError *pError) = 0;
	virtual int RemoveAppDependency(unsigned int uAppId, unsigned int uFileSystemIndex, TSteamError *pError) = 0;
	virtual int FindApp(const char* cszArg1, unsigned int *, TSteamError *pError) = 0;
	virtual int GetAppDependencies(unsigned int uAppId, unsigned int puDependecies[], unsigned int uBufferLength, TSteamError *pError) = 0;
	virtual int IsSubscribed(unsigned int uSubscriptionId, int *pbIsSubscribed, int *pReserved, TSteamError *pError) = 0;
	virtual int GetAppUserDefinedInfo(unsigned int uAppId, const char *cszPropertyName, char *szPropertyValue, unsigned int uBufSize, unsigned int *puPropertyValueLength, TSteamError *pError) = 0;
	virtual SteamCallHandle_t WaitForAppReadyToLaunch(unsigned int uAppId, TSteamError *pError) = 0;
	virtual int IsCacheLoadingEnabled(unsigned int uAppId, int *pbIsLoading, TSteamError *pError) = 0;
	virtual SteamCallHandle_t StopLoadingCache(unsigned int uAppId, TSteamError *pError) = 0;
	virtual ESteamError GetEncryptedUserIDTicket(const void *pEncryptionKeyReceivedFromAppServer, unsigned int uEncryptionKeyLength, void *pOutputBuffer, unsigned int uSizeOfOutputBuffer, unsigned int *pReceiveSizeOfEncryptedTicket, TSteamError *pError) = 0;
	virtual SteamCallHandle_t FlushCache(unsigned int uAppId, TSteamError *pError) = 0;
	virtual SteamCallHandle_t RepairOrDecryptCaches(unsigned int uAppId, int iArg2, TSteamError *pError) = 0;
	virtual SteamCallHandle_t LoadCacheFromDir(unsigned int uAppId, const char *cszPath, TSteamError *pError) = 0;
	virtual int GetCacheDefaultDirectory(char *szPath, TSteamError *pError) = 0;
	virtual int SetCacheDefaultDirectory(const char *cszPath, TSteamError *pError) = 0;
	virtual int GetAppDir(unsigned int uAppId, char* szAppDir, TSteamError *pError) = 0;
	virtual SteamCallHandle_t MoveApp(unsigned int uAppId, const char *szPath, TSteamError *pError) = 0;
	virtual SteamCallHandle_t GetAppCacheSize(unsigned int uAppId, unsigned int *puCacheSizeInMb, TSteamError *pError) = 0;
	virtual SteamCallHandle_t SetAppCacheSize(unsigned int uAppId, unsigned int uCacheSizeInMb, TSteamError *pError) = 0;
	virtual SteamCallHandle_t SetAppVersion(unsigned int uAppId, unsigned int uAppVersionId, TSteamError *pError) = 0;
	virtual SteamCallHandle_t Uninstall(TSteamError* pError) = 0;
	virtual int SetNotificationCallback(SteamNotificationCallback_t pCallbackFunction, TSteamError *pError) = 0;
	virtual SteamCallHandle_t ChangeForgottenPassword(const char* cszArg1, const char* cszArg2, const char* cszArg3, const char* cszArg4, int* piArg5, TSteamError *pError) = 0;
	virtual SteamCallHandle_t RequestForgottenPasswordEmail(const char* cszArg1, char* szArg2, TSteamError *pError) = 0;
	virtual SteamCallHandle_t RequestAccountsByEmailAddressEmail(const char* cszArg1, TSteamError *pError) = 0;
	virtual SteamCallHandle_t RequestAccountsByCdKeyEmail(const char* cszArg1, TSteamError *pError) = 0;
	virtual SteamCallHandle_t GetNumAccountsWithEmailAddress(const char* cszArg1, unsigned int* puArg2, TSteamError *pError) = 0;
	virtual SteamCallHandle_t UpdateAccountBillingInfo(const TSteamPaymentCardInfo *pPaymentCardInfo, TSteamError *pError) = 0;
	virtual SteamCallHandle_t UpdateSubscriptionBillingInfo(unsigned int uSubscriptionId, const TSteamSubscriptionBillingInfo *pSubscriptionBillingInfo, TSteamError *pError) = 0;
	virtual int GetSponsorUrl(unsigned int uAppId, char *szUrl, unsigned int uBufSize, unsigned int *pUrlChars, TSteamError *pError) = 0;
	virtual int GetContentServerInfo(unsigned int uArg1, unsigned int* puArg2, unsigned int* puArg3, TSteamError *pError) = 0;
	virtual SteamCallHandle_t GetAppUpdateStats(unsigned int uAppId, ESteamAppUpdateStatsQueryType eSteamAppUpdateStatsQueryType, TSteamUpdateStats *pUpdateStats, TSteamError *pError) = 0;
	virtual int GetTotalUpdateStats(TSteamUpdateStats*,TSteamError* pError) = 0;
	virtual SteamCallHandle_t CreateCachePreloaders(TSteamError* pError) = 0;
	virtual void Win32SetMiniDumpComment(const char* cszComment) = 0;
	virtual void Win32SetMiniDumpSourceControlId(unsigned int uSourceControlId) = 0;
	virtual void Win32SetMiniDumpEnableFullMemory() = 0;
	virtual void Win32WriteMiniDump(const char*, const char*, const char*, const char*, unsigned int) = 0;
	virtual int GetCurrentAppId(unsigned int* puAppId, TSteamError *pError) = 0;
	virtual int GetAppPurchaseCountry(unsigned int uAppId, char* szCountryCode, unsigned int uBufferLength, int* puRecievedLength, TSteamError* pError) = 0;
	virtual int GetLocalClientVersion(unsigned int* puArg1, unsigned int* puArg2, TSteamError *pError) = 0;
	virtual int IsFileNeededByCache(unsigned int uAppId, const char* cszFileName, unsigned int uArg3, TSteamError* pError) = 0;
	virtual int LoadFileToCache(unsigned int uArg1, const char* cszArg2, const void* pcvArg3, unsigned int uArg4, unsigned int uArg5, TSteamError *pError) = 0;
	virtual int GetCacheDecryptionKey(unsigned int uAppId, char* szCacheDecryptionKey, unsigned int uBufferLength, unsigned int* puRecievedLength, TSteamError *pError) = 0;
	virtual int GetSubscriptionExtendedInfo(unsigned int uSubscriptionId, const char* cszKeyName, char* szKeyValue, unsigned int uBufferLength, unsigned int* puRecievedLength, TSteamError *pError) = 0;
	virtual int GetSubscriptionPurchaseCountry(unsigned int uSubscriptionId, char* szCountry, unsigned int uBufferLength , int* piRecievedLength, TSteamError *pError) = 0;
	virtual int GetAppUserDefinedRecord(unsigned int uAppId, KeyValueIteratorCallback_t AddEntryToKeyValueFunc, void* pvCKeyValue, TSteamError *pError) = 0;
	virtual int FindServersNumServers(ESteamServerType eSteamServerType) = 0;
	virtual int FindServersIterateServer(ESteamServerType eSteamServerType, unsigned int uIndex, char *szServerAddress, int iServerAddressChars) = 0;
	virtual const char* FindServersGetErrorString() = 0;
	virtual int CheckAppOwnership(unsigned int uAppId, int* pbOwned, TSteamGlobalUserID* pSteamGlobalUserID, TSteamError* pError) = 0;
	virtual SteamCallHandle_t GetCachePercentFragmentation(unsigned int uAppId, unsigned int* puPercentFragmented, TSteamError* pError) = 0;
	virtual SteamCallHandle_t DefragCaches(unsigned int uAppId, TSteamError* pError) = 0;
	virtual int IsFileNeededByApp(unsigned int uAppId, const char* cszFileName, unsigned int uArg1, unsigned int* puArg2, TSteamError* pError) = 0;
	virtual SteamCallHandle_t WaitForAppResources(unsigned int uAppId, const char* cszMasterList, TSteamError* pError) = 0;
	virtual int ForceCellId(unsigned int uCellId, TSteamError* pError) = 0;
	virtual int GetAppDLCStatus( unsigned int nAppID, unsigned int nDlcId, int *pbOwned, TSteamError *pError ) = 0;
	virtual unknown_ret StartEngineEx( TSteamError *pError, bool a1, bool a2 ) = 0;
};


#define STEAM_INTERFACE_VERSION_006 "Steam006"

#endif // ISTEAM006_H
