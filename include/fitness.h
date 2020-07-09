#ifndef FITNESS_H
#define FITNESS_H

#include <iostream>
#include <cmath>
#include "individual.h"

class Fitness
{
private:
    int n_obj;
public:
    Fitness();
    ~Fitness();
    double FitnessEval1(Individual);
};

#endif