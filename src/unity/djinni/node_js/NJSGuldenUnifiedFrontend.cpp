// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#include "NJSGuldenUnifiedFrontend.hpp"
#include "NJSObjectWrapper.hpp"

using namespace v8;
using namespace node;
using namespace std;

void NJSGuldenUnifiedFrontend::notifyUnifiedProgress_aimpl__(float progress)
{
    Nan::HandleScope scope;
    //Wrap parameters
    auto arg_0 = Nan::New<Number>(progress);
    Handle<Value> args[1] = {arg_0};
    Local<Object> local_njs_impl = Nan::New<Object>(njs_impl);
    if(!local_njs_impl->IsObject())
    {
        Nan::ThrowError("NJSGuldenUnifiedFrontend::notifyUnifiedProgress fail to retrieve node implementation");
    }
    auto calling_funtion = Nan::Get(local_njs_impl,Nan::New<String>("notifyUnifiedProgress").ToLocalChecked()).ToLocalChecked();
    auto result_notifyUnifiedProgress = Nan::CallAsFunction(calling_funtion->ToObject(),local_njs_impl,1,args);
    if(result_notifyUnifiedProgress.IsEmpty())
    {
        Nan::ThrowError("NJSGuldenUnifiedFrontend::notifyUnifiedProgress call failed");
    }
}

void NJSGuldenUnifiedFrontend::notifyUnifiedProgress(float progress)
{
    uv_work_t* request = new uv_work_t;
    request->data = new std::tuple<NJSGuldenUnifiedFrontend*, float>(this, progress);

    uv_queue_work(uv_default_loop(), request, [](uv_work_t*) -> void{}, [](uv_work_t* req, int status) -> void
    {
        NJSGuldenUnifiedFrontend* pthis = std::get<0>(*((std::tuple<NJSGuldenUnifiedFrontend*, float>*)req->data));
        pthis->notifyUnifiedProgress_aimpl__(std::get<1>(*((std::tuple<NJSGuldenUnifiedFrontend*, float>*)req->data)));
        delete (std::tuple<NJSGuldenUnifiedFrontend*, float>*)req->data;
        req->data = nullptr;
    }
    );
}

void NJSGuldenUnifiedFrontend::notifyBalanceChange_aimpl__(const BalanceRecord & new_balance)
{
    Nan::HandleScope scope;
    //Wrap parameters
    auto arg_0 = Nan::New<Object>();
    auto arg_0_1 = Nan::New<Number>(new_balance.availableIncludingLocked);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("availableIncludingLocked").ToLocalChecked(), arg_0_1);
    auto arg_0_2 = Nan::New<Number>(new_balance.availableExcludingLocked);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("availableExcludingLocked").ToLocalChecked(), arg_0_2);
    auto arg_0_3 = Nan::New<Number>(new_balance.availableLocked);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("availableLocked").ToLocalChecked(), arg_0_3);
    auto arg_0_4 = Nan::New<Number>(new_balance.unconfirmedIncludingLocked);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("unconfirmedIncludingLocked").ToLocalChecked(), arg_0_4);
    auto arg_0_5 = Nan::New<Number>(new_balance.unconfirmedExcludingLocked);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("unconfirmedExcludingLocked").ToLocalChecked(), arg_0_5);
    auto arg_0_6 = Nan::New<Number>(new_balance.unconfirmedLocked);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("unconfirmedLocked").ToLocalChecked(), arg_0_6);
    auto arg_0_7 = Nan::New<Number>(new_balance.immatureIncludingLocked);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("immatureIncludingLocked").ToLocalChecked(), arg_0_7);
    auto arg_0_8 = Nan::New<Number>(new_balance.immatureExcludingLocked);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("immatureExcludingLocked").ToLocalChecked(), arg_0_8);
    auto arg_0_9 = Nan::New<Number>(new_balance.immatureLocked);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("immatureLocked").ToLocalChecked(), arg_0_9);
    auto arg_0_10 = Nan::New<Number>(new_balance.totalLocked);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("totalLocked").ToLocalChecked(), arg_0_10);

    Handle<Value> args[1] = {arg_0};
    Local<Object> local_njs_impl = Nan::New<Object>(njs_impl);
    if(!local_njs_impl->IsObject())
    {
        Nan::ThrowError("NJSGuldenUnifiedFrontend::notifyBalanceChange fail to retrieve node implementation");
    }
    auto calling_funtion = Nan::Get(local_njs_impl,Nan::New<String>("notifyBalanceChange").ToLocalChecked()).ToLocalChecked();
    auto result_notifyBalanceChange = Nan::CallAsFunction(calling_funtion->ToObject(),local_njs_impl,1,args);
    if(result_notifyBalanceChange.IsEmpty())
    {
        Nan::ThrowError("NJSGuldenUnifiedFrontend::notifyBalanceChange call failed");
    }
}

