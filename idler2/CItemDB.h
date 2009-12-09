#ifndef CITEMDB_H
#define CITEMDB_H

#include "Common.h"

class CItemDB
{
public:
	static bool LoadDB();
	static void DumpDB();
	static std::string GetItemName(uint16 id);
	static uint16 ItemCount();
};

#endif
