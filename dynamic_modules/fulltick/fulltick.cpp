
extern "C" {
	#include "../../../simple/bootsrc/includes/simple.h"
	#include "fulltick.h"
}

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

extern "C" {

	SIMPLE_API void init_simple_module(SimpleState *sState)
	{
		init_full_tick(sState);
	}

}

SIMPLE_BLOCK(test_gui)
{
	if ( SIMPLE_API_PARACOUNT != 1 ) {
		SIMPLE_API_ERROR(SIMPLE_API_MISS1PARA);
		return ;
	}
	if ( SIMPLE_API_ISSTRING(1) ) {
		Fl_Window *window = new Fl_Window(340,180);
		Fl_Box *box = new Fl_Box(20,40,300,100,SIMPLE_API_GETSTRING(1));
		box->box(FL_UP_BOX);
		box->labelfont(FL_BOLD+FL_ITALIC);
		box->labelsize(36);
		box->labeltype(FL_SHADOW_LABEL);
		window->end();
		window->show();
		int ret = Fl::run();
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}

SIMPLE_BLOCK(run_fulltick)
{
	if ( SIMPLE_API_PARACOUNT != 0 ) {
		SIMPLE_API_ERROR(FULLTICK_NOPARAM);
		return ;
	} SIMPLE_API_RETNUMBER(Fl::run()); 
}

SIMPLE_BLOCK(init_window)
{
	if ( SIMPLE_API_PARACOUNT != 4 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING4PARAM);
		return ;
	}
	if ( SIMPLE_API_ISNUMBER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISSTRING(3) && SIMPLE_API_ISNUMBER(4)) {
		Fl_Window *window = new Fl_Window(SIMPLE_API_GETNUMBER(1),SIMPLE_API_GETNUMBER(2), SIMPLE_API_GETSTRING(3));
		if (SIMPLE_API_GETNUMBER(4) == 1) 
		{
			Fl_Group& reswindow = *window; reswindow.resizable(&reswindow);
		}
		SIMPLE_API_RETCPOINTER(window,"SIMPLE_FLTK_");
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}

SIMPLE_BLOCK(show_window)
{
	if ( SIMPLE_API_PARACOUNT != 1 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING1PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) ) {
		Fl_Group& window = *((Fl_Group* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_"));
		window.end();
		window.show();
	} else {
		SIMPLE_API_ERROR(FULLTICK_MISINGPOINTER);
	}
}

SIMPLE_BLOCK(resizable_object)
{
	if ( SIMPLE_API_PARACOUNT != 1 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING1PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) ) {
		Fl_Group& window = *((Fl_Group* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_"));
		window.resizable(&window);
	} else {
		SIMPLE_API_ERROR(FULLTICK_MISINGPOINTER);
	}
}

SIMPLE_API void init_full_tick(SimpleState *sState) 
{
	register_block("__test_gui",test_gui);
	register_block("__init_window",init_window);
	register_block("__run_fulltick",run_fulltick);
	register_block("__show_window",show_window);
	register_block("__resizable",resizable_object);
}
