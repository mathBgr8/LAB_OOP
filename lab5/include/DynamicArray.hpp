#pragma once
#include <iostream>
#include <memory>
#include <concepts>   
#include <assert.h>
#include <utility>
#include <math.h>
#include <stdexcept>
#include "Allocator.hpp"

class OutOfBoundException
{
};

template <class ItemType, class ArrayType>
class ArrayIterator
{
private:
    ArrayType *array;
    size_t index;
    size_t size;


public:
    ArrayIterator(ArrayType *value, size_t i, size_t s) : array(value), index(i), size(s){};

    ItemType& operator*()
    {
        if (index >= size)
            throw OutOfBoundException();
        return (*array)[index];
    }

    ItemType* operator->()
    {
        if (index >= size)
            throw OutOfBoundException();
        return (*array)[index];
    }

    bool operator!=(ArrayIterator<ItemType, ArrayType> const &other) const
    {
        return (other.index != index) || (other.array != array);
    }

    bool operator==(ArrayIterator<ItemType, ArrayType> const &other) const
    {
        return (other.index == index) && (other.array == array);
    }
    
    ArrayIterator<ItemType, ArrayType> &operator++()
    {
        ++index;
        return *this;
    }

};


template <class ItemType, class ArrayType>
class const_ArrayIterator
{
private:
    ArrayType *array;
    size_t index;
    size_t size;

public:
    const_ArrayIterator(ArrayType *value, size_t i, size_t s) : array(value), index(i), size(s){};

    ItemType operator*() const
    {
        if (index >= size)
            throw OutOfBoundException();
        return (*array)[index];
    }

    bool operator!=(const_ArrayIterator<ItemType, ArrayType> const &other) const
    {
        return (other.index != index) || (other.array != array);
    }

    const_ArrayIterator<ItemType, ArrayType> &operator++()
    {
        ++index;
        return *this;
    }

};




#define Min_Cap 10UL
template<typename T> 
concept Number = std::is_same<T, int>::value || std::is_same<T, double>::value || std::is_same<T, float>::value;

template<Number T, class Allocator>
class DynamicArray 
{
    private:
        using allocator_type = typename Allocator::template rebind<T>::other;

        allocator_type _alloc_elem;
        size_t _size;
        size_t _capacity;
        T* _array;

    public: 
        DynamicArray() : _size(0), _capacity(Min_Cap) {
            auto _tmp = _alloc_elem.allocate(_capacity);
            _array = _tmp;
        }

        DynamicArray(size_t capacity) : _size(0), _capacity(capacity) {
            auto _tmp = _alloc_elem.allocate(_capacity);
            _array = _tmp;
        }


        T& operator[](const size_t index) {

            if(index < 0 or index >= _size) {
                throw OutOfBoundException();
            }
            return _array[index];
        }

        size_t size() const{
            return _size;
        }

        void push_back(T element) {
            if(_size >= _capacity) 
                _alloc_elem.allocate(1);

            _array[_size++] = element;
        }

        void set_element(size_t index, const T& value) {
            if(index < 0 or index >= _size) {
                throw OutOfBoundException();
            }
            _array[index] = value;
        }

        void pop_back() {
            if(_size <= 0) {
                throw OutOfBoundException();
            }
            // T* val = ;
            _alloc_elem.deallocate(&_array[_size - 1], 0);
            _capacity = _size = _size - 1;
        }




        ArrayIterator<T, DynamicArray<T, Allocator>> begin() {
            return ArrayIterator<T, DynamicArray<T,Allocator>>(this, 0, _size);
        }

        ArrayIterator<T, DynamicArray<T,Allocator>> end() {
            return ArrayIterator<T, DynamicArray<T,Allocator>>(this, _size, _size);
        }

        const_ArrayIterator<T, DynamicArray<T, Allocator>> cbegin() {
            return const_ArrayIterator<T, DynamicArray<T,Allocator>>(this, 0, _size);
        }

        const_ArrayIterator<T, DynamicArray<T,Allocator>> cend() {
            return const_ArrayIterator<T, DynamicArray<T,Allocator>>(this, _size, _size);
        }
};