#include "ofBitmapFont.h"
#include "testApp.h"
#include "glue.h"

#include <assert.h>
#include <pthread.h>
#include <fcntl.h>
#include <dirent.h>

enum {width = 81, height = 50};

static char stdoutbuf[height][width];
static int row, col;
static pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

typedef struct {
	geom func;
	long arg1,arg2,arg3,arg4;
} func_t;

enum {maxq = 65536};

ofxiPhoneKeyboard *keyboard;

static func_t *qptr, myqueue[maxq+1];

int read_fonts()
{
	DIR * d;
	struct dirent * e;
	char * p;
	char * dirname = (char *)malloc(strlen(getPwd)+40);	
	sprintf(dirname, "%s/OcamlExample.app", getPwd);
	d = opendir(dirname);
	if (d == NULL) return -1;
	while (1) {
		e = readdir(d);
		if (e == NULL) break;
		if (strcmp(e->d_name, ".") == 0 || strcmp(e->d_name, "..") == 0) continue;
		p = (char *)malloc(strlen(e->d_name) + 1);
		strcpy(p, e->d_name);
		if (strstr(p, ".ttf")) ofGetAppPtr()->load_of_font(p);
	}
	closedir(d);
	free(dirname);
	return 0;
}

extern "C" int stdin_read(char *buf, int siz)
{
	char ch;
	int cnt = 0;
	do {
	do {
		pthread_mutex_lock(&mut);
		ch = keyboard->getRText();
		if (ch == -1)
			pthread_cond_wait(&cond, &mut);
		pthread_mutex_unlock(&mut);
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

void* PosixThreadMainRoutine(void* data)
{
	const char *init = "ocamlinit";
	char *ocaml = (char *)malloc(strlen(getPwd) + 40);
	char *ocamlinit = (char *)malloc(strlen(getPwd) + 40);
	char *ocamlinclude = (char *)malloc(strlen(getPwd) + 40);
	qptr = myqueue;
	sprintf(ocaml, "%s/OcamlExample.app/ocaml-3.12.0/bin/ocaml", getPwd);
	sprintf(ocamlinit, "%s/OcamlExample.app/ocaml-3.12.0/ocamlinit", getPwd);
	sprintf(ocamlinclude, "%s/OcamlExample.app/ocaml-3.12.0", getPwd);
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
	free(ocaml);
	free(ocamlinit);
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

//--------------------------------------------------------------
void testApp::setup()
{	
	// register touch events
	ofRegisterTouchEvents(this);
	// this load font loads the non-full character set
	// (ie ASCII 33-128), at size "32"
	read_fonts();
	// initialize the accelerometer
	ofxAccelerometer.setup();
	
	//iPhoneAlerts will be sent to this.
	ofxiPhoneAlerts.addListener(this);
		
	for (int i = 0; i < sizeof(keyboards)/sizeof(*keyboards); i++)
	{
		keyboards[i] = new ofxiPhoneKeyboard(0,52,320,32);
		keyboard = *keyboards;
		deviceOrientationChanged(i);
	}
	deviceOrientationChanged(UIDeviceOrientationPortrait);
	
	memset(stdoutbuf, ' ', sizeof stdoutbuf);
	
	LaunchThread();
}

int testApp::load_of_font(const char *name)
{	
	int i;
	for (i = 0; i < sizeof(myfonts)/sizeof(*myfonts); i++)
		if (myfonts[i].name && !strcmp(name, myfonts[i].name))
			return i;
	for (i = 0; i < sizeof(myfonts)/sizeof(*myfonts); i++) if (!(myfonts[i].name))	
	{
		char *ptr;
		myfonts[i].name = strdup(name);
		ptr = strchr(myfonts[i].name,'.');
		if (ptr) *ptr = 0; else return -1;
		myfonts[i].myfont.loadFont(name, 32);
		if (!myfonts[i].myfont.bLoadedOk)
			return -1;
		myfonts[i].myfont.setLineHeight(20.0);
		return i;
	}
	return -1;
}

extern "C" int of_font(const char *name)
{
	return ofGetAppPtr()->load_of_font(name);
}

//--------------------------------------------------------------
void testApp::update()
{	
	ofBackground(0,0,0);	
}

void stdout_puts(const char *buf)
{
	stdout_write(buf, strlen(buf));
}

int spacing = 14;
int offset = 8;

//--------------------------------------------------------------
void testApp::draw()
{	
	func_t *ptr = myqueue;
	int myfont = -1;
	float mytextsize = 1.0;
	int first = gr_initialized ? height-4 : 0;
	if (row < first) row = first; else if ((offset < 0)&&(row<8)) row = 8;
	ofSetColor(180, 180, 180, 255);
#ifdef NAFF_TRANSITION
	if (dly < 100)
	{
		ofTranslate((dly*orientation.x+(100-dly)*oldorient.x)/200,
					(dly*orientation.y+(100-dly)*oldorient.y)/200,
					(dly*orientation.z+(100-dly)*oldorient.z)/200);
		ofRotate((dly*orientation.r+(100-dly)*oldorient.r)/200);
	}
	else 
#endif
	{
		ofTranslate(orientation.x, orientation.y, orientation.z);
		ofRotate(orientation.r);
	}

	for (int i = first; i < height; i++)
	{
		pthread_mutex_lock(&mut);
//		stdoutbuf[i][width-1] = 0;
		for (int j = 0; j < width; j++)
			ofDrawBitmapCharacter(stdoutbuf[i][j], 2+j*8, offset+spacing*i);
//		ofDrawBitmapString(stdoutbuf[i], 2, 8+14*i);
		pthread_mutex_unlock(&mut);
	}
	if (gr_initialized) while (ptr < qptr) {
		pthread_mutex_lock(&mut);
		switch (ptr->func) {
			case qRect:
				ofNoFill();
				ofRect(ptr->arg1, ptr->arg2, ptr->arg3, ptr->arg4);
				break;
			case qLine:
				ofLine(ptr->arg1, ptr->arg2, ptr->arg3, ptr->arg4);
				break;
			case qSetColor:
				ofSetColor(ptr->arg1, ptr->arg2, ptr->arg3);
				break;
			case qDrawBitmapCharacter:
				if (myfont == -1)
					ofDrawBitmapCharacter(ptr->arg1, ptr->arg2,  ptr->arg3);
				else 
				{
					int j;
					char *str;
					func_t *ptr2 = ptr+1;
					while (ptr2->func == ptr->func) ++ptr2;
					str = (char *)malloc(ptr2-ptr+1);
					for (j = 0; j < ptr2-ptr; j++) str[j] = ptr[j].arg1;
					str[j] = 0;
					ofScale(mytextsize,mytextsize,1);
					myfonts[myfont].myfont.drawString(str, ptr->arg2/mytextsize,  ptr->arg3/mytextsize);
					ofScale(1,1,1);
					free(str);
					ptr = ptr2-1;
				}
				break;
			case qSetLineWidth:
				ofSetLineWidth(ptr->arg1);
				break;
			case qTextSize:
				mytextsize = ptr->arg1 > 5 ? ptr->arg1/32.0 : mytextsize;
				break;
			case qCurve:
				ofCurve(ptr->arg1, ptr->arg2, ptr->arg3, ptr->arg4, ptr[1].arg1, ptr[1].arg2, ptr[1].arg3, ptr[1].arg4);
				++ptr;
				break;
			case qFill:
				ofFill();
				ofRect(ptr->arg1, ptr->arg2, ptr->arg3, ptr->arg4);
				break;
			case qBeginShape:
				ofBeginShape();
				break;
			case qVertex:
				ofVertex(ptr->arg1, ptr->arg2);
				break;
			case qEndShape:
				ofEndShape();
				break;
			case qSetFont:
				myfont = ptr->arg1;
//				myfont = 0;
				break;
			default:
			{
				geom unknown = ptr->func;
				break;
			}
		}
		pthread_mutex_unlock(&mut);
		++ptr;
	}
#if 0
	if (++dly == 100)
	{
		keyboard->openKeyboard();
		keyboard->setVisible(true);
	}
	else if (dly > 100) dly = 100;
#endif
}

void testApp::wakethread()
{
	pthread_mutex_lock(&mut);
	pthread_cond_broadcast(&cond);
	pthread_mutex_unlock(&mut);
}

//--------------------------------------------------------------
void testApp::exit()
{

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs &touch)
{

}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs &touch)
{

}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs &touch)
{

}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs &touch)
{
	
}

//--------------------------------------------------------------
void testApp::lostFocus()
{

}

//--------------------------------------------------------------
void testApp::gotFocus()
{

}

//--------------------------------------------------------------
void testApp::gotMemoryWarning()
{

}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation)
{
	keyboard->setVisible(false);
	keyboard->closeKeyboard();
	keyboard = keyboards[newOrientation];
	keyboard->openKeyboard();
//	keyboard->setVisible(true);
	keyboard->setFontColor(255, 255, 255, 255);
	keyboard->setBgColor(0,0,0, 255);
//	keyboard->setPosition(0, 755);
//	keyboard->setTransform(0);
	oldorient = orientation;

	orientation.orient = (UIDeviceOrientation) newOrientation;
	switch (orientation.orient) {
		case     UIDeviceOrientationUnknown:
		case     UIDeviceOrientationPortrait:            // Device oriented vertically, home button on the bottom
		case     UIDeviceOrientationFaceUp:              // Device oriented flat, face up
		case     UIDeviceOrientationFaceDown:            // Device oriented flat, face down
			[[UIApplication sharedApplication] setStatusBarOrientation: UIInterfaceOrientationPortrait];
			orientation.x = 0;
			orientation.y = 0;
			orientation.z = 0;
			orientation.r = 0;
			keyboard->setFontSize(26);
			keyboard->setPosition(0,700);
			keyboard->setTransform(orientation.r);
			spacing=14;
			offset = 8;
			break;
		case     UIDeviceOrientationPortraitUpsideDown:  // Device oriented vertically, home button on the top
			[[UIApplication sharedApplication] setStatusBarOrientation: UIInterfaceOrientationPortraitUpsideDown];
			orientation.x = 768;
			orientation.y = 1024;
			orientation.z = 0;
			orientation.r = 180;
			keyboard->setFontSize(26);
			keyboard->setPosition(400,400-50-50);
			keyboard->setTransform(orientation.r);
			spacing=14;
			offset = 8;
			break;
		case     UIDeviceOrientationLandscapeLeft:       // Device oriented horizontally, home button on the right
			[[UIApplication sharedApplication] setStatusBarOrientation: UIInterfaceOrientationLandscapeRight];
			orientation.x = 768;
			orientation.y = 0;
			orientation.z = 0;
			orientation.r = 90;
			keyboard->setFontSize(20);
			keyboard->setPosition(200,200);
			keyboard->setTransform(orientation.r);
			spacing=12;
			offset = -200;
			break;
		case     UIDeviceOrientationLandscapeRight:      // Device oriented horizontally, home button on the left
			[[UIApplication sharedApplication] setStatusBarOrientation: UIInterfaceOrientationLandscapeLeft];
			orientation.x = 0;
			orientation.y = 1024;
			orientation.z = 0;
			orientation.r = 270;
			keyboard->setFontSize(20);
			keyboard->setPosition(300,600);
			keyboard->setTransform(orientation.r);
			spacing=12;
			offset = -200;
			break;
	}
keyboard->setVisible(true);
}

