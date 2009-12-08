
#include "CSteam006.h"

CSteam006::CSteam006( ISteam006 *realBase )
{
	base = realBase;
}

SteamCallHandle_t CSteam006::ChangePassword(const string_t* cszCurrentPassphrase, const string_t* cszNewPassphrase, TSteamError* pError)
{
	BOOKKEEP_PROXY();

	SteamCallHandle_t returnObj = base->ChangePassword( cszCurrentPassphrase, cszNewPassphrase, pError );

	::Log(
		"CSteam006::ChangePassword( cszCurrentPassphrase = \"%s\", cszNewPassphrase = \"%s\" ) = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, cszCurrentPassphrase, cszNewPassphrase, returnObj, FormatTSteamError( pError )
	);

	return returnObj;
}

int CSteam006::GetCurrentEmailAddress(char* szEmailaddress, unsigned int uBufSize, unsigned int* puEmailaddressChars, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetCurrentEmailAddress( szEmailaddress, uBufSize, puEmailaddressChars, pError );
}

SteamCallHandle_t CSteam006::ChangePersonalQA(const string_t* cszCurrentPassphrase, const string_t* cszNewPersonalQuestion, const string_t* cszNewAnswerToQuestion, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->ChangePersonalQA( cszCurrentPassphrase, cszNewPersonalQuestion, cszNewAnswerToQuestion, pError );
}

