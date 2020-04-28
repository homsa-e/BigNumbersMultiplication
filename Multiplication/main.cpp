#include "experiment/experiment.h"

int main()
{
    Experiment experiment;
    size_t limit = 10000, numberOfExperiments = 3, step = 1;               // numberOfExperiments is the quantity of multiplications for each pair
    experiment.launch(limit, numberOfExperiments, step);                   // pair of i-digit numbers
}
