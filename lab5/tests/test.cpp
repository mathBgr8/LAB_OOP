#include <gtest/gtest.h>
#include <string>
#include <memory>
#include "../include/DynamicArray.hpp"
#include "../include/Allocator.hpp"


TEST(Iter, Test1) {
    DynamicArray<int, Allocator<int, 15>> myvec(10);
    auto it = myvec.end();

    EXPECT_ANY_THROW(*it = 10);
}


TEST(Iter, Test2) {
    DynamicArray<int, Allocator<int, 15>> myvec(10);
    DynamicArray<int, Allocator<int, 15>> myvec1(10);
    auto it = myvec.cend();
    auto it1 = myvec1.cbegin();

    EXPECT_TRUE(it != it1);
}


TEST(Iter, Test3) {
    DynamicArray<int, Allocator<int, 15>> myvec(10);
    auto it = myvec.cend();
    auto it1 = myvec.cbegin();

    EXPECT_FALSE(it != it1);
}


TEST(Iter, Test4) {
    DynamicArray<int, Allocator<int, 15>> myvec(10);
    auto it = myvec.cend();

    EXPECT_ANY_THROW(*it);
}


TEST(Iter, Test5) {
    DynamicArray<int, Allocator<int, 15>> myvec(10);
    for(size_t i{0}; i < 10; ++i) {
        myvec.push_back(10);
    }

    auto it = myvec.begin();
    *it = -10;
    EXPECT_EQ(myvec[0], -10);
}


TEST(Iter, Test6) {
    DynamicArray<int, Allocator<int, 15>> myvec(10);
    for(size_t i{0}; i < 10; ++i) {
        myvec.push_back(10);
    }

    auto it = myvec.begin();
    ++it;
    *it = -10;
    EXPECT_EQ(myvec[1], -10);
}


TEST(Iter, Test7) {
    DynamicArray<int, Allocator<int, 15>> myvec(10);
    for(size_t i{0}; i < 10; ++i) {
        myvec.push_back(i);
    }

    testing::internal::CaptureStdout();
    for(auto it = myvec.cbegin(); it != myvec.cend(); ++it) {
        std::cout << *it << ' ';
    }
    std::string output = testing::internal::GetCapturedStdout();

    std::string res = "0 1 2 3 4 5 6 7 8 9 ";

    EXPECT_EQ(res, output);
}


TEST(Alloc, Test1) {
    EXPECT_THROW((DynamicArray<int, Allocator<int, 15>>)(20), std::bad_alloc);
}


TEST(Alloc, Test2) {
    DynamicArray<int, Allocator<int, 15>> a(10);
    for(int i = 0; i < 15; ++i) {
        a.push_back(i);
    }

    EXPECT_THROW(a.push_back(100), std::bad_alloc);
}


TEST(Alloc, Test3) {
    DynamicArray<int, Allocator<int, 15>> a(10);
    for(int i = 0; i < 15; ++i) {
        a.push_back(i);
    }

    EXPECT_THROW(a.push_back(100), std::bad_alloc);
}

TEST(DynamicArray, Test1) {
    EXPECT_THROW((DynamicArray<int, Allocator<int, 5>>){}, std::bad_alloc);
}

TEST(DynamicArray, Test2) {
    DynamicArray<int, Allocator<int, 15>> arr;
    for(int i = 0; i < 15; ++i) {
        arr.push_back(i);
    }

    arr[12] = -100;
    EXPECT_EQ(arr[12], -100);
}

TEST(DynamicArray, Test3) {
    DynamicArray<int, Allocator<int, 15>> arr;
    for(int i = 0; i < 15; ++i) {
        arr.push_back(i);
    }

    EXPECT_ANY_THROW(arr[16] = -100);
}

TEST(DynamicArray, Test4) {
    DynamicArray<int, Allocator<int, 15>> arr;
    for(int i = 0; i < 15; ++i) {
        arr.push_back(i);
    }

    EXPECT_ANY_THROW(arr[16] = -100);
}

TEST(DynamicArray, Test5) {
    DynamicArray<int, Allocator<int, 15>> arr;
    for(int i = 0; i < 15; ++i) {
        arr.push_back(i);
    }

    EXPECT_THROW(arr.push_back(321), std::bad_alloc);
}

TEST(DynamicArray, Test6) {
    DynamicArray<int, Allocator<int, 15>> arr;
    EXPECT_THROW(arr.pop_back(), OutOfBoundException);
}

TEST(DynamicArray, Test7) {
    DynamicArray<int, Allocator<int, 15>> arr;
    for(int i = 0; i < 15; ++i) {
        arr.push_back(i);
    }

    EXPECT_THROW(arr.set_element(321, 321), OutOfBoundException);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
