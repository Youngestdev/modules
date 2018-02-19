/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fulltick.h
 * Author: thecarisma
 *
 * Created on February 18, 2018, 11:15 PM
 */

#ifndef FULLTICK_H
#define FULLTICK_H

#ifdef __cplusplus
extern "C" {
#endif

SIMPLE_API void init_full_tick(SimpleState *sState) ;

#define FULLTICK_NOPARAM "No parameter is required for this block"
#define FULLTICK_MISING1PARAM "Only one parameter is required for this block "
#define FULLTICK_MISING2PARAM "Two parameters are required for this block "
#define FULLTICK_MISING3PARAM "Three parameters are required for this block "
#define FULLTICK_MISINGPOINTER "A pointer of valid type is required for the block "

#ifdef __cplusplus
}
#endif

#endif /* FULLTICK_H */

