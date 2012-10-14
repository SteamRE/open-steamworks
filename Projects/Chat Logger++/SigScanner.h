/*
	This file is a part of "Chat Logger++"
	©2k12, Didrole
	
	License : Public domain
*/

#pragma once

class CSigScanner
{
public:
	CSigScanner(const void* hModule);

	void* FindSignature(const char* pubSignature, const char* cszMask, bool bSearchUp = false, const void* pPreviousMatch = NULL) const;
	void* FindSignature(const unsigned char* pubSignature, const char* cszMask, bool bSearchUp = false, const void* pPreviousMatch = NULL) const;

private:
	const void* m_pAllocationBase;
	unsigned int m_uSize;
};

inline void* CSigScanner::FindSignature(const char* pubSignature, const char* cszMask, bool bSearchUp/* = false*/, const void* pPreviousMatch/* = NULL*/) const
{
	return FindSignature((const unsigned char*)pubSignature, cszMask, bSearchUp, pPreviousMatch);
}
