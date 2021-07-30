#include "TestDataClass.capnp.h"
#include <capnp/serialize.h>
#include <benchmark/benchmark.h>
#include <iostream>
#include <random>

static void capnproto_bench(benchmark::State &state) {
    static const int N_ARRAY = 1000;
    size_t dataSize = 0;
    std::string string1("Hello World!");
    std::string string2("Γειά σου Κόσμε!");
    dataSize += 2 * sizeof(bool);
    dataSize += 2 * sizeof(int);
    dataSize += 2 * sizeof(long);
    dataSize += 2 * sizeof(float);
    dataSize += 2 * sizeof(double);
    dataSize += string1.size();
    dataSize += string2.size();
    dataSize += N_ARRAY * sizeof(bool);
    dataSize += N_ARRAY * sizeof(int);
    dataSize += N_ARRAY * sizeof(long);
    dataSize += N_ARRAY * sizeof(float);
    dataSize += N_ARRAY * sizeof(double);
    //setup
    std::random_device r;
    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    // initialize sample data
    ::capnp::MallocMessageBuilder message_builder;
    TestDataClass::Builder testClass = message_builder.initRoot<TestDataClass>();
    // benchmark loop
    size_t written = 0;
    size_t size = 0;
    for (auto _ : state) {
        // code to benchmark
        testClass.setBool1(true);
        testClass.setBool2(false);
        // byte1   = 10;
        // byte2   = -100;
        // char1   = 'a';
        // char2   = 'Z';
        // short1  = 20;
        // short2  = -200;
        testClass.setInt1(30);
        testClass.setInt2(-300);
        testClass.setLong1(40);
        testClass.setLong2(-400);
        testClass.setFloat1(50.5f);
        testClass.setFloat2(-500.5f);
        testClass.setDouble1(60.6);
        testClass.setDouble2(-600.6);
        testClass.setString1(string1);
        testClass.setString2(string2);

        ::capnp::List<bool>::Builder        boolarray   = testClass.initBoolArray(N_ARRAY);
        ::capnp::List<int>::Builder         intarray    = testClass.initIntArray(N_ARRAY);
        ::capnp::List<long>::Builder        longarray   = testClass.initLongArray(N_ARRAY);
        ::capnp::List<float>::Builder       floatarray  = testClass.initFloatArray(N_ARRAY);
        ::capnp::List<double>::Builder      doublearray = testClass.initDoubleArray(N_ARRAY);
        // ::capnp::List<capnp::Text>::Builder stringarray = testClass.initStringArray(N_ARRAY);
        for (capnp::uint i = 0; i < N_ARRAY; i++) {
            // boolarray.set(i, (e1() % 2 != 0));
            // // byte, char, short?
            // intarray.set(i, static_cast<int>(e1()));
            // longarray.set(i, static_cast<long>(e1()));
            // floatarray.set(i, static_cast<float>(e1()) * 1.0f);
            // doublearray.set(i, (static_cast<double>(e1()) * 1.0));
            // stringarray.set(i, ("test" + std::to_string(e1())));
            boolarray.set(i, (e1() % 2 != 0));
            intarray.set(i, static_cast<int>(e1()));
            longarray.set(i, static_cast<long>(e1()));
            floatarray.set(i, static_cast<float>(e1()) * 1.0f);
            doublearray.set(i, (static_cast<double>(e1()) * 1.0));
            // stringarray.set(i, ("test" + std::to_string(e1())));
        }
        // multidim
        auto data = ::capnp::messageToFlatArray(message_builder);
        written += data.size();
        size = data.size();
        ::capnp::FlatArrayMessageReader message_receiver_builder(data);
        auto messageReceiver = message_receiver_builder.getRoot<TestDataClass>();
        assert(messageReceiver.getBool1());
        assert(!messageReceiver.getBool2());
        benchmark::DoNotOptimize(data);
        benchmark::DoNotOptimize(messageReceiver);
        benchmark::ClobberMemory();
    }
    state.counters["BytesProcessed"] = benchmark::Counter(static_cast<int>(dataSize), benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1024);
    state.counters["ItemsProcessed"] = benchmark::Counter(1, benchmark::Counter::kIsIterationInvariantRate, benchmark::Counter::OneK::kIs1000);
    state.counters["wireSize"] = static_cast<int>(size);
    state.counters["dataSize"] = static_cast<int>(dataSize);
}

BENCHMARK(capnproto_bench)->Name("CapnProto")->Repetitions(5);
