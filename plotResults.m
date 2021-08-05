#! /usr/bin/env octave

results = csvread("results.csv");
rep = 3; # number of repetitions
aggregates = 3; # mean, median, stdev
start = 12; # first line containing data
dataColumn = 11;

speeds = reshape(results([start + rep:rep+aggregates:end], dataColumn), 8, [])./1e6;
errors = reshape(results([start + rep + 2:rep+aggregates:end], dataColumn), 8, [])./1e6;

clf;
hold on;
h = bar(speeds);
#set (gca, "yscale", "log");
set (gca, "fontsize", 20);
legend("memcpy", "opencmw", "protobuf", "flatbuffers (object api)", "capnproto")
xlabel("Message contents: number of primitves, strings and recursive objects")
ylabel("DataRate [MB/s]")
xticks([1,2,3,4,5,6,7,8])
xticklabels({
    "10000,  0, 0",
    "   10,100, 1",
    "  256,  0, 0",
    "  512,  0, 0",
    " 1024,  0, 0",
    " 2048,  0, 0",
    " 4096,  0, 0",
    " 8192,  0, 0"
})
errorbar(speeds, errors, "."); # plots all errorbars centrally :(

pause