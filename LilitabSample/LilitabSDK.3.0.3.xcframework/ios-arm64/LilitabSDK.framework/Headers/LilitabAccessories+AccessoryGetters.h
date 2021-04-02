//
//  LilitabAccessories+AccessoryGetters.h
//  LilitabSDK
//
//  Created by Kevin Snow on 8/15/19.
//  Copyright © 2019 Lilitab. All rights reserved.
//

#import <LilitabSDK/LilitabAccessories.h>

@interface LilitabAccessories (AccessoryGetters)

+(LilitabAccessory<LilitabDock>* _Nullable) getFirstDock;

+(LilitabAccessory<LilitabCardReader>* _Nullable) getFirstReader;
+(LilitabAccessory<LilitabCardReader>* _Nullable) getFirstSwipe;
+(LilitabAccessory<LilitabCardReader>* _Nullable) getFirstEDynamo;

@end
