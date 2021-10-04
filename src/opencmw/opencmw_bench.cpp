#include "../TestDataClass.hpp"
#include <benchmark/benchmark.h>
#include <opencmw/IoClassSerialiser.hpp>
#include <opencmw/Utils.hpp>
#include <random>

using namespace opencmw;
using namespace opencmw::utils; // for operator<< and fmt::format overloading

/*
 * Simple opencmw benchmark.
 * Alternates between 2 different input domain objects and always compare a random array element.
 * After the benchmark compare the full domain object.
 */
static void opencmw_bench(benchmark::State &state) {
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

    // buffer for storage
    IoBuffer buffer;
    int      i = 0;
    for (auto _ : state) {
        i++;
        try {
            buffer.clear();
            opencmw::serialise<YaS, false>(buffer, i % 2 == 0 ? dataA : dataB);
            buffer.reset();
            opencmw::deserialise<YaS, ProtocolCheck::LENIENT>(buffer, testData2);
            //opencmw::deserialise<YaS, ProtocolCheck::LENIENT>(buffer, testData2);
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
        } catch (std::exception &e) {
            state.SkipWithError((std::string("exception: ") + typeName<std::remove_reference_t<decltype(e)>>.data() + std::string(": ") + e.what()).c_str());
            break;
        } catch (opencmw::ProtocolException &e) {
            state.SkipWithError((std::string("ProtocolException: ") + typeName<std::remove_reference_t<decltype(e)>>.data() + std::string(": ") + std::string(e.what())).c_str());
            break;
        } catch (...) {
            state.SkipWithError("unknown exception");
            break;
        }
        benchmark::DoNotOptimize(buffer);
        benchmark::DoNotOptimize(dataA);
        benchmark::DoNotOptimize(dataB);
        benchmark::DoNotOptimize(testData2);
        benchmark::ClobberMemory();
    }
    //if ((i % 2 == 0 ? dataA : dataB) != testData2) { // full check outside of benchmark loop
    //    state.SkipWithError("input and output array not identical");
    //}
    state.counters["BytesProcessed"] = benchmark::Counter(static_cast<int>(dataSize), benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1024);
    state.counters["ItemsProcessed"] = benchmark::Counter(1, benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1000);
    state.counters["wireSize"]       = static_cast<int>(buffer.size());
    state.counters["dataSize"]       = static_cast<int>(dataSize);
}

BENCHMARK(opencmw_bench)->Name("OpenCMW")->Repetitions(3)->Args({ 1000, 0, 0 })->Args({ 10, 100, 1 })->ArgsProduct({{256, 512, 1024, 2048, 4096, 8192}, {0}, {0}});
