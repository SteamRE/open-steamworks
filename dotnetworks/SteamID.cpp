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
		SteamID( CSteamID id )
		{
			if ( base )
				delete base;

			base = new CSteamID( id.ConvertToUint64() );
		}

	public:
		~SteamID() { this->!SteamID(); }
		!SteamID()
		{
			if ( base )
				delete base;
		}

		SteamID() : base( new CSteamID() ) {}
		SteamID(UInt32 unAccountID, Universe eUniverse, AccountType eAccountType)
		{
			base = new CSteamID(unAccountID, (EUniverse)eUniverse, (EAccountType)eAccountType);
		}
		SteamID(UInt32 unAccountID, UInt32 unAccountInstance, Universe eUniverse, AccountType eAccountType)
		{
			base = new CSteamID(unAccountID, unAccountInstance, (EUniverse)eUniverse, (EAccountType)eAccountType);
		}
		SteamID(UInt64 ulSteamID) : base( new CSteamID(ulSteamID) ) {}

		void Set(UInt32 unAccountID, Universe eUniverse, AccountType eAccountType)
		{
			base->Set(unAccountID, (EUniverse)eUniverse, (EAccountType)eAccountType);
		}
		void InstancedSet(UInt32 unAccountID, UInt32 unInstance, Universe eUniverse, AccountType eAccountType)
		{
			base->InstancedSet(unAccountID, unInstance, (EUniverse)eUniverse, (EAccountType)eAccountType);
		}
		void FullSet(UInt64 ulIdentifier, Universe eUniverse, AccountType eAccountType)
		{
			base->FullSet(ulIdentifier, (EUniverse)eUniverse, (EAccountType)eAccountType);
		}

		void SetFromUint64(UInt64 ulSteamID)
		{
			base->SetFromUint64(ulSteamID);
		}

		UInt64 ConvertToUint64()
		{
			return base->ConvertToUint64();
		}

		UInt64 GetStaticAccountKey()
		{
			return base->GetStaticAccountKey();
		}

		void CreateBlankAnonLogon(Universe eUniverse)
		{
			base->CreateBlankAnonLogon((EUniverse)eUniverse);
		}

		bool BBlankAnonAccount()
		{
			return base->BBlankAnonAccount();
		}

		bool BGameServerAccount()
		{
			return base->BGameServerAccount();
		}

		bool BContentServerAccount() { return base->BContentServerAccount(); }
		bool BClanAccount() { return base->BClanAccount(); }
		bool BChatAccount() { return base->BChatAccount(); }
		bool BIndividualAccount() { return base->BIndividualAccount(); }

		void SetAccountID(UInt32 unAccountID) { base->SetAccountID(unAccountID); }
		UInt32 GetAccountID() { return base->GetAccountID(); }
		UInt32 GetUnAccountInstance() { return base->GetUnAccountInstance(); }
		AccountType GetEAccountType() { return (AccountType)base->GetEAccountType(); }
		Universe GetEUniverse() { return (Universe)base->GetEUniverse(); }
		void SetEUniverse(Universe eUniverse) { base->SetEUniverse((EUniverse)eUniverse); }
		bool IsValid() { return base->IsValid(); }

		String^ Render()
		{
			return gcnew String( base->Render() );
		}

		static bool operator == (SteamID^ lhs, SteamID^ rhs)
		{
			return *(lhs->base) == *(rhs->base);
		}

		static bool operator != (SteamID^ lhs, SteamID^ rhs)
		{
			return *(lhs->base) != *(rhs->base);
		}

		static bool operator < (SteamID^ lhs, SteamID^ rhs)
		{
			return *(lhs->base) < *(rhs->base);
		}
		static bool operator > (SteamID^ lhs, SteamID^ rhs)
		{
			return *(lhs->base) > *(rhs->base);
		}

	internal:
		CSteamID* base;
	};
}
