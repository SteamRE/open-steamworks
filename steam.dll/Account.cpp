

#include "Common.h"


BASIC_PROXY( SteamCallHandle_t, SteamCreateAccount, ( const char *cszUser, const char *cszPassphrase, const char *cszCreationKey, const char *cszPersonalQuestion, const char *cszAnswerToQuestion, const string_t* cszArg6, int *pbCreated, TSteamError *pError ),
			( cszUser, cszPassphrase, cszCreationKey, cszPersonalQuestion, cszAnswerToQuestion, cszArg6, pbCreated, pError ) );
BASIC_PROXY( SteamCallHandle_t, SteamDeleteAccount, ( TSteamError *pError ), ( pError ) );

BASIC_PROXY( int, SteamChangeAccountName, ( const string_t* cszCurrentAccountName, const string_t* cszNewAccountName, TSteamError* pError ), ( cszCurrentAccountName, cszNewAccountName, pError ) );
BASIC_PROXY( SteamCallHandle_t, SteamChangeEmailAddress, ( const char *cszNewEmailAddress, int *pbChanged, TSteamError *pError ), ( cszNewEmailAddress, pbChanged, pError ) );
BASIC_PROXY( int, SteamChangeForgottenPassword, ( const string_t* cszArg1, const string_t* cszArg2, const string_t* cszArg3, const string_t* cszArg4, int* piArg5, TSteamError *pError ),
			( cszArg1, cszArg2, cszArg3, cszArg4, piArg5, pError ) );

BASIC_PROXY( SteamCallHandle_t, SteamChangePassword, ( const char *cszCurrentPassphrase, const char *cszNewPassphrase, int *pbChanged, TSteamError *pError ), ( cszCurrentPassphrase, cszNewPassphrase, pbChanged, pError ) );
BASIC_PROXY( SteamCallHandle_t, SteamChangePersonalQA, ( const char *cszCurrentPassphrase, const char *cszNewPersonalQuestion, const char *cszNewAnswerToQuestion, int *pbChanged, TSteamError *pError ), 
			( cszCurrentPassphrase, cszNewPersonalQuestion, cszNewAnswerToQuestion, pbChanged, pError ) );

ADV_PROXY( int, SteamEnumerateApp, ( unsigned int uAppId, TSteamApp *pApp, TSteamError *pError ), ( uAppId, pApp, pError ) )
#ifdef LOGGING_VERBOSE
	Log(
		"SteamEnumerateApp( uAppId = %u ) = %d\n"
		"\t\tpApp = %s\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uAppId, returnObj, FormatTSteamApp( pApp ), FormatTSteamError( pError )
	);
#endif
END_PROXY()

ADV_PROXY( int, SteamEnumerateAppDependency, ( unsigned int uAppId, unsigned int uDependency, TSteamAppDependencyInfo *pDependencyInfo, TSteamError *pError), ( uAppId, uDependency, pDependencyInfo, pError ) )
#ifdef LOGGING_VERBOSE
	Log(
		"SteamEnumerateAppDependency( uAppId = %u, uDependency = %u ) = %d\n"
		"\t\tpDependencyInfo = %s\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uAppId, uDependency, returnObj, FormatTSteamAppDependencyInfo( pDependencyInfo ), FormatTSteamError( pError )
	);
#endif
END_PROXY()

BASIC_PROXY( int, SteamEnumerateAppIcon, ( unsigned int uAppId, unsigned int uIconIndex, unsigned char *pIconData, unsigned int uIconDataBufSize, unsigned int *puSizeOfIconData, TSteamError *pError ), 
			( uAppId, uIconIndex, pIconData, uIconDataBufSize, puSizeOfIconData, pError ) );

ADV_PROXY( int, SteamEnumerateAppLaunchOption, ( unsigned int uAppId, unsigned int uLaunchOptionIndex, TSteamAppLaunchOption *pLaunchOption, TSteamError *pError ), ( uAppId, uLaunchOptionIndex, pLaunchOption, pError ) )
#ifdef LOGGING_VERBOSE
	Log(
		"SteamEnumerateAppLaunchOption( uAppId = %u, uLaunchOptionIndex = %u ) = %d\n"
		"\t\tpLaunchOption = %s\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uAppId, uLaunchOptionIndex, returnObj, FormatTSteamAppLaunchOption( pLaunchOption ), FormatTSteamError( pError )
	);