void NJSGuldenUnifiedFrontend::notifyBalanceChange(const BalanceRecord & new_balance)
{
    uv_work_t* request = new uv_work_t;
    request->data = new std::tuple<NJSGuldenUnifiedFrontend*, BalanceRecord>(this, new_balance);

    uv_queue_work(uv_default_loop(), request, [](uv_work_t*) -> void{}, [](uv_work_t* req, int status) -> void
    {
        NJSGuldenUnifiedFrontend* pthis = std::get<0>(*((std::tuple<NJSGuldenUnifiedFrontend*, BalanceRecord>*)req->data));
        pthis->notifyBalanceChange_aimpl__(std::get<1>(*((std::tuple<NJSGuldenUnifiedFrontend*, BalanceRecord>*)req->data)));
        delete (std::tuple<NJSGuldenUnifiedFrontend*, BalanceRecord>*)req->data;
        req->data = nullptr;
    }
    );
}

void NJSGuldenUnifiedFrontend::notifyNewMutation_aimpl__(const MutationRecord & mutation, bool self_committed)
{
    Nan::HandleScope scope;
    //Wrap parameters
    auto arg_0 = Nan::New<Object>();
    auto arg_0_1 = Nan::New<Number>(mutation.change);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("change").ToLocalChecked(), arg_0_1);
    auto arg_0_2 = Nan::New<Number>(mutation.timestamp);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("timestamp").ToLocalChecked(), arg_0_2);
    auto arg_0_3 = Nan::New<String>(mutation.txHash).ToLocalChecked();
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("txHash").ToLocalChecked(), arg_0_3);
    auto arg_0_4 = Nan::New<Integer>((int)mutation.status);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("status").ToLocalChecked(), arg_0_4);
    auto arg_0_5 = Nan::New<Int32>(mutation.depth);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("depth").ToLocalChecked(), arg_0_5);

    auto arg_1 = Nan::New<Boolean>(self_committed);
    Handle<Value> args[2] = {arg_0,arg_1};
    Local<Object> local_njs_impl = Nan::New<Object>(njs_impl);
    if(!local_njs_impl->IsObject())
    {
        Nan::ThrowError("NJSGuldenUnifiedFrontend::notifyNewMutation fail to retrieve node implementation");
    }
    auto calling_funtion = Nan::Get(local_njs_impl,Nan::New<String>("notifyNewMutation").ToLocalChecked()).ToLocalChecked();
    auto result_notifyNewMutation = Nan::CallAsFunction(calling_funtion->ToObject(),local_njs_impl,2,args);
    if(result_notifyNewMutation.IsEmpty())
    {
        Nan::ThrowError("NJSGuldenUnifiedFrontend::notifyNewMutation call failed");
    }
}

void NJSGuldenUnifiedFrontend::notifyNewMutation(const MutationRecord & mutation, bool self_committed)
{
    uv_work_t* request = new uv_work_t;
    request->data = new std::tuple<NJSGuldenUnifiedFrontend*, MutationRecord, bool>(this, mutation, self_committed);

    uv_queue_work(uv_default_loop(), request, [](uv_work_t*) -> void{}, [](uv_work_t* req, int status) -> void
    {
        NJSGuldenUnifiedFrontend* pthis = std::get<0>(*((std::tuple<NJSGuldenUnifiedFrontend*, MutationRecord, bool>*)req->data));
        pthis->notifyNewMutation_aimpl__(std::get<1>(*((std::tuple<NJSGuldenUnifiedFrontend*, MutationRecord, bool>*)req->data)), std::get<2>(*((std::tuple<NJSGuldenUnifiedFrontend*, MutationRecord, bool>*)req->data)));
        delete (std::tuple<NJSGuldenUnifiedFrontend*, MutationRecord, bool>*)req->data;
        req->data = nullptr;
    }
    );
}

