#include <bits/stdc++.h>
#include "../include/figure.hpp"
#include "../include/rectangle.hpp"
#include "../include/trapezoid.hpp"
#include "../include/rhombus.hpp"
#include "../include/point.hpp"
#include <string>

#define MIN_SIZE 3


void push_back1(Figure**& _array, int& _size, int& _cap, Figure * el) {

    if(_array == nullptr) {
        throw std::logic_error("Undefined array");
    }

    if(_size == _cap) {
        int new_cap = _cap * 2;
        Figure** _tmp = new Figure*[new_cap];
        for(int i = 0; i < _cap; ++i) {
            _tmp[i] = _array[i];
        }
        delete[] _array;
        _array = _tmp;
        _cap = new_cap;
    }
    _array[_size] = el;
    ++_size;
}

void del(Figure**& _array, int& _size, int idx) {
    std::cout << idx << std::endl;  
    if(_array == nullptr or _size == 0) {
        throw std::logic_error("Undefined array");
    }

    if(!(0 <= idx and idx <= _size)) {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    Figure** tmp = new Figure*[ _size - 1 ];


    for(int i = 0, j = 0; i < _size; ++i, ++j) {
        if(i == idx) {
            --j;
            continue;
        }
        
        tmp[j] = _array[i];
    }

    delete[] _array;
    _array = tmp;
    --_size;
}

void get_info(Figure** array, const int& size) {
    std::cout << "===============\n";
    double sq = 0;
    for(int i = 0; i < size; ++i) {
        Point center = array[i]->center();
        std::cout << "coords of center is " << center << std::endl;
        double square = array[i]->square();
        std::cout << "square is " << square << std::endl;
        sq += square;
        std::cout << "===============\n";
    }

    std::cout << "Sum of figure's squares is " << sq << std::endl;
}

int main() {
    Figure** array = new Figure*[MIN_SIZE];
    int size = 0;
    int cap = MIN_SIZE;

    // Rectangle
    Rectangle rect;
    std::cout << "Input 4 dots of rectangle like that: x1 y1 x2 y2 x3 y3 x4 y4" << std::endl;
    std::cin >> rect;
    
    std::cout << rect.center().x << ' ' << rect.center().y << std::endl;
    std::cout << rect.square() << std::endl;

    push_back1(array, size, cap, &rect);

    // Rhombus
    Rhombus rhomb;
    std::cout << "Input 4 dots of rhombus like that: x1 y1 x2 y2 x3 y3 x4 y4" << std::endl;
    std::cin >> rhomb;
    
    std::cout << rhomb.center().x << ' ' << rhomb.center().y << std::endl;
    std::cout << rhomb.square() << std::endl;

    push_back1(array, size, cap, &rhomb);

    // Trapezoid
    Trapezoid trapez;
    std::cout << "Input 4 dots of trapezoid like that: x1 y1 x2 y2 x3 y3 x4 y4" << std::endl;
    std::cin >> trapez;
    
    std::cout << trapez.center().x << ' ' << trapez.center().y << std::endl;
    std::cout << trapez.square() << std::endl;

    push_back1(array, size, cap, &trapez);

    get_info(array, size);

    int idx;
    std::cout << "What index of figure to delete? " << std::endl;
    std::cin >> idx;
    if(!(0 <= idx and idx < size)) {
        throw std::logic_error("Invalid index");
    }

    del(array, size, idx);

    get_info(array, size);
    
}