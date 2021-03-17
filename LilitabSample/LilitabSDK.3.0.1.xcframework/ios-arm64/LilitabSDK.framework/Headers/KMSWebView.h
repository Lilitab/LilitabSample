//
//  KMSWebView.h
//  KMS
//
//  Created by Kevin Snow on 10/26/17.
//  Copyright © 2017 Lilitab LLC. All rights reserved.
//

#import <UIKit/UIKit.h>


@protocol KMSWebViewDelegate <NSObject>
@optional

-(bool) allowURI:(nonnull NSString*)uriString;
-(bool) handleCardSwipe:(nonnull NSDictionary<NSString*,NSObject*>*)swipeData;

-(UIView* _Nullable) getDomainLimitErrorView;
-(UIView* _Nullable) getNoNetworkErrorView;

@end




IB_DESIGNABLE
@interface KMSWebView : UIView

@property(nullable,nonatomic,weak)  id<KMSWebViewDelegate>  kmsDelegate;

@property (nonatomic,assign)    IBInspectable   BOOL    enableBars;
@property (nonatomic,assign)    IBInspectable   BOOL    enableActivityIndicator;

@property (nonatomic,assign)                    BOOL    animateActivityIndicator;

@end
