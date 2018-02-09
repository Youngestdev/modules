
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

void simple_vm_os_loadfunctions ( SimpleState *pSimpleState ) ;

void simple_vm_os_ismsdos ( void *pPointer ) ;

void simple_vm_os_iswindows ( void *pPointer ) ;

void simple_vm_os_iswindows64 ( void *pPointer ) ;

void simple_vm_os_isunix ( void *pPointer ) ;

void simple_vm_os_ismacosx ( void *pPointer ) ;

void simple_vm_os_islinux ( void *pPointer ) ;

void simple_vm_os_isfreebsd ( void *pPointer ) ;

void simple_vm_os_isandroid ( void *pPointer ) ;

void simple_vm_os_windowsnl ( void *pPointer ) ;

void simple_vm_os_currentdir ( void *pPointer ) ;

void simple_vm_os_exefilename ( void *pPointer ) ;

void simple_vm_os_chdir ( void *pPointer ) ;

void simple_vm_os_exefolder ( void *pPointer ) ;

/* Constants */
#define SIMPLE_VM_POINTER_LIBNAME "system"

#ifdef __cplusplus
}
#endif

#endif /* SYSTEMIC_H */

