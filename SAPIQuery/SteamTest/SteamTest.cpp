#define STEAM_API_NON_VERSIONED_INTERFACES

#include <Steamworks.h>

#include "ServerBrowser.h"

#include "CUtlVector.h"

#include <conio.h>
#include <iomanip>

int main(int argc, char* argv[])
{
	SetEnvironmentVariableA("SteamAppId", "440");

	if (!SteamAPI_Init())
	{
		return 1;
	}

	CServerBrowser *serverBrowser;
	serverBrowser = new CServerBrowser();
	serverBrowser->RefreshInternetServers();

	std::cout << "Refreshing server list ";

	while (serverBrowser->IsRefreshing())
	{
		SteamAPI_RunCallbacks();
		Sleep(1);
	}

	std::cout << " done. (" << serverBrowser->m_ListGameServers.Count() << " servers found)" << std::endl;

	CUtlVector<CGameServer> DodgeballServers;

	size_t maxLenServerName = 4;
	size_t maxLenMapName = 3;
	size_t maxLenPing = 4;
	size_t maxLenPlayerCount = 7;
	size_t maxLenSteamID = 7;

	for ( int i = 0; i < serverBrowser->m_ListGameServers.Count(); ++i )
	{
		if ((strncmp(serverBrowser->m_ListGameServers.Element(i).GetMap(), "tfdb_", 5) != 0) /* && (strncmp(serverBrowser->m_ListGameServers.Element(i).GetMap(), "db_", 3) != 0) */ )
			continue;

		if (strlen(serverBrowser->m_ListGameServers.Element(i).GetName()) > maxLenServerName)
			maxLenServerName = strlen(serverBrowser->m_ListGameServers.Element(i).GetName());

		if (strlen(serverBrowser->m_ListGameServers.Element(i).GetMap()) > maxLenMapName)
			maxLenMapName = strlen(serverBrowser->m_ListGameServers.Element(i).GetMap());

		if (strlen(serverBrowser->m_ListGameServers.Element(i).GetSteamID().SteamRender()) > maxLenSteamID)
			maxLenSteamID = strlen(serverBrowser->m_ListGameServers.Element(i).GetSteamID().SteamRender());

		DodgeballServers.AddToTail(serverBrowser->m_ListGameServers.Element(i));
	}

	maxLenServerName += 1;
	maxLenMapName += 1;
	maxLenPing += 1;
	maxLenPlayerCount += 1;
	maxLenSteamID += 1;

	std::cout << std::left;

	std::cout << std::endl << std::setw(maxLenServerName) << "Name" << std::setw(maxLenMapName) << "Map" << std::setw(maxLenPlayerCount) << "Players" << std::setw(maxLenPing) << "Ping" << std::setw(maxLenSteamID) << "SteamID" << std::endl;

	for ( int i = 0; i < DodgeballServers.Count(); ++i )
	{
		std::cout << std::setw(maxLenServerName) << DodgeballServers.Element(i).GetName() << std::setw(maxLenMapName) << DodgeballServers.Element(i).GetMap() << std::right << std::setw(2) << DodgeballServers.Element(i).GetPlayers() << std::setw(1) << "/" << std::setw(2) << DodgeballServers.Element(i).GetMaxPlayers() << std::setw(3) << " " << std::left << std::setw(maxLenPing) << DodgeballServers.Element(i).GetPing() << std::setw(maxLenSteamID) << DodgeballServers.Element(i).GetSteamID().RenderLadyGaga() << std::endl;
	}

	//while (!_kbhit()) {}
	
	//SteamMatchmakingServers()->ServerRules(1123437328, 27015, serverBrowser); // Broken

	while (!_kbhit()) {}

	SteamAPI_Shutdown();

	return 0;	
}