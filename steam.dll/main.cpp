
#include "Common.h"

#include "CSteam006.h"
#include <time.h>

HMODULE valveSteam;

bool Init()
{
	// valve's steam.dll must be patched before loading
	valveSteam = LoadLibrary( "stean.dll" );

	return valveSteam != 0;
}

void Cleanup()
{
	if ( valveSteam )
		FreeLibrary( valveSteam );
}

BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved )
{
    switch( fdwReason ) 
    { 
        case DLL_PROCESS_ATTACH:
			if ( !Init() )
			{
				MessageBoxA( HWND_DESKTOP, "Unable to initialize steam.dll proxy.", "steam.dll", 0 );

				return false;
			}
            break;

        case DLL_PROCESS_DETACH:
			Cleanup();
            break;
    }

    return TRUE;
}


ADV_PROXY( void *, CreateInterface, (const char *pName, int *pReturnCode), (pName, pReturnCode))
	Log(
		"CreateInterface( pName = \"%s\" ) = 0x%x\n"
		"\t\tpReturnCode = %d\n\n",
		callerModule.szModule, pName, returnObj, pReturnCode
	);
END_PROXY()


CSteam006 *g_Steam006 = 0;

ADV_PROXY( void *, _f, ( const char *pName ), ( pName ) )
	if ( strcmp( pName, STEAM_INTERFACE_VERSION_006 ) == 0 )
	{
		if ( !g_Steam006 )
			g_Steam006 = new CSteam006( (ISteam006 *)returnObj );

		Log(
			"_f( pName = \"%s\" ) = 0x%x\n"
			"\t\tReturning own CSteam006: 0x%x\n\n",
			callerModule.szModule, pName, returnObj, g_Steam006
		);

		return (void *)g_Steam006;
	}

	Log(
		"_f( pName = \"%s\" ) = 0x%x\n\n",
		callerModule.szModule, pName, returnObj
	);
END_PROXY()