#include "../TestDataClass.hpp"
#include <opencmw/IoClassSerialiser.hpp>
#include <opencmw/Utils.hpp>
#include <benchmark/benchmark.h>
#include <random>

using namespace opencmw;
using namespace opencmw::utils; // for operator<< and fmt::format overloading

/*
 * Simple opencmw benchmark.
 * Alternates between 2 different input domain objects and always compare a random array element.
 * After the benchmark compare the full domain object.
 */
static void opencmw_bench(benchmark::State &state) {
    static const int N_ARRAY = 1000;
    // Seed with a real random value, if available
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<size_t> randomArrayIndex(0, N_ARRAY-1);

    size_t dataSize = TestDataClass::get_data_size(N_ARRAY, 0, 0);
    // generate random input data
    TestDataClass testDataA(N_ARRAY, 0, 0);    // numeric heavy data <-> equivalent to Java benchmark
    TestDataClass testDataB(N_ARRAY, 0, 0);    // numeric heavy data <-> equivalent to Java benchmark

    // buffer for storage
    IoBuffer      buffer;
    // received data
    TestDataClass testData2;
    // benchmark loop
    size_t written = 0;
    int i = 0;
    for (auto _ : state) {
        i++;
        buffer.clear();
        opencmw::serialise<YaS>(buffer, i % 2 == 0 ? testDataA : testDataB, false);
        buffer.reset();
        written += buffer.size();
        try {
            opencmw::deserialise<YaS>(buffer, testData2);
        } catch (std::exception &e) {
            std::cout << "caught exception " << typeName<std::remove_reference_t<decltype(e)>> << std::endl;
        } catch (...) {
            std::cout << "caught unknown exception " << std::endl;
        }
        auto randomIdx = randomArrayIndex(e1);
        if ((i % 2 == 0 ? testDataA : testDataB).doubleArray.at(randomIdx) != testData2.doubleArray.at(randomIdx)) {
            state.SkipWithError(("double arrays not identical" + std::to_string(randomIdx)).c_str());
            break;
        }
        benchmark::DoNotOptimize(buffer);
        benchmark::DoNotOptimize(testDataA);
        benchmark::DoNotOptimize(testDataB);
        benchmark::DoNotOptimize(testData2);
        benchmark::ClobberMemory();
    }
    if ((i % 2 == 0 ? testDataA : testDataB) != testData2) { // full check outside of benchmark loop
        state.SkipWithError("input and output array not identical");
    }
    state.counters["BytesProcessed"] = benchmark::Counter(static_cast<int>(dataSize), benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1024);
    state.counters["ItemsProcessed"] = benchmark::Counter(1, benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1000);
    state.counters["wireSize"] = static_cast<int>(buffer.size());
    state.counters["dataSize"] = static_cast<int>(dataSize);
}

BENCHMARK(opencmw_bench)->Name("OpenCMW")->Repetitions(5);
