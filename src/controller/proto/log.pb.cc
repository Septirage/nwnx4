// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: log.proto

#include "log.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace Util {
namespace Log {
}  // namespace Log
}  // namespace Util
static constexpr ::PROTOBUF_NAMESPACE_ID::Metadata* file_level_metadata_log_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_log_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_log_2eproto = nullptr;
const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_log_2eproto::offsets[1] = {};
static constexpr ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema* schemas = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::Message* const* file_default_instances = nullptr;

const char descriptor_table_protodef_log_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\tlog.proto\022\010Util.Log\032\033google/protobuf/e"
  "mpty.proto\032\036google/protobuf/wrappers.pro"
  "to2\222\003\n\nLogService\022@\n\010logTrace\022\034.google.p"
  "rotobuf.StringValue\032\026.google.protobuf.Em"
  "pty\022@\n\010logDebug\022\034.google.protobuf.String"
  "Value\032\026.google.protobuf.Empty\022\?\n\007logInfo"
  "\022\034.google.protobuf.StringValue\032\026.google."
  "protobuf.Empty\022\?\n\007logWarn\022\034.google.proto"
  "buf.StringValue\032\026.google.protobuf.Empty\022"
  ">\n\006logErr\022\034.google.protobuf.StringValue\032"
  "\026.google.protobuf.Empty\022>\n\006logStr\022\034.goog"
  "le.protobuf.StringValue\032\026.google.protobu"
  "f.Emptyb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_log_2eproto_deps[2] = {
  &::descriptor_table_google_2fprotobuf_2fempty_2eproto,
  &::descriptor_table_google_2fprotobuf_2fwrappers_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_log_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_log_2eproto = {
  false, false, 495, descriptor_table_protodef_log_2eproto, "log.proto", 
  &descriptor_table_log_2eproto_once, descriptor_table_log_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_log_2eproto::offsets,
  file_level_metadata_log_2eproto, file_level_enum_descriptors_log_2eproto, file_level_service_descriptors_log_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK ::PROTOBUF_NAMESPACE_ID::Metadata
descriptor_table_log_2eproto_metadata_getter(int index) {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_log_2eproto);
  return descriptor_table_log_2eproto.file_level_metadata[index];
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_log_2eproto(&descriptor_table_log_2eproto);
namespace Util {
namespace Log {

// @@protoc_insertion_point(namespace_scope)
}  // namespace Log
}  // namespace Util
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
