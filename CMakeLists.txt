cmake_minimum_required(VERSION 3.15)

project(opencmw-benchmark CXX)
include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_20)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
  option(ENABLE_BUILD_WITH_TIME_TRACE "Enable -ftime-trace to generate time tracing .json files on clang" OFF)
  if(ENABLE_BUILD_WITH_TIME_TRACE)
    target_compile_options(project_options INTERFACE -ftime-trace)
  endif()
endif()

# enable cache system
include(cmake/Cache.cmake)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)
# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

include(cmake/Conan.cmake)
run_conan()

add_executable(bench  src/bench.cpp)
target_link_libraries(bench PRIVATE CONAN_PKG::benchmark)

add_subdirectory(src/memcpy)
add_subdirectory(src/opencmw)
add_subdirectory(src/protobuf)
add_subdirectory(src/flatbuffers)
add_subdirectory(src/capnproto)
