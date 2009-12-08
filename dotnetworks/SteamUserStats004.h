#pragma once

#include "SteamclientAPI.h"

#include "GameID.h"
#include "SteamID.h"
#include "SteamAPICall.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;


namespace dotnetworks
{
	public ref class SteamUserStats004
	{
	internal:
		SteamUserStats004( void *steamStats );
		
	public:
		// Ask the server to send down this user's data and achievements for nGameID
		bool RequestCurrentStats();

		// Data accessors
		bool GetStat( String^ pchName, int32% pData );
		
		bool GetStat( String^ pchName, float% pData );


		// Set / update data
		bool SetStat( String^ pchName, int32 nData );
		bool SetStat( String^ pchName, float fData );
		bool UpdateAvgRateStat( String^ pchName, float nCountThisSession, double dSessionLength );

		// Achievement flag accessors
		bool GetAchievement( String^ pchName, bool% pbAchieved );
		bool SetAchievement( String^ pchName );
		bool ClearAchievement( String^ pchName );

		// Store the current data on the server, will get a callback when set
		// And one callback for every new achievement
		bool StoreStats();

		// Gets the icon of the achievement, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
		int GetAchievementIcon( String^ pchName );
		// Get general attributes (display name / text, etc) for an Achievement
		String^ GetAchievementDisplayAttribute( String^ pchName, String^ pchKey );

		// Achievement progress - triggers an AchievementProgress callback, that is all.
		// Calling this w/ N out of N progress will NOT set the achievement, the game must still do that.
		bool IndicateAchievementProgress( String^ pchName, uint32 nCurProgress, uint32 nMaxProgress );
		
		// Friends stats & achievements

		// downloads stats for the user
		// returns a UserStatsReceived_t received when completed
		// if the other user has no stats, UserStatsReceived_t.m_eResult will be set to k_EResultFail
		// these stats won't be auto-updated; you'll need to call RequestUserStats() again to refresh any data
		SteamAPICall^ RequestUserStats( SteamID^ steamIDUser );

		// requests stat information for a user, usable after a successful call to RequestUserStats()
		bool GetUserStat( SteamID^ steamIDUser, String^ pchName, int32% pData );
		bool GetUserStat( SteamID^ steamIDUser, String^ pchName, float% pData );
		bool GetUserAchievement( SteamID^ steamIDUser, String^ pchName, bool% pbAchieved );

		// Reset stats 
		bool ResetAllStats( bool bAchievementsToo );

		literal String^ InterfaceVersion = STEAMUSERSTATS_INTERFACE_VERSION_004;

	private:
		ISteamUserStats004 *base;
	};
}