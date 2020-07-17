#ifndef SIMPLE_GA_H
#define SIMPLE_GA_H

#include <iostream> 
#include <vector>
#include <random>
#include <cmath>

#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort
#include <functional>

#include "chromosome.h"
#include "individual.h"

class SimpleGa
{
private: 
    double k_pct_selection; // % of individuals selected for next generation
    int n_kept_idv;
    
    std::function<double (std::vector<double>)> fitness; // fitness function
    int n_pop; // number of population
    int n_vars; // dim of variables = number of chromos
    std::vector<double> lb; // a <double> vector for lower bounds
    std::vector<double> ub; // a <double> vector for upper bounds
    double k_precision; // solution precision
    int n_max; // max number of individuals to generate
    
    std::vector<double> k_increment; // increment
    std::vector<int> n_genes; // number of genes in chromos

    int counter_idv; // Counter of individuals

    std::vector<Individual> pop;
    std::vector<std::vector<double> > val_pop;
    std::vector<Individual> pop_next;

    bool flag_stop;
    
public:
    SimpleGa();
    ~SimpleGa();

    double UniformRandomNumber(double, double); 

    // Function to set problem properties
    // Used in initializer
    void SetProblemProperty(std::function<double (std::vector<double>)>, int, int, std::vector<double>, std::vector<double>, double, int);

    // Generate individuals
    Individual GenerateIndividual(int);
    Individual GenerateIndividual(int, std::vector<Chromosome>);
    void InitPopulation();
    
    void EvalIdv(Individual &);
    void EvalPop();

    void Selection();     
    void CrossoverMutation();

    void CheckStop();

    void Run();

    void PrintAllInfo();
    void PrintStepInfo();
    void PrintResults();
};

#endif