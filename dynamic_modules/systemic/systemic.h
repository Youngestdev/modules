
/* 
    Copyright (c) 2016-2018 Azeez Adewale <azeezadewale98@gmail.com"> 
    MIT License Copyright (c) 2018 simple 

*/

/* 
 * File:   systemic.h
 * Author: thecarisma
 *
 * Created on February 9, 2018, 10:04 PM
 */

#ifndef SYSTEMIC_H
#define SYSTEMIC_H

#ifdef __cplusplus
extern "C" {
#endif

void init_simple_module ( SimpleState *pSimpleState ) ;

void os_ismsdos ( void *pPointer ) ;

void os_iswindows ( void *pPointer ) ;

void os_iswindows64 ( void *pPointer ) ;

void os_isunix ( void *pPointer ) ;

void os_ismacosx ( void *pPointer ) ;

void os_islinux ( void *pPointer ) ;

void os_isfreebsd ( void *pPointer ) ;

void os_isandroid ( void *pPointer ) ;

void os_windowsnl ( void *pPointer ) ;

void os_currentdir ( void *pPointer ) ;

void os_exefilename ( void *pPointer ) ;

void os_chdir ( void *pPointer ) ;

void os_exefolder ( void *pPointer ) ;

void get_env ( void *pointer ) ;

/* Constants */
#define SIMPLE_VM_POINTER_LIBNAME "system"

#ifdef __cplusplus
}
#endif

#endif /* SYSTEMIC_H */

