//
//  ViewController.m
//  LilitabSample
//
//  Created by Kevin Snow on 6/8/16.
//  Copyright © 2016 MynaBay Inc. All rights reserved.
//

#import "ViewController.h"
#import <LilitabSDK/LilitabSDK.h>



@interface ViewController ()

@property (nonatomic,weak) IBOutlet UIButton* statusButton;
@property (nonatomic,weak) IBOutlet UIButton* swipeButton;
@property (nonatomic,weak) IBOutlet UIButton* ledButton;
@property (nonatomic,weak) IBOutlet UITextView* outputTextView;

@end



@implementation ViewController

-(IBAction) buttonStatus:(id)sender
{
    LilitabAccessory<LilitabCardReader>* acc = [LilitabAccessories getFirstSwipe];
    [acc info:^(BOOL success, NSDictionary* results)
                                    {
                                        NSLog(@"info = %@",results);
                                        self.outputTextView.text = [NSString stringWithFormat:@"info = %@",results];
                                    }];
}

-(IBAction) buttonSwipe:(id)sender
{
    LilitabAccessory<LilitabCardReader>* acc = [LilitabAccessories getFirstSwipe];
    if( acc != nil )
    {
        acc.enableSwipe = !acc.enableSwipe;
        
        if( acc.enableSwipe )
        {
            [sender setTitle:@"Disable Swipe" forState:UIControlStateNormal];
        }else{
            [sender setTitle:@"Enable Swipe" forState:UIControlStateNormal];
        }
    }
}

-(IBAction) buttonLED:(id)sender
{
    LilitabAccessory<LilitabCardReader>* acc = [LilitabAccessories getFirstSwipe];
    if( [acc conformsToProtocol:@protocol(LilitabReaderLED)] )
    {
        LilitabAccessory<LilitabReaderLED>* accLed = (LilitabAccessory<LilitabReaderLED>*)acc;
        if( accLed.ledState == LED_Off )
        {
            accLed.ledState = LED_On;
        }else{
            accLed.ledState = LED_Off;
        }
    }
}

-(void) accessoryDidConnect:(NSNotification*)notification
{
    NSLog(@"accessoryDidConnect");
    
    self.statusButton.enabled = YES;
    self.swipeButton.enabled = YES;
    self.ledButton.enabled = YES;
    
    LilitabAccessory<LilitabCardReader>* acc = [LilitabAccessories getFirstSwipe];
    if( acc != nil )
    {
        acc.swipeTimeout = 10;
        acc.swipeBlock = ^(NSDictionary* swipeData)
                                        {
                                            NSLog(@"swipeData = %@",swipeData);
                                            self.outputTextView.text = [NSString stringWithFormat:@"swipeData = %@",swipeData];
                                            
                                            [self.swipeButton setTitle:@"Enable Swipe" forState:UIControlStateNormal];
                                        };
    }
}

-(void) accessoryDidDisconnect:(NSNotification*)notification
{
    NSLog(@"accessoryDidDisconnect");
    
    self.statusButton.enabled = NO;
    self.swipeButton.enabled = NO;
    self.ledButton.enabled = NO;
    
    [self.swipeButton setTitle:@"Enable Swipe" forState:UIControlStateNormal];
    
    LilitabAccessory<LilitabCardReader>* acc = [LilitabAccessories getFirstSwipe];
    if( acc != nil )
    {
        acc.swipeBlock = NULL;
    }
}

-(void) viewWillAppear:(BOOL)animated
{
    self.outputTextView.text = [NSString stringWithFormat:@"LilitabSDK version %@",LilitabSDK.version];
}

-(void) viewDidLoad
{
    [super viewDidLoad];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(accessoryDidConnect:)
                                                 name:LilitabAccessories.didConnectNotification
                                               object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(accessoryDidDisconnect:)
                                                 name:LilitabAccessories.didDisconnectNotification
                                               object:nil];
    
    LilitabAccessories* accessories = [LilitabAccessories new];
    [accessories scanForConnectedAccessories];
    
    LilitabAccessory<LilitabCardReader>* acc = [LilitabAccessories getFirstSwipe];
    if( [acc conformsToProtocol:@protocol(LilitabReaderLED)] )
    {
        LilitabAccessory<LilitabReaderLED>* accLed = (LilitabAccessory<LilitabReaderLED>*)acc;
        accLed.ledState = LED_Off;
    }
}

@end
