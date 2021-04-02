//
//  LilitabMenuButton.h
//
//  Created by Kevin Snow on 10/27/17.
//  Copyright © 2017 Lilitab LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

IB_DESIGNABLE
@interface LilitabMenuButton : UIButton

+(void) closeMenu;

+(NSNotificationName) aboutApp_Notification;
+(NSNotificationName) support_Notification;
+(NSNotificationName) dockStatus_Notification;

@end
