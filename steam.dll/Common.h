#ifndef COMMON_H
#define COMMON_H

#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <tlhelp32.h>

#include <map>

#define STEAM_API_EXPORTS
//#define NO_STRING_T
#define NO_STEAMCLIENT
#include "steamworks.h"

#include "detourxs.h"
#include "Log.h"

// define this for enumeration spew
#define LOGGING_VERBOSE

typedef std::map<SteamHandle_t, char *> HandleMap;
typedef std::pair<SteamHandle_t, char *> HandleEntry;
typedef HandleMap::const_iterator HandleIterator;

#define ADD_MAP_ENTRYF( map, handle, name, ... ) \
	char handleName[255]; \
	sprintf( handleName, name, __VA_ARGS__ ); \
	ADD_MAP_ENTRY( map, handle, handleName )

#define ADD_MAP_ENTRY( map, handle, name ) \
	size_t len = strlen( (char*)name ); \
	char *newMem = (char *)malloc( len ); \
	strncpy( newMem, (char*)name, len + 1 ); \
	map.insert( HandleEntry( handle, newMem ) )

#define FREE_MAP_ENTRY( map, handle ) \
	HandleIterator iter = map.find( handle ); \
	if ( iter != map.end() ) \
	{ \
		map.erase( iter ); \
	}

//		free( iter->second ); \


extern HandleMap logMap; // defined in Logging.cpp
extern HandleMap fileMap; // defined in FileSystem.cpp
extern HandleMap callMap; // defined in AsyncCalls.cpp

extern HMODULE valveSteam;

__forceinline unsigned int GetReturnAddress()
{
	unsigned int retAddr;
	__asm
	{
		push eax;
		mov eax, [ebp+4];
		mov retAddr, eax;
		pop eax;
	}
	return retAddr;
}

#define ENSURE_PROXY( name ) \
	if ( !name##Orig ) \
		name##Orig = (name##Fn)GetProcAddress( valveSteam, #name )

#define BOOKKEEP_PROXY() \
	unsigned int retAddr = GetReturnAddress(); \
	HANDLE snapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, 0); \
	MODULEENTRY32 me32; \
	MODULEENTRY32 callerModule; \
	me32.dwSize = sizeof (MODULEENTRY32); \
	Module32First(snapShot, &me32); \
	do \
	{ \
		unsigned int start = (unsigned int)me32.modBaseAddr; \
		unsigned int end = (unsigned int)start + me32.modBaseSize; \
		if ((retAddr > start) && (retAddr < end)) \
		{ \
			callerModule = me32; \
			break; \
		} \
	} \
	while (Module32Next(snapShot, &me32)); \
	CloseHandle(snapShot);

#define LOG_PROXY( name ) \
	::Log( "%s\n\n", callerModule.szModule, name )

#define LOG_FN() \
	LOG_PROXY( __FUNCTION__ );

#define DECL_PROXY( ret, name, fullParams ) \
	typedef ret (*name##Fn)fullParams; \
	name##Fn name##Orig; \
	S_API ret STEAM_CALL name fullParams \
	{ \
		ENSURE_PROXY( name ); \
		BOOKKEEP_PROXY(); 

#define RETURN_PROXY( name, params ) \
		return name##Orig params; \
	}

#define BASIC_PROXY( ret, name, fullParams, params ) \
	DECL_PROXY( ret, name, fullParams ) \
		LOG_PROXY( #name ); \
	RETURN_PROXY( name, params )

#define ADV_PROXY( ret, name, fullParams, params ) \
	DECL_PROXY( ret, name, fullParams ) \
		ret returnObj = name##Orig params;

#define END_PROXY() \
		return returnObj; \
	}

#define ADV_VOID_PROXY( ret, name, fullParams, params ) \
	DECL_PROXY( ret, name, fullParams ) \
		name##Orig params;

#define END_VOID_PROXY() \
	}

#define SILENT_PROXY( ret, name, fullParams, params ) \
	DECL_PROXY( ret, name, fullParams ) \
	RETURN_PROXY( name, params )



#endif // COMMON_H
