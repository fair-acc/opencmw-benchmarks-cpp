capnp_generate_cpp(ProtoSources ProtoHeaders TestDataClass.capnp)
add_library(capnproto_bench OBJECT capnproto_bench.cpp ${ProtoSources} ${ProtoHeaders})
target_link_libraries(capnproto_bench PRIVATE CONAN_PKG::benchmark CONAN_PKG::capnproto project_options project_warnings)
target_include_directories(capnproto_bench PUBLIC ${CMAKE_CURRENT_BINARY_DIR}) # make compiled protocol buffers visible

target_link_libraries(bench PRIVATE capnproto_bench)
