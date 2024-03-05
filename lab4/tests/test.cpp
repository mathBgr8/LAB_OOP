#include <gtest/gtest.h>
#include "../include/figure.hpp"
#include "../include/rectangle.hpp"
#include "../include/trapezoid.hpp"
#include "../include/rhombus.hpp"
#include "../include/point.hpp"
#include <string>
#include <memory>

TEST(FigureTest, Point1) {
    Point<double> a;
    Point<double> b(1, 2);

    ASSERT_TRUE((a + b) == b);
}

TEST(FigureTest, Point2) {
    Point a(3, 4);
    ASSERT_EQ(a.vector_length() , 5);
}

TEST(FigureTest, Point3) {
    Point a(-1, 2);
    Point b(3, 4);

    ASSERT_EQ(a * b, 5);
}

TEST(FigureTest, Rectangle1) {
    Rectangle<double> a(0, 0, 0, 1, 1, 1, 1, 0);
    Point<double> b(.5, .5);
    ASSERT_EQ(a.center(), b);
    ASSERT_EQ(a.square(), 1);
}

TEST(FigureTest, Rectangle2) {
    Point<double> a = {1, 1};
    Point<double> b = {1, 0};
    Point<double> c = {0, 1};
    Point<double> d = {0, 0};
    Rectangle<double> y(a, b, d, c);
    Point<double> g(.5, .5);

    ASSERT_EQ(y.center(), g);
    ASSERT_EQ(y.square(), 1);
}

TEST(FigureTest, Rectangle3) {
    Rectangle<int> a(0, 0, 0, 1, 1, 1, 1, 0);
    Rectangle<int> b(0, 0, 0, 1, 1, 1, 1, 0);

    ASSERT_TRUE(a == b);
}

TEST(FigureTest, Rectangle4) {
    Rectangle<double> a(0, 0, 0, 1, 1, 1, 1, 0);
    Rectangle<double> b;
    b = a;

    ASSERT_TRUE(a == b);
}

TEST(FigureTest, Rectangle5) {
    EXPECT_THROW(Rectangle<int> a(1, 1, 0, 0, 0, 0, 1, 1), std::logic_error);
}

TEST(FigureTest, Rectangle6) {
    Point a(1, 1);
    EXPECT_THROW(Rectangle f(a, a, a, a), std::logic_error);
}

TEST(FigureTest, Rectangle7) {
    EXPECT_THROW(Rectangle<int> f(1, 1, 1, 1, 1, 1, 1, 1), std::logic_error);
}

TEST(FigureTest, Rectangle8) {
    Rectangle<int> a(0, 0, 0, 1, 1, 1, 1, 0);
    double c = a;
    ASSERT_TRUE(c == 1);
}

TEST(FigureTest, Rectangle9) {
    Rectangle<int> a(0, 0, 0, 1, 1, 1, 1, 0);
    Rectangle<int> b;
    b = a;
    double c = b;
    ASSERT_EQ(b, 1);
}

TEST(FigureTest, Rectangle10) {
    Rectangle<int> a(0, 0, 0, 1, 1, 1, 1, 0);
    Rectangle<int> b;
    a = b;
    double c = a;
    ASSERT_EQ(a, 0);
}

TEST(FigureTest, Rectangle11) {
    Rectangle<int> a;
    Rectangle<int> b;
    a = b;

    ASSERT_TRUE(a == b);
}

TEST(FigureTest, Rhombus1) {
    Rhombus<int> a(0, 0, 1, 1, 0, 2, -1, 1);
    Point center(0, 1);

    ASSERT_TRUE(center == a.center());
    ASSERT_TRUE(a.square() == 2);
}

TEST(FigureTest, Rhombus2) {
    EXPECT_THROW(Rhombus<int> a(1, 1, 0, 0, 0, 2, -1, 1), std::logic_error);
}

TEST(FigureTest, Rhombus3) {
    Rhombus<int> a(0, 0, 1, 1, 0, 2, -1, 1);
    Rhombus<double> b(0, 0, 1, 1, 0, 2, -1, 1);
    ASSERT_TRUE(a == b);
}

TEST(FigureTest, Rhombus3equal2) {
    Rhombus<int> a(0, 0, 1, 1, 0, 2, -1, 1);
    Rhombus<int> b(1, 1, 0, 2, -1, 1, 0, 0);
    ASSERT_TRUE(a == b);
}

TEST(FigureTest, Rhombus4) {
    Rhombus<int> a(0, 0, 1, 1, 0, 2, -1, 1);
    Rhombus<int> b;

    ASSERT_FALSE(a == b);
}

TEST(FigureTest, Rhombus5) {
    Rhombus<int> a(0, 0, 1, 1, 0, 2, -1, 1);
    Rhombus<int> b = a;

    ASSERT_TRUE(a == b);
}

TEST(FigureTest, Rhombus6) {
    EXPECT_THROW(Rhombus<int> a(1, 2, 0, -5, 1, 1, -1, 1), std::logic_error);
}

TEST(FigureTest, Rhombus7) {
    Point a(9, 9);
    EXPECT_THROW(Rhombus f(a, a, a, a), std::logic_error);
}

TEST(FigureTest, Rhombus8) {
    Rhombus<int> a(0, 0, 1, 1, 0, 2, -1, 1);
    double b = a;

    ASSERT_EQ(b, 2);
}

TEST(FigureTest, Rhombus9) {
    Rhombus<int> a(0, 0, 1, 1, 0, 2, -1, 1);
    Rhombus<int> b;
    b = a;
    double c = b;
    ASSERT_EQ(b, 2);
}

