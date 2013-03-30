//
//  ARKViewController.h
//  ARKitDemo
//
//  Created by Zac White on 8/1/09.
//  Copyright 2009 Zac White. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <CoreLocation/CoreLocation.h>

#import "ARCoordinate.h"

@protocol ARViewDelegate

- (UIView *)viewForCoordinate:(ARCoordinate *)coordinate;

@end


@interface ARViewController : UIViewController <UIAccelerometerDelegate, CLLocationManagerDelegate> {
	CLLocationManager *locationManager;
	UIAccelerometer *accelerometerManager;
	
	ARCoordinate *centerCoordinate;
	
	UIImagePickerController *cameraController;
	
	NSObject<ARViewDelegate> *__weak delegate;
	NSObject<CLLocationManagerDelegate> *__weak locationDelegate;
	NSObject<UIAccelerometerDelegate> *__weak accelerometerDelegate;
	
	BOOL scaleViewsBasedOnDistance;
	double maximumScaleDistance;
	double minimumScaleFactor;
	
	//defaults to 20hz;
	double updateFrequency;
	
	BOOL rotateViewsBasedOnPerspective;
	double maximumRotationAngle;
	
@private
	BOOL ar_debugMode;
	
	NSTimer *_updateTimer;
	
	UIView *ar_overlayView;
	
	UILabel *ar_debugView;
	
	NSMutableArray *ar_coordinates;
	NSMutableArray *ar_coordinateViews;
}

@property (readonly) NSArray *coordinates;

@property (nonatomic) BOOL debugMode;

@property BOOL scaleViewsBasedOnDistance;
@property double maximumScaleDistance;
@property double minimumScaleFactor;

@property BOOL rotateViewsBasedOnPerspective;
@property double maximumRotationAngle;

@property (nonatomic) double updateFrequency;

//adding coordinates to the underlying data model.
- (void)addCoordinate:(ARCoordinate *)coordinate;
- (void)addCoordinate:(ARCoordinate *)coordinate animated:(BOOL)animated;

- (void)addCoordinates:(NSArray *)newCoordinates;


//removing coordinates
- (void)removeCoordinate:(ARCoordinate *)coordinate;
- (void)removeCoordinate:(ARCoordinate *)coordinate animated:(BOOL)animated;

- (void)removeCoordinates:(NSArray *)coordinates;

- (id)initWithLocationManager:(CLLocationManager *)manager;

- (void)startListening;
- (void)updateLocations:(NSTimer *)timer;

- (CGPoint)pointInView:(UIView *)realityView forCoordinate:(ARCoordinate *)coordinate;

- (BOOL)viewportContainsCoordinate:(ARCoordinate *)coordinate;

@property (nonatomic, strong) UIImagePickerController *cameraController;

@property (nonatomic, weak) NSObject<ARViewDelegate> *delegate;
@property (nonatomic, weak) NSObject<CLLocationManagerDelegate> *locationDelegate;
@property (nonatomic, weak) NSObject<UIAccelerometerDelegate> *accelerometerDelegate;

@property (strong) ARCoordinate *centerCoordinate;

@property (nonatomic, strong) UIAccelerometer *accelerometerManager;
@property (nonatomic, strong) CLLocationManager *locationManager;

@end
