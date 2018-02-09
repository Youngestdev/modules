
/* 
    Copyright (c) 2016-2018 Azeez Adewale <azeezadewale98@gmail.com"> 
    MIT License Copyright (c) 2017 simple 

*/

/* 
 * File:   file_savant.c
 * Author: thecarisma
 *
 * Created on February 9, 2018, 9:01 PM
 */

#include "../../../simple/bootsrc/includes/simple.h"
#include "file_savant.h"

SIMPLE_API __declspec(dllexport)

SIMPLE_API void init_simple_module(SimpleState *sState)
{   
    register_block("sin",math_sin);
    register_block("cos",math_cos);
    register_block("an",math_tan);
    register_block("asin",math_asin);
    register_block("acos",math_acos);
    register_block("atan",math_atan);
    register_block("atan2",math_atan2);
    register_block("sinh",math_sinh);
    register_block("cosh",math_cosh);
    register_block("tanh",math_tanh);
    register_block("exp",math_exp);
    register_block("log",math_log);
    register_block("log10",math_log10);
    register_block("ceil",math_ceil);
    register_block("floor",math_floor);
    register_block("fabs",math_fabs);
    register_block("pow",math_pow);
    register_block("sqrt",math_sqrt);
    register_block("unsigned",math_unsigned);
    register_block("decimals",math_decimals);
}

