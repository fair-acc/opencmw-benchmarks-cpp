// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_TESTDATACLASS_FB_BENCH_H_
#define FLATBUFFERS_GENERATED_TESTDATACLASS_FB_BENCH_H_

#include "flatbuffers/flatbuffers.h"

namespace fb_bench {

struct TestDataClassFb;
struct TestDataClassFbBuilder;
struct TestDataClassFbT;

struct TestDataClassFbT : public flatbuffers::NativeTable {
  typedef TestDataClassFb TableType;
  bool bool1;
  bool bool2;
  int8_t byte1;
  int8_t byte2;
  int8_t char1;
  int8_t char2;
  int16_t short1;
  int16_t short2;
  int32_t int1;
  int32_t int2;
  int64_t long1;
  int64_t long2;
  float float1;
  float float2;
  double double1;
  double double2;
  std::string string1;
  std::string string2;
  std::vector<bool> boolArray;
  std::vector<int8_t> byteArray;
  std::vector<int16_t> shortArray;
  std::vector<int32_t> intArray;
  std::vector<int64_t> longArray;
  std::vector<float> floatArray;
  std::vector<double> doubleArray;
  std::vector<std::string> stringArray;
  std::vector<uint32_t> nDimensions;
  std::vector<bool> boolNdimArray;
  std::vector<uint8_t> byteNdimArray;
  std::vector<int16_t> shortNdimArray;
  std::vector<int32_t> intNdimArray;
  std::vector<int64_t> longNdimArray;
  std::vector<float> floatNdimArray;
  std::vector<double> doubleNdimArray;
  std::unique_ptr<fb_bench::TestDataClassFbT> nestedData;
  TestDataClassFbT()
      : bool1(false),
        bool2(false),
        byte1(0),
        byte2(0),
        char1(0),
        char2(0),
        short1(0),
        short2(0),
        int1(0),
        int2(0),
        long1(0),
        long2(0),
        float1(0.0f),
        float2(0.0f),
        double1(0.0),
        double2(0.0) {
  }
};

struct TestDataClassFb FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef TestDataClassFbT NativeTableType;
  typedef TestDataClassFbBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_BOOL1 = 4,
    VT_BOOL2 = 6,
    VT_BYTE1 = 8,
    VT_BYTE2 = 10,
    VT_CHAR1 = 12,
    VT_CHAR2 = 14,
    VT_SHORT1 = 16,
    VT_SHORT2 = 18,
    VT_INT1 = 20,
    VT_INT2 = 22,
    VT_LONG1 = 24,
    VT_LONG2 = 26,
    VT_FLOAT1 = 28,
    VT_FLOAT2 = 30,
    VT_DOUBLE1 = 32,
    VT_DOUBLE2 = 34,
    VT_STRING1 = 36,
    VT_STRING2 = 38,
    VT_BOOLARRAY = 40,
    VT_BYTEARRAY = 42,
    VT_SHORTARRAY = 44,
    VT_INTARRAY = 46,
    VT_LONGARRAY = 48,
    VT_FLOATARRAY = 50,
    VT_DOUBLEARRAY = 52,
    VT_STRINGARRAY = 54,
    VT_NDIMENSIONS = 56,
    VT_BOOLNDIMARRAY = 58,
    VT_BYTENDIMARRAY = 60,
    VT_SHORTNDIMARRAY = 62,
    VT_INTNDIMARRAY = 64,
    VT_LONGNDIMARRAY = 66,
    VT_FLOATNDIMARRAY = 68,
    VT_DOUBLENDIMARRAY = 70,
    VT_NESTEDDATA = 72
  };
  bool bool1() const {
    return GetField<uint8_t>(VT_BOOL1, 0) != 0;
  }
  bool bool2() const {
    return GetField<uint8_t>(VT_BOOL2, 0) != 0;
  }
  int8_t byte1() const {
    return GetField<int8_t>(VT_BYTE1, 0);
  }
  int8_t byte2() const {
    return GetField<int8_t>(VT_BYTE2, 0);
  }
  int8_t char1() const {
    return GetField<int8_t>(VT_CHAR1, 0);
  }
  int8_t char2() const {
    return GetField<int8_t>(VT_CHAR2, 0);
  }
  int16_t short1() const {
    return GetField<int16_t>(VT_SHORT1, 0);
  }
  int16_t short2() const {
    return GetField<int16_t>(VT_SHORT2, 0);
  }
  int32_t int1() const {
    return GetField<int32_t>(VT_INT1, 0);
  }
  int32_t int2() const {
    return GetField<int32_t>(VT_INT2, 0);
  }
  int64_t long1() const {
    return GetField<int64_t>(VT_LONG1, 0);
  }
  int64_t long2() const {
    return GetField<int64_t>(VT_LONG2, 0);
  }
  float float1() const {
    return GetField<float>(VT_FLOAT1, 0.0f);
  }
  float float2() const {
    return GetField<float>(VT_FLOAT2, 0.0f);
  }
  double double1() const {
    return GetField<double>(VT_DOUBLE1, 0.0);
  }
  double double2() const {
    return GetField<double>(VT_DOUBLE2, 0.0);
  }
  const flatbuffers::String *string1() const {
    return GetPointer<const flatbuffers::String *>(VT_STRING1);
  }
  const flatbuffers::String *string2() const {
    return GetPointer<const flatbuffers::String *>(VT_STRING2);
  }
  const flatbuffers::Vector<uint8_t> *boolArray() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_BOOLARRAY);
  }
  const flatbuffers::Vector<int8_t> *byteArray() const {
    return GetPointer<const flatbuffers::Vector<int8_t> *>(VT_BYTEARRAY);
  }
  const flatbuffers::Vector<int16_t> *shortArray() const {
    return GetPointer<const flatbuffers::Vector<int16_t> *>(VT_SHORTARRAY);
  }
  const flatbuffers::Vector<int32_t> *intArray() const {
    return GetPointer<const flatbuffers::Vector<int32_t> *>(VT_INTARRAY);
  }
  const flatbuffers::Vector<int64_t> *longArray() const {
    return GetPointer<const flatbuffers::Vector<int64_t> *>(VT_LONGARRAY);
  }
  const flatbuffers::Vector<float> *floatArray() const {
    return GetPointer<const flatbuffers::Vector<float> *>(VT_FLOATARRAY);
  }
  const flatbuffers::Vector<double> *doubleArray() const {
    return GetPointer<const flatbuffers::Vector<double> *>(VT_DOUBLEARRAY);
  }
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *stringArray() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_STRINGARRAY);
  }
  const flatbuffers::Vector<uint32_t> *nDimensions() const {
    return GetPointer<const flatbuffers::Vector<uint32_t> *>(VT_NDIMENSIONS);
  }
  const flatbuffers::Vector<uint8_t> *boolNdimArray() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_BOOLNDIMARRAY);
  }
  const flatbuffers::Vector<uint8_t> *byteNdimArray() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_BYTENDIMARRAY);
  }
  const flatbuffers::Vector<int16_t> *shortNdimArray() const {
    return GetPointer<const flatbuffers::Vector<int16_t> *>(VT_SHORTNDIMARRAY);
  }
  const flatbuffers::Vector<int32_t> *intNdimArray() const {
    return GetPointer<const flatbuffers::Vector<int32_t> *>(VT_INTNDIMARRAY);
  }
  const flatbuffers::Vector<int64_t> *longNdimArray() const {
    return GetPointer<const flatbuffers::Vector<int64_t> *>(VT_LONGNDIMARRAY);
  }
  const flatbuffers::Vector<float> *floatNdimArray() const {
    return GetPointer<const flatbuffers::Vector<float> *>(VT_FLOATNDIMARRAY);
  }
  const flatbuffers::Vector<double> *doubleNdimArray() const {
    return GetPointer<const flatbuffers::Vector<double> *>(VT_DOUBLENDIMARRAY);
  }
  const fb_bench::TestDataClassFb *nestedData() const {
    return GetPointer<const fb_bench::TestDataClassFb *>(VT_NESTEDDATA);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_BOOL1) &&
           VerifyField<uint8_t>(verifier, VT_BOOL2) &&
           VerifyField<int8_t>(verifier, VT_BYTE1) &&
           VerifyField<int8_t>(verifier, VT_BYTE2) &&
           VerifyField<int8_t>(verifier, VT_CHAR1) &&
           VerifyField<int8_t>(verifier, VT_CHAR2) &&
           VerifyField<int16_t>(verifier, VT_SHORT1) &&
           VerifyField<int16_t>(verifier, VT_SHORT2) &&
           VerifyField<int32_t>(verifier, VT_INT1) &&
           VerifyField<int32_t>(verifier, VT_INT2) &&
           VerifyField<int64_t>(verifier, VT_LONG1) &&
           VerifyField<int64_t>(verifier, VT_LONG2) &&
           VerifyField<float>(verifier, VT_FLOAT1) &&
           VerifyField<float>(verifier, VT_FLOAT2) &&
           VerifyField<double>(verifier, VT_DOUBLE1) &&
           VerifyField<double>(verifier, VT_DOUBLE2) &&
           VerifyOffset(verifier, VT_STRING1) &&
           verifier.VerifyString(string1()) &&
           VerifyOffset(verifier, VT_STRING2) &&
           verifier.VerifyString(string2()) &&
           VerifyOffset(verifier, VT_BOOLARRAY) &&
           verifier.VerifyVector(boolArray()) &&
           VerifyOffset(verifier, VT_BYTEARRAY) &&
           verifier.VerifyVector(byteArray()) &&
           VerifyOffset(verifier, VT_SHORTARRAY) &&
           verifier.VerifyVector(shortArray()) &&
           VerifyOffset(verifier, VT_INTARRAY) &&
           verifier.VerifyVector(intArray()) &&
           VerifyOffset(verifier, VT_LONGARRAY) &&
           verifier.VerifyVector(longArray()) &&
           VerifyOffset(verifier, VT_FLOATARRAY) &&
           verifier.VerifyVector(floatArray()) &&
           VerifyOffset(verifier, VT_DOUBLEARRAY) &&
           verifier.VerifyVector(doubleArray()) &&
           VerifyOffset(verifier, VT_STRINGARRAY) &&
           verifier.VerifyVector(stringArray()) &&
           verifier.VerifyVectorOfStrings(stringArray()) &&
           VerifyOffset(verifier, VT_NDIMENSIONS) &&
           verifier.VerifyVector(nDimensions()) &&
           VerifyOffset(verifier, VT_BOOLNDIMARRAY) &&
           verifier.VerifyVector(boolNdimArray()) &&
           VerifyOffset(verifier, VT_BYTENDIMARRAY) &&
           verifier.VerifyVector(byteNdimArray()) &&
           VerifyOffset(verifier, VT_SHORTNDIMARRAY) &&
           verifier.VerifyVector(shortNdimArray()) &&
           VerifyOffset(verifier, VT_INTNDIMARRAY) &&
           verifier.VerifyVector(intNdimArray()) &&
           VerifyOffset(verifier, VT_LONGNDIMARRAY) &&
           verifier.VerifyVector(longNdimArray()) &&
           VerifyOffset(verifier, VT_FLOATNDIMARRAY) &&
           verifier.VerifyVector(floatNdimArray()) &&
           VerifyOffset(verifier, VT_DOUBLENDIMARRAY) &&
           verifier.VerifyVector(doubleNdimArray()) &&
           VerifyOffset(verifier, VT_NESTEDDATA) &&
           verifier.VerifyTable(nestedData()) &&
           verifier.EndTable();
  }
  TestDataClassFbT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(TestDataClassFbT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<TestDataClassFb> Pack(flatbuffers::FlatBufferBuilder &_fbb, const TestDataClassFbT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct TestDataClassFbBuilder {
  typedef TestDataClassFb Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_bool1(bool bool1) {
    fbb_.AddElement<uint8_t>(TestDataClassFb::VT_BOOL1, static_cast<uint8_t>(bool1), 0);
  }
  void add_bool2(bool bool2) {
    fbb_.AddElement<uint8_t>(TestDataClassFb::VT_BOOL2, static_cast<uint8_t>(bool2), 0);
  }
  void add_byte1(int8_t byte1) {
    fbb_.AddElement<int8_t>(TestDataClassFb::VT_BYTE1, byte1, 0);
  }
  void add_byte2(int8_t byte2) {
    fbb_.AddElement<int8_t>(TestDataClassFb::VT_BYTE2, byte2, 0);
  }
  void add_char1(int8_t char1) {
    fbb_.AddElement<int8_t>(TestDataClassFb::VT_CHAR1, char1, 0);
  }
  void add_char2(int8_t char2) {
    fbb_.AddElement<int8_t>(TestDataClassFb::VT_CHAR2, char2, 0);
  }
  void add_short1(int16_t short1) {
    fbb_.AddElement<int16_t>(TestDataClassFb::VT_SHORT1, short1, 0);
  }
  void add_short2(int16_t short2) {
    fbb_.AddElement<int16_t>(TestDataClassFb::VT_SHORT2, short2, 0);
  }
  void add_int1(int32_t int1) {
    fbb_.AddElement<int32_t>(TestDataClassFb::VT_INT1, int1, 0);
  }
  void add_int2(int32_t int2) {
    fbb_.AddElement<int32_t>(TestDataClassFb::VT_INT2, int2, 0);
  }
  void add_long1(int64_t long1) {
    fbb_.AddElement<int64_t>(TestDataClassFb::VT_LONG1, long1, 0);
  }
  void add_long2(int64_t long2) {
    fbb_.AddElement<int64_t>(TestDataClassFb::VT_LONG2, long2, 0);
  }
  void add_float1(float float1) {
    fbb_.AddElement<float>(TestDataClassFb::VT_FLOAT1, float1, 0.0f);
  }
  void add_float2(float float2) {
    fbb_.AddElement<float>(TestDataClassFb::VT_FLOAT2, float2, 0.0f);
  }
  void add_double1(double double1) {
    fbb_.AddElement<double>(TestDataClassFb::VT_DOUBLE1, double1, 0.0);
  }
  void add_double2(double double2) {
    fbb_.AddElement<double>(TestDataClassFb::VT_DOUBLE2, double2, 0.0);
  }
  void add_string1(flatbuffers::Offset<flatbuffers::String> string1) {
    fbb_.AddOffset(TestDataClassFb::VT_STRING1, string1);
  }
  void add_string2(flatbuffers::Offset<flatbuffers::String> string2) {
    fbb_.AddOffset(TestDataClassFb::VT_STRING2, string2);
  }
  void add_boolArray(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> boolArray) {
    fbb_.AddOffset(TestDataClassFb::VT_BOOLARRAY, boolArray);
  }
  void add_byteArray(flatbuffers::Offset<flatbuffers::Vector<int8_t>> byteArray) {
    fbb_.AddOffset(TestDataClassFb::VT_BYTEARRAY, byteArray);
  }
  void add_shortArray(flatbuffers::Offset<flatbuffers::Vector<int16_t>> shortArray) {
    fbb_.AddOffset(TestDataClassFb::VT_SHORTARRAY, shortArray);
  }
  void add_intArray(flatbuffers::Offset<flatbuffers::Vector<int32_t>> intArray) {
    fbb_.AddOffset(TestDataClassFb::VT_INTARRAY, intArray);
  }
  void add_longArray(flatbuffers::Offset<flatbuffers::Vector<int64_t>> longArray) {
    fbb_.AddOffset(TestDataClassFb::VT_LONGARRAY, longArray);
  }
  void add_floatArray(flatbuffers::Offset<flatbuffers::Vector<float>> floatArray) {
    fbb_.AddOffset(TestDataClassFb::VT_FLOATARRAY, floatArray);
  }
  void add_doubleArray(flatbuffers::Offset<flatbuffers::Vector<double>> doubleArray) {
    fbb_.AddOffset(TestDataClassFb::VT_DOUBLEARRAY, doubleArray);
  }
  void add_stringArray(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> stringArray) {
    fbb_.AddOffset(TestDataClassFb::VT_STRINGARRAY, stringArray);
  }
  void add_nDimensions(flatbuffers::Offset<flatbuffers::Vector<uint32_t>> nDimensions) {
    fbb_.AddOffset(TestDataClassFb::VT_NDIMENSIONS, nDimensions);
  }
  void add_boolNdimArray(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> boolNdimArray) {
    fbb_.AddOffset(TestDataClassFb::VT_BOOLNDIMARRAY, boolNdimArray);
  }
  void add_byteNdimArray(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> byteNdimArray) {
    fbb_.AddOffset(TestDataClassFb::VT_BYTENDIMARRAY, byteNdimArray);
  }
  void add_shortNdimArray(flatbuffers::Offset<flatbuffers::Vector<int16_t>> shortNdimArray) {
    fbb_.AddOffset(TestDataClassFb::VT_SHORTNDIMARRAY, shortNdimArray);
  }
  void add_intNdimArray(flatbuffers::Offset<flatbuffers::Vector<int32_t>> intNdimArray) {
    fbb_.AddOffset(TestDataClassFb::VT_INTNDIMARRAY, intNdimArray);
  }
  void add_longNdimArray(flatbuffers::Offset<flatbuffers::Vector<int64_t>> longNdimArray) {
    fbb_.AddOffset(TestDataClassFb::VT_LONGNDIMARRAY, longNdimArray);
  }
  void add_floatNdimArray(flatbuffers::Offset<flatbuffers::Vector<float>> floatNdimArray) {
    fbb_.AddOffset(TestDataClassFb::VT_FLOATNDIMARRAY, floatNdimArray);
  }
  void add_doubleNdimArray(flatbuffers::Offset<flatbuffers::Vector<double>> doubleNdimArray) {
    fbb_.AddOffset(TestDataClassFb::VT_DOUBLENDIMARRAY, doubleNdimArray);
  }
  void add_nestedData(flatbuffers::Offset<fb_bench::TestDataClassFb> nestedData) {
    fbb_.AddOffset(TestDataClassFb::VT_NESTEDDATA, nestedData);
  }
  explicit TestDataClassFbBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  TestDataClassFbBuilder &operator=(const TestDataClassFbBuilder &);
  flatbuffers::Offset<TestDataClassFb> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<TestDataClassFb>(end);
    return o;
  }
};

inline flatbuffers::Offset<TestDataClassFb> CreateTestDataClassFb(
    flatbuffers::FlatBufferBuilder &_fbb,
    bool bool1 = false,
    bool bool2 = false,
    int8_t byte1 = 0,
    int8_t byte2 = 0,
    int8_t char1 = 0,
    int8_t char2 = 0,
    int16_t short1 = 0,
    int16_t short2 = 0,
    int32_t int1 = 0,
    int32_t int2 = 0,
    int64_t long1 = 0,
    int64_t long2 = 0,
    float float1 = 0.0f,
    float float2 = 0.0f,
    double double1 = 0.0,
    double double2 = 0.0,
    flatbuffers::Offset<flatbuffers::String> string1 = 0,
    flatbuffers::Offset<flatbuffers::String> string2 = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> boolArray = 0,
    flatbuffers::Offset<flatbuffers::Vector<int8_t>> byteArray = 0,
    flatbuffers::Offset<flatbuffers::Vector<int16_t>> shortArray = 0,
    flatbuffers::Offset<flatbuffers::Vector<int32_t>> intArray = 0,
    flatbuffers::Offset<flatbuffers::Vector<int64_t>> longArray = 0,
    flatbuffers::Offset<flatbuffers::Vector<float>> floatArray = 0,
    flatbuffers::Offset<flatbuffers::Vector<double>> doubleArray = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> stringArray = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint32_t>> nDimensions = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> boolNdimArray = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> byteNdimArray = 0,
    flatbuffers::Offset<flatbuffers::Vector<int16_t>> shortNdimArray = 0,
    flatbuffers::Offset<flatbuffers::Vector<int32_t>> intNdimArray = 0,
    flatbuffers::Offset<flatbuffers::Vector<int64_t>> longNdimArray = 0,
    flatbuffers::Offset<flatbuffers::Vector<float>> floatNdimArray = 0,
    flatbuffers::Offset<flatbuffers::Vector<double>> doubleNdimArray = 0,
    flatbuffers::Offset<fb_bench::TestDataClassFb> nestedData = 0) {
  TestDataClassFbBuilder builder_(_fbb);
  builder_.add_double2(double2);
  builder_.add_double1(double1);
  builder_.add_long2(long2);
  builder_.add_long1(long1);
  builder_.add_nestedData(nestedData);
  builder_.add_doubleNdimArray(doubleNdimArray);
  builder_.add_floatNdimArray(floatNdimArray);
  builder_.add_longNdimArray(longNdimArray);
  builder_.add_intNdimArray(intNdimArray);
  builder_.add_shortNdimArray(shortNdimArray);
  builder_.add_byteNdimArray(byteNdimArray);
  builder_.add_boolNdimArray(boolNdimArray);
  builder_.add_nDimensions(nDimensions);
  builder_.add_stringArray(stringArray);
  builder_.add_doubleArray(doubleArray);
  builder_.add_floatArray(floatArray);
  builder_.add_longArray(longArray);
  builder_.add_intArray(intArray);
  builder_.add_shortArray(shortArray);
  builder_.add_byteArray(byteArray);
  builder_.add_boolArray(boolArray);
  builder_.add_string2(string2);
  builder_.add_string1(string1);
  builder_.add_float2(float2);
  builder_.add_float1(float1);
  builder_.add_int2(int2);
  builder_.add_int1(int1);
  builder_.add_short2(short2);
  builder_.add_short1(short1);
  builder_.add_char2(char2);
  builder_.add_char1(char1);
  builder_.add_byte2(byte2);
  builder_.add_byte1(byte1);
  builder_.add_bool2(bool2);
  builder_.add_bool1(bool1);
  return builder_.Finish();
}

inline flatbuffers::Offset<TestDataClassFb> CreateTestDataClassFbDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    bool bool1 = false,
    bool bool2 = false,
    int8_t byte1 = 0,
    int8_t byte2 = 0,
    int8_t char1 = 0,
    int8_t char2 = 0,
    int16_t short1 = 0,
    int16_t short2 = 0,
    int32_t int1 = 0,
    int32_t int2 = 0,
    int64_t long1 = 0,
    int64_t long2 = 0,
    float float1 = 0.0f,
    float float2 = 0.0f,
    double double1 = 0.0,
    double double2 = 0.0,
    const char *string1 = nullptr,
    const char *string2 = nullptr,
    const std::vector<uint8_t> *boolArray = nullptr,
    const std::vector<int8_t> *byteArray = nullptr,
    const std::vector<int16_t> *shortArray = nullptr,
    const std::vector<int32_t> *intArray = nullptr,
    const std::vector<int64_t> *longArray = nullptr,
    const std::vector<float> *floatArray = nullptr,
    const std::vector<double> *doubleArray = nullptr,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *stringArray = nullptr,
    const std::vector<uint32_t> *nDimensions = nullptr,
    const std::vector<uint8_t> *boolNdimArray = nullptr,
    const std::vector<uint8_t> *byteNdimArray = nullptr,
    const std::vector<int16_t> *shortNdimArray = nullptr,
    const std::vector<int32_t> *intNdimArray = nullptr,
    const std::vector<int64_t> *longNdimArray = nullptr,
    const std::vector<float> *floatNdimArray = nullptr,
    const std::vector<double> *doubleNdimArray = nullptr,
    flatbuffers::Offset<fb_bench::TestDataClassFb> nestedData = 0) {
  auto string1__ = string1 ? _fbb.CreateString(string1) : 0;
  auto string2__ = string2 ? _fbb.CreateString(string2) : 0;
  auto boolArray__ = boolArray ? _fbb.CreateVector<uint8_t>(*boolArray) : 0;
  auto byteArray__ = byteArray ? _fbb.CreateVector<int8_t>(*byteArray) : 0;
  auto shortArray__ = shortArray ? _fbb.CreateVector<int16_t>(*shortArray) : 0;
  auto intArray__ = intArray ? _fbb.CreateVector<int32_t>(*intArray) : 0;
  auto longArray__ = longArray ? _fbb.CreateVector<int64_t>(*longArray) : 0;
  auto floatArray__ = floatArray ? _fbb.CreateVector<float>(*floatArray) : 0;
  auto doubleArray__ = doubleArray ? _fbb.CreateVector<double>(*doubleArray) : 0;
  auto stringArray__ = stringArray ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*stringArray) : 0;
  auto nDimensions__ = nDimensions ? _fbb.CreateVector<uint32_t>(*nDimensions) : 0;
  auto boolNdimArray__ = boolNdimArray ? _fbb.CreateVector<uint8_t>(*boolNdimArray) : 0;
  auto byteNdimArray__ = byteNdimArray ? _fbb.CreateVector<uint8_t>(*byteNdimArray) : 0;
  auto shortNdimArray__ = shortNdimArray ? _fbb.CreateVector<int16_t>(*shortNdimArray) : 0;
  auto intNdimArray__ = intNdimArray ? _fbb.CreateVector<int32_t>(*intNdimArray) : 0;
  auto longNdimArray__ = longNdimArray ? _fbb.CreateVector<int64_t>(*longNdimArray) : 0;
  auto floatNdimArray__ = floatNdimArray ? _fbb.CreateVector<float>(*floatNdimArray) : 0;
  auto doubleNdimArray__ = doubleNdimArray ? _fbb.CreateVector<double>(*doubleNdimArray) : 0;
  return fb_bench::CreateTestDataClassFb(
      _fbb,
      bool1,
      bool2,
      byte1,
      byte2,
      char1,
      char2,
      short1,
      short2,
      int1,
      int2,
      long1,
      long2,
      float1,
      float2,
      double1,
      double2,
      string1__,
      string2__,
      boolArray__,
      byteArray__,
      shortArray__,
      intArray__,
      longArray__,
      floatArray__,
      doubleArray__,
      stringArray__,
      nDimensions__,
      boolNdimArray__,
      byteNdimArray__,
      shortNdimArray__,
      intNdimArray__,
      longNdimArray__,
      floatNdimArray__,
      doubleNdimArray__,
      nestedData);
}

