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

-(void) setDockLaunchAppName:(NSString*)name;

+(NSNotificationName) KMS_WEBVIEW_REQUEST_Notification;             // Notification.object is an NSDictionary<NSString*,NSObject*>* with @"type" = @"kms" || @"user"
                                                                    //                                                                   @"request" = NSURLRequest instance to load.

+(KMS*) singleton;

+(void) setSDKLicenseKey:(NSDictionary<NSString*,NSObject*>*)licenseObj;

@end
