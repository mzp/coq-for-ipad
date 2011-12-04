//
// drawing primitives test
// a cocos2d example
// http://www.cocos2d-iphone.org
//

// cocos import
#import "cocos2d.h"

//enum {width = 81, height = 25};

// local import
#import "drawPrimitivesNew.h"
#include <unistd.h>

#include <assert.h>
#include <pthread.h>
#include <fcntl.h>
#include <dirent.h>

static int sceneIdx=-1;
static NSString *transitions[] = {
	@"Test1",
	@"Test2",
};

static char stdoutbuf[height][width];
static int row, col;

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static void render_text(const char *buf, id uifont, int siz, int x, int y)
{
	NSStringEncoding enc = NSUTF8StringEncoding;
	NSString *conv = [NSString stringWithCString:buf encoding:enc];
	if (uifont)
	{
		CGSize dimensions = [conv sizeWithFont:uifont];		
		//	return [self initWithString:string dimensions:dim alignment:CCTextAlignmentCenter fontName:fnt fontSize:size];
		//	CCTexture2D *texture = [[CCTexture2D alloc] initWithString:conv dimensions:dim alignment:UITextAlignmentLeft fontName:fnt fontSize:siz];
		NSUInteger width = ccNextPOT(dimensions.width);
		NSUInteger height = ccNextPOT(dimensions.height);
		
		CGColorSpaceRef	colorSpace = CGColorSpaceCreateDeviceGray();
		unsigned char *data = calloc(height, width);
		CGContextRef context = CGBitmapContextCreate(data, width, height, 8, width, colorSpace, kCGImageAlphaNone);
		
		if( context )
		{
			CGColorSpaceRelease(colorSpace);
			
			CGContextSetGrayFillColor(context, 1.0f, 1.0f);
			CGContextTranslateCTM(context, 0.0f, height);
			CGContextScaleCTM(context, 1.0f, -1.0f); //NOTE: NSString draws in UIKit referential i.e. renders upside-down compared to CGBitmapContext referential
			
			UIGraphicsPushContext(context);
			
			[conv drawInRect:CGRectMake(0, 0, dimensions.width, dimensions.height) withFont:uifont lineBreakMode:UILineBreakModeWordWrap alignment:UITextAlignmentLeft];
			
			UIGraphicsPopContext();
			
			CCTexture2D *texture = [[CCTexture2D alloc] initWithData:data pixelFormat:kCCTexture2DPixelFormat_A8 pixelsWide:width pixelsHigh:height contentSize:dimensions];
			
			// Default GL states: GL_TEXTURE_2D, GL_VERTEX_ARRAY, GL_COLOR_ARRAY, GL_TEXTURE_COORD_ARRAY
			// Needed states: GL_TEXTURE_2D, GL_VERTEX_ARRAY, GL_TEXTURE_COORD_ARRAY
			// Unneeded states: GL_COLOR_ARRAY
			glDisableClientState(GL_COLOR_ARRAY);
			
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			
			// glColor4ub(224,224,244,200);
			[texture drawAtPoint: ccp(x,y)];
			[texture release];
			
			glBlendFunc(CC_BLEND_SRC, CC_BLEND_DST);
			
			// restore default GL state
			glEnableClientState(GL_COLOR_ARRAY);
			CGContextRelease(context);
		}
		free(data);
	}
}

Class nextAction()
{
	
	sceneIdx++;
	sceneIdx = sceneIdx % ( sizeof(transitions) / sizeof(transitions[0]) );
	NSString *r = transitions[sceneIdx];
	Class c = NSClassFromString(r);
	return c;
}

Class backAction()
{
	sceneIdx--;
	int total = ( sizeof(transitions) / sizeof(transitions[0]) );
	if( sceneIdx < 0 )
		sceneIdx += total;	
	
	NSString *r = transitions[sceneIdx];
	Class c = NSClassFromString(r);
	return c;
}

