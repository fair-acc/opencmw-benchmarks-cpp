#include <benchmark/benchmark.h>
#include "../TestDataClass.hpp"
#include <cstring>
#include <random>

static void memcpy_bench(benchmark::State &state) {
    auto n_numerals = static_cast<size_t>(state.range(0));
    auto n_strings  = static_cast<size_t>(state.range(1));
    auto N_ARRAY = (TestDataClass::get_data_size(n_numerals, n_strings, 0));
    // Seed with a real random value, if available
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<size_t> randomArrayIndex(0, N_ARRAY-1);

    vector<char> SourceArray(N_ARRAY);
    vector<char> DstArray(N_ARRAY);

    for (size_t i = 0; i < N_ARRAY; i++) {
        SourceArray[i] = static_cast<char>(e1());
    }
    // benchmark loop
    for (auto _ : state) {
        // code to benchmark
        std::copy(SourceArray.begin(), SourceArray.end(), DstArray.begin());
        benchmark::DoNotOptimize(SourceArray);
        benchmark::DoNotOptimize(DstArray);
        benchmark::ClobberMemory();
        auto randomIdx = randomArrayIndex(e1);
        if (SourceArray[randomIdx] != DstArray[randomIdx]) {
            state.SkipWithError(("copied data not identical" + std::to_string(randomIdx)).c_str());
            break;
        }
        std::copy(DstArray.begin(), DstArray.end(), SourceArray.begin());
        benchmark::DoNotOptimize(SourceArray);
        benchmark::DoNotOptimize(DstArray);
        benchmark::ClobberMemory();
    }
    state.counters["BytesProcessed"] = benchmark::Counter(static_cast<int>(N_ARRAY), benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1024);
    state.counters["wireSize"] = static_cast<int>(N_ARRAY);
    state.counters["dataSize"] = static_cast<int>(N_ARRAY);
    state.counters["ItemsProcessed"] = benchmark::Counter(1, benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1000);
}

BENCHMARK(memcpy_bench)->Name("memcpy(Benchmark)")->Repetitions(5)->Args({2 << 8, 0})->Args({2 << 10, 0})->Args({2 << 13, 0})->Args({0, 2 << 10});
