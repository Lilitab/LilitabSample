//
//  LilitabAccessories.h
//
//  Created by Kevin Snow on 8/11/19.
//  Copyright © 2019 Lilitab. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <LilitabSDK/LilitabAccessory.h>

NS_ASSUME_NONNULL_BEGIN

@interface LilitabAccessories : NSObject

/////////////////////////////////////////////////////////////////////

// Supports eDynamo via BLE
-(void) bleReaderScan:(void(^_Nonnull)(LilitabAccessory<LilitabCardReader>* _Nullable peripheral))scanBlock;
-(void) bleReaderScanStop;
-(void) bleReaderSelect:(LilitabAccessory<LilitabCardReader>* _Nullable)peripheral;
-(LilitabAccessory<LilitabCardReader>* _Nullable) bleReaderSelected;

/////////////////////////////////////////////////////////////////////

-(void) scanForConnectedAccessories;

/////////////////////////////////////////////////////////////////////

+(NSArray<LilitabAccessory*>*) allAccessories;
+(NSArray<LilitabAccessory<LilitabDock>*>*) dockAccessories;
+(NSArray<LilitabAccessory<LilitabCardReader>*>*) readerAccessories;

+(LilitabAccessory*) accessoryFor:(EAAccessory*)eaAccessory;

/////////////////////////////////////////////////////////////////////

+(NSNotificationName _Nonnull ) didConnectNotification;
+(NSNotificationName _Nonnull ) didDisconnectNotification;

////////////////////////////////////////////////////////////////////////////////

+(NSNotificationName _Nonnull ) readerStatusNotification;
+(NSNotificationName _Nonnull ) readerEnableChangeNotification;

+(NSNotificationName _Nonnull ) dockStatusNotification;
+(NSNotificationName _Nonnull ) dockCachedStatusNotification;

+(NSNotificationName _Nonnull ) firmwareUpdatedNotification;

////////////////////////////////////////////////////////////////////////////////

@end


NS_ASSUME_NONNULL_END
