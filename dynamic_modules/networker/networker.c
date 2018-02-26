
/* 
    Copyright (c) 2016-2018 Azeez Adewale <azeezadewale98@gmail.com"> 
    MIT License Copyright (c) 2018 simple 

*/

/* 
 * File:   networker.c
 * Author: thecarisma
 *
 * Created on February 12, 2018, 2:18 AM
 */

#include "../../../simple/bootsrc/includes/simple.h"
#include "curl/curl.h"
#include "networker.h"

SIMPLE_API __declspec(dllexport)

SIMPLE_API void init_simple_module(SimpleState *sState)
{   
    register_block("__curl_init",curl_init);
}

void curl_init ( void *pointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
            SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
            return ;
    }
    if ( SIMPLE_API_ISNUMBER(1) ) {
            SIMPLE_API_RETNUMBER(sin(SIMPLE_API_GETNUMBER(1)));
    } else {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}