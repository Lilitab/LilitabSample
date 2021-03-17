//
//  LilitabSDK.h
//  LilitabSDK
//
//  Created by Kevin Snow on 3/7/21.
//

#import <Foundation/Foundation.h>

//! Project version number for LilitabSDK.
FOUNDATION_EXPORT double LilitabSDKVersionNumber;

//! Project version string for LilitabSDK.
FOUNDATION_EXPORT const unsigned char LilitabSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <LilitabSDK/PublicHeader.h>

#import <LilitabSDK/LilitabAccessories.h>
#import <LilitabSDK/LilitabAccessory.h>
#import <LilitabSDK/LilitabAccessories+AccessoryGetters.h>
#import <LilitabSDK/LilitabSignatureView.h>
#import <LilitabSDK/LilitabSignatureOverlayView.h>
#import <LilitabSDK/LilitabSwipeAnimationView.h>
#import <LilitabSDK/LilitabSwipeAnimationOverlayView.h>
#import <LilitabSDK/LilitabBLEHelpOverlayView.h>
#import <LilitabSDK/LilitabMenuButton.h>
#import <LilitabSDK/LilitabWebView.h>

#import <LilitabSDK/CaptureViewController.h>
#import <LilitabSDK/CaptureOverlay.h>

#import <LilitabSDK/KMS.h>
#import <LilitabSDK/KMSGeolocateButton.h>
#import <LilitabSDK/KMSHelpButton.h>
#import <LilitabSDK/KMSHomeButton.h>
#import <LilitabSDK/KMSMenuButton.h>
#import <LilitabSDK/KMSUnlockButton.h>
#import <LilitabSDK/KMSWebView.h>
#import <LilitabSDK/KMSLockIconView.h>
#import <LilitabSDK/KMSDockFirmwareUpdateView.h>
#import <LilitabSDK/KMSDockStatusViewController.h>
#import <LilitabSDK/KMSReaderStatusViewController.h>
#import <LilitabSDK/KMSGeolocateMenuViewController.h>
#import <LilitabSDK/KMSPinpadViewController.h>
#import <LilitabSDK/KMSPrinterStatusViewController.h>
#import <LilitabSDK/KMSBarsViewController.h>


@interface LilitabSDK : NSObject

+(NSString* _Nonnull) version;

+(void) setEnableSpeakerOverride:(BOOL)override;

@end
