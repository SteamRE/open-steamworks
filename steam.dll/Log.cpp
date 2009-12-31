
#include "Common.h"
#include "Log.h"

template <class T>
char Formatter<T>::privBuff[ FORMAT_MAX ];

template <class T>
char *Formatter<T>::From( T *type, char *format, ... )
{
	memset( privBuff, 0, FORMAT_MAX );

	va_list args;
	va_start( args, format );

	vsprintf( privBuff, format, args );

	va_end( args );

	return privBuff;
}

char *FormatTSteamError( TSteamError *error )
{
	return Formatter<TSteamError>::From(
		error,
		"TSteamError [ eSteamError = %s, eDetailedErrorType = %s, nDetailedErrorCode = %d, szDesc = \"%s\" ]",
		EnumString<ESteamError>::From( error->eSteamError ).c_str(), EnumString<EDetailedPlatformErrorType>::From( error->eDetailedErrorType ).c_str(), error->nDetailedErrorCode, error->szDesc
	);
}

char *FormatTSteamProgress( TSteamProgress *progress )
{
	return Formatter<TSteamProgress>::From(
		progress,
		"TSteamProgress [ bValid = %d, uPercentDone = %u, szProgress = \"%s\" ]",
		progress->bValid, progress->uPercentDone, progress->szProgress
	);
}

char *FormatTSteamOfflineStatus( TSteamOfflineStatus *status )
{
	return Formatter<TSteamOfflineStatus>::From(
		status,
		"TSteamOfflineStatus [ eOfflineNow = %d, eOfflineNextSession = %d ]",
		status->eOfflineNow, status->eOfflineNextSession
	);
}

char *FormatTSteamElemInfo( TSteamElemInfo *info )
{
	return Formatter<TSteamElemInfo>::From(
		info,
		"TSteamElemInfo [ bIsDir = %d, uSizeOrCount = %u, bIsLocal = %d, cszName = \"%s\", lastAccess = %u, lastModification = %u, creationTime = %u ]",
		info->bIsDir, info->uSizeOrCount, info->bIsLocal, info->cszName, info->lLastAccessTime, info->lLastModificationTime, info->lCreationTime
	);
}

char *FormatTSteamGlobalUserID( TSteamGlobalUserID *id )
{
	return Formatter<TSteamGlobalUserID>::From(
		id,
		"TSteamGlobalUserID [ m_SteamInstanceID = %u (0x%x), m_SteamLocalUserID = %lld (0x%llx) ]",
		id->m_SteamInstanceID, id->m_SteamInstanceID, id->m_SteamLocalUserID.As64bits, id->m_SteamLocalUserID.As64bits
	);
}

char *FormatTSteamApp( TSteamApp *app )
{
	return Formatter<TSteamApp>::From(
		app,
		"TSteamApp [ szName = \"%s\", szLatestVer = \"%s\", szCurrentVer = \"%s\", szInstallDir = \"%s\", uId = %u, uNumLaunchOptions = %u, uNumIcons = %u, uNumDependencies = %u ]",
		app->szName, app->szLatestVersionLabel, app->szCurrentVersionLabel, app->szInstallDirName, app->uId, app->uNumLaunchOptions, app->uNumIcons, app->uNumDependencies
	);
}

char *FormatTSteamAppStats( TSteamAppStats *appStats )
{
	return Formatter<TSteamAppStats>::From(
		appStats,
		"TSteamAppStats [ uNumApps = %u ]",
		appStats->uNumApps
	);
}

char *FormatTSteamAppDependencyInfo( TSteamAppDependencyInfo *appDep )
{
	return Formatter<TSteamAppDependencyInfo>::From(
		appDep,
		"TSteamAppDependencyInfo [ AppId = %u, IsRequired = %d, szMountName = \"%s\" ]",
		appDep->AppId, appDep->IsRequired, appDep->szMountName
	);
}

char *FormatTSteamSubscriptionStats( TSteamSubscriptionStats *subStats )
{
	return Formatter<TSteamSubscriptionStats>::From(
		subStats,
		"TSteamSubscriptionStats [ uNumSubscriptions = %u, uMaxApps = %u ]",
		subStats->uNumSubscriptions, subStats->uMaxApps
	);
}

char *FormatTSteamSubscription( TSteamSubscription *sub )
{
	return Formatter<TSteamSubscription>::From(
		sub,
		"TSteamSubscription [ szName = \"%s\", uId = %u, uNumApps = %u, eBillingType = %s, uCostCents = %u, uNumDiscounts = %u, bPreorder = %u, bShipping = %u, bCyberCafe = %d, uGameCode = %u, szGameCodeDesc = \"%s\", bDisabled = %d, bReqCD = %d, uTerrCode = %u, bSteam3 = %d  ]",
		sub->szName, sub->uId,  sub->uNumApps, EnumString<EBillingType>::From( sub->eBillingType ).c_str(), sub->uCostInCents, sub->uNumDiscounts, sub->bIsPreorder, sub->bRequiresShippingAddress, sub->bIsCyberCafeSubscription, sub->uGameCode, sub->szGameCodeDesc, sub->bIsDisabled, sub->bRequiresCD, sub->uTerritoryCode, sub->bIsSteam3Subscription
	);
}

char *FormatTSteamAppLaunchOption( TSteamAppLaunchOption *appLaunch )
{
	return Formatter<TSteamAppLaunchOption>::From(
		appLaunch,
		"TSteamAppLaunchOption [ szDesc = \"%s\", szCmdLine = \"%s\", uIndex = %u, uIconIndex = %u, bNoDesktopShortcut = %d, bNoStartMenuShortcut = %d, bIsLongRunning = %d ]",
		appLaunch->szDesc, appLaunch->szCmdLine, appLaunch->uIndex, appLaunch->uIconIndex, appLaunch->bNoDesktopShortcut, appLaunch->bNoStartMenuShortcut, appLaunch->bIsLongRunningUnattended
	);
}


void Log( const char *format, char *module, ... )
{
	if ( strcmp( module, "FileSystem_Steam.dll" ) == 0 )
		return;

	char buff[ LOG_BUFF_MAX ];
	memset( buff, 0, LOG_BUFF_MAX );

	va_list args;
	va_start( args, module );

	int written = vsprintf_s( buff, LOG_BUFF_MAX, format, args );
	if ( written == -1 )
		return;

	va_end( args );

	SYSTEMTIME time;
	GetLocalTime( &time );

	char logBuff[ LOG_LINE_MAX ];
	memset( logBuff, 0, LOG_LINE_MAX );

	written = sprintf_s( logBuff, LOG_LINE_MAX, "%02d:%02d:%02d:%03d\t[ %s ]\t%s", time.wHour, time.wMinute, time.wSecond, time.wMilliseconds, module, buff );
	if ( written == -1 )
		return;

	FILE *logFile = fopen( LOG_FILE, "a" );

	if ( !logFile )
		return;

	fwrite( logBuff, 1, written, logFile );
	fflush( logFile );

	fclose( logFile );

	printf_s( "%s", logBuff );
}

void Log( const char *msg )
{
	FILE *logFile = fopen( LOG_FILE, "a" );

	if ( !logFile )
		return;

	SYSTEMTIME time;
	GetLocalTime( &time );

	static char logBuff[ 2048 * 2 ];
	memset( logBuff, 0, 2048 * 2 );

	sprintf_s( logBuff, 2048 * 2, "%02d:%02d:%02d:%03d %s", time.wHour, time.wMinute, time.wSecond, time.wMilliseconds, msg );

	fputs( logBuff, logFile );

	fflush( logFile );
	fclose( logFile );

	printf( logBuff );
}