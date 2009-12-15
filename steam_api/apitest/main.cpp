#include "steamworks.h"

class CLobbyBrowser
{
public:
	CLobbyBrowser() : m_CallbackLobbyMatchList( this, &CLobbyBrowser::OnLobbyMatchListCallback ) {};

	CCallResult<CLobbyBrowser, LobbyMatchList_t> m_SteamCallResultLobbyMatchList;
	void OnLobbyMatchListCallback( LobbyMatchList_t *pLobbyMatchList, bool bIOFailure )
	{
		std::cout << "qq " << pLobbyMatchList->m_nLobbiesMatching << " " << bIOFailure << std::endl;

	}

	STEAM_CALLBACK( CLobbyBrowser, OnLobbyMatchListCallback, LobbyMatchList_t, m_CallbackLobbyMatchList );
} qq;

void CLobbyBrowser::OnLobbyMatchListCallback( LobbyMatchList_t *pLobbyMatchList )
{
	std::cout << "qq regular callback " << pLobbyMatchList->m_nLobbiesMatching << std::endl;

	throw new std::exception("qq");
}

int main(int argc, char *argv[])
{
	SetEnvironmentVariableA("SteamAppId", "500");

	if(!SteamAPI_Init())
		return 0;

	SteamAPICall_t hSteamAPICall = ((ISteamMatchmaking007 *)SteamMatchmaking())->RequestLobbyList();
	qq.m_SteamCallResultLobbyMatchList.Set(hSteamAPICall, &qq, &CLobbyBrowser::OnLobbyMatchListCallback );

	SteamAPI_SetTryCatchCallbacks(true);

	for(int i = 0; i < 100; i++)
	{
		SteamAPI_RunCallbacks();
		Sleep(100);
	}

	SteamAPI_Shutdown();
	return 0;
}