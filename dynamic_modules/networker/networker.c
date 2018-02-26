
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
    register_block("__curl_easy_init",curl_init);
    register_block("__curl_easy_perform",curl_perform);
    register_block("__curl_easy_cleanup",curl_cleanup);
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

void curl_perform ( void *pointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
        SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
        return ;
    }
    SIMPLE_API_IGNORECPOINTERTYPE ;
    if ( SIMPLE_API_ISPOINTER(1) ) {
        CURLcode *curl_code ; 
        curl_code = (CURLcode *) simple_state_malloc(((VM *) pointer)->sState,sizeof(CURLcode)) ;
        *curl_code = curl_easy_perform((CURL *) SIMPLE_API_GETCPOINTER(1,"SIMPLE_CURL"));
        SIMPLE_API_RETCPOINTER(curl_code,"SIMPLE_CURL_CODE");    
    } else {
        SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
        return ;
    }
}

void curl_cleanup ( void *pointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
        SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
        return ;
    }
    SIMPLE_API_IGNORECPOINTERTYPE ;
    if ( SIMPLE_API_ISPOINTER(1) ) {
        curl_easy_cleanup((CURL *) SIMPLE_API_GETCPOINTER(1,"SIMPLE_CURL_CODE"));
    } else {
        SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
        return ;
    }
}