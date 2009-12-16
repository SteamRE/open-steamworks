#include "steamworks.h"

class CLobbyBrowser
{
public:
	CLobbyBrowser() : m_CallbackLobbyMatchList( this, &CLobbyBrowser::OnLobbyMatchListCallback ),
		m_CallbackLogonSuccess( this, &CLobbyBrowser::OnLogonSuccess) {};

	CCallResult<CLobbyBrowser, LobbyMatchList_t> m_SteamCallResultLobbyMatchList;
	void OnLobbyMatchListCallback( LobbyMatchList_t *pLobbyMatchList, bool bIOFailure )
	{
		std::cout << "qq " << pLobbyMatchList->m_nLobbiesMatching << " " << bIOFailure << std::endl;

	}

	STEAM_CALLBACK( CLobbyBrowser, OnLobbyMatchListCallback, LobbyMatchList_t, m_CallbackLobbyMatchList );

	STEAM_GAMESERVER_CALLBACK( CLobbyBrowser, OnLogonSuccess, LogonSuccess_t, m_CallbackLogonSuccess );
} qq;

void CLobbyBrowser::OnLobbyMatchListCallback( LobbyMatchList_t *pLobbyMatchList )
{
	std::cout << "qq regular callback " << pLobbyMatchList->m_nLobbiesMatching << std::endl;

	throw new std::exception("qq");
}

void CLobbyBrowser::OnLogonSuccess( LogonSuccess_t *pLogon )
{
	std::cout << "GS Logon " << CSteamID(SteamGameServer_GetSteamID()) << std::endl;
}

int main(int argc, char *argv[])
{
	SetEnvironmentVariableA("SteamAppId", "440");

	if(!SteamGameServer_Init(0, 5000, 5001, 5002, 5003, eServerModeAuthentication, "tf", "1.0.7.1"))
		return 0;
	
	((ISteamMasterServerUpdater001 *)SteamMasterServerUpdater())->SetActive( true );

	if(!SteamAPI_Init())
		return 0;

	SteamAPICall_t hSteamAPICall = ((ISteamMatchmaking007 *)SteamMatchmaking())->RequestLobbyList();
	qq.m_SteamCallResultLobbyMatchList.Set(hSteamAPICall, &qq, &CLobbyBrowser::OnLobbyMatchListCallback );

	SteamAPI_SetTryCatchCallbacks(true);

	for(int i = 0; i < 100; i++)
	{
		SteamAPI_RunCallbacks();
		SteamGameServer_RunCallbacks();
		Sleep(100);
	}

	std::cout << "GS ID " << CSteamID(((ISteamGameServer003 *)SteamGameServer())->GetSteamID()) << std::endl;

	std::cin.get();

	SteamGameServer_Shutdown();
	SteamAPI_Shutdown();

	return 0;
}