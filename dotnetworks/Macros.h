#pragma once


#define ARRAY_COPY(from, to, size) \
	Marshal::Copy(from##Ptr, to, 0, size) 

#define ARRAY_TO_PTR_NOCOPY(to, size) \
	IntPtr to##Ptr = Marshal::AllocHGlobal(size); \
	void *to = to##Ptr.ToPointer()

#define ARRAY_TO_PTR(from, to, size) \
	IntPtr to##Ptr = Marshal::AllocHGlobal(size); \
	Marshal::Copy(from, 0, to##Ptr, size); \
	void *to = to##Ptr.ToPointer()

#define ARRAY_FREE(name) \
	Marshal::FreeHGlobal(name##Ptr)

#define STR_FROM_MANAGED(from, to) \
	IntPtr to##Ptr = Marshal::StringToHGlobalAnsi(from); \
	char *to = (char *)to##Ptr.ToPointer()

#define STR_FREE(name) \
	Marshal::FreeHGlobal(name##Ptr)

#define GET_INTERFACE_FUNC( interface ) \
	Object^ GetI##interface( SteamUserHandle^ hSteamUser, SteamPipeHandle^ hSteamPipe, String^ pchVersion ) \
	{ \
		STR_FROM_MANAGED( pchVersion, version ); \
		void *unmgdInterface = (void *)base->GetI##interface( hSteamUser->base, hSteamPipe->base, version ); \
		STR_FREE( version );\
		if ( !unmgdInterface ) \
			return nullptr; \
		return InternalGetInterface( unmgdInterface, pchVersion ); \
	}

#define GET_UTIL_FUNC( interface ) \
	Object^ GetI##interface( SteamPipeHandle^ hSteamPipe, String^ pchVersion ) \
	{ \
		STR_FROM_MANAGED( pchVersion, version ); \
		I##interface *unmgdInterface = base->GetI##interface( hSteamPipe->base, version ); \
		STR_FREE( version );\
		if ( !unmgdInterface ) \
			return nullptr; \
		return InternalGetInterface( unmgdInterface, pchVersion ); \
	}


#define BEGIN_GET_INTERFACE() \
	Object^ InternalGetInterface( void* unmgdInterface, String^ version ) \
	{ \
		Object^ returnInterface;

#define RETURN_INTERFACE( interface, ver ) \
	if ( version == ver ) \
		returnInterface = gcnew interface( unmgdInterface );

#define END_GET_INTERFACE() \
		return returnInterface; \
	}