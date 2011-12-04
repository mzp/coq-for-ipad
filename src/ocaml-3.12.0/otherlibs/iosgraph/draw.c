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

/* $Id: draw.c 9547 2010-01-22 12:48:24Z doligez $ */

#include <math.h>
#include <memory.h>

#include "../../byterun/custom.h"
#include "../../byterun/mlvalues.h"
#include "../../byterun/alloc.h"
#include "../../byterun/memory.h"
#include "../../byterun/fail.h"
#include "graphstubs.h"
#include "../../byterun/glue.h"

#import <CoreGraphics/CGGeometry.h>

//HDC gcMetaFile;
static char *myfont = "Arial";
static int mytextsize = 16;
static struct { int grx, gry; } grwindow;

static value gr_draw_or_fill_arc(value vx, value vy, value vrx, value vry,
                                 value vstart, value vend, BOOL fill);

CAMLprim value caml_gr_plot(value vx, value vy)
{
        int x = Int_val(vx);
        int y = Int_val(vy);
        gr_check_open();
		queue(qRect, x, y, 1, 1);
        return Val_unit;
}

CAMLprim value caml_gr_moveto(value vx, value vy)
{
        grwindow.grx = Int_val(vx);
        grwindow.gry = Int_val(vy);
		return Val_unit;
}

CAMLprim value caml_gr_current_x(void)
{
        return Val_int(grwindow.grx);
}

CAMLprim value caml_gr_current_y(void)
{
        return Val_int(grwindow.gry);
}

CAMLprim value caml_gr_lineto(value vx, value vy)
{
        int x = Int_val(vx);
        int y = Int_val(vy);
		gr_check_open();
		queue(qLine, grwindow.grx, grwindow.gry, x, y);
        grwindow.grx = x;
        grwindow.gry = y;
        return Val_unit;
}

CAMLprim value caml_gr_draw_rect(value vx, value vy, value vw, value vh)
{
        int     x, y, w, h;

		x=Int_val(vx);
        y=(Int_val(vy));
        w=Int_val(vw);
        h=Int_val(vh);

		queue(qRect,x,y,w,h);
        return Val_unit;
}

CAMLprim value caml_gr_draw_text(value text,value x)
{
		int len = Int_val(x);
		char *str = String_val(text);
		DrawText(str, len, grwindow.grx, grwindow.gry, mytextsize);
        return Val_unit;
}

CAMLprim value caml_gr_fill_rect(value vx, value vy, value vw, value vh)
{
        int x = Int_val(vx);
        int y = Int_val(vy);
        int w = Int_val(vw);
        int h = Int_val(vh);

        gr_check_open();
		queue(qFill, x, y, w, h);
        return Val_unit;
}

void mysound(int freq, int dur)
{
	// here goes playSound ??
}

CAMLprim value caml_gr_sound(value freq, value vdur)
{
        mysound(Int_val(freq),Int_val(vdur));
        return Val_unit;
}

int MyGetPixel(int x, int y)
{
	return 0; // need to put something here
}

CAMLprim value caml_gr_point_color(value vx, value vy)
{
        int x = Int_val(vx);
        int y = Int_val(vy);
        long rgb;
        unsigned long b,g,r;

        gr_check_open();
	rgb = MyGetPixel(x, y);
        b = (unsigned long)((rgb & 0xFF0000) >> 16);
        g = (unsigned long)((rgb & 0x00FF00) >> 8);
        r = (unsigned long)(rgb & 0x0000FF);
        return Val_long((r<<16) + (g<<8) + b);
}

CAMLprim value caml_gr_circle(value x,value y,value radius)
{
	return gr_draw_or_fill_arc(x, y, radius, radius,
							   0, 360, FALSE);
}

char *window_title = "";

CAMLprim value caml_gr_set_window_title(value text)
{
        window_title = strdup((char *)text);
        return Val_unit;
}

