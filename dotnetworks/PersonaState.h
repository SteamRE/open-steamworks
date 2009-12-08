#pragma once

namespace dotnetworks
{
	public enum class PersonaState
	{
		Offline = 0,			// friend is not currently logged on
		Online = 1,			// friend is logged on
		Busy = 2,			// user is on, but busy
		Away = 3,			// auto-away feature
		Snooze = 4,			// auto-away for a long time
	};
}