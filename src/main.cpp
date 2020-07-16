#include "simple_ga.h"

/*
double FitnessFunc(std::vector<double> x) {
    double fval = pow(x[0] - 0.4, 2) + pow(x[1] - 0.7, 2);
    return fval;
}
*/

int main()
{
    SimpleGa ga1;

    // Problem parameters
    int n_pop = 60; // # of individuals in one generation
    int n_vars = 2; // dim of variables = number of chromos
    std::vector<double> lb = {0., 0.}; // a <double> vector for lower bounds
    std::vector<double> ub = {1., 1.}; // a <double> vector for upper bounds
    double k_precision = 1e-5; // solution precision

    ga1.SetProblemProperty(n_pop, n_vars, lb, ub, k_precision);

    ga1.InitPopulation();
    
    while (!ga1.flag_stop) {
        ga1.EvalPop();
        ga1.Selection();
        ga1.CrossoverMutation();
        ga1.CheckStop();
        ga1.PrintStepInfo();
    }
    ga1.PrintResults();
    
    return 0;
}