Class restartAction()
{
	NSString *r = transitions[sceneIdx];
	Class c = NSClassFromString(r);
	return c;
}

#pragma mark -
#pragma mark Base Class

@implementation TestDemo

+(id) scene
{
	// 'scene' is an autorelease object.
	CCScene *scene = [CCScene node];

	[scene addChild: [nextAction() node]];
	
//	[[CCDirector sharedDirector] runWithScene: scene];
		
	// return the scene
	return scene;
}

static int gr_open_flag = 0, gr_close_flag = 0;

-(void) update: (ccTime) dt
{
	if (gr_open_flag)
	{
		gr_open_flag = 0;
		sceneIdx=1;
		CCScene *s = [CCScene node];
		[s addChild: [restartAction() node]];	
		
		[[CCDirector sharedDirector] replaceScene: s];
	}
	else if (gr_close_flag)
	{
		gr_close_flag = 0;
		sceneIdx=0;
		CCScene *s = [CCScene node];
		[s addChild: [restartAction() node]];	
		
		[[CCDirector sharedDirector] replaceScene: s];
	}
	else {
		CGSize s = [[CCDirector sharedDirector] winSize];
		menu.position = CGPointMake(s.width-150, s.height-30 );
		[label setPosition: ccp(s.width-150, s.height-70)];
	}

}

void gr_open(void)
{
	gr_open_flag = 1;
}

void gr_close(void)
{
	gr_close_flag = 1;
}

-(id) init
{
	if( (self=[super init]) ) {
			
 		label = [CCLabelTTF labelWithString:[self title] fontName:@"Arial" fontSize:32];
		[self addChild: label];

		CCMenuItemImage *item1 = [CCMenuItemImage itemFromNormalImage:@"b1.png" selectedImage:@"b2.png" target:self selector:@selector(backCallback:)];
		CCMenuItemImage *item2 = [CCMenuItemImage itemFromNormalImage:@"r1.png" selectedImage:@"r2.png" target:self selector:@selector(restartCallback:)];
		CCMenuItemImage *item3 = [CCMenuItemImage itemFromNormalImage:@"f1.png" selectedImage:@"f2.png" target:self selector:@selector(nextCallback:)];
		
		menu = [CCMenu menuWithItems:item1, item2, item3, nil];

		// menu.position = CGPointMake(s.width/2, 380 );
		item1.position = ccp( -100, 0 );
		item2.position = ccp( 0, 0 );
		item3.position = ccp( 100, 0 );

		[self addChild: menu z:-1];	

		// update after action in run!
		[self scheduleUpdateWithPriority:1];
//		[[CCScheduler sharedScheduler] scheduleUpdateForTarget:self priority:0 paused:NO];
	}

	return self;
}

-(void) dealloc
{
	[super dealloc];
}

#define Val_long(x)     (((long)(x) << 1) + 1)

long caml_gr_size_x(void)
{
	CGSize s = [[CCDirector sharedDirector] winSize];
	gr_check_open();
	return Val_long(s.width);
}

long caml_gr_size_y(void)
{
	CGSize s = [[CCDirector sharedDirector] winSize];
	gr_check_open();
	return Val_long(s.height);
}

-(void) newOrientation
{
#ifdef __IPHONE_OS_VERSION_MAX_ALLOWED
	ccDeviceOrientation orientation = [[CCDirector sharedDirector] deviceOrientation];
	switch (orientation) {
		case CCDeviceOrientationLandscapeLeft:
			orientation = CCDeviceOrientationPortrait;
			break;
		case CCDeviceOrientationPortrait:
			orientation = CCDeviceOrientationLandscapeRight;
			break;						
		case CCDeviceOrientationLandscapeRight:
			orientation = CCDeviceOrientationPortraitUpsideDown;
			break;
		case CCDeviceOrientationPortraitUpsideDown:
			orientation = CCDeviceOrientationLandscapeLeft;
			break;
	}
	[[CCDirector sharedDirector] setDeviceOrientation:orientation];
#endif // iPhone
}

