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

	friend bool operator==(const CallbackProvider& x, const CallbackProvider& y);
private:
	HMODULE module;
	SteamBGetCallbackFn getcallback;
	SteamFreeLastCallbackFn freelastcallback;
	SteamGetAPICallResultFn getapicallresult;
};

bool operator==(const CallbackProvider& x, const CallbackProvider& y)
{
	return x.module == y.module;
}

class CallbackManager
{
public:
	void AddCallbackProvider(HMODULE module);
private:
	bool callbackTryCatch;

	typedef std::vector<CallbackProvider> ProviderVector;
	ProviderVector providers;
} callbackmanager;