
/* 
    Copyright (c) 2016-2018 Azeez Adewale <azeezadewale98@gmail.com"> 
    MIT License Copyright (c) 2018 simple 

*/

/* 
 * File:   parser.c
 * Author: Azeez Adewale
 *
 * Created on February 26, 2018, 6:53 PM
 */

#include "../../../simple/bootsrc/includes/simple.h"
#include "parser.h"
#include <stdint.h>
#include "includes/json.h"

SIMPLE_API __declspec(dllexport)

SIMPLE_API void init_simple_module(SimpleState *sState)
{   
    register_block("__test_json_c",test_json_c);
    register_block("__init_json_c",init_json_c);
}

void print_hex( const char* s) 
{
        const char *iter = s;
        unsigned char ch;
        while ((ch = *iter++) != 0) {
           if( ',' != ch)
            printf("%x ", ch);
           else
            printf( ",");
        }
        printf("\n");
}

void test_json_c ( void *pointer )
{
    const char *input = "\"\\ud840\\udd26,\\ud840\\udd27,\\ud800\\udd26,\\ud800\\udd27\"";
    const char *expected = "\xF0\xA0\x84\xA6,\xF0\xA0\x84\xA7,\xF0\x90\x84\xA6,\xF0\x90\x84\xA7";
    struct json_object *parse_result = json_tokener_parse((char*)input);
    const char *unjson = json_object_get_string(parse_result);

    printf("input: %s\n", input);

    int strings_match = !strcmp( expected, unjson);
	int retval = 0;
    if (strings_match) {
        printf("JSON parse result is correct: %s\n", unjson);
        printf("PASS\n");
    } else {
        printf("JSON parse result doesn't match expected string\n");
        printf("expected string bytes: ");
        print_hex( expected);
        printf("parsed string bytes:   ");
        print_hex( unjson);
        printf("FAIL\n");
        retval = 1;
    }
	json_object_put(parse_result);
	//return retval;
}

void init_json_c ( void *pointer )
{
    if ( SIMPLE_API_PARACOUNT != 1 ) {
        SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
        return ;
    }
    if ( SIMPLE_API_ISSTRING(1) ) {
        SIMPLE_API_RETNUMBER(sin(SIMPLE_API_GETNUMBER(1)));
    } else {
        SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
    }
}