-(void) restartCallback: (id) sender
{
//	[self newOrientation];
	CCScene *s = [CCScene node];
	[s addChild: [restartAction() node]];	

	[[CCDirector sharedDirector] replaceScene: s];
}

-(void) nextCallback: (id) sender
{
//	[self newOrientation];

	CCScene *s = [CCScene node];
	[s addChild: [nextAction() node]];
	[[CCDirector sharedDirector] replaceScene: s];
}

-(void) backCallback: (id) sender
{
//	[self newOrientation];

	CCScene *s = [CCScene node];
	[s addChild: [backAction() node]];
	[[CCDirector sharedDirector] replaceScene: s];
}

-(NSString*) title
{
	return @"No title";
}

@end

#pragma mark -
#pragma mark Drawing Primitives Test 1

@implementation Test1
//
// TIP:
// Every CocosNode has a "draw" method.
// In the "draw" method you put all the code that actually draws your node.
// And Test1 is a subclass of TestDemo, which is a subclass of Layer, which is a subclass of CocosNode.
//
// As you can see the drawing primitives aren't CocosNode objects. They are just helper
// functions that let's you draw basic things like: points, line, polygons and circles.
//
//
// TIP:
// Don't draw your stuff outide the "draw" method. Otherwise it wont get transformed.
//
//
// TIP:
// If you want to rotate/translate/scale a circle or any other "primtive", you can do it by rotating
// the node. eg:
//    self.rotation = 90;
//
-(void) draw
{
	CGSize s = [[CCDirector sharedDirector] winSize];
		
	// draw a simple line
	// The default state is:
	// Line Width: 1
	// color: 255,255,255,255 (white, non-transparent)
	// Anti-Aliased
	glEnable(GL_LINE_SMOOTH);
	ccDrawLine( ccp(0, 300), ccp(s.width, 300) );
	int siz = 16;
	id fnt = [UIFont fontWithName:@"Arial" size:siz];
	for (int idx = 0; idx < height; idx++)
	{
		const char *buf = sceneIdx ? "":stdoutbuf[idx];
		stdoutbuf[idx][width-1] = 0;
		int x = s.width/20;
		int y = s.height-100-idx*20;
		render_text(buf, fnt, siz, x, y);
	}
	
	// restore original values
	glLineWidth(1);
	glColor4ub(255,255,255,255);
	glPointSize(1);
}
-(NSString *) title
{
	return @"OCAML console";
}
@end

// enum {maxq = 65536};

void *keyboard;

typedef struct func_t {
	enum geom func;
	long arg1,arg2,arg3,arg4;
	struct func_t *nxt;
} func_t;

static func_t *myqueue = NULL;
static id uifont = 0;
static int fontsiz = 16;

@implementation Test2
//
// TIP:
// Every CocosNode has a "draw" method.
// In the "draw" method you put all the code that actually draws your node.
// And Test1 is a subclass of TestDemo, which is a subclass of Layer, which is a subclass of CocosNode.
//
// As you can see the drawing primitives aren't CocosNode objects. They are just helper
// functions that let's you draw basic things like: points, line, polygons and circles.
//
//
// TIP:
// Don't draw your stuff outide the "draw" method. Otherwise it wont get transformed.
//
//
// TIP:
// If you want to rotate/translate/scale a circle or any other "primitive", you can do it by rotating
// the node. eg:
//    self.rotation = 90;
//

