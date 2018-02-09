/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   string_savant.h
 * Author: thecarisma
 *
 * Created on February 9, 2018, 12:48 AM
 */

#ifndef STRING_SAVANT_H
#define STRING_SAVANT_H

#ifdef __cplusplus
extern "C" {
#endif

void simple_vmlib_lower ( void *pPointer ) ;

void simple_vmlib_upper ( void *pPointer ) ;

void simple_vmlib_left ( void *pPointer ) ;

void simple_vmlib_right ( void *pPointer ) ;

void simple_vmlib_trim ( void *pPointer ) ;

void simple_vmlib_copy ( void *pPointer ) ;

void simple_vmlib_substr ( void *pPointer ) ;

void simple_vmlib_lines ( void *pPointer ) ;

void simple_vmlib_strcmp ( void *pPointer ) ;


#ifdef __cplusplus
}
#endif

#endif /* STRING_SAVANT_H */

