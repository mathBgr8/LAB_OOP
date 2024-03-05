#pragma once
#include <iostream>
#include <concepts>
#include <math.h>

template<typename T> 
concept Number = std::is_same<T, int>::value || std::is_same<T, double>::value || std::is_same<T, float>::value;


template<Number T> 
class Point {

    friend bool operator==(const Point<T>& left_operand, const Point<T>& right_operand) {
        return left_operand.x == right_operand.x and left_operand.y == right_operand.y;
    }

    friend bool operator<(const Point<T>& left_operand, const Point<T>& right_operand) {
        if(left_operand.x != right_operand.x) {
            return left_operand.x < right_operand.x;
        }
        return left_operand.y < right_operand.y;
    }

    friend Point<T> operator-(const Point<T>& left_operand, const Point<T>& right_operand) {
        Point<T> res;
        res.x = left_operand.x - right_operand.x;
        res.y = left_operand.y - right_operand.y;
        return res;
    }
    
    friend Point<T> operator/(const Point<T>& left_operand, const int& num) {
        Point<T> res;
        res.x /= num;
        res.y /= num;
        return res;
    }

    friend T operator*(const Point<T>& left_operand, const Point<T>& right_operand) {
        return left_operand.x * right_operand.x + left_operand.y * right_operand.y;
    }
    
    friend Point<T> operator+(const Point<T>& left_operand, const Point<T>& right_operand) {
        Point<T> res;
        res.x = left_operand.x + right_operand.x;
        res.y = left_operand.y + right_operand.y;
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, Point<T>& p) {
        os << p.x << ' ' << p.y;
        return os;
    }   

    friend std::istream& operator>>(std::istream& is, Point<T>& p) {
        is >> p.x >> p.y;
        return is;
    }


    public:

        Point() = default;
        Point(const T& x, const T& y) : x(x), y(y) {};

        double vector_length() const {
            return sqrt(x * x + y * y);
        }

        T x, y;
    
};


