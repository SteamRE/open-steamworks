
#include "GameID.h"

namespace dotnetworks
{
	GameID::GameID( CGameID gameId ) : base ( new CGameID(gameId.ToUint64()) )
	{
	}

	GameID::GameID() : base( new CGameID() ) {}
	GameID::GameID(uint64 gameId) : base( new CGameID(gameId) ) {}
	GameID::GameID(int32 appId) : base( new CGameID(appId) ) {}
	GameID::GameID(uint32 appId) : base( new CGameID(appId) ) {}
	GameID::GameID(uint32 appId, uint32 modId) : base( new CGameID(appId, modId) ) {}

	GameID::~GameID() { this->!GameID(); }
	GameID::!GameID()
	{
		if (base)
			delete base;
	}

	UInt64 GameID::ToUint64() { return base->ToUint64(); }
	IntPtr^ GameID::GetUint64Ptr() { return gcnew IntPtr( base->GetUint64Ptr() ); }

	bool GameID::IsMod() { return base->IsMod(); }
	bool GameID::IsShortcut() { return base->IsShortcut(); }
	bool GameID::IsP2PFile() { return base->IsP2PFile(); }
	bool GameID::IsSteamApp() { return base->IsSteamApp(); }

	UInt32 GameID::ModID() { return base->ModID(); }
	UInt32 GameID::AppID() { return base->AppID(); }

    bool GameID::operator == (GameID^ lhs, GameID^ rhs) { return *(lhs->base) == *(rhs->base); }
	bool GameID::operator != (GameID^ lhs, GameID^ rhs) { return *(lhs->base) != *(rhs->base); }
	bool GameID::operator < (GameID^ lhs, GameID^ rhs) { return *(lhs->base) < *(rhs->base); }
	bool GameID::operator > (GameID^ lhs, GameID^ rhs) { return *(lhs->base) < *(rhs->base); }

	bool GameID::IsValid() { return base->IsValid(); }

	void GameID::Reset() { base->Reset(); }

}