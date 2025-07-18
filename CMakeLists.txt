cmake_minimum_required(VERSION 3.31)
project(design_patterns_cpp)

set(CMAKE_CXX_STANDARD 26)

# install Gtest dependency
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/7e17b15f1547bb8dd9c2fed91043b7af3437387f.zip
)

# for windows: prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(tests

        ## tests ##
        tests/main.cpp

        ## modules ##

        #auto singleton
        modules/auto_singleton/properties.cpp

        #object pool
        modules/object_pool/properties.cpp

        #thread pool
        modules/thread_pool/pool_manager/PoolManager.cpp
        modules/thread_pool/pool_manager/PoolRequest.cpp
        modules/thread_pool/pool_manager/Arguments.cpp
        modules/thread_pool/properties.cpp
        modules/thread_pool/ThreadPool.cpp

)

target_include_directories(tests
        PRIVATE
        ${CMAKE_SOURCE_DIR}
)

