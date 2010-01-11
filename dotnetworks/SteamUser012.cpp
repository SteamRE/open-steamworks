#pragma once

#include "SteamclientAPI.h"

#include "VoiceResult.h"
#include "BeginAuthSessionResult.h"

#include "SteamUserHandle.cpp"
#include "SteamID.cpp"
#include "AuthTicketHandle.cpp"
#include "GameID.cpp"
#include "AppID.cpp"

#include "Macros.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;

namespace dotnetworks
{

	public ref class SteamUser012
	{
	internal:
		SteamUser012( void *steamUser )
		{
			base = (ISteamUser012 *)steamUser;
		}
		
	public:
		SteamUserHandle^ GetHSteamUser()
		{
			return gcnew SteamUserHandle( base->GetHSteamUser() );
		}

		bool LoggedOn()
		{
			return base->LoggedOn();
		}

		SteamID^ GetSteamID()
		{
			return gcnew SteamID( base->GetSteamID() );
		}

		int InitiateGameConnection( array<byte>^ pAuthBlob, int cbMaxAuthBlob, SteamID^ steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure )
		{
			ARRAY_TO_PTR_NOCOPY(authBlob, cbMaxAuthBlob);

			int ret = base->InitiateGameConnection(authBlob, cbMaxAuthBlob, *(steamIDGameServer->base), unIPServer, usPortServer, bSecure );

			ARRAY_COPY(authBlob, pAuthBlob, cbMaxAuthBlob);
			ARRAY_FREE(authBlob);

			return ret;
		}

		void TerminateGameConnection( uint32 unIPServer, uint16 usPortServer )
		{
			base->TerminateGameConnection( unIPServer, usPortServer );
		}

		void TrackAppUsageEvent(GameID^ gameID, int eAppUsageEvent)
		{
			this->TrackAppUsageEvent(gameID, eAppUsageEvent, "");
		}
		void TrackAppUsageEvent( GameID^ gameID, int eAppUsageEvent, String^ pchExtraInfo )
		{
			IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchExtraInfo);
			char *str = (char *)strPtr.ToPointer();

			base->TrackAppUsageEvent( *(gameID->base), eAppUsageEvent, str );

			Marshal::FreeHGlobal(strPtr);
		}

		bool GetUserDataFolder( [Out] String^% pchBuffer, int cubBuffer )
		{
			char *output = new char[cubBuffer];

			bool ret = base->GetUserDataFolder( output, cubBuffer );

			pchBuffer = gcnew String(output);

			delete [] output;

			return ret;
		}

		void StartVoiceRecording( )
		{
			base->StartVoiceRecording();
		}
		void StopVoiceRecording( )
		{
			base->StopVoiceRecording();
		}

		VoiceResult GetCompressedVoice( array<byte>^ pDestBuffer, uint32 cbDestBufferSize, [Out] uint32% nBytesWritten )
		{
			uint32 tempData;

			ARRAY_TO_PTR_NOCOPY(mem, cbDestBufferSize);

			EVoiceResult ret = base->GetCompressedVoice(mem, cbDestBufferSize, &tempData);

			nBytesWritten = tempData;
			ARRAY_COPY(mem, pDestBuffer, cbDestBufferSize);

			ARRAY_FREE(mem);

			return (VoiceResult)ret;
		}
		VoiceResult DecompressVoice( array<byte>^ pCompressed, uint32 cbCompressed, array<byte>^ pDestBuffer, uint32 cbDestBufferSize, [Out] uint32% nBytesWritten )
		{
			uint32 tempData;

			ARRAY_TO_PTR(pCompressed, compressed, cbCompressed);
			ARRAY_TO_PTR_NOCOPY(dest, cbDestBufferSize);

			EVoiceResult ret = base->DecompressVoice( compressed, cbCompressed, dest, cbDestBufferSize, &tempData);

			ARRAY_COPY(dest, pDestBuffer, cbDestBufferSize);
			nBytesWritten = tempData;

			ARRAY_FREE(compressed);
			ARRAY_FREE(dest);

			return (VoiceResult)ret;
		}

		AuthTicketHandle^ GetAuthSessionTicket( array<byte>^ pTicket, int cbMaxTicket, [Out] uint32% pcbTicket )
		{
			void *ticket = malloc(cbMaxTicket);
			IntPtr ptr(ticket);
			uint32 ticketSize;

			HAuthTicket ret = base->GetAuthSessionTicket(ticket, cbMaxTicket, &ticketSize);

			pcbTicket = ticketSize;
			Marshal::Copy(ptr, pTicket, 0, cbMaxTicket);
			free(ticket);

			return gcnew AuthTicketHandle( ret );
		}

		BeginAuthSessionResult BeginAuthSession(  array<byte>^ pAuthTicket, int cbAuthTicket, SteamID^ steamID )
		{
			void *authTicket = malloc(cbAuthTicket);
			IntPtr ptr(authTicket);

			Marshal::Copy(pAuthTicket, 0, ptr, cbAuthTicket);

			EBeginAuthSessionResult ret = base->BeginAuthSession(authTicket, cbAuthTicket, *(steamID->base));

			free(authTicket);
			return (BeginAuthSessionResult)ret;
		}

		void EndAuthSession( SteamID^ steamID )
		{
			base->EndAuthSession( *(steamID->base) );
		}

		void CancelAuthTicket( AuthTicketHandle^ hAuthTicket )
		{
			base->CancelAuthTicket( hAuthTicket->base );
		}

		uint32 UserHasLicenseForApp( SteamID^ steamID, AppID^ appID )
		{
			return base->UserHasLicenseForApp( *(steamID->base), appID->base );
		}

		literal String^ InterfaceVersion = STEAMUSER_INTERFACE_VERSION_012;

	private:
		ISteamUser012 *base;
	};
}