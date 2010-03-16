//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#ifndef USERSTATSCOMMON_H
#define USERSTATSCOMMON_H
#ifdef _WIN32
#pragma once
#endif

// a single entry in a leaderboard, as returned by GetDownloadedLeaderboardEntry()
struct LeaderboardEntry_t
{
	CSteamID m_steamIDUser; // user with the entry - use SteamFriends()->GetFriendPersonaName() & SteamFriends()->GetFriendAvatar() to get more info
	int32 m_nGlobalRank;	// [1..N], where N is the number of users with an entry in the leaderboard
	int32 m_nScore;			// score as set in the leaderboard
	int32 m_cDetails;		// number of int32 details available for this entry
};



#define STEAMUSERSTATS_INTERFACE_VERSION_001 "STEAMUSERSTATS_INTERFACE_VERSION001"
#define STEAMUSERSTATS_INTERFACE_VERSION_002 "STEAMUSERSTATS_INTERFACE_VERSION002"
#define STEAMUSERSTATS_INTERFACE_VERSION_003 "STEAMUSERSTATS_INTERFACE_VERSION003"
#define STEAMUSERSTATS_INTERFACE_VERSION_004 "STEAMUSERSTATS_INTERFACE_VERSION004"
#define STEAMUSERSTATS_INTERFACE_VERSION_005 "STEAMUSERSTATS_INTERFACE_VERSION005"
#define STEAMUSERSTATS_INTERFACE_VERSION_006 "STEAMUSERSTATS_INTERFACE_VERSION006"
#define STEAMUSERSTATS_INTERFACE_VERSION_007 "STEAMUSERSTATS_INTERFACE_VERSION007"



//-----------------------------------------------------------------------------
// Purpose: called when the latests stats and achievements have been received
//			from the server
//-----------------------------------------------------------------------------
struct UserStatsReceived_t
{
	enum { k_iCallback = k_iSteamUserStatsCallbacks + 1 };
	uint64		m_nGameID;		// Game these stats are for
	EResult		m_eResult;		// Success / error fetching the stats
	CSteamID	m_steamIDUser;	// The user for whom the stats are retrieved for
};


//-----------------------------------------------------------------------------
// Purpose: result of a request to store the user stats for a game
//-----------------------------------------------------------------------------
struct UserStatsStored_t
{
	enum { k_iCallback = k_iSteamUserStatsCallbacks + 2 };
	uint64		m_nGameID;		// Game these stats are for
	EResult		m_eResult;		// success / error
};


//-----------------------------------------------------------------------------
// Purpose: result of a request to store the achievements for a game, or an 
//			"indicate progress" call. If both m_nCurProgress and m_nMaxProgress
//			are zero, that means the achievement has been fully unlocked.
//-----------------------------------------------------------------------------
struct UserAchievementStored_t
{
	enum { k_iCallback = k_iSteamUserStatsCallbacks + 3 };

	uint64		m_nGameID;				// Game this is for
	bool		m_bGroupAchievement;	// if this is a "group" achievement
	char		m_rgchAchievementName[k_cchStatNameMax];		// name of the achievement
	uint32		m_nCurProgress;			// current progress towards the achievement
	uint32		m_nMaxProgress;			// "out of" this many
};


//-----------------------------------------------------------------------------
// Purpose: call result for finding a leaderboard, returned as a result of FindOrCreateLeaderboard() or FindLeaderboard()
//			use CCallResult<> to map this async result to a member function
//-----------------------------------------------------------------------------
struct LeaderboardFindResult_t
{
	enum { k_iCallback = k_iSteamUserStatsCallbacks + 4 };
	SteamLeaderboard_t m_hSteamLeaderboard;	// handle to the leaderboard serarched for, 0 if no leaderboard found
	uint8 m_bLeaderboardFound;				// 0 if no leaderboard found
};


//-----------------------------------------------------------------------------
// Purpose: call result indicating scores for a leaderboard have been downloaded and are ready to be retrieved, returned as a result of DownloadLeaderboardEntries()
//			use CCallResult<> to map this async result to a member function
//-----------------------------------------------------------------------------
struct LeaderboardScoresDownloaded_t
{
	enum { k_iCallback = k_iSteamUserStatsCallbacks + 5 };
	SteamLeaderboard_t m_hSteamLeaderboard;
	SteamLeaderboardEntries_t m_hSteamLeaderboardEntries;	// the handle to pass into GetDownloadedLeaderboardEntries()
	int m_cEntryCount; // the number of entries downloaded
};


//-----------------------------------------------------------------------------
// Purpose: call result indicating scores has been uploaded, returned as a result of UploadLeaderboardScore()
//			use CCallResult<> to map this async result to a member function
//-----------------------------------------------------------------------------
struct LeaderboardScoreUploaded_t
{
	enum { k_iCallback = k_iSteamUserStatsCallbacks + 6 };
	uint8 m_bSuccess;			// 1 if the call was successful
	SteamLeaderboard_t m_hSteamLeaderboard;	// the leaderboard handle that was
	int32 m_nScore;				// the score that was attempted to set
	uint8 m_bScoreChanged;		// true if the score in the leaderboard change, false if the existing score was better
	int m_nGlobalRankNew;		// the new global rank of the user in this leaderboard
	int m_nGlobalRankPrevious;	// the previous global rank of the user in this leaderboard; 0 if the user had no existing entry in the leaderboard
};

struct NumberOfCurrentPlayers_t
{
	enum { k_iCallback = k_iSteamUserStatsCallbacks + 7 };
	uint8 m_bSuccess;			// 1 if the call was successful
	int32 m_cPlayers;			// Number of players currently playing
};




#endif // USERSTATSCOMMON_H
