
/* 
    Copyright (c) 2016-2018 Azeez Adewale <azeezadewale98@gmail.com"> 
    MIT License Copyright (c) 2018 simple 

*/

/* 
 * File:   security.c
 * Author: thecarisma
 *
 * Created on February 18, 2018, 11:48 AM
 */

#include "../../../simple/bootsrc/includes/simple.h"
#include "./openssl/md5.h"
#include "security.h"

SIMPLE_API __declspec(dllexport)

SIMPLE_API void init_simple_module(SimpleState *sState)
{
    register_block("md5",lib_md5);
}

void lib_md5 ( void *pPointer )
{
	unsigned char digest[MD5_DIGEST_LENGTH]  ;
	char string[33]  ;
	int x,nSize  ;
	char *cInput  ;
	if ( SIMPLE_API_PARACOUNT != 1 ) {
		SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
		return ;
	}
	if ( SIMPLE_API_ISSTRING(1) ) {
		cInput = SIMPLE_API_GETSTRING(1) ;
		nSize = SIMPLE_API_GETSTRINGSIZE(1) ;
		MD5((unsigned char *) cInput, nSize, (unsigned char *) &digest);
		for ( x = 0 ; x < 16 ; x++ ) {
			sprintf( &string[x*2] , "%02x" , (unsigned int) digest[x] ) ;
		}
		SIMPLE_API_RETSTRING(string);
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}