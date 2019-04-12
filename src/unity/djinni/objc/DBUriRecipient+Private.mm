// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#import "DBUriRecipient+Private.h"
#import "DJIMarshal+Private.h"
#include <cassert>

namespace djinni_generated {

auto UriRecipient::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::Bool::toCpp(obj.valid),
            ::djinni::String::toCpp(obj.address),
            ::djinni::String::toCpp(obj.label),
            ::djinni::I64::toCpp(obj.amount)};
}

auto UriRecipient::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[DBUriRecipient alloc] initWithValid:(::djinni::Bool::fromCpp(cpp.valid))
                                         address:(::djinni::String::fromCpp(cpp.address))
                                           label:(::djinni::String::fromCpp(cpp.label))
                                          amount:(::djinni::I64::fromCpp(cpp.amount))];
}

}  // namespace djinni_generated
