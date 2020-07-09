#ifndef GA_PROBLEM_H
#define GA_PROBLEM_H

#include <iostream> 
#include <vector>
#include <random>
#include <cmath>

#include "chromosome.h"
#include "individual.h"

class GaProblem
{
private: 
    int n_pop; // number of population
public: 
    int n_vars; // dim of variables = number of chromos
    std::vector<double> lb; // a <double> vector for lower bounds
    std::vector<double> ub; // a <double> vector for upper bounds
    double k_precision;
    std::vector<Individual> pop_gen_prev; // population, previous generation
    std::vector<Individual> pop_gen_now; // population, current generation

public:
    GaProblem();
    ~GaProblem();
    
    // Non-parametric functions for testing classes
    void TestChromosomeClass();
    void TestIndividualClass();

    void InitPopulation();

    void Evaluation();
    void Selection();
    void Crossover();
    void Mutation();
    bool CheckStopping();
};

#endif