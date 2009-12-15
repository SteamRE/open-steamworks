#include "stdafx.h"
#include "callbacks.h"

CallbackManager callbackmanager;

void CallbackProvider::ResolveExports()
{
	getcallback = (SteamBGetCallbackFn)GetProcAddress(module, "Steam_BGetCallback");
	freelastcallback = (SteamFreeLastCallbackFn)GetProcAddress(module, "Steam_FreeLastCallback");
	getapicallresult = (SteamGetAPICallResultFn)GetProcAddress(module, "Steam_GetAPICallResult");
}

void CallbackProvider::Set(HMODULE mod)
{
	if(module == mod)
		return;

	module = mod;
	ResolveExports();
}

void CallbackManager::SetCallbackProvider(HMODULE module)
{
	provider.Set(module);
}

S_API void STEAM_CALL Steam_RegisterInterfaceFuncs(void *hModule)
{
	callbackmanager.SetCallbackProvider((HMODULE)hModule);
}