#define STEAMWORKS_CLIENT_INTERFACES
#define _CRT_SECURE_NO_WARNINGS
#define STEAM
#define STEAM_API_EXPORTS
#include "..\\open steamworks\\Steamworks.h"
#include <windows.h>
#undef UNICODE
#include <tlhelp32.h>
#define UNICODE

#include "macros.h"
#include "CClientEngine.h"

#include "CSteamClient008.h"

HMODULE valveClient;


void Log(char *msg, ...)
{
	FILE *logFile = fopen("MySteam.log", "a");
	FILE *log2 = fopen("steamclient.proxy.log", "a");
	FILE *log3 = fopen("proxy.log", "a");

	char buffer[1024];
	memset(buffer, 0, 1024);

	va_list args;
	va_start(args, msg);

	vsprintf(buffer, msg, args);

	va_end(args);

	SYSTEMTIME time;
	GetLocalTime(&time);

	char szLine[2048];
	memset(szLine, 0, 2048);
	sprintf(szLine, "%02d:%02d:%02d:%03d \t%s",  time.wHour, time.wMinute, time.wSecond, time.wMilliseconds, buffer);

	fputs(szLine, logFile);
	fputs(szLine, log2);
	fputs(szLine, log3);

	fflush(logFile);
	fflush(log2);
	fflush(log3);

	printf(szLine);

	fclose(logFile);
	fclose(log2);
	fclose(log3);
}

// SteamClient008
DECL_PROXY(void*, CreateInterface, ( const char *pName, int *pErrorCode ))
	Log("[%s]\tCreateInterface( pName = \"%s\" )\n", callerModule.szModule, pName);

	static CClientEngine *myClientEngine;
	if (strcmp(pName, CLIENTENGINE_INTERFACE_VERSION) == 0)
	{
		if (!myClientEngine)
		{
			void *iclientEngine = OrigCreateInterface(pName, pErrorCode);
			myClientEngine = new CClientEngine(iclientEngine);
		}

		return (void*)myClientEngine;
	}

	static CSteamClient008 *mySteamClient;
	if (strcmp(pName, STEAMCLIENT_INTERFACE_VERSION_008) == 0)
	{
		if (!mySteamClient)
		{
			mySteamClient = new CSteamClient008(OrigCreateInterface(pName, pErrorCode));
		}

		return (void*)mySteamClient;
	}
RETURN_PROXY(CreateInterface, (pName, pErrorCode))

DECL_PROXY(bool, Steam_BGetCallback, ( HSteamPipe hSteamPipe, CallbackMsg_t *pCallback, HSteamCall *phSteamCall ))
	bool retVal = OrigSteam_BGetCallback( hSteamPipe, pCallback, phSteamCall );
	if (retVal)
		Log("[%s]\tSteam_BGetCallback( hSteamPipe = %d ) = Callback[ hSteamUser = %d, m_iCallback = %d]\n", callerModule.szModule, hSteamPipe, pCallback->m_hSteamUser, pCallback->m_iCallback);
	return retVal;
}

DECL_PROXY(void, Steam_FreeLastCallback, ( HSteamPipe hSteamPipe ))
	Sleep(10);
	Log("[%s]\tSteam_FreeLastCallback( hSteamPipe = %d )\n", callerModule.szModule, hSteamPipe );
RETURN_PROXY(Steam_FreeLastCallback, (hSteamPipe))


PROXY(void, Steam_LogOn, ( HSteamUser hUser, HSteamPipe hSteamPipe, uint64 ulSteamID ), (hUser, hSteamPipe, ulSteamID))
PROXY(void, Steam_LogOff, ( HSteamUser hUser, HSteamPipe hSteamPipe ), (hUser, hSteamPipe))
PROXY(bool, Steam_BLoggedOn, ( HSteamUser hUser, HSteamPipe hSteamPipe ), (hUser, hSteamPipe))
PROXY(bool, Steam_BConnected, ( HSteamUser hUser, HSteamPipe hSteamPipe ), (hUser, hSteamPipe))
//PROXY(int, Steam_InitiateGameConnection, ( HSteamUser hUser, HSteamPipe hSteamPipe, void *pBlob, int cbMaxBlob, uint64 steamID, int nGameAppID, uint32 unIPServer, uint16 usPortServer, bool bSecure );
//PROXY(void, Steam_TerminateGameConnection, ( HSteamUser hUser, HSteamPipe hSteamPipe, uint32 unIPServer, uint16 usPortServer );


PROXY(HSteamPipe, Steam_CreateSteamPipe, (), ())
PROXY(bool, Steam_BReleaseSteamPipe, ( HSteamPipe pipe), (pipe))
PROXY(HSteamUser, Steam_CreateLocalUser, ( HSteamPipe *pipe ), (pipe))
PROXY(HSteamUser, Steam_CreateGlobalUser, ( HSteamPipe *pipe ), (pipe))
PROXY(HSteamUser, Steam_ConnectToGlobalUser, ( HSteamPipe pipe ), (pipe))
PROXY(void, Steam_ReleaseUser, ( HSteamPipe hSteamPipe, HSteamUser hUser ), (hSteamPipe, hUser))
PROXY(void, Steam_SetLocalIPBinding, ( uint32 unIP, uint16 usLocalPort ), (unIP, usLocalPort))

void Init()
{
	// preload libraries
	/*LoadLibrary(L"vstdlib_s.dll");
	LoadLibrary(L"tier0_s.dll");
	LoadLibrary(L"steam.dll");*/

	valveClient = LoadLibrary( L"steanclient.dll" );
	AllocConsole();
}


BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Init();
		break;

	case DLL_PROCESS_DETACH:
		//Cleanup();
		break;
	}

	return TRUE;
}

