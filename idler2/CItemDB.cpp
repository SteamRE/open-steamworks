#include "CItemDB.h"

typedef boost::unordered_map<uint16, std::string> ItemLookupMap;

ItemLookupMap itemMap;

bool CItemDB::LoadDB()
{
	std::fstream db("item.db", std::ios::binary | std::ios::in);

	uint16 items = 0;
	db.read((char *)&items, sizeof(items));

	if(items == 0)
	{
		std::cerr << "Unable to load DB, empty!" << std::endl;
		return false;
	}

	for(int i = 0; i < items; i++)
	{
		uint16 index;
		uint8 len;
		char buff[ITEM_MAXNAMELEN] = {0};

		db.read((char *)&index, sizeof(index));
		db.read((char *)&len, sizeof(len));
		db.read((char *)&buff, len);
		itemMap.insert( ItemLookupMap::value_type(index, buff) );
	}

	return true;
}

void CItemDB::DumpDB()
{
	for(ItemLookupMap::const_iterator iter = itemMap.begin(); iter != itemMap.end(); ++iter)
	{
		std::cout << (iter->first) << ": " << (iter->second) << std::endl;
	}
}

std::string CItemDB::GetItemName(uint16 id)
{
	ItemLookupMap::const_iterator iter = itemMap.find( id );
	if(iter != itemMap.end())
	{
		return iter->second;
	}

	return "UNKNOWN ITEM";
}

uint16 CItemDB::ItemCount()
{
	return itemMap.size();
}
