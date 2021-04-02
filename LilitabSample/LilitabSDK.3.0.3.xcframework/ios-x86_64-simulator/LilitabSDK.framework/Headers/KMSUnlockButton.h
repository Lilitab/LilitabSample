//
//  KMSUnlockButton.h
//
//  Created by Kevin Snow on 7/30/16.
//  Copyright © 2016-2017 Lilitab. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol KMSUnlockButtonDelegate
-(void) unlock;
@end

IB_DESIGNABLE
@interface KMSUnlockButton : UIButton

@property (nonatomic,strong) IBInspectable id<KMSUnlockButtonDelegate>  delegate;

@end
