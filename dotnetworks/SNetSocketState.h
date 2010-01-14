#pragma once

using namespace System;

namespace dotnetworks
{
	public enum class SNetSocketState
	{
		Invalid = 0,						

		// communication is valid
		Connected = 1,				

		// states while establishing a connection
		Initiated = 10,				// the connection state machine has started

		// p2p connections
		LocalCandidatesFound = 11,	// we've found our local IP info
		ReceivedRemoteCandidates = 12,// we've received information from the remote machine, via the Steam back-end, about their IP info

		// direct connections
		ChallengeHandshake = 15,		// we've received a challenge packet from the server

		// failure states
		Disconnecting = 21,			// the API shut it down, and we're in the process of telling the other end	
		LocalDisconnect = 22,			// the API shut it down, and we've completed shutdown
		TimeoutDuringConnect = 23,	// we timed out while trying to creating the connection
		RemoteEndDisconnected = 24,	// the remote end has disconnected from us
		ConnectionBroken = 25,		// connection has been broken; either the other end has disappeared or our local network connection has broke
	};
}