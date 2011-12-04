#include <sys/param.h>
#include "ofMain.h"
#include "testApp.h"
#include "glue.h"

char *getPwd, *getPwd2;

int main(int argc, char **argv){
	    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
		NSArray *dirArray = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,
																NSUserDomainMask,
																YES);
		
		NSString *path = [NSString stringWithFormat:@"%@", [dirArray objectAtIndex:0]];
		const char* cString = [path UTF8String]; 
	char realp[MAXPATHLEN];
	realpath(cString, realp);
	getPwd = (char *)malloc(strlen(cString)+50);
	strcpy(getPwd, realp);
	getPwd2 = strdup(realp);
	chdir(getPwd2);

	char *right = strrchr(getPwd, '/');
	if (right) right[1] = 0;
	
		[pool release];

	ofSetupOpenGL(1024,768, OF_FULLSCREEN);			// <-------- setup the GL context

	ofRunApp(new testApp);
	free(getPwd);
}
