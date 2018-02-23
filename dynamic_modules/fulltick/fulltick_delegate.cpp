
extern "C" {
	#include "../../../simple/bootsrc/includes/simple.h"
	
}

#include "fulltick.h"



/** the callback delegate for the fulltick library **/
static void SimpleCallBack(Fl_Widget*, void* callback_struct) {
	CallbackStruct *cbs = (CallbackStruct *) callback_struct ;
	simple_vm_callblock((VM *) cbs->pointer,simple_string_get(cbs->block));
}

/** might be needed later for key listeners **/
int MyWindow::handle(int msg) {
  return msg;
}

/*
	JUNK YARD
	----------------------------------------------------------------------
	int handle(int e) {
		return (e == FL_SHORTCUT); // eat all keystrokes
	}
	Fl::add_handler(handle);
	-----------------------------------------------------------------------
	if ( simple_vm_exec((VM *) cbs->pointer,cbs->block->str) == 0 ) {
		((VM *) cbs->pointer)->nEvalCalledFromSimpleCode = 0 ;
	}
	simple_string_delete_gc(((VM *) cbs->pointer)->sState,cbs->block);
	-----------------------------------------------------------------------

*/