# Serialiser benchmarks

Small cmake project which compares the performance of different open source c++ serialisation implementations.
As always with benchmarks, this is highly subjective and tailored to a specific use case.
This benchmark compares serialising a user-supplied object into a byte buffer and back.

Compares the following projects:
- memcpy: baseline benchmark, which copies a char array of the size of the user data back and forth.
- [opencmw](https://github.com/fair-acc/opencmw-cpp/): opencmw serialiser implementation.
- [flatbuffer](https://github.com/google/flatbuffers): Flatbuffers benchmark using the object api. Uses one additional copy and not the auto generated c++ object.
- [capnproto](https://capnproto.org/)
- [protobuf](https://developers.google.com/protocol-buffers): Google protocol buffers.

## Prerequisites

Since opencmw is not yet published as a conan package, you have to install it into your local conan cache first:
Clone the opencmw-cpp repository, create a conanbuild directory and run `conan create ..` from it:

```bash
git clone https://github.com/fair-acc/opencmw-cpp.git
cd opencmw-cpp
mkdir conanbuild
cd conanbuild
conan create ..
```

Also, if you plan to change the flatbuffers idl file, you need to have flatbuffers `flatc` compiler installed in your path.

## Building

optional: recompile the flatbuffers headers if changes where made (cmake integration did not work properly).

```bash
cd src/flatbuffers && flatc --cpp --gen-object-api TestDataClass.fbs && cd -
```

then, compile the project.

```bash
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release && cmake --build build
```

## Running

run the benchmark with

```bash
build/bin/bench --benchmark_display_aggregates_only=true  --benchmark_counters_tabular=true --benchmark_color=true
```

To see the other available parameters (e.g. csv/json output) run

```bash
build/bin/bench --help
```

You might have to [disable frequency scaling](https://github.com/google/benchmark#disabling-cpu-frequency-scaling) if googlebench complains about it.

## Example output

```
$ build/bin/bench --benchmark_display_aggregates_only=true  --benchmark_counters_tabular=true --benchmark_color=true
2021-08-04T13:33:07+02:00
Running build/bin/bench
Run on (8 X 3900 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x4)
  L1 Instruction 32 KiB (x4)
  L2 Unified 1024 KiB (x4)
  L3 Unified 8448 KiB (x1)
Load Average: 0.81, 0.59, 0.50
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
-----------------------------------------------------------------------------------------------------------------------------------------------
Benchmark                                                 Time             CPU   Iterations BytesProcessed ItemsProcessed   dataSize   wireSize
-----------------------------------------------------------------------------------------------------------------------------------------------
memcpy(Benchmark)/512/0/repeats:5_mean                  189 ns          189 ns            5     72.8425G/s     5.29583M/s    14.769k    14.769k
memcpy(Benchmark)/512/0/repeats:5_median                188 ns          188 ns            5     73.0335G/s     5.30971M/s    14.769k    14.769k
memcpy(Benchmark)/512/0/repeats:5_stddev               1.58 ns         1.57 ns            5     618.836M/s     43.9364k/s          0          0
memcpy(Benchmark)/2048/0/repeats:5_mean                2132 ns         2132 ns            5      25.241G/s     469.086k/s    57.777k    57.777k
memcpy(Benchmark)/2048/0/repeats:5_median              2129 ns         2129 ns            5      25.273G/s     469.679k/s    57.777k    57.777k
memcpy(Benchmark)/2048/0/repeats:5_stddev              4.46 ns         4.49 ns            5     54.3531M/s      986.437/s          0          0
memcpy(Benchmark)/16384/0/repeats:5_mean              21319 ns        21318 ns            5     20.0733G/s     46.9386k/s   459.185k   459.185k
memcpy(Benchmark)/16384/0/repeats:5_median            21130 ns        21127 ns            5     20.2414G/s     47.3318k/s   459.185k   459.185k
memcpy(Benchmark)/16384/0/repeats:5_stddev              612 ns          612 ns            5     571.204M/s     1.30438k/s          0          0
memcpy(Benchmark)/0/2048/repeats:5_mean                1076 ns         1076 ns            5     23.4157G/s     929.237k/s    27.057k    27.057k
memcpy(Benchmark)/0/2048/repeats:5_median              1074 ns         1074 ns            5     23.4544G/s     930.775k/s    27.057k    27.057k
memcpy(Benchmark)/0/2048/repeats:5_stddev              7.35 ns         7.32 ns            5     161.912M/s     6.27481k/s          0          0
OpenCMW/512/0/repeats:5_mean                           3120 ns         3118 ns            5     4.41172G/s     320.743k/s    14.769k     15.88k
OpenCMW/512/0/repeats:5_median                         3119 ns         3117 ns            5     4.41303G/s     320.838k/s    14.769k     15.88k
OpenCMW/512/0/repeats:5_stddev                         17.9 ns         19.4 ns            5     28.0459M/s     1.99122k/s          0          0
OpenCMW/2048/0/repeats:5_mean                          5628 ns         5626 ns            5     9.56481G/s     177.755k/s    57.777k    58.888k
OpenCMW/2048/0/repeats:5_median                        5631 ns         5630 ns            5     9.55671G/s     177.604k/s    57.777k    58.888k
OpenCMW/2048/0/repeats:5_stddev                        56.8 ns         58.5 ns            5     101.846M/s     1.84836k/s          0          0
OpenCMW/16384/0/repeats:5_mean                        53274 ns        53157 ns            5     8.04558G/s     18.8135k/s   459.185k   460.296k
OpenCMW/16384/0/repeats:5_median                      53092 ns        52972 ns            5     8.07305G/s     18.8777k/s   459.185k   460.296k
OpenCMW/16384/0/repeats:5_stddev                        536 ns          529 ns            5      81.032M/s      185.041/s          0          0
OpenCMW/0/2048/repeats:5_mean                         34405 ns        34370 ns            5     750.778M/s     29.0959k/s    27.057k    30.841k
OpenCMW/0/2048/repeats:5_median                       34373 ns        34347 ns            5     751.258M/s     29.1145k/s    27.057k    30.833k
OpenCMW/0/2048/repeats:5_stddev                         184 ns          201 ns            5     4.35976M/s       168.96/s          0    29.8245
Protobuf/512/0/repeats:5_mean                         16878 ns        16878 ns            5     834.548M/s     59.2516k/s    14.769k   12.0548k
Protobuf/512/0/repeats:5_median                       16838 ns        16837 ns            5     836.531M/s     59.3924k/s    14.769k    12.055k
Protobuf/512/0/repeats:5_stddev                        91.8 ns         91.8 ns            5     4.52382M/s      321.184/s          0    4.60435
Protobuf/2048/0/repeats:5_mean                        64817 ns        64802 ns            5     850.308M/s      15.432k/s    57.777k     47.01k
Protobuf/2048/0/repeats:5_median                      64941 ns        64940 ns            5     848.479M/s     15.3988k/s    57.777k    47.017k
Protobuf/2048/0/repeats:5_stddev                        395 ns          387 ns            5     5.11645M/s      92.8569/s          0     11.726
Protobuf/16384/0/repeats:5_mean                      554125 ns       554096 ns            5     790.342M/s     1.80479k/s   459.185k     373.1k
Protobuf/16384/0/repeats:5_median                    554399 ns       554387 ns            5     789.905M/s     1.80379k/s   459.185k   373.112k
Protobuf/16384/0/repeats:5_stddev                      3259 ns         3274 ns            5     4.66279M/s      10.6478/s          0    57.0412
Protobuf/0/2048/repeats:5_mean                       101916 ns       101743 ns            5     253.629M/s     9.82924k/s    27.057k   25.6452k
Protobuf/0/2048/repeats:5_median                     102171 ns       102168 ns            5      252.56M/s     9.78778k/s    27.057k    25.655k
Protobuf/0/2048/repeats:5_stddev                        799 ns          825 ns            5     2.06226M/s      79.9214/s          0    23.7318
Flatbuffers(object api)/512/0/repeats:5_mean           2651 ns         2651 ns            5     5.18818G/s     377.193k/s    14.769k    15.016k
Flatbuffers(object api)/512/0/repeats:5_median         2644 ns         2644 ns            5     5.20204G/s     378.201k/s    14.769k    15.016k
Flatbuffers(object api)/512/0/repeats:5_stddev         27.9 ns         27.9 ns            5     55.7801M/s      3.9603k/s          0          0
Flatbuffers(object api)/2048/0/repeats:5_mean          8932 ns         8928 ns            5     6.02749G/s     112.016k/s    57.777k    58.024k
Flatbuffers(object api)/2048/0/repeats:5_median        8909 ns         8905 ns            5     6.04233G/s     112.292k/s    57.777k    58.024k
Flatbuffers(object api)/2048/0/repeats:5_stddev        71.4 ns         67.8 ns            5     46.7717M/s      848.845/s          0          0
Flatbuffers(object api)/16384/0/repeats:5_mean       134038 ns       134029 ns            5     3.19093G/s     7.46155k/s   459.185k   459.432k
Flatbuffers(object api)/16384/0/repeats:5_median     133759 ns       133745 ns            5     3.19749G/s     7.47689k/s   459.185k   459.432k
Flatbuffers(object api)/16384/0/repeats:5_stddev       1227 ns         1227 ns            5     29.7213M/s      67.8704/s          0          0
Flatbuffers(object api)/0/2048/repeats:5_mean         66463 ns        66460 ns            5     388.264M/s     15.0469k/s    27.057k     41.08k
Flatbuffers(object api)/0/2048/repeats:5_median       66480 ns        66479 ns            5     388.145M/s     15.0423k/s    27.057k     41.08k
Flatbuffers(object api)/0/2048/repeats:5_stddev         255 ns          255 ns            5     1.49266M/s       57.847/s          0    14.9666
CapnProto/512/0/repeats:5_mean                         4752 ns         4752 ns            5     2.89489G/s     210.466k/s    14.769k    12.968k
CapnProto/512/0/repeats:5_median                       4772 ns         4770 ns            5     2.88353G/s      209.64k/s    14.769k    12.968k
CapnProto/512/0/repeats:5_stddev                       37.1 ns         37.0 ns            5     23.1448M/s     1.64324k/s          0          0
CapnProto/2048/0/repeats:5_mean                       15785 ns        15785 ns            5      3.4092G/s     63.3573k/s    57.777k    50.048k
CapnProto/2048/0/repeats:5_median                     15761 ns        15759 ns            5     3.41439G/s     63.4539k/s    57.777k    50.048k
CapnProto/2048/0/repeats:5_stddev                       152 ns          152 ns            5     33.5161M/s      608.273/s          0          0
CapnProto/16384/0/repeats:5_mean                     122410 ns       122381 ns            5     3.49441G/s     8.17121k/s   459.185k   395.904k
CapnProto/16384/0/repeats:5_median                   122367 ns       122365 ns            5     3.49486G/s     8.17226k/s   459.185k   395.904k
CapnProto/16384/0/repeats:5_stddev                      367 ns          318 ns            5     9.26932M/s       21.167/s          0          0
CapnProto/0/2048/repeats:5_mean                      104005 ns       103807 ns            5     248.582M/s     9.63362k/s    27.057k   65.7184k
CapnProto/0/2048/repeats:5_median                    104024 ns       103932 ns            5     248.274M/s     9.62168k/s    27.057k     65.72k
CapnProto/0/2048/repeats:5_stddev                       734 ns          733 ns            5     1.76216M/s      68.2912/s          0    19.9198
```
