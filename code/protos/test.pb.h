// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#ifndef PROTOBUF_test_2eproto__INCLUDED
#define PROTOBUF_test_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_test_2eproto();
void protobuf_AssignDesc_test_2eproto();
void protobuf_ShutdownFile_test_2eproto();

class Test;

// ===================================================================

class Test : public ::google::protobuf::Message {
 public:
  Test();
  virtual ~Test();

  Test(const Test& from);

  inline Test& operator=(const Test& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Test& default_instance();

  void Swap(Test* other);

  // implements Message ----------------------------------------------

  Test* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Test& from);
  void MergeFrom(const Test& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 a = 1;
  inline bool has_a() const;
  inline void clear_a();
  static const int kAFieldNumber = 1;
  inline ::google::protobuf::uint32 a() const;
  inline void set_a(::google::protobuf::uint32 value);

  // optional uint32 b = 2;
  inline bool has_b() const;
  inline void clear_b();
  static const int kBFieldNumber = 2;
  inline ::google::protobuf::uint32 b() const;
  inline void set_b(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:Test)
 private:
  inline void set_has_a();
  inline void clear_has_a();
  inline void set_has_b();
  inline void clear_has_b();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::uint32 a_;
  ::google::protobuf::uint32 b_;
  friend void  protobuf_AddDesc_test_2eproto();
  friend void protobuf_AssignDesc_test_2eproto();
  friend void protobuf_ShutdownFile_test_2eproto();

  void InitAsDefaultInstance();
  static Test* default_instance_;
};
// ===================================================================


// ===================================================================

// Test

// optional uint32 a = 1;
inline bool Test::has_a() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Test::set_has_a() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Test::clear_has_a() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Test::clear_a() {
  a_ = 0u;
  clear_has_a();
}
inline ::google::protobuf::uint32 Test::a() const {
  // @@protoc_insertion_point(field_get:Test.a)
  return a_;
}
inline void Test::set_a(::google::protobuf::uint32 value) {
  set_has_a();
  a_ = value;
  // @@protoc_insertion_point(field_set:Test.a)
}

// optional uint32 b = 2;
inline bool Test::has_b() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Test::set_has_b() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Test::clear_has_b() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Test::clear_b() {
  b_ = 0u;
  clear_has_b();
}
inline ::google::protobuf::uint32 Test::b() const {
  // @@protoc_insertion_point(field_get:Test.b)
  return b_;
}
inline void Test::set_b(::google::protobuf::uint32 value) {
  set_has_b();
  b_ = value;
  // @@protoc_insertion_point(field_set:Test.b)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_test_2eproto__INCLUDED
