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

#pragma once
#include <dlfcn.h>
#include <string>

class DynamicLibrary {
public:
	DynamicLibrary(std::string path) {
		m_handle = dlopen(path.c_str(), RTLD_NOW);
	}
	
	~DynamicLibrary() {
		// Note that we don't dlclose() our module. This is because it's possible
		// that dlclose() will put the module's refcount down to zero and the OS
		// to unload it. This would cause any reference to anything inside the
		// module to suddenly become invalid, which tends to be A Bad Thing(tm).
	}
	
	void * GetSymbol(std::string name) {
		if(!m_handle) return NULL;
		return dlsym(m_handle, name.c_str());
	}
	
	bool IsLoaded() const {
		return m_handle != NULL;
	}
	
private:
	void *m_handle;
	
	DynamicLibrary(const DynamicLibrary&);
	void operator=(const DynamicLibrary&);
};
