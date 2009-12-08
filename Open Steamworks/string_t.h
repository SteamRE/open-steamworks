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

#ifndef STRING_T_H
#define STRING_T_H

#if defined( _WIN32 )
#pragma once
#endif


#ifndef NO_STRING_T

#ifdef WEAK_STRING_T

typedef int	string_t;

//-----------------------------------------------------------------------------
// Purpose: The correct way to specify the NULL string as a constant.
//-----------------------------------------------------------------------------

#define NULL_STRING			0

//-----------------------------------------------------------------------------
// Purpose: Given a string_t, make a C string. By convention the result string 
// 			pointer should be considered transient and should not be stored.
//-----------------------------------------------------------------------------

#define STRING( offset )	( ( offset ) ? reinterpret_cast<const char *>( offset ) : "" )

//-----------------------------------------------------------------------------
// Purpose: Given a C string, obtain a string_t
//-----------------------------------------------------------------------------

#define MAKE_STRING( str )	( ( *str != 0 ) ? reinterpret_cast<int>( str ) : 0 )

//-----------------------------------------------------------------------------

#define IDENT_STRINGS( s1, s2 )	( *((void **)&(s1)) == *((void **)&(s2)) )

//-----------------------------------------------------------------------------

#else // Strong string_t

//-----------------------------------------------------------------------------

struct string_t
{
public:
	bool operator!() const							{ return ( pszValue == NULL );			}
	bool operator==( const string_t &rhs ) const	{ return ( pszValue == rhs.pszValue );	}
	bool operator!=( const string_t &rhs ) const	{ return ( pszValue != rhs.pszValue );	}
	bool operator<( const string_t &rhs ) const		{ return ((void *)pszValue < (void *)rhs.pszValue ); }

	const char *ToCStr() const						{ return ( pszValue ) ? pszValue : ""; 	}
	
protected:
	const char *pszValue;
};

//-----------------------------------------------------------------------------

struct castable_string_t : public string_t // string_t is used in unions, hence, no constructor allowed
{
	castable_string_t()							{ pszValue = NULL; }
	castable_string_t( const char *pszFrom )	{ pszValue = (pszFrom && *pszFrom) ? pszFrom : 0; }
};

//-----------------------------------------------------------------------------
// Purpose: The correct way to specify the NULL string as a constant.
//-----------------------------------------------------------------------------

#define NULL_STRING			castable_string_t()

//-----------------------------------------------------------------------------
// Purpose: Given a string_t, make a C string. By convention the result string 
// 			pointer should be considered transient and should not be stored.
//-----------------------------------------------------------------------------

#define STRING( string_t_obj )	(string_t_obj).ToCStr()

//-----------------------------------------------------------------------------
// Purpose: Given a C string, obtain a string_t
//-----------------------------------------------------------------------------

#define MAKE_STRING( c_str )	castable_string_t( c_str )

//-----------------------------------------------------------------------------

#define IDENT_STRINGS( s1, s2 )	( *((void **)&(s1)) == *((void **)&(s2)) )

//-----------------------------------------------------------------------------

#endif


#else	// NO_STRING_T

typedef const char *string_t;
#define NULL_STRING				0
#define STRING( c_str )			( c_str )
#define MAKE_STRING( c_str )	( c_str )
#define IDENT_STRINGS( s1, s2 )	( *((void **)&(s1)) == *((void **)&(s2)) )

#endif	// NO_STRING_T

//=============================================================================

#endif // STRING_T_H
