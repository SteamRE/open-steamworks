#pragma once

#include "SteamclientAPI.h"

namespace dotnetworks
{
	public ref class GameOverlayActivated
	{
	internal:
		GameOverlayActivated( GameOverlayActivated_t *overlayActivated )
		{
			Active = overlayActivated->m_bActive != 0;
		};

	public:
		literal int Callback = GameOverlayActivated_t::k_iCallback;

		bool Active;
	};
}