SteamCallHandle_t CSteam006::ChangeEmailAddress(const string_t* cszNewEmailAddress, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->ChangeEmailAddress( cszNewEmailAddress, pError );
}
SteamCallHandle_t CSteam006::VerifyEmailAddress(const string_t* cszEmailAddress, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->VerifyEmailAddress( cszEmailAddress, pError );
}
SteamCallHandle_t CSteam006::RequestEmailAddressVerificationEmail(TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->RequestEmailAddressVerificationEmail( pError );
}
SteamCallHandle_t CSteam006::ChangeAccountName(const string_t* cszCurrentAccountName, const string_t* cszNewAccountName, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->ChangeAccountName( cszCurrentAccountName, cszNewAccountName, pError );
}
int CSteam006::MountAppFilesystem(TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->MountAppFilesystem( pError );
}
int CSteam006::UnmountAppFilesystem(TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->UnmountAppFilesystem( pError );
}
SteamHandle_t CSteam006::MountFilesystem(unsigned int uAppId, const string_t* szMountPath, TSteamError* pError)
{
	BOOKKEEP_PROXY();

	SteamHandle_t returnObj = base->MountFilesystem( uAppId, szMountPath, pError );

	ADD_MAP_ENTRY( fileMap, returnObj, szMountPath );

	::Log(
		"CSteam006::MountFilesystem( uAppId = %u, szMountPath = \"%s\" ) = 0x%x\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uAppId, szMountPath, returnObj, FormatTSteamError( pError )
	);

	return returnObj;
}
int CSteam006::UnmountFilesystem(SteamHandle_t hFile, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	FREE_MAP_ENTRY( fileMap, hFile );

	return base->UnmountFilesystem( hFile, pError );
}
int CSteam006::Stat(const string_t* cszName, TSteamElemInfo* pInfo, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	
	int returnObj = base->Stat( cszName, pInfo, pError );

	::Log(
		"CSteam006::Stat( cszName = \"%s\" ) = %d\n"
		"\t\tpInfo = %s\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, cszName, returnObj, FormatTSteamElemInfo( pInfo ), FormatTSteamError( pError )
	);

	return returnObj;
}
int CSteam006::SetvBuf(SteamHandle_t hFile, void* pBuf, ESteamBufferMethod eMethod, unsigned int uBytes, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->SetvBuf( hFile, pBuf, eMethod, uBytes, pError );
}
int CSteam006::FlushFile(SteamHandle_t hFile, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->FlushFile( hFile, pError );
}
SteamHandle_t CSteam006::OpenFile(const string_t* cszName, const string_t* cszMode, TSteamError* pError)
{
	BOOKKEEP_PROXY();

	SteamHandle_t returnObj = base->OpenFile( cszName, cszMode, pError );

	ADD_MAP_ENTRY( fileMap, returnObj, cszName );

	::Log(
		"CSteam006::OpenFile( cszName = \"%s\", cszMode = \"%s\" ) = 0x%x\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, cszName, cszMode, returnObj, FormatTSteamError( pError )
	);

	return returnObj;
}
SteamHandle_t CSteam006::OpenFileEx(const string_t* cszFileName, const string_t* cszMode, int iArg3, unsigned int* puSize, int* piArg5, TSteamError *pError)
{
	BOOKKEEP_PROXY();

	SteamHandle_t returnObj = base->OpenFileEx( cszFileName, cszMode, iArg3, puSize, piArg5, pError );

	ADD_MAP_ENTRY( fileMap, returnObj, cszFileName );

	::Log(
		"CSteam006::OpenFileEx( cszFileName = \"%s\", cszMode = \"%s\", iArg3 = %d ) = 0x%x\n"
		"\t\tpuSize = %u\n"
		"\t\tpiArg5 = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, cszFileName, cszMode, iArg3, returnObj, *puSize, *piArg5, FormatTSteamError( pError )
		);

	return returnObj;
}
SteamHandle_t CSteam006::OpenTmpFile(TSteamError* pError)
{
	BOOKKEEP_PROXY();

	SteamHandle_t returnObj = base->OpenTmpFile( pError );

	ADD_MAP_ENTRY( fileMap, returnObj, "{TEMP FILE}" );

	::Log(
		"CSteam006::OpenTmpFile() = 0x%x\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, returnObj, FormatTSteamError( pError )
	);

	return returnObj;
}
void CSteam006::ClearError(TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	base->ClearError( pError );
}
int CSteam006::GetVersion(char* szVersion, unsigned int uVersionBufSize)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetVersion( szVersion, uVersionBufSize );
}
int CSteam006::GetOfflineStatus(TSteamOfflineStatus* pSteamOfflineStatus, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetOfflineStatus( pSteamOfflineStatus, pError );
}
int CSteam006::ChangeOfflineStatus(TSteamOfflineStatus* pSteamOfflineStatus, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->ChangeOfflineStatus( pSteamOfflineStatus, pError );
}
int CSteam006::ProcessCall(SteamCallHandle_t handle, TSteamProgress *pProgress, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->ProcessCall( handle, pProgress, pError );
}
int CSteam006::AbortCall(SteamCallHandle_t handle, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->AbortCall( handle, pError );
}
int CSteam006::BlockingCall(SteamCallHandle_t handle, unsigned int uiProcessTickMS, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->BlockingCall( handle, uiProcessTickMS, pError );
}
int CSteam006::SetMaxStallCount(unsigned int uNumStalls, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->SetMaxStallCount( uNumStalls, pError );
}
int CSteam006::CloseFile(SteamHandle_t hFile, TSteamError* pError)
{
	BOOKKEEP_PROXY();

	FREE_MAP_ENTRY( fileMap, hFile );

	int returnObj = base->CloseFile( hFile, pError );

	::Log(
		"CSteam006::CloseFile( hFile = 0x%x ) = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, hFile, returnObj, FormatTSteamError( pError )
	);

	return returnObj;
}
unsigned int CSteam006::ReadFile(void *pBuf, unsigned int uSize, unsigned int uCount, SteamHandle_t hFile, TSteamError *pError)
{
	BOOKKEEP_PROXY();

	unsigned int returnObj = base->ReadFile( pBuf, uSize, uCount, hFile, pError );

	HandleIterator iter = fileMap.find( hFile );
	if ( iter == fileMap.end() )
		::Log( "CSteam006::ReadFile() - Warning, file handle lookup failed!\n" );

	::Log(
		"CSteam006::ReadFile( uSize = %u, uCount = %u, hFile = [ 0x%x, \"%s\" ] ) = %d\n"
		"\t\tpBuf = 0x%x\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uSize, uCount, hFile, ( iter == fileMap.end() ? "UNKNOWN FILE HANDLE" : iter->second ), returnObj, pBuf, FormatTSteamError( pError )
	);

	return returnObj;
}
unsigned int CSteam006::WriteFile(const void *pBuf, unsigned int uSize, unsigned int uCount, SteamHandle_t hFile, TSteamError *pError)
{
	BOOKKEEP_PROXY();

	unsigned int returnObj = base->WriteFile( pBuf, uSize, uCount, hFile, pError );

	HandleIterator iter = fileMap.find( hFile );
	if ( iter == fileMap.end() )
		::Log( "CSteam006::WriteFile() - Warning, file handle lookup failed!\n" );

	::Log(
		"CSteam006::WriteFile( pBuf = 0x%x, uSize = %u, uCount = %u, hFile = [ 0x%x, \"%s\" ] ) = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, pBuf, uSize, uCount, hFile, ( iter == fileMap.end() ? "UNKNOWN FILE HANDLE" : iter->second ), returnObj, FormatTSteamError( pError )
	);
}
int CSteam006::Getc(SteamHandle_t hFile, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->Getc( hFile, pError );
}
int CSteam006::Putc(int cChar, SteamHandle_t hFile, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->Putc( cChar, hFile, pError );
}
int CSteam006::SeekFile(SteamHandle_t hFile, long int lOffset, ESteamSeekMethod sm, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->SeekFile( hFile, lOffset, sm, pError );
}
long int CSteam006::TellFile(SteamHandle_t hFile,TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->TellFile( hFile, pError );
}
long int CSteam006::SizeFile(SteamHandle_t hFile,TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->SizeFile( hFile, pError );
}
SteamHandle_t CSteam006::FindFirst(const char *cszPattern, ESteamFindFilter eFilter, TSteamElemInfo *pFindInfo, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	
	SteamHandle_t returnObj = base->FindFirst( cszPattern, eFilter, pFindInfo, pError );

	::Log(
		"CSteam006::FindFirst( cszPattern = \"%s\", eFilter = %s ) = 0x%x\n"
		"\t\tpFindInfo = %s\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, cszPattern, EnumString<ESteamFindFilter>::From( eFilter ).c_str(), returnObj, FormatTSteamElemInfo( pFindInfo ), FormatTSteamError( pError )
	);

	return returnObj;
}
int CSteam006::FindNext(SteamHandle_t hFind, TSteamElemInfo *pFindInfo, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->FindNext( hFind, pFindInfo, pError );
}
int CSteam006::FindClose(SteamHandle_t hFind, TSteamError* pError)
{
	BOOKKEEP_PROXY();

	int returnObj = base->FindClose( hFind, pError );

	::Log(
		"CSteam006::FindClose( hFind = 0x%x ) = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, hFind, returnObj, FormatTSteamError( pError )
	);

	return returnObj;
}
int CSteam006::GetLocalFileCopy(const char *cszName, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetLocalFileCopy( cszName, pError );
}
int CSteam006::IsFileImmediatelyAvailable(const char *cszName, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->IsFileImmediatelyAvailable( cszName, pError );
}
int CSteam006::HintResourceNeed(const char *cszHintList, int bForgetEverything, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->HintResourceNeed( cszHintList, bForgetEverything, pError );
}
int CSteam006::ForgetAllHints(TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->ForgetAllHints( pError );
}
int CSteam006::PauseCachePreloading(TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->PauseCachePreloading( pError );
}
int CSteam006::ResumeCachePreloading(TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->ResumeCachePreloading( pError );
}
SteamCallHandle_t CSteam006::WaitForResources(const char *cszMasterList, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->WaitForResources( cszMasterList, pError );
}
int CSteam006::StartEngine(TSteamError *pError)
{
	BOOKKEEP_PROXY();

	int returnObj = base->StartEngine( pError );

	::Log(
		"CSteam006::StartEngine() = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, returnObj, FormatTSteamError( pError )
	);

	return returnObj;
}
int CSteam006::ShutdownEngine(TSteamError* pError)
{
	BOOKKEEP_PROXY();

	int returnObj = base->ShutdownEngine( pError );

	::Log(
		"CSteam006::ShutdownEngine() = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, returnObj, FormatTSteamError( pError )
	);

	return returnObj;
}
int CSteam006::Startup(unsigned int uUsingMask, TSteamError *pError)
{
	BOOKKEEP_PROXY();

	int returnObj = base->Startup( uUsingMask, pError );

	::Log(
		"CSteam006::Startup( uUsingMask = %u ) = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uUsingMask, returnObj, FormatTSteamError( pError )
	);

	return returnObj;
}
int CSteam006::Cleanup(TSteamError* pError)
{
	BOOKKEEP_PROXY();

	int returnObj = base->Cleanup( pError );

	::Log(
		"CSteam006::Cleanup() = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, returnObj, FormatTSteamError( pError )
	);

	return returnObj;
}
unsigned int CSteam006::NumAppsRunning(TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->NumAppsRunning( pError );
}
SteamCallHandle_t CSteam006::CreateAccount(const char *cszUser, const char *cszPassphrase, const char *cszCreationKey, const char *cszPersonalQuestion, const char *cszAnswerToQuestion, const string_t* cszArg6, int *pbCreated, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->CreateAccount( cszUser, cszPassphrase, cszCreationKey, cszPersonalQuestion, cszAnswerToQuestion, cszArg6, pbCreated, pError );
}
SteamCallHandle_t CSteam006::GenerateSuggestedAccountNames(const string_t* cszArg1, const string_t* cszArg2, char* szArg3, unsigned int uArg4, unsigned int* puArg5, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GenerateSuggestedAccountNames( cszArg1, cszArg2, szArg3, uArg4, puArg5, pError );
}
int CSteam006::IsLoggedIn(int *pbIsLoggedIn, TSteamError *pError)
{
	BOOKKEEP_PROXY();

	int returnObj = base->IsLoggedIn( pbIsLoggedIn, pError );

	::Log(
		"CSteam006::IsLoggedIn() = %d\n"
		"\t\tpbIsLoggedIn = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, returnObj, *pbIsLoggedIn, FormatTSteamError( pError )
	);

	return returnObj;
}
SteamCallHandle_t CSteam006::Logout(TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->Logout( pError );
}
int CSteam006::IsSecureComputer(int *pbIsSecure, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->IsSecureComputer( pbIsSecure, pError );
}
SteamHandle_t CSteam006::CreateLogContext(const char *cszName)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->CreateLogContext( cszName );
}
int CSteam006::Log(SteamHandle_t hContext, const char *cszMsg)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->Log( hContext, cszMsg );
}
void CSteam006::LogResourceLoadStarted(const char *cszMsg)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->LogResourceLoadStarted( cszMsg );
}
void CSteam006::LogResourceLoadFinished(const char *cszMsg)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->LogResourceLoadFinished( cszMsg );
}
SteamCallHandle_t CSteam006::RefreshLogin(const char *cszPassphrase, int bIsSecureComputer, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->RefreshLogin( cszPassphrase, bIsSecureComputer, pError );
}
int CSteam006::VerifyPassword(const string_t* cszArg1, int* piArg2, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->VerifyPassword( cszArg1, piArg2, pError );
}
int CSteam006::GetUserType(unsigned int* puArg1, TSteamError* pError)
{
	return base->GetUserType( puArg1, pError );
}
int CSteam006::GetAppStats(TSteamAppStats *pAppStats, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetAppStats( pAppStats, pError );
}
SteamCallHandle_t CSteam006::IsAccountNameInUse(const string_t* cszUser, int* pbInUse, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->IsAccountNameInUse( cszUser, pbInUse, pError );
}
int CSteam006::GetAppIds(unsigned int *puIds, unsigned int uMaxIds, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetAppIds( puIds, uMaxIds, pError );
}
int CSteam006::GetSubscriptionStats(TSteamSubscriptionStats *pSubscriptionStats, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetSubscriptionStats( pSubscriptionStats, pError );
}
SteamCallHandle_t CSteam006::RefreshAccountInfo(int arg1, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->RefreshAccountInfo( arg1, pError );
}
SteamCallHandle_t CSteam006::Subscribe(unsigned int uSubscriptionId, const TSteamSubscriptionBillingInfo *pSubscriptionBillingInfo, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->Subscribe( uSubscriptionId, pSubscriptionBillingInfo, pError );
}
SteamCallHandle_t CSteam006::Unsubscribe(unsigned int uSubscriptionId, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->Unsubscribe( uSubscriptionId, pError );
}
int CSteam006::GetSubscriptionReceipt(unsigned int uSubscriptionId , TSteamSubscriptionReceipt* pSteamSubscriptionReceipt, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetSubscriptionReceipt( uSubscriptionId, pSteamSubscriptionReceipt, pError );
}
int CSteam006::GetAccountStatus(unsigned int* puArg1, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetAccountStatus( puArg1, pError );
}
SteamCallHandle_t CSteam006::SetUser(const char *cszUser, int *pbUserSet, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->SetUser( cszUser, pbUserSet, pError );
}
int CSteam006::GetUser(char *szUser, unsigned int uBufSize, unsigned int *puUserChars, TSteamGlobalUserID* pSteamGlobalUserID, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetUser( szUser, uBufSize, puUserChars, pSteamGlobalUserID, pError );
}
SteamCallHandle_t CSteam006::Login(const char *cszUser, const char *cszPassphrase, int bIsSecureComputer, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->Login( cszUser, cszPassphrase, bIsSecureComputer, pError );
}
SteamCallHandle_t CSteam006::AckSubscriptionReceipt(unsigned int uArg1, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->AckSubscriptionReceipt( uArg1, pError );
}
int CSteam006::IsAppSubscribed(unsigned int uAppId, int *pbIsAppSubscribed, int *pReserved, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->IsAppSubscribed( uAppId, pbIsAppSubscribed, pReserved, pError );
}
int CSteam006::GetSubscriptionIds(unsigned int *puIds, unsigned int uMaxIds, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetSubscriptionIds( puIds, uMaxIds, pError );
}
int CSteam006::EnumerateSubscription(unsigned int uSubscriptionId, TSteamSubscription *pSubscription, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->EnumerateSubscription( uSubscriptionId, pSubscription, pError );
}
int CSteam006::EnumerateSubscriptionDiscount(unsigned int uSubscriptionId, unsigned int uDiscountIdx, TSteamSubscriptionDiscount* pSteamSubscriptionDiscount, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->EnumerateSubscriptionDiscount( uSubscriptionId, uDiscountIdx, pSteamSubscriptionDiscount, pError );
}
int CSteam006::EnumerateSubscriptionDiscountQualifier(unsigned int uSubscriptionId, unsigned int uDiscountIdx, unsigned int uQualifierIdx, TSteamDiscountQualifier* pSteamDiscountQualifier, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->EnumerateSubscriptionDiscountQualifier( uSubscriptionId, uDiscountIdx, uQualifierIdx, pSteamDiscountQualifier, pError );
}
int CSteam006::EnumerateApp(unsigned int uAppId, TSteamApp *pApp, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->EnumerateApp( uAppId, pApp, pError );
}
int CSteam006::EnumerateAppLaunchOption(unsigned int uAppId, unsigned int uLaunchOptionIndex, TSteamAppLaunchOption *pLaunchOption, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->EnumerateAppLaunchOption( uAppId, uLaunchOptionIndex, pLaunchOption, pError );
}
SteamCallHandle_t CSteam006::DeleteAccount(TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->DeleteAccount( pError );
}
int CSteam006::EnumerateAppIcon(unsigned int uAppId, unsigned int uIconIndex, unsigned char *pIconData, unsigned int uIconDataBufSize,  unsigned int *puSizeOfIconData, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->EnumerateAppIcon( uAppId, uIconIndex, pIconData, uIconDataBufSize, puSizeOfIconData, pError );
}
SteamCallHandle_t CSteam006::LaunchApp(unsigned int uAppId, unsigned int uLaunchOption, const char *cszArgs, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->LaunchApp( uAppId, uLaunchOption, cszArgs, pError );
}
int CSteam006::GetCacheFilePath(unsigned int uAppId,  char* szFilePath, unsigned int uBufferLength, unsigned int* puRecievedLength, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetCacheFilePath( uAppId, szFilePath, uBufferLength, puRecievedLength, pError );
}
int CSteam006::EnumerateAppVersion(unsigned int uAppId, unsigned int uVersionIndex, TSteamAppVersion *pAppVersion, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->EnumerateAppVersion( uAppId, uVersionIndex, pAppVersion, pError );
}
int CSteam006::EnumerateAppDependency(unsigned int uAppId, unsigned int uDependency, TSteamAppDependencyInfo *pDependencyInfo, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->EnumerateAppDependency( uAppId, uDependency, pDependencyInfo, pError );
}
SteamCallHandle_t CSteam006::StartLoadingCache(unsigned int uAppId, TSteamError *pError)
{
	BOOKKEEP_PROXY();

	SteamCallHandle_t returnObj = base->StartLoadingCache( uAppId, pError );

	ADD_MAP_ENTRYF( callMap, returnObj, "StartLoadingCache( uAppId = %u )", uAppId );

	::Log(
		"CSteam006::StartLoadingCache( uAppId = %d ) = 0x%x\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uAppId, returnObj, FormatTSteamError( pError )
	);

	return returnObj;
}
int CSteam006::InsertAppDependency(unsigned int uAppId, unsigned int uFileSystemIndex, TSteamAppDependencyInfo *pDependencyInfo, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->InsertAppDependency( uAppId, uFileSystemIndex, pDependencyInfo, pError );
}
int CSteam006::RemoveAppDependency(unsigned int uAppId, unsigned int uFileSystemIndex, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->RemoveAppDependency( uAppId, uFileSystemIndex, pError );
}
int CSteam006::FindApp(const string_t* cszArg1, unsigned int* puArg2, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->FindApp( cszArg1, puArg2, pError );
}
int CSteam006::GetAppDependencies(unsigned int uAppId, unsigned int* puDependecies, unsigned int uBufferLength, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetAppDependencies( uAppId, puDependecies, uBufferLength, pError );
}
int CSteam006::IsSubscribed(unsigned int uSubscriptionId, int *pbIsSubscribed, int *pReserved, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->IsSubscribed( uSubscriptionId, pbIsSubscribed, pReserved, pError );
}
int CSteam006::GetAppUserDefinedInfo(unsigned int uAppId, const char *cszPropertyName, char *szPropertyValue, unsigned int uBufSize, unsigned int *puPropertyValueLength, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetAppUserDefinedInfo( uAppId, cszPropertyName, szPropertyValue, uBufSize, puPropertyValueLength, pError );
}
SteamCallHandle_t CSteam006::WaitForAppReadyToLaunch(unsigned int uAppId, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->WaitForAppReadyToLaunch( uAppId, pError );
}
int CSteam006::IsCacheLoadingEnabled(unsigned int uAppId, int *pbIsLoading, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->IsCacheLoadingEnabled( uAppId, pbIsLoading, pError );
}
SteamCallHandle_t CSteam006::StopLoadingCache(unsigned int uAppId, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->StopLoadingCache( uAppId, pError );
}
ESteamError CSteam006::GetEncryptedUserIDTicket(const void *pEncryptionKeyReceivedFromAppServer, unsigned int uEncryptionKeyLength, void *pOutputBuffer, unsigned int uSizeOfOutputBuffer, unsigned int *pReceiveSizeOfEncryptedTicket, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetEncryptedUserIDTicket( pEncryptionKeyReceivedFromAppServer, uEncryptionKeyLength, pOutputBuffer, uSizeOfOutputBuffer, pReceiveSizeOfEncryptedTicket, pError );
}
SteamCallHandle_t CSteam006::FlushCache(unsigned int uAppId, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->FlushCache( uAppId, pError );
}
SteamCallHandle_t CSteam006::RepairOrDecryptCaches(unsigned int uAppId, int iArg2, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->RepairOrDecryptCaches( uAppId, iArg2, pError );
}
SteamCallHandle_t CSteam006::LoadCacheFromDir(unsigned int uAppId, const char *cszPath, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->LoadCacheFromDir( uAppId, cszPath, pError );
}
int CSteam006::GetCacheDefaultDirectory(char *szPath, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetCacheDefaultDirectory( szPath, pError );
}
int CSteam006::SetCacheDefaultDirectory(const char *cszPath, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->SetCacheDefaultDirectory( cszPath, pError );
}
int CSteam006::GetAppDir(unsigned int uAppId, char* szAppDir, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetAppDir( uAppId, szAppDir, pError );
}
SteamCallHandle_t CSteam006::MoveApp(unsigned int uAppId, const char *szPath, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->MoveApp( uAppId, szPath, pError );
}
SteamCallHandle_t CSteam006::GetAppCacheSize(unsigned int uAppId, unsigned int *puCacheSizeInMb, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetAppCacheSize( uAppId, puCacheSizeInMb, pError );
}
SteamCallHandle_t CSteam006::SetAppCacheSize(unsigned int uAppId, unsigned int uCacheSizeInMb, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->SetAppCacheSize( uAppId, uCacheSizeInMb, pError );
}
SteamCallHandle_t CSteam006::SetAppVersion(unsigned int uAppId, unsigned int uAppVersionId, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->SetAppVersion( uAppId, uAppVersionId, pError );
}
SteamCallHandle_t CSteam006::Uninstall(TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->Uninstall( pError );
}
int CSteam006::SetNotificationCallback(SteamNotificationCallback_t pCallbackFunction, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->SetNotificationCallback( pCallbackFunction, pError );
}
SteamCallHandle_t CSteam006::ChangeForgottenPassword(const string_t* cszArg1, const string_t* cszArg2, const string_t* cszArg3, const string_t* cszArg4, int* piArg5, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->ChangeForgottenPassword( cszArg1, cszArg2, cszArg3, cszArg4, piArg5, pError );
}
SteamCallHandle_t CSteam006::RequestForgottenPasswordEmail(const string_t* cszArg1, char* szArg2, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->RequestForgottenPasswordEmail( cszArg1, szArg2, pError );
}
SteamCallHandle_t CSteam006::RequestAccountsByEmailAddressEmail(const string_t* cszArg1, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->RequestAccountsByEmailAddressEmail( cszArg1, pError );
}
SteamCallHandle_t CSteam006::RequestAccountsByCdKeyEmail(const string_t* cszArg1, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->RequestAccountsByCdKeyEmail( cszArg1, pError );
}
SteamCallHandle_t CSteam006::GetNumAccountsWithEmailAddress(const string_t* cszArg1, unsigned int* puArg2, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetNumAccountsWithEmailAddress( cszArg1, puArg2, pError );
}
SteamCallHandle_t CSteam006::UpdateAccountBillingInfo(const TSteamPaymentCardInfo *pPaymentCardInfo, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->UpdateAccountBillingInfo( pPaymentCardInfo, pError );
}
SteamCallHandle_t CSteam006::UpdateSubscriptionBillingInfo(unsigned int uSubscriptionId, const TSteamSubscriptionBillingInfo *pSubscriptionBillingInfo, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->UpdateSubscriptionBillingInfo( uSubscriptionId, pSubscriptionBillingInfo, pError );
}
int CSteam006::GetSponsorUrl(unsigned int uAppId, char *szUrl, unsigned int uBufSize, unsigned int *pUrlChars, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetSponsorUrl( uAppId, szUrl, uBufSize, pUrlChars, pError );
}
int CSteam006::GetContentServerInfo(unsigned int uArg1, unsigned int* puArg2, unsigned int* puArg3, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetContentServerInfo( uArg1, puArg2, puArg3, pError );
}
SteamCallHandle_t CSteam006::GetAppUpdateStats(unsigned int uAppId, ESteamAppUpdateStatsQueryType eSteamAppUpdateStatsQueryType, TSteamUpdateStats *pUpdateStats, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetAppUpdateStats( uAppId, eSteamAppUpdateStatsQueryType, pUpdateStats, pError );
}
int CSteam006::GetTotalUpdateStats(TSteamUpdateStats *pUpdateStats, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetTotalUpdateStats( pUpdateStats, pError );
}
SteamCallHandle_t CSteam006::CreateCachePreloaders(TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->CreateCachePreloaders( pError );
}
void CSteam006::Win32SetMiniDumpComment(const string_t* cszComment)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	base->Win32SetMiniDumpComment( cszComment );
}
void CSteam006::Win32SetMiniDumpSourceControlId(unsigned int uSourceControlId)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	base->Win32SetMiniDumpSourceControlId( uSourceControlId );
}
void CSteam006::Win32SetMiniDumpEnableFullMemory()
{
	BOOKKEEP_PROXY();
	LOG_FN();

	base->Win32SetMiniDumpEnableFullMemory();
}
void CSteam006::Win32WriteMiniDump(const string_t *cszArg1, const string_t *cszArg2, const string_t *cszArg3, const string_t *cszArg4, unsigned int uArg5)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	base->Win32WriteMiniDump( cszArg1, cszArg2, cszArg3, cszArg4, uArg5 );
}
int CSteam006::GetCurrentAppId(unsigned int* puAppId, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetCurrentAppId( puAppId, pError );
}
int CSteam006::GetAppPurchaseCountry(unsigned int uAppId, char* szCountryCode, unsigned int uBufferLength, int* puRecievedLength, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetAppPurchaseCountry( uAppId, szCountryCode, uBufferLength, puRecievedLength, pError );
}
int CSteam006::GetLocalClientVersion(unsigned int* puArg1, unsigned int* puArg2, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetLocalClientVersion( puArg1, puArg2, pError );
}
int CSteam006::IsFileNeededByCache(unsigned int uAppId, const string_t* cszFileName, unsigned int uArg3, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->IsFileNeededByCache( uAppId, cszFileName, uArg3, pError );
}
int CSteam006::LoadFileToCache(unsigned int uArg1, const string_t* cszArg2, const void* pcvArg3, unsigned int uArg4, unsigned int uArg5, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->LoadFileToCache( uArg1, cszArg2, pcvArg3, uArg4, uArg5, pError );
}
int CSteam006::GetCacheDecryptionKey(unsigned int uAppId, char* szCacheDecryptionKey, unsigned int uBufferLength, unsigned int* puRecievedLength, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetCacheDecryptionKey( uAppId, szCacheDecryptionKey, uBufferLength, puRecievedLength, pError );
}
int CSteam006::GetSubscriptionExtendedInfo(unsigned int uSubscriptionId, const string_t* cszKeyName, char* szKeyValue, unsigned int uBufferLength, unsigned int* puRecievedLength, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetSubscriptionExtendedInfo( uSubscriptionId, cszKeyName, szKeyValue, uBufferLength, puRecievedLength, pError );
}
int CSteam006::GetSubscriptionPurchaseCountry(unsigned int uSubscriptionId, char* szCountry, unsigned int uBufferLength , int* piRecievedLength, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetSubscriptionPurchaseCountry( uSubscriptionId, szCountry, uBufferLength, piRecievedLength, pError );
}
int CSteam006::GetAppUserDefinedRecord(unsigned int uAppId, KeyValueIteratorCallback_t AddEntryToKeyValueFunc, void* pvCKeyValue, TSteamError *pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->GetAppUserDefinedRecord( uAppId, AddEntryToKeyValueFunc, pvCKeyValue, pError );
}
int CSteam006::FindServersNumServers(ESteamServerType eSteamServerType)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->FindServersNumServers( eSteamServerType );
}
int CSteam006::FindServersIterateServer(ESteamServerType eSteamServerType, unsigned int uIndex, char *szServerAddress, int iServerAddressChars)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->FindServersIterateServer( eSteamServerType, uIndex, szServerAddress, iServerAddressChars );
}
const string_t* CSteam006::FindServersGetErrorString()
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->FindServersGetErrorString();
}
int CSteam006::CheckAppOwnership(unsigned int uAppId, int* pbOwned, TSteamGlobalUserID* pSteamGlobalUserID, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->CheckAppOwnership( uAppId, pbOwned, pSteamGlobalUserID, pError );
}
SteamCallHandle_t CSteam006::GetCachePercentFragmentation(unsigned int uAppId, unsigned int* puPercentFragmented, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	base->GetCachePercentFragmentation( uAppId, puPercentFragmented, pError );
}
SteamCallHandle_t CSteam006::DefragCaches(unsigned int uAppId, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->DefragCaches( uAppId, pError );
}
int CSteam006::IsFileNeededByApp(unsigned int uAppId, const string_t* cszFileName, unsigned int uArg1, unsigned int* puArg2, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->IsFileNeededByApp( uAppId, cszFileName, uArg1, puArg2, pError );
}
SteamCallHandle_t CSteam006::WaitForAppResources(unsigned int uAppId, const string_t* cszMasterList, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->WaitForAppResources( uAppId, cszMasterList, pError );
}

int CSteam006::ForceCellId(unsigned int uCellId, TSteamError* pError)
{
	BOOKKEEP_PROXY();
	LOG_FN();

	return base->ForceCellId( uCellId, pError );
}