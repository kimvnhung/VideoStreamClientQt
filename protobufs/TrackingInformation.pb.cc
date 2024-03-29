// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: TrackingInformation.proto

#include "TrackingInformation.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_Image_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Image_Image_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_Point_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Point_Point_2eproto;
class TrackingInformationDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<TrackingInformation> _instance;
} _TrackingInformation_default_instance_;
static void InitDefaultsscc_info_TrackingInformation_TrackingInformation_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_TrackingInformation_default_instance_;
    new (ptr) ::TrackingInformation();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::TrackingInformation::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<2> scc_info_TrackingInformation_TrackingInformation_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 2, InitDefaultsscc_info_TrackingInformation_TrackingInformation_2eproto}, {
      &scc_info_Image_Image_2eproto.base,
      &scc_info_Point_Point_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_TrackingInformation_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_TrackingInformation_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_TrackingInformation_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_TrackingInformation_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::TrackingInformation, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::TrackingInformation, frame_),
  PROTOBUF_FIELD_OFFSET(::TrackingInformation, position_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::TrackingInformation)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_TrackingInformation_default_instance_),
};

const char descriptor_table_protodef_TrackingInformation_2eproto[] =
  "\n\031TrackingInformation.proto\032\013Point.proto"
  "\032\013Image.proto\"F\n\023TrackingInformation\022\025\n\005"
  "frame\030\001 \001(\0132\006.Image\022\030\n\010position\030\002 \001(\0132\006."
  "Pointb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_TrackingInformation_2eproto_deps[2] = {
  &::descriptor_table_Image_2eproto,
  &::descriptor_table_Point_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_TrackingInformation_2eproto_sccs[1] = {
  &scc_info_TrackingInformation_TrackingInformation_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_TrackingInformation_2eproto_once;
static bool descriptor_table_TrackingInformation_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_TrackingInformation_2eproto = {
  &descriptor_table_TrackingInformation_2eproto_initialized, descriptor_table_protodef_TrackingInformation_2eproto, "TrackingInformation.proto", 133,
  &descriptor_table_TrackingInformation_2eproto_once, descriptor_table_TrackingInformation_2eproto_sccs, descriptor_table_TrackingInformation_2eproto_deps, 1, 2,
  schemas, file_default_instances, TableStruct_TrackingInformation_2eproto::offsets,
  file_level_metadata_TrackingInformation_2eproto, 1, file_level_enum_descriptors_TrackingInformation_2eproto, file_level_service_descriptors_TrackingInformation_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_TrackingInformation_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_TrackingInformation_2eproto), true);

// ===================================================================

void TrackingInformation::InitAsDefaultInstance() {
  ::_TrackingInformation_default_instance_._instance.get_mutable()->frame_ = const_cast< ::Image*>(
      ::Image::internal_default_instance());
  ::_TrackingInformation_default_instance_._instance.get_mutable()->position_ = const_cast< ::Point*>(
      ::Point::internal_default_instance());
}
class TrackingInformation::HasBitSetters {
 public:
  static const ::Image& frame(const TrackingInformation* msg);
  static const ::Point& position(const TrackingInformation* msg);
};

const ::Image&
TrackingInformation::HasBitSetters::frame(const TrackingInformation* msg) {
  return *msg->frame_;
}
const ::Point&
TrackingInformation::HasBitSetters::position(const TrackingInformation* msg) {
  return *msg->position_;
}
void TrackingInformation::clear_frame() {
  if (GetArenaNoVirtual() == nullptr && frame_ != nullptr) {
    delete frame_;
  }
  frame_ = nullptr;
}
void TrackingInformation::clear_position() {
  if (GetArenaNoVirtual() == nullptr && position_ != nullptr) {
    delete position_;
  }
  position_ = nullptr;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int TrackingInformation::kFrameFieldNumber;
const int TrackingInformation::kPositionFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

TrackingInformation::TrackingInformation()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:TrackingInformation)
}
TrackingInformation::TrackingInformation(const TrackingInformation& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from.has_frame()) {
    frame_ = new ::Image(*from.frame_);
  } else {
    frame_ = nullptr;
  }
  if (from.has_position()) {
    position_ = new ::Point(*from.position_);
  } else {
    position_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:TrackingInformation)
}

