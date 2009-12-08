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
		GameID( CGameID gameId );
	public:
		GameID();
		GameID(uint64 gameId);
		GameID(int32 appId);
		GameID(uint32 appId);
		GameID(uint32 appId, uint32 modId);

		~GameID();
		!GameID();

		UInt64 ToUint64();
		IntPtr^ GetUint64Ptr();

		bool IsMod();
		bool IsShortcut();
		bool IsP2PFile();
		bool IsSteamApp();

		UInt32 ModID();
		UInt32 AppID();

	    static bool operator == (GameID^ lhs, GameID^ rhs);
		static bool operator != (GameID^ lhs, GameID^ rhs);

		static bool operator < (GameID^ lhs, GameID^ rhs);
		static bool operator > (GameID^ lhs, GameID^ rhs);

		bool IsValid();

		void Reset();

	internal:
		CGameID *base;
	};
}