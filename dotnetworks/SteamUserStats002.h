#pragma once

#include "SteamclientAPI.h"

#include "GameID.h"
#include "SteamUserStatType.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;


namespace dotnetworks
{

	public ref class SteamUserStats002
	{
	internal:
		SteamUserStats002( void *steamStats );
		
	public:
		uint32 GetNumStats( GameID^ nGameID );

		String^ GetStatName( GameID^ nGameID, uint32 iStat );
		// Get type of this field
		SteamUserStatType GetStatType( GameID^ nGameID, String^ pchName );

		// Get the number of achievements for nGameID
		uint32 GetNumAchievements( GameID^ nGameID );
		// Get achievement name iAchievement in [0,GetNumAchievements)
		String^ GetAchievementName( GameID^ nGameID, uint32 iAchievement );

		// Ask the server to send down this user's data and achievements for nGameID
		bool RequestCurrentStats( GameID^ nGameID );
		// Data accessors
		bool GetStat( GameID^ nGameID, String^ pchName, int32% pData );
		
		bool GetStat( GameID^ nGameID, String^ pchName, float% pData );

		// Set / update data
		bool SetStat( GameID^ nGameID, String^ pchName, int32 nData );
		bool SetStat( GameID^ nGameID, String^ pchName, float fData );
		bool UpdateAvgRateStat( GameID^ nGameID, String^ pchName, uint32 nCountThisSession, double dSessionLength );

		// Achievement flag accessors
		bool GetAchievement( GameID^ nGameID, String^ pchName, bool% pbAchieved );
		bool SetAchievement( GameID^ nGameID, String^ pchName );
		bool ClearAchievement( GameID^ nGameID, String^ pchName );

		// Store the current data on the server, will get a callback when set
		// And one callback for every new achievement
		bool StoreStats( GameID^ nGameID );

		// Achievement / GroupAchievement metadata

		// Gets the icon of the achievement, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
		int GetAchievementIcon( GameID^ nGameID, String^ pchName );
		// Get general attributes (display name / text, etc) for an Achievement
		String^ GetAchievementDisplayAttribute( GameID^ nGameID, String^ pchName, String^ pchKey );

		// Achievement progress - triggers an AchievementProgress callback, that is all.
		// Calling this w/ N out of N progress will NOT set the achievement, the game must still do that.
		bool IndicateAchievementProgress( GameID^ nGameID, String^ pchName, uint32 nCurProgress, uint32 nMaxProgress );

		literal String^ InterfaceVersion = STEAMUSERSTATS_INTERFACE_VERSION_002;


	private:
		ISteamUserStats002 *base;
	};
}