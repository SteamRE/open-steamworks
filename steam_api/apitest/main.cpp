#include "steamworks.h"

int main(int argc, char *argv[])
{
	SteamAPI_Init();

	SteamAPI_Shutdown();
	return 0;
}