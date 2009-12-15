#pragma once

class CallbackProvider
{
public:
	void Set(HMODULE mod);
	void ResolveExports();
private:
	HMODULE module;
	SteamBGetCallbackFn getcallback;
	SteamFreeLastCallbackFn freelastcallback;
	SteamGetAPICallResultFn getapicallresult;
};

class CallbackManager
{
public:
	void SetCallbackProvider(HMODULE module);
private:
	bool callbackTryCatch;

	CallbackProvider provider;
};

extern CallbackManager callbackmanager;

S_API void STEAM_CALL Steam_RegisterInterfaceFuncs(void *hModule);