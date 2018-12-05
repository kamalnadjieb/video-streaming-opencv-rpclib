cmake_minimum_required(VERSION 3.9)
project(OpenCV_RPC)

find_package(OpenCV REQUIRED)
find_package(rpclib REQUIRED)
find_package(Threads REQUIRED)

add_executable(server server.cpp)
target_compile_features(server PRIVATE cxx_auto_type)
target_compile_options(server PRIVATE $<$<CXX_COMPILER_ID:GNU>:-Wall>)
target_link_libraries(server ${OpenCV_LIBS} rpclib::rpc  ${CMAKE_THREAD_LIBS_INIT})

add_executable(client client.cpp)
target_compile_features(client PRIVATE cxx_auto_type)
target_compile_options(client PRIVATE $<$<CXX_COMPILER_ID:GNU>:-Wall>)
target_link_libraries(client ${OpenCV_LIBS} rpclib::rpc  ${CMAKE_THREAD_LIBS_INIT})
