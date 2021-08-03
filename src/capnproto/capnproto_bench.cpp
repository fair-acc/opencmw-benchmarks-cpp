#include "TestDataClassCapn.capnp.h"
#include "../TestDataClass.hpp"
#include <capnp/serialize.h>
#include <benchmark/benchmark.h>
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
    unsigned int N_ARRAY = static_cast<unsigned int>(data.boolArray.size());
    ::capnp::List<bool>::Builder        boolarray   = protobufContainer.initBoolArray(N_ARRAY);
    ::capnp::List<int>::Builder         intarray    = protobufContainer.initIntArray(N_ARRAY);
    ::capnp::List<long>::Builder        longarray   = protobufContainer.initLongArray(N_ARRAY);
    ::capnp::List<float>::Builder       floatarray  = protobufContainer.initFloatArray(N_ARRAY);
    ::capnp::List<double>::Builder      doublearray = protobufContainer.initDoubleArray(N_ARRAY);
    // ::capnp::List<capnp::Text>::Builder stringarray = testClass.initStringArray(N_ARRAY);
    for (capnp::uint i = 0; i < N_ARRAY; i++) {
        boolarray.set(i, data.boolArray[i]);
        intarray.set(i, data.intArray[i]);
        longarray.set(i, data.longArray[i]);
        floatarray.set(i, data.floatArray[i]);
        doublearray.set(i, data.doubleArray[i]);
        // stringarray.set(i, ("test" + std::to_string(e1())));
    }
    //// n-dim arrays
    ::capnp::List<int>::Builder         nDimensions     = protobufContainer.initIntArray(3);
    nDimensions.set(0, static_cast<int>(data.boolNdimArray.dimensions()[0]));
    nDimensions.set(1, static_cast<int>(data.boolNdimArray.dimensions()[1]));
    nDimensions.set(2, static_cast<int>(data.boolNdimArray.dimensions()[2]));
    unsigned int nDimSize = data.boolNdimArray.dimensions()[0] * data.boolNdimArray.dimensions()[1] * data.boolNdimArray.dimensions()[2];
    ::capnp::List<bool>::Builder        boolndimarray   = protobufContainer.initBoolNdimArray(nDimSize);
    ::capnp::List<uint8_t>::Builder     bytendimarray   = protobufContainer.initByteNdimArray(nDimSize);
    ::capnp::List<int>::Builder         intndimarray    = protobufContainer.initIntNdimArray(nDimSize);
    ::capnp::List<long>::Builder        longndimarray   = protobufContainer.initLongNdimArray(nDimSize);
    ::capnp::List<float>::Builder       floatndimarray  = protobufContainer.initFloatNdimArray(nDimSize);
    ::capnp::List<double>::Builder      doublendimarray = protobufContainer.initDoubleNdimArray(nDimSize);
    for (capnp::uint i = 0; i < nDimSize; i++) {
        boolndimarray.set(i, data.boolNdimArray.elements()[i]);
        bytendimarray.set(i, data.byteNdimArray.elements()[i]);
        intndimarray.set(i, data.intNdimArray.elements()[i]);
        longndimarray.set(i, data.longNdimArray.elements()[i]);
        floatndimarray.set(i, data.floatNdimArray.elements()[i]);
        doublendimarray.set(i, data.doubleNdimArray.elements()[i]);
        // stringarray.set(i, ("test" + std::to_string(e1())));
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
    data.int1 = protobufContainer.getInt1();
    data.int2 = protobufContainer.getInt2();
    data.long1 = protobufContainer.getLong1();
    data.long2 = protobufContainer.getLong2();
    data.float1 = protobufContainer.getFloat1();
    data.float2 = protobufContainer.getFloat2();
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
}

static void capnproto_bench(benchmark::State &state) {
    static const int N_ARRAY = 1000;
    // Seed with a real random value, if available
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<size_t> randomArrayIndex(0, N_ARRAY-1);

    size_t dataSize = TestDataClass::get_data_size(N_ARRAY, 0, 0);
    // generate random input data
    const TestDataClass dataA(N_ARRAY, 0, 0);    // numeric heavy data <-> equivalent to Java benchmark
    const TestDataClass dataB(N_ARRAY, 0, 0);    // numeric heavy data <-> equivalent to Java benchmark
    // received data
    TestDataClass testData2;

    size_t size = 0;
    // benchmark loop
    int i = 0;
    for (auto _ : state) {
        try {
            i++;
            ::capnp::MallocMessageBuilder message_builder{};
            TestDataClassCapn::Builder testClass = message_builder.initRoot<TestDataClassCapn>();
            setContainerFromPoco(testClass, i % 2 == 0 ? dataA : dataB);
            auto dataOrig = ::capnp::messageToFlatArray(message_builder);
            auto data = dataOrig.asChars();
            char * data_array = data.begin();
            size = data.size();
            kj::ArrayPtr<capnp::word> received_array = kj::ArrayPtr<capnp::word>(reinterpret_cast<capnp::word*>(data_array), size/sizeof(capnp::word));
            ::capnp::FlatArrayMessageReader message_receiver_builder(received_array);
            auto messageReceiver = message_receiver_builder.getRoot<TestDataClassCapn>();
            setPocoFromContainer(messageReceiver, testData2);
            // plausibility check
            auto randomIdx = randomArrayIndex(e1);
            if ((i % 2 == 0 ? dataA : dataB).doubleArray.at(randomIdx) != testData2.doubleArray.at(randomIdx)) {
                state.SkipWithError(("double arrays not identical" + std::to_string(randomIdx)).c_str());
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
    state.counters["wireSize"] = static_cast<int>(size);
    state.counters["dataSize"] = static_cast<int>(dataSize);
}

BENCHMARK(capnproto_bench)->Name("CapnProto")->Repetitions(5);
