#include "karatsuba.h"

Karatsuba::Karatsuba()
{
}

Number Karatsuba::multiply(const Number &n1, const Number &n2) const
{ // O(n^log_2(3)) = const * n^log_2(3)
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
    Number a1_a2b1_b2 = multiply(a1_a2, b1_b2);
    Number a1b1_p = a1b1.shift(2 * m), hard_p = (a1_a2b1_b2 - (a1b1 + a2b2)).shift(m);
    a1b1_p += hard_p;
    a1b1_p += a2b2;
    while (a1b1_p.size() > 1 && a1b1_p.digit(a1b1_p.size() - 1) == 0)
    {
        a1b1_p.pop_back();
    }
    return a1b1_p;
}

Karatsuba::~Karatsuba()
{
}
