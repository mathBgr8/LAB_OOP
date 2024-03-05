#include "../include/point.hpp"
#include <math.h>

bool operator==(const Point& left_operand, const Point& right_operand) {
    return left_operand.x == right_operand.x and left_operand.y == right_operand.y;
}

bool operator==(const Point& left_operand, const int& right_operand) {
    return left_operand.x == right_operand and left_operand.y == right_operand;
}

bool operator<(const Point& left_operand, const Point& right_operand) {
    if(left_operand.x != right_operand.x) {
        return left_operand.x < right_operand.x;
    }
    return left_operand.y < right_operand.y;
}

bool operator>(const Point& left_operand, const Point& right_operand) {
    if(left_operand.x != right_operand.x) {
        return left_operand.x > right_operand.x;
    }
    return left_operand.y > right_operand.y;
}

Point operator-(const Point& left_operand, const Point& right_operand) {
    Point res;
    res.x = left_operand.x - right_operand.x;
    res.y = left_operand.y - right_operand.y;
    return res;
}

Point operator+(const Point& left_operand, const Point& right_operand) {

    Point res;
    res.x = left_operand.x + right_operand.x;
    res.y = left_operand.y + right_operand.y;
    return res;
}

Point operator/(const Point& left_operand, const int& num) {
    Point res;
    res.x /= num;
    res.y /= num;
    return res;
}

double operator*(const Point& left_operand, const Point& right_operand) {
    return left_operand.x * right_operand.x + left_operand.y * right_operand.y;
}

double vector_length(const Point& vector) {
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}

