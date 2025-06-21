//
// Created by Nydus0 on 21/06/2025.
//

#include "thread_pool/ThreadPool.hpp"

#include <thread>

ThreadPool::ThreadPool(size_t nbThreads) : NB_THREADS(std::thread::hardware_concurrency()) {

    /*for (int i =0; i < nbThreads; i++) {
        _pool.emplace_back();
    }*/
}

