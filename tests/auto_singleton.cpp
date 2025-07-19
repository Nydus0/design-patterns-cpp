//
// Created by Nydus0 on 19/07/2025.
//

#include <gtest/gtest.h>

#include "modules/auto_singleton/AutoSingleton.hpp"
#include "modules/auto_singleton/properties.hpp"

TEST(auto_singleton, create) {

    EXPECT_NO_THROW({
        auto& service = AutoSingleton<MyService>::get();
        service.run();
    });
}

TEST(auto_singleton, destroy) {
    auto& service = AutoSingleton<MyService>::get();

    EXPECT_NO_THROW({
        //optional: manually destroy early
        AutoSingleton<MyService>::destroy();
    });
}
