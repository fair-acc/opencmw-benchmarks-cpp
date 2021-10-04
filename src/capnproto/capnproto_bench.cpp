#include "../TestDataClass.hpp"
#include "TestDataClassCapn.capnp.h"
#include <benchmark/benchmark.h>
#include <capnp/serialize.h>
#include <iostream>
#include <random>

static void setContainerFromPoco(TestDataClassCapn::Builder &protobufContainer, const TestDataClass &data) {
    // primitives
    protobufContainer.setBool1(data.bool1);
    protobufContainer.setBool2(data.bool2);
    protobufContainer.setByte1(data.byte1);
    protobufContainer.setByte2(data.byte2);
    // char1   = 'a';
    // char2   = 'Z';
    // short1  = 20;
    // short2  = -200;
    protobufContainer.setInt1(data.int1);
    protobufContainer.setInt2(data.int2);
    protobufContainer.setLong1(data.long1);
    protobufContainer.setLong2(data.long2);
    protobufContainer.setFloat1(data.float1);
    protobufContainer.setFloat2(data.float2);
    protobufContainer.setDouble1(data.double1);
    protobufContainer.setDouble2(data.double2);
    protobufContainer.setString1(data.string1);
    protobufContainer.setString2(data.string2);
    // 1-dim arrays
    unsigned int                   n_array     = static_cast<unsigned int>(data.boolArray.size());
    ::capnp::List<bool>::Builder   boolarray   = protobufContainer.initBoolArray(n_array);
    ::capnp::List<int>::Builder    intarray    = protobufContainer.initIntArray(n_array);
    ::capnp::List<long>::Builder   longarray   = protobufContainer.initLongArray(n_array);
    ::capnp::List<float>::Builder  floatarray  = protobufContainer.initFloatArray(n_array);
    ::capnp::List<double>::Builder doublearray = protobufContainer.initDoubleArray(n_array);
    for (capnp::uint i = 0; i < n_array; i++) {
        boolarray.set(i, data.boolArray[i]);
        intarray.set(i, data.intArray[i]);
        longarray.set(i, data.longArray[i]);
        floatarray.set(i, data.floatArray[i]);
        doublearray.set(i, data.doubleArray[i]);
    }
    unsigned int                        n_string    = static_cast<unsigned int>(data.stringArray.size());
    ::capnp::List<capnp::Text>::Builder stringarray = protobufContainer.initStringArray(n_string);
    for (capnp::uint i = 0; i < n_string; i++) {
        stringarray.set(i, data.stringArray[i]);
    }
    //// n-dim arrays
    ::capnp::List<int>::Builder nDimensions = protobufContainer.initIntArray(3);
    nDimensions.set(0, static_cast<int>(data.boolNdimArray.dimensions()[0]));
    nDimensions.set(1, static_cast<int>(data.boolNdimArray.dimensions()[1]));
    nDimensions.set(2, static_cast<int>(data.boolNdimArray.dimensions()[2]));
    unsigned int                    nDimSize        = data.boolNdimArray.dimensions()[0] * data.boolNdimArray.dimensions()[1] * data.boolNdimArray.dimensions()[2];
    ::capnp::List<bool>::Builder    boolndimarray   = protobufContainer.initBoolNdimArray(nDimSize);
    ::capnp::List<uint8_t>::Builder bytendimarray   = protobufContainer.initByteNdimArray(nDimSize);
    ::capnp::List<int>::Builder     intndimarray    = protobufContainer.initIntNdimArray(nDimSize);
    ::capnp::List<long>::Builder    longndimarray   = protobufContainer.initLongNdimArray(nDimSize);
    ::capnp::List<float>::Builder   floatndimarray  = protobufContainer.initFloatNdimArray(nDimSize);
    ::capnp::List<double>::Builder  doublendimarray = protobufContainer.initDoubleNdimArray(nDimSize);
    for (capnp::uint i = 0; i < nDimSize; i++) {
        boolndimarray.set(i, data.boolNdimArray.elements()[i]);
        bytendimarray.set(i, data.byteNdimArray.elements()[i]);
        intndimarray.set(i, data.intNdimArray.elements()[i]);
        longndimarray.set(i, data.longNdimArray.elements()[i]);
        floatndimarray.set(i, data.floatNdimArray.elements()[i]);
        doublendimarray.set(i, data.doubleNdimArray.elements()[i]);
    }
    if (data.nestedData) {
        TestDataClassCapn::Builder    testClass = protobufContainer.initNestedData();
        setContainerFromPoco(testClass, *(data.nestedData));
    }
}

