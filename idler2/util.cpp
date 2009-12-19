#include "Common.h"

void _Sleep(unsigned int dwMilliseconds)
{
#ifdef _WIN32
	Sleep(dwMilliseconds);
#else
	usleep( dwMilliseconds * 1000 );
#endif
}

const char *HumanReadableIP(u_long ip)
{
	u_long addr = ntohl(ip);
	return inet_ntoa(*(struct in_addr *) &addr);
}

#ifdef _MSC_VER
#include <windows.h>
#include <dbghelp.h>
#pragma comment(lib, "dbghelp.lib")

LONG WINAPI mdmpfilter(_EXCEPTION_POINTERS *exc_ptr)
{
  static const char *minidumpFilename = "idler2.mdmp";
  HANDLE hDumpFile = CreateFile(minidumpFilename, GENERIC_WRITE, 0, NULL,
    CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

  if (hDumpFile != INVALID_HANDLE_VALUE) {
   __try {
      MINIDUMP_EXCEPTION_INFORMATION exceptionInfo;
      exceptionInfo.ThreadId = GetCurrentThreadId();
      exceptionInfo.ExceptionPointers = exc_ptr;
      exceptionInfo.ClientPointers = false;

      BOOL ret = MiniDumpWriteDump(GetCurrentProcess(),
        GetCurrentProcessId(), hDumpFile, MiniDumpNormal, &exceptionInfo, NULL, NULL);

      if (ret)
		  std::cerr << "Crash! Minidump information has been written to " << minidumpFilename << std::endl;

    } __except(EXCEPTION_EXECUTE_HANDLER) { }
    CloseHandle(hDumpFile);
  }

  return EXCEPTION_CONTINUE_SEARCH;
}
#endif

void PrintData(unsigned char *data, int len)
{	
	for (int i = 0; i < len; i++)
	{
		unsigned char value = data[i];

		std::cout << std::hex << std::setw(2) << std::setfill('0') << std::uppercase << (unsigned int)value;
		std::cout << " ";
	}

	std::cout << std::resetiosflags(std::ios_base::hex | std::ios_base::uppercase) << std::endl;	
}

void DumpItems(unsigned char *data)
{
	GC_ItemsList *ilist = (GC_ItemsList *)data;
	std::cout << ilist->id << " " << ilist->steamid << " " << ilist->itemcount << std::endl;

	void *ptr = ((unsigned char *)(ilist) + sizeof(GC_ItemsList));
	for(int i = 0; i < ilist->itemcount; i++)
	{
		GC_ItemsList_Item *item = (GC_ItemsList_Item *)ptr;
		std::cout << "Item " << i << " " << item->accountid << " " << item->itemdefindex << " " << item->itemid << std::endl;

		ptr = ((unsigned char *)ptr + sizeof(GC_ItemsList_Item));

		for(int x = 0; x < item->attribcount; x++)
		{
			GC_ItemsList_Item_Attrib *itattr = (GC_ItemsList_Item_Attrib *)ptr;
			std::cout << "Attrib " << x << " " << itattr->attribindex << " = " << itattr->value << std::endl;
			ptr = ((unsigned char *)ptr + sizeof(GC_ItemsList_Item_Attrib));
		}
		
	}
}