#pragma once

#include "SteamclientAPI.h"

#include "SteamID.cpp"

#include "PersonaState.h"


namespace dotnetworks
{
	public ref class PersonaStateChange
	{
	internal:
		PersonaStateChange( PersonaStateChange_t *personaState )
		{
			SteamId = gcnew SteamID( personaState->m_ulSteamID );
			ChangeFlags = (PersonaState)personaState->m_nChangeFlags;
		};

	public:
		literal int Callback = PersonaStateChange_t::k_iCallback;

		SteamID^ SteamId;
		PersonaState ChangeFlags;
	};
}