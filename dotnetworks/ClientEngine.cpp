
#include "ClientEngine.h"

namespace dotnetworks
{
	ClientEngine::ClientEngine( IClientEngine *clientEngine )
	{
		base = clientEngine;
	}

	DEFINE_GET_UTIL_FUNC( ClientEngine, ClientUtils );



	BEGIN_GET_INTERFACE( ClientEngine )
	{
		RETURN_INTERFACE( ClientUtils, CLIENTUTILS_INTERFACE_VERSION );
	}
	END_GET_INTERFACE()
}