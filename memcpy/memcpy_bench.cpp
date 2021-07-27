#include <benchmark/benchmark.h>
#include <cstring>

static void protobuf_bench(benchmark::State &state) {
    static const int N_ARRAY = 30000;
    char SourceArray[N_ARRAY];
    char DstArray[N_ARRAY];

    for (auto i = 0; i < N_ARRAY; i++) {
        SourceArray[i] =  i % 256;
    }
    // benchmark loop
    size_t written = 0;
    for (auto _ : state) {
        // code to benchmark
        std::memcpy(SourceArray, DstArray, N_ARRAY);
        written += N_ARRAY;
        benchmark::DoNotOptimize(SourceArray);
        benchmark::DoNotOptimize(DstArray);
        benchmark::ClobberMemory();
        std::memcpy(DstArray, SourceArray, N_ARRAY);
        benchmark::DoNotOptimize(SourceArray);
        benchmark::DoNotOptimize(DstArray);
        benchmark::ClobberMemory();
    }
    state.SetBytesProcessed(written);
}

BENCHMARK(protobuf_bench)->Name("Protobuf")->Repetitions(5);

BENCHMARK_MAIN();