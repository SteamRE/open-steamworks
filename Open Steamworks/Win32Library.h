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

class DynamicLibrary {
public:
	DynamicLibrary(std::string path) {
		m_handle = LoadLibraryA( path.c_str() );
	}
	
	~DynamicLibrary() {
		if(m_handle)
			FreeLibrary( m_handle );
	}
	
	void * GetSymbol(std::string name) {
		if(!m_handle) return NULL;
		return (void *)GetProcAddress( m_handle, name.c_str() );
	}
	
	bool IsLoaded() const {
		return m_handle != NULL;
	}
	
private:
	HMODULE m_handle;
	
	DynamicLibrary(const DynamicLibrary&);
	void operator=(const DynamicLibrary&);
};
