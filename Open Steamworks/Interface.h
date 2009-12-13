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


#ifndef INTERFACE_H
#define INTERFACE_H

#include <cstdlib>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#include <tchar.h>
#pragma once
#endif

enum
{
	IFACE_OK = 0,
	IFACE_FAILED
};

// load/unload components
class CSysModule;


#define CREATEINTERFACE_PROCNAME "CreateInterface"
// steam.dll ISteam factory
#define OLDFACTORY_PROCNAME "_f"


#ifndef _WIN32
// Linux doesn't have this function so this emulates its functionality
inline void *GetModuleHandleA( const char *name )
{
	void *handle;

	if ( name == NULL )
	{
		// hmm, how can this be handled under linux....
		// is it even needed?
		return NULL;
	}

	handle = dlopen( name, RTLD_NOW );
    if ( handle == NULL )
    {
            printf("DLOPEN Error:%s\n",dlerror());
            // couldn't open this file
            return NULL;
    }

	// read "man dlopen" for details
	// in short dlopen() inc a ref count
	// so dec the ref count by performing the close
	dlclose(handle);
	return handle;
}
#endif

inline HMODULE Sys_LoadLibrary( const char *pLibraryName )
{
#ifdef _WIN32
	return LoadLibraryExA( pLibraryName, NULL, LOAD_WITH_ALTERED_SEARCH_PATH );
#else
	char file[260];
	sprintf(file, "%s_linux.so", pLibraryName);
	return dlopen( file, RTLD_NOW );
#endif
}

//-----------------------------------------------------------------------------
// Purpose: returns a pointer to a function, given a module
// Input  : pModuleName - module name
//			*pName - proc name
//-----------------------------------------------------------------------------
inline void *Sys_GetProcAddress( const char *pModuleName, const char *pName )
{
	HMODULE hModule = GetModuleHandleA( pModuleName );

	if ( !hModule )
		hModule = Sys_LoadLibrary( pModuleName );

//#ifdef _WIN32
	return (void *)GetProcAddress( hModule, pName );
//#else
//	return (CreateInterfaceFn)( dlsym( hModule, CREATEINTERFACE_PROCNAME ) );
//#endif
}

//-----------------------------------------------------------------------------
// Purpose: returns the instance of the named module
// Input  : *pModuleName - name of the module
// Output : interface_instance_t - instance of that module
//-----------------------------------------------------------------------------
inline CreateInterfaceFn Sys_GetFactory( const char *pModuleName )
{
	return (CreateInterfaceFn)( Sys_GetProcAddress( pModuleName, CREATEINTERFACE_PROCNAME ) );
}

//-----------------------------------------------------------------------------
// Purpose: returns a pointer to a function, given a module
// Input  : module - windows HMODULE from Sys_LoadModule()
//			*pName - proc name
// Output : factory for this module
//-----------------------------------------------------------------------------
inline CreateInterfaceFn Sys_GetFactory( CSysModule *pModule )
{
	if ( !pModule )
		return NULL;

	HMODULE	hDLL = reinterpret_cast<HMODULE>(pModule);
#ifdef _WIN32
	return reinterpret_cast<CreateInterfaceFn>( GetProcAddress( hDLL, CREATEINTERFACE_PROCNAME ) );
#else
	// Linux gives this error:
	//../public/interface.cpp: In function `IBaseInterface *(*Sys_GetFactory
	//(CSysModule *)) (const char *, int *)':
	//../public/interface.cpp:154: ISO C++ forbids casting between
	//pointer-to-function and pointer-to-object
	//
	// so lets get around it :)
	return (CreateInterfaceFn)(dlsym( hDLL, CREATEINTERFACE_PROCNAME ));
#endif
}


inline FactoryFn Sys_GetFactoryOld( const char *pModuleName )
{
	return (FactoryFn)( Sys_GetProcAddress( pModuleName, OLDFACTORY_PROCNAME ) );
}



//-----------------------------------------------------------------------------
// Purpose: Loads a DLL/component from disk and returns a handle to it
// Input  : *pModuleName - filename of the component
// Output : opaque handle to the module (hides system dependency)
//-----------------------------------------------------------------------------
inline CSysModule *Sys_LoadModule( const char *pModuleName )
{
	// If using the Steam filesystem, either the DLL must be a minimum footprint
	// file in the depot (MFP) or a filesystem GetLocalCopy() call must be made
	// prior to the call to this routine.
	HMODULE hDLL = Sys_LoadLibrary( pModuleName );
	return reinterpret_cast<CSysModule *>( hDLL );
}

