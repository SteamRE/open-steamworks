#pragma once

#include "SteamclientAPI.h"

#include "Universe.h"
#include "AccountType.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;


namespace dotnetworks
{
	public ref class SteamID
	{
	internal:
		SteamID( CSteamID id );

	public:
		~SteamID();
		!SteamID();

		SteamID();
		SteamID(UInt32 unAccountID, Universe eUniverse, AccountType eAccountType);
		SteamID(UInt32 unAccountID, UInt32 unAccountInstance, Universe eUniverse, AccountType eAccountType);
		SteamID(UInt64 ulSteamID);

		void Set(UInt32 unAccountID, Universe eUniverse, AccountType eAccountType);
		void InstancedSet(UInt32 unAccountID, UInt32 unInstance, Universe eUniverse, AccountType eAccountType);
		void FullSet(UInt64 ulIdentifier, Universe eUniverse, AccountType eAccountType);

		void SetFromUint64(UInt64 ulSteamID);

		UInt64 ConvertToUint64();

		UInt64 GetStaticAccountKey();

		void CreateBlankAnonLogon(Universe eUniverse);

		bool BBlankAnonAccount();

		bool BGameServerAccount();

		bool BContentServerAccount();
		bool BClanAccount();
		bool BChatAccount();
		bool BIndividualAccount();

		void SetAccountID(UInt32 unAccountID);
		UInt32 GetAccountID();
		UInt32 GetUnAccountInstance();
		AccountType GetEAccountType();
		Universe GetEUniverse();
		void SetEUniverse(Universe eUniverse);
		bool IsValid();

		String^ Render();

		static bool operator == (SteamID^ lhs, SteamID^ rhs);
		static bool operator != (SteamID^ lhs, SteamID^ rhs);

		static bool operator < (SteamID^ lhs, SteamID^ rhs);
		static bool operator > (SteamID^ lhs, SteamID^ rhs);

	internal:
		CSteamID* base;
	};
}
