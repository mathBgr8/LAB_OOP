#pragma once
#include "figure.hpp"
#include "point.hpp"
#include <utility>
#include <iostream>
#include <concepts>
#include <cmath>
#include <algorithm>

template <Number T>
class Rhombus : public Figure<T> {
    
    friend std::istream& operator>>(std::istream& is, Rhombus<T>& r) {
        if(r._array == nullptr) {
            r._array = new Point<T>[4];
        }
        
        is >> r._array[0].x >> r._array[0].y >> r._array[1].x >> r._array[1].y >> \
            r._array[2].x >> r._array[2].y >> r._array[3].x >> r._array[3].y;


        if(!r.rhombus_check()) {
            throw std::logic_error("Invalid coords");
        }

        r._original_array = new Point<T>[4];
        r._original_array[0] = r._array[0];
        r._original_array[1] = r._array[1];
        r._original_array[2] = r._array[2];
        r._original_array[3] = r._array[3];

        std::sort(r._array, r._array + 4);

        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, Rhombus<T>& r) {
        if(r._array == nullptr) {
            os << "Cannot display None-Figure" << std::endl;
            return os;
        }
        
        for(int i = 0; i < 4; ++i) {
            os << "dot" << i + 1 << "[" << r._original_array[i].x << ", " << r._original_array[i].y << "]" << std:: endl;
        }

        return os;
    }

    friend bool operator==(Rhombus<T>& left_operand, Rhombus<T>& right_operand) {
        if(left_operand._array == nullptr and right_operand._array == nullptr) {
            return true;
        } else if(left_operand._array != nullptr and right_operand._array != nullptr) {
            return (left_operand._array[0] == right_operand._array[0]) and (left_operand._array[1] == right_operand._array[1]) and (left_operand._array[2] == right_operand._array[2]) and (left_operand._array[3] == right_operand._array[3]);
        }
        return false;
    }

    public:
        Rhombus() = default;

        Rhombus(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
            _array = new Point<T>[4];
            _array[0] = a;
            _array[1] = b;
            _array[2] = c;
            _array[3] = d;


            if(!rhombus_check()) {
                throw std::logic_error("Invalid coords");
            }

            _original_array = new Point<T>[4];
            _original_array[0] = _array[0];
            _original_array[1] = _array[1];
            _original_array[2] = _array[2];
            _original_array[3] = _array[3];

            std::sort(_array, _array + 4);
        }

        Rhombus(const Rhombus<T>& other) {
            _original_array = new Point<T>[4];
            _array = new Point<T>[4];
            for(int i = 0; i < 4; ++i) {
                _original_array[i] = other._original_array[i];
                _array[i] = other._array[i];
            }
        }

        Rhombus(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
            _array = new Point<T>[4];
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

            _original_array = new Point<T>[4];
            _original_array[0] = _array[0];
            _original_array[1] = _array[1];
            _original_array[2] = _array[2];
            _original_array[3] = _array[3];

            std::sort(_array, _array + 4);
        }

        ~Rhombus() = default;

        operator double() const {
            return square();
        }

        void operator=(const Rhombus<T>& r) {
            if(r._array == nullptr) {
                if(_array != nullptr) {
                    delete[] _array;
                    delete[] _original_array;
                }
                _original_array = nullptr;
                _array = nullptr;
                return;
            }

            if(_array == nullptr) {
                _original_array = new Point<T>[4];
                _array = new Point<T>[4];
            }

            for(int i = 0; i < 4; ++i) {
                _original_array[i] = r._original_array[i];
                _array[i] = r._array[i];
            }
            return;
        }


        virtual Point<T> center() const final {
            if(_array == nullptr) {
                throw std::logic_error("Can't get center of None-Figure");
            }
            Point<T> center;
            center = _array[0] + (_array[3] - _array[0]) / 2;
            return center;
        }

        virtual double square() const final {
            if(_array == nullptr) return 0;
            Point<T> diag1, diag2;
            diag1 = _array[3] - _array[0];
            diag2 = _array[2] - _array[1];
            return static_cast<double>(diag1.vector_length() * diag2.vector_length() * .5);
        }

        bool equal(const Rhombus<T>& other) const {
            return (_array[0] == other._array[0]) and (_array[1] == other._array[1]) and (_array[2] == other._array[2]) and (_array[3] == other._array[3]);
        }

        virtual void cinF() {
            Point<T> a, b, c, d;
            std::cin >> a >> b >> c >> d;
            _array[0] = a;
            _array[1] = b;
            _array[2] = c;
            _array[3] = d;

            if(!rhombus_check()) {
                throw std::logic_error("Wrong arguments");
            }

            _original_array = new Point<T>[4];
            _original_array[0] = _array[0];
            _original_array[1] = _array[1];
            _original_array[2] = _array[2];
            _original_array[3] = _array[3];

            std::sort(_array, _array + 4);
        }


        virtual std::ostream& operator<<(std::ostream& os) const {
            if(_array == nullptr) {
                os << "Cannot display None-Figure" << std::endl;
                return os;
            }
            std::cout << "Rhombus looks like this: " << std::endl;

            for(int i = 0; i < 4; ++i) {
                os << "dot" << i + 1 << "[" << _original_array[i].x << ", " << _original_array[i].y << "]" << std:: endl;
            }
            std::cout << std::endl;
            return os;
        }

        virtual std::istream& operator>>(std::istream& is) {
            if(_array == nullptr) {
                _array = new Point<T>[4];
            }
            
            is >> _array[0].x >> _array[0].y >> _array[1].x >> _array[1].y >> \
                _array[2].x >> _array[2].y >> _array[3].x >> _array[3].y;


            if(!rhombus_check()) {
                throw std::logic_error("Invalid coords");
            }

            _original_array = new Point<T>[4];
            _original_array[0] = _array[0];
            _original_array[1] = _array[1];
            _original_array[2] = _array[2];
            _original_array[3] = _array[3];

            std::sort(_array, _array + 4);
            return is;
        }

    private:
        Point<T> * _array = nullptr;
        Point<T> * _original_array = nullptr;

        bool rhombus_check() {
            double a, b, c, d;
            a = (_array[1] - _array[0]).vector_length();
            b = (_array[2] - _array[1]).vector_length();
            c = (_array[3] - _array[2]).vector_length();
            d = (_array[3] - _array[0]).vector_length();

            if(a == b and a == c and c == d and a != 0) {
                return true;
            }
            return false;
        }
};



