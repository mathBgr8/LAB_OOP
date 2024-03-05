#pragma once
#include <iostream>
#include <memory>
#include <list>
#include <map>
#include <utility>
#include <list>

template <class T, size_t BLOCK_COUNT>
class Allocator
{
    private:
        T* _used_blocks;
        std::list<T*> _free_blocks;


    public:
        using value_type = T;
        using pointer = T *;
        using const_pointer = const T *;
        using size_type = std::size_t;

        Allocator()
        {
            static_assert(BLOCK_COUNT > 0);

            _used_blocks = new T[BLOCK_COUNT];
            for (size_t i{0}; i < BLOCK_COUNT; ++i) { 
                _free_blocks.push_back(&_used_blocks[i]);
            }
        }

        ~Allocator()
        {
            // delete _free_blocks;
            // delete _used_blocks;

            // _used_blocks.clear();
            // _free_blocks.clear();

            delete[] _used_blocks;
#ifdef DEBUG
            std::cout << "Memory freed" << std::endl;
#endif
        }

        T *allocate(const size_t& n)
        {

            if(_used_blocks == nullptr) {
                static_assert(BLOCK_COUNT > 0);
                
                _used_blocks = new T[BLOCK_COUNT];

                for (size_t i{0}; i < BLOCK_COUNT; ++i) { 
                    _free_blocks.push_back(&_used_blocks[i]);
                }
            }
            if (_free_blocks.size() >= n)
            {
                T* result = _free_blocks.front();


                for(size_t i {0}; i < n; ++i) {
                    _free_blocks.pop_front();
                }
#ifdef DEBUG
                std::cout << _free_blocks.size() <<  " Decreasing available memory"<< std::endl;
#endif

                return result;
            }
            else
            {
                throw std::bad_alloc();
            }
        }                

        void deallocate(T *pointer, size_t)
        {
            _free_blocks.push_front(pointer);
#ifdef DEBUG
            std::cout << _free_blocks.size() << " Increasing available memory"<< std::endl;
#endif
        }


        template <typename U, typename... Args>
        void construct(U* result, Args&& ... args)
        {
            new (result) U(std::forward<Args>(args)...);
        }
        template <class U>
        struct rebind
        {
            using other = Allocator<U, BLOCK_COUNT>;
        };

        void destroy(pointer p)
        {
            p->~T();
        }
};