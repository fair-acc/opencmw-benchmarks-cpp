#include "IoClassSerialiserBenchmark.hpp"
#include <opencmw/IoClassSerialiser.hpp>
#include <opencmw/Utils.hpp>
#include <benchmark/benchmark.h>

using namespace opencmw;
using namespace opencmw::utils; // for operator<< and fmt::format overloading

static void opencmw_bench(benchmark::State &state) {
    IoBuffer      buffer;
    TestDataClass testData(1000, 0);    // numeric heavy data <-> equivalent to Java benchmark
    testData.bool1 = true;
    testData.bool2 = false;
    for (size_t i = 0; i < testData.intArray.size(); i++) {
        testData.intArray[i] = i % 255;
    }
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

        assert(testData == testData2);
        if (testData.string1 != testData2.string1) {
            // quick check necessary so that the above is not optimised by the Java JIT compiler to NOP
            throw std::exception();
        }
        benchmark::DoNotOptimize(buffer);
        benchmark::DoNotOptimize(testData);
        benchmark::DoNotOptimize(testData2);
        benchmark::ClobberMemory();
    }
    state.SetBytesProcessed(written);
}

BENCHMARK(opencmw_bench)->Name("OpenCMW")->Repetitions(5);
