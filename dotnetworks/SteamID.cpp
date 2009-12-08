
#include "SteamID.h"

namespace dotnetworks
{

	SteamID::SteamID( CSteamID id )
	{
		if (base)
			delete base;

		base = new CSteamID(id.ConvertToUint64());
	}

	SteamID::~SteamID() { this->!SteamID(); }
	SteamID::!SteamID()
	{
		if (base)
			delete base;
	}

	SteamID::SteamID() : base( new CSteamID() ) {}
	SteamID::SteamID(UInt32 unAccountID, Universe eUniverse, AccountType eAccountType)
	{
		base = new CSteamID(unAccountID, (EUniverse)eUniverse, (EAccountType)eAccountType);
	}
	SteamID::SteamID(UInt32 unAccountID, UInt32 unAccountInstance, Universe eUniverse, AccountType eAccountType)
	{
		base = new CSteamID(unAccountID, unAccountInstance, (EUniverse)eUniverse, (EAccountType)eAccountType);
	}
	SteamID::SteamID(UInt64 ulSteamID) : base( new CSteamID(ulSteamID) ) {}

	void SteamID::Set(UInt32 unAccountID, Universe eUniverse, AccountType eAccountType)
	{
		base->Set(unAccountID, (EUniverse)eUniverse, (EAccountType)eAccountType);
	}
	void SteamID::InstancedSet(UInt32 unAccountID, UInt32 unInstance, Universe eUniverse, AccountType eAccountType)
	{
		base->InstancedSet(unAccountID, unInstance, (EUniverse)eUniverse, (EAccountType)eAccountType);
	}
	void SteamID::FullSet(UInt64 ulIdentifier, Universe eUniverse, AccountType eAccountType)
	{
		base->FullSet(ulIdentifier, (EUniverse)eUniverse, (EAccountType)eAccountType);
	}

	void SteamID::SetFromUint64(UInt64 ulSteamID)
	{
		base->SetFromUint64(ulSteamID);
	}

	UInt64 SteamID::ConvertToUint64()
	{
		return base->ConvertToUint64();
	}

	UInt64 SteamID::GetStaticAccountKey()
	{
		return base->GetStaticAccountKey();
	}

	void SteamID::CreateBlankAnonLogon(Universe eUniverse)
	{
		base->CreateBlankAnonLogon((EUniverse)eUniverse);
	}

	bool SteamID::BBlankAnonAccount()
	{
		return base->BBlankAnonAccount();
	}

	bool SteamID::BGameServerAccount()
	{
		return base->BGameServerAccount();
	}

	bool SteamID::BContentServerAccount() { return base->BContentServerAccount(); }
	bool SteamID::BClanAccount() { return base->BClanAccount(); }
	bool SteamID::BChatAccount() { return base->BChatAccount(); }
	bool SteamID::BIndividualAccount() { return base->BIndividualAccount(); }

	void SteamID::SetAccountID(UInt32 unAccountID) { base->SetAccountID(unAccountID); }
	UInt32 SteamID::GetAccountID() { return base->GetAccountID(); }
	UInt32 SteamID::GetUnAccountInstance() { return base->GetUnAccountInstance(); }
	AccountType SteamID::GetEAccountType() { return (AccountType)base->GetEAccountType(); }
	Universe SteamID::GetEUniverse() { return (Universe)base->GetEUniverse(); }
	void SteamID::SetEUniverse(Universe eUniverse) { base->SetEUniverse((EUniverse)eUniverse); }
	bool SteamID::IsValid() { return base->IsValid(); }

	String^ SteamID::Render()
	{
		return gcnew String( base->Render() );
	}

	bool SteamID::operator == (SteamID^ lhs, SteamID^ rhs)
	{
		return *(lhs->base) == *(rhs->base);
	}
	
	bool SteamID::operator != (SteamID^ lhs, SteamID^ rhs)
	{
		return *(lhs->base) != *(rhs->base);
	}

	bool SteamID::operator < (SteamID^ lhs, SteamID^ rhs)
	{
		return *(lhs->base) < *(rhs->base);
	}
	bool SteamID::operator > (SteamID^ lhs, SteamID^ rhs)
	{
		return *(lhs->base) > *(rhs->base);
	}
}