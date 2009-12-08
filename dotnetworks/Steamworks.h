#pragma once

#define STEAMWORKS_CLIENT_INTERFACES
#include "SteamclientAPI.h"

#include "ClientEngine.h"
#include "SteamClient008.h"

#include "Callback.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;


namespace dotnetworks
{

	public ref class Steamworks
	{
	private:
		static Steamworks();

	public:
		static Object^ CreateInterface(String^ name, [Out] int% error);

		static void Steam_LogOn(SteamUserHandle^ hUser, SteamPipeHandle^ hSteamPipe, uint64 ulSteamID);
		static void Steam_LogOff(SteamUserHandle^ hUser, SteamPipeHandle^ hSteamPipe);

		static bool Steam_BLoggedOn(SteamUserHandle^ hUser, SteamPipeHandle^ hSteamPipe);
		static bool Steam_BConnected(SteamUserHandle^ hUser, SteamPipeHandle^ hSteamPipe);

		static bool Steam_BGetCallback(SteamPipeHandle^ pipe, [Out] Callback^% callback, [Out] SteamCallHandle^% steamCall );
		static void Steam_FreeLastCallback(SteamPipeHandle^ pipe);

		static bool SteamAPI_Init();
		static bool SteamAPI_InitSafe();
		static void SteamAPI_Shutdown();

		static void SteamAPI_RunCallbacks();

		static String^ SteamAPI_GetSteamInstallPath();

	private:
		static CreateInterfaceFn ClientFactory;
	};
}