void draw_exec(func_t *ptr)
	{
		switch (ptr->func) {
				case qRect:
				{
					CGPoint vertices[] = { ccp(ptr->arg1,ptr->arg2),
											ccp(ptr->arg1,ptr->arg2+ptr->arg4),
											ccp(ptr->arg1+ptr->arg3,ptr->arg2+ptr->arg4),
											ccp(ptr->arg1+ptr->arg3,ptr->arg2),
											ccp(ptr->arg1,ptr->arg2) };
					ccDrawPoly( vertices, 5, NO);
					ptr = ptr->nxt;
					break;
				}
				case qLine:
					glEnable(GL_LINE_SMOOTH);
					ccDrawLine( ccp(ptr->arg1, ptr->arg2), ccp(ptr->arg3, ptr->arg4) );
					ptr = ptr->nxt;
					break;
				case qSetColor:
					glColor4ub(ptr->arg1, ptr->arg2, ptr->arg3, 255);
					ptr = ptr->nxt;
					break;
				case qSetLineWidth:
					glLineWidth(ptr->arg1);
					ptr = ptr->nxt;
					break;
			case qArc:
			{
				float rad = sqrt(ptr->arg3*ptr->arg3 + ptr->arg4*ptr->arg4); 
				float ang = M_PI*2;
				int segments = 100;
				ccDrawCircle(ccp(ptr->arg1,ptr->arg2), rad, ang, segments, false);
				ptr = ptr->nxt;
				break;
			}
			case qCurve:
				ccDrawCubicBezier(ccp(ptr->arg1, ptr->arg2), ccp(ptr->arg3, ptr->arg4), ccp(ptr[1].arg1, ptr[1].arg2), ccp(ptr[1].arg3, ptr[1].arg4), 100);
				ptr = ptr->nxt;
				break;
			case qFill:
				{
					CGPoint vertices[] = { ccp(ptr->arg1,ptr->arg2),
						ccp(ptr->arg1,ptr->arg2+ptr->arg4),
						ccp(ptr->arg1+ptr->arg3,ptr->arg2+ptr->arg4),
						ccp(ptr->arg1+ptr->arg3,ptr->arg2),
						ccp(ptr->arg1,ptr->arg2) };
					ccDrawPoly( vertices, 5, YES);
					ptr = ptr->nxt;
					break;
				}
				case qShape:
				{
					ccDrawPoly( (CGPoint *)(ptr->arg1), ptr->arg2, NO);
					ptr = ptr->nxt;
					break;
				}
				case qText:
					render_text((const char *)(ptr->arg1), uifont, ptr->arg2, ptr->arg3, ptr->arg4);
					ptr = ptr->nxt;
					break;
				case qSetFont:
					uifont = (id)(ptr->arg1);
					fontsiz = ptr->arg2;
					ptr = ptr->nxt;
					break;
				default:
				{
					enum geom unknown = ptr->func;
					printf("Unknown geom %d\n", unknown);
					ptr = 0;
					break;
				}
			}
		}

void draw_recurse(func_t *ptr)
{
	if (ptr->nxt) draw_recurse(ptr->nxt);
	draw_exec(ptr);
}

-(void) draw
{
	fontsiz = 16;
	uifont = [UIFont fontWithName:@"Arial" size:fontsiz];
	my_mutex_lock(&mut);
	if (myqueue) draw_recurse(myqueue);
	my_mutex_unlock(&mut);
	// restore original values
	glLineWidth(1);
	glColor4ub(255,255,255,255);
	glPointSize(1);
}

-(NSString *) title
{
	return @"OCAML Graphics";
}
@end

char removefrombuf(void)
{
	if (tail != head)
	{
		char tmp = ringbuf[tail];
		tail = (tail+1)&255;
		return tmp;
	}
	else {
		return -1;
	}	
}

 int stdin_read(char *buf, int siz)
{
	char ch;
	int cnt = 0;
	do {
		do {
			my_mutex_lock(&mut);
			ch = removefrombuf();
			my_mutex_unlock(&mut);
			if (ch == -1)
				pthread_cond_wait(&cond, &mut);
		}
		while (ch == -1);
		if (ch)
			buf[cnt++] = ch;
		else {
			if (cnt) --cnt;;
		}
		
		stdout_write(&ch, 1);
	} while ((cnt < siz) && (ch != '\n'));
	return cnt;
}

