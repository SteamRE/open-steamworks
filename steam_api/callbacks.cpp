#include "stdafx.h"
#include "callbacks.h"

void CallbackManager::AddCallbackProvider(HMODULE module)
{
	CallbackProvider provider(module);
	
    ProviderVector::const_iterator iter = std::find(providers.begin(), providers.end(), provider);

	if(iter != providers.end())
		return;

	provider.ResolveExports();
	providers.push_back(provider);
}