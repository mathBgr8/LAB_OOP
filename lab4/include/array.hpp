#pragma once
#include <iostream>
#include <concepts>
#include <memory>
#include "figure.hpp"
#include "rectangle.hpp"
#include "trapezoid.hpp"
#include "rhombus.hpp"
#include "point.hpp"

template <class T>
concept Arrayable = std::is_default_constructible<T>::value;

template <Arrayable T>
class Array
{
public:
    Array() : _size(0), _array{nullptr}
    {
        // std::cout << "Default constructor" << std::endl;
    }

    Array(const std::initializer_list<T> &t)
    {
        // std::cout << "Initializer list constructor" << std::endl;
        _array = std::shared_ptr<T[]>(new T[t.size()]);
        size_t i{0};
        for (auto &c : t)
            _array[i++] = c;
        _size = t.size();
    }

    Array(const Array &other)
    {
        // std::cout << "Copy constructor" << std::endl;
        _size = other._size;
        _array = std::shared_ptr<T[]>(new T[_size]);

        for (size_t i{0}; i < _size; ++i)
            _array[i] = other._array[i];
    }

    Array(Array &&other) noexcept
    {
        // std::cout << "Move constructor" << std::endl;
        _size = other._size;
        _array = other._array;

        other._size = 0;
        other._array = nullptr;
    }

    T& operator[](size_t index){
        assert(index<_size);
        return _array[index];
    }

    size_t size() const{
        return _size;
    }

    ~Array() noexcept
    {
        // std::cout << "destructor:" << _array.use_count() << std::endl;
        // if (_size > 0)
        // {
        //     _size = 0;
        //     delete[] _array;
        //     _array = nullptr;
        // }
    }

    double get_square() {
        if(_array == nullptr) {
            return 0;
        }

        double res_square{0};
        for(size_t i{0}; i < size(); ++i) {
            double tmp = (*_array[i]).square();
            res_square += tmp;
        }
        return res_square;
    }

    void pushBack(T el) {
        std::shared_ptr<T[]> tmp_array;

        tmp_array = std::shared_ptr<T[]>(new T[_size + 1]);

        for (size_t i{0}; i < _size; ++i)
            tmp_array[i] = _array[i];
        _array = tmp_array;
        _array[_size] = el;
        ++_size;
    }

    void delElem(size_t idx) {
        assert(idx < _size);

        std::shared_ptr<T[]> tmp_array;
        tmp_array = std::shared_ptr<T[]>(new T[_size - 1]);
        size_t k{0};
        for (size_t i{0}; i < _size; ++i, ++k) {
            if(i == idx) {
                --k;
                continue;
            }
            tmp_array[k] = _array[i];
        }
        _array = tmp_array;
        --_size;
    }

private:
    size_t _size;
    std::shared_ptr<T[]> _array;
};