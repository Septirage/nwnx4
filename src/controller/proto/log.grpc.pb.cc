// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: log.proto

#include "log.pb.h"
#include "log.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace Util {
namespace Log {

static const char* LogService_method_names[] = {
  "/Util.Log.LogService/logTrace",
  "/Util.Log.LogService/logDebug",
  "/Util.Log.LogService/logInfo",
  "/Util.Log.LogService/logWarn",
  "/Util.Log.LogService/logErr",
  "/Util.Log.LogService/logStr",
};

std::unique_ptr< LogService::Stub> LogService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< LogService::Stub> stub(new LogService::Stub(channel));
  return stub;
}

LogService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_logTrace_(LogService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_logDebug_(LogService_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_logInfo_(LogService_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_logWarn_(LogService_method_names[3], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_logErr_(LogService_method_names[4], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_logStr_(LogService_method_names[5], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status LogService::Stub::logTrace(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::google::protobuf::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall< ::google::protobuf::StringValue, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_logTrace_, context, request, response);
}

void LogService::Stub::experimental_async::logTrace(::grpc::ClientContext* context, const ::google::protobuf::StringValue* request, ::google::protobuf::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::google::protobuf::StringValue, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_logTrace_, context, request, response, std::move(f));
}

void LogService::Stub::experimental_async::logTrace(::grpc::ClientContext* context, const ::google::protobuf::StringValue* request, ::google::protobuf::Empty* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_logTrace_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* LogService::Stub::PrepareAsynclogTraceRaw(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::google::protobuf::Empty, ::google::protobuf::StringValue, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_logTrace_, context, request);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* LogService::Stub::AsynclogTraceRaw(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsynclogTraceRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status LogService::Stub::logDebug(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::google::protobuf::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall< ::google::protobuf::StringValue, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_logDebug_, context, request, response);
}

void LogService::Stub::experimental_async::logDebug(::grpc::ClientContext* context, const ::google::protobuf::StringValue* request, ::google::protobuf::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::google::protobuf::StringValue, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_logDebug_, context, request, response, std::move(f));
}

void LogService::Stub::experimental_async::logDebug(::grpc::ClientContext* context, const ::google::protobuf::StringValue* request, ::google::protobuf::Empty* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_logDebug_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* LogService::Stub::PrepareAsynclogDebugRaw(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::google::protobuf::Empty, ::google::protobuf::StringValue, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_logDebug_, context, request);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* LogService::Stub::AsynclogDebugRaw(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsynclogDebugRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status LogService::Stub::logInfo(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::google::protobuf::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall< ::google::protobuf::StringValue, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_logInfo_, context, request, response);
}

void LogService::Stub::experimental_async::logInfo(::grpc::ClientContext* context, const ::google::protobuf::StringValue* request, ::google::protobuf::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::google::protobuf::StringValue, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_logInfo_, context, request, response, std::move(f));
}

void LogService::Stub::experimental_async::logInfo(::grpc::ClientContext* context, const ::google::protobuf::StringValue* request, ::google::protobuf::Empty* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_logInfo_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* LogService::Stub::PrepareAsynclogInfoRaw(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::google::protobuf::Empty, ::google::protobuf::StringValue, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_logInfo_, context, request);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* LogService::Stub::AsynclogInfoRaw(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsynclogInfoRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status LogService::Stub::logWarn(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::google::protobuf::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall< ::google::protobuf::StringValue, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_logWarn_, context, request, response);
}

void LogService::Stub::experimental_async::logWarn(::grpc::ClientContext* context, const ::google::protobuf::StringValue* request, ::google::protobuf::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::google::protobuf::StringValue, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_logWarn_, context, request, response, std::move(f));
}

void LogService::Stub::experimental_async::logWarn(::grpc::ClientContext* context, const ::google::protobuf::StringValue* request, ::google::protobuf::Empty* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_logWarn_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* LogService::Stub::PrepareAsynclogWarnRaw(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::google::protobuf::Empty, ::google::protobuf::StringValue, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_logWarn_, context, request);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* LogService::Stub::AsynclogWarnRaw(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsynclogWarnRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status LogService::Stub::logErr(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::google::protobuf::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall< ::google::protobuf::StringValue, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_logErr_, context, request, response);
}

void LogService::Stub::experimental_async::logErr(::grpc::ClientContext* context, const ::google::protobuf::StringValue* request, ::google::protobuf::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::google::protobuf::StringValue, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_logErr_, context, request, response, std::move(f));
}

void LogService::Stub::experimental_async::logErr(::grpc::ClientContext* context, const ::google::protobuf::StringValue* request, ::google::protobuf::Empty* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_logErr_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* LogService::Stub::PrepareAsynclogErrRaw(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::google::protobuf::Empty, ::google::protobuf::StringValue, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_logErr_, context, request);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* LogService::Stub::AsynclogErrRaw(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsynclogErrRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status LogService::Stub::logStr(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::google::protobuf::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall< ::google::protobuf::StringValue, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_logStr_, context, request, response);
}

void LogService::Stub::experimental_async::logStr(::grpc::ClientContext* context, const ::google::protobuf::StringValue* request, ::google::protobuf::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::google::protobuf::StringValue, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_logStr_, context, request, response, std::move(f));
}

void LogService::Stub::experimental_async::logStr(::grpc::ClientContext* context, const ::google::protobuf::StringValue* request, ::google::protobuf::Empty* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_logStr_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* LogService::Stub::PrepareAsynclogStrRaw(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::google::protobuf::Empty, ::google::protobuf::StringValue, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_logStr_, context, request);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* LogService::Stub::AsynclogStrRaw(::grpc::ClientContext* context, const ::google::protobuf::StringValue& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsynclogStrRaw(context, request, cq);
  result->StartCall();
  return result;
}

LogService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LogService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LogService::Service, ::google::protobuf::StringValue, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](LogService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::google::protobuf::StringValue* req,
             ::google::protobuf::Empty* resp) {
               return service->logTrace(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LogService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LogService::Service, ::google::protobuf::StringValue, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](LogService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::google::protobuf::StringValue* req,
             ::google::protobuf::Empty* resp) {
               return service->logDebug(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LogService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LogService::Service, ::google::protobuf::StringValue, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](LogService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::google::protobuf::StringValue* req,
             ::google::protobuf::Empty* resp) {
               return service->logInfo(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LogService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LogService::Service, ::google::protobuf::StringValue, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](LogService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::google::protobuf::StringValue* req,
             ::google::protobuf::Empty* resp) {
               return service->logWarn(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LogService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LogService::Service, ::google::protobuf::StringValue, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](LogService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::google::protobuf::StringValue* req,
             ::google::protobuf::Empty* resp) {
               return service->logErr(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LogService_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LogService::Service, ::google::protobuf::StringValue, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](LogService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::google::protobuf::StringValue* req,
             ::google::protobuf::Empty* resp) {
               return service->logStr(ctx, req, resp);
             }, this)));
}

LogService::Service::~Service() {
}

::grpc::Status LogService::Service::logTrace(::grpc::ServerContext* context, const ::google::protobuf::StringValue* request, ::google::protobuf::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LogService::Service::logDebug(::grpc::ServerContext* context, const ::google::protobuf::StringValue* request, ::google::protobuf::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LogService::Service::logInfo(::grpc::ServerContext* context, const ::google::protobuf::StringValue* request, ::google::protobuf::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LogService::Service::logWarn(::grpc::ServerContext* context, const ::google::protobuf::StringValue* request, ::google::protobuf::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LogService::Service::logErr(::grpc::ServerContext* context, const ::google::protobuf::StringValue* request, ::google::protobuf::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LogService::Service::logStr(::grpc::ServerContext* context, const ::google::protobuf::StringValue* request, ::google::protobuf::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace Util
}  // namespace Log