void TrackingInformation::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_TrackingInformation_TrackingInformation_2eproto.base);
  ::memset(&frame_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&position_) -
      reinterpret_cast<char*>(&frame_)) + sizeof(position_));
}

TrackingInformation::~TrackingInformation() {
  // @@protoc_insertion_point(destructor:TrackingInformation)
  SharedDtor();
}

void TrackingInformation::SharedDtor() {
  if (this != internal_default_instance()) delete frame_;
  if (this != internal_default_instance()) delete position_;
}

void TrackingInformation::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const TrackingInformation& TrackingInformation::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_TrackingInformation_TrackingInformation_2eproto.base);
  return *internal_default_instance();
}


void TrackingInformation::Clear() {
// @@protoc_insertion_point(message_clear_start:TrackingInformation)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaNoVirtual() == nullptr && frame_ != nullptr) {
    delete frame_;
  }
  frame_ = nullptr;
  if (GetArenaNoVirtual() == nullptr && position_ != nullptr) {
    delete position_;
  }
  position_ = nullptr;
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* TrackingInformation::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .Image frame = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(mutable_frame(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .Point position = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ctx->ParseMessage(mutable_position(), ptr);
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
bool TrackingInformation::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  // @@protoc_insertion_point(parse_start:TrackingInformation)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .Image frame = 1;
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (10 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadMessage(
               input, mutable_frame()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .Point position = 2;
      case 2: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (18 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadMessage(
               input, mutable_position()));
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
  // @@protoc_insertion_point(parse_success:TrackingInformation)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:TrackingInformation)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void TrackingInformation::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:TrackingInformation)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .Image frame = 1;
  if (this->has_frame()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, HasBitSetters::frame(this), output);
  }

  // .Point position = 2;
  if (this->has_position()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, HasBitSetters::position(this), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:TrackingInformation)
}

::PROTOBUF_NAMESPACE_ID::uint8* TrackingInformation::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:TrackingInformation)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .Image frame = 1;
  if (this->has_frame()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, HasBitSetters::frame(this), target);
  }

  // .Point position = 2;
  if (this->has_position()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessageToArray(
        2, HasBitSetters::position(this), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:TrackingInformation)
  return target;
}

size_t TrackingInformation::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:TrackingInformation)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .Image frame = 1;
  if (this->has_frame()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *frame_);
  }

  // .Point position = 2;
  if (this->has_position()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *position_);
  }

  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void TrackingInformation::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:TrackingInformation)
  GOOGLE_DCHECK_NE(&from, this);
  const TrackingInformation* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<TrackingInformation>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:TrackingInformation)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:TrackingInformation)
    MergeFrom(*source);
  }
}

void TrackingInformation::MergeFrom(const TrackingInformation& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:TrackingInformation)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_frame()) {
    mutable_frame()->::Image::MergeFrom(from.frame());
  }
  if (from.has_position()) {
    mutable_position()->::Point::MergeFrom(from.position());
  }
}

void TrackingInformation::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:TrackingInformation)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TrackingInformation::CopyFrom(const TrackingInformation& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:TrackingInformation)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TrackingInformation::IsInitialized() const {
  return true;
}

void TrackingInformation::Swap(TrackingInformation* other) {
  if (other == this) return;
  InternalSwap(other);
}
void TrackingInformation::InternalSwap(TrackingInformation* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(frame_, other->frame_);
  swap(position_, other->position_);
}

::PROTOBUF_NAMESPACE_ID::Metadata TrackingInformation::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::TrackingInformation* Arena::CreateMaybeMessage< ::TrackingInformation >(Arena* arena) {
  return Arena::CreateInternal< ::TrackingInformation >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
