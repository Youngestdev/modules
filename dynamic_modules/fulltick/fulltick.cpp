


#include "fulltick_delegate.cpp"

/** the callback class for fulltick library **/
CallbackStruct::CallbackStruct(void *the_pointer, String *the_block, Fl_Widget *the_widget) {
	pointer = the_pointer ;
	block = the_block ;
	widget = the_widget ;
}

/** the callback delegate for the fulltick library **/
static void SimpleCallBack(Fl_Widget*, void* callback_struct) {
	CallbackStruct *cbs = (CallbackStruct *) callback_struct ;
	simple_vm_callblock((VM *) cbs->pointer,simple_string_get(cbs->block));
}

/** might be needed later for key listeners **/
int MyWindow::handle(int msg) {
  return msg;
}

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

SIMPLE_BLOCK(set_widget_background)
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
		Fl_Widget *window = (Fl_Widget* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		String* tooltip = simple_string_new_gc(((VM*)pointer)->sState,SIMPLE_API_GETSTRING(2));
		window->tooltip(tooltip->str);
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

SIMPLE_BLOCK(on_click)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISCPOINTER(1) ) {
		Fl_Widget *widget = (Fl_Widget* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		String * str = simple_string_new_gc(((VM *) pointer)->sState,SIMPLE_API_GETSTRING(2)); 
		CallbackStruct *cbs = new CallbackStruct(pointer, str, widget);
		widget->callback(SimpleCallBack,cbs);
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(activate_deactivate_widget)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISCPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Widget *widget = (Fl_Widget* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		if (SIMPLE_API_GETNUMBER(2) == 1) {
			widget->activate();
		} else {
			widget->deactivate();
		}
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

/** FBUTTON (s) **/

SIMPLE_BLOCK(init_button)
{
	if ( SIMPLE_API_PARACOUNT != 4 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING4PARAM);
		return ;
	}
	if ( SIMPLE_API_ISNUMBER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3) && SIMPLE_API_ISNUMBER(4)) {
		Fl_Button *button = new Fl_Button((int)SIMPLE_API_GETNUMBER(1),(int)SIMPLE_API_GETNUMBER(2),(int)SIMPLE_API_GETNUMBER(3),(int)SIMPLE_API_GETNUMBER(4));
		SIMPLE_API_RETCPOINTER(button,"SIMPLE_FLTK_");
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}

SIMPLE_BLOCK(init_return_button)
{
	if ( SIMPLE_API_PARACOUNT != 4 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING4PARAM);
		return ;
	}
	if ( SIMPLE_API_ISNUMBER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3) && SIMPLE_API_ISNUMBER(4)) {
		Fl_Return_Button *button = new Fl_Return_Button((int)SIMPLE_API_GETNUMBER(1),(int)SIMPLE_API_GETNUMBER(2),(int)SIMPLE_API_GETNUMBER(3),(int)SIMPLE_API_GETNUMBER(4));
		SIMPLE_API_RETCPOINTER(button,"SIMPLE_FLTK_");
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}

SIMPLE_BLOCK(init_repeat_button)
{
	if ( SIMPLE_API_PARACOUNT != 4 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING4PARAM);
		return ;
	}
	if ( SIMPLE_API_ISNUMBER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3) && SIMPLE_API_ISNUMBER(4)) {
		Fl_Repeat_Button *button = new Fl_Repeat_Button((int)SIMPLE_API_GETNUMBER(1),(int)SIMPLE_API_GETNUMBER(2),(int)SIMPLE_API_GETNUMBER(3),(int)SIMPLE_API_GETNUMBER(4));
		SIMPLE_API_RETCPOINTER(button,"SIMPLE_FLTK_");
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}

SIMPLE_BLOCK(init_light_button)
{
	if ( SIMPLE_API_PARACOUNT != 4 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING4PARAM);
		return ;
	}
	if ( SIMPLE_API_ISNUMBER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3) && SIMPLE_API_ISNUMBER(4)) {
		Fl_Light_Button *button = new Fl_Light_Button((int)SIMPLE_API_GETNUMBER(1),(int)SIMPLE_API_GETNUMBER(2),(int)SIMPLE_API_GETNUMBER(3),(int)SIMPLE_API_GETNUMBER(4));
		SIMPLE_API_RETCPOINTER(button,"SIMPLE_FLTK_");
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}

