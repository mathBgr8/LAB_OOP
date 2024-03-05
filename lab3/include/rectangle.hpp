#pragma once
#include "figure.hpp"
#include "point.hpp"
#include <algorithm>
#include <utility>
#include <iostream>


class Rectangle : public Figure {

    friend std::istream& operator>>(std::istream& is, Rectangle& r);
    friend std::ostream& operator<<(std::ostream& os, Rectangle& r);
    friend bool operator==(Rectangle& left_operand, Rectangle& right_operand);


    public:
        Rectangle() = default;
        Rectangle(Point a, Point b, Point c, Point d);
        Rectangle(const Rectangle& other);
        Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
        ~Rectangle() = default;
        operator double() const;

        void operator=(const Rectangle& r) {
            if(r._array == nullptr) {
                if(_array != nullptr) {
                    delete[] _original_array;
                    delete[] _array;
                }
                _original_array = nullptr;
                _array = nullptr;
                return;
            }

            if(_array == nullptr) {
                _original_array = new Point[4];
                _array = new Point[4];
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
        Point * _original_array = nullptr;
        Point * _array = nullptr;
        bool rectangle_check();
};
