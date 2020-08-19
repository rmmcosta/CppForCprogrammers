#include "mysum.hpp"
#include <gtest/gtest.h>

TEST(FirstTest, Test0)
{
    ASSERT_EQ(4, sum(2, 2));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}