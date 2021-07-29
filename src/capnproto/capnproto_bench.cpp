#include "TestDataClass.capnp.h"
#include <capnp/serialize.h>
#include <benchmark/benchmark.h>
#include <iostream>

static void capnproto_bench(benchmark::State &state) {
    static const int N_ARRAY = 1000;
    //setup
    // initialize sample data
    ::capnp::MallocMessageBuilder message_builder;
    TestDataClass::Builder testClass = message_builder.initRoot<TestDataClass>();
    testClass.setBool1(true);
    testClass.setBool2(false);
    // // byte1   = 10;
    // // byte2   = -100;
    // // char1   = 'a';
    // // char2   = 'Z';
    // // short1  = 20;
    // // short2  = -200;
    testClass.setInt1(30);
    testClass.setInt2(-300);
    testClass.setLong1(40);
    testClass.setLong2(-400);
    testClass.setFloat1(50.5f);
    testClass.setFloat2(-500.5f);
    testClass.setDouble1(60.6);
    testClass.setDouble2(-600.6);
    testClass.setString1("Hello World!");
    testClass.setString2("Γειά σου Κόσμε!");

    ::capnp::List<bool>::Builder        boolarray   = testClass.initBoolArray(N_ARRAY);
    ::capnp::List<int>::Builder         intarray    = testClass.initIntArray(N_ARRAY);
    ::capnp::List<long>::Builder        longarray   = testClass.initLongArray(N_ARRAY);
    ::capnp::List<float>::Builder       floatarray  = testClass.initFloatArray(N_ARRAY);
    ::capnp::List<double>::Builder      doublearray = testClass.initDoubleArray(N_ARRAY);
    ::capnp::List<capnp::Text>::Builder stringarray = testClass.initStringArray(N_ARRAY);
    for (capnp::uint i = 0; i < N_ARRAY; i++) {
        boolarray.set(i, (i % 2 != 0));
        // byte, char, short?
        intarray.set(i, static_cast<int>(i));
        longarray.set(i, i);
        floatarray.set(i, static_cast<float>(i) * 1.0f);
        doublearray.set(i, (i * 1.0));
        stringarray.set(i, ("test" + std::to_string(i)));
    }
    // multidim
    // benchmark loop
    size_t written = 0;
    size_t size = 0;
    for (auto _ : state) {
        // code to benchmark
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
    state.SetBytesProcessed(static_cast<int>(written));
    std::cout << "size of object: " << size << std::endl;
}

BENCHMARK(capnproto_bench)->Name("CapnProto")->Repetitions(5);
BENCHMARK_MAIN();