#endif
END_PROXY()
BASIC_PROXY( int, SteamEnumerateAppVersion, ( unsigned int uAppId, unsigned int uVersionIndex, TSteamAppVersion *pAppVersion, TSteamError *pError ),
			( uAppId, uVersionIndex, pAppVersion, pError ) );

ADV_PROXY( int, SteamEnumerateSubscription, ( unsigned int uSubscriptionId, TSteamSubscription *pSubscription, TSteamError *pError ), ( uSubscriptionId, pSubscription, pError ) )
#ifdef LOGGING_VERBOSE
	Log(
		"SteamEnumerateSubscription( uSubscriptionId = %u ) = %d\n"
		"\t\tpSubscription = %s\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uSubscriptionId, returnObj, FormatTSteamSubscription( pSubscription ), FormatTSteamError( pError )
	);
#endif
END_PROXY()

BASIC_PROXY( int, SteamEnumerateSubscriptionDiscount, ( unsigned int uSubscriptionId, unsigned int uDiscountIndex, TSteamSubscriptionDiscount* pSubscriptionDiscount, TSteamError *pError),
			( uSubscriptionId, uDiscountIndex, pSubscriptionDiscount, pError ) );
BASIC_PROXY( int, SteamEnumerateSubscriptionDiscountQualifier, ( unsigned int uSubscriptionId, unsigned int uDiscountIndex, unsigned int uQualifierIndex, TSteamDiscountQualifier* pDiscountQualifier, TSteamError *pError ),
			( uSubscriptionId, uDiscountIndex, uQualifierIndex, pDiscountQualifier, pError ) );

BASIC_PROXY( int, SteamGenerateSuggestedAccountNames, (const string_t* cszArg1, const string_t* cszArg2, char* szArg3, unsigned int uArg4, unsigned int* puArg5, TSteamError *pError),
			( cszArg1, cszArg2, szArg3, uArg4, puArg5, pError ) );

ADV_PROXY( int, SteamGetAccountStatus, ( unsigned int* puArg1, TSteamError *pError ), ( puArg1, pError ) )
	Log(
		"SteamGetAccountStatus() = %d\n"
		"\t\tpuArg1 = %u\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, returnObj, *puArg1, FormatTSteamError( pError )
	);
END_PROXY()

ADV_PROXY( SteamCallHandle_t, SteamGetAppCacheSize, ( unsigned int uAppId, unsigned int *pCacheSizeInMb, TSteamError *pError ), ( uAppId, pCacheSizeInMb, pError ) )
	ADD_MAP_ENTRYF( callMap, returnObj, "SteamGetAppCacheSize( uAppId = %u )", uAppId );
#ifdef LOGGING_VERBOSE
	Log(
		"SteamGetAppCacheSize( uAppId = %u ) = 0x%x\n"
		"\t\tpCacheSizeInMb = %u\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uAppId, returnObj, *pCacheSizeInMb, FormatTSteamError( pError )
	);
#endif
END_PROXY()

BASIC_PROXY( int, SteamGetAppDependencies, ( unsigned int uAppId, unsigned int* puDependecies, unsigned int uBufferLength, TSteamError *pError ), ( uAppId, puDependecies, uBufferLength, pError ) );

BASIC_PROXY( int, SteamGetAppDir, ( unsigned int uAppId, char* szAppDir, TSteamError *pError ), ( uAppId, szAppDir, pError ) );
BASIC_PROXY( int, SteamGetAppCacheDir, ( unsigned int uAppId, char *szPath, TSteamError *pError ), ( uAppId, szPath, pError ) );

ADV_PROXY( int, SteamGetAppIds, ( unsigned int *puIds, unsigned int uMaxIds, TSteamError *pError ), ( puIds, uMaxIds, pError ) )
	Log(
		"SteamGetAppIds( uMaxIds = %u ) = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uMaxIds, returnObj, FormatTSteamError( pError )
	);
END_PROXY()

