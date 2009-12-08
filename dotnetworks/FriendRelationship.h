#pragma once

namespace dotnetworks
{
	public enum class FriendRelationship
	{
		None = 0,
		Blocked = 1,
		RequestRecipient = 2,
		Friend = 3,
		RequestInitiator = 4,
		Ignored = 5,
		IgnoredFriend = 6,
	};
}