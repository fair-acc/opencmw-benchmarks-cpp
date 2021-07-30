#include "IoClassSerialiserBenchmark.hpp"
#include <opencmw/IoClassSerialiser.hpp>
#include <opencmw/Utils.hpp>
#include <benchmark/benchmark.h>
#include <random>

using namespace opencmw;
using namespace opencmw::utils; // for operator<< and fmt::format overloading

static void opencmw_bench(benchmark::State &state) {
    // Seed with a real random value, if available
    std::random_device r;
    std::default_random_engine e1(r());

    size_t dataSize = 0;

    IoBuffer      buffer;
    TestDataClass testData(1000, 0);    // numeric heavy data <-> equivalent to Java benchmark
    testData.bool1 = true;
    testData.bool2 = false;
    dataSize += 2 * sizeof(bool);
    testData.byte1   = 10;
    testData.byte2   = -100;
    dataSize += 2 * sizeof(int8_t);
    testData.char1   = 'a';
    testData.char2   = 'Z';
    dataSize += 2 * sizeof(char);
    testData.short1  = 20;
    testData.short2  = -200;
    dataSize += 2 * sizeof(short);
    testData.int1 = 30;
    testData.int2 = -300;
    dataSize += 2 * sizeof(int);
    testData.long1 = 40;
    testData.long2 = -400;
    dataSize += 2 * sizeof(long);
    testData.float1 = 50.5f;
    testData.float2 = -500.5f;
    dataSize += 2 * sizeof(float);
    testData.double1 = 60.6;
    testData.double2 = -600.6;
    dataSize += 2 * sizeof(double);
    testData.string1 = std::string("Hello World!");
    dataSize += testData.string1.size();
    testData.string2 = std::string("Γειά σου Κόσμε!");
    dataSize += testData.string2.size();

    for (size_t i = 0; i < testData.intArray.size(); i++) {
        testData.boolArray[i] =  static_cast<uint8_t>(e1()); // bool arrrays are special
        testData.byteArray[i] =  static_cast<int8_t>(e1());
        testData.shortArray[i] = static_cast<short>(e1());
        testData.intArray[i] = static_cast<int>(e1());
        testData.longArray[i] = static_cast<long>(e1());
        testData.floatArray[i] =  static_cast<float>(e1());
        testData.doubleArray[i] =  static_cast<double>(e1());
        //testData.stringArray.emplace_back(std::to_string(e1())); // ignore string arrays for now
    }
    dataSize += testData.intArray.size() * sizeof(uint8_t); // bool arrays are special
    dataSize += testData.intArray.size() * sizeof(int8_t);
    dataSize += testData.intArray.size() * sizeof(short);
    dataSize += testData.intArray.size() * sizeof(int);
    dataSize += testData.intArray.size() * sizeof(long);
    dataSize += testData.intArray.size() * sizeof(float);
    dataSize += testData.intArray.size() * sizeof(double);

    // multi dim data left as default content
    size_t nDims = static_cast<size_t>(testData.nDimensions[0] * testData.nDimensions[1] * testData.nDimensions[2]);
    dataSize += nDims * sizeof(uint8_t);
    dataSize += nDims * sizeof(int8_t);
    dataSize += nDims * sizeof(short);
    dataSize += nDims * sizeof(int);
    dataSize += nDims * sizeof(long);
    dataSize += nDims * sizeof(float);
    dataSize += nDims * sizeof(double);

    // received data
    TestDataClass testData2;
    // benchmark loop
    size_t written = 0;
    for (auto _ : state) {
        buffer.clear();
        opencmw::serialise<YaS>(buffer, testData, false);
        buffer.reset();
        written += buffer.size();
        try {
            opencmw::deserialise<YaS>(buffer, testData2);
        } catch (std::exception &e) {
            std::cout << "caught exception " << typeName<std::remove_reference_t<decltype(e)>> << std::endl;
        } catch (...) {
            std::cout << "caught unknown exception " << std::endl;
        }

        if (testData.string1 != testData2.string1) {
            throw std::exception();
        }
        benchmark::DoNotOptimize(buffer);
        benchmark::DoNotOptimize(testData);
        benchmark::DoNotOptimize(testData2);
        benchmark::ClobberMemory();
    }
    assert(testData == testData2);
    state.counters["BytesProcessed"] = benchmark::Counter(static_cast<int>(dataSize), benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1024);
    state.counters["wireSize"] = static_cast<int>(buffer.size());
    state.counters["structSize"] = static_cast<int>(sizeof(TestDataClass));
    state.counters["dataSize"] = static_cast<int>(dataSize);
}

BENCHMARK(opencmw_bench)->Name("OpenCMW")->Repetitions(5);
