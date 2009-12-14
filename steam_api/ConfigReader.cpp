#include "StdAfx.h"
#include "ConfigReader.h"

ConfigReader::ConfigReader( const char *fileName )
{
#ifdef WIN32
	strcpy_s( m_FileName, 260, fileName );
#else
	strlcpy( m_FileName, fileName, 260 );
#endif
}

bool ConfigReader::GetConfigString( const char *configName, char *configValue, uint32 outSize )
{
	// boost? heh, no.

	if ( !configName || !configValue || !outSize )
		return false;

#ifdef WIN32
	DWORD numWritten = GetPrivateProfileString( "SteamAPI", configName, NULL, configValue, outSize, m_FileName );

	if ( !numWritten )
		return false;

#else
	// todo: implement me!
#endif

	return true;
}

bool ConfigReader::GetConfigInt( const char *configName, int *configValue )
{
	if ( !configName || !configValue )
		return false;

#ifdef WIN32
	uint32 ret = GetPrivateProfileInt( "SteamAPI", configName, -1, m_FileName );

	if ( ret == -1 )
		return false;

	*configValue = ret;

#else
	// todo: implement me!
#endif

	return true;
}

bool ConfigReader::FileExists()
{
	std::ifstream fileStream( m_FileName );
	bool exists = fileStream.good();

	fileStream.close();

	return exists;
}