add_library(opencmw_bench OBJECT opencmw_bench.cpp)
target_link_libraries(
  opencmw_bench
  PUBLIC CONAN_PKG::benchmark
         CONAN_PKG::opencmw
         project_options
         project_warnings)

target_link_libraries(bench PRIVATE opencmw_bench)
