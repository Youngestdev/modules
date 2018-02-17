
/* 
    Copyright (c) 2018 Azeez Adewale <azeezadewale98@gmail.com"> 
    MIT License Copyright (c) 2018 simple 

*/

/* 
 * File:   consoler.h
 * Author: thecarisma
 *
 * Created on February 11, 2018, 12:26 AM
 */

#include "../../../simple/bootsrc/includes/simple.h"
#include "console-colors.h"
#include "consoler.h"
#include "toot.h"

SIMPLE_API __declspec(dllexport)

SIMPLE_API void init_simple_module(SimpleState *sState)
{   
    register_block("__printwfb",print_with_foreground_background);
    register_block("__beep",console_beep);
}

void print_with_foreground_background ( void *pointer )
{
	if ( SIMPLE_API_PARACOUNT != 3 ) {
		SIMPLE_API_ERROR(SIMPLE_API_MISS3PARA);
		return ;
	}
	SIMPLE_API_IGNORECPOINTERTYPE ;
	if ( ! SIMPLE_API_ISNUMBER(1) && ! SIMPLE_API_ISNUMBER(2) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	if ( ! SIMPLE_API_ISSTRING(3) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	cc_fprintf(((int ) SIMPLE_API_GETNUMBER(1) << 0 ) | ((int ) SIMPLE_API_GETNUMBER(2) << CC_COLOR_BITS ), stdout, SIMPLE_API_GETSTRING(3));
}

void console_beep ( void *pointer )
{
    if ( SIMPLE_API_PARACOUNT != 2 ) {
        SIMPLE_API_ERROR(SIMPLE_API_MISS3PARA);
        return ;
    }
    SIMPLE_API_IGNORECPOINTERTYPE ;
    if ( ! SIMPLE_API_ISNUMBER(1) && ! SIMPLE_API_ISNUMBER(2) ) {
        SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
        return ;
    }
    #ifdef _WIN32
	int lFd;
	HANDLE lHStdOut;
        
        if ( !GetConsoleWindow() && AttachConsole(ATTACH_PARENT_PROCESS) )
        {
            lHStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            lFd = _open_osfhandle((intptr_t)lHStdOut, _O_TEXT);
            if (lFd > 0) *stdout = *_fdopen(lFd, "w");
            printf("\n");
        }
    #endif
    toot( SIMPLE_API_ISNUMBER(1) , SIMPLE_API_ISNUMBER(2) ) ;
}