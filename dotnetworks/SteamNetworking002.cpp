#pragma once

#include "Macros.h"

#include "SteamclientAPI.h"

#include "SNetSocketConnectionType.h"

#include "SteamID.cpp"
#include "SNetSocket.cpp"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;

namespace dotnetworks
{
	public ref class SteamNetworking002
	{
	internal:
		SteamNetworking002( void *steamNetworking )
		{
			base = (ISteamNetworking002 *)steamNetworking;
		}

	public:
		// creates a socket and listens others to connect
		// will trigger a SocketStatusCallback_t callback on another client connecting
		// nVirtualP2PPort is the unique ID that the client will connect to, in case you have multiple ports
		//		this can usually just be 0 unless you want multiple sets of connections
		// unIP is the local IP address to bind to
		//		pass in 0 if you just want the default local IP
		// unPort is the port to use
		//		pass in 0 if you don't want users to be able to connect via IP/Port, but expect to be always peer-to-peer connections only
		SNetListenSocket^ CreateListenSocket( int nVirtualP2PPort, uint32 nIP, uint16 nPort, bool bAllowUseOfPacketRelay )
		{
			return gcnew SNetListenSocket( base->CreateListenSocket( nVirtualP2PPort, nIP, nPort, bAllowUseOfPacketRelay ) );
		}

		// creates a socket and begin connection to a remote destination
		// can connect via a known steamID (client or game server), or directly to an IP
		// on success will trigger a SocketStatusCallback_t callback
		// on failure or timeout will trigger a SocketStatusCallback_t callback with a failure code in m_eSNetSocketState
		SNetSocket^ CreateP2PConnectionSocket( SteamID^ steamIDTarget, int nVirtualPort, int nTimeoutSec, bool bAllowUseOfPacketRelay )
		{
			return gcnew SNetSocket( base->CreateP2PConnectionSocket( *(steamIDTarget->base), nVirtualPort, nTimeoutSec, bAllowUseOfPacketRelay ) );
		}
		SNetSocket^ CreateConnectionSocket( uint32 nIP, uint16 nPort, int nTimeoutSec )
		{
			return gcnew SNetSocket( base->CreateConnectionSocket( nIP, nPort, nTimeoutSec ) );
		}

		// disconnects the connection to the socket, if any, and invalidates the handle
		// any unread data on the socket will be thrown away
		// if bNotifyRemoteEnd is set, socket will not be completely destroyed until the remote end acknowledges the disconnect
		bool DestroySocket( SNetSocket^ hSocket, bool bNotifyRemoteEnd )
		{
			return base->DestroySocket( hSocket->base, bNotifyRemoteEnd );
		}
		// destroying a listen socket will automatically kill all the regular sockets generated from it
		bool DestroyListenSocket( SNetListenSocket^ hSocket, bool bNotifyRemoteEnd )
		{
			return base->DestroyListenSocket( hSocket->base, bNotifyRemoteEnd );
		}

		// sending data
		// must be a handle to a connected socket
		// data is all sent via UDP, and thus send sizes are limited to 1200 bytes; after this, many routers will start dropping packets
		// use the reliable flag with caution; although the resend rate is pretty aggressive,
		// it can still cause stalls in receiving data (like TCP)
		bool SendDataOnSocket( SNetSocket^ hSocket, array<Byte>^ pubData, uint32 cubData, bool bReliable )
		{
			ARRAY_TO_PTR( pubData, data, cubData );

			bool ret = base->SendDataOnSocket( hSocket->base, data, cubData, bReliable );

			ARRAY_FREE( data );

			return ret;
		}

		// receiving data
		// returns false if there is no data remaining
		// fills out *pcubMsgSize with the size of the next message, in bytes
		bool IsDataAvailableOnSocket( SNetSocket^ hSocket, [Out] uint32% pcubMsgSize )
		{
			uint32 msgSize;

			bool ret = base->IsDataAvailableOnSocket( hSocket->base, &msgSize );

			pcubMsgSize = msgSize;

			return ret;
		}

		// fills in pubDest with the contents of the message
		// messages are always complete, of the same size as was sent (i.e. packetized, not streaming)
		// if *pcubMsgSize < cubDest, only partial data is written
		// returns false if no data is available
		bool RetrieveDataFromSocket( SNetSocket^ hSocket, array<Byte>^pubDest, uint32 cubDest, [Out] uint32% pcubMsgSize )
		{
			ARRAY_TO_PTR_NOCOPY( data, cubDest );

			uint32 msgSize;

			bool ret = base->RetrieveDataFromSocket( hSocket->base, data, cubDest, &msgSize );

			ARRAY_COPY( data, pubDest, cubDest );
			ARRAY_FREE( data );

			pcubMsgSize = msgSize;

			return ret;
		}

		// checks for data from any socket that has been connected off this listen socket
		// returns false if there is no data remaining
		// fills out *pcubMsgSize with the size of the next message, in bytes
		// fills out *phSocket with the socket that data is available on
		bool IsDataAvailable( SNetListenSocket^ hListenSocket, [Out] uint32% pcubMsgSize, [Out] SNetSocket^% phSocket )
		{
			uint32 msgSize;
			SNetSocket_t socket;

			bool ret = base->IsDataAvailable( hListenSocket->base, &msgSize, &socket );

			pcubMsgSize = msgSize;
			phSocket = gcnew SNetSocket( socket );

			return ret;
		}

		// retrieves data from any socket that has been connected off this listen socket
		// fills in pubDest with the contents of the message
		// messages are always complete, of the same size as was sent (i.e. packetized, not streaming)
		// if *pcubMsgSize < cubDest, only partial data is written
		// returns false if no data is available
		// fills out *phSocket with the socket that data is available on
		bool RetrieveData( SNetListenSocket^ hListenSocket, array<Byte>^ pubDest, uint32 cubDest, [Out] uint32% pcubMsgSize, [Out] SNetSocket^% phSocket )
		{
			ARRAY_TO_PTR_NOCOPY( data, cubDest );

			uint32 msgSize;
			SNetSocket_t socket;

			bool ret = base->RetrieveData( hListenSocket->base, data, cubDest, &msgSize, &socket );

			ARRAY_COPY( data, pubDest, cubDest );
			ARRAY_FREE( data );

			pcubMsgSize = msgSize;
			phSocket = gcnew SNetSocket( socket );

			return ret;
		}

		// returns information about the specified socket, filling out the contents of the pointers
		bool GetSocketInfo( SNetSocket^ hSocket, [Out] SteamID^% pSteamIDRemote, [Out] int% peSocketStatus, [Out] uint32% punIPRemote, [Out] uint16% punPortRemote )
		{
			int status;
			uint32 ip;
			uint16 port;
			CSteamID steamId;

			bool ret = base->GetSocketInfo( hSocket->base, &steamId, &status, &ip, &port );

			pSteamIDRemote = gcnew SteamID( steamId.ConvertToUint64() );
			peSocketStatus = status;
			punIPRemote = ip;
			punPortRemote = port;

			return ret;
		}

		// returns which local port the listen socket is bound to
		// *pnIP and *pnPort will be 0 if the socket is set to listen for P2P connections only
		bool GetListenSocketInfo( SNetListenSocket^ hListenSocket, [Out] uint32% pnIP, [Out] uint16% pnPort )
		{
			uint32 ip;
			uint16 port;

			bool ret = base->GetListenSocketInfo( hListenSocket->base, &ip, &port );

			pnIP = ip;
			pnPort = port;

			return ret;
		}

		// returns true to describe how the socket ended up connecting
		SNetSocketConnectionType GetSocketConnectionType( SNetSocket^ hSocket )
		{
			return (SNetSocketConnectionType)base->GetSocketConnectionType( hSocket->base );
		}

		// max packet size, in bytes
		int GetMaxPacketSize( SNetSocket^ hSocket )
		{
			return base->GetMaxPacketSize( hSocket->base );
		}

	private:
		ISteamNetworking002 *base;
	};
}