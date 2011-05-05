//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#ifndef ISTEAMBILLING002_H
#define ISTEAMBILLING002_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "BillingCommon.h"

//-----------------------------------------------------------------------------
// Purpose: interface to billing
//-----------------------------------------------------------------------------
abstract_class OBSOLETE_INTERFACE ISteamBilling002
{
public:

	virtual unknown_ret InitCreditCardPurchase( int, uint32, bool ) = 0;
	virtual unknown_ret InitPayPalPurchase( int ) = 0;

	virtual unknown_ret GetActivationCodeInfo( const char* ) = 0;
	virtual unknown_ret PurchaseWithActivationCode( const char* ) = 0;

	virtual unknown_ret GetFinalPrice( void ) = 0;

	virtual unknown_ret CancelPurchase( void ) = 0;
	virtual unknown_ret CompletePurchase( void ) = 0;

	virtual unknown_ret UpdateCardInfo( uint32 ) = 0;

	virtual unknown_ret DeleteCard( uint32 ) = 0;

	virtual unknown_ret GetCardList( void ) = 0;

	virtual unknown_ret GetLicenses( void ) = 0;

	virtual unknown_ret CancelLicense( int, int ) = 0;

	virtual unknown_ret GetPurchaseReceipts( bool ) = 0;
	virtual unknown_ret AcknowledgePurchaseReceipt( uint32 ) = 0;

	// Sets the billing address in the ISteamBilling object for use by other ISteamBilling functions (not stored on server)
	virtual bool SetBillingAddress( uint32, const char *pchName, const char *pchAddress1, const char *pchAddress2, const char *pchCity, const char *pchPostcode, const char *pchState, const char *pchCountry, const char *pchPhone) = 0;

	// Gets any previous set billing address in the ISteamBilling object (not stored on server)
	virtual bool GetBillingAddress( uint32, char *pchName, char *pchAddress1, char *pchAddress2, char *pchCity, char *pchPostcode, char *pchState, char *pchCountry, char *pchPhone) = 0;

	// Sets the billing address in the ISteamBilling object for use by other ISteamBilling functions (not stored on server)
	virtual bool SetShippingAddress( const char *pchName, const char *pchAddress1, const char *pchAddress2, const char *pchCity, const char *pchPostcode, const char *pchState, const char *pchCountry, const char *pchPhone, const char *) = 0;
	// Gets any previous set billing address in the ISteamBilling object (not stored on server)
	virtual bool GetShippingAddress( char *pchName, char *pchAddress1, char *pchAddress2, char *pchCity, char *pchPostcode, char *pchState, char *pchCountry, char *pchPhone) = 0;

	// Sets the credit card info in the ISteamBilling object for use by other ISteamBilling functions  (may eventually also be stored on server)
	virtual bool SetCardInfo( uint32, ECreditCardType eCreditCardType, const char *pchCardNumber, const char *pchCardHolderName, const char *pchCardExpYear, const char *pchCardExpMonth, const char *pchCardCVV2, const char *) = 0;
	// Gets any credit card info in the ISteamBilling object (not stored on server)
	virtual bool GetCardInfo( uint32, ECreditCardType *eCreditCardType, char *pchCardNumber, char *pchCardHolderName, char *pchCardExpYear, char *pchCardExpMonth, char *pchCardCVV2, char *) = 0;

	virtual uint32 GetLicensePackageID( uint32 licenseId ) = 0;
	virtual RTime32 GetLicenseTimeCreated( uint32 licenseId ) = 0;
	virtual unknown_ret GetLicenseTimeNextProcess( uint32 licenseId ) = 0;
	virtual uint32 GetLicenseMinuteLimit( uint32 licenseId ) = 0;
	virtual uint32 GetLicenseMinutesUsed( uint32 licenseId ) = 0;
	virtual EPaymentMethod GetLicensePaymentMethod( uint32 licenseId ) = 0;
	virtual ELicenseFlags GetLicenseFlags( uint32 licenseId ) = 0;
	virtual const char *GetLicensePurchaseCountryCode( uint32 licenseId ) = 0;

	virtual unknown_ret GetReceiptPackageID( uint32 ) = 0;
	virtual unknown_ret GetReceiptStatus( uint32 ) = 0;
	virtual unknown_ret GetReceiptResultDetail( uint32 ) = 0;
	virtual RTime32 GetReceiptTransTime( uint32 ) = 0;
	virtual unknown_ret GetReceiptTransID( uint32 ) = 0;
	virtual bool GetReceiptAcknowledged( uint32 ) = 0;
	virtual EPaymentMethod GetReceiptPaymentMethod( uint32 ) = 0;
	virtual uint32 GetReceiptBaseCost( uint32 ) = 0;
	virtual uint32 GetReceiptTotalDiscount( uint32 ) = 0;
	virtual uint32 GetReceiptTax( uint32 ) = 0;
	virtual uint32 GetReceiptShipping( uint32 ) = 0;
	virtual const char *GetReceiptCountryCode( uint32 ) = 0;

	virtual uint32 GetNumLicenses( void ) = 0;
	virtual uint32 GetNumReceipts( void ) = 0;

	virtual unknown_ret PurchaseWithMachineID( int, const char* ) = 0;

	virtual unknown_ret InitClickAndBuyPurchase( int, int64, const char*, const char* ) = 0;

	virtual unknown_ret GetPreviousClickAndBuyAccount( int64 *, char *, char * ) = 0;

};


#endif // ISTEAMBILLING002_H

