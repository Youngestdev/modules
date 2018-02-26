
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
    if ( SIMPLE_API_PARACOUNT != 0 ) {
            SIMPLE_API_ERROR(SIMPLE_API_BADPARACOUNT);
            return ;
    }
    SIMPLE_API_IGNORECPOINTERTYPE ;
    SIMPLE_API_RETCPOINTER(curl_easy_init(),"SIMPLE_CURL");
}