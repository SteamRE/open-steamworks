#pragma once

namespace dotnetworks
{
	public enum class SteamUserStatType
	{
		Invalid = 0,
		Int = 1,
		Float = 2,
		// Read as FLOAT, set with count / session length
		AVGRate = 3,
		Achievements = 4,
		GroupAchievements = 5,
	};
}