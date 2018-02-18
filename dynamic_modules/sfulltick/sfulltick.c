/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sfulltick.c
 * Author: thecarisma
 *
 * Created on February 18, 2018, 12:51 AM
 */

#include "../../../simple/bootsrc/includes/simple.h"

/*
 * 
 */

SIMPLE_API __declspec(dllexport)

SIMPLE_API void init_simple_module(SimpleState *sState)
{   
    register_block("__testfulltick",test_fulltick);
}

void test_fulltick ( void *pointer )
{
    
}