flatbuffers::Offset<TestDataClassFb> CreateTestDataClassFb(flatbuffers::FlatBufferBuilder &_fbb, const TestDataClassFbT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline TestDataClassFbT *TestDataClassFb::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  std::unique_ptr<fb_bench::TestDataClassFbT> _o = std::unique_ptr<fb_bench::TestDataClassFbT>(new TestDataClassFbT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void TestDataClassFb::UnPackTo(TestDataClassFbT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = bool1(); _o->bool1 = _e; }
  { auto _e = bool2(); _o->bool2 = _e; }
  { auto _e = byte1(); _o->byte1 = _e; }
  { auto _e = byte2(); _o->byte2 = _e; }
  { auto _e = char1(); _o->char1 = _e; }
  { auto _e = char2(); _o->char2 = _e; }
  { auto _e = short1(); _o->short1 = _e; }
  { auto _e = short2(); _o->short2 = _e; }
  { auto _e = int1(); _o->int1 = _e; }
  { auto _e = int2(); _o->int2 = _e; }
  { auto _e = long1(); _o->long1 = _e; }
  { auto _e = long2(); _o->long2 = _e; }
  { auto _e = float1(); _o->float1 = _e; }
  { auto _e = float2(); _o->float2 = _e; }
  { auto _e = double1(); _o->double1 = _e; }
  { auto _e = double2(); _o->double2 = _e; }
  { auto _e = string1(); if (_e) _o->string1 = _e->str(); }
  { auto _e = string2(); if (_e) _o->string2 = _e->str(); }
  { auto _e = boolArray(); if (_e) { _o->boolArray.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->boolArray[_i] = _e->Get(_i) != 0; } } }
  { auto _e = byteArray(); if (_e) { _o->byteArray.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->byteArray[_i] = _e->Get(_i); } } }
  { auto _e = shortArray(); if (_e) { _o->shortArray.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->shortArray[_i] = _e->Get(_i); } } }
  { auto _e = intArray(); if (_e) { _o->intArray.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->intArray[_i] = _e->Get(_i); } } }
  { auto _e = longArray(); if (_e) { _o->longArray.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->longArray[_i] = _e->Get(_i); } } }
  { auto _e = floatArray(); if (_e) { _o->floatArray.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->floatArray[_i] = _e->Get(_i); } } }
  { auto _e = doubleArray(); if (_e) { _o->doubleArray.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->doubleArray[_i] = _e->Get(_i); } } }
  { auto _e = stringArray(); if (_e) { _o->stringArray.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->stringArray[_i] = _e->Get(_i)->str(); } } }
  { auto _e = nDimensions(); if (_e) { _o->nDimensions.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->nDimensions[_i] = _e->Get(_i); } } }
  { auto _e = boolNdimArray(); if (_e) { _o->boolNdimArray.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->boolNdimArray[_i] = _e->Get(_i) != 0; } } }
  { auto _e = byteNdimArray(); if (_e) { _o->byteNdimArray.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->byteNdimArray[_i] = _e->Get(_i); } } }
  { auto _e = shortNdimArray(); if (_e) { _o->shortNdimArray.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->shortNdimArray[_i] = _e->Get(_i); } } }
  { auto _e = intNdimArray(); if (_e) { _o->intNdimArray.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->intNdimArray[_i] = _e->Get(_i); } } }
  { auto _e = longNdimArray(); if (_e) { _o->longNdimArray.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->longNdimArray[_i] = _e->Get(_i); } } }
  { auto _e = floatNdimArray(); if (_e) { _o->floatNdimArray.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->floatNdimArray[_i] = _e->Get(_i); } } }
  { auto _e = doubleNdimArray(); if (_e) { _o->doubleNdimArray.resize(_e->size()); for (flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->doubleNdimArray[_i] = _e->Get(_i); } } }
  { auto _e = nestedData(); if (_e) _o->nestedData = std::unique_ptr<fb_bench::TestDataClassFbT>(_e->UnPack(_resolver)); }
}

