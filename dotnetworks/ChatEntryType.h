#pragma once

namespace dotnetworks
{
	public enum class ChatEntryType
	{
		ChatMsg = 1,		// Normal text message from another user
		Typing = 2,			// Another user is typing (not used in multi-user chat)
		InviteGame = 3,		// Invite from other user into that users current game
		Emote = 4,			// text emote message
		GameStart = 5,	// lobby game is starting
		// Above are previous FriendMsgType entries, now merged into more generic chat entry types
	};
}