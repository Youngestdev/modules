
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
    register_block("ismsdos",simple_vm_os_ismsdos);
    register_block("iswindows",simple_vm_os_iswindows);
    register_block("iswindows64",simple_vm_os_iswindows64);
    register_block("isunix",simple_vm_os_isunix);
    register_block("ismacosx",simple_vm_os_ismacosx);
    register_block("islinux",simple_vm_os_islinux);
    register_block("isfreebsd",simple_vm_os_isfreebsd);
    register_block("isandroid",simple_vm_os_isandroid);
    register_block("windowsnl",simple_vm_os_windowsnl);
    register_block("currentdir",simple_vm_os_currentdir);
    register_block("exefilename",simple_vm_os_exefilename);
    register_block("chdir",simple_vm_os_chdir);
    register_block("exefolder",simple_vm_os_exefolder);
}