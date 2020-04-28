#ifndef NUMBER_H
#define NUMBER_H
#include <iostream>
#include <vector>

class Number
{
  public:
    Number() = default;
    Number(const std::vector<int> &v);
    Number(const std::string &s);
    size_t size() const;
    bool operator==(const Number &other) const;
    Number &operator=(const Number &other);
    Number &operator+=(const Number &other);
    Number operator+(const Number &other) const;
    Number &operator-=(const Number &other);
    Number operator-(const Number &other) const;
    Number shift(size_t t) const;
    void clear();
    void resize(const size_t &new_size);
    void resize(const size_t &new_size, int value);
    std::vector<int>::iterator begin();
    std::vector<int>::iterator end();
    std::vector<int>::const_iterator begin() const;
    std::vector<int>::const_iterator end() const;
    std::pair<Number, Number> split(const size_t &cut_size) const;
    void pop_back();
    const int &digit(const size_t &index) const;
    int &digit(const size_t &index);
    ~Number();
  private:
    std::vector<int> digits;
};

#endif // NUMBER_H
