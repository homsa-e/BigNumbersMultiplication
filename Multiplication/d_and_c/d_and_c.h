#ifndef D_AND_C_H
#define D_AND_C_H
#include "../Number/number.h"
#include "../Multiplicator/multiplicator.h"
#include "../School/school.h"


class DAndC : public Multiplicator
{
  public:
    DAndC();
    Number multiply(const Number &n1, const Number &n2) const override;
    ~DAndC();
};

#endif // D_AND_C_H
