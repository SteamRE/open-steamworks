#ifndef COMMON_H
#define COMMON_H
#ifdef _WIN32
#pragma once
#endif

#define APPID 440

#define DEFAULT_PORT 6868

#define AUTHTICKET_SIZE 1024

#define MOTD_SIZE 512
#define MESSAGE_SIZE 256

// maximum amount of clients able to connect to a server
#define MAX_CLIENTS 100

#define PING_INTERVAL 30
#define PING_TIMEOUT 40

#define ITEM_MAXNAMELEN 64

#include <boost/cstdlib.hpp>
#include <boost/unordered_map.hpp>
#include <fstream>
#include <sstream>
#include <ostream>
#include <iostream>
#include <iomanip>
#include <time.h>

#include "Steamworks.h"
#include "Common.h"
#include "NetMessages.h"
#include "util.h"
#include "IdlerContext.h"
#include "FileLogger.h"

#endif // COMMON_H
