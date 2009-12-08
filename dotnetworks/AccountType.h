#pragma once

using namespace System;

namespace dotnetworks
{
	public enum class AccountType
	{
		Invalid = 0,			
		Individual = 1,		// single user account
		Multiseat = 2,		// multiseat (e.g. cybercafe) account
		GameServer = 3,		// game server account
		AnonGameServer = 4,	// anonymous game server account
		Pending = 5,			// pending
		ContentServer = 6,	// content server
		Clan = 7,
		Chat = 8,
		P2PSuperSeeder = 9,	// a fake steamid used by superpeers to seed content to users of Steam P2P stuff
	};
}