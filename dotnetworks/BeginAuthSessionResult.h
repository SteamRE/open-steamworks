#pragma once

namespace dotnetworks
{
	public enum class BeginAuthSessionResult
	{
		OK = 0,						// Ticket is valid for this game and this steamID.
		InvalidTicket = 1,				// Ticket is not valid.
		DuplicateRequest = 2,			// A ticket has already been submitted for this steamID
		InvalidVersion = 3,			// Ticket is from an incompatible interface version
		GameMismatch = 4,				// Ticket is not for this game
		ExpiredTicket = 5,				// Ticket has expired
	};
}