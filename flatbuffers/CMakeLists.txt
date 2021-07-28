add_library(flatc ALIAS CONAN_PKG::flatc)
flatbuffers_generate_headers(
        TARGET flatbuffers_bench_headers
        SCHEMAS TestDataClass.fbs
)
add_library(flatbuffers_bench flatbuffers_bench.cpp)
target_link_libraries(flatbuffers_bench PRIVATE CONAN_PKG::benchmark CONAN_PKG::flatbuffers flatbuffers_bench_headers)
target_include_directories(flatbuffers_bench PUBLIC ${CMAKE_CURRENT_BINARY_DIR}) # make compiled protocol buffers visible

target_link_libraries(benchmarks PRIVATE flatbuffers_bench)
