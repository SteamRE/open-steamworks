#pragma once

#include "SteamclientAPI.h"

#include "Macros.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;
using namespace System::Runtime::InteropServices;


namespace dotnetworks
{

	public ref class SteamRemoteStorage001
	{
	internal:
		SteamRemoteStorage001( void *steamRemoteStorage )
		{
			base = (ISteamRemoteStorage001 *)steamRemoteStorage;
		}

	public:
		bool FileWrite( String ^psFile, array<Byte>^ pvData, int32 cubData )
		{
			STR_FROM_MANAGED(psFile, str);
			ARRAY_TO_PTR(pvData, mem, cubData );

			bool ret = base->FileWrite( str, mem, cubData );

			STR_FREE(str);
			ARRAY_FREE(mem);

			return ret;
		}

		bool FileRead( String^ filename, array<Byte>^ buffer, int size )
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

		bool FileExists( String^ psFile )
		{
			STR_FROM_MANAGED(psFile, str);

			bool ret = base->FileExists( str );

			STR_FREE(str);
			return ret;
		}

		bool FileDelete( String^ psFile )
		{
			STR_FROM_MANAGED(psFile, str);

			bool ret = base->FileDelete( str );

			STR_FREE(str);
			return ret;
		}

		uint32 GetFileCount()
		{
			return base->GetFileCount();
		}

		String^ GetFileNameAndSize(int index, [Out] int% size)
		{
			int tempSize;

			String^ ret = gcnew String( base->GetFileNameAndSize(index, &tempSize) );

			size = tempSize;
			return ret;
		}

		bool GetQuota([Out] int% current, [Out] int% maximum)
		{
			int tempCurr, tempMax;

			bool ret = base->GetQuota(&tempCurr, &tempMax);

			current = tempCurr;
			maximum = tempMax;

			return ret;
		}

		literal String^ InterfaceVersion = STEAMREMOTESTORAGE_INTERFACE_VERSION_001;

	private:
		ISteamRemoteStorage001 *base;
	};
}