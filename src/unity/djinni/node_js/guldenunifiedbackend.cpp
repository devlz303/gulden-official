// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni

#include <napi.h>

#include "NJSGuldenUnifiedBackend.hpp"
#include "NJSGuldenUnifiedFrontend.hpp"
#include "NJSGuldenMonitorListener.hpp"


Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
    NJSGuldenUnifiedBackend::Init(env, exports);
    NJSGuldenUnifiedFrontend::Init(env, exports);
    NJSGuldenMonitorListener::Init(env, exports);
    return exports;
}
NODE_API_MODULE(guldenunifiedbackend,InitAll);
