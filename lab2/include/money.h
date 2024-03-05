#pragma once

#include <iostream>
#include <string>

class Money {

    public:
        Money();
        Money(const int & n, unsigned char t, bool is_positive);
        Money(const std::initializer_list< unsigned char> &t);
        Money(const std::string &t);
        Money(const Money& other);
        Money(Money&& other) noexcept;   

        Money add(Money& other);
        Money substract(const Money& other);

        bool equal(const Money& other);
        bool greater(const Money& other);
        bool less(const Money& other);

        size_t get_size() const;
        unsigned char* get_array() const;
        std::string get_string_array() const;
        bool is_positive() const;

        std::ostream& print(std::ostream& os);

        virtual ~Money() noexcept;

    private:
        int _size;
        unsigned char *_array;
        bool _positive;

        bool _greater(const Money& other);
        void _add(Money& res, const Money& other);
        void _substract(Money& res, const Money& first, const Money& second);

        bool _is_digit_allowed(unsigned char c);

        int ctoi(char c);
        char itoc(int n);



};