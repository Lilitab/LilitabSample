//
//  LilitabBLEHelpView.h
//  LilitabSDK
//
//  Created by Kevin Snow on 2/18/18.
//  Copyright © 2018 Lilitab. All rights reserved.
//

#import <UIKit/UIKit.h>

IB_DESIGNABLE
@interface LilitabBLEHelpView : UIView

@property (atomic,copy) void(^closePressBlock)(void);        // This block is called when close is pressed.

@end
