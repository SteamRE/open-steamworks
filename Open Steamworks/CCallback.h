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

#ifndef CCALLBACK_H
#define CCALLBACK_H
#ifdef _WIN32
#pragma once
#endif 

#include "SteamTypes.h"

//-----------------------------------------------------------------------------
// Purpose: base for callbacks, 
//			used only by CCallback, shouldn't be used directly
//-----------------------------------------------------------------------------
class CCallbackBase
{
public:
	CCallbackBase() { m_nCallbackFlags = 0; m_iCallback = 0; }
	// don't add a virtual destructor because we export this binary interface across dll's
	virtual void Run( void *pvParam ) = 0;
	virtual void Run( void *pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall ) = 0;
	int GetICallback() { return m_iCallback; }
	virtual int GetCallbackSizeBytes() = 0;

protected:
	enum { k_ECallbackFlagsRegistered = 0x01, k_ECallbackFlagsGameServer = 0x02 };
	uint8 m_nCallbackFlags;
	int m_iCallback;
	friend class CCallbackMgr;
};

//-----------------------------------------------------------------------------
// Purpose: maps a steam async call result to a class member function
//			template params: T = local class, P = parameter struct
//-----------------------------------------------------------------------------
template< class T, class P >
class CCallResult : private CCallbackBase
{
public:
	typedef void (T::*func_t)( P*, bool );

	CCallResult()
	{
		m_hAPICall = 0;
		m_pObj = NULL;
		m_Func = NULL;
		m_iCallback = P::k_iCallback;
	}

	void Set( SteamAPICall_t hAPICall, T *p, func_t func )
	{
		if ( m_hAPICall )
			SteamAPI_UnregisterCallResult( this, m_hAPICall );

		m_hAPICall = hAPICall;
		m_pObj = p;
		m_Func = func;

		if ( hAPICall )
			SteamAPI_RegisterCallResult( this, hAPICall );
	}

	bool IsActive()
	{
		return ( m_hAPICall != 0 );
	}

	void Cancel()
	{
		m_hAPICall = 0;
	}

	~CCallResult()
	{
		if ( m_hAPICall )
			SteamAPI_UnregisterCallResult( this, m_hAPICall );
	}

private:
	virtual void Run( void *pvParam )
	{
		m_hAPICall = 0;
		(m_pObj->*m_Func)( (P *)pvParam, false );		
	}
	void Run( void *pvParam, bool bIOFailure, SteamAPICall_t hSteamAPICall )
	{
		if ( hSteamAPICall == m_hAPICall )
		{
			m_hAPICall = 0;
			(m_pObj->*m_Func)( (P *)pvParam, bIOFailure );			
		}
	}
	int GetCallbackSizeBytes()
	{
		return sizeof( P );
	}

	SteamAPICall_t m_hAPICall;
	T *m_pObj;
	func_t m_Func;
};



//-----------------------------------------------------------------------------
// Purpose: maps a steam callback to a class member function
//			template params: T = local class, P = parameter struct
//-----------------------------------------------------------------------------
template< class T, class P, bool bGameServer >
class CCallback : private CCallbackBase
{
public:
	typedef void (T::*func_t)( P* );

	// If you can't support constructing a callback with the correct parameters
	// then uncomment the empty constructor below and manually call
	// ::Register() for your object
	// Or, just call the regular constructor with (NULL, NULL)
	// CCallback() {}
	
	// constructor for initializing this object in owner's constructor
	CCallback( T *pObj, func_t func ) : m_pObj( pObj ), m_Func( func )
	{
		if ( pObj && func )
			Register( pObj, func );
	}

	~CCallback()
	{
		Unregister();
	}

	// manual registration of the callback
	void Register( T *pObj, func_t func )
	{
		if ( m_nCallbackFlags & k_ECallbackFlagsRegistered )
			Unregister();

		if ( bGameServer )
		{
			m_nCallbackFlags |= k_ECallbackFlagsGameServer;
		}
		m_pObj = pObj;
		m_Func = func;
		SteamAPI_RegisterCallback( this, P::k_iCallback );
	}

	void Unregister()
	{
		SteamAPI_UnregisterCallback( this );
	}

private:
	virtual void Run( void *pvParam )
	{
		(m_pObj->*m_Func)( (P *)pvParam );
	}
	virtual void Run( void *pvParam, bool, SteamAPICall_t )
	{
		(m_pObj->*m_Func)( (P *)pvParam );
	}
	int GetCallbackSizeBytes()
	{
		return sizeof( P );
	}

	T *m_pObj;
	func_t m_Func;
};



#ifdef _WIN32
// disable this warning; this pattern need for steam callback registration
#pragma warning( disable: 4355 )	// 'this' : used in base member initializer list
#endif

// utility macro for declaring the function and callback object together
#define STEAM_CALLBACK( thisclass, func, param, var ) CCallback< thisclass, param, false > var; void func( param *pParam )
#define STEAM_GAMESERVER_CALLBACK( thisclass, func, param, var ) CCallback< thisclass, param, true > var; void func( param *pParam )


#endif // CCALLBACK_H
