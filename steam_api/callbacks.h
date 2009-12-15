#pragma once

class CallbackProvider
{
public:
	void Set(HMODULE mod);
	void ResolveExports();

	inline bool Steam_BGetCallback( HSteamPipe hSteamPipe, CallbackMsg_t *pCallbackMsg, HSteamCall *phSteamCall ) { return getcallback(hSteamPipe, pCallbackMsg, phSteamCall); }
	inline void Steam_FreeLastCallback( HSteamPipe hSteamPipe ) { freelastcallback(hSteamPipe); }
	inline bool Steam_GetAPICallResult( HSteamPipe hSteamPipe, SteamAPICall_t hSteamAPICall, void *pCallback, int cubCallback, int iCallbackExpected, bool *pbFailed) { return getapicallresult(hSteamPipe, hSteamAPICall, pCallback, cubCallback, iCallbackExpected, pbFailed); }

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
	void RunCallbacks(HSteamPipe pipe, bool bGameServer);

	void RegisterCallback(int iCallback, CCallbackBase *callback);
	void UnRegisterCallback(CCallbackBase *callback);

	void RegisterAPICallResult(SteamAPICall_t apiCall, CCallbackBase *callback);
	void UnRegisterAPICallResult(SteamAPICall_t apiCall, CCallbackBase *callback);

	HSteamUser currentUser;
private:
	void RunAPICallbacks(HSteamPipe pipe, SteamAPICallCompleted_t *call);
	
	typedef boost::unordered_multimap<int, CCallbackBase *> CallbacksMap;
	CallbacksMap callbacks;
	typedef boost::unordered_map<SteamAPICall_t, CCallbackBase *> APICallsMap;
	APICallsMap apicalls;

	bool callbackTryCatch;

	CallbackProvider provider;
};

extern CallbackManager callbackmanager;

S_API void STEAM_CALL SteamAPI_RegisterCallback( class CCallbackBase *pCallback, int iCallback );
S_API void STEAM_CALL SteamAPI_UnregisterCallback( class CCallbackBase *pCallback );

S_API void STEAM_CALL SteamAPI_RegisterCallResult( class CCallbackBase *pCallback, SteamAPICall_t hAPICall );
S_API void STEAM_CALL SteamAPI_UnregisterCallResult( class CCallbackBase *pCallback, SteamAPICall_t hAPICall );

S_API void STEAM_CALL Steam_RunCallbacks( HSteamPipe hSteamPipe, bool bGameServerCallbacks );
S_API void STEAM_CALL Steam_RegisterInterfaceFuncs(void *hModule);

S_API HSteamUser STEAM_CALL Steam_GetHSteamUserCurrent();