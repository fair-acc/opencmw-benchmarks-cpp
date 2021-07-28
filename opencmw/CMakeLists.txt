add_executable(opencmw_bench opencmw_bench.cpp)
target_link_libraries(opencmw_bench PRIVATE CONAN_PKG::benchmark CONAN_PKG::opencmw project_options)
