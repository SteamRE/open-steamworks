#pragma once

#include "SteamclientAPI.h"


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
		SteamRemoteStorage001( void *steamRemoteStorage );

	public:
		bool FileWrite( String ^psFile, array<Byte>^ pvData, int32 cubData );

		bool FileRead( String^ filename, array<Byte>^ buffer, int size );

		bool FileExists( String^ psFile );

		bool FileDelete( String^ psFile );

		uint32 GetFileCount();

		String^ GetFileNameAndSize(int index, int% size);

		bool GetQuota(int% current, int% maximum);

		
	public:
		literal String^ InterfaceVersion = STEAMREMOTESTORAGE_INTERFACE_VERSION_001;

	private:
		ISteamRemoteStorage001 *base;
	};
}