void NJSGuldenUnifiedFrontend::notifyUpdatedTransaction_aimpl__(const TransactionRecord & transaction)
{
    Nan::HandleScope scope;
    //Wrap parameters
    auto arg_0 = Nan::New<Object>();
    auto arg_0_1 = Nan::New<String>(transaction.txHash).ToLocalChecked();
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("txHash").ToLocalChecked(), arg_0_1);
    auto arg_0_2 = Nan::New<Number>(transaction.timeStamp);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("timeStamp").ToLocalChecked(), arg_0_2);
    auto arg_0_3 = Nan::New<Number>(transaction.amount);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("amount").ToLocalChecked(), arg_0_3);
    auto arg_0_4 = Nan::New<Number>(transaction.fee);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("fee").ToLocalChecked(), arg_0_4);
    auto arg_0_5 = Nan::New<Integer>((int)transaction.status);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("status").ToLocalChecked(), arg_0_5);
    auto arg_0_6 = Nan::New<Int32>(transaction.height);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("height").ToLocalChecked(), arg_0_6);
    auto arg_0_7 = Nan::New<Number>(transaction.blockTime);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("blockTime").ToLocalChecked(), arg_0_7);
    auto arg_0_8 = Nan::New<Int32>(transaction.depth);
    Nan::DefineOwnProperty(arg_0, Nan::New<String>("depth").ToLocalChecked(), arg_0_8);
    Local<Array> arg_0_9 = Nan::New<Array>();
    for(size_t arg_0_9_id = 0; arg_0_9_id < transaction.inputs.size(); arg_0_9_id++)
    {
        auto arg_0_9_elem = Nan::New<Object>();
        auto arg_0_9_elem_1 = Nan::New<String>(transaction.inputs[arg_0_9_id].address).ToLocalChecked();
        Nan::DefineOwnProperty(arg_0_9_elem, Nan::New<String>("address").ToLocalChecked(), arg_0_9_elem_1);
        auto arg_0_9_elem_2 = Nan::New<String>(transaction.inputs[arg_0_9_id].label).ToLocalChecked();
        Nan::DefineOwnProperty(arg_0_9_elem, Nan::New<String>("label").ToLocalChecked(), arg_0_9_elem_2);
        auto arg_0_9_elem_3 = Nan::New<String>(transaction.inputs[arg_0_9_id].desc).ToLocalChecked();
        Nan::DefineOwnProperty(arg_0_9_elem, Nan::New<String>("desc").ToLocalChecked(), arg_0_9_elem_3);
        auto arg_0_9_elem_4 = Nan::New<Boolean>(transaction.inputs[arg_0_9_id].isMine);
        Nan::DefineOwnProperty(arg_0_9_elem, Nan::New<String>("isMine").ToLocalChecked(), arg_0_9_elem_4);

        arg_0_9->Set((int)arg_0_9_id,arg_0_9_elem);
    }

    Nan::DefineOwnProperty(arg_0, Nan::New<String>("inputs").ToLocalChecked(), arg_0_9);
    Local<Array> arg_0_10 = Nan::New<Array>();
    for(size_t arg_0_10_id = 0; arg_0_10_id < transaction.outputs.size(); arg_0_10_id++)
    {
        auto arg_0_10_elem = Nan::New<Object>();
        auto arg_0_10_elem_1 = Nan::New<Number>(transaction.outputs[arg_0_10_id].amount);
        Nan::DefineOwnProperty(arg_0_10_elem, Nan::New<String>("amount").ToLocalChecked(), arg_0_10_elem_1);
        auto arg_0_10_elem_2 = Nan::New<String>(transaction.outputs[arg_0_10_id].address).ToLocalChecked();
        Nan::DefineOwnProperty(arg_0_10_elem, Nan::New<String>("address").ToLocalChecked(), arg_0_10_elem_2);
        auto arg_0_10_elem_3 = Nan::New<String>(transaction.outputs[arg_0_10_id].label).ToLocalChecked();
        Nan::DefineOwnProperty(arg_0_10_elem, Nan::New<String>("label").ToLocalChecked(), arg_0_10_elem_3);
        auto arg_0_10_elem_4 = Nan::New<String>(transaction.outputs[arg_0_10_id].desc).ToLocalChecked();
        Nan::DefineOwnProperty(arg_0_10_elem, Nan::New<String>("desc").ToLocalChecked(), arg_0_10_elem_4);
        auto arg_0_10_elem_5 = Nan::New<Boolean>(transaction.outputs[arg_0_10_id].isMine);
        Nan::DefineOwnProperty(arg_0_10_elem, Nan::New<String>("isMine").ToLocalChecked(), arg_0_10_elem_5);

        arg_0_10->Set((int)arg_0_10_id,arg_0_10_elem);
    }

    Nan::DefineOwnProperty(arg_0, Nan::New<String>("outputs").ToLocalChecked(), arg_0_10);

    Handle<Value> args[1] = {arg_0};
    Local<Object> local_njs_impl = Nan::New<Object>(njs_impl);
    if(!local_njs_impl->IsObject())
    {
        Nan::ThrowError("NJSGuldenUnifiedFrontend::notifyUpdatedTransaction fail to retrieve node implementation");
    }
    auto calling_funtion = Nan::Get(local_njs_impl,Nan::New<String>("notifyUpdatedTransaction").ToLocalChecked()).ToLocalChecked();
    auto result_notifyUpdatedTransaction = Nan::CallAsFunction(calling_funtion->ToObject(),local_njs_impl,1,args);
    if(result_notifyUpdatedTransaction.IsEmpty())
    {
        Nan::ThrowError("NJSGuldenUnifiedFrontend::notifyUpdatedTransaction call failed");
    }
}

