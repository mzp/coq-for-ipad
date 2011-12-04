/***********************************************************************/
/*                                                                     */
/*                           Objective Caml                            */
/*                                                                     */
/*  Developed by Jacob Navia, based on code by J-M Geffroy and X Leroy */
/*  Copyright 2001 Institut National de Recherche en Informatique et   */
/*  en Automatique.  All rights reserved.  This file is distributed    */
/*  under the terms of the GNU Library General Public License, with    */
/*  the special exception on linking described in file ../../LICENSE.  */
/*                                                                     */
/***********************************************************************/

/* $Id: open.c 9547 2010-01-22 12:48:24Z doligez $ */

#include <memory.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>

#include "../../byterun/custom.h"
#include "../../byterun/callback.h"
#include "../../byterun/mlvalues.h"
#include "../../byterun/alloc.h"
#include "../../byterun/memory.h"
#include "../../byterun/fail.h"
#include "graphstubs.h"
#include "../../byterun/glue.h"

static value gr_reset(void);
int grdisplay_mode;
int grremember_mode;
//static long tid;
//static HANDLE threadHandle;
#if 0
HWND grdisplay = NULL;
int grscreen;
COLORREF grwhite, grblack;
COLORREF grbackground;
int grCurrentColor;
BOOL grdisplay_mode;
BOOL grremember_mode;
int grx, gry;
int grcolor;
extern HFONT * grfont;
MSG msg;
#endif
CAMLprim value caml_gr_clear_graph(void);
// HANDLE hInst;
#if 0
HFONT MyCreationFont(char *name)
{
   LOGFONT CurrentFont;
   memset(&CurrentFont, 0, sizeof(LOGFONT));
   CurrentFont.lfCharSet = ANSI_CHARSET;
   CurrentFont.lfWeight = FW_NORMAL;
   CurrentFont.lfHeight = grwindow.CurrentFontSize;
   CurrentFont.lfPitchAndFamily = (BYTE) (FIXED_PITCH | FF_MODERN);
   strcpy(CurrentFont.lfFaceName, name);  /* Courier */
   return (CreateFontIndirect(&CurrentFont));
}
void SetCoordinates(HWND hwnd)
{
        RECT rc;

        GetClientRect(hwnd,&rc);
        grwindow.width = rc.right;
        grwindow.height = rc.bottom;
        gr_reset();
}
#endif

void ResetForClose(void)
{
	gr_reset();
	gr_close();
}

static value gr_reset(void)
{
        int screenx,screeny;
#if 0
        screenx = GetSystemMetrics(SM_CXSCREEN);
        screeny = GetSystemMetrics(SM_CYSCREEN);
        grwindow.grx = 0;
        grwindow.gry = 0;
#endif
        caml_gr_set_color(Val_long(0));
		qReset();
        return Val_unit;
}

CAMLprim value caml_gr_open_graph(value arg)
{ 
	gr_open();
	gr_reset();
  /* Position the current point at origin */
#if 0
	grwindow.grx = 0;
  grwindow.gry = 0;
#endif
	return Val_unit;
}

CAMLprim value caml_gr_close_graph(void)
{
		ResetForClose();
        return Val_unit;
}

value caml_gr_window_id(void)
{
//	caml_gr_check_open();
	return copy_string( "1" );
}

#if 0
value caml_gr_set_window_title(value n)
{
	if (window_name != NULL) stat_free(window_name);
	window_name = stat_alloc(strlen(String_val(n))+1);
	strcpy(window_name, String_val(n));
	return Val_unit;
}
#endif
value caml_gr_resize_window (value vx, value vy)
{
//	caml_gr_check_open ();
		
	caml_gr_clear_graph ();
	return Val_unit;
}

value caml_gr_open_subwindow(value vx, value vy, value width, value height)
{
	return copy_string( "1" );
}

value caml_gr_close_subwindow(value wid)
{
	return Val_unit;
}

CAMLprim value caml_gr_clear_graph(void)
{
        gr_check_open();
       return Val_unit;
}

#if 0
CAMLprim value caml_gr_resize_window (value vx, value vy)
{
  gr_check_open ();

  /* FIXME TODO implement this function... */

  return Val_unit;
}
#endif
CAMLprim value caml_gr_synchronize(void)
{
        gr_check_open();
        return Val_unit ;
}

CAMLprim value caml_gr_display_mode(value flag)
{
        grdisplay_mode =  (Int_val(flag)) ? 1 : 0;
        return Val_unit ;
}

CAMLprim value caml_gr_remember_mode(value flag)
{
        grremember_mode = (Int_val(flag)) ? 1 : 0;
        return Val_unit ;
}

CAMLprim value caml_gr_sigio_signal(value unit)
{
        return Val_unit;
}

CAMLprim value caml_gr_sigio_handler(void)
{
        return Val_unit;
}


/* Processing of graphic errors */

static value * graphic_failure_exn = NULL;
void gr_fail(char *fmt, char *arg)
{
  char buffer[1024];

  if (graphic_failure_exn == NULL) {
    graphic_failure_exn = caml_named_value("Graphics.Graphic_failure");
    if (graphic_failure_exn == NULL)
      invalid_argument("Exception Graphics.Graphic_failure not initialized, must link graphics.cma");
  }
  sprintf(buffer, fmt, arg);
  raise_with_string(*graphic_failure_exn, buffer);
}

void gr_check_open(void)
{
//  if (!gr_initialized) gr_fail("graphic screen not opened", NULL);
}
