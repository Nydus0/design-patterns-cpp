 //
// Created by Nydus0 on 04/07/2025.
//

#pragma once

#include "thread_pool/ThreadPool.hpp"

#include <map>

 class PoolManager {
 public:
  enum class POOL_TYPE {
   TYPE_1,
   TYPE_2,
   TYPE_3,
   TYPE_4,
   TYPE_DEFAULT
  };


 private:
  std::map<POOL_TYPE, ThreadPool *> _pools;
 };
