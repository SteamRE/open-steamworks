/*
	Steam Delay Loader Generator
	By Didrole
	
	License : Public domain.
*/

#include <idc.idc>


static main()
{
	if(!(GetLongPrm(INF_LFLAGS) & LFLG_IS_DLL))
	{
		Warning("This script can only be used on dynamic libraries.\n");
		return;
	}
	
	if(GetLongPrm(INF_LFLAGS) & LFLG_64BIT)
	{
		Warning("This script can only be used on 32 bits binaries.\n");
		return;
	}
	
	auto bIsWin32	= 0;
	auto bIsOSX		= 0;
	auto bIsLinux	= 0;
	
	auto eFileType = GetLongPrm(INF_FILETYPE);
	if(eFileType == FT_PE)
	{
		bIsWin32 = 1;
	}
	else if(eFileType == FT_MACHO)
	{
		bIsOSX = 1;
	}
	else if(eFileType == FT_ELF)
	{
		bIsLinux = 1;
	}
	else
	{
		Warning("Unsupported file type.\n");
		return;
	}

	auto szFilename = GetInputFile();
	
	auto iIndex = 0;
	while(szFilename[iIndex] != '\0')
		iIndex++;
	while(szFilename[iIndex] != "." && iIndex >= 0)
		iIndex--;
	if(iIndex < 0)
	{
		Warning("Unable to split the filename from its extension\n");
		return;
	}
	
	auto szModuleName = substr(szFilename, 0, iIndex);
		
	auto szOutputFile = AskFile(1, szModuleName + ".s", "Select the output asm filename");
	auto hFile = fopen(szOutputFile, "wb");
	if(!hFile)
	{
		Warning("Failed to open %s\n", szOutputFile);
		return;
	}
	
	auto bPIC = 0;
	if(bIsOSX || bIsLinux)
		bPIC = AskYN(1, "Do you want to generate Position Independent Code ?\nIf you don\'t know what it is just press Yes.");
		
	auto szDataSection =	"\n.data\n\n"
								"szModulePath:\n"
								"	.ascii \"" + (bIsOSX ? "@loader_path/" : (bIsLinux ? "$ORIGIN/" : "") ) + szFilename + "\\0\"\n" +
								
								"h" + szModuleName + ":\n"
								"	.long 0\n";

	auto szTextSection =	"\n.text\n\n";
		
	auto cEntryPoints = GetEntryPointQty();
	
	auto i;
	for(i = 0; i < cEntryPoints; i++)
	{
		auto iOrdinal = GetEntryOrdinal(i);
		auto pFunction = GetEntryPoint(iOrdinal);
		auto szEntryName = GetEntryName(iOrdinal);
				
		if(strstr(szEntryName, "Steam") != bIsOSX ? 1 : 0)
			continue;
		
		if(bIsOSX || bIsLinux)
		{
			szDataSection = szDataSection +
					"sz" + szEntryName + ":\n"
					"	.ascii \"" + ((bIsOSX) ? substr(szEntryName, 1, -1) : szEntryName) + "\\0\"\n" +
					"p" + szEntryName + ":\n"
					"	.long 0\n";
									
			if(bPIC)
			{
				// PIC is such a mess D: This code can be optimised but I'm a noob in asm and most importantly I'm lazy
				szTextSection = szTextSection +
					".globl " + szEntryName + "\n"
					"	" + szEntryName + ":\n"
					"	call ." + szEntryName + "_PIC_Offset\n"
					"." + szEntryName + "_PIC_Offset:\n"
					"	pop %ecx\n"
					"	mov %ecx, %edx\n"
					"	add $p" + szEntryName + " - ." + szEntryName + "_PIC_Offset" + ", %edx\n"
					"	cmp $0, (%edx)\n"
					"	jz ." + szEntryName + "_Loader\n"
					"	jmp *(%edx)\n"
					"." + szEntryName + "_Loader:\n"
					"	push %ebx\n"
					"	mov %ecx, %ebx\n"
					"	push $1\n"
					"	add $szModulePath - ." + szEntryName + "_PIC_Offset, %ecx\n"
					"	push %ecx\n"
					"	call " + ((bIsOSX) ? "_" : "") + "dlopen\n"
					"	mov %ebx, %ecx\n"
					"	add $sz" + szEntryName + " - ." + szEntryName + "_PIC_Offset, %ecx\n"
					+ (bIsOSX ? "	sub $8, %esp\n" : "") + // OSX requires the stack to be 16 byte aligned at the point of function calls
					"	push %ecx\n"
					"	push %eax\n"
					"	call " + ((bIsOSX) ? "_" : "") + "dlsym\n"
					"	mov %ebx, %ecx\n"
					"	add $p" + szEntryName + " - ." + szEntryName + "_PIC_Offset, %ecx\n"
					"	mov %eax, (%ecx)\n"
					"	mov %eax, %ebx\n"
					"	call " + ((bIsOSX) ? "_" : "") + "dlclose\n"
					+ (bIsOSX ? "	add $24, %esp\n" : "	add $16, %esp\n") +
					"	mov %ebx, %eax\n"
					"	pop %ebx\n"
					"	jmp *%eax\n";
			}
			else
			{
				szTextSection = szTextSection +
					".globl " + szEntryName + "\n"
					"	" + szEntryName + ":\n"
					"	cmp $0, p" + szEntryName + "\n"
					"	jz ." + szEntryName + "_Loader\n"
					"	jmp *p" + szEntryName + "\n"
					"." + szEntryName + "_Loader:\n"
					+ (bIsOSX ? "	sub $4, %esp\n" : "") + // OSX requires the stack to be 16 byte aligned at the point of function calls
					"	push $1\n" // RTLD_LAZY
					"	push $szModulePath\n"
					"	call " + ((bIsOSX) ? "_" : "") + "dlopen\n"
					+ (bIsOSX ? "	sub $8, %esp\n" : "") + // OSX requires the stack to be 16 byte aligned at the point of function calls
					"	push $sz" + szEntryName + "\n"
					"	push %eax\n"
					"	call " + ((bIsOSX) ? "_" : "") + "dlsym\n"
					"	mov %eax, p" + szEntryName + "\n"
					"	call " + ((bIsOSX) ? "_" : "") + "dlclose\n"
					+ (bIsOSX ? "	add $28, %esp\n" : "	add $16, %esp\n") +
					"	jmp *p" + szEntryName + "\n";
			}
		}
		else // if(bIsWin32)
		{
			szDataSection = szDataSection +
					"sz" + szEntryName + ":\n"
					"	.string \"" + szEntryName + "\"\n" +
					
					".globl __imp__" + szEntryName + "\n"
					"__imp__" + szEntryName + ":\n"
					"	.long _" + szEntryName + "\n";
	
			szTextSection = szTextSection +
					".globl _" + szEntryName + "\n"
					"	_" + szEntryName + ":\n"
					"	push $szModulePath\n"
					"	call _GetModuleHandleA@4\n"
					"	push $sz" + szEntryName + "\n"
					"	push %eax\n"
					"	call _GetProcAddress@8\n"
					"	mov %eax, __imp__" + szEntryName + "\n"
					"	jmp *%eax\n";
		}
	}
	
	fprintf(hFile, "%s%s", szDataSection, szTextSection);
	
	fclose(hFile);
	
	if(bIsOSX || bIsLinux)
		Warning("File generated successfully\nRun \"gcc -c \"%s\" -o %s.o -m32;strip -x %s.o;ar rcs %s.a %s.o\" to build the lib.\n", szOutputFile, szModuleName, szModuleName, szModuleName, szModuleName);
	else if(bIsWin32)
		Warning("File generated successfully\nRun \"gcc -c \"%s\" -o %s.o -m32;strip -x %s.o;ar rcs %s.lib %s.o\" (on MinGW) to build the lib.\n", szOutputFile, szModuleName, szModuleName, szModuleName, szModuleName);
}