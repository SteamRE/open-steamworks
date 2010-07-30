#include "Steamworks.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

#pragma comment(lib, "../steamclient.lib" )

#ifndef _WIN32
void Sleep(int x) {
	usleep(x);
}
#endif


int main()
{
	using namespace std;

	CSteamAPILoader loader;
	CreateInterfaceFn factory = loader.Load();

	ISteamClient009 *steamClient = (ISteamClient009 *)factory( STEAMCLIENT_INTERFACE_VERSION_009, NULL );
	if ( !steamClient )
	{
		cout << "Error: Unable to load steamclient.dll" << endl;
		return EXIT_FAILURE;
	}

	HSteamPipe steamPipe = steamClient->CreateSteamPipe();
	HSteamUser steamUser = steamClient->ConnectToGlobalUser( steamPipe );

	CallbackMsg_t callbackMsg;

	char fileName[] = "log.txt";
	fstream logFile( fileName, fstream::out | fstream::in | fstream::app );

	while ( true )
	{
		if ( Steam_BGetCallback( steamPipe, &callbackMsg ) )
		{
			int32 callBack = callbackMsg.m_iCallback;
			ECallbackType type = ( ECallbackType )( ( callBack / 100 ) * 100 );
			
			cout << "Callback: " << callBack << ", Type: " << type << ", Size: " << callbackMsg.m_cubParam << endl << "  ";
			logFile << "Callback: " << callBack << ", Type: " << type << ", Size: " << callbackMsg.m_cubParam << endl << "  ";
			
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

			Steam_FreeLastCallback( steamPipe );
		}

		Sleep(10);
	}

	return EXIT_SUCCESS;
}