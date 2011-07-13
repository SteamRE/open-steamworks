//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#ifndef ICLIENTHTTP_H
#define ICLIENTHTTP_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "HTTPCommon.h"

abstract_class UNSAFE_INTERFACE IClientHTTP
{
public:
	virtual HTTPRequestHandle CreateHTTPRequest( EHTTPMethod eHTTPRequestMethod, char *pchAbsoluteURL ) = 0;
	
	virtual bool SetHTTPRequestContextValue( HTTPRequestHandle hRequest, uint64 ulContextValue ) = 0;
	virtual bool SetHTTPRequestNetworkActivityTimeout( HTTPRequestHandle hRequest, uint32 unTimeoutSeconds ) = 0;
	virtual bool SetHTTPRequestHeaderValue( HTTPRequestHandle hRequest, char *pchHeaderName, char *pchHeaderValue ) = 0;
	virtual bool SetHTTPRequestGetOrPostParameter( HTTPRequestHandle hRequest, char *pchParamName, char *pchParamValue ) = 0;
	
	virtual bool SendHTTPRequest( HTTPRequestHandle hRequest, SteamAPICall_t *pCallHandle ) = 0;
	virtual bool DeferHTTPRequest( HTTPRequestHandle hRequest ) = 0;
	virtual bool PrioritizeHTTPRequest( HTTPRequestHandle hRequest ) = 0;
	virtual bool CancelHTTPRequest( HTTPRequestHandle hRequest ) = 0;
	
	virtual bool GetHTTPResponseHeaderSize( HTTPRequestHandle hRequest, char *pchHeaderName, uint32 *unResponseHeaderSize ) = 0;
	virtual bool GetHTTPResponseHeaderValue( HTTPRequestHandle hRequest, char *pchHeaderName, uint8 *pHeaderValueBuffer, uint32 uBufferSize ) = 0;
	virtual bool GetHTTPResponseBodySize( HTTPRequestHandle hRequest, uint32 *unBodySize ) = 0;
	virtual bool GetHTTPResponseBodyData( HTTPRequestHandle hRequest, uint8 *pBodyDataBuffer, uint32 unBufferSize ) = 0;
	
	virtual bool ReleaseHTTPRequest( HTTPRequestHandle hRequest ) = 0;
	virtual bool GetHTTPDownloadProgressPct( HTTPRequestHandle hRequest, float * pflProgress ) = 0;

	virtual bool SetHTTPRequestRawPostBody( HTTPRequestHandle hRequest, const char *pchContentType, uint8 *pubBodyData, uint32 cubBodyData ) = 0;
};

#endif // ICLIENTHTTP_H