int stdout_write(const char *buf, int len)
{
	const char *bufend = buf+len;
	unsigned arg[20];
	int Line, Column, Mode, Seq;
	pthread_mutex_lock(&mut);
	while (buf<bufend) {
		switch (*buf) {
			default:
				stdoutbuf[row][col++] = *buf;
				if (col < width) break;
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
	pthread_mutex_unlock(&mut);
//	pthread_cond_wait(&cond, &mut);
	return len;
}

extern "C" int bas_read(int fd, char *buf, int len)
{
	if (fd!=fileno(stdin))
		return read(fd, buf, len);
	else 
		return stdin_read(buf, len);
}

extern "C" int bas_write(int fd, char *buf, int len)
{
	if (fd!=fileno(stdout))
		return write(fd, buf, len);
	else 
	{
		stdout_write(buf, len);	
		return len;
	}
}

extern "C" int bas_open(char *name, int flags, int mode)
{
	const char *path = getPwd;
	string combined = string(path) + "/" + name;
	const char *combined_c = combined.c_str();
	return open(combined_c, flags, mode);
}

extern "C" void queue(geom func, long arg1, long arg2, long arg3, long arg4)
{
	pthread_mutex_lock(&mut);
	qptr->func = func;
	qptr->arg1 = arg1;
	qptr->arg2 = arg2;
	qptr->arg3 = arg3;
	qptr->arg4 = arg4;	
	if (qptr-myqueue < maxq) ++qptr;
	qptr->func = qEnd;
	if (func == qReset) qptr = myqueue;
	pthread_mutex_unlock(&mut);
}

extern "C" void queue2(geom func, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6, long arg7, long arg8)
{
	pthread_mutex_lock(&mut);
	qptr->func = func;
	qptr->arg1 = arg1;
	qptr->arg2 = arg2;
	qptr->arg3 = arg3;
	qptr->arg4 = arg4;	
	if (qptr-myqueue < maxq) ++qptr;
	qptr->func = func;
	qptr->arg1 = arg5;
	qptr->arg2 = arg6;
	qptr->arg3 = arg7;
	qptr->arg4 = arg8;	
	if (qptr-myqueue < maxq) ++qptr;
	qptr->func = qEnd;
	pthread_mutex_unlock(&mut);
}

