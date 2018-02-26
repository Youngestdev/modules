
/* 
    Copyright (c) 2016-2018 Azeez Adewale <azeezadewale98@gmail.com"> 
    MIT License Copyright (c) 2018 simple 

*/

/* 
 * File:   networker.h
 * Author: thecarisma
 *
 * Created on February 12, 2018, 2:17 AM
 */

#ifndef NETWORKER_H
#define NETWORKER_H

#ifdef __cplusplus
extern "C" {
#endif
    
SIMPLE_API void init_simple_module(SimpleState *sState) ;

void curl_init ( void *pointer ) ;


#ifdef __cplusplus
}
#endif

#endif /* NETWORKER_H */

