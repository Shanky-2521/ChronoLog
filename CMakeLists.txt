cmake_minimum_required(VERSION 3.16)
project(ChronoLog VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Find required packages
find_package(Threads REQUIRED)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

# Main library
add_library(chronolog_lib ${SOURCES} ${HEADERS})

# Test executables
add_executable(test_memtable tests/test_memtable.cpp)
target_link_libraries(test_memtable chronolog_lib Threads::Threads)

add_executable(test_raft tests/test_raft_basic.cpp)
target_link_libraries(test_raft chronolog_lib Threads::Threads)

add_executable(test_storage_node tests/test_storage_node.cpp)
target_link_libraries(test_storage_node chronolog_lib Threads::Threads)

add_executable(test_distributed_cluster tests/test_distributed_cluster.cpp)
target_link_libraries(test_distributed_cluster chronolog_lib Threads::Threads)

# Demo executables
add_executable(chronolog_demo examples/demo.cpp)
target_link_libraries(chronolog_demo chronolog_lib Threads::Threads)

add_executable(raft_demo examples/raft_demo.cpp)
target_link_libraries(raft_demo chronolog_lib Threads::Threads)

add_executable(storage_node_demo examples/storage_node_demo.cpp)
target_link_libraries(storage_node_demo chronolog_lib Threads::Threads)

add_executable(chronolog_cli examples/chronolog_cli.cpp)
target_link_libraries(chronolog_cli chronolog_lib Threads::Threads)

add_executable(cluster_demo examples/cluster_demo.cpp)
target_link_libraries(cluster_demo chronolog_lib Threads::Threads)

# Testing
enable_testing()
add_test(NAME memtable_tests COMMAND test_memtable)
add_test(NAME raft_tests COMMAND test_raft)
add_test(NAME storage_node_tests COMMAND test_storage_node)
add_test(NAME distributed_cluster_tests COMMAND test_distributed_cluster)

# Installation
install(TARGETS chronolog_lib DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
