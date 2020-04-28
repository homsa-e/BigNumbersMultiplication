#include "d_and_c.h"

DAndC::DAndC()
{
}
Number DAndC::multiply(const Number &n1, const Number &n2) const
{
    if (n1.size() == 1 || n2.size() == 1)
    {
        School multiplier;
        return multiplier.multiply(n1, n2);
    }
    size_t m = std::min(n1.size(), n2.size()) / 2;
    std::pair<Number, Number> a = n1.split(m);
    std::pair<Number, Number> b = n2.split(m);

    Number a1_a2 = a.first + a.second;
    Number b1_b2 = b.first + b.second;

    Number a1b1 = multiply(a.first, b.first);
    Number a2b2 = multiply(a.second, b.second);
    Number a1b2 = multiply(a.first, b.second);
    Number a2b1 = multiply(a.second, b.first);

    Number a1b1_p = a1b1.shift(2 * m), hard_p = (a1b2 + a2b1).shift(m);
    a1b1_p += hard_p;
    a1b1_p += a2b2;
    while (a1b1_p.size() > 1 && a1b1_p.digit(a1b1_p.size() - 1) == 0)
    {
        a1b1_p.pop_back();
    }
    return a1b1_p;
}

DAndC::~DAndC()
{
}
