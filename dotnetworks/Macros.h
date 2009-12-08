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

#define DECLARE_GET_INTERFACE() \
	Object^ InternalGetInterface( void* unmgdInterface, String^ version );

#define BEGIN_GET_INTERFACE(baseClass) \
	Object^ baseClass::InternalGetInterface( void* unmgdInterface, String^ version ) \
	{ \
		Object^ returnInterface;

#define RETURN_INTERFACE(inter, actual) \
	if (version == actual) \
		returnInterface = gcnew inter##( unmgdInterface )

#define END_GET_INTERFACE() \
		return returnInterface; \
	}

#define DECLARE_GET_INTERFACE_FUNC(interface) \
	Object^ GetI##interface##(SteamUserHandle^ hSteamUser, SteamPipeHandle^ hSteamPipe, String^ pchVersion )

#define DEFINE_GET_INTERFACE_FUNC(baseClass, interface) \
	Object^ baseClass::GetI##interface##(SteamUserHandle^ hSteamUser, SteamPipeHandle^ hSteamPipe, String^ pchVersion ) \
	{ \
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchVersion); \
		char *str = (char *)strPtr.ToPointer(); \
		Object^ returnInterface; \
		I##interface## *unmgdInterface = base->GetI##interface##(hSteamUser->base, hSteamPipe->base, str); \
		if (!unmgdInterface) \
		{ \
			Marshal::FreeHGlobal(strPtr); \
			return nullptr; \
		} \
		returnInterface = InternalGetInterface(unmgdInterface, pchVersion); \
		Marshal::FreeHGlobal(strPtr); \
		return returnInterface; \
	}


#define DECLARE_GET_UTIL_FUNC(interface) \
	Object^ GetI##interface##(SteamPipeHandle^ hSteamPipe, String^ pchVersion )

#define DEFINE_GET_UTIL_FUNC(baseClass, interface) \
	Object^ baseClass::GetI##interface##(SteamPipeHandle^ hSteamPipe, String^ pchVersion ) \
	{ \
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchVersion); \
		char *str = (char *)strPtr.ToPointer(); \
		Object^ returnInterface; \
		I##interface## *unmgdInterface = base->GetI##interface##(hSteamPipe->base, str); \
		if (!unmgdInterface) \
		{ \
			Marshal::FreeHGlobal(strPtr); \
			return nullptr; \
		} \
		returnInterface = InternalGetInterface(unmgdInterface, pchVersion); \
		Marshal::FreeHGlobal(strPtr); \
		return returnInterface; \
	}

#define DECLARE_GET_GENERIC_FUNC(interface) \
	Object^ GetI##interface##(SteamUserHandle^ hSteamUser, SteamPipeHandle^ hSteamPipe, String^ pchVersion )

#define DEFINE_GET_GENERIC_FUNC(baseClass, interface) \
	Object^ baseClass::GetI##interface##(SteamUserHandle^ hSteamUser, SteamPipeHandle^ hSteamPipe, String^ pchVersion ) \
	{ \
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchVersion); \
		char *str = (char *)strPtr.ToPointer(); \
		Object^ returnInterface; \
		void *unmgdInterface = base->GetI##interface##(hSteamUser->base, hSteamPipe->base, str); \
		if (!unmgdInterface) \
		{ \
			Marshal::FreeHGlobal(strPtr); \
			return nullptr; \
		} \
		returnInterface = InternalGetInterface(unmgdInterface, pchVersion); \
		Marshal::FreeHGlobal(strPtr); \
		return returnInterface; \
	}