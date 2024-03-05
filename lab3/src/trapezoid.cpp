#include "../include/trapezoid.hpp"
#include "../include/figure.hpp"
#include "../include/point.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <math.h>

static double sq_formula(double a, double b, double c, double d) { // a || b
    double s = (a + b) * (a + b) * (4 * c * c - (a - b) * (a - b));
    // double s = (a + b) / 2 * sqrt(c * c - (((a - b) * (a - b) + c * c - d * d) / (2 * (a  - b))) * (((a - b) * (a - b) + c * c - d * d) / (2 * (a  - b))));
    return sqrt(s) / 4;
}

bool Trapezoid::trapezoid_check() { // 0, 0, 3, 0, 1, 2, 2, 2
    Point a, b, c, d;
    a = (_array[0] - _array[1]); // (3, 0)
    b = (_array[2] - _array[1]); // (-2, 2)
    c = (_array[2] - _array[3]); // (1, 0)
    d = (_array[3] - _array[0]); // (2, 2)

    if((a.x * c.y == a.y * c.x) and (b.x * d.y != b.y * d.x)) {
        if(a * b < 0 or c * b < 0) {

            // std::cout << a * b << ' ' << c * b << std::endl;
            return true;
        }
    }

    d = (_array[0] - _array[3]);

    if((d.x * b.y == d.y * b.x) and (a.x * c.y != a.y * c.x)) {
        if(d * a < 0 or b * a < 0) {
            return true;
        }
    }
    return false;
}

Trapezoid::Trapezoid(Point a, Point b, Point c, Point d) {
    _array = new Point[4];
    _array[0] = a;
    _array[1] = b;
    _array[2] = c;
    _array[3] = d;

    if(!trapezoid_check()) {
        throw std::logic_error("Invalid coords");
    }

    _original_array = new Point[4];
    _original_array[0] = a;
    _original_array[1] = b;
    _original_array[2] = c;
    _original_array[3] = d;

    std::sort(_array, _array + 4);
}

Trapezoid::Trapezoid(const Trapezoid& other) {
    _array = new Point[4];
    _original_array = new Point[4];
    for(int i = 0; i < 4; ++i) {
        _array[i] = other._array[i];
        _original_array[i] = other._original_array[i];
    }
}

Trapezoid::Trapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    _array = new Point[4];
    _array[0].x = x1;
    _array[0].y = y1;
    _array[1].x = x2;
    _array[1].y = y2;
    _array[2].x = x3;
    _array[2].y = y3;
    _array[3].x = x4;
    _array[3].y = y4;

    if(!trapezoid_check()) {
        throw std::logic_error("Invalid coords");
    }

    _original_array = new Point[4];
    _original_array[0] = _array[0];
    _original_array[1] = _array[1];
    _original_array[2] = _array[2];
    _original_array[3] = _array[3];

    std::sort(_array, _array + 4);
}

Point Trapezoid::center() const {
    if(_array == nullptr) {
        throw std::logic_error("Cannot get center of None-figure");
    }
    Point center = (_array[0] + _array[1] + _array[2] + _array[3]) / 4;
    return center;
}

double Trapezoid::square() const {

    if(_array == nullptr) {
        return 0;
    }

    Point a, b, c, d, e, f;

    a = (_array[1] - _array[0]);
    c = (_array[3] - _array[2]);

    b = (_array[2] - _array[1]);
    d = (_array[3] - _array[0]);

    e = (_array[3] - _array[1]);
    f = (_array[2] - _array[0]);


    if(a.x * c.y == a.y * c.x) {
        b = _array[3] - _array[1];
        d = _array[2] - _array[0];

        return (sq_formula(vector_length(a), vector_length(c), vector_length(b), vector_length(d)));

    } else if(d.x * b.y == d.y * b.x) {
        a = _array[1] - _array[0];
        c = _array[3] - _array[2];

        return (sq_formula(vector_length(b), vector_length(d), vector_length(a), vector_length(c)));

    } else if(e.x * f.y == e.y * f.x) {
        a = _array[1] - _array[0];
        b = _array[3] - _array[2];

        return (sq_formula(vector_length(e), vector_length(f), vector_length(a), vector_length(b)));
    }

    return 0;
}

Trapezoid::operator double() const {
    return square();
}


bool operator==(Trapezoid& left_operand, Trapezoid& right_operand) {
    if(left_operand._array == nullptr and right_operand._array == nullptr) {
        return true;
    } else if(left_operand._array != nullptr and right_operand._array != nullptr) {
        return (left_operand._array[0] == right_operand._array[0]) and (left_operand._array[1] == right_operand._array[1]) and (left_operand._array[2] == right_operand._array[2]) and (left_operand._array[3] == right_operand._array[3]);
    }
    return false;
}

std::istream& operator>>(std::istream& is, Trapezoid& r) {
    if(r._array == nullptr) {
        r._array = new Point[4];
    }

    is >> r._array[0].x >> r._array[0].y >> r._array[1].x >> r._array[1].y >> \
        r._array[2].x >> r._array[2].y >> r._array[3].x >> r._array[3].y;


    if(!r.trapezoid_check()) {
        throw std::logic_error("Invalid coords");
    }

    std::sort(r._array, r._array + 4);
    return is;
}

std::ostream& operator<<(std::ostream& os, Trapezoid& r) {
    if(r._array == nullptr) {
        os << "Cannot display None-Figure" << std::endl;
        return os;
    }

    for(int i = 0; i < 4; ++i) {
        os << "dot" << i + 1 << "[" << r._original_array[i].x << ", " << r._original_array[i].y << "]" << std:: endl;
    }

    return os;
}
