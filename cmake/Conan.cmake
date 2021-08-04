macro(run_conan)
  # Download automatically, you can also just copy the conan.cmake file
  if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.16.1/conan.cmake" "${CMAKE_BINARY_DIR}/conan.cmake")
  endif()

  set(ENV{CONAN_REVISIONS_ENABLED} 1) # required for new bincrafters repository
  include(${CMAKE_BINARY_DIR}/conan.cmake)

  conan_add_remote(
    NAME
    bincrafters
    URL
    https://bincrafters.jfrog.io/artifactory/api/conan/public-conan)

  conan_cmake_run(
    REQUIRES
    ${CONAN_EXTRA_REQUIRES}
    catch2/2.13.3
    fmt/7.1.3
    mp-units/0.7.0
    protobuf/3.17.1
    capnproto/0.8.0
    opencmw/0.0.1
    flatbuffers/2.0.0
    flatc/1.12.0 # outputs deprecation warning, but should still be used for flatc:
                 # https://github.com/conan-io/conan-center-index/issues/4039
    # disabled because on nixOS system flatc has to be used
    benchmark/1.5.3
    # refl-cpp/0.12.1 # could be used once there is a new release
    OPTIONS
    ${CONAN_EXTRA_OPTIONS}
    BASIC_SETUP
    CMAKE_TARGETS # individual targets to link to
    BUILD
    missing)
endmacro()
