
/* 
    Copyright (c) 2016-2018 Azeez Adewale <azeezadewale98@gmail.com"> 
    MIT License Copyright (c) 2018 simple 

*/

/* 
 * File:   systemic.c
 * Author: thecarisma
 *
 * Created on February 9, 2018, 10:05 PM
 */

#include "../../../simple/bootsrc/includes/simple.h"
#include "systemic.h"

SIMPLE_API __declspec(dllexport)
        
SIMPLE_API void init_simple_module(SimpleState *sState)
{   
    register_block("ismsdos",simple_vm_os_ismsdos);
    register_block("iswindows",simple_vm_os_iswindows);
    register_block("iswindows64",simple_vm_os_iswindows64);
    register_block("isunix",simple_vm_os_isunix);
    register_block("ismacosx",simple_vm_os_ismacosx);
    register_block("islinux",simple_vm_os_islinux);
    register_block("isfreebsd",simple_vm_os_isfreebsd);
    register_block("isandroid",simple_vm_os_isandroid);
    register_block("windowsnl",simple_vm_os_windowsnl);
    register_block("currentdir",simple_vm_os_currentdir);
    register_block("exefilename",simple_vm_os_exefilename);
    register_block("chdir",simple_vm_os_chdir);
    register_block("exefolder",simple_vm_os_exefolder);
}

void simple_vm_os_ismsdos ( void *pPointer )
{
	#if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
	SIMPLE_API_RETNUMBER(1);
	#else
	SIMPLE_API_RETNUMBER(0);
	#endif
}

void simple_vm_os_iswindows ( void *pPointer )
{
	#ifdef _WIN32
	SIMPLE_API_RETNUMBER(1);
	#else
	SIMPLE_API_RETNUMBER(0);
	#endif
}

void simple_vm_os_iswindows64 ( void *pPointer )
{
	int lSystem64  ;
	lSystem64 = 0 ;
	#ifdef _WIN32
	fnCheckWindows64 = (LPFN_ISWOW64PROCESS) GetProcAddress(GetModuleHandle(TEXT("kernel32")),"IsWow64Process") ;
	if ( fnCheckWindows64 != NULL ) {
		fnCheckWindows64(GetCurrentProcess(),&lSystem64);
	}
	#endif
	SIMPLE_API_RETNUMBER(lSystem64);
}

void simple_vm_os_isunix ( void *pPointer )
{
	#if defined(unix) || defined(__unix__) || defined(__unix)
	SIMPLE_API_RETNUMBER(1);
	#else
	SIMPLE_API_RETNUMBER(0);
	#endif
}

void simple_vm_os_ismacosx ( void *pPointer )
{
	#if defined(__APPLE__)  || defined(__MACH__)
	SIMPLE_API_RETNUMBER(1);
	#else
	SIMPLE_API_RETNUMBER(0);
	#endif
}

void simple_vm_os_islinux ( void *pPointer )
{
	#ifdef __linux__
	SIMPLE_API_RETNUMBER(1);
	#else
	SIMPLE_API_RETNUMBER(0);
	#endif
}

void simple_vm_os_isfreebsd ( void *pPointer )
{
	#ifdef __FreeBSD__
	SIMPLE_API_RETNUMBER(1);
	#else
	SIMPLE_API_RETNUMBER(0);
	#endif
}

void simple_vm_os_isandroid ( void *pPointer )
{
	#ifdef __ANDROID__
	SIMPLE_API_RETNUMBER(1);
	#else
	SIMPLE_API_RETNUMBER(0);
	#endif
}

void simple_vm_os_windowsnl ( void *pPointer )
{
	SIMPLE_API_RETSTRING("\r\n");
}

void simple_vm_os_currentdir ( void *pPointer )
{
	char cDirPath[SIMPLE_PATHSIZE]  ;
	simple_currentdir(cDirPath);
	SIMPLE_API_RETSTRING(cDirPath);
}

void simple_vm_os_exefilename ( void *pPointer )
{
	char cDirPath[SIMPLE_PATHSIZE]  ;
	if ( simple_exefilename(cDirPath) ) {
		SIMPLE_API_RETSTRING(cDirPath);
	}
}

void simple_vm_os_chdir ( void *pPointer )
{
	SIMPLE_API_RETNUMBER(simple_chdir(SIMPLE_API_GETSTRING(1)));
}

void simple_vm_os_exefolder ( void *pPointer )
{
	char cDirPath[SIMPLE_PATHSIZE]  ;
	simple_exefolder(cDirPath);
	SIMPLE_API_RETSTRING(cDirPath);
}

