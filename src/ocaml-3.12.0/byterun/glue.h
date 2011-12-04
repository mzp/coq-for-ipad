/*
 *  glue.h
 *  OcamlExample
 *
 *  Created by Jonathan Kimmitt on 17/09/2010.
 *  Copyright 2010 OMSI Limited. All rights reserved.
 *
 */

#include <pthread.h>

#define NoEventMask                     0L
#define KeyPressMask                    (1L<<0)  
#define KeyReleaseMask                  (1L<<1)  
#define ButtonPressMask                 (1L<<2)  
#define ButtonReleaseMask               (1L<<3)  
#define EnterWindowMask                 (1L<<4)  
#define LeaveWindowMask                 (1L<<5)  
#define PointerMotionMask               (1L<<6)  
#define PointerMotionHintMask           (1L<<7)  
#define Button1MotionMask               (1L<<8)  
#define Button2MotionMask               (1L<<9)  
#define Button3MotionMask               (1L<<10) 
#define Button4MotionMask               (1L<<11) 
#define Button5MotionMask               (1L<<12) 
#define ButtonMotionMask                (1L<<13) 
#define KeymapStateMask                 (1L<<14)
#define ExposureMask                    (1L<<15) 
#define VisibilityChangeMask            (1L<<16) 
#define StructureNotifyMask             (1L<<17) 
#define ResizeRedirectMask              (1L<<18) 
#define SubstructureNotifyMask          (1L<<19) 
#define SubstructureRedirectMask        (1L<<20) 
#define FocusChangeMask                 (1L<<21) 
#define PropertyChangeMask              (1L<<22) 
#define ColormapChangeMask              (1L<<23) 
#define OwnerGrabButtonMask             (1L<<24) 

#define KeyPress                2
#define KeyRelease              3
#define ButtonPress             4
#define ButtonRelease           5
#define MotionNotify            6
#define EnterNotify             7
#define LeaveNotify             8
#define FocusIn                 9
#define FocusOut                10
#define KeymapNotify            11
#define Expose                  12
#define GraphicsExpose          13
#define NoExpose                14
#define VisibilityNotify        15
#define CreateNotify            16
#define DestroyNotify           17
#define UnmapNotify             18
#define MapNotify               19
#define MapRequest              20
#define ReparentNotify          21
#define ConfigureNotify         22
#define ConfigureRequest        23
#define GravityNotify           24
#define ResizeRequest           25
#define CirculateNotify         26
#define CirculateRequest        27
#define PropertyNotify          28
#define SelectionClear          29
#define SelectionRequest        30
#define SelectionNotify         31
#define ColormapNotify          32
#define ClientMessage           33
#define MappingNotify           34
#define GenericEvent            35

#define BUTTON_STATE(state) \
((state) & (Button1Mask|Button2Mask|Button3Mask|Button4Mask|Button5Mask))

extern pthread_mutex_t mut;
extern pthread_cond_t cond;

extern char *pwd;
extern char *pwd2;
extern char *window_title;

#define getPwd() pwd
#define getPwd2() pwd2

void my_mutex_lock(pthread_mutex_t *);
void my_mutex_unlock(pthread_mutex_t *);

extern void LaunchThread(void);
extern void wakethread(void);
extern void gr_open(void);
extern void gr_close(void);
extern int DrawFont(const char *, int);

extern void DrawText(const char *str, int len, int x, int y, int siz);
// extern void render_text(const char *buf, void *uifont, int siz, int x, int y);

#define Nothing ((value) 0)
	
	enum geom {qUndefined,qTriangle,qCircle,qEllipse,qLine,qRect,qCurve,qBezier,qSetLineWidth,
		qSetColor,qShape,qFill,qSetFont,qText,qArc};
	
    extern void qReset(void);
    extern void queue(enum geom func, long arg1, long arg2, long arg3, long arg4);
	extern void queue2(enum geom func, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6, long arg7, long arg8);
	extern long unix_error_of_code (int errcode);
	extern void unix_error (int errcode, char * cmdname, long arg) __attribute__ ((noreturn));
	extern void uerror (char * cmdname, long arg) __attribute__ ((noreturn));	

typedef struct camlsyms {
		const char *sym;
		void (*ref);
	} camlsyms;
	
	extern struct camlsyms nat_camlsyms[];
	extern struct camlsyms str_camlsyms[];
	extern struct camlsyms graph_camlsyms[];
	extern struct camlsyms unix_camlsyms[];
	extern struct camlsyms dbm_camlsyms[];
	extern struct camlsyms bigarray_camlsyms[];
	extern struct camlsyms thread_camlsyms[];
	extern struct camlsyms systhread_camlsyms[];

	int ocaml_main(int argc, const char **argv);
	int stdin_read(char *buf, int siz);
	int stdout_write(const char *buf, int len);
	int bas_read(int fd, char *buf, int len);
	int bas_write(int fd, char *buf, int len);
	int bas_open(char *name, int flags, int mode);
	
	int of_font(const char *name);
	
	char *					_ctext;
	int						head, tail;
	char 					ringbuf[256];
