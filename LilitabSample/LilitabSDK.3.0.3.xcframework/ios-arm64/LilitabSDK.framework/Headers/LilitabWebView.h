//
//  LilitabWebView.h
//  LilitabSDK
//
//  Created by Kevin Snow on 2/21/19.
//  Copyright © 2019 Lilitab. All rights reserved.
//

#import <UIKit/UIKit.h>


IB_DESIGNABLE

@interface LilitabWebView : UIView

@property (nonatomic,strong)    NSString*               homeURLString;
@property (nonatomic,assign)    float                   timeout;

@property (nonatomic,strong)    NSArray<NSString*>*     limitDomains;
@property (nonatomic,readonly)  NSArray<NSString*>*     blockedDomains;

-(void) goHome;
-(void) goTo:(NSString*)urlString;

@end
