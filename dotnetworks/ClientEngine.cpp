#pragma once

#include "SteamclientAPI.h"

#include "ClientFriends.cpp"

#include "Macros.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::Serialization;

namespace dotnetworks
{
	public ref class ClientEngine
	{
	internal:
		ClientEngine( IClientEngine *engine )
		{
			base = engine;
		}

	public:
		GET_INTERFACE_FUNC( ClientFriends );


	private:
		IClientEngine *base;

		BEGIN_GET_INTERFACE()
			RETURN_INTERFACE( ClientFriends, CLIENTFRIENDS_INTERFACE_VERSION )
		END_GET_INTERFACE()
	};
}