

#include "Common.h"

HandleMap callMap;

// in non-verbose mode, these callhandles are ignored
#define IGNORE_VERBOSE() \
	if ( iter != callMap.end() ) \
	{ \
		if ( strstr( iter->second, "SteamGetAppCacheSize" ) != NULL ) \
			return returnObj; \
	}

ADV_PROXY( int, SteamProcessCall, ( SteamCallHandle_t handle, TSteamProgress *pProgress, TSteamError *pError ), ( handle, pProgress, pError ) )
	HandleIterator iter = callMap.find( handle );
	if ( iter == callMap.end() )
		Log( "SteamProcessCall() - Warning, unable to look up call handle!!\n" );

	#ifndef LOGGING_VERBOSE
		IGNORE_VERBOSE();
	#endif

	Log(
		"SteamProcessCall( handle = [ 0x%x, \"%s\" ] ) = %d\n"
		"\t\tpProgress = %s\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, handle, ( iter == callMap.end() ? "UNKNOWN CALL HANDLE" : iter->second ), returnObj, FormatTSteamProgress( pProgress ), FormatTSteamError( pError )
	);
END_PROXY()

ADV_PROXY( int, SteamAbortCall, ( SteamCallHandle_t handle, TSteamError *pError ), ( handle, pError ) )
	HandleIterator iter = callMap.find( handle );
	if ( iter == callMap.end() )
		Log( "SteamAbortCall() - Warning, unable to look up call handle!!\n" );

	#ifndef LOGGING_VERBOSE
		IGNORE_VERBOSE();
	#endif

	Log(
		"SteamAbortCall( handle = [ 0x%x, \"%s\" ] ) = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, handle, ( iter == callMap.end() ? "UNKNOWN CALL HANDLE" : iter->second ), returnObj, FormatTSteamError( pError )
	);
END_PROXY()

ADV_PROXY( int, SteamBlockingCall, ( SteamCallHandle_t handle, uint32 uiProcessTickMS, TSteamError *pError ), ( handle, uiProcessTickMS, pError ) )
	HandleIterator iter = callMap.find( handle );
	if ( iter == callMap.end() )
		Log( "SteamBlockingCall() - Warning, unable to look up call handle!!\n" );

	#ifndef LOGGING_VERBOSE
		IGNORE_VERBOSE();
	#endif

	Log(
		"SteamBlockingCall( handle = [ 0x%x, \"%s\" ], uiProcessTickMS = %u ) = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, handle, ( iter == callMap.end() ? "UNKNOWN CALL HANDLE" : iter->second ), uiProcessTickMS, returnObj, FormatTSteamError( pError )
	);
END_PROXY()

ADV_PROXY( int, SteamSetMaxStallCount, ( uint32 uNumStalls, TSteamError *pError ), ( uNumStalls, pError ) )
	Log(
		"SteamSetMaxStallCount( uNumStalls = %u ) = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uNumStalls, returnObj, FormatTSteamError( pError )
	);
END_PROXY()