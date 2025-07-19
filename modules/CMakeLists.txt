add_library(lib_modules STATIC
        #thread_pool
        thread_pool/pool_manager/PoolManager.cpp
        thread_pool/pool_manager/PoolRequest.cpp
        thread_pool/pool_manager/Arguments.cpp
        thread_pool/ThreadPool.cpp)