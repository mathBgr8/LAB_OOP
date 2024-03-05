#pragma once
#include "figure.hpp"
#include "point.hpp"
#include <utility>
#include <iostream>
#include <concepts>
#include <cmath>
#include <algorithm>

template <Number T>
class Trapezoid : public Figure<T> {

    friend std::istream& operator>>(std::istream& is, Trapezoid<T>& r) {
        if(r._array == nullptr) {
            r._array = new Point<T>[4];
        }
        
        is >> r._array[0].x >> r._array[0].y >> r._array[1].x >> r._array[1].y >> \
            r._array[2].x >> r._array[2].y >> r._array[3].x >> r._array[3].y;


        if(!r.trapezoid_check()) {
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

    friend std::ostream& operator<<(std::ostream& os, Trapezoid<T>& r) {
        if(r._array == nullptr) {
            os << "Cannot display None-Figure" << std::endl;
            return os;
        }
        
        for(int i = 0; i < 4; ++i) {
            os << "dot" << i + 1 << "[" << r._original_array[i].x << ", " << r._original_array[i].y << "]" << std:: endl;
        }

        return os;
    }

    friend bool operator==(Trapezoid<T>& left_operand, Trapezoid<T>& right_operand) {
        if(left_operand._array == nullptr and right_operand._array == nullptr) {
            return true;
        } else if(left_operand._array != nullptr and right_operand._array != nullptr) {
            return (left_operand._array[0] == right_operand._array[0]) and (left_operand._array[1] == right_operand._array[1]) and (left_operand._array[2] == right_operand._array[2]) and (left_operand._array[3] == right_operand._array[3]);
        }
        return false;
    }

    public:
        Trapezoid() = default;

        Trapezoid(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
            _array = new Point<T>[4];
            _array[0] = a;
            _array[1] = b;
            _array[2] = c;
            _array[3] = d;

            if(!trapezoid_check()) {
                throw std::logic_error("Invalid coords");
            }

            _original_array = new Point<T>[4];
            _original_array[0] = a;
            _original_array[1] = b;
            _original_array[2] = c;
            _original_array[3] = d;

            std::sort(_array, _array + 4);
        }

        Trapezoid(const Trapezoid<T>& other) {
            _array = new Point<T>[4];
            _original_array = new Point<T>[4];
            for(int i = 0; i < 4; ++i) {
                _array[i] = other._array[i];
                _original_array[i] = other._original_array[i];
            }
        }

        Trapezoid(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4) {
            _array = new Point<T>[4];
            _array[0].x = x1;
            _array[0].y = y1;
            _array[1].x = x2;
            _array[1].y = y2;
            _array[2].x = x3;
            _array[2].y = y3;
            _array[3].x = x4;
            _array[3].y = y4;
            
            if(!trapezoid_check()) {
                throw std::logic_error("Invalid coords in");
            }
            
            _original_array = new Point<T>[4];
            _original_array[0] = _array[0];
            _original_array[1] = _array[1];
            _original_array[2] = _array[2];
            _original_array[3] = _array[3];

            std::sort(_array, _array + 4);
        }

        ~Trapezoid() = default;

        operator double() const {
            return square();
        }

        void operator=(Trapezoid<T>& r) {
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
                _array = new Point<T>[4];
                _original_array = new Point<T>[4];
            }

            for(int i = 0; i < 4; ++i) {
                _original_array[i] = r._original_array[i];
                _array[i] = r._array[i];
            }
            return;
        }


        virtual Point<T> center() const final {
            if(_array == nullptr) {
                throw std::logic_error("Cannot get center of None-figure");
            }
            Point<T> center = (_array[0] + _array[1] + _array[2] + _array[3]) / 4;
            return center;
        }

        virtual double square() const final {

                if(_array == nullptr) {
                    return 0;
                }


                Point<T> a, b, c, d, e, f;

                a = (_array[1] - _array[0]);
                c = (_array[3] - _array[2]);

                b = (_array[2] - _array[1]);
                d = (_array[3] - _array[0]);

                e = (_array[3] - _array[1]);
                f = (_array[2] - _array[0]);

                double alen, blen, clen, dlen, elen, flen;

                alen = static_cast<double>(a.vector_length());
                blen = static_cast<double>(b.vector_length());
                clen = static_cast<double>(c.vector_length());
                dlen = static_cast<double>(d.vector_length());
                elen = static_cast<double>(e.vector_length());
                flen = static_cast<double>(f.vector_length());


                if(a.x * c.y == a.y * c.x) {
                    b = _array[3] - _array[1];
                    d = _array[2] - _array[0];

                    return (sq_formula(alen, clen, blen, dlen));

                } else if(d.x * b.y == d.y * b.x) {
                    a = _array[1] - _array[0];
                    c = _array[3] - _array[2];

                    return (sq_formula(blen, dlen, alen, clen));
                
                } else if(e.x * f.y == e.y * f.x) {
                    a = _array[1] - _array[0];
                    b = _array[3] - _array[2];

                    return (sq_formula(elen, flen, alen, blen));
                }

                return 0;
        }

        virtual void cinF() {
            Point<T> a, b, c, d;
            std::cin >> a >> b >> c >> d;
            _array[0] = a;
            _array[1] = b;
            _array[2] = c;
            _array[3] = d;

            if(!trapezoid_check()) {
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
            std::cout << "Trapezoid looks like this: " << std::endl;

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


            if(!trapezoid_check()) {
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

        double sq_formula(double a, double b, double c, double d) const { // a || b
            double s = (a + b) * (a + b) * (4 * c * c - (a - b) * (a - b));
            // double s = (a + b) / 2 * sqrt(c * c - (((a - b) * (a - b) + c * c - d * d) / (2 * (a  - b))) * (((a - b) * (a - b) + c * c - d * d) / (2 * (a  - b))));
            return sqrt(s) / 4;
        }


        bool trapezoid_check() {
            Point<T> a, b, c, d;
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
};