BASIC_PROXY( int, SteamGetAppPurchaseCountry, ( unsigned int uAppID, char* szCountryCode, unsigned int a3, unsigned int* pPurchaseTime, TSteamError* pError ), ( uAppID, szCountryCode, a3, pPurchaseTime, pError ) );
BASIC_PROXY( int, SteamGetAppDLCStatus, ( int a, int b, int c, int d ), ( a, b, c, d ) );

ADV_PROXY( int, SteamGetAppStats, ( TSteamAppStats *pAppStats, TSteamError *pError ), ( pAppStats, pError ) )
	Log(
		"SteamGetAppStats() = %d\n"
		"\t\tpAppStats = %s\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, returnObj, FormatTSteamAppStats( pAppStats ), FormatTSteamError( pError )
	);
END_PROXY()

BASIC_PROXY( int, SteamGetAppUpdateStats, ( unsigned int uAppId, TSteamUpdateStats *pUpdateStats, TSteamError *pError ), ( uAppId, pUpdateStats, pError ) );

ADV_PROXY( int, SteamGetAppUserDefinedInfo, ( unsigned int uAppId, const char *cszPropertyName, char *szPropertyValue, unsigned int uBufSize, unsigned int *puPropertyValueLength, TSteamError *pError ), ( uAppId, cszPropertyName, szPropertyValue, uBufSize, puPropertyValueLength, pError ) )
#ifdef LOGGGING_VERBOSE
	Log(
		"SteamGetAppUserDefinedInfo( uAppId = %u, cszPropertyName = \"%s\", uBufSize = %u ) = %d\n"
		"\t\tcszPropertyValue = \"%s\"\n"
		"\t\tpuPropertyValueLength = %u\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uAppId, cszPropertyName, uBufSize, returnObj, szPropertyValue, *puPropertyValueLength, FormatTSteamError( pError )
	);
#else
	// steam asks for a gamedir for all apps, so these are ignored for non-verbose logging
	if ( strcmp( cszPropertyName, "gamedir" ) == 0 )
		return returnObj;

	Log(
		"SteamGetAppUserDefinedInfo( uAppId = %u, cszPropertyName = \"%s\", uBufSize = %u ) = %d\n"
		"\t\tcszPropertyValue = \"%s\"\n"
		"\t\tpuPropertyValueLength = %u\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uAppId, cszPropertyName, uBufSize, returnObj, szPropertyValue, *puPropertyValueLength, FormatTSteamError( pError )
	);
#endif
END_PROXY()

ADV_PROXY( int, SteamGetAppUserDefinedRecord, (unsigned int uAppId, KeyValueIteratorCallback_t AddEntryToKeyValueFunc, void* pvCKeyValue, TSteamError *pError), ( uAppId, AddEntryToKeyValueFunc, pvCKeyValue, pError ) )
	Log(
		"SteamGetAppUserDefinedRecord( uAppId = %u, AddEntryToKeValueFunc = 0x%x ) = %d\n"
		"\t\tpvCKeyValue = 0x%x\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uAppId, AddEntryToKeyValueFunc, returnObj, pvCKeyValue, FormatTSteamError( pError )
	);
END_PROXY()

ADV_PROXY( int, SteamGetCurrentEmailAddress, ( char *szEmailaddress, unsigned int uBufSize, unsigned int *puEmailaddressChars, TSteamError *pError ), ( szEmailaddress, uBufSize, puEmailaddressChars, pError ) )
	Log(
		"SteamGetCurrentEmailAddress( uBufSize = %u ) = %d\n"
		"\t\tszEmailaddress = \"%s\"\n"
		"\t\tpuEmailaddressChars = %u\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uBufSize, returnObj, szEmailaddress, *puEmailaddressChars, FormatTSteamError( pError )
	);
END_PROXY()

BASIC_PROXY( int, SteamGetNumAccountsWithEmailAddress, (), () );

BASIC_PROXY( int, SteamGetSponsorUrl, ( unsigned int uAppId, char *szUrl, unsigned int uBufSize, unsigned int *pUrlChars, TSteamError *pError ), ( uAppId, szUrl, uBufSize, pUrlChars, pError ) );

