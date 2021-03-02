// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Reply.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Reply_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Reply_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3008000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3008000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Reply_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Reply_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Reply_2eproto;
class Reply;
class ReplyDefaultTypeInternal;
extern ReplyDefaultTypeInternal _Reply_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::Reply* Arena::CreateMaybeMessage<::Reply>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

enum Reply_Header : int {
  Reply_Header_UNKNOWN_HEADER = 0,
  Reply_Header_ESTABLISH_CONNECTION = 1,
  Reply_Header_START_STREAM = 2,
  Reply_Header_STOP_STREAM = 3,
  Reply_Header_START_TRACKING = 4,
  Reply_Header_STOP_TRACKING = 5,
  Reply_Header_Reply_Header_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  Reply_Header_Reply_Header_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool Reply_Header_IsValid(int value);
constexpr Reply_Header Reply_Header_Header_MIN = Reply_Header_UNKNOWN_HEADER;
constexpr Reply_Header Reply_Header_Header_MAX = Reply_Header_STOP_TRACKING;
constexpr int Reply_Header_Header_ARRAYSIZE = Reply_Header_Header_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Reply_Header_descriptor();
template<typename T>
inline const std::string& Reply_Header_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Reply_Header>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Reply_Header_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    Reply_Header_descriptor(), enum_t_value);
}
inline bool Reply_Header_Parse(
    const std::string& name, Reply_Header* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<Reply_Header>(
    Reply_Header_descriptor(), name, value);
}
enum Reply_Status : int {
  Reply_Status_UNKNOWN_STATUS = 0,
  Reply_Status_SUCCESS = 1,
  Reply_Status_FAIL = 2,
  Reply_Status_Reply_Status_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  Reply_Status_Reply_Status_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool Reply_Status_IsValid(int value);
constexpr Reply_Status Reply_Status_Status_MIN = Reply_Status_UNKNOWN_STATUS;
constexpr Reply_Status Reply_Status_Status_MAX = Reply_Status_FAIL;
constexpr int Reply_Status_Status_ARRAYSIZE = Reply_Status_Status_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Reply_Status_descriptor();
template<typename T>
inline const std::string& Reply_Status_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Reply_Status>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Reply_Status_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    Reply_Status_descriptor(), enum_t_value);
}
inline bool Reply_Status_Parse(
    const std::string& name, Reply_Status* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<Reply_Status>(
    Reply_Status_descriptor(), name, value);
}
// ===================================================================

class Reply :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Reply) */ {
 public:
  Reply();
  virtual ~Reply();

  Reply(const Reply& from);
  Reply(Reply&& from) noexcept
    : Reply() {
    *this = ::std::move(from);
  }

