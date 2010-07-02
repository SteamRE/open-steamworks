//===== Copyright © 1996-2005, Valve Corporation, All rights reserved. ======//
//
// Purpose:
//
// $NoKeywords: $
//
//===========================================================================//

#ifndef PLATFORM_H
#define PLATFORM_H

//-----------------------------------------------------------------------------
// Methods to invoke the constructor, copy constructor, and destructor
//-----------------------------------------------------------------------------

template <class T>
inline void Construct( T* pMemory )
{
	::new( pMemory ) T;
}

template <class T>
inline void CopyConstruct( T* pMemory, T const& src )
{
	::new( pMemory ) T(src);
}

template <class T>
inline void Destruct( T* pMemory )
{
	pMemory->~T();

#ifdef _DEBUG
	memset( pMemory, 0xDD, sizeof(T) );
#endif
}

#endif /* PLATFORM_H */