int myselect(void)
{
	char ch;
	int cnt = 0;
		do {
			my_mutex_lock(&mut);
			ch = removefrombuf();
			my_mutex_unlock(&mut);
			if (ch == -1)
				mysleep();
		}
		while (ch == -1);
	return ch;
}

int mysleep(void)
{
	pthread_cond_wait(&cond, &mut);
}

void my_mutex_lock(pthread_mutex_t *p)
{
	
}

void my_mutex_unlock(pthread_mutex_t *p)
{
	
}

void* PosixThreadMainRoutine(void* data)
{
	const char *init = "ocamlinit";
	memset(stdoutbuf, ' ', sizeof stdoutbuf);
	const char *ocaml = fullp(@"ocaml-3.12.0/bin/ocaml");
	const char *ocamlinit = fullp(@"ocaml-3.12.0/ocamlinit");
	const char *ocamlinclude = fullp(@"ocaml-3.12.0");
	if (access(init,R_OK))
	{
		init = ocamlinit;
		if (access(init,R_OK))
		{
			const char *argv[] = {"ocamlrun", ocaml, "-I", ocamlinclude, NULL};
			ocaml_main(4,argv);
		}
		else 
		{
			const char *argv[] = {"ocamlrun", ocaml, "-I", ocamlinclude, "-init", init, NULL};
			ocaml_main(6,argv);
		}
	}	
	else 
	{
		const char *argv[] = {"ocamlrun", ocaml, "-I", ocamlinclude, "-init", init, NULL};
		ocaml_main(6,argv);
	}
	free((char *)ocaml);
	free((char *)ocamlinit);
	free((char *)ocamlinclude);
	return NULL;
}

void LaunchThread()
{
    // Create the thread using POSIX routines.
    pthread_attr_t  attr;
    pthread_t       posixThreadID;
    int             returnVal;
	
    returnVal = pthread_attr_init(&attr);
    assert(!returnVal);
    returnVal = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    assert(!returnVal);
	
    int     threadError = pthread_create(&posixThreadID, &attr, &PosixThreadMainRoutine, NULL);
	
    returnVal = pthread_attr_destroy(&attr);
    assert(!returnVal);
    if (threadError != 0)
    {
		// Report an error.
    }
}

//static int first;
#if 0
//--------------------------------------------------------------
void testApp_setup()
{	
	read_fonts();
	
	for (int i = 0; i < sizeof(keyboards)/sizeof(*keyboards); i++)
	{
		keyboards[i] = NULL;
		keyboard = *keyboards;
		deviceOrientationChanged(i);
	}
	deviceOrientationChanged(UIDeviceOrientationPortrait);
	
	memset(stdoutbuf, ' ', sizeof stdoutbuf);
	
	LaunchThread();
}
#endif
void stdout_puts(const char *buf)
{
	stdout_write(buf, strlen(buf));
}

void wakethread()
{
//	my_mutex_lock(&mut);
	pthread_cond_broadcast(&cond);
//	my_mutex_unlock(&mut);
}

