#ifndef UTIL_H
#define UTIL_H

#include "Common.h"

#ifdef _WIN32
#include <windows.h>
LONG WINAPI mdmpfilter(_EXCEPTION_POINTERS *exc_ptr);
#endif

void _Sleep( unsigned int dwMilliseconds );
const char *HumanReadableIP( u_long ip );

#endif // UTIL_H