TEST(FigureTest, Rhombus10) {
    Rhombus<int> a(0, 0, 1, 1, 0, 2, -1, 1);
    Rhombus<int> b;
    a = b;
    double c = a;
    ASSERT_EQ(a, 0);
}

TEST(FigureTest, Rhombus11) {
    Rhombus<int> a;
    Rhombus<int> b;
    a = b;

    ASSERT_TRUE(a == b);
}

TEST(FigureTest, Trapezoid1) {
    EXPECT_THROW(Trapezoid a(0, 0, 3, 0, 1, 2, 2, 2), std::logic_error);
}

TEST(FigureTest, Trapezoid2) {
    Trapezoid a(0, 0, 3, 0, 2, 2, 1, 2);
    Trapezoid b(0, 0, 3, 0, 2, 2, 1, 2);

    ASSERT_TRUE(a == b);
}

TEST(FigureTest, Trapezoid3) {
    Trapezoid a(0, 0, 3, 0, 2, 2, 1, 2);
    Trapezoid b = a;

    ASSERT_TRUE(a == b);
}

TEST(FigureTest, Trapezoid4) {
    EXPECT_THROW(Trapezoid a(0, 0, 1, 3, 0, 2, 1, -1), std::logic_error);
}

TEST(FigureTest, Trapezoid5) {
    Point f(1, 1);
    EXPECT_THROW(Trapezoid a(f, f, f, f), std::logic_error);
}

TEST(FigureTest, Trapezoid6) {
    Trapezoid a(0, 0, 3, 0, 2, 2, 1, 2);
    double c = a;
    ASSERT_EQ(c, 4);
}

TEST(FigureTest, Trapezoid7) {
    Trapezoid a(0, 0, 3, 0, 2, 2, 1, 2);
    Trapezoid<int> b;
    b = a;
    double c = b;
    ASSERT_EQ(b, 4);
}

TEST(FigureTest, Trapezoid8) {
    Trapezoid a(0, 0, 3, 0, 2, 2, 1, 2);
    Trapezoid<int> b;
    a = b;
    double c = a;
    ASSERT_EQ(a, 0);
}

TEST(FigureTest, Trapezoid9) {
    Trapezoid<int> a;
    Trapezoid<int> b;
    a = b;

    ASSERT_TRUE(a == b);
}

TEST(FigureTest, EmptyClass1) {
    Rectangle<double> a;
    EXPECT_EQ(a.square(), 0);
}

TEST(FigureTest, EmptyClass2) {
    Rectangle<int> a;
    EXPECT_THROW(a.center(), std::logic_error);
}

TEST(FigureTest, EmptyClass3) {
    Rhombus<double> a;
    EXPECT_EQ(a.square(), 0);
}

TEST(FigureTest, EmptyClass4) {
    Rhombus<int> a;
    EXPECT_THROW(a.center(), std::logic_error);
}

TEST(FigureTest, EmptyClass5) {
    Trapezoid<int> a;
    EXPECT_EQ(a.square(), 0);
}

TEST(FigureTest, EmptyClass6) {
    Trapezoid<int> a;
    EXPECT_THROW(a.center(), std::logic_error);
}

TEST(FigureTest, EmptyClass7) {
    Trapezoid<int> a;
    Trapezoid<double> b;
    ASSERT_TRUE(a == b);
}

TEST(FigureTest, EmptyClass8) {
    Rhombus<int> a;
    Rhombus<double> b;
    ASSERT_TRUE(a == b);
}

TEST(FigureTest, EmptyClass9) {
    Rectangle<int> a;
    Rectangle<int> b;
    ASSERT_TRUE(a == b);
}


TEST(FigureTest, stdout1) {
    Rectangle<int> a(0, 0, 0, 1, 1, 1, 1, 0);
    testing::internal::CaptureStdout();
    std::cout << a;
    std::string output = testing::internal::GetCapturedStdout();

    std::string r = "dot1[0, 0]\ndot2[0, 1]\ndot3[1, 1]\ndot4[1, 0]\n";

    ASSERT_EQ(r, output);
}

TEST(FigureTest, stdout2) {
    Trapezoid<double> a(0, 0, 3, 0, 2, 2, 1, 2);
    testing::internal::CaptureStdout();
    std::cout << a;
    std::string output = testing::internal::GetCapturedStdout();

    std::string r = "dot1[0, 0]\ndot2[3, 0]\ndot3[2, 2]\ndot4[1, 2]\n";

    ASSERT_EQ(r, output);
}

TEST(FigureTest, stdout3) {
    Rhombus<int> a(0, 0, 1, 1, 0, 2, -1, 1);
    testing::internal::CaptureStdout();
    std::cout << a;
    std::string output = testing::internal::GetCapturedStdout();

    std::string r = "dot1[0, 0]\ndot2[1, 1]\ndot3[0, 2]\ndot4[-1, 1]\n";

    ASSERT_EQ(r, output);
}

TEST(FigureTest, stdout4) {
    Rectangle<int> a;
    testing::internal::CaptureStdout();
    std::cout << a;
    std::string output = testing::internal::GetCapturedStdout();

    std::string r = "Cannot display None-Figure\n";
    ASSERT_EQ(r, output);
}

TEST(FigureTest, stdout5) {
    Trapezoid<int> a;
    testing::internal::CaptureStdout();
    std::cout << a;
    std::string output = testing::internal::GetCapturedStdout();

    std::string r = "Cannot display None-Figure\n";

    ASSERT_EQ(r, output);
}

TEST(FigureTest, stdout6) {
    Rhombus<int> a;
    testing::internal::CaptureStdout();
    std::cout << a;
    std::string output = testing::internal::GetCapturedStdout();

    std::string r = "Cannot display None-Figure\n";

    ASSERT_EQ(r, output);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
