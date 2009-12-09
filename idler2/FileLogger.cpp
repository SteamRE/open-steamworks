
#include "FileLogger.h"

CFileLogger::CFileLogger( const char *fName )
{
	m_fName = new char[ 260 ];
	_strcpy_s( m_fName, 260, fName );
}

CFileLogger::~CFileLogger()
{
	delete [] m_fName;
}


void CFileLogger::Log( const char *msg )
{
	FILE *hFile = fopen( m_fName, "a" );
	if ( !hFile )
		return;

	fwrite( msg, 1, strlen( msg ), hFile );

	fclose( hFile );
}
