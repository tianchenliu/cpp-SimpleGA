#include "simple_ga.h"

SimpleGa::SimpleGa()
{
    n_pop = 20;
    n_vars = 2; // dim of variables = number of chromos
    lb = {0., 0.}; // a <double> vector for lower bounds
    ub = {1., 1.}; // a <double> vector for upper bounds
    k_precision = 1e-4;
}

SimpleGa::~SimpleGa()
{
}

void SimpleGa::TestChromosomeClass() {
    /*
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
    */

   std::vector<int> chromo_input1 = {1,0,1,0,1,1,0,0,1,0};
   Chromosome c1(1, chromo_input1);
   std::vector<int> chromo_input2 = {1,1,0,0,0,1,0,1,1,0};
   Chromosome c2(2, chromo_input2);
   
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
    //Individual i1(1, n_vars, lb, ub, k_precision);
    //i1.FindValues();
    //i1.PrintIndividual();

    std::vector<int> chromo_input1 = {1,0,1,0,1,1,0,0,1,0};
    Chromosome c1(1, chromo_input1);
    std::vector<int> chromo_input2 = {1,1,0,0,0,1,0,1,1,0};
    Chromosome c2(2, chromo_input2);
    
    std::vector<Chromosome> chromos_input;
    chromos_input.push_back(c1);
    chromos_input.push_back(c2);

    Individual i2(2, chromos_input);
    
    i2.PrintAllInfo();

}
