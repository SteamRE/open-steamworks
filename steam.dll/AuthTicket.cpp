

#include "Common.h"

BASIC_PROXY( ESteamError, SteamGetEncryptedUserIDTicket, ( const void *pEncryptionKeyReceivedFromAppServer, unsigned int uEncryptionKeyLength, void *pOutputBuffer, unsigned int uSizeOfOutputBuffer, unsigned int *pReceiveSizeOfEncryptedTicket, TSteamError *pError ), ( pEncryptionKeyReceivedFromAppServer, uEncryptionKeyLength, pOutputBuffer, uSizeOfOutputBuffer, pReceiveSizeOfEncryptedTicket, pError ) );

BASIC_PROXY( ESteamError, SteamInitializeUserIDTicketValidator, ( const char *pszOptionalPublicEncryptionKeyFilename, const char *pszOptionalPrivateDecryptionKeyFilename, unsigned int ClientClockSkewToleranceInSeconds, unsigned int ServerClockSkewToleranceInSeconds, unsigned int MaxNumLoginsWithinClientClockSkewTolerancePerClient, unsigned int	HintPeakSimultaneousValidations, unsigned int AbortValidationAfterStallingForNProcessSteps ), ( pszOptionalPublicEncryptionKeyFilename, pszOptionalPrivateDecryptionKeyFilename, ClientClockSkewToleranceInSeconds, ServerClockSkewToleranceInSeconds, MaxNumLoginsWithinClientClockSkewTolerancePerClient, HintPeakSimultaneousValidations, AbortValidationAfterStallingForNProcessSteps ) );
BASIC_PROXY( ESteamError, SteamShutdownUserIDTicketValidator, (), () );

BASIC_PROXY( const unsigned char*, SteamGetEncryptionKeyToSendToNewClient, ( unsigned int *pReceiveSizeOfEncryptionKey ), ( pReceiveSizeOfEncryptionKey ) );

BASIC_PROXY( ESteamError, SteamStartValidatingUserIDTicket, ( void *pEncryptedUserIDTicketFromClient, unsigned int uSizeOfEncryptedUserIDTicketFromClient, unsigned int ObservedClientIPAddr, SteamUserIDTicketValidationHandle_t *pReceiveHandle ), ( pEncryptedUserIDTicketFromClient, uSizeOfEncryptedUserIDTicketFromClient, ObservedClientIPAddr, pReceiveHandle ) );
BASIC_PROXY( ESteamError, SteamStartValidatingNewValveCDKey, ( void *pEncryptedNewValveCDKeyFromClient, unsigned int uSizeOfEncryptedNewValveCDKeyFromClient, unsigned int ObservedClientIPAddr, struct sockaddr *pPrimaryValidateNewCDKeyServerSockAddr, struct sockaddr *pSecondaryValidateNewCDKeyServerSockAddr, SteamUserIDTicketValidationHandle_t *pReceiveHandle ), ( pEncryptedNewValveCDKeyFromClient, uSizeOfEncryptedNewValveCDKeyFromClient, ObservedClientIPAddr, pPrimaryValidateNewCDKeyServerSockAddr, pSecondaryValidateNewCDKeyServerSockAddr, pReceiveHandle ) );

BASIC_PROXY( ESteamError, SteamProcessOngoingUserIDTicketValidation, ( SteamUserIDTicketValidationHandle_t Handle, TSteamGlobalUserID *pReceiveValidSteamGlobalUserID, unsigned int *pReceiveClientLocalIPAddr, unsigned char *pOptionalReceiveProofOfAuthenticationToken, size_t SizeOfOptionalAreaToReceiveProofOfAuthenticationToken, size_t *pOptionalReceiveSizeOfProofOfAuthenticationToken ), ( Handle, pReceiveValidSteamGlobalUserID, pReceiveClientLocalIPAddr, pOptionalReceiveProofOfAuthenticationToken, SizeOfOptionalAreaToReceiveProofOfAuthenticationToken, pOptionalReceiveSizeOfProofOfAuthenticationToken ) );

BASIC_PROXY( void, SteamAbortOngoingUserIDTicketValidation, ( SteamUserIDTicketValidationHandle_t Handle ), ( Handle ) );

BASIC_PROXY( ESteamError, SteamOptionalCleanUpAfterClientHasDisconnected, ( unsigned int ObservedClientIPAddr, unsigned int ClientLocalIPAddr ), ( ObservedClientIPAddr, ClientLocalIPAddr ) );
