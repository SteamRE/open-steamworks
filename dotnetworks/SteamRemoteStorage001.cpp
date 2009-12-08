
#include "SteamRemoteStorage001.h"

#include "Macros.h"

namespace dotnetworks
{

	SteamRemoteStorage001::SteamRemoteStorage001( void *steamRemoteStorage )
	{
		base = (ISteamRemoteStorage001 *)steamRemoteStorage;
	}

	bool SteamRemoteStorage001::FileWrite( String ^psFile, array<Byte>^ pvData, int32 cubData )
	{
		STR_FROM_MANAGED(psFile, str);
		ARRAY_TO_PTR(pvData, mem, cubData );

		bool ret = base->FileWrite( str, mem, cubData );

		STR_FREE(str);
		ARRAY_FREE(mem);

		return ret;
	}

	bool SteamRemoteStorage001::FileRead( String^ filename, array<Byte>^ buffer, int size )
	{
		STR_FROM_MANAGED(filename, str);

		IntPtr memPtr = Marshal::AllocHGlobal(size);
		void *mem = (void *)memPtr.ToPointer();
		bool ret = base->FileRead( str, mem, size );

		Marshal::Copy(memPtr, buffer, 0, size);
		
		Marshal::FreeHGlobal(memPtr);
		STR_FREE(str);

		return ret;
	}

	bool SteamRemoteStorage001::FileExists( String^ psFile )
	{
		STR_FROM_MANAGED(psFile, str);

		bool ret = base->FileExists( str );

		STR_FREE(str);
		return ret;
	}

	bool SteamRemoteStorage001::FileDelete( String^ psFile )
	{
		STR_FROM_MANAGED(psFile, str);

		bool ret = base->FileDelete( str );

		STR_FREE(str);
		return ret;
	}

	uint32 SteamRemoteStorage001::GetFileCount()
	{
		return base->GetFileCount();
	}

	String^ SteamRemoteStorage001::GetFileNameAndSize(int index, int% size)
	{
		int tempSize;

		String^ ret = gcnew String( base->GetFileNameAndSize(index, &tempSize) );

		size = tempSize;
		return ret;
	}

	bool SteamRemoteStorage001::GetQuota(int% current, int% maximum)
	{
		int tempCurr, tempMax;

		bool ret = base->GetQuota(&tempCurr, &tempMax);

		current = tempCurr;
		maximum = tempMax;

		return ret;
	}

	
}