SIMPLE_BLOCK(init_round_button)
{
	if ( SIMPLE_API_PARACOUNT != 4 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING4PARAM);
		return ;
	}
	if ( SIMPLE_API_ISNUMBER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3) && SIMPLE_API_ISNUMBER(4)) {
		Fl_Round_Button *button = new Fl_Round_Button((int)SIMPLE_API_GETNUMBER(1),(int)SIMPLE_API_GETNUMBER(2),(int)SIMPLE_API_GETNUMBER(3),(int)SIMPLE_API_GETNUMBER(4));
		SIMPLE_API_RETCPOINTER(button,"SIMPLE_FLTK_");
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}

SIMPLE_BLOCK(init_check_button)
{
	if ( SIMPLE_API_PARACOUNT != 4 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING4PARAM);
		return ;
	}
	if ( SIMPLE_API_ISNUMBER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3) && SIMPLE_API_ISNUMBER(4)) {
		Fl_Check_Button *button = new Fl_Check_Button((int)SIMPLE_API_GETNUMBER(1),(int)SIMPLE_API_GETNUMBER(2),(int)SIMPLE_API_GETNUMBER(3),(int)SIMPLE_API_GETNUMBER(4));
		SIMPLE_API_RETCPOINTER(button,"SIMPLE_FLTK_");
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}

