#include "SteamclientAPI.h"
#include "SteamAPI.h"

#include <iostream>
#include <iomanip>
#include <fstream>

#pragma comment(lib, "..\\steamclient")

ISteamClient008 *steamClient = NULL;

HSteamPipe pipe = NULL;
HSteamUser user = NULL;

SYSTEMTIME time;


int main()
{
	using namespace std;

	Sys_LoadInterface( "steamclient", STEAMCLIENT_INTERFACE_VERSION_008, NULL, (void**)&steamClient );
	if ( !steamClient )
	{
		cout << "Error: Unable to load steamclient.dll" << endl;
		return EXIT_FAILURE;
	}

	pipe = steamClient->CreateSteamPipe();
	while (!pipe) // keep trying to get the pipe
	{
		pipe = steamClient->CreateSteamPipe();
		cout << ".";

		Sleep(100);
	}

	user = steamClient->ConnectToGlobalUser( pipe );
	while (!user)
	{
		user = steamClient->ConnectToGlobalUser( pipe);
		cout << ".";

		Sleep(100);
	}

	if ( !( pipe && user ) )
	{
		cout << "Unable to create steam pipe or user, please ensure steam is running and you are logged in." << endl;
		return EXIT_FAILURE;
	}

	CallbackMsg_t callbackMsg;
	HSteamCall steamCall;

	GetLocalTime(&time);

	char fileName[] = "log.txt";
	fstream logFile( fileName, fstream::out | fstream::in | fstream::app );

	while ( true )
	{
		if ( Steam_BGetCallback( pipe, &callbackMsg, &steamCall ) )
		{
			int32 callBack = callbackMsg.m_iCallback;
			ECallbackType type = ( ECallbackType )( ( callBack / 100 ) * 100 );

			cout << "Callback: " << callBack << ", Type: " << EnumString<ECallbackType>::From( type ) << ", Size: " << callbackMsg.m_cubParam << endl << "  ";
			logFile << "Callback: " << callBack << ", Type: " << EnumString<ECallbackType>::From( type ) << ", Size: " << callbackMsg.m_cubParam << endl << "  ";

			for ( int i = 0; i < callbackMsg.m_cubParam; i++ )
			{
				unsigned char value = callbackMsg.m_pubParam[ i ];
			
				cout << hex << setw( 2 ) << setfill( '0' ) << uppercase << (unsigned int)value;
				cout << " ";

				logFile << hex << setw( 2 ) << setfill( '0' ) << uppercase << (unsigned int)value;
				logFile << " ";
			}

			// log to file

			cout << resetiosflags( ios_base::hex | ios_base::uppercase ) << endl;
			logFile << resetiosflags( ios_base::hex | ios_base::uppercase ) << endl;

			cout << endl;
			logFile << endl;

			logFile.flush();

			Steam_FreeLastCallback( pipe );
		}

		Sleep(10);
	}

	return EXIT_SUCCESS;
}