//
//  ocaml_cocosAppDelegate.m
//  ocaml-cocos
//
//  Created by Jonathan Kimmitt on 19/10/2010.
//  Copyright OMSI Limited 2010. All rights reserved.
//

#import "cocos2d.h"

#import "ocaml_cocosAppDelegate.h"
#import "GameConfig.h"
#import "HelloWorldScene.h"
#import "drawPrimitivesNew.h"
// #import "src/ofxiPhoneKeyboard.h"
#import "RootViewController.h"
#import "CCTouchDispatcher.h"

@implementation ocaml_cocosAppDelegate

@synthesize window;

- (void)ccTouchesBegan:(NSSet *)touches withEvent:(UIEvent *)event;
{
	UITouch *touch = [touches anyObject];
	
	if( touch ) {
		CGPoint location = [touch locationInView: [touch view]];
		
		// IMPORTANT:
		// The touches are always in "portrait" coordinates. You need to convert them to your current orientation
		CGPoint convertedPoint = [[CCDirector sharedDirector] convertToGL:location];
		
		int kind = ButtonPress; int mouse_x = convertedPoint.x; int mouse_y = convertedPoint.y;
		int button = 1; int key = 0;
		
		caml_gr_enqueue_event(kind, mouse_x, mouse_y,
							  button, key);		
	}		
}

- (void)ccTouchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
	
}

- (void)ccTouchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
	UITouch *touch = [touches anyObject];
	
	if( touch ) {
		CGPoint location = [touch locationInView: [touch view]];
		
		// IMPORTANT:
		// The touches are always in "portrait" coordinates. You need to convert them to your current orientation
		CGPoint convertedPoint = [[CCDirector sharedDirector] convertToGL:location];
		
		int kind = ButtonRelease; int mouse_x = convertedPoint.x; int mouse_y = convertedPoint.y;
		int button = 1; int key = 0;
		
		caml_gr_enqueue_event(kind, mouse_x, mouse_y,
							  button, key);
	}	
}

- (void)ccTouchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
	
}

-(void) registerWithTouchDispatcher
{
	[[CCTouchDispatcher sharedDispatcher] addStandardDelegate:self priority:0];
}

- (void) applicationDidFinishLaunching:(UIApplication*)application
{
	// Init the window
	window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
	
	// Try to use CADisplayLink director
	// if it fails (SDK < 3.1) use the default director
	if( ! [CCDirector setDirectorType:kCCDirectorTypeDisplayLink] )
		[CCDirector setDirectorType:kCCDirectorTypeDefault];
	
	
	CCDirector *director = [CCDirector sharedDirector];
	
	// Init the View Controller
	viewController = [[RootViewController alloc] initWithNibName:nil bundle:nil];
	viewController.wantsFullScreenLayout = YES;
	
	//
	// Create the EAGLView manually
	//  1. Create a RGB565 format. Alternative: RGBA8
	//	2. depth format of 0 bit. Use 16 or 24 bit for 3d effects, like CCPageTurnTransition
	//
	//
	EAGLView *glView = [EAGLView viewWithFrame:[window bounds]
								   pixelFormat:kEAGLColorFormatRGB565	// kEAGLColorFormatRGBA8
								   depthFormat:0						// GL_DEPTH_COMPONENT16_OES
							preserveBackbuffer:NO];
	
	// attach the openglView to the director
	[director setOpenGLView:glView];
	
	// To enable Hi-Red mode (iPhone4)
	//	[director setContentScaleFactor:2];
	
	//
	// VERY IMPORTANT:
	// If the rotation is going to be controlled by a UIViewController
	// then the device orientation should be "Portrait".
	//
#if GAME_AUTOROTATION == kGameAutorotationUIViewController
	[director setDeviceOrientation:kCCDeviceOrientationPortrait];
#else
	[director setDeviceOrientation:kCCDeviceOrientationLandscapeLeft];
#endif
	
	[director setAnimationInterval:1.0/10];
//	[director setDisplayFPS:YES];
	
	
	// make the OpenGLView a child of the view controller
	[viewController setView:glView];
	
	// make the View Controller a child of the main window
	[window addSubview: viewController.view];

#if 1
//	int x=100, y=100, w=100, h=100, r = 90;
//	int x=10, y=700, w=400, h=40;
	int x=10, y=30, w=400, h=40;
	
	_textField = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, w, h)];
	[_textField setFrame: CGRectMake(x , y, w, h)];
	[_textField setDelegate:self];
	[_textField setBackgroundColor:[UIColor blackColor]];
	[_textField setTextColor:[UIColor whiteColor]];
	[_textField setFont:[UIFont fontWithName:@"Helvetica" size:20]];
	[_textField setPlaceholder:@"Tap here to enter an OCAML phrase"];	
//	[window addSubview:_textField];
//	_textField.transform = CGAffineTransformMakeRotation(r * M_PI / 180.0);
	[[[CCDirector sharedDirector] openGLView] addSubview:_textField];
#endif		
	
	[window makeKeyAndVisible];
	
	// Default texture format for PNG/BMP/TIFF/JPEG/GIF images
	// It can be RGBA8888, RGBA4444, RGB5_A1, RGB565
	// You can change anytime.
	[CCTexture2D setDefaultAlphaPixelFormat:kCCTexture2DPixelFormat_RGBA8888];
	
	[[CCDirector sharedDirector] runWithScene: [TestDemo scene]];	
	
	[self registerWithTouchDispatcher];
	
	LaunchThread();
}

