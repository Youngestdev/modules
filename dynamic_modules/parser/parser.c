
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
#include "includes/json.h"

SIMPLE_API __declspec(dllexport)

SIMPLE_API void init_simple_module(SimpleState *sState)
{   
    register_block("__test_json_c",test_json_c);
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
	return retval;
}