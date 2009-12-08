

#include "Common.h"

HandleMap fileMap;

ADV_PROXY( int, SteamMountAppFilesystem, ( TSteamError *pError ), ( pError ) )
	Log(
		"SteamMountAppFilesystem() = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, returnObj, FormatTSteamError( pError )
	);
END_PROXY()

ADV_PROXY( int, SteamUnmountAppFilesystem, ( TSteamError *pError ), ( pError ) )
	Log(
		"SteamUnmountAppFilesystem() = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, returnObj, FormatTSteamError( pError )
	);
END_PROXY()

ADV_PROXY( SteamHandle_t, SteamMountFilesystem, ( unsigned int uAppId, const char *szMountPath, TSteamError *pError ), ( uAppId, szMountPath, pError ) )
	ADD_MAP_ENTRY( fileMap, returnObj, szMountPath );
	Log(
		"SteamMountFilesystem( uAppId = %u, szMountPath = \"%s\" ) = 0x%x\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uAppId, szMountPath, returnObj, FormatTSteamError( pError )
	);
END_PROXY()

ADV_PROXY( int, SteamUnmountFilesystem, ( SteamHandle_t hFile, TSteamError *pError ), ( hFile, pError ) )
	HandleIterator iter = fileMap.find( hFile );
	if ( iter == fileMap.end() )
		Log( "SteamUnmountFilesystem() - Warning, file handle lookup failed!\n" );

	Log(
		"SteamUnmountFilesystem( hFile = [ 0x%x, \"%s\" ] ) = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, hFile, ( iter == fileMap.end() ? "UNKNOWN FILE HANDLE" : iter->second ), returnObj, FormatTSteamError( pError )
	);

	if ( iter != fileMap.end() )
		fileMap.erase( iter );
END_PROXY()

ADV_PROXY( SteamHandle_t, SteamOpenFileEx, ( const char *cszFileName, const char *cszMode, unsigned int *puSize, TSteamError *pError ), ( cszFileName, cszMode, puSize, pError ) )
	ADD_MAP_ENTRY( fileMap, returnObj, cszFileName );
	Log(
		"SteamOpenFileEx( cszFileName = \"%s\", cszMode = \"%s\" ) = %d\n"
		"\t\tpuSize = %u\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, cszFileName, cszMode, returnObj, *puSize, FormatTSteamError( pError )
	);
END_PROXY()

BASIC_PROXY( SteamHandle_t, SteamOpenFile, ( const char *cszName, const char *cszMode, TSteamError *pError ), ( cszName, cszMode, pError ) );
BASIC_PROXY( SteamHandle_t, SteamOpenFile64, ( const char *cszName, const char *cszMode, TSteamError *pError ), ( cszName, cszMode, pError ) );
BASIC_PROXY( SteamHandle_t, SteamOpenTmpFile, ( TSteamError *pError ), ( pError ) );

BASIC_PROXY( int, SteamFlushFile, ( SteamHandle_t hFile, TSteamError *pError ), ( hFile, pError ) );
BASIC_PROXY( int, SteamCloseFile, ( SteamHandle_t hFile, TSteamError *pError ), ( hFile, pError ) );

BASIC_PROXY( int, SteamSetvBuf, ( SteamHandle_t hFile, void* pBuf, ESteamBufferMethod eMethod, unsigned int uBytes, TSteamError *pError ), ( hFile, pBuf, eMethod, uBytes, pError ) );
BASIC_PROXY( int, SteamGetc, ( SteamHandle_t hFile, TSteamError *pError ), ( hFile, pError ) );
BASIC_PROXY( int, SteamPutc, ( int cChar, SteamHandle_t hFile, TSteamError *pError ), ( cChar, hFile, pError ) );

BASIC_PROXY( int, SteamPrintFile, ( SteamHandle_t hFile, TSteamError *pError, const char *cszFormat, ... ), ( hFile, pError, cszFormat ) );
BASIC_PROXY( unsigned int, SteamReadFile, ( void *pBuf, unsigned int uSize, unsigned int uCount, SteamHandle_t hFile, TSteamError *pError ), ( pBuf, uSize, uCount, hFile, pError ) );
BASIC_PROXY( unsigned int, SteamWriteFile, ( const void *pBuf, unsigned int uSize, unsigned int uCount, SteamHandle_t hFile, TSteamError *pError ), ( pBuf, uSize, uCount, hFile, pError ) );

