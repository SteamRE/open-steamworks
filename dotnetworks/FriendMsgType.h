#pragma once

namespace dotnetworks
{
	public enum class FriendMsgType
	{
		Chat = 1,			// chat test message
		Typing = 2,			// lets the friend know the other user has starting typing a chat message
		Invite = 3,			// invites the friend into the users current game
		ChatSent = 4,		// chat that the user has sent to a friend
	};
}