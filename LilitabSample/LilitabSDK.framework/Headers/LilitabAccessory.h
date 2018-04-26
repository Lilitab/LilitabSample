//
//  LilitabAccessory.h
//  LilitabSDK
//
//  Created by Kevin Snow on 6/28/14.
//  Copyright (c) 2014-2018 Lilitab. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

    // Accessory Types
typedef NS_ENUM(NSInteger)
{
    LILITAB_NO_ACCESSORY,
    LILITAB_SWIPE,
    LILITAB_DOCK,
    LILITAB_eDynamo,
} Lilitab_Accessory_Type;

    // LED states
typedef NS_ENUM(NSInteger)
{
    LED_Off,
    LED_On,
    LED_Blink1,
    LED_Blink2,
    LED_Blink3,
    LED_Blink4,
    LED_SwipeForward,
    LED_SwipeReverse
} LilitabSDK_LED_Mode;

    // Names used with NSNotificationCenter to be notified of dock status events
#define     LilitabSDK_DockStatusNotification           @"LilitabSDK-DockStatusNotification"

    // Names used with NSNotificationCenter to be notified of connect/disconnect events
#define     LilitabSDK_DidConnectNotification           @"Liliswipe_DidConnectNotification"
#define     LilitabSDK_DidDisconnectNotification        @"Liliswipe_DidDisconnectNotification"


@interface LilitabSDK : NSObject

    /////////////////////////////////////////////////////////////////////
    // singleton - Singleton object for communication with lilitab accessories
    //
+(LilitabSDK*) singleton;


    /////////////////////////////////////////////////////////////////////
    // singleton - Singleton object for communication with lilitab accessories
    //
+(NSNotificationName) didConnectNotification;
+(NSNotificationName) didDisconnectNotification;
+(NSNotificationName) dockStatusNotification;
+(NSNotificationName) swipeEnableChangeNotification;
+(NSNotificationName) readerStatusNotification;


    /////////////////////////////////////////////////////////////////////
    // accessoryType - Type of Lilitab accessory attached.
    //
@property (nonatomic,readonly) Lilitab_Accessory_Type accessoryType;


    /////////////////////////////////////////////////////////////////////
    // eDynamoSerialNumber - Serial number of eDynamo to attach to.
    //
-(void) scanBLEDevices:(void(^)(CBPeripheral* peripheral))scanBlock;    // eDynamo.
-(void) stopBLEScan;
-(void) selectBLEDevice:(CBPeripheral*)peripheral;
-(CBPeripheral*) selectedBLEDevice;


    /////////////////////////////////////////////////////////////////////
    // isAttached - readonly property containing presence of liliswipe
    //
@property (nonatomic,readonly)  BOOL isAttached;


    /////////////////////////////////////////////////////////////////////
    // status - The completionBLock is executed after the status information
    // has been read from the swipe.
    //
-(void) status:(void (^)(BOOL success,NSDictionary* results))completionBlock;


    /////////////////////////////////////////////////////////////////////
    // ledState - Controls the LEDs on the swipe. Defaults to LED_Off.
    //
@property (nonatomic,assign)    LilitabSDK_LED_Mode  ledState;


    /////////////////////////////////////////////////////////////////////
    // noPowerBlinkDuration - Controls the duration between blinks in
    // milliseconds if not power is present. Defaults to 0 (no blink)
    //
@property (nonatomic,assign)    NSTimeInterval      noPowerBlinkDuration;


    /////////////////////////////////////////////////////////////////////
    // Swiping - Set the swipeBlock property to code to execute for a swipe
    // Use the enable property to enable/disable swipeBlock execution.
    // After enabling swipe, it stays active until a swipe, timeout or error.
    // A timeout of 0 is infinite
    //
@property (atomic,copy)                    void(^swipeBlock)(NSDictionary* swipeData);
@property (nonatomic,assign)    BOOL                enableSwipe;            // default: NO
@property (atomic,assign)       BOOL                allowMultipleSwipes;    // default: NO
@property (atomic,assign)    NSTimeInterval         swipeTimeout;


    /////////////////////////////////////////////////////////////////////
    // Speaker override lets app force sound out speakers with headphone
    // jack plugged in.
    //
@property (nonatomic,assign)    BOOL                enableSpeakerOverride;


    /////////////////////////////////////////////////////////////////////
    // Lock & Unlock a Dock accessory
    //
-(void) lockWithCompletion:(void (^)(BOOL success))completionBlock;
-(void) unlockWithCompletion:(void (^)(BOOL success))completionBlock;
@property (atomic,readonly)     BOOL                dockHasPower;


    /////////////////////////////////////////////////////////////////////
    // Dock status events
    //
@property (nonatomic,assign)    NSTimeInterval      dockLiveStatusInterval;


    /////////////////////////////////////////////////////////////////////
    // Firmware Updating
    //
-(void) updateFirmware:(NSData*)firmware
               options:(NSDictionary*)optionsDict
          withProgress:(void (^)(float percent0to1))progressBlock
        withCompletion:(void (^)(BOOL success))completionBlock;

-(void) cancelFirmwareUpdate;


    /////////////////////////////////////////////////////////////////////
    // scanForConnectedAccessories - Call to generate LilitabSDK_DidConnectNotification
    // notifications for any accessories already attached.
    //
-(void) scanForConnectedAccessories;


    /////////////////////////////////////////////////////////////////////
    // disconnectOnAppResign
    //
    // Disconnect from accessory when app resigns. 
@property (nonatomic,assign)    BOOL    disconnectOnAppResign;


    /////////////////////////////////////////////////////////////////////
    // sendReaderCommand - Send commands to the embedded card reader.
    //
-(void) sendReaderCommand:(NSData*)cmdData withCompletion:(void (^)(BOOL success,NSDictionary* results))completionBlock;


    /////////////////////////////////////////////////////////////////////
    // version - return a version string of the library
    //
@property (nonatomic,readonly)  NSString*  version;


    /////////////////////////////////////////////////////////////////////
    // setHeadTimeTo - Time passed to the card reader head. (DEPRECATED)
    //
    // Most developers will NOT need this call. Reader head time is
    // maintained by SDK.
    // Use only if reader head needs a date other than NOW.
    // To clear a date, call with NULL (restores automatic maintainence)
    //
-(void) setHeadTimeTo:(NSDate*)date;


    /////////////////////////////////////////////////////////////////////
    /////////// DO NOT USE CALLS BELOW HERE IN APPLICATIONS /////////////
    /////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////
    // debugMessages - Have library pass debug strings to app.
    //
    // Used for SDK development/testing
    //
@property (nonatomic,copy) void(^debugMessages)(NSString* msg);


    /////////////////////////////////////////////////////////////////////
    // INTERNAL - Testing functions
    //
-(void) sendCommand:(NSString*)cmd withCompletion:(void (^)(BOOL success,NSDictionary* results))completionBlock;

    /////////////////////////////////////////////////////////////////////

@end

    /////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////

