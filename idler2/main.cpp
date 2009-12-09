#include "Common.h"
#include "CClientContext.h"
#include "CServerContext.h"

IdlerContext	*context = NULL;
ISteamClient008 *client  = NULL;
ISteamUtils004	*utils	 = NULL;

void PrintUsage()
{
	using namespace std;

	cout << "Usage: idler2 -server [port] [bind address]" << endl;
	cout << "       idler2 -client ip [port]" << endl;
}

bool StartClient(int argc, char *argv[])
{
	using namespace std;

	if (argc < 3)
	{
		cerr << "Error, no IP specified." << endl << endl;
		PrintUsage();

		return false;
	}

	uint32 ip = htonl(inet_addr(argv[2]));

	if (ip == INADDR_NONE || ip == INADDR_ANY)
	{
		cerr << "Error, invalid IP." << endl << endl;
		PrintUsage();

		return false;
	}

	uint16 port = DEFAULT_PORT;
	if (argc > 3)
	{
		port = (uint16)atoi(argv[3]);

		if (port == 0)
		{
			cerr << "Warning, invalid port. Defaulting to " << DEFAULT_PORT << "." << endl;
			port = DEFAULT_PORT;
		}
	}

	cout << "Connecting to " << HumanReadableIP(ip) << ":" << port << endl;

#ifdef _WIN32
	SetConsoleTitle( "CLIENT" );
#endif
	context = new CClientContext(client, ip, port);
	return true;
}

bool StartServer(int argc, char *argv[])
{
	using namespace std;

	uint16 port = DEFAULT_PORT;
	uint32 bind = htonl(INADDR_ANY);
	if (argc > 2)
	{
		port = (uint16)atoi(argv[2]);

		if (port == 0)
		{
			cerr << "Warning, invalid port (" << argv[2] << "). Defaulting to " << DEFAULT_PORT << "." << endl;
			port = DEFAULT_PORT;
		}

		if(argc > 3)
		{
			bind = htonl(inet_addr(argv[3]));
			if(bind == INADDR_NONE)
			{
				cerr << "Invalid bind address (" << argv[3] << "). Defaulting to INADDR_ANY." << endl;
				bind = htonl(INADDR_ANY);
			}
		}
	}

	cout << "Running server on address: " << HumanReadableIP(bind) << " port: " << port << endl;

#ifdef _WIN32
	SetConsoleTitle( "SERVER" );
#endif
	context = new CServerContext(client, bind, port);
	return true;
}

int main(int argc, char *argv[])
{
#ifdef _MSC_VER
	SetUnhandledExceptionFilter(mdmpfilter);
#endif

	using namespace std;

	SetEnvironmentVariable("SteamAppId", "440");
	/*
	ofstream appIdFile;
	appIdFile.open( "steam_appid.txt" );
	appIdFile << APPID;
	appIdFile.flush();
	appIdFile.close();
*/

	CSteamAPILoader apiloader;

	CreateInterfaceFn clientFactory = apiloader.Load();
	if(clientFactory == NULL)
		return EXIT_FAILURE;

	assert(clientFactory != NULL);
	client = (ISteamClient008 *)clientFactory(STEAMCLIENT_INTERFACE_VERSION_008, NULL);
	assert(client != NULL);

	if (argc < 2)
	{
		PrintUsage();
		return EXIT_FAILURE;
	}

	if (strcmp(argv[1], "-server") == 0)
	{
		if( !StartServer(argc, argv) )
			return EXIT_FAILURE;
	}
	else if (strcmp(argv[1], "-client") == 0)
	{
		if( !StartClient(argc, argv) )
			return EXIT_FAILURE;
	}
	else
	{
		cerr << "Error, no such command \"" << argv[1] << "\"." << endl;
		PrintUsage();

		return EXIT_FAILURE;
	}

	if( context == NULL )
	{
		cerr << "Missing context to run." << endl;
		return EXIT_FAILURE;
	}

	if( context->Begin() )
	{
		HSteamPipe pipe = context->GetPipe();

		utils = (ISteamUtils004 *)client->GetISteamUtils( pipe, STEAMUTILS_INTERFACE_VERSION_004 );
		assert( utils->GetAppID() == APPID );

		CallbackMsg_t callbackMsg;
		HSteamCall steamCall;

		while( context->IsRunning() )
		{
			context->Think();

			if ( Steam_BGetCallback( pipe, &callbackMsg, &steamCall ))
			{
				context->HandleCallback( callbackMsg );

				Steam_FreeLastCallback( pipe );
			}

			_Sleep(10);
		}
	}

	context->End();
	delete context;

	return EXIT_SUCCESS;
}
