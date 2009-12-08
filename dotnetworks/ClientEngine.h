#pragma once

#define STEAMWORKS_CLIENT_INTERFACES
#include "SteamclientAPI.h"

#include "SteamPipeHandle.h"
#include "SteamUserHandle.h"
#include "ClientUtils.h"

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
		ClientEngine( IClientEngine *clientEngine );

	public:
		DECLARE_GET_UTIL_FUNC(ClientUtils);

	private:
		// TODO: finish ClientEngine
		DECLARE_GET_INTERFACE();

	public:
		literal String^ InterfaceVersion = CLIENTENGINE_INTERFACE_VERSION;

	private:
		IClientEngine *base;
	};
}