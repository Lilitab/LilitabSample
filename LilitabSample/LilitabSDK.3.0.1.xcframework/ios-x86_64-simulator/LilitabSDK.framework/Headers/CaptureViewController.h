//
//  CaptureViewController.h

//
//  Created by Kevin Snow on 1/20/19.
//  Copyright © 2019 Lilitab. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface CaptureViewController : UIViewController

@property (nonatomic,copy) void(^captureBlock)(NSDictionary<NSString*,id>* captureResult);

-(instancetype) initWithSetting:(NSDictionary<NSString*,NSObject*>*)settings;

@property (nonatomic,weak) IBOutlet UITextView*                 titleTextView;
@property (nonatomic,weak) IBOutlet UIButton*                   cancelButton;
@property (nonatomic,weak) IBOutlet UIButton*                   captureButton;
@property (nonatomic,weak) IBOutlet UIActivityIndicatorView*    spinner;

-(void) close;

@end
