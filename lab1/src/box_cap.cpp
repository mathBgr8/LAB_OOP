#include <stdexcept>
int foot_to_inch = 12;

int box_capacity(int length, int width, int height, int box_size) {

    if(length < 0 or width < 0 or height < 0 or box_size <= 0) {
        throw std::invalid_argument("invalid data");
    }

    int len_cap = length * foot_to_inch / box_size;
    int width_cap = width * foot_to_inch / box_size;
    int height_cap = height * foot_to_inch / box_size;

    return len_cap * width_cap * height_cap;
}
