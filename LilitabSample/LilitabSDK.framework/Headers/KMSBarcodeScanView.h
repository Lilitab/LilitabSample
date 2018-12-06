//
//  KMSBarcodeScanView.h
//  LilitabSDK
//
//  Created by Kevin Snow on 5/4/18.
//  Copyright © 2018 Lilitab. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>


IB_DESIGNABLE
@interface KMSBarcodeScanView : UIView

@property (nonatomic,strong)    NSString*               message;            // Message to display to user.
@property (nonatomic,readonly)  UIButton*               cancelButton;       // Cancel button.

@property (nonatomic,assign)    NSTimeInterval          timeout;            // 0=no timeout

@property (nonatomic,copy) void(^scannedBarcodeBlock)(NSDictionary<NSString*,id>* scanResult); // This block is called with scan.

@property (nonatomic,copy) void(^cancelPressBlock)(void);                   // This block is called if cancel is pressed.

-(void) startScanner:(NSString*)scanSDK onCamera:(NSString*)camera;         // ScanSDK = "Apple", "Scandit", or "off"
                                                                            // camera = "front" or "back"
-(void) stopScanner;

@end
