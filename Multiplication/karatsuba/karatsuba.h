#ifndef KARATSUBA_H
#define KARATSUBA_H
#include "../School/school.h"
#include "../Multiplicator/multiplicator.h"

class Karatsuba : public Multiplicator
{
  public:
    Karatsuba();
    Number multiply(const Number &n1, const Number &n2) const override;
    ~Karatsuba();
};

#endif // KARATSUBA_H