SIMPLE_BLOCK(set_button_down_box)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISCPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Button *box = ((Fl_Button* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_"));
		box->down_box((Fl_Boxtype)(int)SIMPLE_API_GETNUMBER(2));
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}

SIMPLE_BLOCK(set_button_down_color)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Button *button = (Fl_Button* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		button->down_color(((Fl_Color) SIMPLE_API_GETNUMBER(2)));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(set_button_only)
{
	if ( SIMPLE_API_PARACOUNT != 1 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING1PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) ) {
		Fl_Button *button = (Fl_Button* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		button->setonly();
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(set_button_shortcut)
{
	if ( SIMPLE_API_PARACOUNT != 3 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING3PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Button *button = (Fl_Button* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		if (((int)SIMPLE_API_GETNUMBER(2)) == 1) {
			button->shortcut(((int)SIMPLE_API_GETNUMBER(3)));
		} else {
			button->shortcut(((char *)SIMPLE_API_GETSTRING(3)));
		}
		
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(set_button_value)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Button *button = (Fl_Button* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		button->value(((int) SIMPLE_API_GETNUMBER(2)));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

/** FINPUT/FTEXT (s) **/

SIMPLE_BLOCK(init_input)
{
	if ( SIMPLE_API_PARACOUNT != 4 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING4PARAM);
		return ;
	}
	if ( SIMPLE_API_ISNUMBER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3) && SIMPLE_API_ISNUMBER(4)) {
		Fl_Input *input = new Fl_Input((int)SIMPLE_API_GETNUMBER(1),(int)SIMPLE_API_GETNUMBER(2),(int)SIMPLE_API_GETNUMBER(3),(int)SIMPLE_API_GETNUMBER(4));
		SIMPLE_API_RETCPOINTER(input,"SIMPLE_FLTK_");
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}

SIMPLE_BLOCK(init_float_input)
{
	if ( SIMPLE_API_PARACOUNT != 4 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING4PARAM);
		return ;
	}
	if ( SIMPLE_API_ISNUMBER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3) && SIMPLE_API_ISNUMBER(4)) {
		Fl_Float_Input *input = new Fl_Float_Input((int)SIMPLE_API_GETNUMBER(1),(int)SIMPLE_API_GETNUMBER(2),(int)SIMPLE_API_GETNUMBER(3),(int)SIMPLE_API_GETNUMBER(4));
		SIMPLE_API_RETCPOINTER(input,"SIMPLE_FLTK_");
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}

SIMPLE_BLOCK(init_int_input)
{
	if ( SIMPLE_API_PARACOUNT != 4 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING4PARAM);
		return ;
	}
	if ( SIMPLE_API_ISNUMBER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3) && SIMPLE_API_ISNUMBER(4)) {
		Fl_Int_Input *input = new Fl_Int_Input((int)SIMPLE_API_GETNUMBER(1),(int)SIMPLE_API_GETNUMBER(2),(int)SIMPLE_API_GETNUMBER(3),(int)SIMPLE_API_GETNUMBER(4));
		SIMPLE_API_RETCPOINTER(input,"SIMPLE_FLTK_");
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}

SIMPLE_BLOCK(init_secret_input)
{
	if ( SIMPLE_API_PARACOUNT != 4 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING4PARAM);
		return ;
	}
	if ( SIMPLE_API_ISNUMBER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3) && SIMPLE_API_ISNUMBER(4)) {
		Fl_Secret_Input *input = new Fl_Secret_Input((int)SIMPLE_API_GETNUMBER(1),(int)SIMPLE_API_GETNUMBER(2),(int)SIMPLE_API_GETNUMBER(3),(int)SIMPLE_API_GETNUMBER(4));
		SIMPLE_API_RETCPOINTER(input,"SIMPLE_FLTK_");
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}

SIMPLE_BLOCK(init_multiline_input)
{
	if ( SIMPLE_API_PARACOUNT != 4 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING4PARAM);
		return ;
	}
	if ( SIMPLE_API_ISNUMBER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3) && SIMPLE_API_ISNUMBER(4)) {
		Fl_Multiline_Input *input = new Fl_Multiline_Input((int)SIMPLE_API_GETNUMBER(1),(int)SIMPLE_API_GETNUMBER(2),(int)SIMPLE_API_GETNUMBER(3),(int)SIMPLE_API_GETNUMBER(4));
		SIMPLE_API_RETCPOINTER(input,"SIMPLE_FLTK_");
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}

SIMPLE_BLOCK(input_copy)
{
	if ( SIMPLE_API_PARACOUNT != 3 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING3PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3) ) {
		Fl_Input_ *input = (Fl_Input_* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		if (SIMPLE_API_GETNUMBER(3) == 1) {
			SIMPLE_API_RETNUMBER(input->copy((int)SIMPLE_API_GETNUMBER(2)));
		} else {
			SIMPLE_API_RETNUMBER(input->copy_cuts());
		}
		
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}

SIMPLE_BLOCK(input_cut)
{
	if ( SIMPLE_API_PARACOUNT != 4 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING4PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3) && SIMPLE_API_ISNUMBER(4)) {
		Fl_Input_ *input = (Fl_Input_* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		if (SIMPLE_API_GETNUMBER(4) == 1) {
			SIMPLE_API_RETNUMBER(input->cut()); 
		} else if (SIMPLE_API_GETNUMBER(4) == 2) {
			SIMPLE_API_RETNUMBER(input->cut((int)SIMPLE_API_GETNUMBER(2)));
		} else {
			SIMPLE_API_RETNUMBER(input->cut((int)SIMPLE_API_GETNUMBER(2),(int)SIMPLE_API_GETNUMBER(3)));
		}
		
	} else {
		SIMPLE_API_ERROR(SIMPLE_API_BADPARATYPE);
	}
}

SIMPLE_BLOCK(set_input_cursor_color)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Input_ *input = (Fl_Input_* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		input->cursor_color(((Fl_Color) SIMPLE_API_GETNUMBER(2)));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(get_input_index)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Input_ *input = (Fl_Input_* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		SIMPLE_API_RETSTRING((const char*)input->index((int) SIMPLE_API_GETNUMBER(2)));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(input_insert)
{
	if ( SIMPLE_API_PARACOUNT != 3 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING3PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISSTRING(2) && SIMPLE_API_ISNUMBER(3)) {
		Fl_Input_ *input = (Fl_Input_* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		if ((int)SIMPLE_API_GETNUMBER(3) == -1) {
			input->insert((const char*) SIMPLE_API_GETSTRING(2));
		} else { 
			input->insert((const char*) SIMPLE_API_GETSTRING(2), (int)SIMPLE_API_GETNUMBER(3));
		}
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(input_mark)
{
	if ( SIMPLE_API_PARACOUNT != 3 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING3PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3)) {
		Fl_Input_ *input = (Fl_Input_* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		if ((int)SIMPLE_API_GETNUMBER(3) == 1) {
			SIMPLE_API_RETNUMBER(input->mark());
		} else { 
			SIMPLE_API_RETNUMBER(input->mark((int)SIMPLE_API_GETNUMBER(2)));
		}
		
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(input_maximum_size)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2)) {
		Fl_Input_ *input = (Fl_Input_* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		input->maximum_size((int)SIMPLE_API_GETNUMBER(2));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(input_position)
{
	if ( SIMPLE_API_PARACOUNT != 4 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING4PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3) && SIMPLE_API_ISNUMBER(4)) {
		Fl_Input_ *input = (Fl_Input_* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		if ((int)SIMPLE_API_GETNUMBER(4) == 1) {
			SIMPLE_API_RETNUMBER(input->position());
		} else if ((int)SIMPLE_API_GETNUMBER(4) == 0)  { 
			SIMPLE_API_RETNUMBER(input->position((int)SIMPLE_API_GETNUMBER(2),(int)SIMPLE_API_GETNUMBER(3)));
		} else {
			SIMPLE_API_RETNUMBER(input->position((int)SIMPLE_API_GETNUMBER(2)));
		}
		
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(input_read_only)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2)) {
		Fl_Input_ *input = (Fl_Input_* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		input->readonly((int)SIMPLE_API_GETNUMBER(2));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(input_replace)
{
	if ( SIMPLE_API_PARACOUNT != 4 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING4PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) && SIMPLE_API_ISNUMBER(3) && SIMPLE_API_ISSTRING(4)) {
		Fl_Input_ *input = (Fl_Input_* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		input->replace((int)SIMPLE_API_GETNUMBER(2),(int)SIMPLE_API_GETNUMBER(3),SIMPLE_API_GETSTRING(4));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(input_shortcut)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Input_ *input = (Fl_Input_* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		input->shortcut(((int)SIMPLE_API_GETNUMBER(2)));		
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(input_size)
{
	if ( SIMPLE_API_PARACOUNT != 1 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING1PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) ) {
		Fl_Input_ *input = (Fl_Input_* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		SIMPLE_API_RETNUMBER(input->size());		
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(input_static_value)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISSTRING(2) ) {
		Fl_Input_ *input = (Fl_Input_* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		input->static_value(SIMPLE_API_GETSTRING(2));		
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(input_tab_nav)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Input_ *input = (Fl_Input_* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		input->tab_nav((int)SIMPLE_API_GETNUMBER(2));		
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(input_text_color)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Input_ *input = (Fl_Input_* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		input->textcolor(((Fl_Color) SIMPLE_API_GETNUMBER(2)));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(input_text_font)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Input_ *input = (Fl_Input_* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		input->labelfont((Fl_Font)SIMPLE_API_GETNUMBER(2));
	} else {
		SIMPLE_API_ERROR(FULLTICK_WRONGPARAM);
	}
}

SIMPLE_BLOCK(input_text_size)
{
	if ( SIMPLE_API_PARACOUNT != 2 ) {
		SIMPLE_API_ERROR(FULLTICK_MISING2PARAM);
		return ;
	}
	if ( SIMPLE_API_ISPOINTER(1) && SIMPLE_API_ISNUMBER(2) ) {
		Fl_Input_ *input = (Fl_Input_* ) SIMPLE_API_GETCPOINTER(1,"SIMPLE_FLTK_");
		input->labelsize((Fl_Fontsize)SIMPLE_API_GETNUMBER(2));
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
	register_block("__set_bg",set_widget_background);
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
	register_block("__activate_deactivate_widget",activate_deactivate_widget);
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

	/** FBUTTON (s) **/
	register_block("__init_button",init_button);
	register_block("__init_return_button",init_return_button);
	register_block("__init_repeat_button",init_repeat_button);
	register_block("__init_light_button",init_light_button);
	register_block("__init_round_button",init_round_button);
	register_block("__init_check_button",init_check_button);
	register_block("__set_button_down_box",set_button_down_box);
	register_block("__set_button_down_color",set_button_down_color);
	register_block("__set_button_only",set_button_only);
	register_block("__set_button_shortcut",set_button_shortcut);
	register_block("__set_button_value",set_button_value);

	/** FINPUT/FTEXT (s) **/
	register_block("__init_input",init_input);
	register_block("__init_float_input",init_float_input);
	register_block("__init_int_input",init_int_input);
	register_block("__init_secret_input",init_secret_input);
	register_block("__init_multiline_input",init_multiline_input);
	register_block("__input_copy",input_copy);
	register_block("__input_cut",input_cut);
	register_block("__set_input_cursor_color",set_input_cursor_color);
	register_block("__get_input_index",get_input_index);
	register_block("__input_insert",input_insert);
	register_block("__input_mark",input_mark);
	register_block("__input_maximum_size",input_maximum_size);
	register_block("__input_position",input_position);
	register_block("__input_read_only",input_read_only);
	register_block("__input_replace",input_replace);
	register_block("__input_shortcut",input_shortcut);
	register_block("__input_size",input_size);
	register_block("__input_static_value",input_static_value);
	register_block("__input_tab_nav",input_tab_nav);
	register_block("__input_text_color",input_text_color);
	register_block("__input_text_font",input_text_font);
	register_block("__input_text_size",input_text_size);

}
