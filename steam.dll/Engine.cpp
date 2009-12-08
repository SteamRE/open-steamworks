

#include "Common.h"

ADV_PROXY( int, SteamStartEngine, ( TSteamError *pError ), ( pError ) )
	Log(
		"SteamStartEngine() = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, returnObj, FormatTSteamError( pError )
	);
END_PROXY()

ADV_PROXY( int, SteamStartup, ( uint32 uUsingMask, TSteamError *pError ), ( uUsingMask, pError ) )
	Log(
		"SteamStartup( uUsingMask = %u ) = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, uUsingMask, returnObj, FormatTSteamError( pError )
	);
END_PROXY()

ADV_PROXY( int, SteamGetVersion, ( char* szVersion, unsigned int uVersionBufSize ), ( szVersion, uVersionBufSize ) )
	Log(
		"SteamGetVersion( uVersionBufSize = %u ) = %d\n"
		"\t\tszVersion = \"%s\"\n\n",
		callerModule.szModule, uVersionBufSize, returnObj, szVersion
	);
END_PROXY()

ADV_PROXY( int, SteamGetLocalClientVersion, ( unsigned int* puArg1, unsigned int* puArg2, TSteamError *pError ), ( puArg1, puArg2, pError ) );
	Log(
		"SteamGetLocalClientVersion() = %d\n"
		"\t\tpuArg1 = %d\n"
		"\t\tpuArg2 = %d\n\n",
		callerModule.szModule, returnObj, *puArg1, *puArg2, FormatTSteamError( pError )
	);
END_PROXY()

ADV_PROXY( int, SteamCleanup, ( TSteamError *pError ), ( pError ) )
	Log(
		"SteamCleanup() = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, returnObj, FormatTSteamError( pError )
	);
END_PROXY()

ADV_PROXY( int, SteamShutdownEngine, ( TSteamError *pError ), ( pError ) )
	Log(
		"SteamShutdownEngine() = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, returnObj, FormatTSteamError( pError )
	);
END_PROXY()