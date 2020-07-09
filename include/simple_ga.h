#ifndef SIMPLE_GA_H
#define SIMPLE_GA_H

#include <iostream> 
#include <vector>
#include <random>
#include <cmath>

#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort


#include "chromosome.h"
#include "individual.h"
#include "fitness.h"

class SimpleGa
{
private: 
    double k_pct_selection = 0.5; // % of individuals selected for next generation
public: 
    int counter_idv = 0; // Counter of individuals
    int n_pop; // number of population
    int n_vars; // dim of variables = number of chromos
    std::vector<double> lb; // a <double> vector for lower bounds
    std::vector<double> ub; // a <double> vector for upper bounds
    double k_precision;
    std::vector<Individual> pop_gen_prev; // population, previous generation
    std::vector<Individual> pop_gen_now; // population, current generation
    std::vector<std::vector<double> > val_pop_gen_prev; // value of population, previous generation
    std::vector<double> val_pop_gen_now; // value of population, current generation
    
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