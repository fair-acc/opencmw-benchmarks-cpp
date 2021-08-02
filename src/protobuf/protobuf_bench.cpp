#include "../TestDataClass.hpp"
#include "TestDataClass.pb.h"
#include <benchmark/benchmark.h>
#include <vector>
#include <string>
#include <random>

static void setContainerFromPoco(protobuf::TestDataClass &protobufContainer, const TestDataClass &data) {
    // primitives
    protobufContainer.set_bool1(data.bool1);
    protobufContainer.set_bool2(data.bool2);
    // byte1   = 10;
    // byte2   = -100;
    // char1   = 'a';
    // char2   = 'Z';
    // short1  = 20;
    // short2  = -200;
    protobufContainer.set_int1(data.int1);
    protobufContainer.set_int2(data.int2);
    protobufContainer.set_long1(data.long1);
    protobufContainer.set_long2(data.long2);
    protobufContainer.set_float1(data.float1);
    protobufContainer.set_float2(data.float2);
    protobufContainer.set_double1(data.double1);
    protobufContainer.set_double2(data.double2);
    protobufContainer.set_string1(data.string1);
    protobufContainer.set_string2(data.string2);
    // 1-dim arrays
    protobufContainer.mutable_boolarray()->Reserve(data.boolArray.size());
    protobufContainer.mutable_boolarray()->Assign(data.boolArray.begin(), data.boolArray.end());
    protobufContainer.mutable_intarray()->    Reserve(data.intArray.size());
    protobufContainer.mutable_intarray()->    Assign(data.intArray.begin(), data.intArray.end());
    protobufContainer.mutable_longarray()->   Reserve(data.longArray.size());
    protobufContainer.mutable_longarray()->   Assign(data.longArray.begin(), data.longArray.end());
    protobufContainer.mutable_floatarray()->  Reserve(data.floatArray.size());
    protobufContainer.mutable_floatarray()->  Assign(data.floatArray.begin(), data.floatArray.end());
    protobufContainer.mutable_doublearray()-> Reserve(data.doubleArray.size());
    protobufContainer.mutable_doublearray()-> Assign(data.doubleArray.begin(), data.doubleArray.end());
    // n-dim arrays
    protobufContainer.mutable_ndimensions()->Reserve(data.boolNdimArray.dimensions().size());
    protobufContainer.mutable_ndimensions()->Assign(data.boolNdimArray.dimensions().begin(), data.boolNdimArray.dimensions().end());

    protobufContainer.mutable_boolndimarray()->Reserve(data.boolNdimArray.elements().size());
    protobufContainer.mutable_boolndimarray()->Assign(data.boolNdimArray.elements().begin(), data.boolNdimArray.elements().end());

    protobufContainer.mutable_intndimarray()->Reserve(data.intNdimArray.elements().size());
    protobufContainer.mutable_intndimarray()->Assign(data.intNdimArray.elements().begin(), data.intNdimArray.elements().end());

    protobufContainer.mutable_longndimarray()->Reserve(data.longNdimArray.elements().size());
    protobufContainer.mutable_longndimarray()->Assign(data.longNdimArray.elements().begin(), data.longNdimArray.elements().end());

    protobufContainer.mutable_floatndimarray()->Reserve(data.floatNdimArray.elements().size());
    protobufContainer.mutable_floatndimarray()->Assign(data.floatNdimArray.elements().begin(), data.floatNdimArray.elements().end());

    protobufContainer.mutable_doublendimarray()->Reserve(data.doubleNdimArray.elements().size());
    protobufContainer.mutable_doublendimarray()->Assign(data.doubleNdimArray.elements().begin(), data.doubleNdimArray.elements().end());
}

