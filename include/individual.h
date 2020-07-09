#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <iostream> 
#include <vector>
#include <random>
#include <cmath>

#include "chromosome.h"

class Individual
{
private:
    int n_chromos;
public:
    int id;
    std::vector<Chromosome> chromos; // all chromos of an individual
    std::vector<double> var_values; // real variable values of chromos

public:
    Individual(int, std::vector<Chromosome>);
    ~Individual();

    void PrintAllInfo();

};


#endif