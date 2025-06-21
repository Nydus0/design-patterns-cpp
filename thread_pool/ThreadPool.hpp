//
// Created by Nydus0 on 21/06/2025.
//

#ifndef thread_pool_ThreadPool_H
#define thread_pool_ThreadPool_H

#include <condition_variable>
#include <mutex>
#include <thread>
#include <vector>

class ThreadPool {
public:
    explicit ThreadPool(size_t nbThreads);

private:
    size_t NB_THREADS{};
    std::vector<std::thread> _pool;
    std::condition_variable cv;
    std::mutex guard;
};



#endif
