#pragma once

/* example config

[SteamAPI]
SteamClient = SteamClient008
SteamUtils = SteamUtils003

*/

class ConfigReader
{

public:
	ConfigReader( const char *fileName );


	bool GetConfigString( const char *configName, char *configValue, uint32 outSize );
	bool GetConfigInt( const char *configName, int *configValue );

	bool FileExists();


private:
	char m_FileName[ 260 ];

};
