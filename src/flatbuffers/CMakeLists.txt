add_library(flatc ALIAS CONAN_PKG::flatc)
# auto generating the flatbuffers headers is disabled because it didn't work with the conan binary. just uncomment all the comments and see if it works.
# flatbuffers_generate_headers(
#         TARGET flatbuffers_bench_headers
#         SCHEMAS TestDataClass.fbs
# )
add_library(flatbuffers_bench OBJECT flatbuffers_bench.cpp)
target_link_libraries(flatbuffers_bench PRIVATE CONAN_PKG::benchmark CONAN_PKG::flatbuffers CONAN_PKG::opencmw project_options project_warnings) # flatbuffers_bench_headers)
# target_include_directories(flatbuffers_bench PUBLIC ${CMAKE_CURRENT_BINARY_DIR}) # make compiled protocol buffers visible

target_link_libraries(bench PRIVATE flatbuffers_bench)
