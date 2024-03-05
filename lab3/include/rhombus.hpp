#pragma once
#include "figure.hpp"
#include "point.hpp"
#include <iostream>

class Rhombus : public Figure {

    friend std::istream& operator>>(std::istream& is, Rhombus& r);
    friend std::ostream& operator<<(std::ostream& os, Rhombus& r);
    friend bool operator==(Rhombus& left_operand, Rhombus& right_operand);

    public:
        Rhombus() = default;
        Rhombus(Point a, Point b, Point c, Point d);
        Rhombus(const Rhombus& other);
        Rhombus(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
        ~Rhombus() = default;
        operator double() const;

        void operator=(const Rhombus& r) {
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
        bool equal(const Rhombus& other) const;

    private:
        Point * _array = nullptr;
        Point * _original_array = nullptr;

        bool rhombus_check();
};

