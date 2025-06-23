//
// Created by Nydus0 on 21/06/2025.
//

#include "thread_pool/ThreadPool.hpp"


ThreadPool::ThreadPool(size_t nbThreads) : NB_THREADS(std::thread::hardware_concurrency()), _stop(false) {
    for (size_t i = 0; i < nbThreads; i++) {
        _workers.emplace_back([this]() { this->workerLoop(); });
    }
}

ThreadPool::~ThreadPool() {
    _stop = true;
    _queue_condition.notify_all();
    for (auto &worker: _workers) { worker.join(); }
}

void ThreadPool::workerLoop() {
    while (true) {
        std::function<void()> task;
        {
            std::unique_lock lock(_queue_mutex);
            _queue_condition.wait(lock, [this]() { return _stop || !_tasks.empty(); });
            if (_stop && _tasks.empty()) { return; }

            task = std::move(_tasks.front());
            _tasks.pop();
        }

        //run task
        task();
    }
}