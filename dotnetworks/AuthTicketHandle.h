#pragma once

#include "SteamclientAPI.h"

namespace dotnetworks
{
	public ref class AuthTicketHandle
	{
	public:
		AuthTicketHandle(HAuthTicket authTicket);

	internal:
		HAuthTicket base;
	};
}