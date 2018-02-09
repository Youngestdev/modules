
/* 
    Copyright (c) 2016-2018 Azeez Adewale <azeezadewale98@gmail.com"> 
    MIT License Copyright (c) 2018 simple 

*/

/* 
 * File:   systemic.c
 * Author: thecarisma
 *
 * Created on February 9, 2018, 10:05 PM
 */

#include "../../../simple/bootsrc/includes/simple.h"
#include "systemic.h"

SIMPLE_API __declspec(dllexport)
        
SIMPLE_API void init_simple_module(SimpleState *sState)
{   
    register_block("sin",math_sin);
    
}