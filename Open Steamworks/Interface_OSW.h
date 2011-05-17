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

#if !defined(INTERFACEOSW_H) && !defined(CLANG)
#define INTERFACEOSW_H
#ifdef _WIN32
#pragma once
#endif

#include <cstdlib>
#include <iostream>
#include <string>
#include <memory>

#ifdef _WIN32
	#define TARGET_OS_WIN32 1
	#include <windows.h>
	#include <tchar.h>
	#include "Win32Library.h"
#elif defined(__APPLE_CC__)
	#define TARGET_OS_MAC 1
	#include "POSIXLibrary.h"
	#include <CoreServices/CoreServices.h>
	#include <sys/param.h>
#else
	#define TARGET_OS_UNIX 1
	#include <libgen.h>
	#include <limits.h>
	#include "POSIXLibrary.h"
#endif

#define CREATEINTERFACE_PROCNAME "CreateInterface"
#define FACTORY_PROCNAME "_f"

class CSteamAPILoader
{
public:
	CSteamAPILoader() {
		TryGetSteamDir();
		TryLoadLibraries();
	}
	
	CreateInterfaceFn Load()
	{
		return (CreateInterfaceFn)m_steamclient->GetSymbol( CREATEINTERFACE_PROCNAME );
	}

	FactoryFn LoadFactory()
	{
		return (FactoryFn)m_steam->GetSymbol( FACTORY_PROCNAME );
	}

	std::string GetSteamDir() {
		return m_steamDir;
	}
	
	DynamicLibrary *GetSteamClientModule()
	{
		return m_steamclient.get();
	}
	DynamicLibrary *GetSteamModule()
	{
		return m_steam.get();
	}


private:
	void TryGetSteamDir()
	{
#if TARGET_OS_WIN32
		HKEY hRegKey;

		if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "Software\\Valve\\Steam", 0, KEY_QUERY_VALUE, &hRegKey) == ERROR_SUCCESS)
		{
			char pchSteamDir[MAX_PATH];
			DWORD dwLength = sizeof(pchSteamDir);
			RegQueryValueExA(hRegKey, "InstallPath", NULL, NULL, (BYTE*)pchSteamDir, &dwLength);
			RegCloseKey(hRegKey);
			
			m_steamDir = pchSteamDir;
		}
#elif TARGET_OS_MAC
		CFURLRef url;
		OSStatus err = LSFindApplicationForInfo(kLSUnknownCreator, CFSTR("com.valvesoftware.steam"), NULL, NULL, &url);
		if(err) return;
		
		UInt8 fsPath[MAXPATHLEN];
		Boolean success = CFURLGetFileSystemRepresentation(url, true, fsPath, sizeof(fsPath));
		
		if(success)
			m_steamDir = (const char *)fsPath;

		CFRelease(url);
#else
		// We don't know where to find Steam on this platform, so we're going
		// to say it lives in the same directory as our executable
		char pchSteamDir[PATH_MAX];
		if( readlink("/proc/self/exe", pchSteamDir, sizeof(pchSteamDir)) != -1)
		{
			m_steamDir = dirname(pchSteamDir);
		}
		else
			m_steamDir = ".";
#endif
	}
	
	void TryLoadLibraries()
	{
#if TARGET_OS_WIN32

		// steamclient.dll expects to be able to load tier0_s without an absolute
		// path, so we'll need to add the steam dir to the search path.
		SetDllDirectoryA( m_steamDir.c_str() );

		m_steamclient.reset( new DynamicLibrary( m_steamDir + "\\steamclient.dll" ) );
		m_steam.reset( new DynamicLibrary( m_steamDir + "\\steam.dll" ) );

#elif TARGET_OS_MAC

		std::string libsPath;
		if(!m_steamDir.empty()) {
			libsPath = m_steamDir + "/Contents/MacOS/osx32/";
		} else {
			// The user doesn't have steam installed, fall back to using the 
			// loader's runtime search paths
			libsPath = "@rpath/";
		}
		
		m_steamclient.reset( new DynamicLibrary( libsPath + "steamclient.dylib" ) );
		m_steam.reset( new DynamicLibrary( libsPath + "libsteam.dylib" ) );

#else

		m_steamclient.reset( new DynamicLibrary( m_steamDir + "/steamclient.so" ) );
		m_steam.reset( new DynamicLibrary( m_steamDir + "/libsteam.so" ) );

#endif
	}
	
	std::string m_steamDir;

	std::auto_ptr<DynamicLibrary> m_steamclient;
	std::auto_ptr<DynamicLibrary> m_steam;
};
#endif // INTERFACEOSW_H
