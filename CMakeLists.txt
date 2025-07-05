cmake_minimum_required(VERSION 3.31)
project(design_patterns_cpp)

set(CMAKE_CXX_STANDARD 26)

add_executable(test

        test/main.cpp

        object_pool/properties.cpp
        thread_pool/ThreadPool.cpp
        thread_pool/properties.cpp
        thread_pool/pool_manager/PoolManager.cpp
        thread_pool/pool_manager/PoolRequest.cpp
)

target_include_directories(test
        PRIVATE
        ${CMAKE_SOURCE_DIR}
)

