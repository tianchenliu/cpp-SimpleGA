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
    int id;
    int n_vars; // dim of variables = number of chromos
    std::vector<double> lb; // a <double> vector for lower bounds
    std::vector<double> ub; // a <double> vector for upper bounds
    double k_precision; // solution precision
    std::vector<int> n_genes_per_chromo; // number of genes per chromo
    std::vector<Chromosome> chromos; // all chromos of an individual
    std::vector<double> true_values; // true values of chromos

public:
    Individual();
    Individual(int, int, std::vector<double>, std::vector<double>, double);
    ~Individual();

    void GenerateIndividual();
    void FindValues();

    std::vector<double> GetValues() { return true_values; };

    void PrintIndividual();
    void PrintIndividualInfo();
};


#endif