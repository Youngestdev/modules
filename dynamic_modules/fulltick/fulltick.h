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

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#ifdef WIN32
#include <FL/x.H>           
#include <windows.h>		
#endif 

#ifdef __cplusplus
extern "C" {
#endif

class CallbackStruct
{
public:
  void *func;
  void *data;
  void *widget;
  void     *type;
  void *link;
  CallbackStruct( void *theFunc, void *theData, void *theWidget, void *theLink = 0):
    func(theFunc),
    data(theData),
    widget(theWidget)
  {}
  CallbackStruct( void *theFunc, void *theData, void *theType):
    func(theFunc),
    data(theData),
    widget(0),
    type(theType)
  {}
  
};

class MyWindow : public Fl_Window {
  int handle(int);
public:
  MyWindow(int w, int h, const char *t=0L) 
    : Fl_Window( w, h, t ) { }
};

SIMPLE_API void init_full_tick(SimpleState *sState) ;

#define FULLTICK_NOPARAM "No parameter is required for this block"
#define FULLTICK_MISING1PARAM "Only one parameter is required for this block "
#define FULLTICK_MISING2PARAM "Two parameters are required for this block "
#define FULLTICK_MISING3PARAM "Three parameters are required for this block "
#define FULLTICK_MISING4PARAM "Four parameters are required for this block "
#define FULLTICK_MISING5PARAM "Five parameters are required for this block "
#define FULLTICK_MISING6PARAM "Six parameters are required for this block "
#define FULLTICK_WRONGPARAM "An invalid parameter has been passed to the (GUI)fulltick Module "

#ifdef __cplusplus
}
#endif

#endif /* FULLTICK_H */