- (void) addtobuf: (char) ch
{
	ringbuf[head] = ch;
	head = (head+1)&255;	
	wakethread();
}

- (void)textFieldDidBeginEditing:(UITextField *)textField
{
	//	ofGetAppPtr()->update();
	textField.autocorrectionType = UITextAutocorrectionTypeNo;	// no auto correction support
    textField.autocapitalizationType = UITextAutocapitalizationTypeNone;	// don't capitalize
	open = true;
}

//--------------------------------------------------------------
- (void)textFieldDidEndEditing:(UITextField *)textField             // may be called if forced even if shouldEndEditing returns NO (e.g. view removed from window) or endEditing:YES called
{
	free(_ctext);
	_ctext = malloc([[textField text] length]+1);
	[[textField text] getCString:_ctext maxLength:[[textField text] length]+1 encoding:NSASCIIStringEncoding];
	//	ofGetAppPtr()->update();
	open = false;
}

//--------------------------------------------------------------
// Terminates the editing session
- (BOOL)textFieldShouldReturn:(UITextField *)textField              // called when 'return' key pressed. return NO to ignore.
{
	//Terminate editing
	// [textField resignFirstResponder];
	ringbuf[head] = '\n';
	head = (head+1)&255;	
	wakethread();
	[_textField setText:nil];
	return NO;
}

- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField;        // return NO to disallow editing.
{
	return YES;
}

- (BOOL)textFieldShouldEndEditing:(UITextField *)textField;          // return YES to allow editing to stop and to resign first responder status. NO to disallow the editing session to end
{
	return YES;
}

- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;   // return NO to not change text
{
	_ctext = malloc([[textField text] length]+1);
	char *rtext = malloc([string length]+1);
	[[textField text] getCString:_ctext maxLength:[[textField text] length]+1 encoding:NSASCIIStringEncoding];
	[string getCString:rtext maxLength:[string length]+1 encoding:NSASCIIStringEncoding];
	ringbuf[head] = rtext[0];
	head = (head+1)&255;	
	wakethread();
	return YES;
}

- (BOOL)textFieldShouldClear:(UITextField *)textField;               // called when clear button pressed. return NO to ignore (no notifications)
{
	return NO;
}

//--------------------------------------------------------------
- (char *) getText
{
	return _ctext;
}

//--------------------------------------------------------------
- (void) showText
{
	//	[ofxiPhoneGetUIWindow() addSubview:_textField];
}

//--------------------------------------------------------------
- (void) hideText
{
	[_textField endEditing:YES];
	[_textField removeFromSuperview];
}

//--------------------------------------------------------------
- (void) setText: (NSString *)text
{
	[_textField setText:text];
}

//--------------------------------------------------------------
- (void) setPlaceholder: (NSString *)text
{
	[_textField setPlaceholder:text];
}

//--------------------------------------------------------------
- (void) setFontSize: (int)size
{
	[_textField setFont:[UIFont fontWithName:@"Helvetica" size:size]];
}

//--------------------------------------------------------------
- (void) setFontColorRed: (int)r green: (int)g blue:(int)b alpha:(int)a
{
	[_textField setTextColor:[UIColor 
							  colorWithRed:	(float)r/255 
							  green:		(float)g/255 
							  blue:			(float)b/255 
							  alpha:		(float)a/255]];
}

//--------------------------------------------------------------
- (void) setBgColorRed: (int)r green: (int)g blue:(int)b alpha:(int)a
{
	[_textField setBackgroundColor:[UIColor 
									colorWithRed:	(float)r/255 
									green:			(float)g/255 
									blue:			(float)b/255 
									alpha:			(float)a/255]];
}

//--------------------------------------------------------------
- (bool) isKeyboardShowing
{
	return open;
}

//--------------------------------------------------------------
- (void) setFrame: (CGRect) rect
{
	
	//	CGSize s = [[[UIApplication sharedApplication] keyWindow] bounds].size;		
	//	[_textField setFrame: CGRectMake(rect.origin.x , rect.origin.y-rect.size.height, rect.size.width, rect.size.height)];
	[_textField setFrame: CGRectMake(rect.origin.x , rect.origin.y, rect.size.width, rect.size.height)];
}

//--------------------------------------------------------------
- (void) openKeyboard
{
	[_textField becomeFirstResponder];
}

//--------------------------------------------------------------
- (void) closeKeyboard
{
	[_textField resignFirstResponder];
}

//--------------------------------------------------------------
- (void) setTransform: (int) r
{
	_textField.transform = CGAffineTransformMakeRotation(r * M_PI / 180.0);
}

- (void)applicationWillResignActive:(UIApplication *)application {
	[[CCDirector sharedDirector] pause];
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
	[[CCDirector sharedDirector] resume];
}

- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application {
	[[CCDirector sharedDirector] purgeCachedData];
}

-(void) applicationDidEnterBackground:(UIApplication*)application {
	[[CCDirector sharedDirector] stopAnimation];
}

-(void) applicationWillEnterForeground:(UIApplication*)application {
	[[CCDirector sharedDirector] startAnimation];
}

- (void)applicationWillTerminate:(UIApplication *)application {
	CCDirector *director = [CCDirector sharedDirector];
	
	[[director openGLView] removeFromSuperview];
	
	[viewController release];
	
	[window release];
	
	[director end];	
}

- (void)applicationSignificantTimeChange:(UIApplication *)application {
	[[CCDirector sharedDirector] setNextDeltaTimeZero:YES];
}

- (void)dealloc {
	[_textField release];
	[[CCDirector sharedDirector] release];
	[window release];
	[super dealloc];
}

@end
