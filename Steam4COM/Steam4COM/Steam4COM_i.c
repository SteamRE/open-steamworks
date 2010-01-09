

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_ISteamworks,0xE1930C46,0x5747,0x4069,0x85,0x57,0x91,0xA9,0xF7,0xA5,0xD9,0xC0);


MIDL_DEFINE_GUID(IID, IID_ISteamID,0x2C1BFF57,0x1DFF,0x486C,0x83,0xC7,0x9A,0x5F,0x9C,0x3C,0x5D,0x21);


MIDL_DEFINE_GUID(IID, IID_IGameID,0xE03512EF,0x12F4,0x418C,0x8E,0x1B,0xA7,0x05,0x2B,0x35,0xBC,0xE4);


MIDL_DEFINE_GUID(IID, LIBID_Steam4COMLib,0x3019F688,0x8724,0x45B8,0x83,0x5B,0x6D,0x1A,0xC7,0xDB,0xDC,0xAD);


MIDL_DEFINE_GUID(CLSID, CLSID_Steamworks,0x1147E492,0x6F78,0x4DED,0x93,0x48,0x4B,0x89,0x8E,0xA4,0x9B,0xE4);


MIDL_DEFINE_GUID(CLSID, CLSID_SteamID,0x97BA9E56,0xE772,0x4AD9,0x8E,0x62,0xFA,0xBC,0x24,0x52,0x2A,0x24);


MIDL_DEFINE_GUID(CLSID, CLSID_GameID,0x74F18782,0x62C7,0x4C77,0x8D,0xBA,0xDB,0xEC,0xD1,0x07,0xFA,0x4B);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



