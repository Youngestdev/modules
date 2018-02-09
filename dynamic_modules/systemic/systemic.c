
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

#ifdef _WIN32
#include "windows.h"
typedef int (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL); ;
LPFN_ISWOW64PROCESS isWindows64  ;
#endif

#include "../../../simple/bootsrc/includes/simple.h"
#include "systemic.h"

SIMPLE_API __declspec(dllexport)
        
SIMPLE_API void init_simple_module(SimpleState *sState)
{   
    register_block("isMsDos",os_ismsdos);
    register_block("isWindows",os_iswindows);
    register_block("isWindows64",os_iswindows64);
    register_block("isUnix",os_isunix);
    register_block("isMacosx",os_ismacosx);
    register_block("isLinux",os_islinux);
    register_block("isFreebsd",os_isfreebsd);
    register_block("isAndroid",os_isandroid);
    register_block("windowsnl",os_windowsnl);
    register_block("currentDir",os_currentdir);
    register_block("exefilename",os_exefilename);
    register_block("changeDir",os_chdir);
    register_block("exeFolder",os_exefolder);
    register_block("getSystemEnvironment",simple_vmlib_get);
}

void os_ismsdos ( void *pPointer )
{
	#if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
	SIMPLE_API_RETNUMBER(1);
	#else
	SIMPLE_API_RETNUMBER(0);
	#endif
}

void os_iswindows ( void *pPointer )
{
	#ifdef _WIN32
	SIMPLE_API_RETNUMBER(1);
	#else
	SIMPLE_API_RETNUMBER(0);
	#endif
}

void os_iswindows64 ( void *pPointer )
{
	int lSystem64  ;
	lSystem64 = 0 ;
	#ifdef _WIN32
	isWindows64 = (LPFN_ISWOW64PROCESS) GetProcAddress(GetModuleHandle(TEXT("kernel32")),"IsWow64Process") ;
	if ( isWindows64 != NULL ) {
		isWindows64(GetCurrentProcess(),&lSystem64);
	}
	#endif
	SIMPLE_API_RETNUMBER(lSystem64);
}

void os_isunix ( void *pPointer )
{
	#if defined(unix) || defined(__unix__) || defined(__unix)
	SIMPLE_API_RETNUMBER(1);
	#else
	SIMPLE_API_RETNUMBER(0);
	#endif
}

void os_ismacosx ( void *pPointer )
{
	#if defined(__APPLE__)  || defined(__MACH__)
	SIMPLE_API_RETNUMBER(1);
	#else
	SIMPLE_API_RETNUMBER(0);
	#endif
}

void os_islinux ( void *pPointer )
{
	#ifdef __linux__
	SIMPLE_API_RETNUMBER(1);
	#else
	SIMPLE_API_RETNUMBER(0);
	#endif
}

void os_isfreebsd ( void *pPointer )
{
	#ifdef __FreeBSD__
	SIMPLE_API_RETNUMBER(1);
	#else
	SIMPLE_API_RETNUMBER(0);
	#endif
}

void os_isandroid ( void *pPointer )
{
	#ifdef __ANDROID__
	SIMPLE_API_RETNUMBER(1);
	#else
	SIMPLE_API_RETNUMBER(0);
	#endif
}

void os_windowsnl ( void *pPointer )
{
	SIMPLE_API_RETSTRING("\r\n");
}

void os_currentdir ( void *pPointer )
{
	char cDirPath[SIMPLE_PATHSIZE]  ;
	simple_currentdir(cDirPath);
	SIMPLE_API_RETSTRING(cDirPath);
}

void os_exefilename ( void *pPointer )
{
	char cDirPath[SIMPLE_PATHSIZE]  ;
	if ( simple_exefilename(cDirPath) ) {
		SIMPLE_API_RETSTRING(cDirPath);
	}
}

void os_chdir ( void *pPointer )
{
	SIMPLE_API_RETNUMBER(simple_chdir(SIMPLE_API_GETSTRING(1)));
}

void os_exefolder ( void *pPointer )
{
	char cDirPath[SIMPLE_PATHSIZE]  ;
	simple_exefolder(cDirPath);
	SIMPLE_API_RETSTRING(cDirPath);
}

void simple_vmlib_get ( void *pointer )
{
	char *pData  ;
	if ( SIMPLE_API_PARACOUNT != 1 ) {
		SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
		return ;
	}
	if ( SIMPLE_API_ISSTRING(1) ) {
		pData = getenv(SIMPLE_API_GETSTRING(1));
		if ( pData != NULL ) {
			SIMPLE_API_RETSTRING(pData);
		} else {
			SIMPLE_API_RETSTRING("");
		}
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}