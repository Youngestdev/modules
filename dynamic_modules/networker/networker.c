
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
    register_block("__curl_easy_setopt",curl_setopt);
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

void curl_setopt ( void *pointer )
{
    if ( SIMPLE_API_PARACOUNT != 4 ) {
        SIMPLE_API_ERROR(SIMPLE_API_MISS4PARA);
        return ;
    }
    SIMPLE_API_IGNORECPOINTERTYPE ;
    if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3)) {
        CURLcode *curl_code ; 
        curl_code = (CURLcode *) simple_state_malloc(((VM *) pointer)->sState,sizeof(CURLcode)) ;
        *curl_code = curl_easy_setopt((CURL *) SIMPLE_API_GETCPOINTER(1,"SIMPLE_CURL"), (CURLoption ) SIMPLE_API_GETNUMBER(2), (int) SIMPLE_API_GETNUMBER(3));
        SIMPLE_API_RETCPOINTER(curl_code,"SIMPLE_CURL_CODE");
    } else if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISSTRING(3)) {
        CURLcode *curl_code ; 
        curl_code = (CURLcode *) simple_state_malloc(((VM *) pointer)->sState,sizeof(CURLcode)) ;
        *curl_code = curl_easy_setopt((CURL *) SIMPLE_API_GETCPOINTER(1,"SIMPLE_CURL"), (CURLoption ) SIMPLE_API_GETNUMBER(2), SIMPLE_API_GETSTRING(3));
        SIMPLE_API_RETCPOINTER(curl_code,"SIMPLE_CURL_CODE");
    } else if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISPOINTER(3)) {
        CURLcode *curl_code ; 
        curl_code = (CURLcode *) simple_state_malloc(((VM *) pointer)->sState,sizeof(CURLcode)) ;
        *curl_code = curl_easy_setopt((CURL *) SIMPLE_API_GETCPOINTER(1,"SIMPLE_CURL"), (CURLoption ) SIMPLE_API_GETNUMBER(2), (void *) SIMPLE_API_GETCPOINTER(3,"void"));
        SIMPLE_API_RETCPOINTER(curl_code,"SIMPLE_CURL_CODE");
    } else if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISPOINTER(3) && SIMPLE_API_ISNUMBER(4) ) {
        CURLcode *curl_code ; 
        curl_code = (CURLcode *) simple_state_malloc(((VM *) pointer)->sState,sizeof(CURLcode)) ;
        *curl_code = curl_easy_setopt((CURL *) SIMPLE_API_GETCPOINTER(1,"SIMPLE_CURL"), (CURLoption ) SIMPLE_API_GETNUMBER(2), (CURLLIST *) SIMPLE_API_GETCPOINTER(3,"SIMPLE_CURL_LIST"));
        SIMPLE_API_RETCPOINTER(curl_code,"SIMPLE_CURL_CODE");
    } else {
        SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
        return ;
    }
}