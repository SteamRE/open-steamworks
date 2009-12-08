

#include "Common.h"

ADV_PROXY( int, SteamWriteMiniDumpFromAssert, (unsigned int unknown1, unsigned int unknown2, unsigned int unknown3, const char *szMessage, const char *szFileName), ( unknown1, unknown2, unknown3, szMessage, szFileName ) );
	Log( "[%s]\tSteamWriteMiniDumpFromAssert( unknown1 = %u, unknown2 = %u, unknown3 = %u, szMessage = \"%s\", szFileName = \"%s\" ) = %d\n\n", callerModule.szModule, unknown1, unknown2, unknown3, szMessage, szFileName, returnObj );
END_PROXY()

ADV_PROXY( int, SteamWriteMiniDumpSetComment, (const string_t* cszComment), ( cszComment ) )
	Log( "[%s]\tSteamWriteMiniDumpSetComment( cszComment = \"%s\" ) = %d\n\n", callerModule.szModule, cszComment, returnObj );
END_PROXY()

BASIC_PROXY( int, SteamWriteMiniDumpUsingExceptionInfo, (), () );
BASIC_PROXY( int, SteamWriteMiniDumpUsingExceptionInfoWithBuildId, (), () );