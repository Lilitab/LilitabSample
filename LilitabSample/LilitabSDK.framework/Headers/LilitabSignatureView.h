//
//  LilitabSignatureView.h
//  LilitabSDK
//
//  Created by Kevin Snow on 3/2/18.
//  Copyright © 2018 Lilitab. All rights reserved.
//

#import <UIKit/UIKit.h>

IB_DESIGNABLE
@interface LilitabSignatureView : UIView

@property (nonatomic,readonly)  UIButton*       approveButton;
@property (nonatomic,readonly)  UIButton*       cancelButton;

@property (nonatomic,readonly)  UILabel*        titleLabel;
@property (nonatomic,readonly)  UILabel*        amountLabel;
@property (nonatomic,readonly)  UITextView*     agreementLabel;

-(UIImage*) getSignatureImage;
-(void)     clearSignatureImage;

@property (nonatomic,copy) void(^approvePressBlock)(BOOL ok, UIImage* image);
@property (nonatomic,copy) void(^cancelPressBlock)(void);

@end
