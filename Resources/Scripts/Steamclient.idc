/*
	Steamclient interfaces finder.
	By LazyDidrole
	
	License : Public domain.
*/

#include <idc.idc>

extern iArray;

static main()
{
	iArray = CreateArray("Id2Name");
	
	FindFunctionNames();
	FindFunctions();
	
	DeleteArray(iArray);
}

static DoesAnyJumpEndsHere( ea )
{
	auto xref;
	auto type;

	for ( xref = RfirstB( ea ); xref != BADADDR; xref = RnextB( ea, xref ) )
	{
		type = XrefType();
		if( type == fl_JF || type == fl_JN )
			return 1;
	}
	
	return 0;
}

static FindFunctionNames()
{
	auto ea;
	auto xref;
	auto i;

	auto InterfaceName;
	auto FunctionName;
	auto IPC_ID;
	auto DoneOnce;
	
	if( ( ea = FindBinary( 0, SEARCH_DOWN+SEARCH_NOSHOW, "55 8b ec 81 ec ? ? ? ? 83 3d ? ? ? ? ? 0f 84 ? ? ? ? 56 57 ff 15 ? ? ? ? 80 3d ? ? ? ? ? a3 ? ? ? ? 0f 84 ? ? ? ? 53 68 ? ? ? ? 8d bd 7c fe ff ff 8b c7 68 ? ? ? ? 50 ff 15 ? ? ? ? 8b 1d ? ? ? ? 83 c4 0c c6 45 ff 00 eb ?" ) ) != BADADDR)
	{
		for ( xref = RfirstB( ea ); xref != BADADDR; xref = RnextB( ea, xref ) )
		{
			InterfaceName = "";
			FunctionName = "";
			IPC_ID = "";
			DoneOnce = 0;

			for ( i = xref; !DoesAnyJumpEndsHere(i + 1); i-- )
			{
				if ( GetMnem( i ) == "push" && GetOpType( i, 0 ) == 5 )
				{
					if(!DoneOnce)
					{
						InterfaceName = GetString( GetOperandValue( i, 0 ), -1, ASCSTR_C );
						DoneOnce = 1;
					}
					else
					{
						FunctionName = GetString( GetOperandValue( i, 0 ), -1, ASCSTR_C );
					}
				}
				else if( GetMnem( i ) == "cmp" )
				{
					IPC_ID = GetOperandValue( i, 1 );
					break;
				}
			}
			SetArrayString(iArray, long(IPC_ID), InterfaceName + "::" + FunctionName);
		}
	}
	else
	{
		Message("Unable to find PipeDebugStart\n");
	}
}

static FindFunctions()
{
	auto ea;
	auto xref;
	auto xref2;
	auto start;
	auto i;
	
	if( ( ea = FindBinary( 0, SEARCH_DOWN+SEARCH_NOSHOW, "55 8b ec 81 ec ? ? ? ? 53 56 57 8b f9 8d 5f 48 8b cb 89 5d e8 ff 15 ? ? ? ? 8b 45 14 8b 4d 10 50 51 68 ? ? ? ? 8d 95 40 ff ff ff 68 ? ? ? ? 52 ff 15 ? ? ? ? a1 ? ? ? ? 8b 08 83 c4 14 85 c9 75 ? 89 4d fc eb ?" ) ) != BADADDR )
	{
		for ( xref = RfirstB( ea ); xref != BADADDR; xref = RnextB( ea, xref ) )
		{
			start = GetFunctionAttr( xref, FUNCATTR_START );

			for ( i = xref; i >= start; i-- )
			{
				if( GetMnem( i ) == "mov" && GetOpType( i, 0 ) == 4 && GetOpType( i, 1 ) == 5 )
				{
					for ( xref2 = DfirstB( start ); xref2 != BADADDR; xref2 = DnextB( start, xref2 ) )
					{
						Message("%x: %u %s\n", xref2, GetOperandValue( i, 1 ), GetArrayElement(AR_STR, iArray, long(GetOperandValue( i, 1 ))));
						MakeComm( xref2, GetArrayElement(AR_STR, iArray, long(GetOperandValue( i, 1 ))) );
					}
					break;
				}
			}
		}
	}
	else
	{
		Message("Unable to find SendSerializedFunction\n");
	}
}