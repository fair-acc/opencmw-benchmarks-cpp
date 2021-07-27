#include "TestDataClass.capnp.h"
#include <capnp/message.h>
#include <capnp/serialize-packed.h>
#include <benchmark/benchmark.h>
#include <array>
#include <string>

static void protobuf_bench(benchmark::State &state) {
    static const int N_ARRAY = 1000;
    //setup
    // initialize sample data
    ::capnp::MallocMessageBuilder message;
    TestDataClass::Builder testClassBuilder = message.initRoot<TestDataClass>();
    // testClass.set_bool1(true);
    // testClass.set_bool2(false);
    // // byte1   = 10;
    // // byte2   = -100;
    // // char1   = 'a';
    // // char2   = 'Z';
    // // short1  = 20;
    // // short2  = -200;
    // testClass.set_int1(30);
    // testClass.set_int2(-300);
    // testClass.set_long1(40);
    // testClass.set_long2(-400);
    // testClass.set_float1(50.5f);
    // testClass.set_float2(-500.5f);
    // testClass.set_double1(60.6);
    // testClass.set_double2(-600.6);
    // testClass.set_string1("Hello World!");
    // testClass.set_string2("Γειά σου Κόσμε!");

    // for (auto i = 0; i < N_ARRAY; i++) {
    //     testClass.add_boolarray(i % 2 != 0);
    //     // byte, char, short?
    //     testClass.add_intarray(i);
    //     testClass.add_longarray(i);
    //     testClass.add_floatarray(i * 1.0f);
    //     testClass.add_doublearray(i * 1.0);
    //     testClass.add_stringarray("test" + std::to_string(i));
    //     // multidim
    // }
    // benchmark loop
    size_t written = 0;
    kj::VectorOutputStream data;
    for (auto _ : state) {
        // code to benchmark
        testClass.serialise(testClassBuilder);
        writeMessage(buffer, output);
        written += buffer.length();
        TestDataClass recovered;
        kj::ArrayInputStream array(buffer.getArray());
        capnp::InputStreamMessageReader input(array);
        TestDataClass deserialised;
        deserialised.Deserialize(input.getRoot<TestDataClass>());
        benchmark::DoNotOptimize(data);
        benchmark::ClobberMemory();
    }
    state.SetBytesProcessed(written);
}

BENCHMARK(protobuf_bench)->Name("Protobuf")->Repetitions(5);

BENCHMARK_MAIN();