//-----------------------------------------------------------------------------
// Purpose: Unloads a DLL/component from
// Input  : *pModuleName - filename of the component
// Output : opaque handle to the module (hides system dependency)
//-----------------------------------------------------------------------------
inline void Sys_UnloadModule( CSysModule *pModule )
{
	if ( !pModule )
		return;

	HMODULE	hDLL = reinterpret_cast<HMODULE>( pModule );

#ifdef _WIN32
	FreeLibrary( hDLL );
#else
	dlclose( (void *)hDLL );
#endif
}


//-----------------------------------------------------------------------------
// Purpose: get the interface for the specified module and version
// Input  :
// Output :
//-----------------------------------------------------------------------------
inline bool Sys_LoadInterface(
	const char *pModuleName,
	const char *pInterfaceVersionName,
	CSysModule **pOutModule,
	void **pOutInterface )
{
	CSysModule *pMod = Sys_LoadModule( pModuleName );
	if ( !pMod )
		return false;

	CreateInterfaceFn fn = Sys_GetFactory( pMod );
	if ( !fn )
	{
		Sys_UnloadModule( pMod );
		return false;
	}

	*pOutInterface = fn( pInterfaceVersionName, NULL );
	if ( !( *pOutInterface ) )
	{
		Sys_UnloadModule( pMod );
		return false;
	}

	if ( pOutModule )
		*pOutModule = pMod;

	return true;
}

class CDllDemandLoader
{
public:
	CDllDemandLoader( char const *pchModuleName ) : m_pchModuleName( pchModuleName ), m_hModule( 0 ), m_bLoadAttempted( false )	{};
	virtual				~CDllDemandLoader() { Unload(); };

	CreateInterfaceFn GetFactory(const char *altpath)
	{
		if ( !m_hModule && !m_bLoadAttempted )
		{
			m_bLoadAttempted = true;
			if(altpath && *altpath)
			{
				char trypath[260];
				sprintf_s(trypath, sizeof(trypath), "%s\\%s", altpath, m_pchModuleName);
				m_hModule = Sys_LoadModule( trypath );
			}

			if(m_hModule == NULL)
				m_hModule = Sys_LoadModule( m_pchModuleName );
		}

		if ( !m_hModule )
		{
			std::cerr << "Unable to get factory for " << m_pchModuleName << std::endl;
			return NULL;
		}

		return Sys_GetFactory( m_hModule );
	}

	void Unload()
	{
		if ( m_hModule )
		{
			Sys_UnloadModule( m_hModule );
			m_hModule = 0;
		}
	}

private:
	char const	*m_pchModuleName;
	CSysModule	*m_hModule;
	bool		m_bLoadAttempted;
};

class CSteamAPILoader
{
public:
	CSteamAPILoader() :
#ifdef _WIN32
	  steamservice("steamservice"),
#endif
	  steamclient("steamclient")
	{
		TryGetSteamDir();
	}

	CreateInterfaceFn Load()
	{
#ifdef _WIN32
		if(steamservice.GetFactory(m_pchSteamDirBin) == NULL)
			return NULL;
#endif
		if(steamclient.GetFactory(m_pchSteamDir) == NULL)
			return NULL;

		return steamclient.GetFactory(m_pchSteamDir);
	}
private:
	void TryGetSteamDir()
	{
		memset(m_pchSteamDir, 0, sizeof(m_pchSteamDir));
#ifdef _WIN32
		HKEY hRegKey;

		if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "Software\\Valve\\Steam", 0, KEY_QUERY_VALUE, &hRegKey) == ERROR_SUCCESS)
		{
			DWORD dwLength = sizeof(m_pchSteamDir);
			DWORD rc = RegQueryValueExA(hRegKey, "InstallPath", NULL, NULL, (BYTE*)m_pchSteamDir, &dwLength);
			RegCloseKey(hRegKey);

			strncpy(m_pchSteamDirBin, m_pchSteamDir, sizeof(m_pchSteamDir) - 4);
			strcat(m_pchSteamDirBin, "\\bin");

			SetDllDirectoryA(m_pchSteamDir);
		}
#endif
	}

#ifdef _WIN32
	CDllDemandLoader steamservice;
#endif
	CDllDemandLoader steamclient;

	char m_pchSteamDir[260];
	char m_pchSteamDirBin[260];
	bool m_bFullyInitialized;
};

#endif // INTERFACE_H
