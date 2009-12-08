

#include "Common.h"

BASIC_PROXY( void, SteamClearError, ( TSteamError *pError ), ( pError ) );

ADV_PROXY( int, InternalSteamNumClientsConnectedToEngine,( TSteamError *pError ), ( pError ) )
	Log(
		"InternalSteamNumClientsConnectedToEngine() = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, returnObj, FormatTSteamError( pError )
	);
END_PROXY()

ADV_PROXY( int, InternalSteamShouldShutdownEngine2, (), () )
	Log( "InternalSteamShouldShutdownEngine2() = %d\n\n", callerModule.szModule, returnObj );
END_PROXY()

BASIC_PROXY( int, SteamChangeOfflineStatus, ( TSteamOfflineStatus* pSteamOfflineStatus, TSteamError* pError ), ( pSteamOfflineStatus, pError ) );
ADV_PROXY( int, SteamGetOfflineStatus, ( TSteamOfflineStatus* pSteamOfflineStatus, TSteamError* pError ), ( pSteamOfflineStatus, pError ) )
	Log(
		"SteamGetOfflineStatus() = %d\n"
		"\t\tpOfflineStatus = %s\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, returnObj, FormatTSteamOfflineStatus( pSteamOfflineStatus ), FormatTSteamError( pError )
	);
END_PROXY()

BASIC_PROXY( SteamCallHandle_t, SteamUninstall, ( TSteamError *pError ), ( pError ) );

BASIC_PROXY( int, SteamWeakVerifyNewValveCDKey, (), () );
BASIC_PROXY( int, SteamGetEncryptedNewValveCDKey, ( const char *cszValveCDkey, int *pnGameCode, uint32 *puTerritoryCode, void *pUniqueSerialNumber ), ( cszValveCDkey, pnGameCode, puTerritoryCode, pUniqueSerialNumber ) );

// Encrypts machine-specific data from the machine that is executing.
BASIC_PROXY( ESteamError, SteamDecryptDataForThisMachine,
(
	const uint8 *pEncryptedData,	// [in]		The encrypted data to decrypt. This is usually stored as a hex string.
	uint32 uEncryptedDataSize,		// [in]		The size of the encrypted data in bytes. This is usually the number of characters in the hex string.
	uint8 *pDecryptedBuffer,		// [in/out]	The buffer to decrypt the data into.
	uint32 uDecryptedBufferSize,	// [in]		The size of the decryption buffer in bytes.
	uint32 *puDecryptedDataSize		// [out]	The number of bytes that were decrypted.
), ( pEncryptedData, uEncryptedDataSize, pDecryptedBuffer, uDecryptedBufferSize, puDecryptedDataSize ) );

// Decrypts machine-specific data from the machine that is executing.
BASIC_PROXY( ESteamError, SteamEncryptDataForThisMachine, 
(
	const uint8 *pPlaintextData,	// [in]		The plaintext data to encrypt.
	uint32 uPlaintextDataSize,		// [in]		The size of the plaintext data in bytes.
	uint8 *pEncryptedBuffer,		// [in/out]	The buffer to encrypt the data into.
	uint32 uEncryptedBufferSize,	// [in]		The size of the encryption buffer in bytes.
	uint32 *puEncryptedDataSize		// [out]	The number of bytes that were used in the encryption buffer.
), ( pPlaintextData, uPlaintextDataSize, pEncryptedBuffer, uEncryptedBufferSize, puEncryptedDataSize ) );

ADV_PROXY( const string_t*, SteamFindServersGetErrorString, (), () )
	Log( "SteamFindServersGetErrorString() = \"%s\"\n\n", callerModule.szModule, returnObj );
END_PROXY()

ADV_PROXY( int, SteamFindServersIterateServer, ( ESteamServerType eSteamServerType, unsigned int uIndex, char *szServerAddress, int iServerAddressChars ), ( eSteamServerType, uIndex, szServerAddress, iServerAddressChars ) )
	Log(
		"SteamFindServersIterateServer( eServerType = %s, uIndex = %u, iServerAddressChars = %u ) = %d\n"
		"\t\tszServerAddress = \"%s\"\n\n",
		callerModule.szModule, EnumString<ESteamServerType>::From( eSteamServerType ).c_str(), uIndex, iServerAddressChars, returnObj, szServerAddress
	);
END_PROXY()

ADV_PROXY( int, SteamFindServersNumServers, ( ESteamServerType eSteamServerType ), ( eSteamServerType ) )
	Log( "SteamFindServersNumServers( eServerType = %s ) = %d\n\n", callerModule.szModule, EnumString<ESteamServerType>::From( eSteamServerType ).c_str(), returnObj );
END_PROXY()

BASIC_PROXY( int, SteamGetContentServerInfo, ( unsigned int uArg1, unsigned int* puArg2, unsigned int* puArg3, TSteamError *pError ), ( uArg1, puArg2, puArg3, pError ) );

BASIC_PROXY( int, SteamRefreshMinimumFootprintFiles, (), () );

ADV_PROXY( int, SteamSetNotificationCallback, ( SteamNotificationCallback_t pCallbackFunction, TSteamError *pError ), ( pCallbackFunction, pError ) )
	Log(
		"SteamSetNotificationCallback( pCallbackFunction = 0x%x ) = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, pCallbackFunction, returnObj, FormatTSteamError( pError )
	);
END_PROXY()

ADV_PROXY( int, SteamIsUsingSdkContentServer, ( int unknown, TSteamError *pError ), ( unknown, pError ) )
#ifdef LOGGING_VERBOSE
	Log(
		"SteamIsUsingSdkContentServer( unknown = %d ) = %d\n"
		"\t\tpError = %s\n\n",
		callerModule.szModule, unknown, returnObj, FormatTSteamError( pError )
	);
#endif
END_PROXY()

BASIC_PROXY( int, SteamForceCellId, ( CellID_t cellId, TSteamError *pError ), ( cellId, pError ) );