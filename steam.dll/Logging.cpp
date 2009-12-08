

#include "Common.h"


HandleMap logMap;

ADV_PROXY( SteamHandle_t, SteamCreateLogContext, ( const char *cszName ), ( cszName ) )
	ADD_MAP_ENTRY( logMap, returnObj, cszName );
	Log( "SteamCreateLogContext( cszName = \"%s\" ) = 0x%x\n\n", callerModule.szModule, cszName, returnObj );
END_PROXY()

ADV_PROXY( int, SteamLog, ( SteamHandle_t hContext, const char *cszMsg ), ( hContext, cszMsg ) )
	HandleIterator iter = logMap.find( hContext );
	if ( iter == logMap.end() )
		Log( "SteamLog() - Warning, log context lookup failed!\n" );

	Log("SteamLog( hContext = [ 0x%x, \"%s\" ], cszMsg = \"%s\" ) = %d\n\n", callerModule.szModule, hContext, ( iter == logMap.end() ? "UNKNOWN LOG CONTEXT" : iter->second ), cszMsg, returnObj );
END_PROXY()

ADV_VOID_PROXY( void, SteamLogResourceLoadStarted, ( const char *cszMsg ), ( cszMsg ) )
	Log( "SteamLogResourceLoadStarted( cszMsg = \"%s\" )\n\n", callerModule.szModule, cszMsg );
END_VOID_PROXY()

ADV_VOID_PROXY( void, SteamLogResourceLoadFinished, ( const char *cszMsg ), ( cszMsg ) )
	Log( "SteamLogResourceLoadFinished( cszMSg = \"%s\" )\n\n", callerModule.szModule, cszMsg );
END_VOID_PROXY()
