#include <gtest/gtest.h>

import mcpplibs.mylib;

TEST(MyLibTest, HelloMcpplibs) {
    EXPECT_EQ(mcpplibs::mylib::hello_mcpplibs(), "hello mcpplibs");
}
