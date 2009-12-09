#include "CUser.h"

std::ostream& operator<<(std::ostream& out, const CUser& u)
{
	out << u.GetUsername() << " (" << u.GetSteamID() << ")";
	return out;
}