BASIC_PROXY( int, SteamSeekFile, ( SteamHandle_t hFile, long lOffset, ESteamSeekMethod eSeekMethod, TSteamError *pError ), ( hFile, lOffset, eSeekMethod, pError ) ); 
BASIC_PROXY( long, SteamSizeFile, ( SteamHandle_t hFile, TSteamError *pError ), ( hFile, pError ) );
BASIC_PROXY( long long, SteamSizeFile64, ( SteamHandle_t hFile, TSteamError *pError ), ( hFile, pError ) );
BASIC_PROXY( long, SteamTellFile, ( SteamHandle_t hFile, TSteamError *pError ), ( hFile, pError ) );

BASIC_PROXY( int, SteamStat, ( const char *cszName, TSteamElemInfo *pInfo, TSteamError *pError ), ( cszName, pInfo, pError ) );

ADV_PROXY( SteamHandle_t, SteamFindFirst, ( const char *cszPattern, ESteamFindFilter eFilter, TSteamElemInfo *pFindInfo, TSteamError *pError ), ( cszPattern, eFilter, pFindInfo, pError ) )
	ADD_MAP_ENTRY( fileMap, returnObj, cszPattern );
	Log(
		"SteamFindFirst( cszPattern = \"%s\", eFilter = %s ) = 0x%x\n"
		"\t\tpFindInfo = %s\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, cszPattern, EnumString<ESteamFindFilter>::From( eFilter ).c_str(), returnObj, FormatTSteamElemInfo( pFindInfo ), FormatTSteamError( pError )
	);
END_PROXY()

BASIC_PROXY( int, SteamFindNext, ( SteamHandle_t hDirectory, TSteamElemInfo *pFindInfo, TSteamError *pError ), ( hDirectory, pFindInfo, pError ) );
BASIC_PROXY( int, SteamFindClose, ( SteamHandle_t hDirectory, TSteamError *pError ), ( hDirectory, pError ) );
BASIC_PROXY( SteamHandle_t, SteamFindFirst64, ( const char *cszPattern, ESteamFindFilter eFilter, TSteamElemInfo *pFindInfo, TSteamError *pError ), ( cszPattern, eFilter, pFindInfo, pError ) );
BASIC_PROXY( int, SteamFindNext64, ( SteamHandle_t hDirectory, TSteamElemInfo *pFindInfo, TSteamError *pError ), ( hDirectory, pFindInfo, pError ) );

BASIC_PROXY( int, SteamGetLocalFileCopy, ( const char *cszName, TSteamError *pError ), ( cszName, pError ) );

BASIC_PROXY( int, SteamIsFileImmediatelyAvailable, ( const char *cszName, TSteamError *pError ), ( cszName, pError ) );
BASIC_PROXY( int, SteamIsFileNeededByApp, ( unsigned int uAppId, const string_t* cszFileName, unsigned int uArg1, unsigned int* puArg2, TSteamError* pError ),
			( uAppId, cszFileName, uArg1, puArg2, pError ) );

BASIC_PROXY( int, SteamHintResourceNeed, ( const char *cszMountPath, const char *cszMasterList, int bForgetEverything, TSteamError *pError ), ( cszMountPath, cszMasterList, bForgetEverything, pError ) );
BASIC_PROXY( int, SteamForgetAllHints, ( const char *cszMountPath, TSteamError *pError ), ( cszMountPath, pError ) );

BASIC_PROXY( int, SteamPauseCachePreloading, ( const char *cszMountPath, TSteamError *pError ), ( cszMountPath, pError ) );
BASIC_PROXY( int, SteamResumeCachePreloading, ( const char *cszMountPath, TSteamError *pError ), ( cszMountPath, pError ) );

BASIC_PROXY( int, SteamDefragCaches, ( unsigned int uAppId, TSteamError* pError ), ( uAppId, pError ) );

