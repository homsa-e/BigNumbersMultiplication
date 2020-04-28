#ifndef MULTIPLICATOR_H
#define MULTIPLICATOR_H
#include "../Number/number.h"
#include <iostream>
#include <vector>

class Multiplicator
{
  public:
    Multiplicator();
    virtual Number multiply(const Number &n1, const Number &n2) const = 0;
    virtual ~Multiplicator();
};

#endif // MULTIPLICATOR_H