CAMLprim value caml_gr_draw_arc(value *argv, int argc)
{
  return gr_draw_or_fill_arc(argv[0], argv[1], argv[2], argv[3],
                             argv[4], argv[5], FALSE);
}

CAMLprim value caml_gr_draw_arc_nat(int vx, int vy, int vrx, int vry, int vstart, int vend)
{
  return gr_draw_or_fill_arc(vx, vy, vrx, vry, vstart, vend, FALSE);
}

CAMLprim value caml_gr_set_line_width(value vwidth)
{
        int width = Int_val(vwidth);

        gr_check_open();
		queue(qSetLineWidth, width, 0, 0, 0);
		return Val_unit;
}

CAMLprim value caml_gr_set_color(value vcolor)
{
		int color = Long_val(vcolor);

        int  r = (color & 0xFF0000) >> 16,
        g = (color & 0x00FF00) >> 8 ,
        b =  color & 0x0000FF;
		queue(qSetColor, r, g, b,0); // 0-255
        return Val_unit;
}


static value gr_draw_or_fill_arc(value vx, value vy, value vrx, value vry,
                                 value vstart, value vend, BOOL fill)
{
        int x, y, r_x, r_y, start, end;

        r_x = Int_val(vrx);
        r_y = Int_val(vry);
        if ((r_x < 0) || (r_y < 0))
                invalid_argument("draw_arc: radius must be positive");
        x     = Int_val(vx);
        y     = Int_val(vy);
        start = Int_val(vstart);
        end   = Int_val(vend);

		queue2(qArc,x, y, r_x, r_y, start, end, fill, 0);
        return Val_unit;
}

CAMLprim value caml_gr_show_bitmap(value filename,int x,int y)
{
#if 0
        AfficheBitmap(filename,grwindow.gcBitmap,x,(y));
        AfficheBitmap(filename,grwindow.gc,x,(y));
#endif
        return Val_unit;
}

CAMLprim value caml_gr_set_font(value fontname)
{
        gr_check_open();
		myfont = strdup(String_val(fontname));
        if (!DrawFont(myfont, mytextsize))
			caml_invalid_argument (myfont);
		return Val_unit;
}

CAMLprim value caml_gr_set_text_size (value sz)
{
		mytextsize = Int_val(sz);
        if (!DrawFont(myfont, mytextsize))
			caml_invalid_argument (myfont);
		return Val_unit;
}

CAMLprim value caml_gr_draw_char(value chr)
{
	char str[1] = {Int_val(chr)};
	gr_check_open();
	DrawText(str, 1, grwindow.grx, grwindow.gry, mytextsize);
	return Val_unit;
}

CAMLprim value caml_gr_draw_string(value str)
{
	int len = string_length(str);
	char *str1 = String_val(str);
	DrawText(str1, len, grwindow.grx, grwindow.gry, mytextsize);
	return Val_unit;
}

CAMLprim value caml_gr_text_size(value str)
{
        int cx, cy;
        value res;

        mlsize_t len = string_length(str);
        if (len > 32767) len = 32767;

//        GetTextExtentPoint(grwindow.gc,String_val(str), len,&extent);

		cx = 1;
		cy = 1;
        res = alloc_tuple(2);
        Field(res, 0) = Val_long(cx);
        Field(res, 1) = Val_long(cy);

        return res;
}

CAMLprim value caml_gr_fill_poly(value vect)
{
        int n_points, i;
        n_points = Wosize_val(vect);
        if (n_points < 3)
                gr_fail("fill_poly: not enough points",0);
	
		CGPoint *myvertices = calloc(n_points, sizeof(CGPoint));
        for( i = 0; i < n_points; i++ ){
                myvertices[i].x = Int_val(Field(Field(vect,i),0));
                myvertices[i].y = (Int_val(Field(Field(vect,i),1)));
        }
		queue(qShape, (long)myvertices, n_points, 0, 0);
        return Val_unit;
}

