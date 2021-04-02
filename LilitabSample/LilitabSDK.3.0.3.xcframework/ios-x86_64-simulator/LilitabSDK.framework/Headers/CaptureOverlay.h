//
//  CaptureOverlay.h
//
//  Created by Kevin Snow on 1/31/19.
//  Copyright © 2019 Lilitab. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CaptureOverlay : NSObject

    // Capture block. Called with capture or scan result
@property (nonatomic,copy) void(^captureBlock)(NSDictionary<NSString*,id>* captureResult);

    // View support
-(instancetype) initFor:(UIView*)parent withSetting:(NSDictionary<NSString*,NSObject*>*)settings;

@property (nonatomic,readonly)  UITextView*                 titleTextView;
@property (nonatomic,readonly)  UIButton*                   captureButton;
@property (nonatomic,readonly)  UIButton*                   cancelButton;
@property (nonatomic,readonly)  UIActivityIndicatorView*    spinner;

-(void) close;

@end

NS_ASSUME_NONNULL_END
