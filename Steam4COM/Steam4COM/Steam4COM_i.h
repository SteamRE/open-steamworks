

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Sat Jan 09 16:03:31 2010
 */
/* Compiler settings for .\Steam4COM.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Steam4COM_i_h__
#define __Steam4COM_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISteamworks_FWD_DEFINED__
#define __ISteamworks_FWD_DEFINED__
typedef interface ISteamworks ISteamworks;
#endif 	/* __ISteamworks_FWD_DEFINED__ */


#ifndef __ISteamID_FWD_DEFINED__
#define __ISteamID_FWD_DEFINED__
typedef interface ISteamID ISteamID;
#endif 	/* __ISteamID_FWD_DEFINED__ */


#ifndef __IGameID_FWD_DEFINED__
#define __IGameID_FWD_DEFINED__
typedef interface IGameID IGameID;
#endif 	/* __IGameID_FWD_DEFINED__ */


#ifndef __Steamworks_FWD_DEFINED__
#define __Steamworks_FWD_DEFINED__

#ifdef __cplusplus
typedef class Steamworks Steamworks;
#else
typedef struct Steamworks Steamworks;
#endif /* __cplusplus */

#endif 	/* __Steamworks_FWD_DEFINED__ */


#ifndef __SteamID_FWD_DEFINED__
#define __SteamID_FWD_DEFINED__

#ifdef __cplusplus
typedef class SteamID SteamID;
#else
typedef struct SteamID SteamID;
#endif /* __cplusplus */

#endif 	/* __SteamID_FWD_DEFINED__ */


#ifndef __GameID_FWD_DEFINED__
#define __GameID_FWD_DEFINED__

#ifdef __cplusplus
typedef class GameID GameID;
#else
typedef struct GameID GameID;
#endif /* __cplusplus */

#endif 	/* __GameID_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ISteamworks_INTERFACE_DEFINED__
#define __ISteamworks_INTERFACE_DEFINED__

