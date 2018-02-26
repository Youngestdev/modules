
/* 
    Copyright (c) 2016-2018 Azeez Adewale <azeezadewale98@gmail.com"> 
    MIT License Copyright (c) 2018 simple 

*/

/* 
 * File:   parser.h
 * Author: thecarisma
 *
 * Created on February 26, 2018, 6:55 PM
 */

#ifndef PARSER_H
#define PARSER_H

#ifdef __cplusplus
extern "C" {
#endif
    
SIMPLE_API void init_simple_module(SimpleState *sState) ;

void print_hex( const char* s) ;
void test_json_c ( void *pointer ) ;
void init_json_c ( void *pointer ) ;
void json_object_get_type ( void *pointer ) ;
void json_c_type_to_name ( void *pointer ) ;


#ifdef __cplusplus
}
#endif

#endif /* PARSER_H */

