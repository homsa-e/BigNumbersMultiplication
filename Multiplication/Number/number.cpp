#include "number.h"
#include <cstdlib>
#include <iostream>
#include <vector>

Number::Number(const std::vector<int> &v) : digits(v)
{
}
Number::Number(const std::string &s)
{
    digits.resize(s.size());
    for (size_t i = 0; i < s.size(); ++i)
    {
        digits[s.size() - 1 - i] = int(s[i] - 48);
    }
}
size_t Number::size() const
{
    return digits.size();
}
bool Number::operator==(const Number &other) const
{
    size_t i = 0;
    if (size() != other.size())
        return false;
    while (i < size())
    {
        if (digits[i] != other.digits[i])
            return false;
        ++i;
    }
    return true;
}

Number &Number::operator=(const Number &other)
{
    this->clear();
    digits = other.digits;
    return *this;
}

Number &Number::operator+=(const Number &other)
{
    if (size() < other.size())
    {
        digits.resize(other.size(), 0);
    }
    int carry = 0;
    for (size_t i = 0; i < other.size(); ++i)
    {
        int sum = digits[i] + other.digits[i] + carry;
        int new_digit = sum % 10;
        digits[i] = new_digit;
        carry = sum / 10;
    }

    size_t digit_index = other.size();
    while (carry != 0)
    {
        if (digit_index < size())
        {
            int sum = digits[digit_index] + carry;
            int new_digit = sum % 10;
            digits[digit_index] = new_digit;
            carry = sum / 10;
            ++digit_index;
        }
        else
        {
            digits.push_back(carry);
            break;
        }
    }

    return *this;
}
Number Number::operator+(const Number &other) const
{
    Number ans = *this;
    ans += other;
    return ans;
}

Number &Number::operator-=(const Number &other)
{
    if (size() < other.size())
    {
        digits.resize(other.size(), 0);
    }

    int borrow = 0;
    for (size_t i = 0; i != size(); ++i)
    {
        int diff = digits[i] - (i < other.size() ? other.digits[i] : 0) - borrow;
        if (diff < 0)
        {
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        digits[i] = diff + 10 * borrow;
    }
    while (digits[digits.size() - 1] == 0 && digits.size() > 1)
        digits.pop_back();
    return *this;
}
Number Number::operator-(const Number &other) const
{
    Number ans = *this;
    ans -= other;
    return ans;
}

Number Number::shift(size_t t) const
{
    Number res;
    res.digits.resize(t + digits.size(), 0);
    std::copy(digits.begin(), digits.end(), res.digits.begin() + t);
    return res;
}
void Number::clear()
{
    digits.resize(0);
}
void Number::resize(const size_t &new_size)
{
    digits.resize(new_size);
}
void Number::resize(const size_t &new_size, int value)
{
    digits.resize(new_size, value);
}
const int &Number::digit(const size_t &index) const
{
    return digits[index];
}
int &Number::digit(const size_t &index)
{
    return digits[index];
}
void Number::pop_back()
{
    digits.pop_back();
}

std::pair<Number, Number> Number::split(const size_t &cut_size) const
{
    Number res1;
    Number res2;

    res1.resize(cut_size, 0);
    res2.resize(this->size() - cut_size, 0);

    std::copy(this->begin(), this->begin() + cut_size, res1.begin());
    std::copy(this->begin() + cut_size, this->end(), res2.begin());
    return std::make_pair(res2, res1);
}

std::vector<int>::iterator Number::begin()
{
    return digits.begin();
}
std::vector<int>::iterator Number::end()
{
    return digits.end();
}
std::vector<int>::const_iterator Number::begin() const
{
    return digits.begin();
}
std::vector<int>::const_iterator Number::end() const
{
    return digits.end();
}
Number::~Number()
{
    digits.resize(0);
}
