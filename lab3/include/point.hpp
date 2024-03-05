#pragma once
#include <iostream>

class Point {

    friend bool operator==(const Point& left_operand, const Point& right_operand);
    friend bool operator<(const Point& left_operand, const Point& right_operand);
    friend bool operator>(const Point& left_operand, const Point& right_operand);
    friend Point operator-(const Point& left_operand, const Point& right_operand);
    friend Point operator/(const Point& left_operand, const int& num);
    friend double operator*(const Point& left_operand, const Point& right_operand);
    friend Point operator+(const Point& left_operand, const Point& right_operand);
    friend std::ostream& operator<<(std::ostream& os, Point& p);
    friend double vector_length(const Point& vector);

    public:

        Point() = default;
        Point(double x, double y) : x(x), y(y) {};
        ~Point() = default;

        double x, y;

};


inline std::ostream& operator<<(std::ostream& os, Point& p) {
    os << p.x << ' ' << p.y;
    return os;
}
