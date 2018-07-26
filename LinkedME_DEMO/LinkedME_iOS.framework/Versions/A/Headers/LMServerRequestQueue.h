//
//  LMServerRequestQueue.h
//  iOS-Deep-Linking-SDK
//
//  Created by han on 9/6/14.
//
//

#import "LMServerRequest.h"

@class LMOpenRequest;

@interface LMServerRequestQueue : NSObject

@property (nonatomic, readonly) unsigned int size;

- (void)enqueue:(LMServerRequest *)request;
- (LMServerRequest *)dequeue;
- (LMServerRequest *)peek;
- (LMServerRequest *)peekAt:(unsigned int)index;
- (void)insert:(LMServerRequest *)request at:(unsigned int)index;
- (LMServerRequest *)removeAt:(unsigned int)index;
- (void)remove:(LMServerRequest *)request;
- (void)persistEventually;
- (void)persistImmediately;
- (void)clearQueue;

- (BOOL)containsInstallOrOpen;
- (BOOL)containsClose;

- (BOOL)removeInstallOrOpen;

- (LMOpenRequest *)moveInstallOrOpenToFront:(NSInteger)networkCount;

+ (id)getInstance;

@property (readonly, assign, atomic) NSInteger queueDepth;

@end
