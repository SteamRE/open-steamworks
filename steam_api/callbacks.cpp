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

void CallbackManager::RunCallbacks(HSteamPipe pipe, bool bGameServer)
{
	CallbackMsg_t callbackMsg;
	HSteamCall steamCall;

	steamclient->RunFrame();

	if( provider.Steam_BGetCallback(pipe, &callbackMsg, &steamCall) )
	{
		currentUser = callbackMsg.m_hSteamUser;

		int32 callBack = callbackMsg.m_iCallback;
		ECallbackType type = (ECallbackType)((callBack / 100) * 100);
		std::cout << "[DEBUG] Callback: " << callBack << ", Type: " << EnumString<ECallbackType>::From(type) << ", Size: " << callbackMsg.m_cubParam << std::endl;

		std::pair<CallbacksMap::iterator, CallbacksMap::iterator> range = callbacks.equal_range(callbackMsg.m_iCallback);
		for(CallbacksMap::const_iterator iter = range.first; iter != range.second; ++iter)
		{
			CCallbackBase *callback = iter->second;

			if(bGameServer && !(callback->m_nCallbackFlags & CCallbackBase::k_ECallbackFlagsGameServer))
				continue;

			callback->Run(callbackMsg.m_pubParam);
		}

		provider.Steam_FreeLastCallback(pipe);
	}
}




void CallbackManager::RegisterCallback(int iCallback, CCallbackBase *callback)
{
	// since the property is there I'm going to set it so we have it for unregister, I'm not sure if the real steam_api uses it
	// it has to be safe because if you were to register a CCallback with multiple callback numbers, who knows what one would be erased
	callback->m_iCallback = iCallback;

	callbacks.insert(CallbacksMap::value_type(iCallback, callback));
}

void CallbackManager::UnRegisterCallback(CCallbackBase *callback)
{
	std::pair<CallbacksMap::iterator, CallbacksMap::iterator> range = callbacks.equal_range( callback->m_iCallback );

	CallbacksMap::const_iterator iter = range.first;
	while(iter != range.second)
	{
		if(iter->second == callback)
			iter = callbacks.erase(iter);
		else
			++iter;
	}
}




void CallbackManager::RegisterAPICallResult(SteamAPICall_t apiCall, CCallbackBase *callback)
{
	apicalls.insert(APICallsMap::value_type(apiCall, callback));
}

void CallbackManager::UnRegisterAPICallResult(SteamAPICall_t apiCall, CCallbackBase *callback)
{
	std::pair<APICallsMap::iterator, APICallsMap::iterator> range = apicalls.equal_range( apiCall );

	APICallsMap::const_iterator iter = range.first;
	while(iter != range.second)
	{
		if(iter->second == callback)
			iter = apicalls.erase(iter);
		else
			++iter;
	}
}




S_API void STEAM_CALL SteamAPI_RegisterCallback( class CCallbackBase *pCallback, int iCallback )
{
	callbackmanager.RegisterCallback(iCallback, pCallback);
}

S_API void STEAM_CALL SteamAPI_UnregisterCallback( class CCallbackBase *pCallback )
{
	callbackmanager.UnRegisterCallback(pCallback);
}




S_API void STEAM_CALL SteamAPI_RegisterCallResult( class CCallbackBase *pCallback, SteamAPICall_t hAPICall )
{
	callbackmanager.RegisterAPICallResult(hAPICall, pCallback);
}

S_API void STEAM_CALL SteamAPI_UnregisterCallResult( class CCallbackBase *pCallback, SteamAPICall_t hAPICall )
{
	callbackmanager.UnRegisterAPICallResult(hAPICall, pCallback);
}




S_API void STEAM_CALL Steam_RunCallbacks( HSteamPipe hSteamPipe, bool bGameServerCallbacks )
{
	callbackmanager.RunCallbacks(hSteamPipe, bGameServerCallbacks);
}

S_API void STEAM_CALL Steam_RegisterInterfaceFuncs(void *hModule)
{
	callbackmanager.SetCallbackProvider((HMODULE)hModule);
}



S_API HSteamUser STEAM_CALL Steam_GetHSteamUserCurrent()
{
	return callbackmanager.currentUser;
}