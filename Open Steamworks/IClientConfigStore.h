//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code,  comments,  and all related files,  projects,  resources, 
// redistributables included with this project are Copyright Valve Corporation.
// Additionally,  Valve,  the Valve logo,  Half-Life,  the Half-Life logo,  the
// Lambda logo,  Steam,  the Steam logo,  Team Fortress,  the Team Fortress logo, 
// Opposing Force,  Day of Defeat,  the Day of Defeat logo,  Counter-Strike,  the
// Counter-Strike logo,  Source,  the Source logo,  and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#ifndef ICLIENTCONFIGSTORE_H
#define ICLIENTCONFIGSTORE_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "UtilsCommon.h"


#define CLIENTCONFIGSTORE_INTERFACE_VERSION "CLIENTCONFIGSTORE_INTERFACE_VERSION001"


abstract_class UNSAFE_INTERFACE IClientConfigStore
{
public:
	virtual bool IsSet( EConfigStore eConfigStore, const char *keyName ) = 0;

	virtual bool GetBool( EConfigStore eConfigStore, const char *keyName, bool defaultValue ) = 0;
	virtual int GetInt( EConfigStore eConfigStore, const char *keyName, int defaultValue ) = 0;
	virtual uint64 GetUint64( EConfigStore eConfigStore, const char *keyName, uint64 defaultValue ) = 0;
	virtual float GetFloat( EConfigStore eConfigStore, const char *keyName, float defaultValue ) = 0;
	virtual const char* GetString( EConfigStore eConfigStore, const char *keyName, const char *defaultValue ) = 0;
	virtual bool GetBinary( EConfigStore eConfigStore, const char *keyName, uint8 *pBuffer, uint32 uSize ) = 0;
	virtual bool GetBinaryWatermarked( EConfigStore eConfigStore, const char *keyName, uint8 *pBuffer, uint32 uSize ) = 0;

	virtual void SetBool( EConfigStore eConfigStore, const char *keyName, bool value ) = 0;
	virtual void SetInt( EConfigStore eConfigStore, const char *keyName, int value ) = 0;
	virtual void SetUint64( EConfigStore eConfigStore, const char *keyName, uint64 value ) = 0;
	virtual void SetFloat( EConfigStore eConfigStore, const char *keyName, float value ) = 0;
	virtual void SetString( EConfigStore eConfigStore, const char *keyName, const char *value ) = 0;
	virtual void SetBinary( EConfigStore eConfigStore, const char *keyName, const uint8 *pBuffer, uint32 uSize ) = 0;
	virtual void SetBinaryWatermarked( EConfigStore eConfigStore, const char *keyName, const uint8 *pBuffer, uint32 uSize ) = 0;

	virtual void RemoveKey( EConfigStore eConfigStore, const char *keyName ) = 0;
	virtual bool GetKeySerialized( EConfigStore eConfigStore, const char *keyName, uint8 *pBuffer, int iSize ) = 0;

	virtual bool FlushToDisk( bool ) = 0;
};

#endif // ICLIENTCONFIGSTORE_H
