#ifndef EXPERIMENT_H
#define EXPERIMENT_H
#include "../d_and_c/d_and_c.h"
#include "../karatsuba/karatsuba.h"
#include "../Multiplicator/multiplicator.h"
#include "../Number/number.h"
#include "../School/school.h"
#include <chrono>
#include <ctime>
#include <fstream>
#include <random>

class Experiment
{
  public:
    Experiment();
    Number generate(const size_t &k, const int &seed);
    void printToCsv(std::ofstream &fout, const size_t &i, const std::vector<double> &times);
    void launch(const size_t &size, const size_t &numberOfExperiments, size_t &step);
    ~Experiment();

  public:
    std::vector<std::vector<double>> results;
};

#endif // EXPERIMENT_H
