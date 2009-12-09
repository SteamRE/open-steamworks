#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "Common.h"

class CFileLogger
{

public:
	CFileLogger( const char *fName );
	~CFileLogger();

	void Log( const char *msg );

private:
	char *m_fName;

};


#endif
