#include <iostream>

#include "object_pool/properties.hpp"
#include "object_pool/ObjectPool.hpp"
#include "thread_pool/properties.hpp"
#include "thread_pool/ThreadPool.hpp"

using namespace std;

int main() {

    std::cout << "=== test object pool ===" << std::endl;

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
    std::cout << "=== end test object pool ===\n\n" << std::endl;


    std::cout << "=== test thread pool ===" << std::endl;

    ThreadPool threadPool(10);


    std::cout << "=== end test thread pool ===\n\n" << std::endl;


    return 0;
}


