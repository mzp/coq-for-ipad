enum {width = 81, height = 25};

#import "cocos2d.h"
#import "../src/ocaml-3.12.0/byterun/glue.h"

const char *fullp(NSString *relPath);

//CLASS INTERFACE
#ifdef __IPHONE_OS_VERSION_MAX_ALLOWED
@interface AppController : NSObject <UIApplicationDelegate>
{
	UIWindow *window;
}
@end

#elif defined(__MAC_OS_X_VERSION_MAX_ALLOWED)
@interface cocos2dmacAppDelegate : NSObject <NSApplicationDelegate>
{
	NSWindow	*window_;
	MacGLView	*glView_;
}

@property (assign) IBOutlet NSWindow	*window;
@property (assign) IBOutlet MacGLView	*glView;

@end
#endif // Mac

@interface TestDemo : CCLayer
{
	CCLabelTTF *label;
	CCMenu *menu;
}

-(NSString*) title;

-(void) update:(ccTime)dt;

// returns a Scene that contains the TestDemo as the only child
+(id) scene;

@end

@interface Test1 : TestDemo
{}
@end

@interface Test2 : TestDemo
{}
@end
