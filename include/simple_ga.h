#ifndef SIMPLE_GA_H
#define SIMPLE_GA_H

#include <iostream> 
#include <vector>
#include <random>
#include <cmath>

#include "chromosome.h"
#include "individual.h"
#include "fitness.h"

class SimpleGa
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
    std::vector<double> pop_gen_val_prev; // population, previous generation
    std::vector<double> pop_gen_val_now; // population, current generation

public:
    SimpleGa();
    ~SimpleGa();
    
    // Non-parametric functions for testing classes
    void TestChromosomeClass();
    void TestIndividualClass();

    void InitPopulation();

    void Evaluation(Fitness);
    void Selection();
    void Crossover();
    void Mutation();
    bool CheckStopping();
};

#endif