#include "../TestDataClass.hpp"
#include "TestDataClass_generated.h"
#include <benchmark/benchmark.h>
#include <iostream>
#include <random>
#include <string>

using namespace flatbuffers;
using namespace fb_bench;

static void setContainerFromPoco(fb_bench::TestDataClassFbT &testDataClassFB, const TestDataClass &data) {
    testDataClassFB.bool1   = data.bool1;
    testDataClassFB.bool2   = data.bool2;
    testDataClassFB.byte1   = data.byte1;
    testDataClassFB.byte2   = data.byte2;
    testDataClassFB.char1   = data.char1;
    testDataClassFB.char2   = data.char2;
    testDataClassFB.short1  = data.short1;
    testDataClassFB.short2  = data.short2;
    testDataClassFB.int1    = data.int1;
    testDataClassFB.int2    = data.int2;
    testDataClassFB.long1   = data.long1;
    testDataClassFB.long2   = data.long2;
    testDataClassFB.float1  = data.float1;
    testDataClassFB.float2  = data.float2;
    testDataClassFB.double1 = data.double1;
    testDataClassFB.double2 = data.double2;
    testDataClassFB.string1 = data.string1;
    testDataClassFB.string2 = data.string2;
    // 1-dim arrays
    testDataClassFB.boolArray       = data.boolArray;
    testDataClassFB.byteArray       = data.byteArray;
    testDataClassFB.shortArray      = data.shortArray;
    testDataClassFB.intArray        = data.intArray;
    testDataClassFB.longArray       = data.longArray;
    testDataClassFB.floatArray      = data.floatArray;
    testDataClassFB.doubleArray     = data.doubleArray;
    testDataClassFB.stringArray     = data.stringArray;

    testDataClassFB.nDimensions     = std::vector(data.boolNdimArray.dimensions().begin(), data.boolNdimArray.dimensions().end());
    testDataClassFB.boolNdimArray   = data.boolNdimArray.elements();
    testDataClassFB.byteNdimArray   = data.byteNdimArray.elements();
    testDataClassFB.shortNdimArray  = data.shortNdimArray.elements();
    testDataClassFB.intNdimArray    = data.intNdimArray.elements();
    testDataClassFB.longNdimArray   = data.longNdimArray.elements();
    testDataClassFB.floatNdimArray  = data.floatNdimArray.elements();
    testDataClassFB.doubleNdimArray = data.doubleNdimArray.elements();

    if (data.nestedData) {
        testDataClassFB.nestedData = std::unique_ptr<TestDataClassFbT>(new TestDataClassFbT{});
        setContainerFromPoco(*(testDataClassFB.nestedData), *(data.nestedData));
    }
}

static void setPocoFromContainer(const fb_bench::TestDataClassFbT &testDataClassFB, TestDataClass &data) {
    data.bool1   = testDataClassFB.bool1;
    data.bool2   = testDataClassFB.bool2;
    data.byte1   = testDataClassFB.byte1;
    data.byte2   = testDataClassFB.byte2;
    data.char1   = testDataClassFB.char1;
    data.char2   = testDataClassFB.char2;
    data.short1  = testDataClassFB.short1;
    data.short2  = testDataClassFB.short2;
    data.int1    = testDataClassFB.int1;
    data.int2    = testDataClassFB.int2;
    data.long1   = testDataClassFB.long1;
    data.long2   = testDataClassFB.long2;
    data.float1  = testDataClassFB.float1;
    data.float2  = testDataClassFB.float2;
    data.double1 = testDataClassFB.double1;
    data.double2 = testDataClassFB.double2;
    data.string1 = testDataClassFB.string1;
    data.string2 = testDataClassFB.string2;
    // 1-dim arrays
    data.boolArray   = testDataClassFB.boolArray;
    data.byteArray   = testDataClassFB.byteArray;
    data.shortArray  = testDataClassFB.shortArray;
    data.intArray    = testDataClassFB.intArray;
    data.longArray   = testDataClassFB.longArray;
    data.floatArray  = testDataClassFB.floatArray;
    data.doubleArray = testDataClassFB.doubleArray;
    data.stringArray = testDataClassFB.stringArray;

    std::array<uint, 3> dims;
    std::copy_n(testDataClassFB.nDimensions.begin(), 3, dims.begin());
    data.boolNdimArray.dimensions()   = dims;
    data.boolNdimArray.elements()     = testDataClassFB.boolNdimArray;
    data.byteNdimArray.dimensions()   = dims;
    data.byteNdimArray.elements()     = testDataClassFB.byteNdimArray;
    data.shortNdimArray.dimensions()  = dims;
    data.shortNdimArray.elements()    = testDataClassFB.shortNdimArray;
    data.intNdimArray.dimensions()    = dims;
    data.intNdimArray.elements()      = testDataClassFB.intNdimArray;
    data.longNdimArray.dimensions()   = dims;
    data.longNdimArray.elements()     = testDataClassFB.longNdimArray;
    data.floatNdimArray.dimensions()  = dims;
    data.floatNdimArray.elements()    = testDataClassFB.floatNdimArray;
    data.doubleNdimArray.dimensions() = dims;
    data.doubleNdimArray.elements()   = testDataClassFB.doubleNdimArray;

    if (testDataClassFB.nestedData) {
        data.nestedData = std::unique_ptr<TestDataClass>(new TestDataClass{});
        setPocoFromContainer(*(testDataClassFB.nestedData), *(data.nestedData));
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

    size_t                                dataSize = TestDataClass::get_data_size(n_numerals, n_strings, 0);
    // generate random input data
    const TestDataClass dataA(n_numerals, n_strings, n_nesting); // numeric heavy data <-> equivalent to Java benchmark
    const TestDataClass dataB(n_numerals, n_strings, n_nesting); // numeric heavy data <-> equivalent to Java benchmark
    // received data
    TestDataClass     testData2;

    TestDataClassFbT  in{};
    TestDataClassFbT  out{};

    FlatBufferBuilder fbb;
    size_t            size = 0;
    // benchmark loop
    int i = 0;
    for (auto _ : state) {
        try {
            i++;
            fbb.Clear();
            setContainerFromPoco(in, i % 2 == 0 ? dataA : dataB);
            fbb.Finish(TestDataClassFb::Pack(fbb, &in));
            size      = fbb.GetSize();
            auto data = fbb.GetBufferPointer();
            GetTestDataClassFb(data)->UnPackTo(&out);
            setPocoFromContainer(out, testData2);
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
            state.SkipWithError(
                    (std::string("caught exception: ") + opencmw::typeName<std::remove_reference_t<decltype(e)>>.data() + e.what()).c_str());
            break;
        } catch (...) {
            state.SkipWithError("unknown exception");
            break;
        }
    }
    // benchmark loop
    state.counters["BytesProcessed"] = benchmark::Counter(static_cast<int>(dataSize),
            benchmark::Counter::kIsIterationInvariantRate,
            benchmark::Counter::OneK::kIs1024);
    state.counters["ItemsProcessed"] = benchmark::Counter(1, benchmark::Counter::kIsIterationInvariantRate,
            benchmark::Counter::OneK::kIs1000);
    state.counters["wireSize"]       = static_cast<int>(size);
    state.counters["dataSize"]       = static_cast<int>(dataSize);
}

BENCHMARK(capnproto_bench)->Name("Flatbuffers(object api)")->Repetitions(3)->Args({ 10000, 0, 0 })->Args({ 10, 100, 1 })->ArgsProduct({{256, 512, 1024, 2048, 4096, 8192}, {0}, {0}});
