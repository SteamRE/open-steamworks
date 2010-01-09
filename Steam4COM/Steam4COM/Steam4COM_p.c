

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "Steam4COM_i.h"

#define TYPE_FORMAT_STRING_SIZE   3                                 
#define PROC_FORMAT_STRING_SIZE   1                                 
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _Steam4COM_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } Steam4COM_MIDL_TYPE_FORMAT_STRING;

typedef struct _Steam4COM_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } Steam4COM_MIDL_PROC_FORMAT_STRING;

typedef struct _Steam4COM_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } Steam4COM_MIDL_EXPR_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const Steam4COM_MIDL_TYPE_FORMAT_STRING Steam4COM__MIDL_TypeFormatString;
extern const Steam4COM_MIDL_PROC_FORMAT_STRING Steam4COM__MIDL_ProcFormatString;
extern const Steam4COM_MIDL_EXPR_FORMAT_STRING Steam4COM__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISteamworks_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ISteamworks_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISteamID_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ISteamID_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IGameID_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IGameID_ProxyInfo;



#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const Steam4COM_MIDL_PROC_FORMAT_STRING Steam4COM__MIDL_ProcFormatString =
    {
        0,
        {

			0x0
        }
    };

static const Steam4COM_MIDL_TYPE_FORMAT_STRING Steam4COM__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ISteamworks, ver. 0.0,
   GUID={0xE1930C46,0x5747,0x4069,{0x85,0x57,0x91,0xA9,0xF7,0xA5,0xD9,0xC0}} */

#pragma code_seg(".orpc")
static const unsigned short ISteamworks_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ISteamworks_ProxyInfo =
    {
    &Object_StubDesc,
    Steam4COM__MIDL_ProcFormatString.Format,
    &ISteamworks_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ISteamworks_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Steam4COM__MIDL_ProcFormatString.Format,
    &ISteamworks_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _ISteamworksProxyVtbl = 
{
    0,
    &IID_ISteamworks,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */
};


static const PRPC_STUB_FUNCTION ISteamworks_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION
};

CInterfaceStubVtbl _ISteamworksStubVtbl =
{
    &IID_ISteamworks,
    &ISteamworks_ServerInfo,
    7,
    &ISteamworks_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ISteamID, ver. 0.0,
   GUID={0x2C1BFF57,0x1DFF,0x486C,{0x83,0xC7,0x9A,0x5F,0x9C,0x3C,0x5D,0x21}} */

#pragma code_seg(".orpc")
static const unsigned short ISteamID_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ISteamID_ProxyInfo =
    {
    &Object_StubDesc,
    Steam4COM__MIDL_ProcFormatString.Format,
    &ISteamID_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ISteamID_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Steam4COM__MIDL_ProcFormatString.Format,
    &ISteamID_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _ISteamIDProxyVtbl = 
{
    0,
    &IID_ISteamID,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */
};


static const PRPC_STUB_FUNCTION ISteamID_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION
};

CInterfaceStubVtbl _ISteamIDStubVtbl =
{
    &IID_ISteamID,
    &ISteamID_ServerInfo,
    7,
    &ISteamID_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IGameID, ver. 0.0,
   GUID={0xE03512EF,0x12F4,0x418C,{0x8E,0x1B,0xA7,0x05,0x2B,0x35,0xBC,0xE4}} */

#pragma code_seg(".orpc")
static const unsigned short IGameID_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IGameID_ProxyInfo =
    {
    &Object_StubDesc,
    Steam4COM__MIDL_ProcFormatString.Format,
    &IGameID_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IGameID_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Steam4COM__MIDL_ProcFormatString.Format,
    &IGameID_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IGameIDProxyVtbl = 
{
    0,
    &IID_IGameID,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */
};


static const PRPC_STUB_FUNCTION IGameID_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION
};

CInterfaceStubVtbl _IGameIDStubVtbl =
{
    &IID_IGameID,
    &IGameID_ServerInfo,
    7,
    &IGameID_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    Steam4COM__MIDL_TypeFormatString.Format,
    0, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x70001f4, /* MIDL Version 7.0.500 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * _Steam4COM_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_ISteamworksProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISteamIDProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IGameIDProxyVtbl,
    0
};

const CInterfaceStubVtbl * _Steam4COM_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_ISteamworksStubVtbl,
    ( CInterfaceStubVtbl *) &_ISteamIDStubVtbl,
    ( CInterfaceStubVtbl *) &_IGameIDStubVtbl,
    0
};

PCInterfaceName const _Steam4COM_InterfaceNamesList[] = 
{
    "ISteamworks",
    "ISteamID",
    "IGameID",
    0
};

const IID *  _Steam4COM_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _Steam4COM_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _Steam4COM, pIID, n)

int __stdcall _Steam4COM_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _Steam4COM, 3, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _Steam4COM, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _Steam4COM, 3, *pIndex )
    
}

const ExtendedProxyFileInfo Steam4COM_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _Steam4COM_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _Steam4COM_StubVtblList,
    (const PCInterfaceName * ) & _Steam4COM_InterfaceNamesList,
    (const IID ** ) & _Steam4COM_BaseIIDList,
    & _Steam4COM_IID_Lookup, 
    3,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

