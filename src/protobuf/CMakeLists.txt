protobuf_generate_cpp(ProtoSources ProtoHeaders TestDataClass.proto)
add_library(protobuf_bench OBJECT protobuf_bench.cpp ${ProtoSources} ${ProtoHeaders})
target_link_libraries(protobuf_bench PRIVATE CONAN_PKG::benchmark CONAN_PKG::protobuf project_options) # no warnings because protobuf generated headers have useless casts
target_include_directories(protobuf_bench PUBLIC ${CMAKE_CURRENT_BINARY_DIR}) # make compiled protocol buffers visible

target_link_libraries(bench PRIVATE protobuf_bench)
