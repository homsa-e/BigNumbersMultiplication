#include "school.h"

School::School()
{

}
Number School::multiply(const Number &n1, const Number &n2) const {
    std::vector<int> d(n1.size() + n2.size(), 0);
    for (size_t i = 0; i < n1.size(); ++i) {
        int carry = 0;
        for (size_t j = 0; j < n2.size(); ++j) {
            d[i + j] += (n2.digit(j) * n1.digit(i) + carry);
            carry = d[i+j]/10;
            d[i+j] %= 10;
        }
        d[i + n2.size()] = carry;
    }
    Number result = Number(d);
    return result;
}
School::~School()
{

}
