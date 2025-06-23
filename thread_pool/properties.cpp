//
// Created by Nydus0 on 21/06/2025.
//
#include "thread_pool/properties.hpp"

#include <iostream>

int print_sum(int a, int b) {
    return a + b;
}

std::string greet(const std::string& name) {
    return "Hello, " + name;
}