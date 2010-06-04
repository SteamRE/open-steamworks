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

#ifndef ICLIENTBILLING_H
#define ICLIENTBILLING_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "BillingCommon.h"


class UNSAFE_INTERFACE IClientBilling
{
public:
	virtual bool InitCreditCardPurchase( PackageId_t nPackageID, uint32 nCardIndex, bool bStoreCardInfo, uint32 nGiftID ) = 0;
	virtual bool InitPayPalPurchase( PackageId_t nPackageID, uint32 nGiftID ) = 0;

	virtual bool GetActivationCodeInfo( const char *pchActivationCode ) = 0;

	virtual bool PurchaseWithActivationCode( const char *pchActivationCode ) = 0;

	virtual bool GetFinalPrice() = 0;

	virtual bool CancelPurchase() = 0;
	virtual bool CompletePurchase() = 0;

	virtual bool UpdateCardInfo( uint32 nCardIndex ) = 0;
	virtual bool DeleteCard( uint32 nCardIndex ) = 0;

	virtual bool GetCardList() = 0;
	virtual bool Obsolete_GetLicenses() = 0;

	virtual bool CancelLicense( PackageId_t packageID, int32 nCancelReason ) = 0;

	virtual bool GetPurchaseReceipts( bool bUnacknowledgedOnly ) = 0;
	virtual bool AcknowledgePurchaseReceipt( uint32 nReceiptIndex ) = 0;

	virtual bool GetClickAndBuyVIPStatus() = 0;

	virtual bool SetBillingAddress( uint32 nCardIndex, const char *pchFirstName, const char *pchLastName, const char *pchAddress1, const char *pchAddress2, const char *pchCity, const char *pchPostcode, const char *pchState, const char *pchCountry, const char *pchPhone ) = 0;
	virtual bool GetBillingAddress( uint32 nCardIndex, char* pchFirstName, char* pchLastName, char* pchAddress1, char* pchAddress2, char* pchCity, char* pchPostcode, char* pchState, char* pchCountry, char* pchPhone ) = 0;

	virtual bool SetShippingAddress( const char *pchFirstName, const char *pchLastName, const char *pchAddress1, const char *pchAddress2, const char *pchCity, const char *pchPostcode, const char *pchState, const char *pchCountry, const char *pchPhone ) = 0;
	virtual bool GetShippingAddress( char* pchFirstName, char* pchLastName, char* pchAddress1, char* pchAddress2, char* pchCity, char* pchPostcode, char* pchState, char* pchCountry, char* pchPhone ) = 0;

	virtual bool SetCardInfo( uint32 nCardIndex, ECreditCardType eCreditCardType, const char *pchCardNumber, const char *pchCardHolderFirstName, const char *pchCardHolderLastName, const char *pchCardExpYear, const char *pchCardExpMonth, const char *pchCardCVV2 ) = 0;
	virtual bool GetCardInfo( uint32 nCardIndex, ECreditCardType *peCreditCardType, char* pchCardNumber, char* pchCardHolderFirstName, char* pchCardHolderLastName, char* pchCardExpYear, char* pchCardExpMonth, char* pchCardCVV2 ) = 0;

	virtual uint32 SetGiftInfo( const char *pchEmailGiftee, CSteamID steamIDGiftee, const char *pchGifteeName, const char *pchGiftMessage, const char *pchSentiment, const char *pchGiverSignature ) = 0;

	virtual PackageId_t GetLicensePackageID( uint32 nLicenseIndex ) = 0;
	virtual RTime32 GetLicenseTimeCreated( uint32 nLicenseIndex ) = 0;
	virtual RTime32 GetLicenseTimeNextProcess( uint32 nLicenseIndex ) = 0;
	virtual int32 GetLicenseMinuteLimit( uint32 nLicenseIndex ) = 0;
	virtual int32 GetLicenseMinutesUsed( uint32 nLicenseIndex ) = 0;
	virtual EPaymentMethod GetLicensePaymentMethod( uint32 nLicenseIndex ) = 0;
	virtual ELicenseFlags GetLicenseFlags( uint32 nLicenseIndex ) = 0;
	virtual const char *GetLicensePurchaseCountryCode( uint32 nLicenseIndex ) = 0;

	virtual PackageId_t GetReceiptPackageID( uint32 nReceiptIndex ) = 0;
	virtual EPurchaseStatus GetReceiptStatus( uint32 nReceiptIndex ) = 0;
	virtual EPurchaseResultDetail GetReceiptResultDetail( uint32 nReceiptIndex ) = 0;
	virtual RTime32 GetReceiptTransTime( uint32 nReceiptIndex ) = 0;
	virtual uint64 GetReceiptTransID( uint32 nReceiptIndex ) = 0;
	virtual bool GetReceiptAcknowledged( uint32 nReceiptIndex ) = 0;
	virtual EPaymentMethod GetReceiptPaymentMethod( uint32 nReceiptIndex ) = 0;
	virtual uint32 GetReceiptBaseCost( uint32 nReceiptIndex ) = 0;
	virtual uint32 GetReceiptTotalDiscount( uint32 nReceiptIndex ) = 0;
	virtual uint32 GetReceiptTax( uint32 nReceiptIndex ) = 0;
	virtual uint32 GetReceiptShipping( uint32 nReceiptIndex ) = 0;
	virtual ECurrencyCode GetReceiptCurrencyCode( uint32 nReceiptIndex ) = 0;
	virtual const char *GetReceiptCountryCode( uint32 nReceiptIndex ) = 0;

	virtual void Unknown() = 0;

	virtual uint32 GetNumLicenses() = 0;
	virtual uint32 GetNumReceipts() = 0;

	virtual bool PurchaseWithMachineID( PackageId_t nPackageID, const char *pchCustomData ) = 0;

	virtual bool InitClickAndBuyPurchase( PackageId_t nPackageID, int64 nAccountNum, const char *pchState, const char *pchCountryCode, uint32 nGiftID ) = 0;
	virtual bool GetPreviousClickAndBuyAccount( int64* pnAccountNum, char* pchState, char* pchCountryCode ) = 0;

	virtual bool GetReceiptCardInfo( uint32 nReceiptIndex, ECreditCardType* eCreditCardType, char* pchCardLast4Digits, char* pchCardHolderFirstName, char* pchCardHolderLastName, char* pchCardExpYear, char* pchCardExpMonth ) = 0;
	virtual bool GetReceiptBillingAddress( uint32 nReceiptIndex, char* pchFirstName, char* pchLastName, char* pchAddress1, char* pchAddress2, char* pchCity, char* pchPostcode, char* pchState, char* pchCountry, char* pchPhone ) = 0;
	virtual uint32 GetReceiptLineItemCount( uint32 nReceiptIndex ) = 0;
	virtual bool GetReceiptLineItemInfo( uint32 nReceiptIndex, uint32 nLineItemIndex, PackageId_t* nPackageID, uint32* nBaseCost, uint32* nDiscount, uint32* nTax, uint32* nShipping, ECurrencyCode* eCurrencyCode ) = 0;
	
	virtual void EnableTestLicense( uint32 ) = 0;
	virtual void DisableTestLicense( uint32 ) = 0;
};

#endif // ICLIENTBILLING_H
