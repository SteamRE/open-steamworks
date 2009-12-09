#ifndef CUSER_H
#define CUSER_H

#include "Common.h"

class CUser
{
private:
	CSteamID		steamID;
	SNetSocket_t	socket;
	std::string		username;
	time_t			lastpong;

public:
	CUser(SNetSocket_t s, const CSteamID &steam, const std::string &user) : steamID(steam), socket(s), username(user), lastpong(time(0)) {};

	const std::string&	GetUsername() const { return username; };
	const CSteamID&		GetSteamID() const { return steamID; };
	SNetSocket_t		GetSocket() const { return socket; };
	time_t				GetPongTime() const { return lastpong; };

	void				PongResponse() { lastpong = time(0); };
};

std::ostream& operator<<(std::ostream& out, const CUser& u);

#endif
