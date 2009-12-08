#pragma once

DEFINE_PROXY_CLASS(CSteam2Bridge002, ISteam2Bridge002)

	DECL_CLASS_PROXY(unknown_ret, SetSteam2Ticket, ( unsigned char *a, int b ))
			::Log("[%s]\tCSteam2Bridge002::SetSteam2Ticket( size = %d )\n", callerModule.szModule, b);
	RETURN_CLASS_PROXY(SetSteam2Ticket, (a, b))

	DECL_CLASS_PROXY(bool, SetAccountName, ( const char *szName ))
		::Log( "[%s]\tCSteam2Brige002::SetAccountName( szName = \"%s\" )\n", callerModule.szModule, szName );
	RETURN_CLASS_PROXY(SetAccountName, (szName))

	CLASS_PROXY(bool, SetPassword, ( const char *szPassword ), (szPassword))
	DECL_CLASS_PROXY(bool, SetAccountCreationTime, ( uint32 creationTime ))
		::Log("[%s]\tCSteam2Bridge002::SetAccountCreationTime( creationTime = %d )\n", callerModule.szModule, creationTime);
	RETURN_CLASS_PROXY(SetAccountCreationTime, (creationTime))

#undef CreateProcess // fuck you winbase.h
	CLASS_PROXY(unknown_ret, CreateProcess, ( void *a, uint32 b, char  const* c, char *d, uint32 e, void *f, char *g, uint32 h), (a, b, c, d, e, f, g, h))

	CLASS_PROXY(EUniverse, GetConnectedUniverse, (), ())
	CLASS_PROXY(const char *, GetIPCountry, (), ())

	CLASS_PROXY(uint32, GetNumLicenses,(), ())

	CLASS_PROXY(uint32, GetLicensePackageID,( uint32 licenseId ), (licenseId))
	CLASS_PROXY(uint32, GetLicenseTimeCreated,( uint32 licenseId ), (licenseId))
	CLASS_PROXY(unknown_ret, GetLicenseTimeNextProcess,( uint32 licenseId ), (licenseId))
	CLASS_PROXY(uint32, GetLicenseMinuteLimit,( uint32 licenseId ), (licenseId))
	CLASS_PROXY(uint32, GetLicenseMinutesUsed,( uint32 licenseId ), (licenseId))
	CLASS_PROXY(EPaymentMethod, GetLicensePaymentMethod,( uint32 licenseId ), (licenseId))
	CLASS_PROXY(ELicenseFlags, GetLicenseFlags,( uint32 licenseId ), (licenseId))
	CLASS_PROXY(const char *, GetLicensePurchaseCountryCode,( uint32 licenseId ), (licenseId))

	DECL_CLASS_PROXY(bool, SetOfflineMode, ( bool offlineMode ))
		::Log("[%s]\tCSteam2Bridge002::SetOfflinemode( bOfflineMode = %d )\n", callerModule.szModule, offlineMode);
	RETURN_CLASS_PROXY(SetOfflineMode, (offlineMode))

	CLASS_PROXY(unknown_ret, GetCurrentSessionToken, (), ())

	CLASS_PROXY(unknown_ret, SetCellID,( CellID_t cellId ), (cellId))

	DECL_CLASS_PROXY(unknown_ret, SetSteam2FullASTicket,( unsigned char *a, int b ))
		::Log("[%s]\tCSteam2Bridge002::SetSteam2FullASTicket( size = %d )\n", callerModule.szModule, b);
	RETURN_CLASS_PROXY( SetSteam2FullASTicket, (a, b))

	CLASS_PROXY(bool, UpdateAppOwnershipTicket,( uint32 a, bool b), (a, b))

	CLASS_PROXY(uint32, GetAppOwnershipTicketLength,( uint32 a ), (a))
	CLASS_PROXY(unknown_ret, GetAppOwnershipTicketData,( uint32 a, void *b, uint32 c ), (a, b, c))

	CLASS_PROXY(unknown_ret, GetAppDecryptionKey,( uint32 a, void *b, uint32 c), (a, b, c))
};