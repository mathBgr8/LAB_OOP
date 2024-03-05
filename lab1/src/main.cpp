#include <iostream>
#include "box_cap.h"

int box_size = 16;

int main() {
    unsigned int l, w, h;
    std::cout << "Enter length, width and height of room:\n";
    std::cin >> l >> w >> h;

    try{
        std::cout << box_capacity(l, w, h, box_size) << '\n';
    }
    catch(const std::invalid_argument& err){
        std::cerr<<err.what();
    }
}
