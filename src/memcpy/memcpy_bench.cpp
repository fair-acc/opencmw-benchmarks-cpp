#include <benchmark/benchmark.h>
#include <cstring>
#include <random>

static void memcpy_bench(benchmark::State &state) {
    static const int N_ARRAY = 30000;
    // Seed with a real random value, if available
    std::random_device r;
    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<size_t> randomArrayIndex(0, N_ARRAY-1);
    char SourceArray[N_ARRAY];
    char DstArray[N_ARRAY];

    for (auto i = 0; i < N_ARRAY; i++) {
        SourceArray[i] = static_cast<char>(e1());
    }
    // benchmark loop
    for (auto _ : state) {
        // code to benchmark
        std::memcpy(SourceArray, DstArray, N_ARRAY);
        benchmark::DoNotOptimize(SourceArray);
        benchmark::DoNotOptimize(DstArray);
        benchmark::ClobberMemory();
        auto randomIdx = randomArrayIndex(e1);
        if (SourceArray[randomIdx] != DstArray[randomIdx]) {
            state.SkipWithError(("copied data not identical" + std::to_string(randomIdx)).c_str());
            break;
        }
        std::memcpy(DstArray, SourceArray, N_ARRAY);
        benchmark::DoNotOptimize(SourceArray);
        benchmark::DoNotOptimize(DstArray);
        benchmark::ClobberMemory();
    }
    state.counters["BytesProcessed"] = benchmark::Counter(static_cast<int>(N_ARRAY), benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1024);
    state.counters["wireSize"] = static_cast<int>(N_ARRAY);
    state.counters["dataSize"] = static_cast<int>(N_ARRAY);
    state.counters["ItemsProcessed"] = benchmark::Counter(1, benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1000);
}

BENCHMARK(memcpy_bench)->Name("memcpy(Benchmark)")->Repetitions(5);
