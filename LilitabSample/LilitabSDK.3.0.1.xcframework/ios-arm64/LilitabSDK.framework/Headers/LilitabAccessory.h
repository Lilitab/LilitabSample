//
//  LilitabAccessory.h
//  LilitabSDK
//
//  Created by Kevin Snow on 8/13/19.
//  Copyright © 2019 Lilitab. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ExternalAccessory/ExternalAccessory.h>

NS_ASSUME_NONNULL_BEGIN



@interface LilitabAccessory : NSObject

////////////////////////////////////////////////////////////////////////////////

-(void) info:(void (^_Nonnull)(BOOL success,NSDictionary* _Nonnull results))completionBlock;

-(NSString*) type;
-(NSString*) name;

////////////////////////////////////////////////////////////////////////////////

@end




////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


@protocol LilitabCardReader <NSObject>

    /////////////////////////////////////////////////////////////////////
    // Swiping - Set the swipeBlock property to code to execute for a swipe
    // Use the enable property to enable/disable swipeBlock execution.
    // After enabling swipe, it stays active until a swipe, timeout or error.
    // A timeout of 0 is infinite
    //
@property (atomic,copy)         void(^ _Nullable swipeBlock)(NSDictionary* _Nonnull swipeData);
@property (atomic,assign)       BOOL                enableSwipe;            // default: NO
@property (atomic,assign)       BOOL                allowMultipleSwipes;    // default: NO
@property (atomic,assign)    NSTimeInterval         swipeTimeout;

@end


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


@protocol LilitabDock <NSObject>

-(void) lockWithCompletion:(void (^_Nullable)(BOOL success))completionBlock;

-(void) unlockWithCompletion:(void (^_Nullable)(BOOL success))completionBlock;
-(void) unlock:(NSString*)originator withCompletion:(void (^_Nullable)(BOOL success))completionBlock;

@property (nonatomic,readonly) BOOL isPowered;
@property (nonatomic,readonly) BOOL isLocked;
@property (nonatomic,readonly) BOOL headPresent;
@property (nonatomic,assign)   BOOL forwardHeartbeats;

@property (nonatomic,readonly) NSString* _Nonnull                   dockFirmwareUUID;
@property (nonatomic,readonly) NSString*                            dockHandle;
@property (nonatomic,readonly) NSDictionary<NSString*,NSString*>*   dockInfo;

@property (nonatomic,readonly) NSDictionary<NSString*,NSString*>*  lastLiveStatus;

-(void) setLaunchAppName:(NSString*)name withCompletion:(void (^_Nonnull)(BOOL success,NSDictionary* _Nonnull results))completionBlock;

-(void) sendCommand:(NSString*)cmd completion:(void (^_Nonnull)(NSDictionary* _Nonnull results))completion;

@end


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


@protocol LilitabFirmwareUpdatable <NSObject>

-(void) updateFirmware:(NSData*_Nonnull)firmware
               options:(NSDictionary<NSString*,NSString*>*_Nullable)optionsDict
          withProgress:(void (^_Nullable)(float percent0to1))progressBlock
        withCompletion:(void (^_Nullable)(BOOL success))completionBlock;

-(void) cancelFirmwareUpdate;

@end


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


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
} LilitabReader_LED_Mode;

@protocol LilitabReaderLED <NSObject>

@property (nonatomic,assign)    LilitabReader_LED_Mode  ledState;

@end


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


@protocol LilitabPowerBlink <NSObject>

// noPowerBlinkDuration - Controls the duration between blinks in
// milliseconds if not power is present. Defaults to 0 (no blink)

@property (nonatomic,assign)    NSTimeInterval      noPowerBlinkDuration;

@end


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


@protocol LilitabSetReaderHeadTime <NSObject>

-(void) setHeadTimeTo:(NSDate*)readerHeadTime;

@end


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


@protocol LilitabEACommand <NSObject>

-(void) sendCmd:(NSString*)cmdStr completion:(void (^)(BOOL success,NSDictionary* results))completionBlock;
-(EAAccessory*) getEAAcessory;

@end


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

NS_ASSUME_NONNULL_END
