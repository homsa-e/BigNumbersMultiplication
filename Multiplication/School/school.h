#ifndef SCHOOL_H
#define SCHOOL_H
#include "../Multiplicator/multiplicator.h"

class School: public Multiplicator
{
public:
    School();
    Number multiply(const Number &n1, const Number &n2) const override;
    ~School();
};

#endif // SCHOOL_H
