syntax = "proto3";

struct TestDataClass {
  bool1 @1: Bool;
  bool2 @2: Bool;
  byte1 @3: UInt8; // todo: data types missing in protobuf
  byte2 @4: UInt8;
  char1 @5: UInt8;
  char2 @6: UInt8;
  // optional short1 @7;
  // optional short2 @8;
  int1 @9: Int32;
  int2 @10: Int32;
  long1 @11: Int64;
  long2 @12: Int64;
  float1 @13: Float32;
  float2 @14: Float32;
  double1 @15: Float64;
  double2 @16: Float64;
  string1 @17: Text;
  string2 @18: Text;
  boolArray @19; // todo: is using repeated for arrays a valid choice?
  byteArray @20: List(UInt8);
  int32 intArray @22: List(Int32);
  int64 longArray @23: List(Int64);
  float floatArray @24: List(Float32);
  double doubleArray @25: List(Float64);
  string stringArray @26: List(Text);
  // optional nDimensions @27; // todo: how to model multi dim in protobuf
  // optional boolNdimArray @28;
  // optional byteNdimArray @29;
  // optional shortNdimArray @30;
  // optional intNdimArray @31;
  // optional longNdimArray @32;
  // optional floatNdimArray @33;
  // optional doubleNdimArray @34;
  nestedData @35: TestDataClass;
}