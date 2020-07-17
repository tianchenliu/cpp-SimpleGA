#include "simple_ga.h"

double FitnessFunc(std::vector<double> x) {
    double fval = pow(x[0] - 0.2, 2) + pow(x[1] - 0.2, 2) + pow(x[2] - 0.1, 2);
    return fval;
}

int main()
{
    SimpleGa ga1;

    // Problem parameters
    int n_pop = 100; // # of individuals in one generation
    int n_vars = 3; // dim of variables = number of chromos
    std::vector<double> lb = {0., 0., 0.}; // a <double> vector for lower bounds
    std::vector<double> ub = {1., 1., 1.}; // a <double> vector for upper bounds
    double k_precision = 1e-5; // solution precision
    int n_max = 1000;

    ga1.SetProblemProperty(FitnessFunc, n_pop, n_vars, lb, ub, k_precision, n_max);

    ga1.Run();
    
    return 0;
}
