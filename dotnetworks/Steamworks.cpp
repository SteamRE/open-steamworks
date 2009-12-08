#pragma comment(lib, "delayimp") // for delay loading steam_api
#pragma comment(lib, "..\\steamclient")
#pragma comment(lib, "..\\steam_api")

#include "Steamworks.h"


namespace dotnetworks
{
	static Steamworks::Steamworks()
	{
		ClientFactory = Sys_GetFactory( "steamclient" );
	}

	Object^ Steamworks::CreateInterface(String^ name, [Out] int% error)
	{
		STR_FROM_MANAGED(name, str);

		int returnCode;
		void *unmgdInterface;

		Object^ returnInterface = nullptr;

		unmgdInterface = ClientFactory(str, &returnCode);
		if (!unmgdInterface)
		{
			Marshal::FreeHGlobal(strPtr);
			return nullptr;
		}
		
		if (name == CLIENTENGINE_INTERFACE_VERSION)
			returnInterface = gcnew ClientEngine( (IClientEngine *)unmgdInterface );
		if (name == STEAMCLIENT_INTERFACE_VERSION_008)
			returnInterface = gcnew SteamClient008( (ISteamClient008 *)unmgdInterface );

		STR_FREE(str);

		return returnInterface;
	}

	void Steamworks::Steam_LogOn(SteamUserHandle^ hUser, SteamPipeHandle^ hSteamPipe, uint64 ulSteamID)
	{
		::Steam_LogOn(hUser->base, hSteamPipe->base, ulSteamID);
	}
	void Steamworks::Steam_LogOff(SteamUserHandle^ hUser, SteamPipeHandle^ hSteamPipe)
	{
		::Steam_LogOff(hUser->base, hSteamPipe->base);
	}

	bool Steamworks::Steam_BLoggedOn(SteamUserHandle^ hUser, SteamPipeHandle^ hSteamPipe)
	{
		return ::Steam_BLoggedOn(hUser->base, hSteamPipe->base);
	}
	bool Steamworks::Steam_BConnected(SteamUserHandle^ hUser, SteamPipeHandle^ hSteamPipe)
	{
		return ::Steam_BConnected(hUser->base, hSteamPipe->base);
	}

	bool Steamworks::Steam_BGetCallback(SteamPipeHandle^ pipe, [Out] Callback^% callback, [Out] SteamCallHandle^% steamCall )
	{
		CallbackMsg_t callbackMsg;
		HSteamCall hSteamCall;

		bool ret = ::Steam_BGetCallback(pipe->base, &callbackMsg, &hSteamCall);

		callback = gcnew Callback( callbackMsg );
		steamCall = gcnew SteamCallHandle( hSteamCall );

		return ret;
	}
	void Steamworks::Steam_FreeLastCallback(SteamPipeHandle^ pipe)
	{
		::Steam_FreeLastCallback(pipe->base);
	}

	bool Steamworks::SteamAPI_Init()
	{
		return ::SteamAPI_Init();
	}
	bool Steamworks::SteamAPI_InitSafe()
	{
		return ::SteamAPI_InitSafe();
	}
	void Steamworks::SteamAPI_Shutdown()
	{
		::SteamAPI_Shutdown();
	}

	void Steamworks::SteamAPI_RunCallbacks()
	{
		::SteamAPI_RunCallbacks();
	}

	String^ Steamworks::SteamAPI_GetSteamInstallPath()
	{
		return gcnew String( ::SteamAPI_GetSteamInstallPath() );
	}
}