/* interface ISteamworks */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISteamworks;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E1930C46-5747-4069-8557-91A9F7A5D9C0")
    ISteamworks : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ISteamworksVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISteamworks * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISteamworks * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISteamworks * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISteamworks * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISteamworks * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISteamworks * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISteamworks * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ISteamworksVtbl;

    interface ISteamworks
    {
        CONST_VTBL struct ISteamworksVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISteamworks_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISteamworks_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISteamworks_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISteamworks_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISteamworks_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISteamworks_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISteamworks_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISteamworks_INTERFACE_DEFINED__ */


#ifndef __ISteamID_INTERFACE_DEFINED__
#define __ISteamID_INTERFACE_DEFINED__

/* interface ISteamID */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISteamID;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2C1BFF57-1DFF-486C-83C7-9A5F9C3C5D21")
    ISteamID : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ISteamIDVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISteamID * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISteamID * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISteamID * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISteamID * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISteamID * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISteamID * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISteamID * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ISteamIDVtbl;

    interface ISteamID
    {
        CONST_VTBL struct ISteamIDVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISteamID_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISteamID_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISteamID_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISteamID_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISteamID_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISteamID_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISteamID_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISteamID_INTERFACE_DEFINED__ */


#ifndef __IGameID_INTERFACE_DEFINED__
#define __IGameID_INTERFACE_DEFINED__

/* interface IGameID */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IGameID;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E03512EF-12F4-418C-8E1B-A7052B35BCE4")
    IGameID : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IGameIDVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGameID * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGameID * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGameID * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGameID * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGameID * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGameID * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGameID * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IGameIDVtbl;

    interface IGameID
    {
        CONST_VTBL struct IGameIDVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGameID_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGameID_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGameID_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGameID_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGameID_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGameID_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGameID_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGameID_INTERFACE_DEFINED__ */



#ifndef __Steam4COMLib_LIBRARY_DEFINED__
#define __Steam4COMLib_LIBRARY_DEFINED__

/* library Steam4COMLib */
/* [helpstring][version][uuid] */ 

#pragma once
typedef unsigned char uint8;

typedef signed char int8;

typedef short int16;

typedef unsigned short uint16;

typedef int int32;

typedef unsigned int uint32;

typedef long long int64;

typedef unsigned long long uint64;

typedef int intp;

typedef unsigned int uintp;

#pragma once
typedef 
enum EResult
    {	k_EResultOK	= 1,
	k_EResultFail	= 2,
	k_EResultNoConnection	= 3,
	k_EResultInvalidPassword	= 5,
	k_EResultLoggedInElsewhere	= 6,
	k_EResultInvalidProtocolVer	= 7,
	k_EResultInvalidParam	= 8,
	k_EResultFileNotFound	= 9,
	k_EResultBusy	= 10,
	k_EResultInvalidState	= 11,
	k_EResultInvalidName	= 12,
	k_EResultInvalidEmail	= 13,
	k_EResultDuplicateName	= 14,
	k_EResultAccessDenied	= 15,
	k_EResultTimeout	= 16,
	k_EResultBanned	= 17,
	k_EResultAccountNotFound	= 18,
	k_EResultInvalidSteamID	= 19,
	k_EResultServiceUnavailable	= 20,
	k_EResultNotLoggedOn	= 21,
	k_EResultPending	= 22,
	k_EResultEncryptionFailure	= 23,
	k_EResultInsufficientPrivilege	= 24,
	k_EResultLimitExceeded	= 25,
	k_EResultRevoked	= 26,
	k_EResultExpired	= 27,
	k_EResultAlreadyRedeemed	= 28,
	k_EResultDuplicateRequest	= 29,
	k_EResultAlreadyOwned	= 30,
	k_EResultIPNotFound	= 31,
	k_EResultPersistFailed	= 32,
	k_EResultLockingFailed	= 33,
	k_EResultLogonSessionReplaced	= 34,
	k_EResultConnectFailed	= 35,
	k_EResultHandshakeFailed	= 36,
	k_EResultIOFailure	= 37,
	k_EResultRemoteDisconnect	= 38,
	k_EResultShoppingCartNotFound	= 39,
	k_EResultBlocked	= 40,
	k_EResultIgnored	= 41,
	k_EResultNoMatch	= 42,
	k_EResultAccountDisabled	= 43,
	k_EResultServiceReadOnly	= 44
    } 	EResult;

typedef /* [hidden] */ struct ZZ_Lazy_EResult_t
    {
    unsigned char k_EResultOK;
    unsigned char k_EResultFail;
    unsigned char k_EResultNoConnection;
    unsigned char k_EResultInvalidPassword;
    unsigned char k_EResultLoggedInElsewhere;
    unsigned char k_EResultInvalidProtocolVer;
    unsigned char k_EResultInvalidParam;
    unsigned char k_EResultFileNotFound;
    unsigned char k_EResultBusy;
    unsigned char k_EResultInvalidState;
    unsigned char k_EResultInvalidName;
    unsigned char k_EResultInvalidEmail;
    unsigned char k_EResultDuplicateName;
    unsigned char k_EResultAccessDenied;
    unsigned char k_EResultTimeout;
    unsigned char k_EResultBanned;
    unsigned char k_EResultAccountNotFound;
    unsigned char k_EResultInvalidSteamID;
    unsigned char k_EResultServiceUnavailable;
    unsigned char k_EResultNotLoggedOn;
    unsigned char k_EResultPending;
    unsigned char k_EResultEncryptionFailure;
    unsigned char k_EResultInsufficientPrivilege;
    unsigned char k_EResultLimitExceeded;
    unsigned char k_EResultRevoked;
    unsigned char k_EResultExpired;
    unsigned char k_EResultAlreadyRedeemed;
    unsigned char k_EResultDuplicateRequest;
    unsigned char k_EResultAlreadyOwned;
    unsigned char k_EResultIPNotFound;
    unsigned char k_EResultPersistFailed;
    unsigned char k_EResultLockingFailed;
    unsigned char k_EResultLogonSessionReplaced;
    unsigned char k_EResultConnectFailed;
    unsigned char k_EResultHandshakeFailed;
    unsigned char k_EResultIOFailure;
    unsigned char k_EResultRemoteDisconnect;
    unsigned char k_EResultShoppingCartNotFound;
    unsigned char k_EResultBlocked;
    unsigned char k_EResultIgnored;
    unsigned char k_EResultNoMatch;
    unsigned char k_EResultAccountDisabled;
    unsigned char k_EResultServiceReadOnly;
    } 	ZZ_Lazy_EResult;

#pragma once
typedef 
enum EUniverse
    {	k_EUniverseInvalid	= 0,
	k_EUniversePublic	= 1,
	k_EUniverseBeta	= 2,
	k_EUniverseInternal	= 3,
	k_EUniverseDev	= 4,
	k_EUniverseRC	= 5,
	k_EUniverseMax	= ( k_EUniverseRC + 1 ) 
    } 	EUniverse;

typedef /* [hidden] */ struct ZZ_Lazy_EUniverse_t
    {
    unsigned char k_EUniverseInvalid;
    unsigned char k_EUniversePublic;
    unsigned char k_EUniverseBeta;
    unsigned char k_EUniverseInternal;
    unsigned char k_EUniverseDev;
    unsigned char k_EUniverseRC;
    unsigned char k_EUniverseMax;
    } 	ZZ_Lazy_EUniverse;

#pragma once
typedef 
enum EDenyReason
    {	k_EDenyInvalidVersion	= 1,
	k_EDenyGeneric	= 2,
	k_EDenyNotLoggedOn	= 3,
	k_EDenyNoLicense	= 4,
	k_EDenyCheater	= 5,
	k_EDenyLoggedInElseWhere	= 6,
	k_EDenyUnknownText	= 7,
	k_EDenyIncompatibleAnticheat	= 8,
	k_EDenyMemoryCorruption	= 9,
	k_EDenyIncompatibleSoftware	= 10,
	k_EDenySteamConnectionLost	= 11,
	k_EDenySteamConnectionError	= 12,
	k_EDenySteamResponseTimedOut	= 13,
	k_EDenySteamValidationStalled	= 14,
	k_EDenySteamOwnerLeftGuestUser	= 15
    } 	EDenyReason;

typedef /* [hidden] */ struct ZZ_Lazy_EDenyReason_t
    {
    unsigned char k_EDenyInvalidVersion;
    unsigned char k_EDenyGeneric;
    unsigned char k_EDenyNotLoggedOn;
    unsigned char k_EDenyNoLicense;
    unsigned char k_EDenyCheater;
    unsigned char k_EDenyLoggedInElseWhere;
    unsigned char k_EDenyUnknownText;
    unsigned char k_EDenyIncompatibleAnticheat;
    unsigned char k_EDenyMemoryCorruption;
    unsigned char k_EDenyIncompatibleSoftware;
    unsigned char k_EDenySteamConnectionLost;
    unsigned char k_EDenySteamConnectionError;
    unsigned char k_EDenySteamResponseTimedOut;
    unsigned char k_EDenySteamValidationStalled;
    unsigned char k_EDenySteamOwnerLeftGuestUser;
    } 	ZZ_Lazy_EDenyReason;

#pragma once
typedef 
enum EAccountType
    {	k_EAccountTypeInvalid	= 0,
	k_EAccountTypeIndividual	= 1,
	k_EAccountTypeMultiseat	= 2,
	k_EAccountTypeGameServer	= 3,
	k_EAccountTypeAnonGameServer	= 4,
	k_EAccountTypePending	= 5,
	k_EAccountTypeContentServer	= 6,
	k_EAccountTypeClan	= 7,
	k_EAccountTypeChat	= 8,
	k_EAccountTypeP2PSuperSeeder	= 9,
	k_EAccountTypeAnonUser	= 10,
	k_EAccountTypeMax	= ( k_EAccountTypeAnonUser + 1 ) 
    } 	EAccountType;

typedef /* [hidden] */ struct ZZ_Lazy_EAccountType_t
    {
    unsigned char k_EAccountTypeInvalid;
    unsigned char k_EAccountTypeIndividual;
    unsigned char k_EAccountTypeMultiseat;
    unsigned char k_EAccountTypeGameServer;
    unsigned char k_EAccountTypeAnonGameServer;
    unsigned char k_EAccountTypePending;
    unsigned char k_EAccountTypeContentServer;
    unsigned char k_EAccountTypeClan;
    unsigned char k_EAccountTypeChat;
    unsigned char k_EAccountTypeP2PSuperSeeder;
    unsigned char k_EAccountTypeAnonUser;
    unsigned char k_EAccountTypeMax;
    } 	ZZ_Lazy_EAccountType;

#pragma once
typedef 
enum ESteamUserStatType
    {	k_ESteamUserStatTypeINVALID	= 0,
	k_ESteamUserStatTypeINT	= 1,
	k_ESteamUserStatTypeFLOAT	= 2,
	k_ESteamUserStatTypeAVGRATE	= 3,
	k_ESteamUserStatTypeACHIEVEMENTS	= 4,
	k_ESteamUserStatTypeGROUPACHIEVEMENTS	= 5
    } 	ESteamUserStatType;

typedef /* [hidden] */ struct ZZ_Lazy_ESteamUserStatType_t
    {
    unsigned char k_ESteamUserStatTypeINVALID;
    unsigned char k_ESteamUserStatTypeINT;
    unsigned char k_ESteamUserStatTypeFLOAT;
    unsigned char k_ESteamUserStatTypeAVGRATE;
    unsigned char k_ESteamUserStatTypeACHIEVEMENTS;
    unsigned char k_ESteamUserStatTypeGROUPACHIEVEMENTS;
    } 	ZZ_Lazy_ESteamUserStatType;

#pragma once
typedef 
enum EChatEntryType
    {	k_EChatEntryTypeChatMsg	= 1,
	k_EChatEntryTypeTyping	= 2,
	k_EChatEntryTypeInviteGame	= 3,
	k_EChatEntryTypeEmote	= 4,
	k_EChatEntryTypeLobbyGameStart	= 5
    } 	EChatEntryType;

typedef /* [hidden] */ struct ZZ_Lazy_EChatEntryType_t
    {
    unsigned char k_EChatEntryTypeChatMsg;
    unsigned char k_EChatEntryTypeTyping;
    unsigned char k_EChatEntryTypeInviteGame;
    unsigned char k_EChatEntryTypeEmote;
    unsigned char k_EChatEntryTypeLobbyGameStart;
    } 	ZZ_Lazy_EChatEntryType;

#pragma once
typedef 
enum EChatRoomEnterResponse
    {	k_EChatRoomEnterResponseSuccess	= 1,
	k_EChatRoomEnterResponseDoesntExist	= 2,
	k_EChatRoomEnterResponseNotAllowed	= 3,
	k_EChatRoomEnterResponseFull	= 4,
	k_EChatRoomEnterResponseError	= 5,
	k_EChatRoomEnterResponseBanned	= 6
    } 	EChatRoomEnterResponse;

typedef /* [hidden] */ struct ZZ_Lazy_EChatRoomEnterResponse_t
    {
    unsigned char k_EChatRoomEnterResponseSuccess;
    unsigned char k_EChatRoomEnterResponseDoesntExist;
    unsigned char k_EChatRoomEnterResponseNotAllowed;
    unsigned char k_EChatRoomEnterResponseFull;
    unsigned char k_EChatRoomEnterResponseError;
    unsigned char k_EChatRoomEnterResponseBanned;
    } 	ZZ_Lazy_EChatRoomEnterResponse;

#pragma once
typedef 
enum EServerMode
    {	eServerModeInvalid	= 0,
	eServerModeNoAuthentication	= 1,
	eServerModeAuthentication	= 2,
	eServerModeAuthenticationAndSecure	= 3
    } 	EServerMode;

typedef /* [hidden] */ struct ZZ_Lazy_EServerMode_t
    {
    unsigned char eServerModeInvalid;
    unsigned char eServerModeNoAuthentication;
    unsigned char eServerModeAuthentication;
    unsigned char eServerModeAuthenticationAndSecure;
    } 	ZZ_Lazy_EServerMode;

#pragma once
typedef 
enum EFriendRelationship
    {	k_EFriendRelationshipNone	= 0,
	k_EFriendRelationshipBlocked	= 1,
	k_EFriendRelationshipRequestRecipient	= 2,
	k_EFriendRelationshipFriend	= 3,
	k_EFriendRelationshipRequestInitiator	= 4,
	k_EFriendRelationshipIgnored	= 5,
	k_EFriendRelationshipIgnoredFriend	= 6
    } 	EFriendRelationship;

typedef /* [hidden] */ struct ZZ_Lazy_EFriendRelationship_t
    {
    unsigned char k_EFriendRelationshipNone;
    unsigned char k_EFriendRelationshipBlocked;
    unsigned char k_EFriendRelationshipRequestRecipient;
    unsigned char k_EFriendRelationshipFriend;
    unsigned char k_EFriendRelationshipRequestInitiator;
    unsigned char k_EFriendRelationshipIgnored;
    unsigned char k_EFriendRelationshipIgnoredFriend;
    } 	ZZ_Lazy_EFriendRelationship;

#pragma once
typedef 
enum EPersonaState
    {	k_EPersonaStateOffline	= 0,
	k_EPersonaStateOnline	= 1,
	k_EPersonaStateBusy	= 2,
	k_EPersonaStateAway	= 3,
	k_EPersonaStateSnooze	= 4,
	k_EPersonaStateMax	= ( k_EPersonaStateSnooze + 1 ) 
    } 	EPersonaState;

typedef /* [hidden] */ struct ZZ_Lazy_EPersonaState_t
    {
    unsigned char k_EPersonaStateOffline;
    unsigned char k_EPersonaStateOnline;
    unsigned char k_EPersonaStateBusy;
    unsigned char k_EPersonaStateAway;
    unsigned char k_EPersonaStateSnooze;
    unsigned char k_EPersonaStateMax;
    } 	ZZ_Lazy_EPersonaState;

#pragma once
typedef 
enum k_EFriendFlags
    {	k_EFriendFlagNone	= 0,
	k_EFriendFlagBlocked	= 0x1,
	k_EFriendFlagFriendshipRequested	= 0x2,
	k_EFriendFlagImmediate	= 0x4,
	k_EFriendFlagClanMember	= 0x8,
	k_EFriendFlagOnGameServer	= 0x10,
	k_EFriendFlagRequestingFriendship	= 0x80,
	k_EFriendFlagRequestingInfo	= 0x100,
	k_EFriendFlagIgnored	= 0x200,
	k_EFriendFlagIgnoredFriend	= 0x400,
	k_EFriendFlagAll	= 0xffff
    } 	k_EFriendFlags;

typedef /* [hidden] */ struct ZZ_Lazy_k_EFriendFlags_t
    {
    unsigned char k_EFriendFlagNone;
    unsigned char k_EFriendFlagBlocked;
    unsigned char k_EFriendFlagFriendshipRequested;
    unsigned char k_EFriendFlagImmediate;
    unsigned char k_EFriendFlagClanMember;
    unsigned char k_EFriendFlagOnGameServer;
    unsigned char k_EFriendFlagRequestingFriendship;
    unsigned char k_EFriendFlagRequestingInfo;
    unsigned char k_EFriendFlagIgnored;
    unsigned char k_EFriendFlagIgnoredFriend;
    unsigned char k_EFriendFlagAll;
    } 	ZZ_Lazy_k_EFriendFlags;

#pragma once
typedef 
enum EPersonaChange
    {	k_EPersonaChangeName	= 0x1,
	k_EPersonaChangeStatus	= 0x2,
	k_EPersonaChangeComeOnline	= 0x4,
	k_EPersonaChangeGoneOffline	= 0x8,
	k_EPersonaChangeGamePlayed	= 0x10,
	k_EPersonaChangeGameServer	= 0x20,
	k_EPersonaChangeAvatar	= 0x40,
	k_EPersonaChangeJoinedSource	= 0x80,
	k_EPersonaChangeLeftSource	= 0x100,
	k_EPersonaChangeRelationshipChanged	= 0x200,
	k_EPersonaChangeNameFirstSet	= 0x400
    } 	EPersonaChange;

typedef /* [hidden] */ struct ZZ_Lazy_EPersonaChange_t
    {
    unsigned char k_EPersonaChangeName;
    unsigned char k_EPersonaChangeStatus;
    unsigned char k_EPersonaChangeComeOnline;
    unsigned char k_EPersonaChangeGoneOffline;
    unsigned char k_EPersonaChangeGamePlayed;
    unsigned char k_EPersonaChangeGameServer;
    unsigned char k_EPersonaChangeAvatar;
    unsigned char k_EPersonaChangeJoinedSource;
    unsigned char k_EPersonaChangeLeftSource;
    unsigned char k_EPersonaChangeRelationshipChanged;
    unsigned char k_EPersonaChangeNameFirstSet;
    } 	ZZ_Lazy_EPersonaChange;

#pragma once
typedef 
enum EFriendMsgType
    {	k_EFriendMsgTypeChat	= 1,
	k_EFriendMsgTypeTyping	= 2,
	k_EFriendMsgTypeInvite	= 3,
	k_EFriendMsgTypeChatSent	= 4
    } 	EFriendMsgType;

typedef /* [hidden] */ struct ZZ_Lazy_EFriendMsgType_t
    {
    unsigned char k_EFriendMsgTypeChat;
    unsigned char k_EFriendMsgTypeTyping;
    unsigned char k_EFriendMsgTypeInvite;
    unsigned char k_EFriendMsgTypeChatSent;
    } 	ZZ_Lazy_EFriendMsgType;

#pragma once
typedef 
enum ERegistrySubTree
    {	k_ERegistrySubTreeNews	= 0,
	k_ERegistrySubTreeApps	= 1,
	k_ERegistrySubTreeSubscriptions	= 2,
	k_ERegistrySubTreeGameServers	= 3,
	k_ERegistrySubTreeFriends	= 4,
	k_ERegistrySubTreeSystem	= 5
    } 	ERegistrySubTree;

typedef /* [hidden] */ struct ZZ_Lazy_ERegistrySubTree_t
    {
    unsigned char k_ERegistrySubTreeNews;
    unsigned char k_ERegistrySubTreeApps;
    unsigned char k_ERegistrySubTreeSubscriptions;
    unsigned char k_ERegistrySubTreeGameServers;
    unsigned char k_ERegistrySubTreeFriends;
    unsigned char k_ERegistrySubTreeSystem;
    } 	ZZ_Lazy_ERegistrySubTree;

#pragma once
typedef 
enum EAppUsageEvent
    {	k_EAppUsageEventGameLaunch	= 1,
	k_EAppUsageEventGameLaunchTrial	= 2,
	k_EAppUsageEventMedia	= 3,
	k_EAppUsageEventPreloadStart	= 4,
	k_EAppUsageEventPreloadFinish	= 5,
	k_EAppUsageEventMarketingMessageView	= 6,
	k_EAppUsageEventInGameAdViewed	= 7,
	k_EAppUsageEventGameLaunchFreeWeekend	= 8
    } 	EAppUsageEvent;

typedef /* [hidden] */ struct ZZ_Lazy_EAppUsageEvent_t
    {
    unsigned char k_EAppUsageEventGameLaunch;
    unsigned char k_EAppUsageEventGameLaunchTrial;
    unsigned char k_EAppUsageEventMedia;
    unsigned char k_EAppUsageEventPreloadStart;
    unsigned char k_EAppUsageEventPreloadFinish;
    unsigned char k_EAppUsageEventMarketingMessageView;
    unsigned char k_EAppUsageEventInGameAdViewed;
    unsigned char k_EAppUsageEventGameLaunchFreeWeekend;
    } 	ZZ_Lazy_EAppUsageEvent;

#pragma once
typedef 
enum ELogonState
    {	k_ELogonStateNotLoggedOn	= 0,
	k_ELogonStateLoggingOn	= 1,
	k_ELogonStateLoggingOff	= 2,
	k_ELogonStateLoggedOn	= 3
    } 	ELogonState;

typedef /* [hidden] */ struct ZZ_Lazy_ELogonState_t
    {
    unsigned char k_ELogonStateNotLoggedOn;
    unsigned char k_ELogonStateLoggingOn;
    unsigned char k_ELogonStateLoggingOff;
    unsigned char k_ELogonStateLoggedOn;
    } 	ZZ_Lazy_ELogonState;

#pragma once
typedef 
enum EVACBan
    {	k_EVACBanGoldsrc	= 0,
	k_EVACBanSource	= ( k_EVACBanGoldsrc + 1 ) ,
	k_EVACBanDayOfDefeatSource	= ( k_EVACBanSource + 1 ) 
    } 	EVACBan;

typedef /* [hidden] */ struct ZZ_Lazy_EVACBan_t
    {
    unsigned char k_EVACBanGoldsrc;
    unsigned char k_EVACBanSource;
    unsigned char k_EVACBanDayOfDefeatSource;
    } 	ZZ_Lazy_EVACBan;

#pragma once
typedef 
enum EItemRequestResult
    {	k_EItemRequestResultOK	= 0,
	k_EItemRequestResultDenied	= ( k_EItemRequestResultOK + 1 ) ,
	k_EItemRequestResultServerError	= ( k_EItemRequestResultDenied + 1 ) ,
	k_EItemRequestResultTimeout	= ( k_EItemRequestResultServerError + 1 ) ,
	k_EItemRequestResultInvalid	= ( k_EItemRequestResultTimeout + 1 ) ,
	k_EItemRequestResultNoMatch	= ( k_EItemRequestResultInvalid + 1 ) ,
	k_EItemRequestResultUnknownError	= ( k_EItemRequestResultNoMatch + 1 ) ,
	k_EItemRequestResultNotLoggedOn	= ( k_EItemRequestResultUnknownError + 1 ) 
    } 	EItemRequestResult;

typedef /* [hidden] */ struct ZZ_Lazy_EItemRequestResult_t
    {
    unsigned char k_EItemRequestResultOK;
    unsigned char k_EItemRequestResultDenied;
    unsigned char k_EItemRequestResultServerError;
    unsigned char k_EItemRequestResultTimeout;
    unsigned char k_EItemRequestResultInvalid;
    unsigned char k_EItemRequestResultNoMatch;
    unsigned char k_EItemRequestResultUnknownError;
    unsigned char k_EItemRequestResultNotLoggedOn;
    } 	ZZ_Lazy_EItemRequestResult;

#pragma once
typedef 
enum EItemQuality
    {	k_EItemQuality_Normal	= 0,
	k_EItemQuality_Common	= ( k_EItemQuality_Normal + 1 ) ,
	k_EItemQuality_Rare	= ( k_EItemQuality_Common + 1 ) ,
	k_EItemQuality_Unique	= ( k_EItemQuality_Rare + 1 ) ,
	k_EItemQuality_Count	= ( k_EItemQuality_Unique + 1 ) ,
	k_EItemQuality_Unk5	= ( k_EItemQuality_Count + 1 ) ,
	k_EItemQuality_Unk6	= ( k_EItemQuality_Unk5 + 1 ) ,
	k_EItemQuality_Community	= ( k_EItemQuality_Unk6 + 1 ) ,
	k_EItemQuality_Valve	= ( k_EItemQuality_Community + 1 ) ,
	k_EItemQuality_Max	= 0xff
    } 	EItemQuality;

typedef /* [hidden] */ struct ZZ_Lazy_EItemQuality_t
    {
    unsigned char k_EItemQuality_Normal;
    unsigned char k_EItemQuality_Common;
    unsigned char k_EItemQuality_Rare;
    unsigned char k_EItemQuality_Unique;
    unsigned char k_EItemQuality_Count;
    unsigned char k_EItemQuality_Unk5;
    unsigned char k_EItemQuality_Unk6;
    unsigned char k_EItemQuality_Community;
    unsigned char k_EItemQuality_Valve;
    } 	ZZ_Lazy_EItemQuality;

#pragma once
typedef 
enum EMatchMakingServerResponse
    {	eServerResponded	= 0,
	eServerFailedToRespond	= ( eServerResponded + 1 ) ,
	eNoServersListedOnMasterServer	= ( eServerFailedToRespond + 1 ) 
    } 	EMatchMakingServerResponse;

typedef /* [hidden] */ struct ZZ_Lazy_EMatchMakingServerResponse_t
    {
    unsigned char eServerResponded;
    unsigned char eServerFailedToRespond;
    unsigned char eNoServersListedOnMasterServer;
    } 	ZZ_Lazy_EMatchMakingServerResponse;

#pragma once
typedef 
enum EMatchMakingType
    {	eInternetServer	= 0,
	eLANServer	= ( eInternetServer + 1 ) ,
	eFriendsServer	= ( eLANServer + 1 ) ,
	eFavoritesServer	= ( eFriendsServer + 1 ) ,
	eHistoryServer	= ( eFavoritesServer + 1 ) ,
	eSpectatorServer	= ( eHistoryServer + 1 ) ,
	eInvalidServer	= ( eSpectatorServer + 1 ) 
    } 	EMatchMakingType;

typedef /* [hidden] */ struct ZZ_Lazy_EMatchMakingType_t
    {
    unsigned char eInternetServer;
    unsigned char eLANServer;
    unsigned char eFriendsServer;
    unsigned char eFavoritesServer;
    unsigned char eHistoryServer;
    unsigned char eSpectatorServer;
    unsigned char eInvalidServer;
    } 	ZZ_Lazy_EMatchMakingType;

#pragma once
typedef 
enum EPaymentMethod
    {	k_EPaymentMethodNone	= 0,
	k_EPaymentMethodCDKey	= 0x1,
	k_EPaymentMethodCreditCard	= 0x2,
	k_EPaymentMethodPayPal	= 0x4,
	k_EPaymentMethodManual	= 0x8
    } 	EPaymentMethod;

typedef /* [hidden] */ struct ZZ_Lazy_EPaymentMethod_t
    {
    unsigned char k_EPaymentMethodNone;
    unsigned char k_EPaymentMethodCDKey;
    unsigned char k_EPaymentMethodCreditCard;
    unsigned char k_EPaymentMethodPayPal;
    unsigned char k_EPaymentMethodManual;
    } 	ZZ_Lazy_EPaymentMethod;

#pragma once
typedef 
enum ELicenseFlags
    {	k_ELicenseFlagRenew	= 0x1,
	k_ELicenseFlagRenewalFailed	= 0x2,
	k_ELicenseFlagPending	= 0x4,
	k_ELicenseFlagExpired	= 0x8,
	k_ELicenseFlagCancelledByUser	= 0x10,
	k_ELicenseFlagCancelledByAdmin	= 0x20
    } 	ELicenseFlags;

typedef /* [hidden] */ struct ZZ_Lazy_ELicenseFlags_t
    {
    unsigned char k_ELicenseFlagRenew;
    unsigned char k_ELicenseFlagRenewalFailed;
    unsigned char k_ELicenseFlagPending;
    unsigned char k_ELicenseFlagExpired;
    unsigned char k_ELicenseFlagCancelledByUser;
    unsigned char k_ELicenseFlagCancelledByAdmin;
    } 	ZZ_Lazy_ELicenseFlags;

#pragma once
typedef 
enum EPurchaseResultDetail
    {	k_EPurchaseResultNoDetail	= 0,
	k_EPurchaseResultAVSFailure	= 1,
	k_EPurchaseResultInsufficientFunds	= 2,
	k_EPurchaseResultContactSupport	= 3,
	k_EPurchaseResultTimeout	= 4,
	k_EPurchaseResultInvalidPackage	= 5,
	k_EPurchaseResultInvalidPaymentMethod	= 6,
	k_EPurchaseResultInvalidData	= 7,
	k_EPurchaseResultOthersInProgress	= 8,
	k_EPurchaseResultAlreadyPurchased	= 9,
	k_EPurchaseResultWrongPrice	= 10
    } 	EPurchaseResultDetail;

typedef /* [hidden] */ struct ZZ_Lazy_EPurchaseResultDetail_t
    {
    unsigned char k_EPurchaseResultNoDetail;
    unsigned char k_EPurchaseResultAVSFailure;
    unsigned char k_EPurchaseResultInsufficientFunds;
    unsigned char k_EPurchaseResultContactSupport;
    unsigned char k_EPurchaseResultTimeout;
    unsigned char k_EPurchaseResultInvalidPackage;
    unsigned char k_EPurchaseResultInvalidPaymentMethod;
    unsigned char k_EPurchaseResultInvalidData;
    unsigned char k_EPurchaseResultOthersInProgress;
    unsigned char k_EPurchaseResultAlreadyPurchased;
    unsigned char k_EPurchaseResultWrongPrice;
    } 	ZZ_Lazy_EPurchaseResultDetail;

#pragma once
typedef 
enum ESteamAPICallFailure
    {	k_ESteamAPICallFailureNone	= -1,
	k_ESteamAPICallFailureSteamGone	= 0,
	k_ESteamAPICallFailureNetworkFailure	= 1,
	k_ESteamAPICallFailureInvalidHandle	= 2,
	k_ESteamAPICallFailureMismatchedCallback	= 3
    } 	ESteamAPICallFailure;

typedef /* [hidden] */ struct ZZ_Lazy_ESteamAPICallFailure_t
    {
    unsigned char k_ESteamAPICallFailureNone;
    unsigned char k_ESteamAPICallFailureSteamGone;
    unsigned char k_ESteamAPICallFailureNetworkFailure;
    unsigned char k_ESteamAPICallFailureInvalidHandle;
    unsigned char k_ESteamAPICallFailureMismatchedCallback;
    } 	ZZ_Lazy_ESteamAPICallFailure;

#pragma once
typedef 
enum EAvatarSize
    {	k_EAvatarSize32x32	= 0,
	k_EAvatarSize64x64	= 1
    } 	EAvatarSize;

typedef /* [hidden] */ struct ZZ_Lazy_EAvatarSize_t
    {
    unsigned char k_EAvatarSize32x32;
    unsigned char k_EAvatarSize64x64;
    } 	ZZ_Lazy_EAvatarSize;

#pragma once
typedef 
enum ELobbyType
    {	k_ELobbyTypeFriendsOnly	= 1,
	k_ELobbyTypePublic	= 2
    } 	ELobbyType;

typedef /* [hidden] */ struct ZZ_Lazy_ELobbyType_t
    {
    unsigned char k_ELobbyTypeFriendsOnly;
    unsigned char k_ELobbyTypePublic;
    } 	ZZ_Lazy_ELobbyType;

#pragma once
typedef 
enum ELobbyComparison
    {	k_ELobbyComparisonEqualToOrLessThan	= -2,
	k_ELobbyComparisonLessThan	= -1,
	k_ELobbyComparisonEqual	= 0,
	k_ELobbyComparisonGreaterThan	= 1,
	k_ELobbyComparisonEqualToOrGreaterThan	= 2
    } 	ELobbyComparison;

typedef /* [hidden] */ struct ZZ_Lazy_ELobbyComparison_t
    {
    unsigned char k_ELobbyComparisonEqualToOrLessThan;
    unsigned char k_ELobbyComparisonLessThan;
    unsigned char k_ELobbyComparisonEqual;
    unsigned char k_ELobbyComparisonGreaterThan;
    unsigned char k_ELobbyComparisonEqualToOrGreaterThan;
    } 	ZZ_Lazy_ELobbyComparison;

#pragma once
typedef 
enum ESNetSocketState
    {	k_ESNetSocketStateInvalid	= 0,
	k_ESNetSocketStateConnected	= 1,
	k_ESNetSocketStateInitiated	= 10,
	k_ESNetSocketStateLocalCandidatesFound	= 11,
	k_ESNetSocketStateReceivedRemoteCandidates	= 12,
	k_ESNetSocketStateChallengeHandshake	= 15,
	k_ESNetSocketStateDisconnecting	= 21,
	k_ESNetSocketStateLocalDisconnect	= 22,
	k_ESNetSocketStateTimeoutDuringConnect	= 23,
	k_ESNetSocketStateRemoteEndDisconnected	= 24,
	k_ESNetSocketStateConnectionBroken	= 25
    } 	ESNetSocketState;

typedef /* [hidden] */ struct ZZ_Lazy_ESNetSocketState_t
    {
    unsigned char k_ESNetSocketStateInvalid;
    unsigned char k_ESNetSocketStateConnected;
    unsigned char k_ESNetSocketStateInitiated;
    unsigned char k_ESNetSocketStateLocalCandidatesFound;
    unsigned char k_ESNetSocketStateReceivedRemoteCandidates;
    unsigned char k_ESNetSocketStateChallengeHandshake;
    unsigned char k_ESNetSocketStateDisconnecting;
    unsigned char k_ESNetSocketStateLocalDisconnect;
    unsigned char k_ESNetSocketStateTimeoutDuringConnect;
    unsigned char k_ESNetSocketStateRemoteEndDisconnected;
    unsigned char k_ESNetSocketStateConnectionBroken;
    } 	ZZ_Lazy_ESNetSocketState;

#pragma once
typedef 
enum ESNetSocketConnectionType
    {	k_ESNetSocketConnectionTypeNotConnected	= 0,
	k_ESNetSocketConnectionTypeUDP	= 1,
	k_ESNetSocketConnectionTypeUDPRelay	= 2
    } 	ESNetSocketConnectionType;

typedef /* [hidden] */ struct ZZ_Lazy_ESNetSocketConnectionType_t
    {
    unsigned char k_ESNetSocketConnectionTypeNotConnected;
    unsigned char k_ESNetSocketConnectionTypeUDP;
    unsigned char k_ESNetSocketConnectionTypeUDPRelay;
    } 	ZZ_Lazy_ESNetSocketConnectionType;

#pragma once
typedef 
enum ELeaderboardDataRequest
    {	k_ELeaderboardDataRequestGlobal	= 0,
	k_ELeaderboardDataRequestGlobalAroundUser	= 1,
	k_ELeaderboardDataRequestFriends	= 2
    } 	ELeaderboardDataRequest;

typedef /* [hidden] */ struct ZZ_Lazy_ELeaderboardDataRequest_t
    {
    unsigned char k_ELeaderboardDataRequestGlobal;
    unsigned char k_ELeaderboardDataRequestGlobalAroundUser;
    unsigned char k_ELeaderboardDataRequestFriends;
    } 	ZZ_Lazy_ELeaderboardDataRequest;

#pragma once
typedef 
enum ELeaderboardSortMethod
    {	k_ELeaderboardSortMethodNone	= 0,
	k_ELeaderboardSortMethodAscending	= 1,
	k_ELeaderboardSortMethodDescending	= 2
    } 	ELeaderboardSortMethod;

typedef /* [hidden] */ struct ZZ_Lazy_ELeaderboardSortMethod_t
    {
    unsigned char k_ELeaderboardSortMethodNone;
    unsigned char k_ELeaderboardSortMethodAscending;
    unsigned char k_ELeaderboardSortMethodDescending;
    } 	ZZ_Lazy_ELeaderboardSortMethod;

#pragma once
typedef 
enum ELeaderboardDisplayType
    {	k_ELeaderboardDisplayTypeNone	= 0,
	k_ELeaderboardDisplayTypeNumeric	= 1,
	k_ELeaderboardDisplayTypeTimeSeconds	= 2,
	k_ELeaderboardDisplayTypeTimeMilliSeconds	= 3
    } 	ELeaderboardDisplayType;

typedef /* [hidden] */ struct ZZ_Lazy_ELeaderboardDisplayType_t
    {
    unsigned char k_ELeaderboardDisplayTypeNone;
    unsigned char k_ELeaderboardDisplayTypeNumeric;
    unsigned char k_ELeaderboardDisplayTypeTimeSeconds;
    unsigned char k_ELeaderboardDisplayTypeTimeMilliSeconds;
    } 	ZZ_Lazy_ELeaderboardDisplayType;

#pragma once
typedef 
enum EVoiceResult
    {	k_EVoiceResultOK	= 0,
	k_EVoiceResultNotInitialized	= 1,
	k_EVoiceResultNotRecording	= 2,
	k_EVoiceResultNoData	= 3,
	k_EVoiceResultBufferTooSmall	= 4,
	k_EVoiceResultDataCorrupted	= 5
    } 	EVoiceResult;

typedef /* [hidden] */ struct ZZ_Lazy_EVoiceResult_t
    {
    unsigned char k_EVoiceResultOK;
    unsigned char k_EVoiceResultNotInitialized;
    unsigned char k_EVoiceResultNotRecording;
    unsigned char k_EVoiceResultNoData;
    unsigned char k_EVoiceResultBufferTooSmall;
    unsigned char k_EVoiceResultDataCorrupted;
    } 	ZZ_Lazy_EVoiceResult;

#pragma once
typedef 
enum EBeginAuthSessionResult
    {	k_EBeginAuthSessionResultOK	= 0,
	k_EBeginAuthSessionResultInvalidTicket	= 1,
	k_EBeginAuthSessionResultDuplicateRequest	= 2,
	k_EBeginAuthSessionResultInvalidVersion	= 3,
	k_EBeginAuthSessionResultGameMismatch	= 4,
	k_EBeginAuthSessionResultExpiredTicket	= 5
    } 	EBeginAuthSessionResult;

typedef /* [hidden] */ struct ZZ_Lazy_EBeginAuthSessionResult_t
    {
    unsigned char k_EBeginAuthSessionResultOK;
    unsigned char k_EBeginAuthSessionResultInvalidTicket;
    unsigned char k_EBeginAuthSessionResultDuplicateRequest;
    unsigned char k_EBeginAuthSessionResultInvalidVersion;
    unsigned char k_EBeginAuthSessionResultGameMismatch;
    unsigned char k_EBeginAuthSessionResultExpiredTicket;
    } 	ZZ_Lazy_EBeginAuthSessionResult;

#pragma once
typedef 
enum EAuthSessionResponse
    {	k_EAuthSessionResponseOK	= 0,
	k_EAuthSessionResponseUserNotConnectedToSteam	= 1,
	k_EAuthSessionResponseNoLicenseOrExpired	= 2,
	k_EAuthSessionResponseVACBanned	= 3,
	k_EAuthSessionResponseLoggedInElseWhere	= 4,
	k_EAuthSessionResponseVACCheckTimedOut	= 5,
	k_EAuthSessionResponseAuthTicketCanceled	= 6,
	k_EAuthSessionResponseAuthTicketInvalidAlreadyUsed	= 7,
	k_EAuthSessionResponseAuthTicketInvalid	= 8
    } 	EAuthSessionResponse;

typedef /* [hidden] */ struct ZZ_Lazy_EAuthSessionResponse_t
    {
    unsigned char k_EAuthSessionResponseOK;
    unsigned char k_EAuthSessionResponseUserNotConnectedToSteam;
    unsigned char k_EAuthSessionResponseNoLicenseOrExpired;
    unsigned char k_EAuthSessionResponseVACBanned;
    unsigned char k_EAuthSessionResponseLoggedInElseWhere;
    unsigned char k_EAuthSessionResponseVACCheckTimedOut;
    unsigned char k_EAuthSessionResponseAuthTicketCanceled;
    unsigned char k_EAuthSessionResponseAuthTicketInvalidAlreadyUsed;
    unsigned char k_EAuthSessionResponseAuthTicketInvalid;
    } 	ZZ_Lazy_EAuthSessionResponse;

#pragma once
typedef 
enum ENotificationPosition
    {	k_EPositionTopLeft	= 0,
	k_EPositionTopRight	= 1,
	k_EPositionBottomLeft	= 2,
	k_EPositionBottomRight	= 3
    } 	ENotificationPosition;

typedef /* [hidden] */ struct ZZ_Lazy_ENotificationPosition_t
    {
    unsigned char k_EPositionTopLeft;
    unsigned char k_EPositionTopRight;
    unsigned char k_EPositionBottomLeft;
    unsigned char k_EPositionBottomRight;
    } 	ZZ_Lazy_ENotificationPosition;

#pragma once
typedef 
enum EItemCriteriaOperator
    {	k_EOperator_String_EQ	= 0,
	k_EOperator_Not	= ( k_EOperator_String_EQ + 1 ) ,
	k_EOperator_String_Not_EQ	= 1,
	k_EOperator_Float_EQ	= ( k_EOperator_String_Not_EQ + 1 ) ,
	k_EOperator_Float_Not_EQ	= ( k_EOperator_Float_EQ + 1 ) ,
	k_EOperator_Float_LT	= ( k_EOperator_Float_Not_EQ + 1 ) ,
	k_EOperator_Float_Not_LT	= ( k_EOperator_Float_LT + 1 ) ,
	k_EOperator_Float_LTE	= ( k_EOperator_Float_Not_LT + 1 ) ,
	k_EOperator_Float_Not_LTE	= ( k_EOperator_Float_LTE + 1 ) ,
	k_EOperator_Float_GT	= ( k_EOperator_Float_Not_LTE + 1 ) ,
	k_EOperator_Float_Not_GT	= ( k_EOperator_Float_GT + 1 ) ,
	k_EOperator_Float_GTE	= ( k_EOperator_Float_Not_GT + 1 ) ,
	k_EOperator_Float_Not_GTE	= ( k_EOperator_Float_GTE + 1 ) ,
	k_EOperator_Subkey_Contains	= ( k_EOperator_Float_Not_GTE + 1 ) ,
	k_EOperator_Subkey_Not_Contains	= ( k_EOperator_Subkey_Contains + 1 ) ,
	k_EItemCriteriaOperator_Count	= ( k_EOperator_Subkey_Not_Contains + 1 ) 
    } 	EItemCriteriaOperator;

typedef /* [hidden] */ struct ZZ_Lazy_EItemCriteriaOperator_t
    {
    unsigned char k_EOperator_String_EQ;
    unsigned char k_EOperator_Not;
    unsigned char k_EOperator_String_Not_EQ;
    unsigned char k_EOperator_Float_EQ;
    unsigned char k_EOperator_Float_Not_EQ;
    unsigned char k_EOperator_Float_LT;
    unsigned char k_EOperator_Float_Not_LT;
    unsigned char k_EOperator_Float_LTE;
    unsigned char k_EOperator_Float_Not_LTE;
    unsigned char k_EOperator_Float_GT;
    unsigned char k_EOperator_Float_Not_GT;
    unsigned char k_EOperator_Float_GTE;
    unsigned char k_EOperator_Float_Not_GTE;
    unsigned char k_EOperator_Subkey_Contains;
    unsigned char k_EOperator_Subkey_Not_Contains;
    unsigned char k_EItemCriteriaOperator_Count;
    } 	ZZ_Lazy_EItemCriteriaOperator;

#pragma once
typedef 
enum ESystemIMType
    {	k_ESystemIMRawText	= 0,
	k_ESystemIMInvalidCard	= 1,
	k_ESystemIMRecurringPurchaseFailed	= 2,
	k_ESystemIMCardWillExpire	= 3,
	k_ESystemIMSubscriptionExpired	= 4,
	k_ESystemIMTypeMax	= ( k_ESystemIMSubscriptionExpired + 1 ) 
    } 	ESystemIMType;

typedef /* [hidden] */ struct ZZ_Lazy_ESystemIMType_t
    {
    unsigned char k_ESystemIMRawText;
    unsigned char k_ESystemIMInvalidCard;
    unsigned char k_ESystemIMRecurringPurchaseFailed;
    unsigned char k_ESystemIMCardWillExpire;
    unsigned char k_ESystemIMSubscriptionExpired;
    } 	ZZ_Lazy_ESystemIMType;

#pragma once
typedef 
enum ENewsUpdateType
    {	k_EAppNews	= 0,
	k_ESteamAds	= 1,
	k_ESteamNews	= 2,
	k_ECDDBUpdate	= 3,
	k_EClientUpdate	= 4
    } 	ENewsUpdateType;

typedef /* [hidden] */ struct ZZ_Lazy_ENewsUpdateType_t
    {
    unsigned char k_EAppNews;
    unsigned char k_ESteamAds;
    unsigned char k_ESteamNews;
    unsigned char k_ECDDBUpdate;
    unsigned char k_EClientUpdate;
    } 	ZZ_Lazy_ENewsUpdateType;

#pragma once
typedef 
enum EAppState
    {	k_EAppStateDownloading	= 0,
	k_EAppStatePaused	= 1,
	k_EAppStateDownloadComplete	= 2
    } 	EAppState;

typedef /* [hidden] */ struct ZZ_Lazy_EAppState_t
    {
    unsigned char k_EAppStateDownloading;
    unsigned char k_EAppStatePaused;
    unsigned char k_EAppStateDownloadComplete;
    } 	ZZ_Lazy_EAppState;

#pragma once
typedef 
enum EPurchaseStatus
    {	k_EPurchasePending	= 0,
	k_EPurchaseSucceeded	= 1,
	k_EPurchaseFailed	= 2,
	k_EPurchaseRefunded	= 3,
	k_EPurchaseInit	= 4,
	k_EPurchaseChargedback	= 5,
	k_EPurchaseRevoked	= 6
    } 	EPurchaseStatus;

typedef /* [hidden] */ struct ZZ_Lazy_EPurchaseStatus_t
    {
    unsigned char k_EPurchasePending;
    unsigned char k_EPurchaseSucceeded;
    unsigned char k_EPurchaseFailed;
    unsigned char k_EPurchaseRefunded;
    unsigned char k_EPurchaseInit;
    unsigned char k_EPurchaseChargedback;
    unsigned char k_EPurchaseRevoked;
    } 	ZZ_Lazy_EPurchaseStatus;

#pragma once
typedef 
enum ECurrencyCode
    {	k_ECurrencyCodeInvalid	= 0,
	k_ECurrencyCodeUSD	= 1,
	k_ECurrencyCodeGBP	= 2,
	k_ECurrencyCodeEUR	= 3,
	k_ECurrencyCodeMax	= 4
    } 	ECurrencyCode;

typedef /* [hidden] */ struct ZZ_Lazy_ECurrencyCode_t
    {
    unsigned char k_ECurrencyCodeInvalid;
    unsigned char k_ECurrencyCodeUSD;
    unsigned char k_ECurrencyCodeGBP;
    unsigned char k_ECurrencyCodeEUR;
    unsigned char k_ECurrencyCodeMax;
    } 	ZZ_Lazy_ECurrencyCode;

#pragma once
typedef 
enum EConnectionPriority
    {	k_EConnectionPriorityLow	= 0,
	k_EConnectionPriorityMedium	= 1,
	k_EConnectionPriorityHigh	= 2
    } 	EConnectionPriority;

typedef /* [hidden] */ struct ZZ_Lazy_EConnectionPriority_t
    {
    unsigned char k_EConnectionPriorityLow;
    unsigned char k_EConnectionPriorityMedium;
    unsigned char k_EConnectionPriorityHigh;
    } 	ZZ_Lazy_EConnectionPriority;

#pragma once
typedef 
enum EDepotBuildStatus
    {	k_EDepotBuildStatusInvalid	= -1,
	k_EDepotBuildStatusFailed	= 0,
	k_EDepotBuildStatusProcessingConfig	= 1,
	k_EDepotBuildStatusProcessingData	= 2,
	k_EDepotBuildStatusUploadingData	= 3,
	k_EDepotBuildStatusCompleted	= 4
    } 	EDepotBuildStatus;

typedef /* [hidden] */ struct ZZ_Lazy_EDepotBuildStatus_t
    {
    unsigned char k_EDepotBuildStatusInvalid;
    unsigned char k_EDepotBuildStatusFailed;
    unsigned char k_EDepotBuildStatusProcessingConfig;
    unsigned char k_EDepotBuildStatusProcessingData;
    unsigned char k_EDepotBuildStatusUploadingData;
    unsigned char k_EDepotBuildStatusCompleted;
    } 	ZZ_Lazy_EDepotBuildStatus;

#pragma once
typedef 
enum EChatRoomType
    {	k_EChatRoomTypeFriend	= 1,
	k_EChatRoomTypeMUC	= 2,
	k_EChatRoomTypeLobby	= 3
    } 	EChatRoomType;

typedef /* [hidden] */ struct ZZ_Lazy_EChatRoomType_t
    {
    unsigned char k_EChatRoomTypeFriend;
    unsigned char k_EChatRoomTypeMUC;
    unsigned char k_EChatRoomTypeLobby;
    } 	ZZ_Lazy_EChatRoomType;

#pragma once
typedef 
enum ECallState
    {	k_ECallStateUnknown	= 0,
	k_ECallStateWaiting	= 1,
	k_ECallStateDialing	= 2,
	k_ECallStateRinging	= 3,
	k_ECallStateInCall	= 4
    } 	ECallState;

typedef /* [hidden] */ struct ZZ_Lazy_ECallState_t
    {
    unsigned char k_ECallStateUnknown;
    unsigned char k_ECallStateWaiting;
    unsigned char k_ECallStateDialing;
    unsigned char k_ECallStateRinging;
    unsigned char k_ECallStateInCall;
    } 	ZZ_Lazy_ECallState;

#pragma once
typedef 
enum EChatRoomVoiceStatus
    {	eChatRoomVoiceStatusBad	= 0,
	eChatRoomVoiceStatusUnknownRoom	= 1,
	eChatRoomVoiceStatusUnknownUser	= 2,
	eChatRoomVoiceStatusNotSpeaking	= 3,
	eChatRoomVoiceStatusConnectedSpeaking	= 4,
	eChatRoomVoiceStatusConnectedSpeakingData	= 5,
	eChatRoomVoiceStatusNotConnectedSpeaking	= 6,
	eChatRoomVoiceStatusConnecting	= 7,
	eChatRoomVoiceStatusUnreachable	= 8,
	eChatRoomVoiceStatusDisconnected	= 9,
	eChatRoomVoiceStatusCount	= 10
    } 	EChatRoomVoiceStatus;

typedef /* [hidden] */ struct ZZ_Lazy_EChatRoomVoiceStatus_t
    {
    unsigned char eChatRoomVoiceStatusBad;
    unsigned char eChatRoomVoiceStatusUnknownRoom;
    unsigned char eChatRoomVoiceStatusUnknownUser;
    unsigned char eChatRoomVoiceStatusNotSpeaking;
    unsigned char eChatRoomVoiceStatusConnectedSpeaking;
    unsigned char eChatRoomVoiceStatusConnectedSpeakingData;
    unsigned char eChatRoomVoiceStatusNotConnectedSpeaking;
    unsigned char eChatRoomVoiceStatusConnecting;
    unsigned char eChatRoomVoiceStatusUnreachable;
    unsigned char eChatRoomVoiceStatusDisconnected;
    unsigned char eChatRoomVoiceStatusCount;
    } 	ZZ_Lazy_EChatRoomVoiceStatus;

#pragma once
typedef 
enum EClanRelationship
    {	eClanRelationshipNone	= 0,
	eClanRelationshipBlocked	= 1,
	eClanRelationshipInvited	= 2,
	eClanRelationshipMember	= 3,
	eClanRelationshipKicked	= 4
    } 	EClanRelationship;

typedef /* [hidden] */ struct ZZ_Lazy_EClanRelationship_t
    {
    unsigned char eClanRelationshipNone;
    unsigned char eClanRelationshipBlocked;
    unsigned char eClanRelationshipInvited;
    unsigned char eClanRelationshipMember;
    unsigned char eClanRelationshipKicked;
    } 	ZZ_Lazy_EClanRelationship;

#pragma once
typedef 
enum EClanRank
    {	k_EClanRankNone	= 0,
	k_EClanRankOwner	= 1,
	k_EClanRankOfficer	= 2,
	k_EClanRankMember	= 3
    } 	EClanRank;

typedef /* [hidden] */ struct ZZ_Lazy_EClanRank_t
    {
    unsigned char k_EClanRankNone;
    unsigned char k_EClanRankOwner;
    unsigned char k_EClanRankOfficer;
    unsigned char k_EClanRankMember;
    } 	ZZ_Lazy_EClanRank;

#pragma once
typedef 
enum EGCMsgResponse
    {	k_EGCMsgResponseOK	= 0,
	k_EGCMsgResponseDenied	= ( k_EGCMsgResponseOK + 1 ) ,
	k_EGCMsgResponseServerError	= ( k_EGCMsgResponseDenied + 1 ) ,
	k_EGCMsgResponseTimeout	= ( k_EGCMsgResponseServerError + 1 ) ,
	k_EGCMsgResponseInvalid	= ( k_EGCMsgResponseTimeout + 1 ) ,
	k_EGCMsgResponseNoMatch	= ( k_EGCMsgResponseInvalid + 1 ) ,
	k_EGCMsgResponseUnknownError	= ( k_EGCMsgResponseNoMatch + 1 ) ,
	k_EGCMsgResponseNotLoggedOn	= ( k_EGCMsgResponseUnknownError + 1 ) 
    } 	EGCMsgResponse;

typedef /* [hidden] */ struct ZZ_Lazy_EGCMsgResponse_t
    {
    unsigned char k_EGCMsgResponseOK;
    unsigned char k_EGCMsgResponseDenied;
    unsigned char k_EGCMsgResponseServerError;
    unsigned char k_EGCMsgResponseTimeout;
    unsigned char k_EGCMsgResponseInvalid;
    unsigned char k_EGCMsgResponseNoMatch;
    unsigned char k_EGCMsgResponseUnknownError;
    unsigned char k_EGCMsgResponseNotLoggedOn;
    } 	ZZ_Lazy_EGCMsgResponse;

#pragma once
typedef 
enum EDetailedPlatformErrorType
    {	eNoDetailedErrorAvailable	= 0,
	eStandardCerrno	= ( eNoDetailedErrorAvailable + 1 ) ,
	eWin32LastError	= ( eStandardCerrno + 1 ) ,
	eWinSockLastError	= ( eWin32LastError + 1 ) ,
	eDetailedPlatformErrorCount	= ( eWinSockLastError + 1 ) 
    } 	EDetailedPlatformErrorType;

typedef /* [hidden] */ struct ZZ_Lazy_EDetailedPlatformErrorType_t
    {
    unsigned char eNoDetailedErrorAvailable;
    unsigned char eStandardCerrno;
    unsigned char eWin32LastError;
    unsigned char eWinSockLastError;
    unsigned char eDetailedPlatformErrorCount;
    } 	ZZ_Lazy_EDetailedPlatformErrorType;

#pragma once
typedef 
enum ESteamError
    {	eSteamErrorNone	= 0,
	eSteamErrorUnknown	= 1,
	eSteamErrorLibraryNotInitialized	= 2,
	eSteamErrorLibraryAlreadyInitialized	= 3,
	eSteamErrorConfig	= 4,
	eSteamErrorContentServerConnect	= 5,
	eSteamErrorBadHandle	= 6,
	eSteamErrorHandlesExhausted	= 7,
	eSteamErrorBadArg	= 8,
	eSteamErrorNotFound	= 9,
	eSteamErrorRead	= 10,
	eSteamErrorEOF	= 11,
	eSteamErrorSeek	= 12,
	eSteamErrorCannotWriteNonUserConfigFile	= 13,
	eSteamErrorCacheOpen	= 14,
	eSteamErrorCacheRead	= 15,
	eSteamErrorCacheCorrupted	= 16,
	eSteamErrorCacheWrite	= 17,
	eSteamErrorCacheSession	= 18,
	eSteamErrorCacheInternal	= 19,
	eSteamErrorCacheBadApp	= 20,
	eSteamErrorCacheVersion	= 21,
	eSteamErrorCacheBadFingerPrint	= 22,
	eSteamErrorNotFinishedProcessing	= 23,
	eSteamErrorNothingToDo	= 24,
	eSteamErrorCorruptEncryptedUserIDTicket	= 25,
	eSteamErrorSocketLibraryNotInitialized	= 26,
	eSteamErrorFailedToConnectToUserIDTicketValidationServer	= 27,
	eSteamErrorBadProtocolVersion	= 28,
	eSteamErrorReplayedUserIDTicketFromClient	= 29,
	eSteamErrorReceiveResultBufferTooSmall	= 30,
	eSteamErrorSendFailed	= 31,
	eSteamErrorReceiveFailed	= 32,
	eSteamErrorReplayedReplyFromUserIDTicketValidationServer	= 33,
	eSteamErrorBadSignatureFromUserIDTicketValidationServer	= 34,
	eSteamErrorValidationStalledSoAborted	= 35,
	eSteamErrorInvalidUserIDTicket	= 36,
	eSteamErrorClientLoginRateTooHigh	= 37,
	eSteamErrorClientWasNeverValidated	= 38,
	eSteamErrorInternalSendBufferTooSmall	= 39,
	eSteamErrorInternalReceiveBufferTooSmall	= 40,
	eSteamErrorUserTicketExpired	= 41,
	eSteamErrorCDKeyAlreadyInUseOnAnotherClient	= 42,
	eSteamErrorNotLoggedIn	= 101,
	eSteamErrorAlreadyExists	= 102,
	eSteamErrorAlreadySubscribed	= 103,
	eSteamErrorNotSubscribed	= 104,
	eSteamErrorAccessDenied	= 105,
	eSteamErrorFailedToCreateCacheFile	= 106,
	eSteamErrorCallStalledSoAborted	= 107,
	eSteamErrorEngineNotRunning	= 108,
	eSteamErrorEngineConnectionLost	= 109,
	eSteamErrorLoginFailed	= 110,
	eSteamErrorAccountPending	= 111,
	eSteamErrorCacheWasMissingRetry	= 112,
	eSteamErrorLocalTimeIncorrect	= 113,
	eSteamErrorCacheNeedsDecryption	= 114,
	eSteamErrorAccountDisabled	= 115,
	eSteamErrorCacheNeedsRepair	= 116,
	eSteamErrorRebootRequired	= 117,
	eSteamErrorNetwork	= 200,
	eSteamErrorOffline	= 201
    } 	ESteamError;

typedef /* [hidden] */ struct ZZ_Lazy_ESteamError_t
    {
    unsigned char eSteamErrorNone;
    unsigned char eSteamErrorUnknown;
    unsigned char eSteamErrorLibraryNotInitialized;
    unsigned char eSteamErrorLibraryAlreadyInitialized;
    unsigned char eSteamErrorConfig;
    unsigned char eSteamErrorContentServerConnect;
    unsigned char eSteamErrorBadHandle;
    unsigned char eSteamErrorHandlesExhausted;
    unsigned char eSteamErrorBadArg;
    unsigned char eSteamErrorNotFound;
    unsigned char eSteamErrorRead;
    unsigned char eSteamErrorEOF;
    unsigned char eSteamErrorSeek;
    unsigned char eSteamErrorCannotWriteNonUserConfigFile;
    unsigned char eSteamErrorCacheOpen;
    unsigned char eSteamErrorCacheRead;
    unsigned char eSteamErrorCacheCorrupted;
    unsigned char eSteamErrorCacheWrite;
    unsigned char eSteamErrorCacheSession;
    unsigned char eSteamErrorCacheInternal;
    unsigned char eSteamErrorCacheBadApp;
    unsigned char eSteamErrorCacheVersion;
    unsigned char eSteamErrorCacheBadFingerPrint;
    unsigned char eSteamErrorNotFinishedProcessing;
    unsigned char eSteamErrorNothingToDo;
    unsigned char eSteamErrorCorruptEncryptedUserIDTicket;
    unsigned char eSteamErrorSocketLibraryNotInitialized;
    unsigned char eSteamErrorFailedToConnectToUserIDTicketValidationServer;
    unsigned char eSteamErrorBadProtocolVersion;
    unsigned char eSteamErrorReplayedUserIDTicketFromClient;
    unsigned char eSteamErrorReceiveResultBufferTooSmall;
    unsigned char eSteamErrorSendFailed;
    unsigned char eSteamErrorReceiveFailed;
    unsigned char eSteamErrorReplayedReplyFromUserIDTicketValidationServer;
    unsigned char eSteamErrorBadSignatureFromUserIDTicketValidationServer;
    unsigned char eSteamErrorValidationStalledSoAborted;
    unsigned char eSteamErrorInvalidUserIDTicket;
    unsigned char eSteamErrorClientLoginRateTooHigh;
    unsigned char eSteamErrorClientWasNeverValidated;
    unsigned char eSteamErrorInternalSendBufferTooSmall;
    unsigned char eSteamErrorInternalReceiveBufferTooSmall;
    unsigned char eSteamErrorUserTicketExpired;
    unsigned char eSteamErrorCDKeyAlreadyInUseOnAnotherClient;
    unsigned char eSteamErrorNotLoggedIn;
    unsigned char eSteamErrorAlreadyExists;
    unsigned char eSteamErrorAlreadySubscribed;
    unsigned char eSteamErrorNotSubscribed;
    unsigned char eSteamErrorAccessDenied;
    unsigned char eSteamErrorFailedToCreateCacheFile;
    unsigned char eSteamErrorCallStalledSoAborted;
    unsigned char eSteamErrorEngineNotRunning;
    unsigned char eSteamErrorEngineConnectionLost;
    unsigned char eSteamErrorLoginFailed;
    unsigned char eSteamErrorAccountPending;
    unsigned char eSteamErrorCacheWasMissingRetry;
    unsigned char eSteamErrorLocalTimeIncorrect;
    unsigned char eSteamErrorCacheNeedsDecryption;
    unsigned char eSteamErrorAccountDisabled;
    unsigned char eSteamErrorCacheNeedsRepair;
    unsigned char eSteamErrorRebootRequired;
    unsigned char eSteamErrorNetwork;
    unsigned char eSteamErrorOffline;
    } 	ZZ_Lazy_ESteamError;

#pragma once
typedef 
enum ESteamSeekMethod
    {	eSteamSeekMethodSet	= 0,
	eSteamSeekMethodCur	= 1,
	eSteamSeekMethodEnd	= 2
    } 	ESteamSeekMethod;

#pragma once
typedef 
enum ESteamBufferMethod
    {	eSteamBufferMethodFBF	= 0,
	eSteamBufferMethodNBF	= 1
    } 	ESteamBufferMethod;

#pragma once
typedef 
enum ESteamFindFilter
    {	eSteamFindLocalOnly	= 0,
	eSteamFindRemoteOnly	= ( eSteamFindLocalOnly + 1 ) ,
	eSteamFindAll	= ( eSteamFindRemoteOnly + 1 ) 
    } 	ESteamFindFilter;

typedef /* [hidden] */ struct ZZ_Lazy_ESteamFindFilter_t
    {
    unsigned char eSteamFindLocalOnly;
    unsigned char eSteamFindRemoteOnly;
    unsigned char eSteamFindAll;
    } 	ZZ_Lazy_ESteamFindFilter;

#pragma once
typedef 
enum EBillingType
    {	eNoCost	= 0,
	eBillOnceOnly	= 1,
	eBillMonthly	= 2,
	eProofOfPrepurchaseOnly	= 3,
	eGuestPass	= 4,
	eHardwarePromo	= 5,
	eGift	= 6,
	eAutoGrant	= 7,
	eNumBillingTypes	= 8
    } 	EBillingType;

typedef /* [hidden] */ struct ZZ_Lazy_EBillingType_t
    {
    unsigned char eNoCost;
    unsigned char eBillOnceOnly;
    unsigned char eBillMonthly;
    unsigned char eProofOfPrepurchaseOnly;
    unsigned char eGuestPass;
    unsigned char eHardwarePromo;
    unsigned char eGift;
    unsigned char eAutoGrant;
    unsigned char eNumBillingTypes;
    } 	ZZ_Lazy_EBillingType;

#pragma once
typedef 
enum ESteamSubscriptionBillingInfoType
    {	ePaymentCardInfo	= 1,
	ePrepurchasedInfo	= 2,
	eAccountBillingInfo	= 3,
	eExternalBillingInfo	= 4,
	ePaymentCardReceipt	= 5,
	ePrepurchaseReceipt	= 6,
	eEmptyReceipt	= 7
    } 	ESteamSubscriptionBillingInfoType;

#pragma once
typedef 
enum ESteamPaymentCardType
    {	eVisa	= 1,
	eMaster	= 2,
	eAmericanExpress	= 3,
	eDiscover	= 4,
	eDinnersClub	= 5,
	eJCB	= 6
    } 	ESteamPaymentCardType;

#pragma once
typedef 
enum ESteamNotify
    {	eSteamNotifyTicketsWillExpire	= 0,
	eSteamNotifyAccountInfoChanged	= 1,
	eSteamNotifyContentDescriptionChanged	= 2,
	eSteamNotifyPleaseShutdown	= 3,
	eSteamNotifyNewContentServer	= 4,
	eSteamNotifySubscriptionStatusChanged	= 5,
	eSteamNotifyContentServerConnectionLost	= 6,
	eSteamNotifyCacheLoadingCompleted	= 7,
	eSteamNotifyCacheNeedsDecryption	= 8,
	eSteamNotifyCacheNeedsRepair	= 9,
	eSteamNotifyAppDownloading	= 10,
	eSteamNotifyAppDownloadingPaused	= 11
    } 	ESteamNotify;

typedef /* [hidden] */ struct ZZ_Lazy_ESteamNotify_t
    {
    unsigned char eSteamNotifyTicketsWillExpire;
    unsigned char eSteamNotifyAccountInfoChanged;
    unsigned char eSteamNotifyContentDescriptionChanged;
    unsigned char eSteamNotifyPleaseShutdown;
    unsigned char eSteamNotifyNewContentServer;
    unsigned char eSteamNotifySubscriptionStatusChanged;
    unsigned char eSteamNotifyContentServerConnectionLost;
    unsigned char eSteamNotifyCacheLoadingCompleted;
    unsigned char eSteamNotifyCacheNeedsDecryption;
    unsigned char eSteamNotifyCacheNeedsRepair;
    unsigned char eSteamNotifyAppDownloading;
    unsigned char eSteamNotifyAppDownloadingPaused;
    } 	ZZ_Lazy_ESteamNotify;

#pragma once
typedef 
enum ESteamAppUpdateStatsQueryType
    {	ePhysicalBytesReceivedThisSession	= 1,
	eAppReadyToLaunchStatus	= 2,
	eAppPreloadStatus	= 3,
	eAppEntireDepot	= 4,
	eCacheBytesPresent	= 5
    } 	ESteamAppUpdateStatsQueryType;

#pragma once
typedef 
enum ESteamSubscriptionStatus
    {	eSteamSubscriptionOK	= 0,
	eSteamSubscriptionPending	= 1,
	eSteamSubscriptionPreorder	= 2,
	eSteamSubscriptionPrepurchaseTransferred	= 3,
	eSteamSubscriptionPrepurchaseInvalid	= 4,
	eSteamSubscriptionPrepurchaseRejected	= 5,
	eSteamSubscriptionPrepurchaseRevoked	= 6,
	eSteamSubscriptionPaymentCardDeclined	= 7,
	eSteamSubscriptionCancelledByUser	= 8,
	eSteamSubscriptionCancelledByVendor	= 9,
	eSteamSubscriptionPaymentCardUseLimit	= 10,
	eSteamSubscriptionPaymentCardAlert	= 11,
	eSteamSubscriptionFailed	= 12,
	eSteamSubscriptionPaymentCardAVSFailure	= 13,
	eSteamSubscriptionPaymentCardInsufficientFunds	= 14,
	eSteamSubscriptionRestrictedCountry	= 15
    } 	ESteamSubscriptionStatus;

#pragma once
typedef 
enum ESteamServerType
    {	eSteamValveCDKeyValidationServer	= 0,
	eSteamHalfLifeMasterServer	= 1,
	eSteamFriendsServer	= 2,
	eSteamCSERServer	= 3,
	eSteamHalfLife2MasterServer	= 4,
	eSteamRDKFMasterServer	= 5,
	eMaxServerTypes	= 6
    } 	ESteamServerType;

typedef /* [hidden] */ struct ZZ_Lazy_ESteamServerType_t
    {
    unsigned char eSteamValveCDKeyValidationServer;
    unsigned char eSteamHalfLifeMasterServer;
    unsigned char eSteamFriendsServer;
    unsigned char eSteamCSERServer;
    unsigned char eSteamHalfLife2MasterServer;
    unsigned char eSteamRDKFMasterServer;
    unsigned char eMaxServerTypes;
    } 	ZZ_Lazy_ESteamServerType;

typedef void *( *CreateInterfaceFn )( 
    const unsigned char *pName,
    int *pReturnCode);

typedef void *( *FactoryFn )( 
    const unsigned char *pName);

typedef void *( *InstantiateInterfaceFn )( void);

typedef void ( *SteamAPIWarningMessageHook_t )( 
    int hpipe,
    const unsigned char *message);

typedef void ( *KeyValueIteratorCallback_t )( 
    const unsigned char *key,
    const unsigned char *value,
    void *kv);

typedef void ( *SteamNotificationCallback_t )( 
    ESteamNotify eEvent,
    unsigned int nData);

typedef int ( *SteamBGetCallbackFn )( 
    int hpipe,
    void *pCallbackMsg,
    int32 *phSteamCall);

typedef void ( *SteamFreeLastCallbackFn )( 
    int hpipe);

typedef int ( *SteamGetAPICallResultFn )( 
    int hpipe,
    uint64 hSteamAPICall,
    void *pCallback,
    int cubCallback,
    int iCallbackExpected,
    int *pbFailed);

#define	k_cubDigestSize	( 20 )

#define	k_cubSaltSize	( 8 )

#define	k_cchGameExtraInfoMax	( 64 )

#define	k_nMaxNumCardsPerAccount	( 1 )

#define	k_unServerFlagNone	( 0 )

#define	k_unServerFlagActive	( 0x1 )

#define	k_unServerFlagSecure	( 0x2 )

#define	k_unServerFlagDedicated	( 0x4 )

#define	k_unServerFlagLinux	( 0x8 )

#define	k_unServerFlagPassworded	( 0x10 )

#define	k_unServerFlagPrivate	( 0x20 )

typedef uint8 SHADigest_t[ 20 ];

typedef uint8 Salt_t[ 8 ];

typedef uint64 GID_t;

typedef uint32 PackageId_t;

#define	k_uPackageIdInvalid	( 0xffffffff )

typedef uint32 AppId_t;

#define	k_uAppIdInvalid	( 0 )

typedef uint32 ShareType_t;

typedef uint32 HDepotBuild;

typedef int HVoiceCall;

typedef uint32 RTime32;

typedef uint32 CellID_t;

typedef uint64 SteamAPICall_t;

typedef int32 HSteamPipe;

typedef int32 HSteamUser;

typedef int32 HSteamCall;

typedef uint32 HAuthTicket;

#define	k_HAuthTicketInvalid	( 0 )

typedef int HNewItemRequest;

typedef uint64 ItemID;

typedef int unknown_ret;

typedef int HServerQuery;

#define	HSERVERQUERY_INVALID	( 0xffffffff )

#define	k_unFavoriteFlagNone	( 0 )

#define	k_unFavoriteFlagFavorite	( 0x1 )

#define	k_unFavoriteFlagHistory	( 0x2 )

typedef uint32 SNetSocket_t;

typedef uint32 SNetListenSocket_t;

#define	k_cchFriendChatMsgMax	( ( 32 * 1024 )  )

#define	k_cchPersonaNameMax	( 128 )

#define	k_cubChatMetadataMax	( 8192 )

#define	k_cchSystemIMTextMax	( 4096 )

#define	k_cchStatNameMax	( 128 )

#define	k_cchLeaderboardNameMax	( 128 )

#define	k_cLeaderboardDetailsMax	( 64 )

typedef uint64 SteamLeaderboard_t;

typedef uint64 SteamLeaderboardEntries_t;

typedef void ( *PFNLegacyKeyRegistration )( 
    const unsigned char *pchCDKey,
    const unsigned char *pchInstallPath);

typedef int ( *PFNLegacyKeyInstalled )( void);

#define	k_unSteamAccountIDMask	( 0xffffffff )

#define	k_unSteamAccountInstanceMask	( 0xfffff )


enum EChatSteamIDInstanceFlags
    {	k_EChatAccountInstanceMask	= 0xfff,
	k_EChatInstanceFlagClan	= ( ( k_unSteamAccountInstanceMask + 1 )  >> 1 ) ,
	k_EChatInstanceFlagLobby	= ( ( k_unSteamAccountInstanceMask + 1 )  >> 2 ) 
    } ;
typedef unsigned int SteamHandle_t;

typedef void *SteamUserIDTicketValidationHandle_t;

typedef unsigned int SteamCallHandle_t;

typedef unsigned __int64 SteamUnsigned64_t;

typedef unsigned short SteamInstanceID_t;

typedef unsigned long long SteamLocalUserID_t;

typedef unsigned char SteamPersonalQuestion_t[ 256 ];


enum ECallbackType
    {	k_iSteamUserCallbacks	= 100,
	k_iSteamGameServerCallbacks	= 200,
	k_iSteamFriendsCallbacks	= 300,
	k_iSteamBillingCallbacks	= 400,
	k_iSteamMatchmakingCallbacks	= 500,
	k_iSteamContentServerCallbacks	= 600,
	k_iSteamUtilsCallbacks	= 700,
	k_iClientFriendsCallbacks	= 800,
	k_iClientUserCallbacks	= 900,
	k_iSteamAppsCallbacks	= 1000,
	k_iSteamUserStatsCallbacks	= 1100,
	k_iSteamNetworkingCallbacks	= 1200,
	k_iClientRemoteStorageCallbacks	= 1300,
	k_iSteamUserItemsCallbacks	= 1400,
	k_iSteamGameServerItemsCallbacks	= 1500,
	k_iClientUtilsCallbacks	= 1600,
	k_iSteamGameCoordinatorCallbacks	= 1700
    } ;
typedef /* [hidden] */ struct ZZ_Lazy_ECallbackType_t
    {
    unsigned char k_iSteamUserCallbacks;
    unsigned char k_iSteamGameServerCallbacks;
    unsigned char k_iSteamFriendsCallbacks;
    unsigned char k_iSteamBillingCallbacks;
    unsigned char k_iSteamMatchmakingCallbacks;
    unsigned char k_iSteamContentServerCallbacks;
    unsigned char k_iSteamUtilsCallbacks;
    unsigned char k_iClientFriendsCallbacks;
    unsigned char k_iClientUserCallbacks;
    unsigned char k_iSteamAppsCallbacks;
    unsigned char k_iSteamUserStatsCallbacks;
    unsigned char k_iSteamNetworkingCallbacks;
    unsigned char k_iClientRemoteStorageCallbacks;
    unsigned char k_iSteamUserItemsCallbacks;
    unsigned char k_iSteamGameServerItemsCallbacks;
    unsigned char k_iClientUtilsCallbacks;
    unsigned char k_iSteamGameCoordinatorCallbacks;
    } 	ZZ_Lazy_ECallbackType;

#pragma once
typedef struct TSteamElemInfo
    {
    int bIsDir;
    unsigned int uSizeOrCount;
    int bIsLocal;
    unsigned char cszName[ 255 ];
    long lLastAccessTime;
    long lLastModificationTime;
    long lCreationTime;
    } 	TSteamElemInfo;

#pragma once
typedef struct TSTeamError
    {
    ESteamError eSteamError;
    EDetailedPlatformErrorType eDetailedErrorType;
    int nDetailedErrorCode;
    unsigned char szDesc[ 255 ];
    } 	TSteamError;

#pragma once
typedef struct TSteamProgress
    {
    int bValid;
    unsigned int uPercentDone;
    unsigned char szProgress[ 255 ];
    } 	TSteamProgress;

#pragma once
typedef struct TSteamAppStats
    {
    unsigned int uNumApps;
    unsigned int uMaxNameChars;
    unsigned int uMaxInstallDirNameChars;
    unsigned int uMaxVersionLabelChars;
    unsigned int uMaxLaunchOptions;
    unsigned int uMaxLaunchOptionDescChars;
    unsigned int uMaxLaunchOptionCmdLineChars;
    unsigned int uMaxNumIcons;
    unsigned int uMaxIconSize;
    unsigned int uMaxDependencies;
    } 	TSteamAppStats;

#pragma once
typedef struct TSteamUpdateStats
    {
    SteamUnsigned64_t uBytesTotal;
    SteamUnsigned64_t uBytesPresent;
    } 	TSteamUpdateStats;

#pragma once
typedef struct TSteamPaymentCardInfo
    {
    ESteamPaymentCardType eCardType;
    unsigned char szCardNumber[ 18 ];
    unsigned char szCardHolderName[ 101 ];
    unsigned char szCardExpYear[ 5 ];
    unsigned char szCardExpMonth[ 3 ];
    unsigned char szCardCVV2[ 6 ];
    unsigned char szBillingAddress1[ 129 ];
    unsigned char szBillingAddress2[ 129 ];
    unsigned char szBillingCity[ 51 ];
    unsigned char szBillingZip[ 17 ];
    unsigned char szBillingState[ 33 ];
    unsigned char szBillingCountry[ 33 ];
    unsigned char szBillingPhone[ 21 ];
    unsigned char szBillingEmailAddress[ 101 ];
    unsigned int uExpectedCostInCents;
    unsigned int uExpectedTaxInCents;
    unsigned char szShippingName[ 101 ];
    unsigned char szShippingAddress1[ 129 ];
    unsigned char szShippingAddress2[ 129 ];
    unsigned char szShippingCity[ 51 ];
    unsigned char szShippingZip[ 17 ];
    unsigned char szShippingState[ 33 ];
    unsigned char szShippingCountry[ 33 ];
    unsigned char szShippingPhone[ 21 ];
    unsigned int uExpectedShippingCostInCents;
    } 	TSteamPaymentCardInfo;

#pragma once
typedef struct TSteamPrepurchaseInfo
    {
    unsigned char szTypeOfProofOfPurchase[ 21 ];
    unsigned int uLengthOfBinaryProofOfPurchaseToken;
    unsigned char cBinaryProofOfPurchaseToken[ 201 ];
    } 	TSteamPrepurchaseInfo;

#pragma once
typedef struct TSteamExternalBillingInfo
    {
    unsigned char szAccountName[ 101 ];
    unsigned char szPassword[ 81 ];
    } 	TSteamExternalBillingInfo;

#pragma once
typedef struct TSteamSubscriptionBillingInfo
    {
    ESteamSubscriptionBillingInfoType eBillingInfoType;
    union 
        {
        TSteamPaymentCardInfo PaymentCardInfo;
        TSteamPrepurchaseInfo PrepurchaseInfo;
        TSteamExternalBillingInfo ExternalBillingInfo;
        unsigned char bUseAccountBillingInfo;
        } 	;
    } 	TSteamSubscriptionBillingInfo;

#pragma once
typedef struct TSteamSubscriptionStats
    {
    unsigned int uNumSubscriptions;
    unsigned int uMaxNameChars;
    unsigned int uMaxApps;
    } 	TSteamSubscriptionStats;

#pragma once
typedef struct TSteamSubscription
    {
    unsigned char *szName;
    unsigned int uMaxNameChars;
    unsigned int *puAppIds;
    unsigned int uMaxAppIds;
    unsigned int uId;
    unsigned int uNumApps;
    EBillingType eBillingType;
    unsigned int uCostInCents;
    unsigned int uNumDiscounts;
    int bIsPreorder;
    int bRequiresShippingAddress;
    unsigned int uDomesticShippingCostInCents;
    unsigned int uInternationalShippingCostInCents;
    int bIsCyberCafeSubscription;
    unsigned int uGameCode;
    unsigned char szGameCodeDesc[ 255 ];
    int bIsDisabled;
    int bRequiresCD;
    unsigned int uTerritoryCode;
    int bIsSteam3Subscription;
    } 	TSteamSubscription;

#pragma once
typedef struct TSteamApp
    {
    unsigned char *szName;
    unsigned int uMaxNameChars;
    unsigned char *szLatestVersionLabel;
    unsigned int uMaxLatestVersionLabelChars;
    unsigned char *szCurrentVersionLabel;
    unsigned int uMaxCurrentVersionLabelChars;
    unsigned char *szInstallDirName;
    unsigned int uMaxInstallDirNameChars;
    unsigned int uId;
    unsigned int uLatestVersionId;
    unsigned int uCurrentVersionId;
    unsigned int uMinCacheFileSizeMB;
    unsigned int uMaxCacheFileSizeMB;
    unsigned int uNumLaunchOptions;
    unsigned int uNumIcons;
    unsigned int uNumVersions;
    unsigned int uNumDependencies;
    unsigned char *szUnkString;
    } 	TSteamApp;

#pragma once
typedef struct TSteamAppLaunchOption
    {
    unsigned char *szDesc;
    unsigned int uMaxDescChars;
    unsigned char *szCmdLine;
    unsigned int uMaxCmdLineChars;
    unsigned int uIndex;
    unsigned int uIconIndex;
    int bNoDesktopShortcut;
    int bNoStartMenuShortcut;
    int bIsLongRunningUnattended;
    } 	TSteamAppLaunchOption;

#pragma once
typedef struct TSteamAppVersion
    {
    unsigned char *szLabel;
    unsigned int uMaxLabelChars;
    unsigned int uVersionId;
    int bIsNotAvailable;
    } 	TSteamAppVersion;

#pragma once
typedef struct TSteamSplitLocalUserID
    {
    unsigned int Low32bits;
    unsigned int High32bits;
    } 	TSteamSplitLocalUserID;

#pragma once
typedef struct TSteamGlobalUserID
    {
    SteamInstanceID_t m_SteamInstanceID;
    union m_SteamLocalUserID
        {
        SteamLocalUserID_t As64bits;
        TSteamSplitLocalUserID Split;
        } 	m_SteamLocalUserID;
    } 	TSteamGlobalUserID;

#pragma once
typedef struct TSteamAppDependencyInfo
    {
    unsigned int AppId;
    unsigned int IsRequired;
    unsigned char szMountName[ 255 ];
    } 	TSteamAppDependencyInfo;

#pragma once
typedef struct TSteamOfflineStatus
    {
    int eOfflineNow;
    int eOfflineNextSession;
    } 	TSteamOfflineStatus;

#pragma once
typedef struct TSteamPaymentCardReceiptInfo
    {
    ESteamPaymentCardType eCardType;
    unsigned char szCardLastFourDigits[ 5 ];
    unsigned char szCardHolderName[ 101 ];
    unsigned char szBillingAddress1[ 129 ];
    unsigned char szBillingAddress2[ 129 ];
    unsigned char szBillingCity[ 51 ];
    unsigned char szBillingZip[ 17 ];
    unsigned char szBillingState[ 33 ];
    unsigned char szBillingCountry[ 33 ];
    unsigned char szCardApprovalCode[ 101 ];
    unsigned char szTransDate[ 10 ];
    unsigned char szTransTime[ 10 ];
    unsigned int uPriceWithoutTax;
    unsigned int uTaxAmount;
    unsigned int uShippingCost;
    } 	TSteamPaymentCardReceiptInfo;

#pragma once
typedef struct TSteamPrepurchaseReceiptInfo
    {
    unsigned char szTypeOfProofOfPurchase[ 21 ];
    } 	TSteamPrepurchaseReceiptInfo;

#pragma once
typedef struct TSteamSubscriptionReceipt
    {
    ESteamSubscriptionStatus eStatus;
    ESteamSubscriptionStatus ePreviousStatus;
    ESteamSubscriptionBillingInfoType eReceiptInfoType;
    unsigned char szConfirmationCode[ 17 ];
    union 
        {
        TSteamPaymentCardReceiptInfo PaymentCardReceiptInfo;
        TSteamPrepurchaseReceiptInfo PrepurchaseReceiptInfo;
        } 	;
    } 	TSteamSubscriptionReceipt;

#pragma once
typedef struct TSteamSubscriptionDiscount
    {
    unsigned char szName[ 255 ];
    unsigned int uDiscountInCents;
    unsigned int uNumQualifiers;
    } 	TSteamSubscriptionDiscount;

#pragma once
typedef struct TSteamDiscountQualifier
    {
    unsigned char szName[ 255 ];
    unsigned int uRequiredSubscription;
    int bIsDisqualifier;
    } 	TSteamDiscountQualifier;

#pragma once
typedef struct SteamSalt
    {
    unsigned char uchSalt[ 8 ];
    } 	SteamSalt_t;

struct FriendGameInfo_t
    {
    uint32 m_gameID;
    uint32 m_unGameIP;
    uint16 m_usGamePort;
    uint16 m_usQueryPort;
    uint64 m_steamIDLobby;
    } ;
#pragma once
struct LeaderboardEntry_t
    {
    uint64 m_steamIDUser;
    int32 m_nGlobalRank;
    int32 m_nScore;
    int32 m_cDetails;
    } ;
struct CallbackMsg_t
    {
    HSteamUser m_hSteamUser;
    int m_iCallback;
    uint8 *m_pubParam;
    int m_cubParam;
    } ;

EXTERN_C const IID LIBID_Steam4COMLib;

EXTERN_C const CLSID CLSID_Steamworks;

#ifdef __cplusplus

class DECLSPEC_UUID("1147E492-6F78-4DED-9348-4B898EA49BE4")
Steamworks;
#endif

EXTERN_C const CLSID CLSID_SteamID;

#ifdef __cplusplus

class DECLSPEC_UUID("97BA9E56-E772-4AD9-8E62-FABC24522A24")
SteamID;
#endif

EXTERN_C const CLSID CLSID_GameID;

#ifdef __cplusplus

class DECLSPEC_UUID("74F18782-62C7-4C77-8DBA-DBECD107FA4B")
GameID;
#endif
#endif /* __Steam4COMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