void NJSGuldenUnifiedFrontend::notifyUpdatedTransaction(const TransactionRecord & transaction)
{
    uv_work_t* request = new uv_work_t;
    request->data = new std::tuple<NJSGuldenUnifiedFrontend*, TransactionRecord>(this, transaction);

    uv_queue_work(uv_default_loop(), request, [](uv_work_t*) -> void{}, [](uv_work_t* req, int status) -> void
    {
        NJSGuldenUnifiedFrontend* pthis = std::get<0>(*((std::tuple<NJSGuldenUnifiedFrontend*, TransactionRecord>*)req->data));
        pthis->notifyUpdatedTransaction_aimpl__(std::get<1>(*((std::tuple<NJSGuldenUnifiedFrontend*, TransactionRecord>*)req->data)));
        delete (std::tuple<NJSGuldenUnifiedFrontend*, TransactionRecord>*)req->data;
        req->data = nullptr;
    }
    );
}

void NJSGuldenUnifiedFrontend::notifyInitWithExistingWallet_aimpl__()
{
    Nan::HandleScope scope;
    //Wrap parameters
    Handle<Value> args[1];
    Local<Object> local_njs_impl = Nan::New<Object>(njs_impl);
    if(!local_njs_impl->IsObject())
    {
        Nan::ThrowError("NJSGuldenUnifiedFrontend::notifyInitWithExistingWallet fail to retrieve node implementation");
    }
    auto calling_funtion = Nan::Get(local_njs_impl,Nan::New<String>("notifyInitWithExistingWallet").ToLocalChecked()).ToLocalChecked();
    auto result_notifyInitWithExistingWallet = Nan::CallAsFunction(calling_funtion->ToObject(),local_njs_impl,0,args);
    if(result_notifyInitWithExistingWallet.IsEmpty())
    {
        Nan::ThrowError("NJSGuldenUnifiedFrontend::notifyInitWithExistingWallet call failed");
    }
}

void NJSGuldenUnifiedFrontend::notifyInitWithExistingWallet()
{
    uv_work_t* request = new uv_work_t;
    request->data = new std::tuple<NJSGuldenUnifiedFrontend*>(this);

    uv_queue_work(uv_default_loop(), request, [](uv_work_t*) -> void{}, [](uv_work_t* req, int status) -> void
    {
        NJSGuldenUnifiedFrontend* pthis = std::get<0>(*((std::tuple<NJSGuldenUnifiedFrontend*>*)req->data));
        pthis->notifyInitWithExistingWallet_aimpl__();
        delete (std::tuple<NJSGuldenUnifiedFrontend*>*)req->data;
        req->data = nullptr;
    }
    );
}

