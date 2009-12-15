#include "steamworks.h"

class CLobbyBrowser
{
public:
	CCallResult<CLobbyBrowser, LobbyMatchList_t> m_SteamCallResultLobbyMatchList;
	void OnLobbyMatchListCallback( LobbyMatchList_t *pLobbyMatchList, bool bIOFailure )
	{
		std::cout << "qq " << pLobbyMatchList->m_nLobbiesMatching << std::endl;
	}
} qq;

int main(int argc, char *argv[])
{
	SetEnvironmentVariableA("SteamAppId", "500");

	if(!SteamAPI_Init())
		return 0;

	SteamAPICall_t hSteamAPICall = ((ISteamMatchmaking007 *)SteamMatchmaking())->RequestLobbyList();
	qq.m_SteamCallResultLobbyMatchList.Set(hSteamAPICall, &qq, &CLobbyBrowser::OnLobbyMatchListCallback );


	while(true)
	{
		SteamAPI_RunCallbacks();
	}

	SteamAPI_Shutdown();
	return 0;
}