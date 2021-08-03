@0x8e19171a5e95aa63;

struct TestDataClassCapn {
  nestedData @0: TestDataClassCapn;
  bool1 @1: Bool;
  bool2 @2: Bool;
  byte1 @3: Int8; # todo: data types missing in protobuf
  byte2 @4: Int8;
  char1 @5: UInt8;
  char2 @6: UInt8;
  short1 @7: Int32;
  short2 @8: Int32;
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
  boolArray @19: List(Bool);
  byteArray @20: List(UInt8);
  intArray @21: List(Int32);
  longArray @22: List(Int64);
  floatArray @23: List(Float32);
  doubleArray @24: List(Float64);
  stringArray @25: List(Text);
  nDimensions @26: List(Int32);
  boolNdimArray @27: List(Bool);
  byteNdimArray @28: List(UInt8);
  intNdimArray @29: List(Int32);
  longNdimArray @30: List(Int64);
  floatNdimArray @31: List(Float32);
  doubleNdimArray @32: List(Float64);
}