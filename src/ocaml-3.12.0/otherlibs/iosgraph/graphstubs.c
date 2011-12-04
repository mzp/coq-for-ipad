#include <stdio.h>
#include <memory.h>
#include "../../byterun/mlvalues.h"
#include "../../byterun/glue.h"
#include "graphstubs.h"

//GR_WINDOW grwindow;
char *window_name;

struct camlsyms graph_camlsyms[] = {
"caml_gr_plot",  caml_gr_plot, 
"caml_gr_moveto",  caml_gr_moveto,
"caml_gr_current_x", caml_gr_current_x,
"caml_gr_current_y", caml_gr_current_y,
"caml_gr_lineto", caml_gr_lineto,
"caml_gr_draw_rect", caml_gr_draw_rect,
"caml_gr_draw_text", caml_gr_draw_text,
"caml_gr_fill_rect", caml_gr_fill_rect,
"caml_gr_sound", caml_gr_sound,
"caml_gr_point_color", caml_gr_point_color,
"caml_gr_circle", caml_gr_circle,
"caml_gr_set_window_title", caml_gr_set_window_title,
"caml_gr_draw_arc", caml_gr_draw_arc,
"caml_gr_draw_arc_nat", caml_gr_draw_arc_nat,
"caml_gr_set_line_width", caml_gr_set_line_width,
"caml_gr_set_color", caml_gr_set_color,
"caml_gr_show_bitmap", caml_gr_show_bitmap,
"caml_gr_get_mousex", caml_gr_get_mousex,
"caml_gr_get_mousey", caml_gr_get_mousey,
"caml_gr_set_font", caml_gr_set_font,
"caml_gr_set_text_size", caml_gr_set_text_size,
"caml_gr_draw_char", caml_gr_draw_char,
"caml_gr_draw_string", caml_gr_draw_string,
"caml_gr_text_size", caml_gr_text_size,
"caml_gr_fill_poly", caml_gr_fill_poly,
"caml_gr_fill_arc", caml_gr_fill_arc,
"caml_gr_fill_arc_nat", caml_gr_fill_arc_nat,
"caml_gr_create_image", caml_gr_create_image,
"caml_gr_blit_image", caml_gr_blit_image,
"caml_gr_draw_image", caml_gr_draw_image,
//"caml_gr_make_image", caml_gr_make_image,
"caml_gr_dump_image", caml_gr_dump_image,
"caml_gr_wait_event", caml_gr_wait_event,
"caml_gr_clear_graph", caml_gr_clear_graph,
"caml_gr_open_graph", caml_gr_open_graph,
"caml_gr_close_graph", caml_gr_close_graph,
"caml_gr_clear_graph", caml_gr_clear_graph,
"caml_gr_size_x", caml_gr_size_x,
"caml_gr_size_y", caml_gr_size_y,
"caml_gr_resize_window", caml_gr_resize_window,
"caml_gr_synchronize", caml_gr_synchronize,
"caml_gr_display_mode", caml_gr_display_mode,
"caml_gr_remember_mode", caml_gr_remember_mode,
"caml_gr_sigio_signal", caml_gr_sigio_signal,
"caml_gr_sigio_handler", caml_gr_sigio_handler,
"caml_gr_window_id", caml_gr_window_id,
	"caml_gr_open_subwindow", caml_gr_open_subwindow,
	"caml_gr_close_subwindow", caml_gr_close_subwindow,
	"", NULL};

enum {TEXT};
static int movex, movey, mode, tcolour;
static void *gc, *hsel;
#if 0
extern HBRUSH CreateBrushIndirect(LOGBRUSH *arg) { 
	HBRUSH brush = malloc(sizeof(LOGBRUSH));
	memcpy(brush, arg, sizeof(LOGBRUSH));
	return brush;
}

extern void *CreateCompatibleBitmap(void * arg1,  int arg2,  int arg3) { 
	return calloc(arg2,arg3);
}

extern void *CreateCompatibleDC(void *arg) { 
	return arg;
}

extern HPEN CreatePenIndirect(LOGPEN *arg) { 
	HPEN pen = malloc(sizeof(LOGPEN));
	memcpy(pen, arg, sizeof(LOGPEN));
	return pen;
}

extern HPEN CreatePen(int arg1,  int arg2,  int arg3) { 
	return calloc(1, sizeof(HPEN));
}

extern int GetObject(void *arg1,  int arg2,  LOGPEN *arg3) { 
	memcpy(arg3, arg1, arg2);
	return 0;
}

extern void *GetStockObject(int arg) { 
	switch (arg) {
		case WHITE_PEN:
			return calloc(1, sizeof(LOGPEN));
			break;
		case WHITE_BRUSH:
			return "WHITE_BRUSH";
			break;
		default:
			return "";
			break;
	}
}

extern int GetSysColor(int arg) { 
	switch (arg) {
		case COLOR_WINDOWTEXT:
			return arg;
			break;
		default:
			return 0;
			break;
	}
}

extern int GetSystemMetrics(int arg) { 
	switch (arg) {
		case SM_CXSCREEN:
			return 768;
			break;
		case SM_CYSCREEN:
			return 1024;
			break;
		default:
			return 0;
			break;
	}
}

extern int MoveToEx(HDC arg1,  int arg2,  int arg3,  void *arg4) { 
	movex = arg2;
	movey = arg3;
	return 0;
}

extern COLORREF RGB(int arg1, int arg2, int arg3) { 
	COLORREF ref;
	ref = (arg1&0xFF) |
		((arg2&0xFF)<<8) |
		((arg3&0xFF)<<16);
	return ref;
}

extern void *SelectObject(void *arg1, void *arg2) {
	gc = arg1;
	hsel = arg2;
	return arg2;
}
#endif
extern int SetTextAlign(void * arg1,  int arg2) { 
	
}

extern int SetTextColor(void * arg1,  int arg2) { 
	tcolour = arg2;
}