BASIC_PROXY( int, SteamWaitForAppResources, ( unsigned int uAppId, const string_t* cszMasterList, TSteamError* pError ), ( uAppId, cszMasterList, pError ) );

ADV_PROXY( SteamCallHandle_t, SteamWaitForResources, ( const char *cszMountPath, const char *cszMasterList, TSteamError *pError ), ( cszMountPath, cszMasterList, pError ) )
	ADD_MAP_ENTRYF( callMap, returnObj, "SteamWaitForResources( cszMountPath = \"%s\" )", cszMountPath );
	Log(
		"SteamWaitForResources( cszMountPath = \"%s\", cszMasterList = \"%s\" ) = 0x%x\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, cszMountPath, cszMasterList, returnObj, FormatTSteamError( pError )
	);
END_PROXY()

BASIC_PROXY( SteamCallHandle_t, SteamFlushCache, ( unsigned int uAppId, TSteamError *pError ), ( uAppId, pError ) );

BASIC_PROXY( int, SteamGetCacheDecryptionKey, (unsigned int uAppId, char* szCacheDecryptionKey, unsigned int uBufferLength, unsigned int* puRecievedLength, TSteamError *pError), ( uAppId, szCacheDecryptionKey, uBufferLength, puRecievedLength, pError ) );
BASIC_PROXY( int, SteamGetCacheDefaultDirectory, ( char *szPath, TSteamError *pError ), ( szPath, pError ) );
BASIC_PROXY( int, SteamSetCacheDefaultDirectory, ( const char *szPath, TSteamError *pError ), ( szPath, pError ) );
BASIC_PROXY( int, SteamGetCacheFilePath, ( unsigned int uAppId,  char* szFilePath, unsigned int uBufferLength, unsigned int* puRecievedLength, TSteamError *pError ), ( uAppId, szFilePath, uBufferLength, puRecievedLength, pError ) );
BASIC_PROXY( int, SteamGetCachePercentFragmentation, ( unsigned int uAppId, unsigned int* puPercentFragmented, TSteamError* pError ), ( uAppId, puPercentFragmented, pError ) );

BASIC_PROXY( int, SteamIsFileNeededByCache, ( unsigned int uAppId, const string_t* cszFileName, unsigned int uArg3, TSteamError* pError), ( uAppId, cszFileName, uArg3, pError ) );

BASIC_PROXY( int, SteamRepairOrDecryptCaches, ( unsigned int uAppId, int iArg2, TSteamError *pError ), ( uAppId, iArg2, pError ) );

ADV_PROXY( int, SteamCreateCachePreloaders, ( TSteamError *pError ), ( pError ) )
	Log(
		"SteamCreateCachePreloaders() = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, returnObj, FormatTSteamError( pError )
	);
END_PROXY()

BASIC_PROXY( int, SteamIsCacheLoadingEnabled, ( unsigned int uAppId, int *pbIsLoading, TSteamError *pError ), ( uAppId, pbIsLoading, pError ) );

BASIC_PROXY( SteamCallHandle_t, SteamLoadCacheFromDir, ( unsigned int uAppId, const char *szPath, TSteamError *pError ), ( uAppId, szPath, pError ) );
BASIC_PROXY( int, SteamLoadFileToCache, ( unsigned int uArg1, const string_t* cszArg2, const void* pcvArg3, unsigned int uArg4, unsigned int uArg5, TSteamError *pError ), ( uArg1, cszArg2, pcvArg3, uArg4, uArg5, pError ) );

ADV_PROXY( SteamCallHandle_t, SteamStartLoadingCache, ( unsigned int uAppId, TSteamError *pError ), ( uAppId, pError ) )
	ADD_MAP_ENTRYF( callMap, returnObj, "StartLoadingCache( uAppId = %u )", uAppId );
	Log(
		"SteamStartLoadingCache( uAppId = %u ) = 0x%x\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uAppId, returnObj, FormatTSteamError( pError )
	);
END_PROXY()

BASIC_PROXY( SteamCallHandle_t, SteamStopLoadingCache, ( unsigned int uAppId, TSteamError *pError ), ( uAppId, pError ) );
