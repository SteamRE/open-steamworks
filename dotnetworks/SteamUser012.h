#pragma once

#include "SteamclientAPI.h"

#include "VoiceResult.h"
#include "SteamUserHandle.h"
#include "SteamID.h"
#include "AuthTicketHandle.h"
#include "BeginAuthSessionResult.h"
#include "GameID.h"
#include "AppID.h"

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
		SteamUser012( void *steamUser );
		
	public:
		SteamUserHandle^ GetHSteamUser();

		bool LoggedOn();

		SteamID^ GetSteamID();

		int InitiateGameConnection( array<byte>^ pAuthBlob, int cbMaxAuthBlob, SteamID^ steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure );

		void TerminateGameConnection( uint32 unIPServer, uint16 usPortServer );

		void TrackAppUsageEvent(GameID^ gameID, int eAppUsageEvent);
		void TrackAppUsageEvent( GameID^ gameID, int eAppUsageEvent, String^ pchExtraInfo );

		bool GetUserDataFolder( [Out] String^% pchBuffer, int cubBuffer );

		void StartVoiceRecording( );
		void StopVoiceRecording( );

		VoiceResult GetCompressedVoice( array<byte>^ pDestBuffer, uint32 cbDestBufferSize, [Out] uint32% nBytesWritten );
		VoiceResult DecompressVoice( array<byte>^ pCompressed, uint32 cbCompressed, array<byte>^ pDestBuffer, uint32 cbDestBufferSize, [Out] uint32% nBytesWritten );
		
		AuthTicketHandle^ GetAuthSessionTicket( array<byte>^ pTicket, int cbMaxTicket, [Out] uint32% pcbTicket );

		BeginAuthSessionResult BeginAuthSession(  array<byte>^ pAuthTicket, int cbAuthTicket, SteamID^ steamID );

		void EndAuthSession( SteamID^ steamID );

		void CancelAuthTicket( AuthTicketHandle^ hAuthTicket );

		uint32 UserHasLicenseForApp( SteamID^ steamID, AppID^ appID );

		literal String^ InterfaceVersion = STEAMUSER_INTERFACE_VERSION_012;

	private:
		ISteamUser012 *base;
	};
}