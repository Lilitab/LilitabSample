//
//  LilitabBLEHelpOverlayView.h
//  LilitabSDK
//
//  Created by Kevin Snow on 3/19/18.
//  Copyright © 2018 Lilitab. All rights reserved.
//

#import <UIKit/UIKit.h>


IB_DESIGNABLE
@interface LilitabBLEHelpOverlayView : UIView

+(instancetype) helpOverlay_Magtek;
+(instancetype) helpOverlay_StarPrint;

@property (atomic,copy) void(^closePressBlock)(void);        // This block is called when close is pressed.

@end
