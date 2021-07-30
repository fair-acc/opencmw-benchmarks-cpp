#add_executable(memcpy_bench memcpy_bench.cpp)
add_library(memcpy_bench OBJECT memcpy_bench.cpp)
target_link_libraries(memcpy_bench PUBLIC CONAN_PKG::benchmark project_options project_warnings)

target_link_libraries(bench PRIVATE memcpy_bench)