ADV_PROXY( int, SteamGetSubscriptionExtendedInfo, (unsigned int uSubscriptionId, const string_t* cszKeyName, char* szKeyValue, unsigned int uBufferLength, unsigned int* puRecievedLength, TSteamError *pError), ( uSubscriptionId, cszKeyName, szKeyValue, uBufferLength, puRecievedLength, pError ) )
	Log(
		"SteamGetSubscriptionExtendedInfo( uSubscriptioId = %u, cszKeyName = \"%s\", uBufferLength = %u ) = %d\n"
		"\t\tszKeyValue = \"%s\"\n"
		"\t\tpuRecievedLength = %u\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uSubscriptionId, cszKeyName, uBufferLength, returnObj, szKeyValue, *puRecievedLength, FormatTSteamError( pError )
	);
END_PROXY()

ADV_PROXY( int, SteamGetSubscriptionIds, ( unsigned int *puIds, unsigned int uMaxIds, TSteamError *pError ), ( puIds, uMaxIds, pError ) )
	Log(
		"SteamGetSubscriptionIds( uMaxIds = %u ) = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uMaxIds, returnObj, FormatTSteamError( pError )
	);
END_PROXY()

ADV_PROXY( int, SteamGetSubscriptionPurchaseCountry, ( unsigned int uSubscriptionId, char* szCountry, unsigned int uBufferLength , int* piRecievedLength, TSteamError *pError ), ( uSubscriptionId, szCountry, uBufferLength, piRecievedLength, pError ) )
	Log(
		"SteamGetSubscriptionPurchaseCountry( uSubscriptionId = %u, uBufferLength = %u ) = %d\n"
		"\t\tszCountry = \"%s\"\n"
		"\t\tpiRecievedLength = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uSubscriptionId, uBufferLength, returnObj, szCountry, *piRecievedLength, FormatTSteamError( pError )
	);
END_PROXY()

BASIC_PROXY( int, SteamGetSubscriptionReceipt, ( unsigned int uSubscriptionId , TSteamSubscriptionReceipt* pSubscriptionReceipt, TSteamError *pError ), 
			( uSubscriptionId, pSubscriptionReceipt, pError ) );

ADV_PROXY( int, SteamGetSubscriptionStats,( TSteamSubscriptionStats *pSubscriptionStats, TSteamError *pError ), ( pSubscriptionStats, pError ) )
	Log(
		"SteamGetSubscripionStats() = %d\n"
		"\t\tpSubscriptionStats = %s\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, returnObj, FormatTSteamSubscriptionStats( pSubscriptionStats ), FormatTSteamError( pError )
	);
END_PROXY()

BASIC_PROXY( int, SteamGetTotalUpdateStats, ( TSteamUpdateStats *pUpdateStats, TSteamError *pError ), ( pUpdateStats, pError ) );

ADV_PROXY( int, SteamGetUser, ( char *szUser, unsigned int uBufSize, unsigned int *puUserChars, TSteamGlobalUserID* pSteamGlobalUserID, TSteamError *pError ), ( szUser, uBufSize, puUserChars, pSteamGlobalUserID, pError ) )
	Log(
		"SteamGetUser( uBufSize = %u ) = %d\n"
		"\t\tszUser = \"%s\"\n"
		"\t\tpuUserChars = %u\n"
		"\t\tpSteamGlobalUserID = %s\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uBufSize, returnObj, szUser, *puUserChars, FormatTSteamGlobalUserID( pSteamGlobalUserID ), FormatTSteamError( pError )
	);
END_PROXY()

BASIC_PROXY( SteamCallHandle_t, SteamSetUser, ( const char *cszUser, int *pbUserSet, TSteamError *pError ), ( cszUser, pbUserSet, pError ) );

BASIC_PROXY( int, SteamGetUserType, ( unsigned int* puArg1, TSteamError* pError ), ( puArg1, pError ) );

BASIC_PROXY( int, SteamIsAccountNameInUse, ( const string_t* cszUser, int* pbInUse, TSteamError *pError ), ( cszUser, pbInUse, pError ) );

BASIC_PROXY( int, SteamIsAppSubscribed, ( unsigned int uAppId, int *pbIsAppSubscribed, int *pReserved, TSteamError *pError ), ( uAppId, pbIsAppSubscribed, pReserved, pError ) );

