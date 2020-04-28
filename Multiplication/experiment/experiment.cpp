#include "experiment.h"

Experiment::Experiment()
{
}

Number Experiment::generate(const size_t &k, const int &seed)
{
    Number x;
    std::srand(std::time(NULL) + seed);
    x.resize(k);
    x.digit(x.size() - 1) = (rand() % 9) + 1;
    for (size_t i = 0; i < k - 1; ++i)
    {
        x.digit(i) = rand() % 10;
    }
    return x;
}

void Experiment::printToCsv(std::ofstream &fout, const size_t &i, const std::vector<double> &times)
{
    fout << i + 1;
    for (size_t j = 0; j < times.size(); ++j)
    {
        fout << ',' << times[j];
    }
    fout << std::endl;
}

void Experiment::launch(const size_t &size, const size_t &numberOfExperiments, size_t &step)
{
    std::vector<Multiplicator *> multipliers(3);
    multipliers[0] = new School();
    multipliers[1] = new DAndC();
    multipliers[2] = new Karatsuba();
    results.resize(size);
    for (size_t i = 0; i < results.size(); ++i)
        results[i].resize(3);
    Number r1, r2;
    std::ofstream fout;
    fout.open("data.csv");
    for (size_t i = 0; i < size; i += step)
    {
        if (i >= 999)
            step = 10;
        std::vector<double> times(3); // times[0] is for Grade School Multiplication,
        r1 = generate(i + 1, 1);      // times[1] - D&C, times[2] - Karatsuba
        r2 = generate(i + 1, 2);
        for (size_t j = 0; j < numberOfExperiments; ++j)
        {
            for (size_t k = 0; k < multipliers.size(); ++k)
            {
                auto start = std::chrono::high_resolution_clock::now();
                multipliers[k]->multiply(r1, r2);
                auto end = std::chrono::high_resolution_clock::now();
                auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
                times[k] += dur.count();
            }
        }
        for (size_t k = 0; k < times.size(); ++k)
        {
            times[k] /= numberOfExperiments;
            times[k] /= 1000; // division by 1000 to get milliseconds
            results[i][k] = times[k];
        }
        printToCsv(fout, i, times);
    }
    fout.close();
    for (size_t i = 0; i < multipliers.size(); ++i)
    {
        delete multipliers[i];
    }
}

Experiment::~Experiment()
{
}
