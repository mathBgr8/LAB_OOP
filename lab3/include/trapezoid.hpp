#pragma once
#include "figure.hpp"
#include "point.hpp"
#include <iostream>


class Trapezoid : public Figure {

    friend std::istream& operator>>(std::istream& is, Trapezoid& r);
    friend std::ostream& operator<<(std::ostream& os, Trapezoid& r);
    friend bool operator==(Trapezoid& left_operand, Trapezoid& right_operand);

    public:
        Trapezoid() = default;
        Trapezoid(Point a, Point b, Point c, Point d);
        Trapezoid(const Trapezoid& other);
        Trapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
        ~Trapezoid() = default;

        operator double() const;

        void operator=(Trapezoid& r) {
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
                _array = new Point[4];
                _original_array = new Point[4];
            }

            for(int i = 0; i < 4; ++i) {
                _original_array[i] = r._original_array[i];
                _array[i] = r._array[i];
            }
            return;
        }


        virtual Point center() const final;
        virtual double square() const final;

    private:
        Point * _array = nullptr;
        Point * _original_array = nullptr;

        bool trapezoid_check();
};
