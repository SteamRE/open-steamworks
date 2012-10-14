/*
	This file is a part of "Chat Logger++"
	©2k12, Didrole
	
	License : Public domain
*/

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "SigScanner.h"


CSigScanner::CSigScanner(const void* hModule) : m_pAllocationBase(NULL), m_uSize(0)
{
	if(!hModule)
		return;

	MEMORY_BASIC_INFORMATION basicInformation;

	if(!VirtualQuery(hModule, &basicInformation, sizeof(basicInformation)))
		return;

	const IMAGE_DOS_HEADER *pDOSHeader = (IMAGE_DOS_HEADER*)basicInformation.AllocationBase;
	const IMAGE_NT_HEADERS *pNTHeader = (IMAGE_NT_HEADERS*)(((unsigned char*)basicInformation.AllocationBase) + pDOSHeader->e_lfanew);

	if(pNTHeader->Signature != IMAGE_NT_SIGNATURE)
		return;

	m_pAllocationBase = basicInformation.AllocationBase;
	m_uSize = pNTHeader->OptionalHeader.SizeOfImage;
}

void* CSigScanner::FindSignature(const unsigned char* pubSignature, const char* cszMask, bool bSearchUp/* = false*/, const void* pPreviousMatch/* = NULL*/) const
{
	if(!m_pAllocationBase || !cszMask || !*cszMask)
		return NULL;

	unsigned char *pCurrent = NULL;

	unsigned int uSignatureLength = (unsigned int)strlen(cszMask);

	if(!bSearchUp)
	{
		if(pPreviousMatch)
		{
			if(pPreviousMatch < m_pAllocationBase || (unsigned char*)pPreviousMatch + uSignatureLength > (unsigned char*)m_pAllocationBase + m_uSize)
				return NULL;

			pCurrent = (unsigned char*)pPreviousMatch + 1;
		}
		else
			pCurrent = (unsigned char *)m_pAllocationBase;

		unsigned char *pEnd = (unsigned char*)m_pAllocationBase + m_uSize;

		unsigned int i;

		for(; pCurrent < pEnd && (unsigned long)(pEnd - pCurrent) >= uSignatureLength; pCurrent++)
		{
			for(i = 0; cszMask[i] != '\0'; i++)
			{
				if((cszMask[i] != '?') && (pubSignature[i] != pCurrent[i]))
					break;
			}
			if(cszMask[i] == '\0')
				return pCurrent;
		}
		return NULL;
	}
	else
	{
		if(pPreviousMatch)
		{
			if((unsigned char*)pPreviousMatch - uSignatureLength < m_pAllocationBase || pPreviousMatch > (unsigned char*)m_pAllocationBase + m_uSize)
				return NULL;

			pCurrent = (unsigned char*)pPreviousMatch - 1;
		}
		else
			pCurrent = (unsigned char*)m_pAllocationBase + m_uSize - uSignatureLength;

		unsigned char *pEnd = (unsigned char*)m_pAllocationBase;

		unsigned int i;

		for(; pCurrent > pEnd && (unsigned long)(pCurrent - pEnd) >= uSignatureLength; pCurrent--)
		{
			for(i = 0; cszMask[i] != '\0'; i++)
			{
				if((cszMask[i] != '?') && (pubSignature[i] != pCurrent[i]))
					break;
			}
			if(cszMask[i] == '\0')
				return pCurrent;
		}
		return NULL;
	}
}