void NJSGuldenUnifiedFrontend::notifyInitWithoutExistingWallet_aimpl__()
{
    Nan::HandleScope scope;
    //Wrap parameters
    Handle<Value> args[1];
    Local<Object> local_njs_impl = Nan::New<Object>(njs_impl);
    if(!local_njs_impl->IsObject())
    {
        Nan::ThrowError("NJSGuldenUnifiedFrontend::notifyInitWithoutExistingWallet fail to retrieve node implementation");
    }
    auto calling_funtion = Nan::Get(local_njs_impl,Nan::New<String>("notifyInitWithoutExistingWallet").ToLocalChecked()).ToLocalChecked();
    auto result_notifyInitWithoutExistingWallet = Nan::CallAsFunction(calling_funtion->ToObject(),local_njs_impl,0,args);
    if(result_notifyInitWithoutExistingWallet.IsEmpty())
    {
        Nan::ThrowError("NJSGuldenUnifiedFrontend::notifyInitWithoutExistingWallet call failed");
    }
}

void NJSGuldenUnifiedFrontend::notifyInitWithoutExistingWallet()
{
    uv_work_t* request = new uv_work_t;
    request->data = new std::tuple<NJSGuldenUnifiedFrontend*>(this);

    uv_queue_work(uv_default_loop(), request, [](uv_work_t*) -> void{}, [](uv_work_t* req, int status) -> void
    {
        NJSGuldenUnifiedFrontend* pthis = std::get<0>(*((std::tuple<NJSGuldenUnifiedFrontend*>*)req->data));
        pthis->notifyInitWithoutExistingWallet_aimpl__();
        delete (std::tuple<NJSGuldenUnifiedFrontend*>*)req->data;
        req->data = nullptr;
    }
    );
}

void NJSGuldenUnifiedFrontend::notifyShutdown_aimpl__()
{
    Nan::HandleScope scope;
    //Wrap parameters
    Handle<Value> args[1];
    Local<Object> local_njs_impl = Nan::New<Object>(njs_impl);
    if(!local_njs_impl->IsObject())
    {
        Nan::ThrowError("NJSGuldenUnifiedFrontend::notifyShutdown fail to retrieve node implementation");
    }
    auto calling_funtion = Nan::Get(local_njs_impl,Nan::New<String>("notifyShutdown").ToLocalChecked()).ToLocalChecked();
    auto result_notifyShutdown = Nan::CallAsFunction(calling_funtion->ToObject(),local_njs_impl,0,args);
    if(result_notifyShutdown.IsEmpty())
    {
        Nan::ThrowError("NJSGuldenUnifiedFrontend::notifyShutdown call failed");
    }
}

void NJSGuldenUnifiedFrontend::notifyShutdown()
{
    uv_work_t* request = new uv_work_t;
    request->data = new std::tuple<NJSGuldenUnifiedFrontend*>(this);

    uv_queue_work(uv_default_loop(), request, [](uv_work_t*) -> void{}, [](uv_work_t* req, int status) -> void
    {
        NJSGuldenUnifiedFrontend* pthis = std::get<0>(*((std::tuple<NJSGuldenUnifiedFrontend*>*)req->data));
        pthis->notifyShutdown_aimpl__();
        delete (std::tuple<NJSGuldenUnifiedFrontend*>*)req->data;
        req->data = nullptr;
    }
    );
}

void NJSGuldenUnifiedFrontend::notifyCoreReady_aimpl__()
{
    Nan::HandleScope scope;
    //Wrap parameters
    Handle<Value> args[1];
    Local<Object> local_njs_impl = Nan::New<Object>(njs_impl);
    if(!local_njs_impl->IsObject())
    {
        Nan::ThrowError("NJSGuldenUnifiedFrontend::notifyCoreReady fail to retrieve node implementation");
    }
    auto calling_funtion = Nan::Get(local_njs_impl,Nan::New<String>("notifyCoreReady").ToLocalChecked()).ToLocalChecked();
    auto result_notifyCoreReady = Nan::CallAsFunction(calling_funtion->ToObject(),local_njs_impl,0,args);
    if(result_notifyCoreReady.IsEmpty())
    {
        Nan::ThrowError("NJSGuldenUnifiedFrontend::notifyCoreReady call failed");
    }
}

void NJSGuldenUnifiedFrontend::notifyCoreReady()
{
    uv_work_t* request = new uv_work_t;
    request->data = new std::tuple<NJSGuldenUnifiedFrontend*>(this);

    uv_queue_work(uv_default_loop(), request, [](uv_work_t*) -> void{}, [](uv_work_t* req, int status) -> void
    {
        NJSGuldenUnifiedFrontend* pthis = std::get<0>(*((std::tuple<NJSGuldenUnifiedFrontend*>*)req->data));
        pthis->notifyCoreReady_aimpl__();
        delete (std::tuple<NJSGuldenUnifiedFrontend*>*)req->data;
        req->data = nullptr;
    }
    );
}

