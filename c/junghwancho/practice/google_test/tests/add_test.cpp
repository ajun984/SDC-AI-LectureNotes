#include <gtest/gtest.h>
#include "../simple/add.h"

TEST(AddTest, onePlusTwoGivesThree)
{
    EXPECT_EQ(3, add(1, 2));
}

TEST(add_test, okGotIt)
{
    EXPECT_EQ(3, add(1, 2));
}