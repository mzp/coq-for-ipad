#pragma once

#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"

class testApp : public ofxiPhoneApp {
	
public:
	void setup();
	void update();
	void draw();
	void wakethread();
	void exit();
	int load_of_font(const char *);
	
	void touchDown(ofTouchEventArgs &touch);
	void touchMoved(ofTouchEventArgs &touch);
	void touchUp(ofTouchEventArgs &touch);
	void touchDoubleTap(ofTouchEventArgs &touch);
	
	void lostFocus();
	void gotFocus();
	void gotMemoryWarning();
	void deviceOrientationChanged(int newOrientation);

	ofxiPhoneKeyboard *keyboards[UIDeviceOrientationFaceDown+1];
	
	ofTrueTypeFont  franklinBook;
	ofTrueTypeFont	verdana;

	int dly;

	struct {
		int x,y,z,r;
		UIDeviceOrientation orient;
	} orientation, oldorient;
	
	struct fontcache {
		ofTrueTypeFont myfont;
		const char *name;
	} myfonts[20];
		
//	std::string text1, text2, text3;
};