int stdout_write(const char *buf, int len)
{
	const char *bufend = buf+len;
	unsigned arg[20];
	int Line, Column, Mode, Seq;
	my_mutex_lock(&mut);
	while (buf<bufend) {
		switch (*buf) {
			default:
				stdoutbuf[row][col++] = *buf;
				if (col < width-1) break;
				col = 0;
			case '\n':
				if (++row == height)
				{
					for (row = 0; row < height-1; row++)
						memcpy(stdoutbuf[row], stdoutbuf[row+1], width);
					memset(stdoutbuf[row], ' ', width);
				}
			case '\r':
				col = 0;
				break;
			case '\e':
			{
				int cnt;
				switch(*++buf)
				{
					case '[':
						for (cnt = 0; cnt < sizeof(arg)/sizeof(*arg); cnt++)
							arg[cnt] = 0;
						cnt = 0;
						do {
							++buf;
							arg[cnt] = 0;
							while (isdigit(*buf))
								arg[cnt] = arg[cnt]*10 + *buf++ - '0';
							++cnt;
						} while(*buf == ';');
						switch (*buf)
					{
						case 'C':
							col += arg[0];
							if (col >= width)
								col = width-1;
							break;
						case 'H':
							row = arg[0];
							col = arg[1];
							break;
						case 'J': if (arg[0]==2)
						{
							for (Column = 0; Column < width; Column++)
								for (Line = 0; Line < height; Line++)
									stdoutbuf[Line][Column] = ' ';
							row = 0;
							col = 0;
						}
							break;
						case 'm':
							Mode = arg[0];
							break;
						default:
							Seq = *buf;
					}
						break;
					default:
						Seq = *buf;
				}
			}
				break;
		}
		++buf;
	}
	my_mutex_unlock(&mut);
	//	pthread_cond_wait(&cond, &mut);
	return len;
}

 int bas_read(int fd, char *buf, int len)
{
	if (fd!=fileno(stdin))
		return read(fd, buf, len);
	else 
		return stdin_read(buf, len);
}

 int bas_write(int fd, char *buf, int len)
{
	if (fd!=fileno(stdout))
		return write(fd, buf, len);
	else 
	{
		stdout_write(buf, len);	
		return len;
	}
}
#if 0
 int bas_open(char *name, int flags, int mode)
{
	const char *path = getPwd;
	string combined = string(path) + "/" + name;
	const char *combined_c = combined.c_str();
	return open(combined_c, flags, mode);
}
#endif

void qReset(void)
{
	my_mutex_lock(&mut);
	while (myqueue) {
		func_t *newqptr = myqueue->nxt;
		free(myqueue);
		myqueue = newqptr;
	}
	my_mutex_unlock(&mut);
}

void queue(enum geom func, long arg1, long arg2, long arg3, long arg4)
{
	func_t *newqptr = calloc(1, sizeof (func_t));
	my_mutex_lock(&mut);
	newqptr->func = func;
	newqptr->arg1 = arg1;
	newqptr->arg2 = arg2;
	newqptr->arg3 = arg3;
	newqptr->arg4 = arg4;	
	newqptr->nxt = myqueue;
	myqueue = newqptr;
	my_mutex_unlock(&mut);
}

void queue2(enum geom func, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6, long arg7, long arg8)
{
	func_t *newqptr = calloc(2, sizeof (func_t));
	my_mutex_lock(&mut);
	newqptr[0].func = func;
	newqptr[0].arg1 = arg1;
	newqptr[0].arg2 = arg2;
	newqptr[0].arg3 = arg3;
	newqptr[0].arg4 = arg4;	
	newqptr[0].nxt = myqueue;
	newqptr[1].func = func;
	newqptr[1].arg1 = arg5;
	newqptr[1].arg2 = arg6;
	newqptr[1].arg3 = arg7;
	newqptr[1].arg4 = arg8;	
	newqptr[1].nxt = myqueue;
	myqueue = newqptr;
	my_mutex_unlock(&mut);
}

void DrawText(const char *str, int len, int x, int y, int siz)
{
	func_t *newqptr = calloc(1, sizeof (func_t));
	my_mutex_lock(&mut);
	newqptr->func = qText;
	newqptr->arg1 = (long)strdup(str);
	newqptr->arg2 = siz;
	newqptr->arg3 = x;
	newqptr->arg4 = y;	
	newqptr->nxt = myqueue;
	myqueue = newqptr;
	my_mutex_unlock(&mut);
}

int DrawFont(const char *font, int siz)
{
	NSStringEncoding enc = NSUTF8StringEncoding;
	NSString *fnt = [NSString stringWithCString:font encoding:enc];
	id uifont = [UIFont fontWithName:fnt size:siz];
	if (uifont)
	{
		queue(qSetFont, (long)(void *)uifont, siz, 0, 0);
		return 1;
	}
	else
		return 0;
}