CAMLprim value caml_gr_fill_arc(value *argv, int argc)
{
  return gr_draw_or_fill_arc(argv[0], argv[1], argv[2], argv[3],
                             argv[4], argv[5], TRUE);
}

CAMLprim value caml_gr_fill_arc_nat(int vx, int vy, int vrx, int vry, int vstart, int vend)
{
  return gr_draw_or_fill_arc(vx, vy, vrx, vry, vstart, vend, TRUE);
}

// Image primitives
struct image {
        int w;
        int h;
        void * data;
        void * mask;
};

#define Width(i) (((struct image *)Data_custom_val(i))->w)
#define Height(i) (((struct image *)Data_custom_val(i))->h)
#define Data(i) (((struct image *)Data_custom_val(i))->data)
#define Mask(i) (((struct image *)Data_custom_val(i))->mask)
#define Max_image_mem 500000
#if 1
static void finalize_image (value i)
{
        free (Data(i));
        if (Mask(i) != NULL) free(Mask(i));
}
static struct custom_operations image_ops = {
        "_image",
        finalize_image,
        custom_compare_default,
        custom_hash_default,
        custom_serialize_default,
        custom_deserialize_default
};

CAMLprim value caml_gr_create_image(value vw, value vh)
{
        void * cbm;
        value res;
        int w = Int_val(vw);
        int h = Int_val(vh);

        if (w < 0 || h < 0)
                gr_fail("create_image: width and height must be positive",0);

        res = alloc_custom(&image_ops, sizeof(struct image),
                w * h, Max_image_mem);
        if (res) {
                Width (res) = w;
                Height (res) = h;
                Data (res) = cbm;
                Mask (res) = NULL;
        }
        return res;
}
#endif

CAMLprim value caml_gr_blit_image (value i, value x, value y)
{
        int xsrc = Int_val(x);
        int ysrc = (Int_val(y) + Height(i) - 1);
        return Val_unit;
}


CAMLprim value caml_gr_draw_image(value i, value x, value y)
{
        void * oldBmp;

        int xdst = Int_val(x);
        int ydst = (Int_val(y)+Height(i)-1);
        return Val_unit;
}

static value alloc_int_vect(mlsize_t size)
{
        value res;
        mlsize_t i;

        if (size == 0) return Atom(0);
        if (size <= Max_young_wosize) {
                res = alloc(size, 0);
        }
        else {
                res = alloc_shr(size, 0);
        }
        for (i = 0; i < size; i++) {
                Field(res, i) = Val_long(0);
        }
        return res;
}

CAMLprim value caml_gr_dump_image (value img)
{
        int height = Height(img);
        int width = Width(img);
        value matrix = Val_unit;
        int i, j;
//        void * oldBmp;

        Begin_roots2(img, matrix)
                matrix = alloc_int_vect (height);
        for (i = 0; i < height; i++) {
                modify (&Field (matrix, i), alloc_int_vect (width));
        }
        End_roots();

//        oldBmp = SelectObject(grwindow.tempDC,Data(img));
        for (i = 0; i < height; i++) {
                for (j = 0; j < width; j++) {
                        int col = MyGetPixel(j, i);
                        int blue = (col >> 16) & 0xFF;
                        int green = (col >> 8) & 0xFF;
                        int red = col & 0xFF;
                        Field(Field(matrix, i), j) = Val_long((red << 16) +
                                        (green << 8) + blue);
                }
        }
//        SelectObject(grwindow.tempDC,oldBmp);
        if (Mask(img) != NULL) {
//                oldBmp = SelectObject(grwindow.tempDC,Mask(img));
                for (i = 0; i < height; i++) {
                        for (j = 0; j < width; j++) {
                                if (MyGetPixel(j, i) != 0)
                                        Field(Field(matrix, i), j) =
                                                Val_long(-1);
                        }
                }
//                SelectObject(grwindow.tempDC,oldBmp);
        }
        return matrix;
}
