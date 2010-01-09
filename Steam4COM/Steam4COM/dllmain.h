// dllmain.h : Declaration of module class.

class CSteam4COMModule : public CAtlDllModuleT< CSteam4COMModule >
{
public :
	DECLARE_LIBID(LIBID_Steam4COMLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_STEAM4COM, "{B5D80C1B-73D7-49EC-8656-2DEFC10F30C8}")
};

extern class CSteam4COMModule _AtlModule;