static void setPocoFromContainer(const protobuf::TestDataClass &protobufContainer, TestDataClass &data) {
    data.bool1 = protobufContainer.bool1();
    data.bool2 = protobufContainer.bool2();
    // byte1   = 10;
    // byte2   = -100;
    // char1   = 'a';
    // char2   = 'Z';
    // short1  = 20;
    // short2  = -200;
    data.int1 = protobufContainer.int1();
    data.int2 = protobufContainer.int2();
    data.long1 = protobufContainer.long1();
    data.long2 = protobufContainer.long2();
    data.float1 = protobufContainer.float1();
    data.float2 = protobufContainer.float2();
    data.double1 = protobufContainer.double1();
    data.double2 = protobufContainer.double2();
    data.string1 = protobufContainer.string1();
    data.string2 = protobufContainer.string2();
    // 1d arrays
    data.boolArray.resize(protobufContainer.boolarray_size());
    std::copy(protobufContainer.boolarray().begin(), protobufContainer.boolarray().end(), data.boolArray.begin());
    data.intArray.resize(protobufContainer.intarray_size());
    std::copy(protobufContainer.intarray().begin(), protobufContainer.intarray().end(), data.intArray.begin());
    data.longArray.resize(protobufContainer.longarray_size());
    std::copy(protobufContainer.longarray().begin(), protobufContainer.longarray().end(), data.longArray.begin());
    data.floatArray.resize(protobufContainer.floatarray_size());
    std::copy(protobufContainer.floatarray().begin(), protobufContainer.floatarray().end(), data.floatArray.begin());
    data.doubleArray.resize(protobufContainer.doublearray_size());
    std::copy(protobufContainer.doublearray().begin(), protobufContainer.doublearray().end(), data.doubleArray.begin());
    // N-dim arrays
    std::copy(protobufContainer.ndimensions().begin(), protobufContainer.ndimensions().end(), data.boolNdimArray.dimensions().begin());
    std::copy(protobufContainer.ndimensions().begin(), protobufContainer.ndimensions().end(), data.intNdimArray.dimensions().begin());
    std::copy(protobufContainer.ndimensions().begin(), protobufContainer.ndimensions().end(), data.longNdimArray.dimensions().begin());
    std::copy(protobufContainer.ndimensions().begin(), protobufContainer.ndimensions().end(), data.floatNdimArray.dimensions().begin());
    std::copy(protobufContainer.ndimensions().begin(), protobufContainer.ndimensions().end(), data.doubleNdimArray.dimensions().begin());

    data.boolNdimArray.elements().resize(protobufContainer.boolndimarray_size());
    std::copy(protobufContainer.boolndimarray().begin(), protobufContainer.boolndimarray().end(), data.boolNdimArray.elements().begin());
    data.intNdimArray.elements().resize(protobufContainer.intndimarray_size());
    std::copy(protobufContainer.intndimarray().begin(), protobufContainer.intndimarray().end(), data.intNdimArray.elements().begin());
    data.longNdimArray.elements().resize(protobufContainer.longndimarray_size());
    std::copy(protobufContainer.longndimarray().begin(), protobufContainer.longndimarray().end(), data.longNdimArray.elements().begin());
    data.floatNdimArray.elements().resize(protobufContainer.floatndimarray_size());
    std::copy(protobufContainer.floatndimarray().begin(), protobufContainer.floatndimarray().end(), data.floatNdimArray.elements().begin());
    data.doubleNdimArray.elements().resize(protobufContainer.doublendimarray_size());
    std::copy(protobufContainer.doublendimarray().begin(), protobufContainer.doublendimarray().end(), data.doubleNdimArray.elements().begin());
}

static void protobuf_bench(benchmark::State &state) {
    static const int N_ARRAY = 1000;
    // Seed with a real random value, if available
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<size_t> randomArrayIndex(0, N_ARRAY-1);

    size_t dataSize = TestDataClass::get_data_size(N_ARRAY, 0, 0);
    // generate random input data
    TestDataClass dataA(N_ARRAY, 0, 0);    // numeric heavy data <-> equivalent to Java benchmark
    TestDataClass dataB(N_ARRAY, 0, 0);    // numeric heavy data <-> equivalent to Java benchmark
    // received data
    TestDataClass testData2;

    // initialize sample data
    protobuf::TestDataClass testClass;
    protobuf::TestDataClass recovered;
    // benchmark loop
    std::vector<char> data{};
    int i = 0;
    for (auto _ : state) {
        i++;
        // code to benchmark
        setContainerFromPoco(testClass, i % 2 == 0 ? dataA : dataB);
        auto len = testClass.ByteSizeLong();
        data.resize(len);
        testClass.SerializeToArray(data.data(), static_cast<int>(len));
        recovered.ParseFromArray(data.data(), len);
        setPocoFromContainer(recovered, testData2);
        auto randomIdx = randomArrayIndex(e1);
        try {
            if ((i % 2 == 0 ? dataA : dataB).doubleArray.at(randomIdx) != testData2.doubleArray.at(randomIdx)) {
                state.SkipWithError(("double arrays not identical" + std::to_string(randomIdx)).c_str());
                break;
            }
        } catch (std::exception &e) {
            state.SkipWithError((std::string("caught exception: ") + opencmw::typeName<std::remove_reference_t<decltype(e)>>.data() + e.what()).c_str());
            break;
        } catch (...) {
            state.SkipWithError("unknown exception");
            break;
        }
        benchmark::DoNotOptimize(testClass);
        benchmark::DoNotOptimize(recovered);
        benchmark::DoNotOptimize(dataA);
        benchmark::DoNotOptimize(dataB);
        benchmark::DoNotOptimize(testData2);
        benchmark::ClobberMemory();
    }
    state.counters["BytesProcessed"] = benchmark::Counter(static_cast<int>(dataSize), benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1024);
    state.counters["wireSize"] = static_cast<int>(data.size());
    state.counters["dataSize"] = static_cast<int>(dataSize);
    state.counters["ItemsProcessed"] = benchmark::Counter(1, benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1000);
}

BENCHMARK(protobuf_bench)->Name("Protobuf")->Repetitions(5);