  inline Reply& operator=(const Reply& from) {
    CopyFrom(from);
    return *this;
  }
  inline Reply& operator=(Reply&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Reply& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Reply* internal_default_instance() {
    return reinterpret_cast<const Reply*>(
               &_Reply_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Reply* other);
  friend void swap(Reply& a, Reply& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Reply* New() const final {
    return CreateMaybeMessage<Reply>(nullptr);
  }

  Reply* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Reply>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Reply& from);
  void MergeFrom(const Reply& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Reply* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Reply";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_Reply_2eproto);
    return ::descriptor_table_Reply_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef Reply_Header Header;
  static constexpr Header UNKNOWN_HEADER =
    Reply_Header_UNKNOWN_HEADER;
  static constexpr Header ESTABLISH_CONNECTION =
    Reply_Header_ESTABLISH_CONNECTION;
  static constexpr Header START_STREAM =
    Reply_Header_START_STREAM;
  static constexpr Header STOP_STREAM =
    Reply_Header_STOP_STREAM;
  static constexpr Header START_TRACKING =
    Reply_Header_START_TRACKING;
  static constexpr Header STOP_TRACKING =
    Reply_Header_STOP_TRACKING;
  static inline bool Header_IsValid(int value) {
    return Reply_Header_IsValid(value);
  }
  static constexpr Header Header_MIN =
    Reply_Header_Header_MIN;
  static constexpr Header Header_MAX =
    Reply_Header_Header_MAX;
  static constexpr int Header_ARRAYSIZE =
    Reply_Header_Header_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  Header_descriptor() {
    return Reply_Header_descriptor();
  }
  template<typename T>
  static inline const std::string& Header_Name(T enum_t_value) {
    static_assert(::std::is_same<T, Header>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function Header_Name.");
    return Reply_Header_Name(enum_t_value);
  }
  static inline bool Header_Parse(const std::string& name,
      Header* value) {
    return Reply_Header_Parse(name, value);
  }

  typedef Reply_Status Status;
  static constexpr Status UNKNOWN_STATUS =
    Reply_Status_UNKNOWN_STATUS;
  static constexpr Status SUCCESS =
    Reply_Status_SUCCESS;
  static constexpr Status FAIL =
    Reply_Status_FAIL;
  static inline bool Status_IsValid(int value) {
    return Reply_Status_IsValid(value);
  }
  static constexpr Status Status_MIN =
    Reply_Status_Status_MIN;
  static constexpr Status Status_MAX =
    Reply_Status_Status_MAX;
  static constexpr int Status_ARRAYSIZE =
    Reply_Status_Status_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  Status_descriptor() {
    return Reply_Status_descriptor();
  }
  template<typename T>
  static inline const std::string& Status_Name(T enum_t_value) {
    static_assert(::std::is_same<T, Status>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function Status_Name.");
    return Reply_Status_Name(enum_t_value);
  }
  static inline bool Status_Parse(const std::string& name,
      Status* value) {
    return Reply_Status_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // string description = 3;
  void clear_description();
  static const int kDescriptionFieldNumber = 3;
  const std::string& description() const;
  void set_description(const std::string& value);
  void set_description(std::string&& value);
  void set_description(const char* value);
  void set_description(const char* value, size_t size);
  std::string* mutable_description();
  std::string* release_description();
  void set_allocated_description(std::string* description);

  // .Reply.Header header = 1;
  void clear_header();
  static const int kHeaderFieldNumber = 1;
  ::Reply_Header header() const;
  void set_header(::Reply_Header value);

  // .Reply.Status status = 2;
  void clear_status();
  static const int kStatusFieldNumber = 2;
  ::Reply_Status status() const;
  void set_status(::Reply_Status value);

  // @@protoc_insertion_point(class_scope:Reply)
 private:
  class HasBitSetters;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr description_;
  int header_;
  int status_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Reply_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Reply

// .Reply.Header header = 1;
inline void Reply::clear_header() {
  header_ = 0;
}
inline ::Reply_Header Reply::header() const {
  // @@protoc_insertion_point(field_get:Reply.header)
  return static_cast< ::Reply_Header >(header_);
}
inline void Reply::set_header(::Reply_Header value) {
  
  header_ = value;
  // @@protoc_insertion_point(field_set:Reply.header)
}

// .Reply.Status status = 2;
inline void Reply::clear_status() {
  status_ = 0;
}
inline ::Reply_Status Reply::status() const {
  // @@protoc_insertion_point(field_get:Reply.status)
  return static_cast< ::Reply_Status >(status_);
}
inline void Reply::set_status(::Reply_Status value) {
  
  status_ = value;
  // @@protoc_insertion_point(field_set:Reply.status)
}

// string description = 3;
inline void Reply::clear_description() {
  description_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& Reply::description() const {
  // @@protoc_insertion_point(field_get:Reply.description)
  return description_.GetNoArena();
}
inline void Reply::set_description(const std::string& value) {
  
  description_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Reply.description)
}
inline void Reply::set_description(std::string&& value) {
  
  description_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Reply.description)
}
inline void Reply::set_description(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  description_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Reply.description)
}
inline void Reply::set_description(const char* value, size_t size) {
  
  description_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Reply.description)
}
inline std::string* Reply::mutable_description() {
  
  // @@protoc_insertion_point(field_mutable:Reply.description)
  return description_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* Reply::release_description() {
  // @@protoc_insertion_point(field_release:Reply.description)
  
  return description_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void Reply::set_allocated_description(std::string* description) {
  if (description != nullptr) {
    
  } else {
    
  }
  description_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), description);
  // @@protoc_insertion_point(field_set_allocated:Reply.description)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::Reply_Header> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Reply_Header>() {
  return ::Reply_Header_descriptor();
}
template <> struct is_proto_enum< ::Reply_Status> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Reply_Status>() {
  return ::Reply_Status_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Reply_2eproto