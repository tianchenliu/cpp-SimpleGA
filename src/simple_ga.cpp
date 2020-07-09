#include "simple_ga.h"

SimpleGa::SimpleGa()
{
    n_pop = 50;
    n_vars = 2; // dim of variables = number of chromos
    lb = {0., 0.}; // a <double> vector for lower bounds
    ub = {1., 1.}; // a <double> vector for upper bounds
    k_precision = 1e-4;
}

SimpleGa::~SimpleGa()
{
}

void SimpleGa::TestChromosomeClass() {
    int n;
    std::cout << "Enter n_len: ";
    std::cin >> n; 

    Chromosome c1(1, n), c2(2, n);
    
    c1.PrintChromo();
    c2.PrintChromo();

    c1.Crossover(c2, 1);
    std::cout << "After crossover: " << std::endl;
    c1.PrintChromo();

    c1.Mutation();
    c1.PrintChromo();
    c1.PrintMutationPositions();
}

void SimpleGa::TestIndividualClass() {    
    Individual i1(1, n_vars, lb, ub, k_precision);
    i1.FindValues();
    i1.PrintIndividual();

    std::vector<double> idv_values = i1.GetValues();
    for (int i=0; i<idv_values.size(); i++) {
        std::cout << idv_values[i] << " ";
    }

}

void SimpleGa::InitPopulation() {
    for (int i=0; i<n_pop; i++) {
        Individual idv(i, n_vars, lb, ub, k_precision);
        pop_gen_prev.push_back(idv);
    }
}

void SimpleGa::Evaluation(){

}

void SimpleGa::Selection(){

}

void SimpleGa::Crossover() {

}

void SimpleGa::Mutation() {

}

bool SimpleGa::CheckStopping() {
    bool flag_stop = false;

    return flag_stop;
}

