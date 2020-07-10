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
    std::vector<double> val_var; // real variable values of chromos
    double val_fitness = 0;

public:
    Individual(int, std::vector<Chromosome>);
    ~Individual();

    void PrintAllInfo();

};


#endif