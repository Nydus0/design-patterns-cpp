//
// Created by Nydus0 on 04/07/2025.
//

#pragma once

#include "thread_pool/pool_manager/PoolManager.hpp"

template <typename... Args> class PoolRequest {

public:
    explicit PoolRequest(PoolManager::POOL_TYPE, Args&&... a) :
    _poolType(PoolManager::POOL_TYPE::TYPE_DEFAULT),
    _args(std::forward<Args>(a)...) {}

    const std::tuple<Args...>& getArgs() const { return _args; }

private:
    PoolManager::POOL_TYPE _poolType;
    std::tuple<Args...> _args;
};

//deduction guide
template <typename... Args>
PoolRequest(PoolManager::POOL_TYPE, Args&&...) -> PoolRequest<std::decay_t<Args>...>;

