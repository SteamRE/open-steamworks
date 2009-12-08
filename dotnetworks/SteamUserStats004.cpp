
#include "SteamUserStats004.h"

namespace dotnetworks
{
	SteamUserStats004::SteamUserStats004( void *steamStats )
	{
		base = (ISteamUserStats004 *)steamStats;
	}
	
	// Ask the server to send down this user's data and achievements for nGameID
	bool SteamUserStats004::RequestCurrentStats()
	{
		return base->RequestCurrentStats();
	}

	// Data accessors
	bool SteamUserStats004::GetStat( String^ pchName, int32% pData )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		int32 tempData;
		bool ret = base->GetStat( str, &tempData );

		pData = tempData;
		Marshal::FreeHGlobal(strPtr);
		return ret;
	}
	
	bool SteamUserStats004::GetStat( String^ pchName, float% pData )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		float tempData;
		bool ret = base->GetStat( str, &tempData);

		pData = tempData;
		Marshal::FreeHGlobal(strPtr);
		return ret;
	}


	// Set / update data
	bool SteamUserStats004::SetStat( String^ pchName, int32 nData )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		bool ret = base->SetStat( str, nData );

		Marshal::FreeHGlobal(strPtr);
		return ret;
	}
	bool SteamUserStats004::SetStat( String^ pchName, float fData )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		bool ret = base->SetStat( str, fData );

		Marshal::FreeHGlobal(strPtr);
		return ret;
	}
	bool SteamUserStats004::UpdateAvgRateStat( String^ pchName, float nCountThisSession, double dSessionLength )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		bool ret = base->UpdateAvgRateStat( str, nCountThisSession, dSessionLength );

		Marshal::FreeHGlobal(strPtr);
		return ret;
	}

	// Achievement flag accessors
	bool SteamUserStats004::GetAchievement( String^ pchName, bool% pbAchieved )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		bool tempData;
		bool ret = base->GetAchievement( str, &tempData );

		pbAchieved = tempData;
		Marshal::FreeHGlobal(strPtr);

		return ret;
	}
	bool SteamUserStats004::SetAchievement( String^ pchName )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		bool ret = base->SetAchievement( str );

		Marshal::FreeHGlobal(strPtr);
		return ret;
	}
	bool SteamUserStats004::ClearAchievement( String^ pchName )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		bool ret = base->ClearAchievement( str );

		Marshal::FreeHGlobal(strPtr);
		return ret;
	}

	// Store the current data on the server, will get a callback when set
	// And one callback for every new achievement
	bool SteamUserStats004::StoreStats()
	{
		return base->StoreStats();
	}

	// Gets the icon of the achievement, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
	int SteamUserStats004::GetAchievementIcon( String^ pchName )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		int ret = base->GetAchievementIcon( str );

		Marshal::FreeHGlobal(strPtr);
		return ret;
	}
	// Get general attributes (display name / text, etc) for an Achievement
	String^ SteamUserStats004::GetAchievementDisplayAttribute( String^ pchName, String^ pchKey )
	{
		IntPtr strNamePtr = Marshal::StringToHGlobalAnsi(pchName);
		char *strName = (char *)strNamePtr.ToPointer();

		IntPtr strKeyPtr = Marshal::StringToHGlobalAnsi(pchKey);
		char *strKey = (char *)strKeyPtr.ToPointer();

		String^ ret = gcnew String( base->GetAchievementDisplayAttribute( strName, strKey ) );

		Marshal::FreeHGlobal(strNamePtr);
		Marshal::FreeHGlobal(strKeyPtr);
		return ret;
	}

	// Achievement progress - triggers an AchievementProgress callback, that is all.
	// Calling this w/ N out of N progress will NOT set the achievement, the game must still do that.
	bool SteamUserStats004::IndicateAchievementProgress( String^ pchName, uint32 nCurProgress, uint32 nMaxProgress )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		bool ret = base->IndicateAchievementProgress( str, nCurProgress, nMaxProgress );

		Marshal::FreeHGlobal(strPtr);
		return ret;
	}
	
	// Friends stats & achievements

	// downloads stats for the user
	// returns a UserStatsReceived_t received when completed
	// if the other user has no stats, UserStatsReceived_t.m_eResult will be set to k_EResultFail
	// these stats won't be auto-updated; you'll need to call RequestUserStats() again to refresh any data
	SteamAPICall^ SteamUserStats004::RequestUserStats( SteamID^ steamIDUser )
	{
		return gcnew SteamAPICall( base->RequestUserStats( *(steamIDUser->base) ) );
	}

	// requests stat information for a user, usable after a successful call to RequestUserStats()
	bool SteamUserStats004::GetUserStat( SteamID^ steamIDUser, String^ pchName, int32% pData )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		int32 tempData;
		bool ret = base->GetUserStat( *(steamIDUser->base), str, &tempData );

		pData = tempData;
		Marshal::FreeHGlobal(strPtr);
		return ret;
	}
	bool SteamUserStats004::GetUserStat( SteamID^ steamIDUser, String^ pchName, float% pData )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		float tempData;
		bool ret = base->GetUserStat( *(steamIDUser->base), str, &tempData );

		pData = tempData;
		Marshal::FreeHGlobal(strPtr);
		return ret;
	}
	bool SteamUserStats004::GetUserAchievement( SteamID^ steamIDUser, String^ pchName, bool% pbAchieved )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		bool tempData;
		bool ret = base->GetUserAchievement( *(steamIDUser->base), str, &tempData );

		pbAchieved = tempData;
		Marshal::FreeHGlobal(strPtr);
		return ret;
	}

	// Reset stats 
	bool SteamUserStats004::ResetAllStats( bool bAchievementsToo )
	{
		return base->ResetAllStats( bAchievementsToo );
	}
}