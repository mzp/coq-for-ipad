/***********************************************************************/
/*                                                                     */
/*                           Objective Caml                            */
/*                                                                     */
/*            Xavier Leroy, projet Cristal, INRIA Rocquencourt         */
/*                                                                     */
/*  Copyright 2004 Institut National de Recherche en Informatique et   */
/*  en Automatique.  All rights reserved.  This file is distributed    */
/*  under the terms of the GNU Library General Public License, with    */
/*  the special exception on linking described in file ../../LICENSE.  */
/*                                                                     */
/***********************************************************************/

/* $Id: events.c 6553 2004-07-13 12:25:21Z xleroy $ */

#include "../../byterun/custom.h"
#include "../../byterun/mlvalues.h"
#include "../../byterun/alloc.h"
#include "../../byterun/memory.h"
#include "../../byterun/fail.h"
#include "graphstubs.h"
#include "../../byterun/glue.h"

enum {
  EVENT_BUTTON_DOWN = 1,
  EVENT_BUTTON_UP = 2,
  EVENT_KEY_PRESSED = 4,
  EVENT_MOUSE_MOTION = 8
};

struct event_data {
  short mouse_x, mouse_y;
  unsigned char kind;
  unsigned char button;
  unsigned char key;
};

#define SIZE_QUEUE 256

static struct event_data caml_gr_queue[SIZE_QUEUE];
static unsigned int caml_gr_head = 0;       /* position of next read */
static unsigned int caml_gr_tail = 0;       /* position of next write */
static int last_mouse_x, last_mouse_y;

CAMLprim value caml_gr_get_mousex(void)
{
	return last_mouse_x;
}

CAMLprim value caml_gr_get_mousey(void)
{
	return last_mouse_y;
}


#define QueueIsEmpty (caml_gr_tail == caml_gr_head)

void caml_gr_enqueue_event(int kind, int mouse_x, int mouse_y,
								  int button, int key)
{
	struct event_data * ev;
	last_mouse_x = mouse_x;
	last_mouse_y = mouse_y;
	
//	my_mutex_lock(&mut);	
	ev = &(caml_gr_queue[caml_gr_tail]);
	ev->kind = kind;
	ev->mouse_x = mouse_x;
	ev->mouse_y = mouse_y;
	ev->button = (button != 0);
	ev->key = key;
	caml_gr_tail = (caml_gr_tail + 1) % SIZE_QUEUE;
	/* If queue was full, it now appears empty; drop oldest entry from queue. */
	if (QueueIsEmpty) caml_gr_head = (caml_gr_head + 1) % SIZE_QUEUE;
//	my_mutex_unlock(&mut);
	wakethread();
}

enum {False, True};

long caml_gr_selected_events;

static value caml_gr_wait_allocate_result(int mouse_x, int mouse_y, int button,
										  int keypressed, int key)
{
	value res = alloc_small(5, 0);
	Field(res, 0) = Val_int(mouse_x);
	Field(res, 1) = Val_int(mouse_y == -1 ? -1 : (mouse_y));
	Field(res, 2) = Val_bool(button);
	Field(res, 3) = Val_bool(keypressed);
	Field(res, 4) = Val_int(key & 0xFF);
	return res;
}

value caml_gr_wait_event_poll(void)
{
	int mouse_x, mouse_y, button, key, keypressed;
	int root_x, root_y, win_x, win_y;
	unsigned int modifiers;
	unsigned int i;
	
		mouse_x = win_x;
		mouse_y = win_y;

	/* Look inside event queue for pending KeyPress events */
	key = 0;
	keypressed = False;
	my_mutex_lock(&mut);
	for (i = caml_gr_head; i != caml_gr_tail; i = (i + 1) % SIZE_QUEUE) {
		if (caml_gr_queue[i].kind == KeyPress) {
			keypressed = True;
			key = caml_gr_queue[i].key;
			break;
		}
	}
	my_mutex_unlock(&mut);
	return caml_gr_wait_allocate_result(mouse_x, mouse_y, button, keypressed, key);
}

static value caml_gr_wait_event_in_queue(long mask)
{
	struct event_data * ev;
	/* Pop events in queue until one matches mask. */
	my_mutex_lock(&mut);
	while (caml_gr_head != caml_gr_tail) {
		ev = &(caml_gr_queue[caml_gr_head]);
		caml_gr_head = (caml_gr_head + 1) % SIZE_QUEUE;
		if ((ev->kind == KeyPress && (mask & KeyPressMask))
			|| (ev->kind == ButtonPress && (mask & ButtonPressMask))
			|| (ev->kind == ButtonRelease && (mask & ButtonReleaseMask))
			|| (ev->kind == MotionNotify && (mask & PointerMotionMask)))
		{
			my_mutex_unlock(&mut);
			return caml_gr_wait_allocate_result(ev->mouse_x, ev->mouse_y,
												ev->button, ev->kind == KeyPress,
												ev->key);
		}
	}
	my_mutex_unlock(&mut);
	return Val_false;
}

value caml_gr_wait_event_blocking(long mask)
{
	value res;
	do {
		/* First see if we have a matching event in the queue */
		res = caml_gr_wait_event_in_queue(mask);
		if (res == Val_false)
		{
			/* Increase the selected events if required */
			if ((mask & ~caml_gr_selected_events) != 0) {
				caml_gr_selected_events |= mask;
			}
			mysleep();
		}
	} while (res == Val_false);
	return res;
}

CAMLprim value caml_gr_wait_event(value eventlist) /* ML */
{
  int mask, poll;

  gr_check_open();
  mask = 0;
  poll = 0;
  while (eventlist != Val_int(0)) {
    switch (Int_val(Field(eventlist, 0))) {
    case 0:                     /* Button_down */
      mask |= EVENT_BUTTON_DOWN; break;
    case 1:                     /* Button_up */
      mask |= EVENT_BUTTON_UP; break;
    case 2:                     /* Key_pressed */
      mask |= EVENT_KEY_PRESSED; break;
    case 3:                     /* Mouse_motion */
      mask |= EVENT_MOUSE_MOTION; break;
    case 4:                     /* Poll */
      poll = 1; break;
    }
    eventlist = Field(eventlist, 1);
  }
  if (poll)
    return caml_gr_wait_event_poll();
  else
    return caml_gr_wait_event_blocking(mask);
}
