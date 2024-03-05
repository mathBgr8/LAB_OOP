#include <gtest/gtest.h>
#include "../src/box_cap.h"

int box_size = 16;

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(box_capacity(32, 64, 16, box_size) == 13824);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(box_capacity(32768, 1, 1, box_size) == 0);
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(box_capacity(6, 10, 11, box_size) == 224);
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(box_capacity(0, 0, 0, box_size) == 0);
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(box_capacity(2, 2, 2, box_size) == 1);
}

TEST(test_06, basic_test_set)
{
    ASSERT_TRUE(box_capacity(1700, 1700, 1700, box_size) == 2072671875);
}

TEST(test_07, basic_test_set)
{
    EXPECT_THROW(box_capacity(-10, -11, -14, box_size), std::logic_error);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
