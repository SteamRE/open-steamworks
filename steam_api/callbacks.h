#pragma once

class CallbackProvider
{
public:
	CallbackProvider(HMODULE module) : module(module) {};
	CallbackProvider(const CallbackProvider& other) : module(other.module), getcallback(other.getcallback), freelastcallback(other.freelastcallback), getapicallresult(other.getapicallresult) {};

	void ResolveExports()
	{
		getcallback = (SteamBGetCallbackFn)GetProcAddress(module, "Steam_BGetCallback");
		freelastcallback = (SteamFreeLastCallbackFn)GetProcAddress(module, "Steam_FreeLastCallback");
		getapicallresult = (SteamGetAPICallResultFn)GetProcAddress(module, "Steam_GetAPICallResult");
	}

	bool operator==( const CallbackProvider& y) { return this->module == y.module; }
private:
	HMODULE module;
	SteamBGetCallbackFn getcallback;
	SteamFreeLastCallbackFn freelastcallback;
	SteamGetAPICallResultFn getapicallresult;
};



class CallbackManager
{
public:
	void AddCallbackProvider(HMODULE module);
private:
	bool callbackTryCatch;

	typedef std::vector<CallbackProvider> ProviderVector;
	ProviderVector providers;
} callbackmanager;