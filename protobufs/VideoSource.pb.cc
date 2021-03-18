// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: VideoSource.proto

#include "VideoSource.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
class VideoSourceDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<VideoSource> _instance;
} _VideoSource_default_instance_;
static void InitDefaultsscc_info_VideoSource_VideoSource_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_VideoSource_default_instance_;
    new (ptr) ::VideoSource();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::VideoSource::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_VideoSource_VideoSource_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsscc_info_VideoSource_VideoSource_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_VideoSource_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_VideoSource_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_VideoSource_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_VideoSource_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::VideoSource, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::VideoSource, path_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::VideoSource)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_VideoSource_default_instance_),
};

const char descriptor_table_protodef_VideoSource_2eproto[] =
  "\n\021VideoSource.proto\"\033\n\013VideoSource\022\014\n\004pa"
  "th\030\001 \001(\tb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_VideoSource_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_VideoSource_2eproto_sccs[1] = {
  &scc_info_VideoSource_VideoSource_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_VideoSource_2eproto_once;
static bool descriptor_table_VideoSource_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_VideoSource_2eproto = {
  &descriptor_table_VideoSource_2eproto_initialized, descriptor_table_protodef_VideoSource_2eproto, "VideoSource.proto", 56,
  &descriptor_table_VideoSource_2eproto_once, descriptor_table_VideoSource_2eproto_sccs, descriptor_table_VideoSource_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_VideoSource_2eproto::offsets,
  file_level_metadata_VideoSource_2eproto, 1, file_level_enum_descriptors_VideoSource_2eproto, file_level_service_descriptors_VideoSource_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_VideoSource_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_VideoSource_2eproto), true);

// ===================================================================

void VideoSource::InitAsDefaultInstance() {
}
class VideoSource::HasBitSetters {
 public:
};

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int VideoSource::kPathFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

VideoSource::VideoSource()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:VideoSource)
}
VideoSource::VideoSource(const VideoSource& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  path_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.path().size() > 0) {
    path_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.path_);
  }
  // @@protoc_insertion_point(copy_constructor:VideoSource)
}

void VideoSource::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_VideoSource_VideoSource_2eproto.base);
  path_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

VideoSource::~VideoSource() {
  // @@protoc_insertion_point(destructor:VideoSource)
  SharedDtor();
}

void VideoSource::SharedDtor() {
  path_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void VideoSource::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const VideoSource& VideoSource::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_VideoSource_VideoSource_2eproto.base);
  return *internal_default_instance();
}


void VideoSource::Clear() {
// @@protoc_insertion_point(message_clear_start:VideoSource)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  path_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* VideoSource::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string path = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParserUTF8(mutable_path(), ptr, ctx, "VideoSource.path");
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool VideoSource::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  // @@protoc_insertion_point(parse_start:VideoSource)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string path = 1;
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (10 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadString(
                input, this->mutable_path()));
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
            this->path().data(), static_cast<int>(this->path().length()),
            ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::PARSE,
            "VideoSource.path"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:VideoSource)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:VideoSource)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void VideoSource::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:VideoSource)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string path = 1;
  if (this->path().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->path().data(), static_cast<int>(this->path().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "VideoSource.path");
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->path(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:VideoSource)
}

::PROTOBUF_NAMESPACE_ID::uint8* VideoSource::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:VideoSource)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string path = 1;
  if (this->path().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->path().data(), static_cast<int>(this->path().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "VideoSource.path");
    target =
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringToArray(
        1, this->path(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:VideoSource)
  return target;
}

size_t VideoSource::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:VideoSource)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string path = 1;
  if (this->path().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->path());
  }

  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void VideoSource::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:VideoSource)
  GOOGLE_DCHECK_NE(&from, this);
  const VideoSource* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<VideoSource>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:VideoSource)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:VideoSource)
    MergeFrom(*source);
  }
}

void VideoSource::MergeFrom(const VideoSource& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:VideoSource)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.path().size() > 0) {

    path_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.path_);
  }
}

void VideoSource::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:VideoSource)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void VideoSource::CopyFrom(const VideoSource& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:VideoSource)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool VideoSource::IsInitialized() const {
  return true;
}

void VideoSource::Swap(VideoSource* other) {
  if (other == this) return;
  InternalSwap(other);
}
void VideoSource::InternalSwap(VideoSource* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  path_.Swap(&other->path_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::PROTOBUF_NAMESPACE_ID::Metadata VideoSource::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::VideoSource* Arena::CreateMaybeMessage< ::VideoSource >(Arena* arena) {
  return Arena::CreateInternal< ::VideoSource >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