static void setPocoFromContainer(const TestDataClassCapn::Reader &protobufContainer, TestDataClass &data) {
    data.bool1 = protobufContainer.getBool1();
    data.bool2 = protobufContainer.getBool2();
    // byte1   = 10;
    // byte2   = -100;
    // char1   = 'a';
    // char2   = 'Z';
    // short1  = 20;
    // short2  = -200;
    data.int1    = protobufContainer.getInt1();
    data.int2    = protobufContainer.getInt2();
    data.long1   = protobufContainer.getLong1();
    data.long2   = protobufContainer.getLong2();
    data.float1  = protobufContainer.getFloat1();
    data.float2  = protobufContainer.getFloat2();
    data.double1 = protobufContainer.getDouble1();
    data.double2 = protobufContainer.getDouble2();
    data.string1 = protobufContainer.getString1();
    data.string2 = protobufContainer.getString2();
    // 1d arrays
    data.boolArray.resize(protobufContainer.getBoolArray().size());
    std::copy(protobufContainer.getBoolArray().begin(), protobufContainer.getBoolArray().end(), data.boolArray.begin());
    data.intArray.resize(protobufContainer.getIntArray().size());
    std::copy(protobufContainer.getIntArray().begin(), protobufContainer.getIntArray().end(), data.intArray.begin());
    data.longArray.resize(protobufContainer.getLongArray().size());
    std::copy(protobufContainer.getLongArray().begin(), protobufContainer.getLongArray().end(), data.longArray.begin());
    data.floatArray.resize(protobufContainer.getFloatArray().size());
    std::copy(protobufContainer.getFloatArray().begin(), protobufContainer.getFloatArray().end(), data.floatArray.begin());
    data.doubleArray.resize(protobufContainer.getDoubleArray().size());
    std::copy(protobufContainer.getDoubleArray().begin(), protobufContainer.getDoubleArray().end(), data.doubleArray.begin());
    data.stringArray.resize(protobufContainer.getStringArray().size());
    std::copy(protobufContainer.getStringArray().begin(), protobufContainer.getStringArray().end(), data.stringArray.begin());
    // N-dim arrays
    std::copy(protobufContainer.getNDimensions().begin(), protobufContainer.getNDimensions().end(), data.boolNdimArray.dimensions().begin());
    std::copy(protobufContainer.getNDimensions().begin(), protobufContainer.getNDimensions().end(), data.intNdimArray.dimensions().begin());
    std::copy(protobufContainer.getNDimensions().begin(), protobufContainer.getNDimensions().end(), data.longNdimArray.dimensions().begin());
    std::copy(protobufContainer.getNDimensions().begin(), protobufContainer.getNDimensions().end(), data.floatNdimArray.dimensions().begin());
    std::copy(protobufContainer.getNDimensions().begin(), protobufContainer.getNDimensions().end(), data.doubleNdimArray.dimensions().begin());

    data.boolNdimArray.elements().resize(protobufContainer.getBoolNdimArray().size());
    std::copy(protobufContainer.getBoolNdimArray().begin(), protobufContainer.getBoolNdimArray().end(), data.boolNdimArray.elements().begin());
    data.intNdimArray.elements().resize(protobufContainer.getIntNdimArray().size());
    std::copy(protobufContainer.getIntNdimArray().begin(), protobufContainer.getIntNdimArray().end(), data.intNdimArray.elements().begin());
    data.longNdimArray.elements().resize(protobufContainer.getLongNdimArray().size());
    std::copy(protobufContainer.getLongNdimArray().begin(), protobufContainer.getLongNdimArray().end(), data.longNdimArray.elements().begin());
    data.floatNdimArray.elements().resize(protobufContainer.getFloatNdimArray().size());
    std::copy(protobufContainer.getFloatNdimArray().begin(), protobufContainer.getFloatNdimArray().end(), data.floatNdimArray.elements().begin());
    data.doubleNdimArray.elements().resize(protobufContainer.getDoubleNdimArray().size());
    std::copy(protobufContainer.getDoubleNdimArray().begin(), protobufContainer.getDoubleNdimArray().end(), data.doubleNdimArray.elements().begin());

    if (protobufContainer.hasNestedData()) {
        auto nested = protobufContainer.getNestedData();
        data.nestedData = std::unique_ptr<TestDataClass>(new TestDataClass{});
        setPocoFromContainer(nested, *(data.nestedData));
    }
}

