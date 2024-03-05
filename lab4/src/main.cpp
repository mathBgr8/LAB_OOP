#include <bits/stdc++.h>
#include <typeinfo>
#include "../include/figure.hpp"
#include "../include/rectangle.hpp"
#include "../include/trapezoid.hpp"
#include "../include/rhombus.hpp"
#include "../include/point.hpp"
#include "../include/array.hpp"
#include <string>
#include <memory>


int main() {

    // Point a(123, 321);
    // std::cout << a << ' ' << typeid(a.x).name() << std::endl;

    // Point<double> a1(0, 0);
    // Point<double> a2(0, 1);
    // Point<double> a3(1, 1);
    // Point<double> a4(1, 0);
    // Rectangle<double> rect(0, 0, 0, 1, 1, 1, 1, 0);
    // Point<double> c = rect.center();
    // std::cout << rect.square() << std::endl;

    // Rhombus<double> rhomb(a1, a2, a3, a4);
    // Point<double> rc = rhomb.center();
    // std::cout << rc << std::endl;

    // Trapezoid<double> trap(0, 0, 3, 0, 2, 2, 1, 2);
    // Point<double> tc = trap.center();
    // double dbltc = trap;
    // std::cout << trap.square() << std::endl;
    
    Array<std::shared_ptr<Figure<double>>> array{
        std::make_shared<Rhombus<double>>(),
        std::make_shared<Rectangle<double>>(),
        std::make_shared<Trapezoid<double>>()
    };

    auto obj = std::make_shared<Trapezoid<double>>(0, 0, 3, 0, 2, 2, 1, 2);
    // std::cout << typeid(obj).name() << std::endl;
    // std::shared_ptr<Trapezoid<double>> trapez(0, 0, 3, 0, 2, 2, 1, 2);

    for(int i = 0; i < array.size(); ++i) {
        (*array[i]) >> std::cin;
        (*array[i]) << std::cout;
    }

    std::cout << array.get_square() << std::endl;
    array.pushBack(obj);
    
    

    for(size_t i = 0; i < array.size(); ++i) 
        std::cout << "Square of " << typeid(*array[i]).name() << ' ' << array[i]->square() << std::endl;
    std::cout << array.get_square() << std::endl;

    array.delElem(0);

    for(size_t i = 0; i < array.size(); ++i) 
        std::cout << "Square of " << typeid(*array[i]).name() << ' ' << array[i]->square() << std::endl;

    std::cout << array.get_square() << std::endl;
}