void NJSGuldenUnifiedFrontend::logPrint_aimpl__(const std::string & str)
{
    Nan::HandleScope scope;
    //Wrap parameters
    auto arg_0 = Nan::New<String>(str).ToLocalChecked();
    Handle<Value> args[1] = {arg_0};
    Local<Object> local_njs_impl = Nan::New<Object>(njs_impl);
    if(!local_njs_impl->IsObject())
    {
        Nan::ThrowError("NJSGuldenUnifiedFrontend::logPrint fail to retrieve node implementation");
    }
    auto calling_funtion = Nan::Get(local_njs_impl,Nan::New<String>("logPrint").ToLocalChecked()).ToLocalChecked();
    auto result_logPrint = Nan::CallAsFunction(calling_funtion->ToObject(),local_njs_impl,1,args);
    if(result_logPrint.IsEmpty())
    {
        Nan::ThrowError("NJSGuldenUnifiedFrontend::logPrint call failed");
    }
}

void NJSGuldenUnifiedFrontend::logPrint(const std::string & str)
{
    uv_work_t* request = new uv_work_t;
    request->data = new std::tuple<NJSGuldenUnifiedFrontend*, std::string>(this, str);

    uv_queue_work(uv_default_loop(), request, [](uv_work_t*) -> void{}, [](uv_work_t* req, int status) -> void
    {
        NJSGuldenUnifiedFrontend* pthis = std::get<0>(*((std::tuple<NJSGuldenUnifiedFrontend*, std::string>*)req->data));
        pthis->logPrint_aimpl__(std::get<1>(*((std::tuple<NJSGuldenUnifiedFrontend*, std::string>*)req->data)));
        delete (std::tuple<NJSGuldenUnifiedFrontend*, std::string>*)req->data;
        req->data = nullptr;
    }
    );
}

NAN_METHOD(NJSGuldenUnifiedFrontend::New) {
    //Only new allowed
    if(!info.IsConstructCall())
    {
        return Nan::ThrowError("NJSGuldenUnifiedFrontend function can only be called as constructor (use New)");
    }
    if(!info[0]->IsObject())
    {
        return Nan::ThrowError("NJSGuldenUnifiedFrontend::New requires an implementation from node");
    }
    auto node_instance = std::make_shared<NJSGuldenUnifiedFrontend>(info[0]->ToObject());
    djinni::js::ObjectWrapper<NJSGuldenUnifiedFrontend>::Wrap(node_instance, info.This());
    info.GetReturnValue().Set(info.This());
}


Nan::Persistent<ObjectTemplate> NJSGuldenUnifiedFrontend::GuldenUnifiedFrontend_prototype;

Local<Object> NJSGuldenUnifiedFrontend::wrap(const std::shared_ptr<::GuldenUnifiedFrontend> &object) {
    Nan::EscapableHandleScope scope;
    Local<ObjectTemplate> local_prototype = Nan::New(GuldenUnifiedFrontend_prototype);

    Local<Object> obj;
    if(!local_prototype.IsEmpty())
    {
        obj = local_prototype->NewInstance();
        djinni::js::ObjectWrapper<::GuldenUnifiedFrontend>::Wrap(object, obj);
    }
    else
    {
        Nan::ThrowError("NJSGuldenUnifiedFrontend::wrap: object template not valid");
    }
    return scope.Escape(obj);
}

void NJSGuldenUnifiedFrontend::Initialize(Local<Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> func_template = Nan::New<FunctionTemplate>(NJSGuldenUnifiedFrontend::New);
    Local<ObjectTemplate> objectTemplate = func_template->InstanceTemplate();
    objectTemplate->SetInternalFieldCount(1);

    func_template->SetClassName(Nan::New<String>("NJSGuldenUnifiedFrontend").ToLocalChecked());
    Nan::SetPrototypeMethod(func_template,"New", New);
    //Set object prototype
    GuldenUnifiedFrontend_prototype.Reset(objectTemplate);

    //Add template to target
    target->Set(Nan::New<String>("NJSGuldenUnifiedFrontend").ToLocalChecked(), func_template->GetFunction());
}