ADV_PROXY( int, SteamIsSubscribed, ( unsigned int uSubscriptionId, int *pbIsSubscribed, int *pReserved, TSteamError *pError ), ( uSubscriptionId, pbIsSubscribed, pReserved, pError ) )
#ifdef LOGGING_VERBOSE
	Log(
		"SteamIsSubscribed( uSubscriptionId = %u ) = %d\n"
		"\t\tpbIsSubscrubed = %d\n"
		"\t\tpReserved = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uSubscriptionId, returnObj, *pbIsSubscribed, *pReserved, FormatTSteamError( pError )
	);
#endif
END_PROXY()

BASIC_PROXY( int, SteamIsLoggedIn, ( int *pbIsLoggedIn, TSteamError *pError ), ( pbIsLoggedIn, pError ) );
BASIC_PROXY( int, SteamIsSecureComputer, ( int *pbIsSecure, TSteamError *pError ), ( pbIsSecure, pError ) );

BASIC_PROXY( SteamCallHandle_t, SteamLaunchApp, ( unsigned int uAppId, unsigned int uLaunchOption, const char *cszArgs, TSteamError *pError ), ( uAppId, uLaunchOption, cszArgs, pError ) );

ADV_PROXY( SteamCallHandle_t, SteamLogin, ( const char *cszUser, const char *cszPassphrase, int bIsSecureComputer, TSteamError *pError ), ( cszUser, cszPassphrase, bIsSecureComputer, pError ) )
	ADD_MAP_ENTRYF( callMap, returnObj, "SteamLogin( cszUser = \"%s\" )", cszUser  );
	Log(
		"SteamLogin( cszUser = \"%s\", cszPassphrase = \"*****\", bIsSecureComputer = %d ) = 0x%x\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, cszUser, bIsSecureComputer, returnObj, FormatTSteamError( pError )
	);
END_PROXY()

BASIC_PROXY( SteamCallHandle_t, SteamLogout, ( TSteamError *pError ), ( pError ) );

BASIC_PROXY( SteamCallHandle_t, SteamMoveApp, ( unsigned int uAppId, const char *szPath, TSteamError *pError ), ( uAppId, szPath, pError ) );

BASIC_PROXY( int, SteamRefreshAccountInfo, ( int arg1, TSteamError *pError ), ( arg1, pError ) );
BASIC_PROXY( int, SteamRefreshAccountInfo2, ( int a, int b, int c ), ( a, b, c ) );
BASIC_PROXY( int, SteamRefreshAccountInfoEx, (), () );

BASIC_PROXY( SteamCallHandle_t, SteamRefreshLogin, ( const char *cszPassphrase, int bIsSecureComputer, TSteamError *pError ), ( cszPassphrase, bIsSecureComputer, pError ) );

BASIC_PROXY( SteamCallHandle_t, SteamRequestAccountsByCdKeyEmail, ( const string_t* cszArg1, TSteamError *pError ), ( cszArg1, pError ) );
BASIC_PROXY( SteamCallHandle_t, SteamRequestAccountsByEmailAddressEmail, ( const string_t* cszArg1, TSteamError *pError ), ( cszArg1, pError ) );
BASIC_PROXY( SteamCallHandle_t, SteamRequestEmailAddressVerificationEmail, ( TSteamError* pError ), ( pError ) );
BASIC_PROXY( SteamCallHandle_t, SteamRequestForgottenPasswordEmail, ( const string_t* cszArg1, char* szArg2, TSteamError *pError ), ( cszArg1, szArg2, pError ) );

BASIC_PROXY( SteamCallHandle_t, SteamSubscribe, ( unsigned int uSubscriptionId, const TSteamSubscriptionBillingInfo *pSubscriptionBillingInfo, TSteamError *pError ), ( uSubscriptionId, pSubscriptionBillingInfo, pError ) );
BASIC_PROXY( SteamCallHandle_t, SteamUnsubscribe, ( unsigned int uSubscriptionId, TSteamError *pError ), ( uSubscriptionId, pError ) );

