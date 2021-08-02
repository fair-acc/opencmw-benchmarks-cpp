#include "TestDataClass.pb.h"
#include <benchmark/benchmark.h>
#include <vector>
#include <string>
#include <random>

static void protobuf_bench(benchmark::State &state) {
    static const int N_ARRAY = 1000;
    // Seed with a real random value, if available
    std::random_device r;
    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<> randomArrayIndex(0, N_ARRAY-1);

    size_t dataSize = 0;

    //setup
    // initialize sample data
    benchmark::TestDataClass testClass;
    testClass.set_bool1(true);
    testClass.set_bool2(false);
    dataSize += 2 * sizeof(bool);
    // byte1   = 10;
    // byte2   = -100;
    // char1   = 'a';
    // char2   = 'Z';
    // short1  = 20;
    // short2  = -200;
    testClass.set_int1(30);
    testClass.set_int2(-300);
    dataSize += 2 * sizeof(int);
    testClass.set_long1(40);
    testClass.set_long2(-400);
    dataSize += 2 * sizeof(long);
    testClass.set_float1(50.5f);
    testClass.set_float2(-500.5f);
    dataSize += 2 * sizeof(float);
    testClass.set_double1(60.6);
    testClass.set_double2(-600.6);
    dataSize += 2 * sizeof(double);
    std::string string1("Hello World!");
    testClass.set_string1(string1);
    dataSize += string1.size();
    std::string string2("Γειά σου Κόσμε!");
    testClass.set_string2(string2);
    dataSize += string2.size();

    for (auto i = 0; i < N_ARRAY; i++) {
        testClass.add_boolarray(e1() % 2 != 0);
        // byte, char, short?
        testClass.add_intarray(static_cast<int>(e1()));
        testClass.add_longarray(static_cast<int>(e1()));
        testClass.add_floatarray(static_cast<float>(e1()));
        testClass.add_doublearray(static_cast<double>(e1()));
        //testClass.add_stringarray("test" + std::to_string(e1()));
        // multidim
    }
    dataSize += N_ARRAY * sizeof(bool);
    dataSize += N_ARRAY * sizeof(int);
    dataSize += N_ARRAY * sizeof(long);
    dataSize += N_ARRAY * sizeof(float);
    dataSize += N_ARRAY * sizeof(double);
    // benchmark loop
    size_t written = 0;
    auto len = testClass.ByteSizeLong();
    std::vector<char> data(len);
    for (auto _ : state) {
        // code to benchmark
        testClass.SerializeToArray(data.data(), static_cast<int>(len));
        written += len;
        benchmark::TestDataClass recovered;
        recovered.ParseFromArray(data.data(), len);
        auto randomIdx = randomArrayIndex(e1);
        try {
            if (testClass.doublearray().at(randomIdx) != recovered.doublearray().at(randomIdx)) {
                state.SkipWithError(std::string("double arrays not identical at " + std::to_string(randomIdx)).c_str());
                break;
            }
        } catch (...) {
            state.SkipWithError(std::string("problem accessing double array at index" + std::to_string(randomIdx)).c_str());
            break;
        }
        benchmark::DoNotOptimize(recovered);
        benchmark::ClobberMemory();
    }
    state.counters["BytesProcessed"] = benchmark::Counter(static_cast<int>(dataSize), benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1024);
    state.counters["wireSize"] = static_cast<int>(len);
    state.counters["dataSize"] = static_cast<int>(dataSize);
    state.counters["ItemsProcessed"] = benchmark::Counter(1, benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1000);
}

BENCHMARK(protobuf_bench)->Name("Protobuf")->Repetitions(5);
