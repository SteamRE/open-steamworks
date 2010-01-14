#pragma once

#include "SteamclientAPI.h"

#include "SNetSocket.cpp"
#include "SteamID.cpp"

#include "SNetSocketState.h"

namespace dotnetworks
{
	public ref class SocketStatusCallback
	{
	internal:
		SocketStatusCallback( SocketStatusCallback_t *socketStatus )
		{
			Socket = gcnew SNetSocket( socketStatus->m_hSocket );
			ListenSocket = gcnew SNetListenSocket( socketStatus->m_hListenSocket );

			RemoteID = gcnew SteamID( socketStatus->m_steamIDRemote );

			SocketState = (SNetSocketState)socketStatus->m_eSNetSocketState;
		};

	public:
		literal int Callback = SocketStatusCallback_t::k_iCallback;

		SNetSocket^ Socket;
		SNetListenSocket^ ListenSocket;

		SteamID^ RemoteID;

		SNetSocketState SocketState;

	};
}