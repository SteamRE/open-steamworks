#pragma once

using namespace System;

namespace dotnetworks
{
	// Steam API call failure results
	public enum class SteamAPICallFailure
	{
		None = -1,			// no failure
		SteamGone = 0,		// the local Steam process has gone away
		NetworkFailure = 1,	// the network connection to Steam has been broken, or was already broken
		// SteamServersDisconnected_t callback will be sent around the same time
		// SteamServersConnected_t will be sent when the client is able to talk to the Steam servers again
		InvalidHandle = 2,	// the SteamAPICall_t handle passed in no longer exists
		MismatchedCallback = 3,// GetAPICallResult() was called with the wrong callback type for this API call
	};
}