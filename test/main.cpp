#include <iostream>

#include "object_pool/properties.hpp"
#include "object_pool/ObjectPool.hpp"

#include "thread_pool/properties.hpp"
#include "thread_pool/ThreadPool.hpp"
#include "thread_pool/pool_manager/PoolManager.hpp"
#include "thread_pool/pool_manager/PoolRequest.hpp"

using namespace std;

int main() {

    /*std::cout << "=== test object pool ===" << std::endl;

    size_t poolSize = 100;
    ObjectPool<string, LargeObject> objectPool(poolSize);

    cout << " acquire object1 from pool " << endl;
    LargeObject* obj1 = objectPool.acquire("obj1");
    cout << " acquire object2 from pool " << endl;
    LargeObject* obj2 = objectPool.acquire("obj2");
    cout << " set object2 name attribute " << endl;
    obj2->setName("obj2");
    cout << " release object1 in pool " << endl;
    objectPool.release(obj1->name());
    cout << " object1 has been released " << endl;

    cout << " object2 in pool with name " << objectPool.get(obj2->name())->name() << endl;
    std::cout << "=== end test object pool ===\n\n" << std::endl;*/


    std::cout << "=== test thread pool ===" << std::endl;

    /*
    ThreadPool threadPool(4);

    auto f1 = threadPool.enqueue(print_sum, 3, 4);
    auto f2 = threadPool.enqueue(greet, "Coco");
    auto f3 = threadPool.enqueue([](int x) {
        return "lambda called with " + to_string(x) ;
    }, 42);
    auto f4 = threadPool.enqueue([]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    });

    std::cout << "all tasks complete - thread pool ready for destruction " << "\n";

    std::cout << "Result of task 1: " << f1.get() << "\n";
    std::cout << "Result of task 2: " << f2.get() << "\n";
    std::cout << "Result of task 3: " << f3.get() << "\n";
    std::cout << "cannot print result of task 4 as returns void " << "\n";
    */


    ThreadPool pool(4);

    PoolManager manager;

    // Create the argument holder
    Arguments args;
    args.add(3);
    args.add(5);

    // Package them in a request
    const PoolRequest request(PoolRequest::POOL_TYPE::COMPUTE, args);

    // Submit the function and get the result
    auto future = manager.submit(request, add);

    std::cout << "Result: " << future.get() << std::endl;

    std::cout << "=== end test thread pool ===" << std::endl;
    return 0;
}


