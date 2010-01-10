#include "Steamworks.h"

#include <iostream>
#include <iomanip>

#include "../fmod/fmod.hpp"
#include "../fmod/fmod_errors.h"
#pragma comment(lib, "../fmodex_vc")

#pragma comment(lib, "../steamclient")

#define ERRCHECK( result ) \
	if ( result != FMOD_OK ) \
	{ \
		printf("FMOD error! (%d): %s", result, FMOD_ErrorString( result ) ); \
		getchar(); \
		exit( EXIT_FAILURE ); \
	}


int main()
{
	FMOD::System *system;
	FMOD_RESULT result;
	
	result = FMOD::System_Create( &system );
	ERRCHECK( result );

	result = system->init( 100, FMOD_INIT_NORMAL, NULL);
	ERRCHECK( result );


	CSteamAPILoader loader;

	CreateInterfaceFn factory = loader.Load();

	ISteamClient008 *steamClient = (ISteamClient008 *)factory( STEAMCLIENT_INTERFACE_VERSION_008, NULL );

	HSteamPipe pipe = steamClient->CreateSteamPipe();
	HSteamUser user = steamClient->ConnectToGlobalUser( pipe );

	ISteamUser012 *steamUser = (ISteamUser012 *)steamClient->GetISteamUser( user, pipe, STEAMUSER_INTERFACE_VERSION_012 );

	getchar();

	printf( "RECORDING\n" );
	steamUser->StartVoiceRecording();

	steamUser->StopVoiceRecording();
	printf( "DONE!\n" );

	void *pVoiceData = malloc( 10000 );
	uint32 actualSize;

	void *pUncompressed = malloc( 50000 );
	uint32 realSize;

	while ( steamUser->GetCompressedVoice( pVoiceData, 10000, &actualSize ) != k_EVoiceResultOK ) ;

	EVoiceResult res = steamUser->DecompressVoice( pVoiceData, actualSize, pUncompressed, 50000, &realSize );

	FMOD_CREATESOUNDEXINFO exInfo;
	memset( (void*)&exInfo, 0, sizeof( FMOD_CREATESOUNDEXINFO ) );
	exInfo.cbsize = sizeof( FMOD_CREATESOUNDEXINFO );
	exInfo.length = realSize;
	exInfo.defaultfrequency = 11025;
	exInfo.numchannels = 1;
	exInfo.format = FMOD_SOUND_FORMAT_PCM16;

	FMOD::Sound *snd;

	result = system->createSound( (char *)pUncompressed, FMOD_HARDWARE | FMOD_OPENMEMORY | FMOD_OPENRAW, &exInfo, &snd );
	ERRCHECK( result );

	FMOD::Channel *chan;
	result = system->playSound( FMOD_CHANNEL_FREE, snd, false, &chan );
	ERRCHECK( result );

	CallbackMsg_t callbackMsg;
	HSteamCall call;
	while ( true )
	{
		if ( Steam_BGetCallback( pipe, &callbackMsg, &call ) )
		{
			int32 callBack = callbackMsg.m_iCallback;
			ECallbackType type = (ECallbackType)((callBack / 100) * 100);

			std::cout << "[SERVER] Unhandled Callback: " << callBack << ", Type: " << EnumString<ECallbackType>::From(type) << ", Size: " << callbackMsg.m_cubParam << std::endl;

			int32 callSize = callbackMsg.m_cubParam;
			unsigned char *data = callbackMsg.m_pubParam;
			std::cout << "  ";
			for (int i = 0; i < callSize; i++)
			{
				unsigned char value = data[i];

				std::cout << std::hex << std::setw(2) << std::setfill('0') << std::uppercase << (unsigned int)value;
				std::cout << " ";
			}

			std::cout << std::resetiosflags(std::ios_base::hex | std::ios_base::uppercase) << std::endl;

			Steam_FreeLastCallback( pipe );
		}

		system->update();

		Sleep(1);
	}

}