inline flatbuffers::Offset<TestDataClassFb> TestDataClassFb::Pack(flatbuffers::FlatBufferBuilder &_fbb, const TestDataClassFbT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateTestDataClassFb(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<TestDataClassFb> CreateTestDataClassFb(flatbuffers::FlatBufferBuilder &_fbb, const TestDataClassFbT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const TestDataClassFbT* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _bool1 = _o->bool1;
  auto _bool2 = _o->bool2;
  auto _byte1 = _o->byte1;
  auto _byte2 = _o->byte2;
  auto _char1 = _o->char1;
  auto _char2 = _o->char2;
  auto _short1 = _o->short1;
  auto _short2 = _o->short2;
  auto _int1 = _o->int1;
  auto _int2 = _o->int2;
  auto _long1 = _o->long1;
  auto _long2 = _o->long2;
  auto _float1 = _o->float1;
  auto _float2 = _o->float2;
  auto _double1 = _o->double1;
  auto _double2 = _o->double2;
  auto _string1 = _o->string1.empty() ? 0 : _fbb.CreateString(_o->string1);
  auto _string2 = _o->string2.empty() ? 0 : _fbb.CreateString(_o->string2);
  auto _boolArray = _o->boolArray.size() ? _fbb.CreateVector(_o->boolArray) : 0;
  auto _byteArray = _o->byteArray.size() ? _fbb.CreateVector(_o->byteArray) : 0;
  auto _shortArray = _o->shortArray.size() ? _fbb.CreateVector(_o->shortArray) : 0;
  auto _intArray = _o->intArray.size() ? _fbb.CreateVector(_o->intArray) : 0;
  auto _longArray = _o->longArray.size() ? _fbb.CreateVector(_o->longArray) : 0;
  auto _floatArray = _o->floatArray.size() ? _fbb.CreateVector(_o->floatArray) : 0;
  auto _doubleArray = _o->doubleArray.size() ? _fbb.CreateVector(_o->doubleArray) : 0;
  auto _stringArray = _o->stringArray.size() ? _fbb.CreateVectorOfStrings(_o->stringArray) : 0;
  auto _nDimensions = _o->nDimensions.size() ? _fbb.CreateVector(_o->nDimensions) : 0;
  auto _boolNdimArray = _o->boolNdimArray.size() ? _fbb.CreateVector(_o->boolNdimArray) : 0;
  auto _byteNdimArray = _o->byteNdimArray.size() ? _fbb.CreateVector(_o->byteNdimArray) : 0;
  auto _shortNdimArray = _o->shortNdimArray.size() ? _fbb.CreateVector(_o->shortNdimArray) : 0;
  auto _intNdimArray = _o->intNdimArray.size() ? _fbb.CreateVector(_o->intNdimArray) : 0;
  auto _longNdimArray = _o->longNdimArray.size() ? _fbb.CreateVector(_o->longNdimArray) : 0;
  auto _floatNdimArray = _o->floatNdimArray.size() ? _fbb.CreateVector(_o->floatNdimArray) : 0;
  auto _doubleNdimArray = _o->doubleNdimArray.size() ? _fbb.CreateVector(_o->doubleNdimArray) : 0;
  auto _nestedData = _o->nestedData ? CreateTestDataClassFb(_fbb, _o->nestedData.get(), _rehasher) : 0;
  return fb_bench::CreateTestDataClassFb(
      _fbb,
      _bool1,
      _bool2,
      _byte1,
      _byte2,
      _char1,
      _char2,
      _short1,
      _short2,
      _int1,
      _int2,
      _long1,
      _long2,
      _float1,
      _float2,
      _double1,
      _double2,
      _string1,
      _string2,
      _boolArray,
      _byteArray,
      _shortArray,
      _intArray,
      _longArray,
      _floatArray,
      _doubleArray,
      _stringArray,
      _nDimensions,
      _boolNdimArray,
      _byteNdimArray,
      _shortNdimArray,
      _intNdimArray,
      _longNdimArray,
      _floatNdimArray,
      _doubleNdimArray,
      _nestedData);
}

inline const fb_bench::TestDataClassFb *GetTestDataClassFb(const void *buf) {
  return flatbuffers::GetRoot<fb_bench::TestDataClassFb>(buf);
}

inline const fb_bench::TestDataClassFb *GetSizePrefixedTestDataClassFb(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<fb_bench::TestDataClassFb>(buf);
}

inline bool VerifyTestDataClassFbBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<fb_bench::TestDataClassFb>(nullptr);
}

inline bool VerifySizePrefixedTestDataClassFbBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<fb_bench::TestDataClassFb>(nullptr);
}

inline void FinishTestDataClassFbBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<fb_bench::TestDataClassFb> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedTestDataClassFbBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<fb_bench::TestDataClassFb> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<fb_bench::TestDataClassFbT> UnPackTestDataClassFb(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<fb_bench::TestDataClassFbT>(GetTestDataClassFb(buf)->UnPack(res));
}

inline std::unique_ptr<fb_bench::TestDataClassFbT> UnPackSizePrefixedTestDataClassFb(
    const void *buf,
    const flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<fb_bench::TestDataClassFbT>(GetSizePrefixedTestDataClassFb(buf)->UnPack(res));
}

}  // namespace fb_bench

#endif  // FLATBUFFERS_GENERATED_TESTDATACLASS_FB_BENCH_H_