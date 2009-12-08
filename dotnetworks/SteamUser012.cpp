
#include "SteamUser012.h"

#include "Macros.h"

namespace dotnetworks
{

	SteamUser012::SteamUser012( void *steamUser )
	{
		base = (ISteamUser012 *)steamUser;
	}
	
	SteamUserHandle^ SteamUser012::GetHSteamUser()
	{
		return gcnew SteamUserHandle( base->GetHSteamUser() );
	}

	bool SteamUser012::LoggedOn()
	{
		return base->LoggedOn();
	}

	SteamID^ SteamUser012::GetSteamID()
	{
		return gcnew SteamID( base->GetSteamID() );
	}

	int SteamUser012::InitiateGameConnection( array<byte>^ pAuthBlob, int cbMaxAuthBlob, SteamID^ steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure )
	{
		ARRAY_TO_PTR_NOCOPY(authBlob, cbMaxAuthBlob);

		int ret = base->InitiateGameConnection(authBlob, cbMaxAuthBlob, *(steamIDGameServer->base), unIPServer, usPortServer, bSecure );

		ARRAY_COPY(authBlob, pAuthBlob, cbMaxAuthBlob);
		ARRAY_FREE(authBlob);

		return ret;
	}

	void SteamUser012::TerminateGameConnection( uint32 unIPServer, uint16 usPortServer )
	{
		base->TerminateGameConnection( unIPServer, usPortServer );
	}

	void SteamUser012::TrackAppUsageEvent(GameID^ gameID, int eAppUsageEvent)
	{
		this->TrackAppUsageEvent(gameID, eAppUsageEvent, "");
	}
	void SteamUser012::TrackAppUsageEvent( GameID^ gameID, int eAppUsageEvent, String^ pchExtraInfo )
	{
		IntPtr strPtr = Marshal::StringToHGlobalAnsi(pchExtraInfo);
		char *str = (char *)strPtr.ToPointer();

		base->TrackAppUsageEvent( *(gameID->base), eAppUsageEvent, str );

		Marshal::FreeHGlobal(strPtr);
	}

	bool SteamUser012::GetUserDataFolder( [Out] String^% pchBuffer, int cubBuffer )
	{		
		char *output = new char[cubBuffer];

		bool ret = base->GetUserDataFolder( output, cubBuffer );

		pchBuffer = gcnew String(output);

		delete [] output;

		return ret;
	}

	void SteamUser012::StartVoiceRecording( )
	{
		base->StartVoiceRecording();
	}
	void SteamUser012::StopVoiceRecording( )
	{
		base->StopVoiceRecording();
	}

	VoiceResult SteamUser012::GetCompressedVoice( array<byte>^ pDestBuffer, uint32 cbDestBufferSize, [Out] uint32% nBytesWritten )
	{
		uint32 tempData;

		ARRAY_TO_PTR_NOCOPY(mem, cbDestBufferSize);

		EVoiceResult ret = base->GetCompressedVoice(mem, cbDestBufferSize, &tempData);

		nBytesWritten = tempData;
		ARRAY_COPY(mem, pDestBuffer, cbDestBufferSize);

		ARRAY_FREE(mem);

		return (VoiceResult)ret;
	}
	VoiceResult SteamUser012::DecompressVoice( array<byte>^ pCompressed, uint32 cbCompressed, array<byte>^ pDestBuffer, uint32 cbDestBufferSize, [Out] uint32% nBytesWritten )
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
	
	AuthTicketHandle^ SteamUser012::GetAuthSessionTicket( array<byte>^ pTicket, int cbMaxTicket, [Out] uint32% pcbTicket )
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

	BeginAuthSessionResult SteamUser012::BeginAuthSession(  array<byte>^ pAuthTicket, int cbAuthTicket, SteamID^ steamID )
	{
		void *authTicket = malloc(cbAuthTicket);
		IntPtr ptr(authTicket);

		Marshal::Copy(pAuthTicket, 0, ptr, cbAuthTicket);

		EBeginAuthSessionResult ret = base->BeginAuthSession(authTicket, cbAuthTicket, *(steamID->base));

		free(authTicket);
		return (BeginAuthSessionResult)ret;
	}

	void SteamUser012::EndAuthSession( SteamID^ steamID )
	{
		base->EndAuthSession( *(steamID->base) );
	}

	void SteamUser012::CancelAuthTicket( AuthTicketHandle^ hAuthTicket )
	{
		base->CancelAuthTicket( hAuthTicket->base );
	}

	uint32 SteamUser012::UserHasLicenseForApp( SteamID^ steamID, AppID^ appID )
	{
		return base->UserHasLicenseForApp( *(steamID->base), appID->base );
	}

}