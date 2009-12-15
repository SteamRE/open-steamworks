#include "steamworks.h"

int main(int argc, char *argv[])
{
	SetEnvironmentVariableA("SteamAppId", "500");

	if(!SteamAPI_Init())
		return 0;

	((ISteamMatchmaking007 *)SteamMatchmaking())->RequestLobbyList();

	while(true)
	{
		SteamAPI_RunCallbacks();
	}

	SteamAPI_Shutdown();
	return 0;
}