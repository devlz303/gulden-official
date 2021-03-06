// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#import <Foundation/Foundation.h>

@interface DBAddressRecord : NSObject
- (nonnull instancetype)initWithAddress:(nonnull NSString *)address
                                   name:(nonnull NSString *)name
                                   desc:(nonnull NSString *)desc
                                purpose:(nonnull NSString *)purpose;
+ (nonnull instancetype)addressRecordWithAddress:(nonnull NSString *)address
                                            name:(nonnull NSString *)name
                                            desc:(nonnull NSString *)desc
                                         purpose:(nonnull NSString *)purpose;

@property (nonatomic, readonly, nonnull) NSString * address;

@property (nonatomic, readonly, nonnull) NSString * name;

@property (nonatomic, readonly, nonnull) NSString * desc;

@property (nonatomic, readonly, nonnull) NSString * purpose;

@end
