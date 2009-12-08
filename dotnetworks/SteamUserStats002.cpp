
#include "SteamUserStats002.h"

namespace dotnetworks
{

	SteamUserStats002::SteamUserStats002( void *steamStats )
	{
		base = (ISteamUserStats002 *)steamStats;
	}
	
	uint32 SteamUserStats002::GetNumStats( GameID^ nGameID )
	{
		return base->GetNumStats( *(nGameID->base) );
	}

	String^ SteamUserStats002::GetStatName( GameID^ nGameID, uint32 iStat )
	{
		return gcnew String( base->GetStatName( *(nGameID->base), iStat ) );
	}

	// Get type of this field
	SteamUserStatType SteamUserStats002::GetStatType( GameID^ nGameID, String^ pchName )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		SteamUserStatType ret = (SteamUserStatType) base->GetStatType( *(nGameID->base), str );

		Marshal::FreeHGlobal(strPtr);
		return ret;
	}

	// Get the number of achievements for nGameID
	uint32 SteamUserStats002::GetNumAchievements( GameID^ nGameID ) 
	{
		return base->GetNumAchievements( *(nGameID->base) );
	}
	// Get achievement name iAchievement in [0,GetNumAchievements)
	String^ SteamUserStats002::GetAchievementName( GameID^ nGameID, uint32 iAchievement )
	{
		return gcnew String( base->GetAchievementName( *(nGameID->base), iAchievement ) );
	}

	// Ask the server to send down this user's data and achievements for nGameID
	bool SteamUserStats002::RequestCurrentStats( GameID^ nGameID )
	{
		return base->RequestCurrentStats( *(nGameID->base) );
	}

	// Data accessors
	bool SteamUserStats002::GetStat( GameID^ nGameID, String^ pchName, int32% pData )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		int32 tempData;
		bool ret = base->GetStat( *(nGameID->base), str, &tempData );

		pData = tempData;
		Marshal::FreeHGlobal(strPtr);
		return ret;
	}
	
	bool SteamUserStats002::GetStat( GameID^ nGameID, String^ pchName, float% pData )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		float tempData;
		bool ret = base->GetStat( *(nGameID->base), str, &tempData);

		pData = tempData;
		Marshal::FreeHGlobal(strPtr);
		return ret;
	}

	// Set / update data
	bool SteamUserStats002::SetStat( GameID^ nGameID, String^ pchName, int32 nData )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		bool ret = base->SetStat( *(nGameID->base), str, nData );

		Marshal::FreeHGlobal(strPtr);
		return ret;
	}
	bool SteamUserStats002::SetStat( GameID^ nGameID, String^ pchName, float fData )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		bool ret = base->SetStat( *(nGameID->base), str, fData );

		Marshal::FreeHGlobal(strPtr);
		return ret;
	}
	bool SteamUserStats002::UpdateAvgRateStat( GameID^ nGameID, String^ pchName, uint32 nCountThisSession, double dSessionLength )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		bool ret = base->UpdateAvgRateStat( *(nGameID->base), str, nCountThisSession, dSessionLength );

		Marshal::FreeHGlobal(strPtr);
		return ret;
	}

	// Achievement flag accessors
	bool SteamUserStats002::GetAchievement( GameID^ nGameID, String^ pchName, bool% pbAchieved )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		bool tempData;
		bool ret = base->GetAchievement( *(nGameID->base), str, &tempData);

		pbAchieved = tempData;
		Marshal::FreeHGlobal(strPtr);

		return ret;
	}
	bool SteamUserStats002::SetAchievement( GameID^ nGameID, String^ pchName )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		bool ret = base->SetAchievement( *(nGameID->base), str);

		Marshal::FreeHGlobal(strPtr);
		return ret;
	}
	bool SteamUserStats002::ClearAchievement( GameID^ nGameID, String^ pchName )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		bool ret = base->ClearAchievement( *(nGameID->base), str);

		Marshal::FreeHGlobal(strPtr);
		return ret;
	}

	// Store the current data on the server, will get a callback when set
	// And one callback for every new achievement
	bool SteamUserStats002::StoreStats( GameID^ nGameID )
	{
		return base->StoreStats( *(nGameID->base) );
	}

	// Achievement / GroupAchievement metadata

	// Gets the icon of the achievement, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
	int SteamUserStats002::GetAchievementIcon( GameID^ nGameID, String^ pchName )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		int ret = base->GetAchievementIcon( *(nGameID->base), str );

		Marshal::FreeHGlobal(strPtr);
		return ret;
	}
	// Get general attributes (display name / text, etc) for an Achievement
	String^ SteamUserStats002::GetAchievementDisplayAttribute( GameID^ nGameID, String^ pchName, String^ pchKey )
	{
		IntPtr strNamePtr = Marshal::StringToHGlobalAnsi(pchName);
		char *strName = (char *)strNamePtr.ToPointer();

		IntPtr strKeyPtr = Marshal::StringToHGlobalAnsi(pchKey);
		char *strKey = (char *)strKeyPtr.ToPointer();

		String^ ret = gcnew String( base->GetAchievementDisplayAttribute( *(nGameID->base), strName, strKey ) );

		Marshal::FreeHGlobal(strNamePtr);
		Marshal::FreeHGlobal(strKeyPtr);
		return ret;
	}

	// Achievement progress - triggers an AchievementProgress callback, that is all.
	// Calling this w/ N out of N progress will NOT set the achievement, the game must still do that.
	bool SteamUserStats002::IndicateAchievementProgress( GameID^ nGameID, String^ pchName, uint32 nCurProgress, uint32 nMaxProgress )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
		char *str = (char *)strPtr.ToPointer();

		bool ret = base->IndicateAchievementProgress( *(nGameID->base), str, nCurProgress, nMaxProgress );

		Marshal::FreeHGlobal(strPtr);
		return ret;
	}

}