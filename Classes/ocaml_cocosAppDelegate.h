//
//  ocaml_cocosAppDelegate.h
//  ocaml-cocos
//
//  Created by Jonathan Kimmitt on 19/10/2010.
//  Copyright OMSI Limited 2010. All rights reserved.
//

#import <UIKit/UIKit.h>

@class RootViewController;

@interface ocaml_cocosAppDelegate : NSObject <UIApplicationDelegate, UITextFieldDelegate, CCStandardTouchDelegate, CCTargetedTouchDelegate> {
	UIWindow			*window;
	RootViewController	*viewController;
	UITextField*			_textField;
	bool					open;
}

@property (nonatomic, retain) UIWindow *window;

@end
