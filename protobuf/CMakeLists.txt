protobuf_generate_cpp(ProtoSources ProtoHeaders TestDataClass.proto)
add_executable(protobuf_bench protobuf_bench.cpp ${ProtoSources} ${ProtoHeaders})
target_link_libraries(protobuf_bench PRIVATE CONAN_PKG::benchmark CONAN_PKG::protobuf)
target_include_directories(protobuf_bench PUBLIC ${CMAKE_CURRENT_BINARY_DIR}) # make compiled protocol buffers visible
