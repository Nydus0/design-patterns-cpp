//
// Created by Nydus0 on 21/06/2025.
//

#pragma once

#include <condition_variable>
#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <thread>

class ThreadPool {
public:
    explicit ThreadPool(size_t nbWorkers);
    ~ThreadPool();

    template<typename F, typename... Args>
    auto enqueue(F &&f, Args &&... args) -> std::future<typename std::invoke_result<F, Args...>::type>;

private:
    void workerLoop();

    size_t NB_THREADS{};
    std::atomic_bool _stop {false};
    std::vector<std::thread> _workers;
    std::queue<std::function<void()>> _tasks;
    std::condition_variable _queue_condition;
    std::mutex _queue_mutex;
};

template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args)
    -> std::future<std::invoke_result_t<F, Args...>> {

    using return_type = std::invoke_result_t<F, Args...>;

    auto task = std::make_shared<std::packaged_task<return_type()>>(
        std::bind(std::forward<F>(f), std::forward<Args>(args)...)
    );
    std::future<return_type> res = task->get_future();

    {
        std::unique_lock lock(_queue_mutex);
        if (_stop) { throw std::runtime_error("enqueue on stopped ThreadPool"); }

        _tasks.emplace([task]() { (*task)(); });
    }

    _queue_condition.notify_one();
    return res;
}