static void capnproto_bench(benchmark::State &state) {
    auto n_numerals = static_cast<size_t>(state.range(0));
    auto n_strings  = static_cast<size_t>(state.range(1));
    auto n_nesting = static_cast<int>(state.range(2));
    // Seed with a real random value, if available
    std::random_device                    r;
    std::default_random_engine            e1(r());
    std::uniform_int_distribution<size_t> randomArrayIndex(0, n_numerals - 1);
    std::uniform_int_distribution<size_t> randomStringArrayIndex(0, n_strings - 1);

    size_t                                dataSize = TestDataClass::get_data_size(n_numerals, n_strings, n_nesting);
    // generate random input data
    const TestDataClass dataA(n_numerals, n_strings, n_nesting); // numeric heavy data <-> equivalent to Java benchmark
    const TestDataClass dataB(n_numerals, n_strings, n_nesting); // numeric heavy data <-> equivalent to Java benchmark
    // received data
    TestDataClass testData2;

    size_t        size = 0;
    // benchmark loop
    int i = 0;
    for (auto _ : state) {
        try {
            i++;
            ::capnp::MallocMessageBuilder message_builder{};
            TestDataClassCapn::Builder    testClass = message_builder.initRoot<TestDataClassCapn>();
            setContainerFromPoco(testClass, i % 2 == 0 ? dataA : dataB);
            auto  dataOrig                                 = ::capnp::messageToFlatArray(message_builder);
            auto  data                                     = dataOrig.asChars();
            char *data_array                               = data.begin();
            size                                           = data.size();
            kj::ArrayPtr<capnp::word>       received_array = kj::ArrayPtr<capnp::word>(reinterpret_cast<capnp::word *>(data_array), size / sizeof(capnp::word));
            ::capnp::FlatArrayMessageReader message_receiver_builder(received_array);
            auto                            messageReceiver = message_receiver_builder.getRoot<TestDataClassCapn>();
            setPocoFromContainer(messageReceiver, testData2);
            // plausibility check
            auto randomIdx = randomArrayIndex(e1);
            if (n_numerals > 0 && (i % 2 == 0 ? dataA : dataB).doubleArray.at(randomIdx) != testData2.doubleArray.at(randomIdx)) {
                state.SkipWithError(("double arrays not identical" + std::to_string(randomIdx)).c_str());
                break;
            }
            auto randomStringIdx = randomStringArrayIndex(e1);
            if (n_strings > 0 && (i % 2 == 0 ? dataA : dataB).stringArray.at(randomStringIdx) != testData2.stringArray.at(randomStringIdx)) {
                state.SkipWithError(("string arrays not identical" + std::to_string(randomStringIdx)).c_str());
                break;
            }
            benchmark::DoNotOptimize(dataA);
            benchmark::DoNotOptimize(dataB);
            benchmark::DoNotOptimize(testData2);
            benchmark::ClobberMemory();
        } catch (std::exception &e) {
            state.SkipWithError((std::string("caught exception: ") + opencmw::typeName<std::remove_reference_t<decltype(e)>>.data() + e.what()).c_str());
            break;
        } catch (...) {
            state.SkipWithError("unknown exception");
            break;
        }
    }
    // benchmark loop
    state.counters["BytesProcessed"] = benchmark::Counter(static_cast<int>(dataSize), benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1024);
    state.counters["ItemsProcessed"] = benchmark::Counter(1, benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1000);
    state.counters["wireSize"]       = static_cast<int>(size);
    state.counters["dataSize"]       = static_cast<int>(dataSize);
}

BENCHMARK(capnproto_bench)->Name("CapnProto")->Repetitions(3)->Args({ 1000, 0, 0 })->Args({ 10, 100, 1 })->ArgsProduct({{256, 512, 1024, 2048, 4096, 8192}, {0}, {0}});
