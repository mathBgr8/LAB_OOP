#include <gtest/gtest.h>
#include "../include/money.h"

TEST(MoneyTest, DefaultConstructor) {
    Money t;
    ASSERT_EQ(t.get_size(), 0);
    ASSERT_EQ(t.get_array(), nullptr);
}

TEST(MoneyTest, FillConstructor) {
    Money t(10, '5', true);
    ASSERT_EQ(t.get_size(), 10 + 1);
    unsigned char* _array = t.get_array();

    for(int i = 1; i < t.get_size(); ++i) {
        ASSERT_EQ(_array[i], '5');
    }
}

TEST(MoneyTest, InitializerListConstructor) {
    Money t = {'1', '2', '3', '4', '5'};
    ASSERT_EQ(t.get_size(), 5 + 1);
    unsigned char* _array = t.get_array();
    for(int i = 0; i < t.get_size(); ++i) {
        ASSERT_EQ(_array[i], (i + '0'));
    }
}

TEST(MoneyTest, StringConstructor) {
    Money t("-123");
    ASSERT_EQ(t.get_size(), 3 + 1);
    ASSERT_TRUE(!t.is_positive());
    std::string _array = t.get_string_array();
    for(int i = 0; i < t.get_size(); ++i) {
        ASSERT_EQ(_array[i], (i + '0'));
    }
}

TEST(MoneyTest, equal1) {
    Money a("-0100");
    Money b("-100");
    
    ASSERT_TRUE(a.equal(b));
}
TEST(MoneyTest, equal2) {
    Money a("100");
    Money b("-100");
    
    ASSERT_TRUE(!a.equal(b));
}
TEST(MoneyTest, equal3) {
    Money a("-0");
    Money b("0");
    
    ASSERT_TRUE(a.equal(b));
}
TEST(MoneyTest, equal4) {
    Money a("100");
    Money b("100");
    
    ASSERT_TRUE(a.equal(b));
}
TEST(MoneyTest, greater1) {
    Money a("2");
    Money b("3");
    
    ASSERT_TRUE(!a.greater(b));
}
TEST(MoneyTest, greater3) {
    Money a("100");
    Money b("900");
    
    ASSERT_TRUE(!a.greater(b));
}
TEST(MoneyTest, greater2) {
    Money a("0100");
    Money b("10");
    
    ASSERT_TRUE(a.greater(b));
}

TEST(MoneyTest, greater4) {
    Money a("1001");
    Money b("-10");
    
    ASSERT_TRUE(a.greater(b));
}

TEST(MoneyTest, greater5) {
    Money a("-1");
    Money b("-10");
    
    ASSERT_TRUE(a.greater(b));
}

TEST(MoneyTest, sum) {
    Money a("100");
    Money b("100");
    Money c("200");

    Money res = a.add(b);
    ASSERT_TRUE(res.equal(c));
}

TEST(MoneyTest, sum1) {
    Money a("-100");
    Money b("100");
    Money c("0");

    Money res = a.add(b);
    ASSERT_TRUE(res.equal(c));
}

TEST(MoneyTest, sum2) {
    Money a("100");
    Money b("-100");
    Money c("0");

    Money res = a.add(b);
    ASSERT_TRUE(res.equal(c));
}

TEST(MoneyTest, sum5) {
    Money a("-100");
    Money b("-100");
    Money c("-200");

    Money res = a.add(b);
    ASSERT_TRUE(res.equal(c));
}

TEST(MoneyTest, sum3) {
    Money a("0");
    Money b("0");
    Money c("0");

    Money res = a.add(b);
    ASSERT_TRUE(res.equal(c));
}

TEST(MoneyTest, sum4) {
    Money a("100");
    Money b("900");
    Money c("1000");

    Money res = a.add(b);
    ASSERT_TRUE(res.equal(c));
}

TEST(MoneyTest, sum6) {
    Money a("0");
    Money b("-10");
    Money c("-10");

    Money res = a.add(b);
    ASSERT_TRUE(res.equal(c));
}

TEST(MoneyTest, sum7) {
    Money a;
    Money b;
    Money c;

    Money res = a.add(b);
    ASSERT_TRUE(res.equal(c));
}


TEST(MoneyTest, sum8) {
    Money a("10");
    Money b;
    Money c("10");

    Money res = a.add(b);
    ASSERT_TRUE(res.equal(c));
}

TEST(MoneyTest, subs1) {
    Money a("100");
    Money b("900");
    Money c("-800");

    Money res = a.substract(b);
    ASSERT_TRUE(res.equal(c));
}

TEST(MoneyTest, subs2) {
    Money a("-100");
    Money b("900");
    Money c("-1000");

    Money res = a.substract(b);
    ASSERT_TRUE(res.equal(c));
}
TEST(MoneyTest, subs3) {
    Money a("-100");
    Money b("-900");
    Money c("800");

    Money res = a.substract(b);
    ASSERT_TRUE(res.equal(c));
}
TEST(MoneyTest, subs4) {
    Money a("0");
    Money b("-900");
    Money c("900");

    Money res = a.substract(b);
    ASSERT_TRUE(res.equal(c));
}
TEST(MoneyTest, subs5) {
    Money a("0");
    Money b("900");
    Money c("-900");

    Money res = a.substract(b);
    ASSERT_TRUE(res.equal(c));
}

TEST(MoneyTest, subs6) {
    Money a;
    Money b("900");
    Money c("-900");

    Money res = a.substract(b);
    ASSERT_TRUE(res.equal(c));
}

TEST(MoneyTest, subs7) {
    Money a("100");
    Money b;
    Money c("100");

    Money res = a.substract(b);
    ASSERT_TRUE(res.equal(c));
}

TEST(MoneyTest, allowed_input) {
    std::string s = "-1fsdafdsjfhdslfds432432432";
    EXPECT_THROW(Money a(s), std::logic_error);
}

TEST(MoneyTest, Destructor) {
    Money a("-10101010010101");

    EXPECT_DEATH(delete &a, "");
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
