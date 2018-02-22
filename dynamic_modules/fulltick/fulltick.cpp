
extern "C" {
	#include "../../../simple/bootsrc/includes/simple.h"
	#include "fulltick.h"
}

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#ifdef WIN32
#include <FL/x.H>           
#include <windows.h>		
#endif 

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

/** FAPP **/

SIMPLE_BLOCK(run_fulltick)
{
	if ( SIMPLE_API_PARACOUNT != 0 ) {
		SIMPLE_API_ERROR(FULLTICK_NOPARAM);
		return ;
	} SIMPLE_API_RETNUMBER(Fl::run()); 
}

SIMPLE_BLOCK(set_look_and_feel)
{
	if ( SIMPLE_API_PARACOUNT != 1 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING1PARAM);
		return ;
	} 
	if ( SIMPLE_API_ISSTRING(1) ) {
		Fl::scheme(SIMPLE_API_GETSTRING(1));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	} 
}

/** FWIDGETS **/

SIMPLE_BLOCK(resizable_object)
{
	if ( SIMPLE_API_PARACOUNT != 1 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING1PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) ) {
		Fl_Window * window = (Fl_Window* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		window->resizable(window);
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(object_background)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Widget *window = (Fl_Widget* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		window->color(((Fl_Color) SIMPLE_API_GETNUMBER(2)));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(set_label_color)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Widget *window = (Fl_Widget* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		window->labelcolor(((Fl_Color) SIMPLE_API_GETNUMBER(2)));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(set_label_size)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Widget *window = (Fl_Widget* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		window->labelsize((int)SIMPLE_API_GETNUMBER(2));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(set_label_type)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Widget *widget = (Fl_Widget* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		if (_FL_SHADOW_LABEL == ((Fl_Labeltype)(int)SIMPLE_API_GETNUMBER(2)))
			widget->labeltype(FL_SHADOW_LABEL);
		else if ((FL_NORMAL_LABEL == ((Fl_Labeltype)(int)SIMPLE_API_GETNUMBER(2))))
			widget->labeltype(FL_SYMBOL_LABEL);
		else if ((_FL_ENGRAVED_LABEL == ((Fl_Labeltype)(int)SIMPLE_API_GETNUMBER(2))))
			widget->labeltype(FL_ENGRAVED_LABEL);
		else if ((_FL_EMBOSSED_LABEL == ((Fl_Labeltype)(int)SIMPLE_API_GETNUMBER(2))))
			widget->labeltype(FL_EMBOSSED_LABEL);
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(set_label_font)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Widget *window = (Fl_Widget* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		window->labelfont((int)SIMPLE_API_GETNUMBER(2));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(set_label)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISSTRING(2) ) {
		Fl_Widget *window = (Fl_Widget* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		window->copy_label(SIMPLE_API_GETSTRING(2));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(set_size)
{
	if ( SIMPLE_API_PARACOUNT != 3 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING3PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3) ) {
		Fl_Widget *window = (Fl_Widget* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		window->size((int)SIMPLE_API_GETNUMBER(2),(int)SIMPLE_API_GETNUMBER(3));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(set_tooltip)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	} 
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISSTRING(2) ) {
		Fl_Window *window = (Fl_Window* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		window->tooltip(SIMPLE_API_GETSTRING(2));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(set_visibility)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	} 
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Widget *object = (Fl_Widget* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		if (SIMPLE_API_GETNUMBER(2) == 0) {
			object->hide();
		} else if (SIMPLE_API_GETNUMBER(2) == 1) {
			object->show();
		} else if (SIMPLE_API_GETNUMBER(2) == 2) {
			Fl_Window* object = (Fl_Window* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
			object->iconize();
		}
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

void execute_click(Fl_Widget *, void * block) {
  printf("CALL BLOCK : %s\n", (char *) block);
}

/** on click / callback failing **/
SIMPLE_BLOCK(on_click)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISCPOINTER(1) && SIMPLE_API_GETSTRING(2) ) {
		Fl_Widget *window = (Fl_Widget* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		window->callback(execute_click,(char *)SIMPLE_API_GETSTRING(2)/*(Fl_Callback *)(&window,(void*)(SIMPLE_API_GETPOINTER(2)))*/);
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(add_widget)
{
	if ( SIMPLE_API_PARACOUNT != 3 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING3PARAM);
		return ;
	}
	if ( SIMPLE_API_ISCPOINTER(1) && SIMPLE_API_ISCPOINTER(2) && SIMPLE_API_ISNUMBER(3)) {
		Fl_Group *window = (Fl_Group* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		if ( (int)SIMPLE_API_GETNUMBER(3) == 1) {
			window->add_resizable(*((Fl_Group* ) SIMPLE_API_GETCPOINTER(2,"SIMPLE_FLTK_")));
		} else {
			window->add(((Fl_Group* ) SIMPLE_API_GETCPOINTER(2,"SIMPLE_FLTK_")));
		}
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(redraw_widget)
{
	if ( SIMPLE_API_PARACOUNT != 1 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING1PARAM);
		return ;
	}
	if ( SIMPLE_API_ISCPOINTER(1) ) {
		Fl_Widget *widget = (Fl_Widget* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		widget->redraw();
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(redraw_widget_parent)
{
	if ( SIMPLE_API_PARACOUNT != 1 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING1PARAM);
		return ;
	}
	if ( SIMPLE_API_ISCPOINTER(1) ) {
		Fl_Widget *widget = (Fl_Widget* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		widget->parent()->redraw();
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(get_parent_widget)
{
	if ( SIMPLE_API_PARACOUNT != 1 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING1PARAM);
		return ;
	}
	if ( SIMPLE_API_ISCPOINTER(1) ) {
		Fl_Widget *widget = (Fl_Widget* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		Fl_Widget *parent_widget = widget->parent();
		SIMPLE_API_RETCPOINTER(parent_widget,"SIMPLE_FLTK_");
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(set_position)
{
	if ( SIMPLE_API_PARACOUNT != 3 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING3PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3) ) {
		Fl_Widget *window = (Fl_Widget* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		window->position((int)SIMPLE_API_GETNUMBER(2),(int)SIMPLE_API_GETNUMBER(3));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

/** FWINDOW **/

SIMPLE_BLOCK(init_window)
{
	if ( SIMPLE_API_PARACOUNT != 4 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING6PARAM);
		return ;
	}
	if ( SIMPLE_API_ISNUMBER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISSTRING(3) && SIMPLE_API_ISNUMBER(4)) {
		Fl_Window *window = new Fl_Window((int)SIMPLE_API_GETNUMBER(1),(int)SIMPLE_API_GETNUMBER(2), SIMPLE_API_GETSTRING(3));
		if (SIMPLE_API_GETNUMBER(4) == 1) 
		{
			Fl_Window& reswindow = *window; reswindow.resizable(&reswindow);
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
	if ( SIMPLE_API_ISCPOINTER(1) ) {
		Fl_Window& window = *((Fl_Window* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_"));
		window.end();
		window.show();
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(full_screen)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2)) {
		Fl_Window *window = (Fl_Window* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		if (SIMPLE_API_GETNUMBER(2) ) {
			window->fullscreen();
		} else {
			window->fullscreen_off();
		}
		
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(set_window_border)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2)) {
		Fl_Window *window = (Fl_Window* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		window->border((int)SIMPLE_API_GETNUMBER(2));
		int windowx = window->x(), windowy = window->y();
		 window->hide(); window->show(); window->position(windowx, windowy);
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(set_window_icon)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Window *window = (Fl_Window* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		window->icon((char*)LoadIcon(fl_display, MAKEINTRESOURCE(101)));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

/** FBOX/FPANEL **/

SIMPLE_BLOCK(init_box)
{
	if ( SIMPLE_API_PARACOUNT != 4 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING4PARAM);
		return ;
	}
	if ( SIMPLE_API_ISNUMBER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3) && SIMPLE_API_ISNUMBER(4)) {
		Fl_Box *box = new Fl_Box((int)SIMPLE_API_GETNUMBER(1),(int)SIMPLE_API_GETNUMBER(2),(int)SIMPLE_API_GETNUMBER(3),(int)SIMPLE_API_GETNUMBER(4));
		SIMPLE_API_RETCPOINTER(box,"SIMPLE_FLTK_");
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}

SIMPLE_BLOCK(set_box_type)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISCPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Box *box = ((Fl_Box* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_"));
		box->box((Fl_Boxtype)(int)SIMPLE_API_GETNUMBER(2));
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}

/** FLABEL **/

SIMPLE_BLOCK(set_size_with_label)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Widget *widget = (Fl_Widget* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		int wi=0, hi=0; fl_font(widget->labelfont(), widget->labelsize()); 
		fl_measure(widget->label(), wi,hi);
		widget->size(wi+(int)SIMPLE_API_GETNUMBER(2),hi+(int)SIMPLE_API_GETNUMBER(2));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_API void init_full_tick(SimpleState *sState) 
{
	register_block("__test_gui",test_gui);

	/** FAPP **/
	register_block("__run_fulltick",run_fulltick);
	register_block("__set_look_and_feel",set_look_and_feel);

	/** FWIDGETS **/
	register_block("__resizable",resizable_object);
	register_block("__set_bg",object_background);
	register_block("__set_label",set_label);
	register_block("__set_label_color",set_label_color);
	register_block("__set_label_size",set_label_size);
	register_block("__set_label_type",set_label_type);
	register_block("__set_label_font",set_label_font);
	register_block("__set_size",set_size);
	register_block("__set_position",set_position);
	register_block("__set_tooltip",set_tooltip);
	register_block("__set_visibility",set_visibility);
	register_block("__on_click",on_click);
	register_block("__add_widget",add_widget);
	register_block("__redraw_widget",redraw_widget);
	register_block("__redraw_widget_parent",redraw_widget_parent);
	register_block("__get_parent_widget",get_parent_widget);

	/** FWINDOW **/
	register_block("__init_window",init_window);
	register_block("__show_window",show_window);
	register_block("__full_screen",full_screen);
	register_block("__set_window_border",set_window_border);
	register_block("__set_window_icon",set_window_icon);

	/** FBOX/FPANEL **/
	register_block("__init_box",init_box);
	register_block("__set_box_type",set_box_type);

	/** FLABEL **/
	register_block("__set_size_with_label",set_size_with_label);
}
