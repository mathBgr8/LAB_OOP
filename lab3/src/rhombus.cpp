#include "../include/rhombus.hpp"
#include "../include/figure.hpp"
#include "../include/point.hpp"
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>


bool Rhombus::rhombus_check() {
    double a, b, c, d;
    a = vector_length(_array[1] - _array[0]);
    b = vector_length(_array[2] - _array[1]);
    c = vector_length(_array[3] - _array[2]);
    d = vector_length(_array[3] - _array[0]);

    if(a == b and a == c and c == d and a != 0) {
        return true;
    }
    return false;
}

Rhombus::Rhombus(Point a, Point b, Point c, Point d) {
    _array = new Point[4];
    _array[0] = a;
    _array[1] = b;
    _array[2] = c;
    _array[3] = d;


    if(!rhombus_check()) {
        throw std::logic_error("Invalid coords");
    }

    _original_array = new Point[4];
    _original_array[0] = _array[0];
    _original_array[1] = _array[1];
    _original_array[2] = _array[2];
    _original_array[3] = _array[3];

    std::sort(_array, _array + 4);
}

Rhombus::Rhombus(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    _array = new Point[4];
    _array[0].x = x1;
    _array[0].y = y1;
    _array[1].x = x2;
    _array[1].y = y2;
    _array[2].x = x3;
    _array[2].y = y3;
    _array[3].x = x4;
    _array[3].y = y4;


    if(!rhombus_check()) {
        throw std::logic_error("Invalid coords");
    }

    _original_array = new Point[4];
    _original_array[0] = _array[0];
    _original_array[1] = _array[1];
    _original_array[2] = _array[2];
    _original_array[3] = _array[3];

    std::sort(_array, _array + 4);
}


Rhombus::Rhombus(const Rhombus& other) {
    _original_array = new Point[4];
    _array = new Point[4];
    for(int i = 0; i < 4; ++i) {
        _original_array[i] = other._original_array[i];
        _array[i] = other._array[i];
    }
}


Point Rhombus::center() const {
    if(_array == nullptr) {
        throw std::logic_error("Can't get center of None-Figure");
    }
    Point center;
    center = _array[0] + (_array[3] - _array[0]) / 2;
    return center;
}

double Rhombus::square() const {
    if(_array == nullptr) return 0;
    Point diag1, diag2;
    diag1 = _array[3] - _array[0];
    diag2 = _array[2] - _array[1];
    return vector_length(diag1) * vector_length(diag2) * .5;
}

bool Rhombus::equal(const Rhombus& other) const {
    return (_array[0] == other._array[0]) and (_array[1] == other._array[1]) and (_array[2] == other._array[2]) and (_array[3] == other._array[3]);
}

Rhombus::operator double() const {
    return square();
}


bool operator==(Rhombus& left_operand, Rhombus& right_operand) {
    if(left_operand._array == nullptr and right_operand._array == nullptr) {
        return true;
    } else if(left_operand._array != nullptr and right_operand._array != nullptr) {
        return (left_operand._array[0] == right_operand._array[0]) and (left_operand._array[1] == right_operand._array[1]) and (left_operand._array[2] == right_operand._array[2]) and (left_operand._array[3] == right_operand._array[3]);
    }
    return false;
}

std::istream& operator>>(std::istream& is, Rhombus& r) {
    if(r._array == nullptr) {
        r._array = new Point[4];
    }

    is >> r._array[0].x >> r._array[0].y >> r._array[1].x >> r._array[1].y >> \
        r._array[2].x >> r._array[2].y >> r._array[3].x >> r._array[3].y;


    if(!r.rhombus_check()) {
        throw std::logic_error("Invalid coords");
    }
    std::sort(r._array, r._array + 4);

    return is;
}

std::ostream& operator<<(std::ostream& os, Rhombus& r) {
    if(r._array == nullptr) {
        os << "Cannot display None-Figure" << std::endl;
        return os;
    }

    for(int i = 0; i < 4; ++i) {
        os << "dot" << i + 1 << "[" << r._original_array[i].x << ", " << r._original_array[i].y << "]" << std:: endl;
    }

    return os;
}
