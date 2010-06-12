#include <Steamworks.h>
#include "ServerBrowser.h"
#include <conio.h>
#include <iomanip>

int main(int argc, char* argv[])
{
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

	std::cout << " done. (" << serverBrowser->GetNumServers() << " servers found)" << std::endl;

	std::list<CGameServer>::iterator iter;
	std::list<CGameServer> List = serverBrowser->GetList();
	std::list<CGameServer> FinalList;

	int maxLenServerName = 0;
	int maxLenMapName = 0;
	int maxLenPing = 4;
	int maxLenPlayerCount = 7;

	for( iter = List.begin(); iter != List.end(); ++iter )
	{
		if (strncmp(iter->GetMap(), "tfdb_", 5))
			continue;

		if (strlen(iter->GetName()) > maxLenServerName)
			maxLenServerName = strlen(iter->GetName());

		if (strlen(iter->GetMap()) > maxLenMapName)
			maxLenMapName = strlen(iter->GetMap());

		FinalList.push_back(*iter);
	}

	maxLenServerName += 1;
	maxLenMapName += 1;
	maxLenPing += 1;
	maxLenPlayerCount += 1;

	std::cout << std::left;

	std::cout << std::endl << std::setw(maxLenServerName) << "Name" << std::setw(maxLenMapName) << "Map" << std::setw(maxLenPlayerCount) << "Players" << std::setw(maxLenPing) << "Ping" << std::endl;

	for( iter = FinalList.begin(); iter != FinalList.end(); ++iter )
	{
		std::cout << std::setw(maxLenServerName) << iter->GetName() << std::setw(maxLenMapName) << iter->GetMap() << std::right << std::setw(2) << iter->GetPlayers() << std::setw(1) << "/" << std::setw(2) << iter->GetMaxPlayers() << std::setw(3) << " " << std::left << std::setw(maxLenPing) << iter->GetPing() << std::endl;
	}

	while (!_kbhit()) {}

	SteamAPI_Shutdown();

	return 0;	
}