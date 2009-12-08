// what is this?
//
// this example program maxes the stats and unlocks all achievements for every
// possible game that the local user owns
//

#include "SteamclientAPI.h"


//#pragma comment(lib, "..\\steamclient")

#undef max // so we can use numeric_limits<T>::max()
#include <limits>
#include <iostream>


void ShowError(std::string msg, int errorCode = 0)
{
	std::cout << "Error: " << msg;
	if (errorCode > 0)
		std::cout<< " Error code: " << errorCode;
	
	std::cout << std::flush;

	getchar();
	exit(EXIT_FAILURE);
}

int main()
{
	ISteamClient008 *steamClient;
	if ( !Sys_LoadInterface( "steamclient", STEAMCLIENT_INTERFACE_VERSION_008, NULL, (void**)&steamClient ) )
	{

		ShowError("Unable to get ISteamClient.");

	}

	HSteamPipe pipe = steamClient->CreateSteamPipe();
	if (!pipe)
		ShowError("Unable to create steam pipe, please ensure that steam is running and you are connected.");

	HSteamUser user = steamClient->ConnectToGlobalUser(pipe);
	if (!user)
		ShowError("Unable connect to global user, please ensure that steam is running and you are connected.");

	ISteamUserStats002 *userStats = (ISteamUserStats002 *)steamClient->GetISteamUserStats(user, pipe, STEAMUSERSTATS_INTERFACE_VERSION_002);
	if (!userStats)
		ShowError("Unable to get ISteamUserStats.");

	AppId_t maxApps = std::numeric_limits<AppId_t>::max();
	for (AppId_t appId = 0; appId < maxApps; appId++)
	{

		CGameID gameId(appId);

		if (appId % 500 == 0)
			std::cout << "Working on AppID: " << appId << std::endl;

		if (!userStats->RequestCurrentStats(gameId))
		{
			std::cout << "Unable to request stats for " << appId << ", no game ownership or game does not exist." << std::endl;
			continue;
		}

		uint32 maxStats = userStats->GetNumStats(gameId);
		if (maxStats > 0)
		{
			for (uint32 x = 0; x < maxStats; x++)
			{
				const char *name = userStats->GetStatName(gameId, x);
				if (!userStats->SetStat(gameId, name, std::numeric_limits<int>::max()))
				{
					std::cout << "Unable to set stat '" << name << "' to maximum value, or already maxed." << std::endl;
					continue;
				}

				std::cout << "Stat '" << name << "' maxed." << std::endl;
			}
		}

		uint32 maxAchievements = userStats->GetNumAchievements(gameId);
		if (maxAchievements > 0)
		{
			for (uint32 x = 0; x < maxAchievements; x++)
			{
				const char *name = userStats->GetAchievementName(gameId, x);
				if (!userStats->SetAchievement(gameId, name))
				{
					std::cout << "Unable to achieve '" << name << "'..." << std::endl;
					continue;
				}
				
				std::cout << "Achievement '" << name << "' achieved." << std::endl;
			}
		}

		// anything worth storing?
		if (maxStats > 0 || maxAchievements > 0)
		{
			if (!userStats->StoreStats(gameId))
			{
				std::cout << "Unable to store stats for " << gameId.AppID() << "..." << std::endl;
				continue;
			}
		}
	}
}