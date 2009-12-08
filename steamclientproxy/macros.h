#pragma once

void Log(char *msg, ...);

#define ENSURE_PROXY(name) \
	if ( !Orig##name ) \
		Orig##name = (name##Fn)GetProcAddress(valveClient, #name);

#define DECL_PROXY(ret, name, params) \
	typedef ret (*name##Fn) params; \
	name##Fn Orig##name; \
	S_API ret STEAM_CALL name params \
	{ \
		unsigned int retAddr = GetReturnAddress(); \
		ENSURE_PROXY(name); \
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

#define RETURN_PROXY(name, params) \
		return Orig##name params; \
	}

#define LOG_PROXY(name) \
	Log("[%s]\t"#name"\n", callerModule.szModule);	Log(#name"\n");

#define PROXY(ret, name, params, retParams) \
	DECL_PROXY(ret, name, params) \
	LOG_PROXY(name) \
	RETURN_PROXY(name, retParams);

#define DECL_CLASS_PROXY(ret, name, params) \
	virtual ret name params \
	{ \
		unsigned int retAddr = ::GetReturnAddress(); \
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

#define LOG_CLASS_PROXY(name) \
	::Log((char*)("[%s]\t" + std::string(className) + "::"#name"\n").c_str(), callerModule.szModule);

#define RETURN_CLASS_PROXY(name, params) \
		return base->name params; \
	}

#define CLASS_PROXY(ret, name, params, retParams) \
	DECL_CLASS_PROXY(ret, name, params) \
	LOG_CLASS_PROXY(name) \
	RETURN_CLASS_PROXY(name, retParams) 

#define GET_IFACE_CLASS_PROXY(ret, name, params, retParams) \
	DECL_CLASS_PROXY(ret, name, params) \
		::Log((char*)("[%s]\t" + std::string(className) + "::"#name"( hSteamUser = %d, hSteamPipe = %d, pchVersion = \"%s\" )\n").c_str(), callerModule.szModule, hSteamUser, hSteamPipe, pchVersion); \
	RETURN_CLASS_PROXY(name, retParams) \


#define DEFINE_PROXY_CLASS(name, basetype) \
	class name \
	{ \
	private: \
		basetype *base; \
		char *className ; \
	public: \
		name(void *inherit) \
		{ \
			base = (basetype *)inherit; \
			className = #name; \
		}

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
