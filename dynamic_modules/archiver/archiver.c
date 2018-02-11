
/* 
    Copyright (c) 2016-2018 Azeez Adewale <azeezadewale98@gmail.com"> 
    MIT License Copyright (c) 2018 simple 

*/

/* 
 * File:   archiver.c
 * Author: thecarisma
 *
 * Created on February 11, 2018, 3:27 PM
 */

#include "../../../simple/bootsrc/includes/simple.h"
#include "zip.h"
#include "archiver.h"

SIMPLE_API __declspec(dllexport)

SIMPLE_API void init_simple_module(SimpleState *sState)
{   
    register_block("__open_zip",open_zip_file);
}

ZIP_T *zip_openfile(const char *cFile, const char *cMode) {
    return zip_open(cFile, ZIP_DEFAULT_COMPRESSION_LEVEL, cMode[0]);
}

void open_zip_file ( void *pointer )
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(SIMPLE_API_MISS2PARA);
		return ;
	}
	SIMPLE_API_IGNORECPOINTERTYPE ;
	if ( ! SIMPLE_API_ISSTRING(1) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	if ( ! SIMPLE_API_ISSTRING(2) ) {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
		return ;
	}
	SIMPLE_API_RETCPOINTER(zip_openfile(SIMPLE_API_GETSTRING(1),SIMPLE_API_GETSTRING(2)),"ZIP_T");
}

