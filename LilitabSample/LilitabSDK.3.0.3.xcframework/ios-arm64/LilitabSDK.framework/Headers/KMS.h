//
//  KMS.h
//  KMSSDK
//
//  Created by Kevin Snow on 11/19/17.
//  Copyright © 2017 Lilitab LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// Add BOOL property of "KMS-BLOCK-LOCATION-SERVICES" to app's info.plist to prevent location services



@interface KMS : NSObject

-(NSString*) enterpriseId;
-(NSString*) groupId;
-(NSString*) tabletId;
-(NSString*) dockId;
+(NSNotificationName) KMS_COORDINATES_CHANGED_Notification;         // KMS Coordinates changed notification

-(UIColor*) backgroundColor;
+(NSNotificationName) KMS_BACKGROUNDCOLOR_CHANGED_Notification;     // Background color changed notification

-(NSURLRequest*) homeUrlRequest;

-(NSURLRequest*) tabletRegistrationUrlRequest;
-(NSURLRequest*) dockRegistrationUrlRequest;

-(void) showPortal;

-(void) setDockLaunchAppName:(NSString*)name;


+(NSNotificationName) NETWORK_REACHABILITY_CHANGED_Notification;
+(NSNotificationName) KMS_SERVICE_REACHABILITY_CHANGED_Notification;
+(NSNotificationName) HOMEPAGE_REACHABILITY_CHANGED_Notification;


+(KMS*) singleton;
@property (nonatomic,assign)    BOOL    enabled;    // once KMS is enabled, it cannot be stopped.

+(void) setSDKLicenseKey:(NSDictionary<NSString*,NSObject*>*)licenseObj;

@end
