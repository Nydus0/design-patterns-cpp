# design-patterns-cpp

Describes several implementations of c++ patterns with specific custom features.

Auto-singleton:
- singleton class in modern c++ style
- provides an optional manual deletion of the singleton class 

Object pool:
- fast pool element access by key
- RAII with unique_ptr
- concept guard for pool elements (elements must have a reset() function)

Thread pool:
- pool manager assigns pool requests to threadpools, depending on pool type
- thread pool receives functions and arguments separately and binds them to execute its task

