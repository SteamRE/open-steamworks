#pragma once

#include "SteamclientAPI.h"

#include "SteamUserStatType.h"

#include "GameID.cpp"

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
		SteamUserStats002( void *steamStats )
		{
			base = (ISteamUserStats002 *)steamStats;
		}
		
	public:
		uint32 GetNumStats( GameID^ nGameID )
		{
			return base->GetNumStats( *(nGameID->base) );
		}

		String^ GetStatName( GameID^ nGameID, uint32 iStat )
		{
			return gcnew String( base->GetStatName( *(nGameID->base), iStat ) );
		}

		// Get type of this field
		SteamUserStatType GetStatType( GameID^ nGameID, String^ pchName )
		{
			IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
			char *str = (char *)strPtr.ToPointer();

			SteamUserStatType ret = (SteamUserStatType) base->GetStatType( *(nGameID->base), str );

			Marshal::FreeHGlobal(strPtr);
			return ret;
		}

		// Get the number of achievements for nGameID
		uint32 GetNumAchievements( GameID^ nGameID ) 
		{
			return base->GetNumAchievements( *(nGameID->base) );
		}
		// Get achievement name iAchievement in [0,GetNumAchievements)
		String^ GetAchievementName( GameID^ nGameID, uint32 iAchievement )
		{
			return gcnew String( base->GetAchievementName( *(nGameID->base), iAchievement ) );
		}

		// Ask the server to send down this user's data and achievements for nGameID
		bool RequestCurrentStats( GameID^ nGameID )
		{
			return base->RequestCurrentStats( *(nGameID->base) );
		}

		// Data accessors
		bool GetStat( GameID^ nGameID, String^ pchName, [Out] int32% pData )
		{
			IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
			char *str = (char *)strPtr.ToPointer();

			int32 tempData;
			bool ret = base->GetStat( *(nGameID->base), str, &tempData );

			pData = tempData;
			Marshal::FreeHGlobal(strPtr);
			return ret;
		}

		bool GetStat( GameID^ nGameID, String^ pchName, [Out] float% pData )
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
		bool SetStat( GameID^ nGameID, String^ pchName, int32 nData )
		{
			IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
			char *str = (char *)strPtr.ToPointer();

			bool ret = base->SetStat( *(nGameID->base), str, nData );

			Marshal::FreeHGlobal(strPtr);
			return ret;
		}
		bool SetStat( GameID^ nGameID, String^ pchName, float fData )
		{
			IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
			char *str = (char *)strPtr.ToPointer();

			bool ret = base->SetStat( *(nGameID->base), str, fData );

			Marshal::FreeHGlobal(strPtr);
			return ret;
		}
		bool UpdateAvgRateStat( GameID^ nGameID, String^ pchName, uint32 nCountThisSession, double dSessionLength )
		{
			IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
			char *str = (char *)strPtr.ToPointer();

			bool ret = base->UpdateAvgRateStat( *(nGameID->base), str, nCountThisSession, dSessionLength );

			Marshal::FreeHGlobal(strPtr);
			return ret;
		}

		// Achievement flag accessors
		bool GetAchievement( GameID^ nGameID, String^ pchName, [Out] bool% pbAchieved )
		{
			IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
			char *str = (char *)strPtr.ToPointer();

			bool tempData;
			bool ret = base->GetAchievement( *(nGameID->base), str, &tempData);

			pbAchieved = tempData;
			Marshal::FreeHGlobal(strPtr);

			return ret;
		}
		bool SetAchievement( GameID^ nGameID, String^ pchName )
		{
			IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
			char *str = (char *)strPtr.ToPointer();

			bool ret = base->SetAchievement( *(nGameID->base), str);

			Marshal::FreeHGlobal(strPtr);
			return ret;
		}
		bool ClearAchievement( GameID^ nGameID, String^ pchName )
		{
			IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
			char *str = (char *)strPtr.ToPointer();

			bool ret = base->ClearAchievement( *(nGameID->base), str);

			Marshal::FreeHGlobal(strPtr);
			return ret;
		}

		// Store the current data on the server, will get a callback when set
		// And one callback for every new achievement
		bool StoreStats( GameID^ nGameID )
		{
			return base->StoreStats( *(nGameID->base) );
		}

		// Achievement / GroupAchievement metadata

		// Gets the icon of the achievement, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
		int GetAchievementIcon( GameID^ nGameID, String^ pchName )
		{
			IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
			char *str = (char *)strPtr.ToPointer();

			int ret = base->GetAchievementIcon( *(nGameID->base), str );

			Marshal::FreeHGlobal(strPtr);
			return ret;
		}
		// Get general attributes (display name / text, etc) for an Achievement
		String^ GetAchievementDisplayAttribute( GameID^ nGameID, String^ pchName, String^ pchKey )
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
		bool IndicateAchievementProgress( GameID^ nGameID, String^ pchName, uint32 nCurProgress, uint32 nMaxProgress )
		{
			IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchName);
			char *str = (char *)strPtr.ToPointer();

			bool ret = base->IndicateAchievementProgress( *(nGameID->base), str, nCurProgress, nMaxProgress );

			Marshal::FreeHGlobal(strPtr);
			return ret;
		}

		literal String^ InterfaceVersion = STEAMUSERSTATS_INTERFACE_VERSION_002;


	private:
		ISteamUserStats002 *base;
	};
}