BASIC_PROXY( SteamCallHandle_t, SteamUpdateAccountBillingInfo, ( const TSteamPaymentCardInfo *pPaymentCardInfo, int *pbChanged, TSteamError *pError ), ( pPaymentCardInfo, pbChanged, pError ) );
BASIC_PROXY( SteamCallHandle_t, SteamUpdateSubscriptionBillingInfo, ( unsigned int uSubscriptionId, const TSteamSubscriptionBillingInfo *pSubscriptionBillingInfo, int *pbChanged, TSteamError *pError ),
			( uSubscriptionId, pSubscriptionBillingInfo, pbChanged, pError ) );

BASIC_PROXY( int, SteamVerifyEmailAddress, ( const string_t* cszEmailAddress, TSteamError* pError ), ( cszEmailAddress, pError ) );
BASIC_PROXY( int, SteamVerifyPassword, ( const string_t* cszArg1, int* piArg2, TSteamError* pError ), ( cszArg1, piArg2, pError ) );

BASIC_PROXY( SteamCallHandle_t, SteamWaitForAppReadyToLaunch, ( unsigned int uAppId, TSteamError *pError ), ( uAppId, pError ) );

BASIC_PROXY( int, SteamAckSubscriptionReceipt, ( unsigned int uArg1, TSteamError *pError ), ( uArg1, pError ) );
BASIC_PROXY( int, SteamSetSubscriptionReceipt, (), () );
BASIC_PROXY( int, SteamRemoveAppDependency, ( unsigned int uAppId, unsigned int uFileSystemIndex, TSteamError *pError ), ( uAppId, uFileSystemIndex, pError ) );
BASIC_PROXY( int, SteamInsertAppDependency, ( unsigned int uAppId, unsigned int uFileSystemIndex, TSteamAppDependencyInfo *pDependencyInfo, TSteamError *pError ), ( uAppId, uFileSystemIndex, pDependencyInfo, pError ) );

BASIC_PROXY( SteamCallHandle_t, SteamSetAppCacheSize,( unsigned int uAppId, unsigned int nCacheSizeInMb, TSteamError *pError ), ( uAppId, nCacheSizeInMb, pError ) );
BASIC_PROXY( SteamCallHandle_t, SteamSetAppVersion, ( unsigned int uAppId, unsigned int uAppVersionId, TSteamError *pError ), ( uAppId, uAppVersionId, pError ) );

ADV_PROXY( int, SteamNumAppsRunning, ( TSteamError *pError ), ( pError ) )
	Log(
		"SteamNumAppsRunning() = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, returnObj, FormatTSteamError( pError )
	);
END_PROXY()

BASIC_PROXY( int, SteamFindApp, ( const string_t* cszArg1, unsigned int* puArg2, TSteamError *pError ), ( cszArg1, puArg2, pError ) );

BASIC_PROXY( SteamCallHandle_t, SteamSetNewPassword, ( const char *cszUser, const char *cszAnswerToQuestion, const SteamSalt_t *cpSaltForAnswer, const char *cszNewPassphrase, int *pbChanged, TSteamError *pError ),
			( cszUser, cszAnswerToQuestion, cpSaltForAnswer, cszNewPassphrase, pbChanged, pError ) );
BASIC_PROXY( SteamCallHandle_t, SteamGetPersonalQuestion, ( const char *cszUser, SteamPersonalQuestion_t PersonalQuestion, SteamSalt_t *pSaltForAnswer, TSteamError *pError ),
			( cszUser, PersonalQuestion, pSaltForAnswer, pError ) );

BASIC_PROXY( SteamCallHandle_t, SteamEmailVerified, ( const char *cszEmailVerificationKey, int *pbVerified, TSteamError *pError ), ( cszEmailVerificationKey, pbVerified, pError ) );
BASIC_PROXY( SteamCallHandle_t, SteamSendVerificationEmail, ( int *pbSent, TSteamError *pError ), ( pbSent, pError ) );

ADV_PROXY( int, SteamWasBlobRegistryDeleted, (unsigned int unknown, TSteamError *pError), ( unknown, pError ) )
	Log(
		"SteamWasBlobRegistryDeleted( unknown = %u ) = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, unknown, returnObj, FormatTSteamError( pError )
	);
END_PROXY()