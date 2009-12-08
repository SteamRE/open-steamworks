#ifndef LOG_H
#define LOG_H

#include "Common.h"

#define FORMAT_MAX 1024
#define LOG_FILE "steam.dll.log"

#define LOG_BUFF_MAX 2024 * 2
#define LOG_LINE_MAX (LOG_BUFF_MAX + 1024)

template <class ObjectType> 
class Formatter
{
public:
	static char *From( ObjectType *type, char *format, ... );

private:
	static char privBuff[ FORMAT_MAX ];
};


char *FormatTSteamError( TSteamError *error );
char *FormatTSteamProgress( TSteamProgress *progress );
char *FormatTSteamOfflineStatus( TSteamOfflineStatus *status );
char *FormatTSteamElemInfo( TSteamElemInfo *info );
char *FormatTSteamGlobalUserID( TSteamGlobalUserID *id );
char *FormatTSteamApp( TSteamApp *app );
char *FormatTSteamAppStats( TSteamAppStats *appStats );
char *FormatTSteamAppDependencyInfo( TSteamAppDependencyInfo *appDep );
char *FormatTSteamSubscriptionStats( TSteamSubscriptionStats *subStats );
char *FormatTSteamSubscription( TSteamSubscription *sub );
char *FormatTSteamAppLaunchOption( TSteamAppLaunchOption *appLaunch );

void Log(const char *msg, char *module, ...);
void Log(const char *msg );


#endif // LOG_H
