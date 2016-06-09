//
//  ViewController.m
//  LilitabSample
//
//  Created by Kevin Snow on 6/8/16.
//  Copyright © 2016 MynaBay Inc. All rights reserved.
//

#import "ViewController.h"
#import <EndoClient/EndoClient.h>
#import "LiliswipeSDK.h"



@interface ViewController ()

@property (nonatomic,weak) IBOutlet UIButton* statusButton;
@property (nonatomic,weak) IBOutlet UIButton* swipeButton;
@property (nonatomic,weak) IBOutlet UIButton* ledButton;

@end



@implementation ViewController

-(IBAction) buttonStatus:(id)sender
{
    EndoLog(@"Requesting status from reader");
    [[Liliswipe sharedSwipe] status:^(BOOL success, NSDictionary* results)
                                    {
                                        EndoLog(@"status = %@",results);
                                    }];
}

-(IBAction) buttonSwipe:(id)sender
{
    [Liliswipe sharedSwipe].enableSwipe = ![Liliswipe sharedSwipe].enableSwipe;
    
    if( [Liliswipe sharedSwipe].enableSwipe )
    {
        EndoLog(@"Enabled swiping");
        [sender setTitle:@"Disable Swipe" forState:UIControlStateNormal];
    }else{
        EndoLog(@"Disabled swiping");
        [sender setTitle:@"Enable Swipe" forState:UIControlStateNormal];
    }
}

-(IBAction) buttonLED:(id)sender
{
    if( [Liliswipe sharedSwipe].ledState == LED_Off )
    {
        [Liliswipe sharedSwipe].ledState = LED_On;
    }else{
        [Liliswipe sharedSwipe].ledState = LED_Off;
    }
}

-(void) accessoryDidConnect:(NSNotification*)notification
{
    EndoLog(@"accessoryDidConnect");
    
    self.statusButton.enabled = YES;
    self.swipeButton.enabled = YES;
    self.ledButton.enabled = YES;
    
    [Liliswipe sharedSwipe].swipeTimeout = 10;
    [Liliswipe sharedSwipe].swipeBlock = ^(NSDictionary* swipeData)
                                        {
                                            EndoLog(@"swipeData = %@",swipeData);
                                            
                                            [self.swipeButton setTitle:@"Enable Swipe" forState:UIControlStateNormal];
                                        };
}

-(void) accessoryDidDisconnect:(NSNotification*)notification
{
    EndoLog(@"accessoryDidDisconnect");
    
    self.statusButton.enabled = NO;
    self.swipeButton.enabled = NO;
    self.ledButton.enabled = NO;
    
    [self.swipeButton setTitle:@"Enable Swipe" forState:UIControlStateNormal];
    
    [Liliswipe sharedSwipe].swipeBlock = NULL;
}

-(void) viewDidLoad
{
    [super viewDidLoad];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(accessoryDidConnect:)
                                                 name:Liliswipe_DidConnectNotification
                                               object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(accessoryDidDisconnect:)
                                                 name:Liliswipe_DidDisconnectNotification
                                               object:nil];
    
    [Liliswipe sharedSwipe].enableAttachmentNotification = YES;
}

@end
