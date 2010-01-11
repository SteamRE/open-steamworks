#pragma once

#include "SteamclientAPI.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;


namespace dotnetworks
{
	public ref class GameID
	{
	internal:
		GameID( CGameID gameId ) : base( new CGameID( gameId.ToUint64() ) )
		{
		}

	public:
		GameID() : base( new CGameID() )
		{
		}
		GameID( uint64 gameId ) : base( new CGameID( gameId ) )
		{
		}
		GameID( int32 appId ) : base( new CGameID( appId ) )
		{
		}

		GameID( uint32 appId ) : base( new CGameID( appId ) )
		{
		}
		GameID( uint32 appId, uint32 modId ) : base( new CGameID( appId, modId ) )
		{
		}

		~GameID()
		{
			this->!GameID();
		}
		!GameID()
		{
			if ( base )
				delete base;
		}

		UInt64 ToUint64()
		{
			return base->ToUint64();
		}
		IntPtr^ GetUint64Ptr()
		{
			return gcnew IntPtr( base->GetUint64Ptr() );
		}

		bool IsMod() { return base->IsMod(); }
		bool IsShortcut() { return base->IsShortcut(); }
		bool IsP2PFile() { return base->IsP2PFile(); }
		bool IsSteamApp() { return base->IsSteamApp(); }

		UInt32 ModID() { return base->ModID(); }
		UInt32 AppID() { return base->AppID(); }

	    static bool operator == (GameID^ lhs, GameID^ rhs) { return *(lhs->base) == *(rhs->base); }
		static bool operator != (GameID^ lhs, GameID^ rhs) { return *(lhs->base) != *(rhs->base); }

		static bool operator < (GameID^ lhs, GameID^ rhs) { return *(lhs->base) < *(rhs->base); }
		static bool operator > (GameID^ lhs, GameID^ rhs) { return !(*(lhs->base) < *(rhs->base)); }

		bool IsValid() { return base->IsValid(); }

		void Reset() { return base->Reset(); }

	internal:
		CGameID *base;
	};
}