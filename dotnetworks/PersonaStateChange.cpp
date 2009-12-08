#pragma once

#include "SteamclientAPI.h"


namespace dotnetworks
{
	public ref class PersonaStateChange
	{
	internal:
		PersonaStateChange( PersonaStateChange_t *personaState )
		{
			SteamID = personaState->m_ulSteamID;
			ChangeFlags = personaState->m_nChangeFlags;
		};

	public:
		literal int Callback = 304;

		uint64 SteamID;
		int ChangeFlags;
	};
}